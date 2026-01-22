#pragma once
#include "DxLib.h"
#include <array>
#include <list>
#include <string>

#ifndef CUBE_H
#define CUBE_H

#define SURFACE_COUNT 6
#define VERTEX_COUNT 6

#define SURFACE_BOTTOM 0 // 下面 y-
#define SURFACE_TOP 1    // 上面 y+
#define SURFACE_SOUTH 2  // 前面 z+
#define SURFACE_NORTH 3  // 後面 z-
#define SURFACE_EAST 4   // 右面 x+
#define SURFACE_WEST 5   // 左面 x-

#define VERTEX_LEFT_BL 0
#define VERTEX_LEFT_TL 1
#define VERTEX_LEFT_BR 2
#define VERTEX_RIGHT_BR 3
#define VERTEX_RIGHT_TL 4
#define VERTEX_RIGHT_TR 5

#define CUBE_DEFAULT_SIZE 50 // デフォルトサイズ

namespace DxLibStudy::GameObjects
{
    class Cube
    {
    private:
        std::array<u_int, SURFACE_COUNT> textureIds;
        std::array<bool, SURFACE_COUNT> drawState = {
            true, // 下
            true, // 上
            true, // 奥
            true, // 手前
            true, // 右
            true, // 左
        };

        VECTOR pos;   // 原点に一番近い点
        int x_width;  // 横
        int y_height; // 縦
        int z_depth;  // 奥行
        int renderSurface;
        std::array<std::array<VERTEX3D, VERTEX_COUNT>, SURFACE_COUNT> surfaces{};

        std::array<VERTEX3D, VERTEX_COUNT> CreateSouthPolygon();
        std::array<VERTEX3D, VERTEX_COUNT> CreateNorthPolygon();
        std::array<VERTEX3D, VERTEX_COUNT> CreateEastPolygon();
        std::array<VERTEX3D, VERTEX_COUNT> CreateWestPolygon();
        std::array<VERTEX3D, VERTEX_COUNT> CreateTopPolygon();
        std::array<VERTEX3D, VERTEX_COUNT> CreateBottomPolygon();

    public:
        Cube(VECTOR pos, std::array<int, SURFACE_COUNT> textureIds, int x_width = CUBE_DEFAULT_SIZE, int y_height = CUBE_DEFAULT_SIZE, int z_depth = CUBE_DEFAULT_SIZE);
        ~Cube();

        void UpdatePos(VECTOR pos);
        void UpdateSize(int x_width, int y_height, int z_depth);
        void DrawSurface();

        void DEBUG_ShowWireFrame();
        void DEBUG_HideWireFrame();
    };

    struct CubeObject
    {
        int id;
        Cube object;
    };
}

#endif // CUBE_H
