#include "DxLib.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    ChangeWindowMode(FALSE);
    SetGraphMode(1920, 1080, 60);
    SetDrawScreen(DX_SCREEN_BACK);

    // DXライブラリの初期化
    if (DxLib_Init() == -1)
    {
        return -1; // エラー時終了
    }

    // DireXバージョンを取得
    int ShaderVersion = GetValidShaderVersion();
    printfDx("Shader Version: %d\n", ShaderVersion); // もし、500ならDirectX11相当

    // メインループ
    while (ProcessMessage() == 0 && ClearDrawScreen() == 0)
    {
        // 画面をクリア
        ClearDrawScreen();

        // キー入力
        if (CheckHitKey(KEY_INPUT_SPACE))
        {
            DrawString(0, 50, "Plessing SPACE", GetColor(255, 255, 255));
        }
        if (CheckHitKey(KEY_INPUT_F11))
        {
            if (GetWindowModeFlag() == FALSE)
            {
                ChangeWindowMode(TRUE);
                SetGraphMode(1920, 1060, 60);
                SetDrawScreen(DX_SCREEN_BACK);
            }
            else
            {
                ChangeWindowMode(FALSE);
                SetGraphMode(1920, 1080, 60);
                SetDrawScreen(DX_SCREEN_BACK);
            }
        }

        // 文字列を画面に表示
        DrawString(100, 100, "Hello, DxLib!", GetColor(255, 255, 255));

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
