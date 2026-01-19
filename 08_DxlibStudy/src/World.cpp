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
#pragma endregion
