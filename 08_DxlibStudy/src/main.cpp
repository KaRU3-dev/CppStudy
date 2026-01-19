#include "DxLib.h"
#include <cstdint>
#include <string>
#include <math.h>

#include "Camera.h"

using namespace DxLib;

constexpr std::int16_t FONT_SIZE = 20;
constexpr std::int32_t PLAYERSPEED = 500;

int deltaPrevTime;

struct Vector2
{
    std::int32_t x;
    std::int32_t y;
};
#define ScreenSize Vector2
#define Position Vector2

std::int32_t GetScreenWidth()
{
    return (std::int32_t)GetSystemMetrics(SM_CXSCREEN);
}

std::int32_t GetScreenHeight()
{
    return (std::int32_t)GetSystemMetrics(SM_CYSCREEN);
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
    ScreenSize screenSize;
    screenSize.x = GetScreenWidth();
    screenSize.y = GetScreenHeight();

    // プレイヤー初期位置の初期化
    Position playerPosition;
    playerPosition.x = 100;
    playerPosition.y = 100;

    // 画面モードの変更
    SetGraphMode(screenSize.x, screenSize.y, 32);
    ChangeWindowMode(FALSE);
    SetDrawScreen(DX_SCREEN_BACK);

    // DXライブラリの初期化
    if (DxLib_Init() == -1)
    {
        return -1; // エラー時終了
    }

    SetCameraNearFar(1.0f, 2000.0f); // クリップ距離
    DxlibStudy::Camera camera;

    // メインループ
    while (ProcessMessage() == 0 && ClearDrawScreen() == 0)
    {
        // 画面をクリア
        ClearDrawScreen();

        int fps = GetFPS();

        camera.Update();
        camera.Apply();

        // 文字列を画面に表示
        std::string screenInfoMsg = "Screen Size: " + std::to_string(screenSize.x) + "x" + std::to_string(screenSize.y) +
                                    "\nScreen update: " + std::to_string(fps) + "fps";
        DrawString(0, 0, screenInfoMsg.c_str(), GetColor(255, 255, 255));

        // DrawCube3D(Pos1, Pos2, DifColor, SpcColor, FillFlag)
        // Pos1 と Pos2 で対角の 2 点を指定（VECTOR）
        DrawCube3D(VGet(-150.0f, -150.0f, -150.0f),
                   VGet(50.0f, 50.0f, 50.0f),
                   GetColor(0, 255, 0), // ディフューズ色
                   GetColor(0, 255, 0), // スペキュラ色（光沢）
                   TRUE);               // TRUE=塗りつぶし、FALSE=ワイヤーフレーム

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
