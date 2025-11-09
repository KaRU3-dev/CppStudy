#include <iostream>

#include <GL/freeglut.h>
#include "imgui.h"
#include "backends/imgui_impl_glut.h"
#include "backends/imgui_impl_opengl2.h"

void display()
{
    int w = glutGet(GLUT_WINDOW_WIDTH);
    int h = glutGet(GLUT_WINDOW_HEIGHT);
    if (w <= 0 || h <= 0)
    {
        // ウィンドウがまだ有効でないなら何もしない（または短絡的に reshape を呼ぶ）
        return;
    }

    // 1) クリア
    glClearColor(0.1f, 0.12f, 0.15f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // 2) 自前描画（GL state を保存）
    glPushAttrib(GL_ALL_ATTRIB_BITS);
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();

    // （必要なら適切な投影をセット）
    // glMatrixMode(GL_PROJECTION);
    // glLoadIdentity();
    // glOrtho(-1,1,-1,1,-1,1);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glBegin(GL_POLYGON);
    glColor3d(1.0, 0.0, 0.0);
    glVertex2d(-0.9, -0.9);
    glColor3d(0.0, 1.0, 0.0);
    glVertex2d(0.9, -0.9);
    glColor3d(0.0, 0.0, 1.0);
    glVertex2d(0.9, 0.9);
    glColor3d(1.0, 1.0, 0.0);
    glVertex2d(-0.9, 0.9);
    glEnd();

    // restore
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
    glPopMatrix();
    glPopAttrib();

    // 3) ImGui フレーム（順序に注意）
    ImGui_ImplGLUT_NewFrame();
    ImGui_ImplOpenGL2_NewFrame();
    ImGui::NewFrame();

    // 4) ImGui ウィジェット
    ImGui::Begin("Demo Window");
    ImGui::Text("Hello, ImGui + freeglut!");
    static float f = 0.0f;
    ImGui::SliderFloat("float", &f, 0.0f, 1.0f);
    if (ImGui::Button("Quit"))
    {
        glutLeaveMainLoop();
    }
    ImGui::End();

    // 5) Render ImGui and swap
    ImGui::Render();
    ImGui_ImplOpenGL2_RenderDrawData(ImGui::GetDrawData());
    glutSwapBuffers();
}
void reshape(int w, int h)
{
    if (h == 0)
        h = 1;

    glViewport(0, 0, w, h);
}

void init()
{
    glClearColor(0.0, 0.0, 0.0, 1.0);
}

int main(int argc, char **argv)
{
    std::cout << "Hello, MinGW!" << std::endl;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("ImGui + freeglut Example");
    reshape(800, 600);

    init();

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    int w = glutGet(GLUT_WINDOW_WIDTH);
    int h = glutGet(GLUT_WINDOW_HEIGHT);
    if (w <= 0)
        w = 800;
    if (h <= 0)
        h = 600;
    ImGuiIO &io = ImGui::GetIO();
    io.DisplaySize = ImVec2((float)w, (float)h);
    ImGui::StyleColorsDark();

    ImGui_ImplGLUT_Init();
    ImGui_ImplOpenGL2_Init();

    ImGui_ImplGLUT_InstallFuncs();

    glutReshapeFunc(reshape);
    glutDisplayFunc(display);

    glutIdleFunc([]()
                 { glutPostRedisplay(); });

    glutMainLoop();

    ImGui_ImplOpenGL2_Shutdown();
    ImGui_ImplGLUT_Shutdown();
    ImGui::DestroyContext();

    return 0;
}
