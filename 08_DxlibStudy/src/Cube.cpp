#include "Cube.h"

using namespace DxLibStudy::GameObjects;

Cube::Cube(VECTOR pos, std::array<int, SURFACE_COUNT> textureIds, int x_width, int y_height, int z_depth)
{
    this->pos = pos;
    this->x_width = x_width;
    this->y_height = y_height;
    this->z_depth = z_depth;
    this->renderSurface = TRUE;

    this->textureIds.at(SURFACE_BOTTOM) = textureIds.at(SURFACE_BOTTOM);
    this->textureIds.at(SURFACE_TOP) = textureIds.at(SURFACE_TOP);
    this->textureIds.at(SURFACE_SOUTH) = textureIds.at(SURFACE_SOUTH);
    this->textureIds.at(SURFACE_NORTH) = textureIds.at(SURFACE_NORTH);
    this->textureIds.at(SURFACE_EAST) = textureIds.at(SURFACE_EAST);
    this->textureIds.at(SURFACE_WEST) = textureIds.at(SURFACE_WEST);

    surfaces.at(SURFACE_BOTTOM) = CreateBottomPolygon();
    surfaces.at(SURFACE_TOP) = CreateTopPolygon();
    surfaces.at(SURFACE_SOUTH) = CreateSouthPolygon();
    surfaces.at(SURFACE_NORTH) = CreateNorthPolygon();
    surfaces.at(SURFACE_EAST) = CreateEastPolygon();
    surfaces.at(SURFACE_WEST) = CreateWestPolygon();
}

Cube::~Cube()
{
    for (auto item : textureIds)
    {
        DeleteGraph(item);
    }
}

void Cube::DrawSurface()
{
    for (int i = 0; i < SURFACE_COUNT; i++)
    {
        auto surface = surfaces.at(i);

        if (drawState.at(i) == false)
        {
            for (auto &v : surface)
            {
                v.dif = GetColorU8(0, 0, 0, 0);
            }

            DrawPolygon3D(surface.data(), 6, textureIds.at(i), FALSE);
        }
        else
        {
            DrawPolygon3D(surface.data(), 6, textureIds.at(i), FALSE);
        }
    }

    DrawString(0, 100 + pos.z, "Renderd Surface", GetColor(255, 255, 255));
}

std::array<VERTEX3D, VERTEX_COUNT> Cube::CreateSouthPolygon()
{
    std::array<VERTEX3D, 6> v;

    // 左側三角形
    v[VERTEX_LEFT_BL].pos = VGet(-1 * CUBE_DEFAULT_SIZE + pos.x, -1 * CUBE_DEFAULT_SIZE + pos.y, -1 * CUBE_DEFAULT_SIZE + pos.z);
    v[VERTEX_LEFT_BL].u = 0.0f;
    v[VERTEX_LEFT_BL].v = 1.0f;
    v[VERTEX_LEFT_TL].pos = VGet(-1 * CUBE_DEFAULT_SIZE + pos.x, 1 * CUBE_DEFAULT_SIZE + pos.y, -1 * CUBE_DEFAULT_SIZE + pos.z);
    v[VERTEX_LEFT_TL].u = 0.0f;
    v[VERTEX_LEFT_TL].v = 0.0f;
    v[VERTEX_LEFT_BR].pos = VGet(1 * CUBE_DEFAULT_SIZE + pos.x, -1 * CUBE_DEFAULT_SIZE + pos.y, -1 * CUBE_DEFAULT_SIZE + pos.z);
    v[VERTEX_LEFT_BR].u = 1.0f;
    v[VERTEX_LEFT_BR].v = 1.0f;

    // 右側三角形
    v[VERTEX_RIGHT_BR] = v[VERTEX_LEFT_BR];
    v[VERTEX_RIGHT_TL] = v[VERTEX_LEFT_TL];
    v[VERTEX_RIGHT_TR].pos = VGet(1 * CUBE_DEFAULT_SIZE + pos.x, 1 * CUBE_DEFAULT_SIZE + pos.y, -1 * CUBE_DEFAULT_SIZE + pos.z);
    v[VERTEX_RIGHT_TR].u = 1.0f;
    v[VERTEX_RIGHT_TR].v = 0.0f;

    // 色と法線
    for (int i = 0; i < 6; i++)
    {
        v[i].dif = GetColorU8(255, 255, 255, 255);
        v[i].spc = GetColorU8(0, 0, 0, 0);
        v[i].norm = VGet(0, 0, -1);
    }

    return v;
}

std::array<VERTEX3D, VERTEX_COUNT> Cube::CreateNorthPolygon()
{
    std::array<VERTEX3D, 6> v;

    // 左側三角形
    v[VERTEX_LEFT_BL].pos = VGet(1 * CUBE_DEFAULT_SIZE + pos.x, -1 * CUBE_DEFAULT_SIZE + pos.y, 1 * CUBE_DEFAULT_SIZE + pos.z);
    v[VERTEX_LEFT_BL].u = 0.0f;
    v[VERTEX_LEFT_BL].v = 1.0f;
    v[VERTEX_LEFT_TL].pos = VGet(1 * CUBE_DEFAULT_SIZE + pos.x, 1 * CUBE_DEFAULT_SIZE + pos.y, 1 * CUBE_DEFAULT_SIZE + pos.z);
    v[VERTEX_LEFT_TL].u = 0.0f;
    v[VERTEX_LEFT_TL].v = 0.0f;
    v[VERTEX_LEFT_BR].pos = VGet(-1 * CUBE_DEFAULT_SIZE + pos.x, -1 * CUBE_DEFAULT_SIZE + pos.y, 1 * CUBE_DEFAULT_SIZE + pos.z);
    v[VERTEX_LEFT_BR].u = 1.0f;
    v[VERTEX_LEFT_BR].v = 1.0f;

    // 右側三角形
    v[VERTEX_RIGHT_BR] = v[VERTEX_LEFT_BR];
    v[VERTEX_RIGHT_TL] = v[VERTEX_LEFT_TL];
    v[VERTEX_RIGHT_TR].pos = VGet(-1 * CUBE_DEFAULT_SIZE + pos.x, 1 * CUBE_DEFAULT_SIZE + pos.y, 1 * CUBE_DEFAULT_SIZE + pos.z);
    v[VERTEX_RIGHT_TR].u = 1.0f;
    v[VERTEX_RIGHT_TR].v = 0.0f;

    // 色と法線
    for (int i = 0; i < 6; i++)
    {
        v[i].dif = GetColorU8(255, 255, 255, 255);
        v[i].spc = GetColorU8(0, 0, 0, 0);
        v[i].norm = VGet(0, 0, 1);
    }

    return v;
}

std::array<VERTEX3D, VERTEX_COUNT> Cube::CreateWestPolygon()
{
    std::array<VERTEX3D, 6> v;

    // 左側三角形
    v[VERTEX_LEFT_BL].pos = VGet(-1 * CUBE_DEFAULT_SIZE + pos.x, -1 * CUBE_DEFAULT_SIZE + pos.y, 1 * CUBE_DEFAULT_SIZE + pos.z);
    v[VERTEX_LEFT_BL].u = 0.0f;
    v[VERTEX_LEFT_BL].v = 1.0f;
    v[VERTEX_LEFT_TL].pos = VGet(-1 * CUBE_DEFAULT_SIZE + pos.x, 1 * CUBE_DEFAULT_SIZE + pos.y, 1 * CUBE_DEFAULT_SIZE + pos.z);
    v[VERTEX_LEFT_TL].u = 0.0f;
    v[VERTEX_LEFT_TL].v = 0.0f;
    v[VERTEX_LEFT_BR].pos = VGet(-1 * CUBE_DEFAULT_SIZE + pos.x, -1 * CUBE_DEFAULT_SIZE + pos.y, -1 * CUBE_DEFAULT_SIZE + pos.z);
    v[VERTEX_LEFT_BR].u = 1.0f;
    v[VERTEX_LEFT_BR].v = 1.0f;

    // 右側三角形
    v[VERTEX_RIGHT_BR] = v[VERTEX_LEFT_BR];
    v[VERTEX_RIGHT_TL] = v[VERTEX_LEFT_TL];
    v[VERTEX_RIGHT_TR].pos = VGet(-1 * CUBE_DEFAULT_SIZE + pos.x, 1 * CUBE_DEFAULT_SIZE + pos.y, -1 * CUBE_DEFAULT_SIZE + pos.z);
    v[VERTEX_RIGHT_TR].u = 1.0f;
    v[VERTEX_RIGHT_TR].v = 0.0f;

    // 色と法線
    for (int i = 0; i < 6; i++)
    {
        v[i].dif = GetColorU8(255, 255, 255, 255);
        v[i].spc = GetColorU8(0, 0, 0, 0);
        v[i].norm = VGet(-1, 0, 0);
    }

    return v;
}

std::array<VERTEX3D, VERTEX_COUNT> Cube::CreateEastPolygon()
{
    std::array<VERTEX3D, 6> v;

    // 左側三角形
    v[VERTEX_LEFT_BL].pos = VGet(1 * CUBE_DEFAULT_SIZE + pos.x, -1 * CUBE_DEFAULT_SIZE + pos.y, -1 * CUBE_DEFAULT_SIZE + pos.z);
    v[VERTEX_LEFT_BL].u = 0.0f;
    v[VERTEX_LEFT_BL].v = 1.0f;
    v[VERTEX_LEFT_TL].pos = VGet(1 * CUBE_DEFAULT_SIZE + pos.x, 1 * CUBE_DEFAULT_SIZE + pos.y, -1 * CUBE_DEFAULT_SIZE + pos.z);
    v[VERTEX_LEFT_TL].u = 0.0f;
    v[VERTEX_LEFT_TL].v = 0.0f;
    v[VERTEX_LEFT_BR].pos = VGet(1 * CUBE_DEFAULT_SIZE + pos.x, -1 * CUBE_DEFAULT_SIZE + pos.y, 1 * CUBE_DEFAULT_SIZE + pos.z);
    v[VERTEX_LEFT_BR].u = 1.0f;
    v[VERTEX_LEFT_BR].v = 1.0f;

    // 右側三角形
    v[VERTEX_RIGHT_BR] = v[VERTEX_LEFT_BR];
    v[VERTEX_RIGHT_TL] = v[VERTEX_LEFT_TL];
    v[VERTEX_RIGHT_TR].pos = VGet(1 * CUBE_DEFAULT_SIZE + pos.x, 1 * CUBE_DEFAULT_SIZE + pos.y, 1 * CUBE_DEFAULT_SIZE + pos.z);
    v[VERTEX_RIGHT_TR].u = 1.0f;
    v[VERTEX_RIGHT_TR].v = 0.0f;

    // 色と法線
    for (int i = 0; i < 6; i++)
    {
        v[i].dif = GetColorU8(255, 255, 255, 255);
        v[i].spc = GetColorU8(0, 0, 0, 0);
        v[i].norm = VGet(1, 0, 0);
    }

    return v;
}

std::array<VERTEX3D, VERTEX_COUNT> Cube::CreateTopPolygon()
{
    std::array<VERTEX3D, 6> v;

    // 左側三角形
    v[VERTEX_LEFT_BL].pos = VGet(-1 * CUBE_DEFAULT_SIZE + pos.x, 1 * CUBE_DEFAULT_SIZE + pos.y, -1 * CUBE_DEFAULT_SIZE + pos.z);
    v[VERTEX_LEFT_BL].u = 0.0f;
    v[VERTEX_LEFT_BL].v = 1.0f;
    v[VERTEX_LEFT_TL].pos = VGet(-1 * CUBE_DEFAULT_SIZE + pos.x, 1 * CUBE_DEFAULT_SIZE + pos.y, 1 * CUBE_DEFAULT_SIZE + pos.z);
    v[VERTEX_LEFT_TL].u = 0.0f;
    v[VERTEX_LEFT_TL].v = 0.0f;
    v[VERTEX_LEFT_BR].pos = VGet(1 * CUBE_DEFAULT_SIZE + pos.x, 1 * CUBE_DEFAULT_SIZE + pos.y, -1 * CUBE_DEFAULT_SIZE + pos.z);
    v[VERTEX_LEFT_BR].u = 1.0f;
    v[VERTEX_LEFT_BR].v = 1.0f;

    // 右側三角形
    v[VERTEX_RIGHT_BR] = v[VERTEX_LEFT_BR];
    v[VERTEX_RIGHT_TL] = v[VERTEX_LEFT_TL];
    v[VERTEX_RIGHT_TR].pos = VGet(1 * CUBE_DEFAULT_SIZE + pos.x, 1 * CUBE_DEFAULT_SIZE + pos.y, 1 * CUBE_DEFAULT_SIZE + pos.z);
    v[VERTEX_RIGHT_TR].u = 1.0f;
    v[VERTEX_RIGHT_TR].v = 0.0f;

    // 色と法線
    for (int i = 0; i < 6; i++)
    {
        v[i].dif = GetColorU8(255, 255, 255, 255);
        v[i].spc = GetColorU8(0, 0, 0, 0);
        v[i].norm = VGet(0, 1, 0);
    }

    return v;
}

std::array<VERTEX3D, VERTEX_COUNT> Cube::CreateBottomPolygon()
{
    std::array<VERTEX3D, 6> v;

    // SIZE = CUBE_DEFAULT_SIZE

    // 左側三角形
    v[VERTEX_LEFT_BL].pos = VGet(-1 * CUBE_DEFAULT_SIZE + pos.x, -1 * CUBE_DEFAULT_SIZE + pos.y, 1 * CUBE_DEFAULT_SIZE + pos.z);
    v[VERTEX_LEFT_BL].u = 0.0f;
    v[VERTEX_LEFT_BL].v = 1.0f;
    v[VERTEX_LEFT_TL].pos = VGet(-1 * CUBE_DEFAULT_SIZE + pos.x, -1 * CUBE_DEFAULT_SIZE + pos.y, -1 * CUBE_DEFAULT_SIZE + pos.z);
    v[VERTEX_LEFT_TL].u = 0.0f;
    v[VERTEX_LEFT_TL].v = 0.0f;
    v[VERTEX_LEFT_BR].pos = VGet(1 * CUBE_DEFAULT_SIZE + pos.x, -1 * CUBE_DEFAULT_SIZE + pos.y, 1 * CUBE_DEFAULT_SIZE + pos.z);
    v[VERTEX_LEFT_BR].u = 1.0f;
    v[VERTEX_LEFT_BR].v = 1.0f;

    // 右側三角形
    v[VERTEX_RIGHT_BR] = v[VERTEX_LEFT_BR];
    v[VERTEX_RIGHT_TL] = v[VERTEX_LEFT_TL];
    v[VERTEX_RIGHT_TR].pos = VGet(1 * CUBE_DEFAULT_SIZE + pos.x, -1 * CUBE_DEFAULT_SIZE + pos.y, -1 * CUBE_DEFAULT_SIZE + pos.z);
    v[VERTEX_RIGHT_TR].u = 1.0f;
    v[VERTEX_RIGHT_TR].v = 0.0f;

    // 色と法線
    for (int i = 0; i < 6; i++)
    {
        v[i].dif = GetColorU8(255, 255, 255, 255);
        v[i].spc = GetColorU8(0, 0, 0, 0);
        v[i].norm = VGet(0, -1, 0);
    }

    return v;
}

void Cube::UpdatePos(VECTOR pos)
{
    //
}

void Cube::UpdateSize(int x_width, int y_height, int z_depth)
{
    //
}

void Cube::DEBUG_ShowWireFrame()
{
    //
}

void Cube::DEBUG_HideWireFrame()
{
    //
}
