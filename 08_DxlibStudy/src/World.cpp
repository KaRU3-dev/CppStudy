#include "World.h"

using namespace DxLib;
using namespace DxLibStudy;

void World::Generate()
{
    // Cube size
    int size = 10;

    // 24x24x24
    int scale = 24;
    int height = 24;
    for (int i = 0; i < scale; i++)
    {
        for (int j = 0; j < scale; j++)
        {
            for (int k = 0; k < height; k++)
            {
                VECTOR pos = VGet(i * size, k * size, j * size);
                int x_width = size;
                int y_height = size;
                int z_depth = size;

                CubeObject cubeObject = {
                    i * 100 + j,
                    GameObjects::Cube(pos, textureIds, x_width, y_height, z_depth)};

                this->AddCube(cubeObject);
            }
        }
    }
}

void World::AddCube(CubeObject cube)
{
    this->Cubes.push_back(cube);
}

void World::RemoveCube(int id)
{
    for (auto it = this->Cubes.begin(); it != this->Cubes.end(); ++it)
    {
        if (it->id == id)
        {
            this->Cubes.erase(it);
            break;
        }
    }
}

void World::UpdateACube(int id, VECTOR pos, int x_width, int y_height, int z_depth)
{
    for (auto it = this->Cubes.begin(); it != this->Cubes.end(); ++it)
    {
        if (it->id == id)
        {
            it->object.UpdatePos(pos);
            it->object.UpdateSize(x_width, y_height, z_depth);
            break;
        }
    }
}

void World::Draw()
{
    for (CubeObject cube : this->Cubes)
    {
        cube.object.DrawSurface();
    }
}

void World::DEBUG_ShowWireFrame()
{
    this->isDebug = true;

    for (auto it = this->Cubes.begin(); it != this->Cubes.end(); ++it)
    {
        it->object.DEBUG_ShowWireFrame();
    }
}

void World::DEBUG_HideWireFrame()
{
    this->isDebug = false;

    for (auto it = this->Cubes.begin(); it != this->Cubes.end(); ++it)
    {
        it->object.DEBUG_HideWireFrame();
    }
}
