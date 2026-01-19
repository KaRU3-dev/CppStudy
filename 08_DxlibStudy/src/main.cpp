#include "DxLib.h"
#include <cstdint>
#include <string>
#include <math.h>

constexpr std::int16_t FONT_SIZE = 20;
constexpr std::int32_t PLAYERSPEED = 500;

int deltaPrevTime;

struct Vertex
{
    std::int32_t x;
    std::int32_t y;
};
#define ScreenSize Vertex
#define Position Vertex

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
    // SetFullScreenResolutionMode(DX_FSRESOLUTIONMODE_DESKTOP); // 破壊的な解像度の変更を伴う
    // SetWindowSizeChangeEnableFlag(FALSE, FALSE);

    // DXライブラリの初期化
    if (DxLib_Init() == -1)
    {
        return -1; // エラー時終了
    }

    // アセット読み込み
    int hjsImgHandle = LoadGraph("assets/images/emoji-hjs.png");

    // DireXバージョンを取得
    // int ShaderVersion = GetValidShaderVersion();
    // printfDx("Shader Version: %d\n", ShaderVersion); // もし、500ならDirectX11相当

    // メインループ
    while (ProcessMessage() == 0 && ClearDrawScreen() == 0)
    {
        // 画面をクリア
        ClearDrawScreen();

        // プレイヤーの移動
        float dx = 0.0f;
        float dy = 0.0f;
        if (CheckHitKey(KEY_INPUT_A))
        {
            dx -= 1.0f; // 左移動
        }
        if (CheckHitKey(KEY_INPUT_D))
        {
            dx += 1.0f; // 右移動
        }
        if (CheckHitKey(KEY_INPUT_W))
        {
            dy -= 1.0f; // 上移動
        }
        if (CheckHitKey(KEY_INPUT_S))
        {
            dy += 1.0f; // 下移動
        }
        float len = sqrtf(dx * dx + dy * dy);
        if (len > 0.0f)
        {
            dx /= len;
            dy /= len;
        }
        float deltaTime = GetDeltaTime();
        playerPosition.x += (std::int32_t)(dx * PLAYERSPEED * deltaTime);
        playerPosition.y += (std::int32_t)(dy * PLAYERSPEED * deltaTime);

        // 文字列を画面に表示
        std::string screenInfoMsg = "Screen Size: " + std::to_string(screenSize.x) + "x" + std::to_string(screenSize.y);
        DrawString(0, 0, screenInfoMsg.c_str(), GetColor(255, 255, 255));

        // 画像を表示
        DrawGraph(playerPosition.x, playerPosition.y, hjsImgHandle, TRUE);

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
