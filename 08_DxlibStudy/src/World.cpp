#include "World.h"

using namespace DxLib;
using namespace DxLibStudy;

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
    for (auto it = this->Cubes.begin(); it != this->Cubes.end(); ++it)
    {
        it->object.DrawSurface();
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
