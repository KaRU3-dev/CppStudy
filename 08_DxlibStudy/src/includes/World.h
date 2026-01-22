#pragma once
#include "DxLib.h"
#include "Cube.h"

#include <list>
#include <string>

#ifndef WORLD_H
#define WORLD_H
namespace DxLibStudy
{
    struct CubeObject
    {
        int id;
        DxLibStudy::GameObjects::Cube object;
    };

    class World
    {
    public:
        std::array<int, 6> textureIds;
        std::list<CubeObject> Cubes;
        bool isDebug = false;

        void Generate();

        void AddCube(CubeObject cube);
        void RemoveCube(int id);
        void UpdateACube(int id, VECTOR pos, int x_width, int y_height, int z_depth);
        void Draw();

        void DEBUG_ShowWireFrame();
        void DEBUG_HideWireFrame();
    };
}

#endif // WORLD_H
