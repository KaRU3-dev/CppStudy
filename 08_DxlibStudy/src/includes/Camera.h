#pragma once
#include "DxLib.h"
#include <math.h>

#include <cstdint>

#ifndef CAMERA_H
#define CAMERA_H
namespace DxlibStudy
{
    class Camera
    {
    public:
        Camera();

        void Update();
        void Apply();

    private:
        DxLib::VECTOR pos;
        float yaw;
        float pitch;

        int centerX;
        int centerY;

        void UpdateMouse();
        void UpdateMove();
        DxLib::VECTOR GetDirection() const;
    };
}
#endif // CAMERA_H
