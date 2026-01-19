#pragma once
#include "DxLib.h"
#include <list>

#ifndef WORLD_H
#define WORLD_H
namespace DxLibStudy
{
    class Cube
    {
    private:
        VECTOR pos;   // 原点に一番近い点
        int x_width;  // 横
        int y_height; // 縦
        int z_depth;  // 奥行
        int renderSurface;

    public:
        Cube(VECTOR pos, int x_width, int y_height, int z_depth);
        void UpdatePos(VECTOR pos);
        void Draw();

        void DEBUG_ShowWireFrame();
        void DEBUG_HideWireFrame();
    };

    struct CubeObject
    {
        int id;
        Cube object;
    };

    class World
    {
    public:
        std::list<CubeObject> Cubes;

        void AddCube(CubeObject cube);
        void RemoveCube(int id);
        void UpdateACube(int id, VECTOR pos, int x_width, int y_height, int z_depth);
        void Draw();
    };
}

#endif // WORLD_H
