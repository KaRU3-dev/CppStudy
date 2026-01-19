#include "World.h"

using namespace DxLib;
using namespace DxLibStudy;

#pragma region Cube
Cube::Cube(VECTOR pos, int x_width, int y_height, int z_depth)
{
    this->pos = pos;
    this->x_width = x_width;
    this->y_height = y_height;
    this->z_depth = z_depth;
    this->renderSurface = TRUE;
}

void Cube::UpdatePos(VECTOR pos)
{
    this->pos = pos;
}

void Cube::UpdateSize(int x_width, int y_height, int z_depth)
{
    this->x_width = x_width;
    this->y_height = y_height;
    this->z_depth = z_depth;
}

void Cube::Draw()
{
    VECTOR origin = VGet(
        this->pos.x,
        this->pos.y,
        this->pos.z);
    VECTOR diag = VGet(
        this->pos.x + this->x_width,
        this->pos.y + this->y_height,
        this->pos.z + this->z_depth);

    DrawCube3D(
        origin,
        diag,
        GetColor(255, 255, 0),
        GetColor(0, 0, 0),
        this->renderSurface);
}

void Cube::DEBUG_ShowWireFrame()
{
    this->renderSurface = FALSE;
}

void Cube::DEBUG_HideWireFrame()
{
    this->renderSurface = TRUE;
}
#pragma endregion

#pragma region World
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
        it->object.Draw();
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
#pragma endregion
