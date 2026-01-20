#include "Cube.h"

using namespace DxLibStudy::GameObjects;

Cube::Cube(VECTOR pos, int x_width, int y_height, int z_depth)
{
    this->pos = pos;
    this->x_width = x_width;
    this->y_height = y_height;
    this->z_depth = z_depth;
    this->renderSurface = TRUE;

    textureIds.at(SURFACE_BOTTOM) = LoadGraph("assets/images/CubeSurface_bottom.png");
    textureIds.at(SURFACE_TOP) = LoadGraph("assets/images/CubeSurface_top.png");
    textureIds.at(SURFACE_SOUTH) = LoadGraph("assets/images/CubeSurface_south.png");
    textureIds.at(SURFACE_NORTH) = LoadGraph("assets/images/CubeSurface_north.png");
    textureIds.at(SURFACE_EAST) = LoadGraph("assets/images/CubeSurface_east.png");
    textureIds.at(SURFACE_WEST) = LoadGraph("assets/images/CubeSurface_west.png");

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
}

std::array<VERTEX3D, VERTEX_COUNT> Cube::CreateSouthPolygon()
{
    std::array<VERTEX3D, 6> v;

    // 左側三角形
    v[VERTEX_LEFT_BL].pos = VGet(-100, -100, -100);
    v[VERTEX_LEFT_BL].u = 0.0f;
    v[VERTEX_LEFT_BL].v = 1.0f;
    v[VERTEX_LEFT_TL].pos = VGet(-100, 100, -100);
    v[VERTEX_LEFT_TL].u = 0.0f;
    v[VERTEX_LEFT_TL].v = 0.0f;
    v[VERTEX_LEFT_BR].pos = VGet(100, -100, -100);
    v[VERTEX_LEFT_BR].u = 1.0f;
    v[VERTEX_LEFT_BR].v = 1.0f;

    // 右側三角形
    v[VERTEX_RIGHT_BR] = v[VERTEX_LEFT_BR];
    v[VERTEX_RIGHT_TL] = v[VERTEX_LEFT_TL];
    v[VERTEX_RIGHT_TR].pos = VGet(100, 100, -100);
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
    v[VERTEX_LEFT_BL].pos = VGet(100, -100, 100);
    v[VERTEX_LEFT_BL].u = 0.0f;
    v[VERTEX_LEFT_BL].v = 1.0f;
    v[VERTEX_LEFT_TL].pos = VGet(100, 100, 100);
    v[VERTEX_LEFT_TL].u = 0.0f;
    v[VERTEX_LEFT_TL].v = 0.0f;
    v[VERTEX_LEFT_BR].pos = VGet(-100, -100, 100);
    v[VERTEX_LEFT_BR].u = 1.0f;
    v[VERTEX_LEFT_BR].v = 1.0f;

    // 右側三角形
    v[VERTEX_RIGHT_BR] = v[VERTEX_LEFT_BR];
    v[VERTEX_RIGHT_TL] = v[VERTEX_LEFT_TL];
    v[VERTEX_RIGHT_TR].pos = VGet(-100, 100, 100);
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
    v[VERTEX_LEFT_BL].pos = VGet(-100, -100, 100);
    v[VERTEX_LEFT_BL].u = 0.0f;
    v[VERTEX_LEFT_BL].v = 1.0f;
    v[VERTEX_LEFT_TL].pos = VGet(-100, 100, 100);
    v[VERTEX_LEFT_TL].u = 0.0f;
    v[VERTEX_LEFT_TL].v = 0.0f;
    v[VERTEX_LEFT_BR].pos = VGet(-100, -100, -100);
    v[VERTEX_LEFT_BR].u = 1.0f;
    v[VERTEX_LEFT_BR].v = 1.0f;

    // 右側三角形
    v[VERTEX_RIGHT_BR] = v[VERTEX_LEFT_BR];
    v[VERTEX_RIGHT_TL] = v[VERTEX_LEFT_TL];
    v[VERTEX_RIGHT_TR].pos = VGet(-100, 100, -100);
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
    v[VERTEX_LEFT_BL].pos = VGet(100, -100, -100);
    v[VERTEX_LEFT_BL].u = 0.0f;
    v[VERTEX_LEFT_BL].v = 1.0f;
    v[VERTEX_LEFT_TL].pos = VGet(100, 100, -100);
    v[VERTEX_LEFT_TL].u = 0.0f;
    v[VERTEX_LEFT_TL].v = 0.0f;
    v[VERTEX_LEFT_BR].pos = VGet(100, -100, 100);
    v[VERTEX_LEFT_BR].u = 1.0f;
    v[VERTEX_LEFT_BR].v = 1.0f;

    // 右側三角形
    v[VERTEX_RIGHT_BR] = v[VERTEX_LEFT_BR];
    v[VERTEX_RIGHT_TL] = v[VERTEX_LEFT_TL];
    v[VERTEX_RIGHT_TR].pos = VGet(100, 100, 100);
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
    v[VERTEX_LEFT_BL].pos = VGet(-100, 100, -100);
    v[VERTEX_LEFT_BL].u = 0.0f;
    v[VERTEX_LEFT_BL].v = 1.0f;
    v[VERTEX_LEFT_TL].pos = VGet(-100, 100, 100);
    v[VERTEX_LEFT_TL].u = 0.0f;
    v[VERTEX_LEFT_TL].v = 0.0f;
    v[VERTEX_LEFT_BR].pos = VGet(100, 100, -100);
    v[VERTEX_LEFT_BR].u = 1.0f;
    v[VERTEX_LEFT_BR].v = 1.0f;

    // 右側三角形
    v[VERTEX_RIGHT_BR] = v[VERTEX_LEFT_BR];
    v[VERTEX_RIGHT_TL] = v[VERTEX_LEFT_TL];
    v[VERTEX_RIGHT_TR].pos = VGet(100, 100, 100);
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

    // 左側三角形
    v[VERTEX_LEFT_BL].pos = VGet(-100, -100, 100);
    v[VERTEX_LEFT_BL].u = 0.0f;
    v[VERTEX_LEFT_BL].v = 1.0f;
    v[VERTEX_LEFT_TL].pos = VGet(-100, -100, -100);
    v[VERTEX_LEFT_TL].u = 0.0f;
    v[VERTEX_LEFT_TL].v = 0.0f;
    v[VERTEX_LEFT_BR].pos = VGet(100, -100, 100);
    v[VERTEX_LEFT_BR].u = 1.0f;
    v[VERTEX_LEFT_BR].v = 1.0f;

    // 右側三角形
    v[VERTEX_RIGHT_BR] = v[VERTEX_LEFT_BR];
    v[VERTEX_RIGHT_TL] = v[VERTEX_LEFT_TL];
    v[VERTEX_RIGHT_TR].pos = VGet(100, -100, -100);
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
