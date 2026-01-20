#include "Cube.h"

using namespace DxLibStudy::GameObjects;

Cube::Cube(VECTOR pos, int x_width, int y_height, int z_depth)
{
    this->pos = pos;
    this->x_width = x_width;
    this->y_height = y_height;
    this->z_depth = z_depth;
    this->renderSurface = TRUE;

    BOTTOM_GRAPH = LoadGraph("assets/images/CubeSurface_bottom.png", FALSE);
    TOP_GRAPH = LoadGraph("assets/images/CubeSurface_top.png", FALSE);
    SOUTH_GRAPH = LoadGraph("assets/images/CubeSurface_south.png", FALSE);
    NORTH_GRAPH = LoadGraph("assets/images/CubeSurface_north.png", FALSE);
    EAST_GRAPH = LoadGraph("assets/images/CubeSurface_east.png", FALSE);
    WEST_GRAPH = LoadGraph("assets/images/CubeSurface_west.png", FALSE);

    CreateSurface();
}

Cube::~Cube()
{
    DeleteGraph(BOTTOM_GRAPH);
    DeleteGraph(TOP_GRAPH);
    DeleteGraph(SOUTH_GRAPH);
    DeleteGraph(NORTH_GRAPH);
    DeleteGraph(EAST_GRAPH);
    DeleteGraph(WEST_GRAPH);
}

void Cube::DrawSurface()
{
    for (int i = 0; i < SURFACE_COUNT; i++)
    {
        int TexID;
        switch (i)
        {
        case SURFACE_BOTTOM:
            TexID = BOTTOM_GRAPH;
            break;
        case SURFACE_TOP:
            TexID = TOP_GRAPH;
            break;
        case SURFACE_SOUTH:
            TexID = SOUTH_GRAPH;
            break;
        case SURFACE_NORTH:
            TexID = NORTH_GRAPH;
            break;
        case SURFACE_EAST:
            TexID = EAST_GRAPH;
            break;
        case SURFACE_WEST:
            TexID = WEST_GRAPH;
            break;
        }

        VERTEX3D v[6];
        for (int j = 0; j < 6; j++)
        {
            v[j].pos = surfaces.at(i)[j].pos;
            v[j].dif = surfaces.at(i)[j].dif;
            v[j].norm = surfaces.at(i)[j].norm;
            v[j].u = surfaces.at(i)[j].u;
            v[j].v = surfaces.at(i)[j].v;
        }

        DrawPolygon3D(v, 6, TexID, !renderSurface);
    }
}

void Cube::CreateSurface()
{
    surfaces.at(SURFACE_BOTTOM) = CreateBottomPolygon();
    surfaces.at(SURFACE_TOP) = CreateTopPolygon();
    surfaces.at(SURFACE_SOUTH) = CreateSouthPolygon();
    surfaces.at(SURFACE_NORTH) = CreateNorthPolygon();
    surfaces.at(SURFACE_EAST) = CreateEastPolygon();
    surfaces.at(SURFACE_WEST) = CreateWestPolygon();
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
