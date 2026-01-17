#include "DxLib.h"
#include <dxcapi.h>
#include <dxgi.h>
#include <dxva.h>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    // DXライブラリの初期化
    if (ChangeWindowMode(TRUE) != DX_CHANGESCREEN_OK || DxLib_Init() == -1)
    {
        return -1; // エラーが発生したら終了
    }

    // 描画先を裏画面に設定
    SetDrawScreen(DX_SCREEN_BACK);

    // 白色の円を描画
    DrawCircle(320, 240, 100, GetColor(255, 255, 255), TRUE);

    // 裏画面の内容を表画面にコピー
    ScreenFlip();

    // 何かキーが押されるまで待つ
    WaitKey();

    // DXライブラリの終了処理
    DxLib_End();

    return 0; // 正常終了
}
