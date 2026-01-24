#pragma once
#include "DxLib.h"
#include "Cube.h"
#include "PerlinNoise.hpp"

#include <list>
#include <string>

#ifndef WORLD_H
#define WORLD_H
namespace DxLibStudy
{
    struct Chunk
    {
        std::list<int> blocks; // 8 x 8 = 64 blocks * 256
    };

    struct Region
    {
        std::list<Chunk> chunks; // 32 * 32 = 1024 chunks
    };

    // Generate chunk with perlin noise -> https://github.com/Reputeless/PerlinNoise
    // 1. demention select
    // 2. biome select
    // 3. set biome area
    // 4. generate blocks
    // *. set cabe area
    // *. set village area
    // *. generate nature
    // WORLD = blocks + cabe + trees + village

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
