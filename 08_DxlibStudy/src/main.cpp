#include "DxLib.h"
#include <cstdint>
#include <string>
#include <math.h>

#include "Camera.h"
#include "Cube.h"
#include "World.h"

using namespace DxLib;

constexpr std::int16_t FONT_SIZE = 20;
constexpr std::int32_t PLAYERSPEED = 500;

int deltaPrevTime;

VECTOR GetScreenSize()
{
    int w, h;
    w = GetSystemMetrics(SM_CXSCREEN);
    h = GetSystemMetrics(SM_CYSCREEN);

    return VGet(w, h, 0);
}

float GetDeltaTime()
{
    int delta = GetNowCount();
    float deltaTime = (float)(delta - deltaPrevTime) / 1000.0f;
    deltaPrevTime = delta;
    return deltaTime;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    // 前デルタタイムを初期化
    deltaPrevTime = GetNowCount();

    // スクリーンサイズを取得し、初期化
    VECTOR screenSize = GetScreenSize();

    // プレイヤー初期位置の初期化
    VECTOR playerPosition;
    playerPosition.x = 100;
    playerPosition.y = 100;

    // 画面モードの変更
    SetGraphMode(screenSize.x, screenSize.y, 32); // 画面モード設定
    ChangeWindowMode(FALSE);                      // デフォルトのウィンドウモード設定 FALSE -> フルスクリーン
    SetDrawScreen(DX_SCREEN_BACK);                // デフォルトの描画場所
    SetWaitVSyncFlag(TRUE);                       // 垂直同期

    // DXライブラリの初期化
    if (DxLib_Init() == -1)
    {
        return -1; // エラー時終了
    }

    // ゲーム内環境の初期化
    SetUseLighting(FALSE);
    SetUseBackCulling(TRUE);
    SetUseZBuffer3D(TRUE);
    SetWriteZBuffer3D(TRUE);
    int renderSurface = TRUE;

    // グラフ初期化
    int bt = LoadGraph("assets/images/CubeSurface_bottom.png");
    int tt = LoadGraph("assets/images/CubeSurface_top.png");
    int st = LoadGraph("assets/images/CubeSurface_south.png");
    int nt = LoadGraph("assets/images/CubeSurface_north.png");
    int et = LoadGraph("assets/images/CubeSurface_east.png");
    int wt = LoadGraph("assets/images/CubeSurface_west.png");
    std::array<int, 6> textureIds = {bt, tt, st, nt, et, wt};

    // カメラの初期化
    SetCameraNearFar(1.0f, 20000.0f); // クリップ距離
    DxlibStudy::Camera camera;

    // ワールド生成
    DxLibStudy::World world;

    DxLibStudy::GameObjects::Cube cube1(VGet(0.0f, 0.0f, 0.0f), textureIds, 100, 100, 100);
    DxLibStudy::GameObjects::Cube cube2(VGet(0.0f, 0.0f, 1.0f * 100.0f), textureIds, 100, 100, 100);
    DxLibStudy::GameObjects::Cube cube3(VGet(0.0f, 0.0f, 1.0f * 200.0f), textureIds, 100, 100, 100);

    DxLibStudy::CubeObject cubeObject1 = {1, cube1};
    DxLibStudy::CubeObject cubeObject2 = {2, cube2};
    DxLibStudy::CubeObject cubeObject3 = {3, cube3};

    world.AddCube(cubeObject1);
    world.AddCube(cubeObject2);
    world.AddCube(cubeObject3);

    // メインループ
    while (ProcessMessage() == 0 && ClearDrawScreen() == 0)
    {
        // 画面をクリア
        ClearDrawScreen();

        int fps = GetFPS();

        camera.Update();
        camera.Apply();

        // キー入力
        if (CheckHitKey(KEY_INPUT_F12))
        {
            if (world.isDebug)
            {
                world.DEBUG_HideWireFrame();
            }
            else
            {
                world.DEBUG_ShowWireFrame();
            }
        }

        // 文字列を画面に表示
        std::string screenInfoMsg = "Screen Size: " + std::to_string(screenSize.x) + "x" + std::to_string(screenSize.y) +
                                    "\nScreen update: " + std::to_string(fps) + "fps";
        DrawString(0, 0, screenInfoMsg.c_str(), GetColor(255, 255, 255));

        // ワールド描画
        world.Draw();

        // 画面の更新
        ScreenFlip();

        // Escキーで終了
        if (CheckHitKey(KEY_INPUT_ESCAPE))
        {
            break;
        }
    }

    // DXライブラリの終了処理
    DxLib_End();
    return 0;
}
