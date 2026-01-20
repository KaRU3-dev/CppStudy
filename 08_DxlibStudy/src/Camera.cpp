#include "Camera.h"
#include <cmath>

using namespace DxLib;
using namespace DxlibStudy;

Camera::Camera()
{
    pos = VGet(0.0f, 100.0f, -400.0f);
    yaw = 0.0f;
    pitch = 0.0f;

    // 画面中央を取得
    int w, h;
    GetWindowSize(&w, &h);
    centerX = w / 2;
    centerY = h / 2;

    // マウス初期位置を中央へ
    SetMousePoint(centerX, centerY);
}

void Camera::Update()
{
    UpdateMouse();
    UpdateMove();
}

void Camera::Apply()
{
    VECTOR dir = GetDirection();
    SetCameraPositionAndTarget_UpVecY(
        pos,
        VAdd(pos, dir));
}

void Camera::UpdateMouse()
{
    int mx, my;
    GetMousePoint(&mx, &my);

    const float sensitivity = 0.0025f;

    yaw += (mx - centerX) * sensitivity;
    pitch -= (my - centerY) * sensitivity;

    // 上下制限
    if (pitch > 1.5f)
        pitch = 1.5f;
    if (pitch < -1.5f)
        pitch = -1.5f;

    // ★ マウスを常に画面中央へ戻す
    SetMousePoint(centerX, centerY);
}

void Camera::UpdateMove()
{
    const float speed = 5.0f;

    VECTOR dir = GetDirection();
    VECTOR forward = VGet(dir.x, 0.0f, dir.z);
    VECTOR right = VGet(cosf(yaw), 0.0f, -sinf(yaw));

    if (CheckHitKey(KEY_INPUT_W))
        pos = VAdd(pos, VScale(forward, speed));
    if (CheckHitKey(KEY_INPUT_S))
        pos = VSub(pos, VScale(forward, speed));
    if (CheckHitKey(KEY_INPUT_A))
        pos = VSub(pos, VScale(right, speed));
    if (CheckHitKey(KEY_INPUT_D))
        pos = VAdd(pos, VScale(right, speed));
    if (CheckHitKey(KEY_INPUT_SPACE))
        pos.y += speed;
    if (CheckHitKey(KEY_INPUT_C))
        pos.y -= speed;
}

VECTOR Camera::GetDirection() const
{
    return VGet(
        cosf(pitch) * sinf(yaw),
        sinf(pitch),
        cosf(pitch) * cosf(yaw));
}
