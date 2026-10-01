#include "TestScene.h"
#include <glad/glad.h>     

void TestScene::init()
{
    glClearColor(0.5f, 0.0f, 0.0f, 1.0f);
    /*glEnable(GL_DEPTH_TEST);*/
}
void TestScene::draw(float x, float y, float z, float r, float g, float b)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glPushMatrix();
    glTranslatef(x, y, z);

    glColor3f(r, g, b);
    glBegin(GL_QUADS);
    glVertex3f(-0.5f, 0.5f, 0.0f);
    glVertex3f(-0.5f, -0.5f, 0.0f);
    glVertex3f(0.5f, -0.5f, 0.0f);
    glVertex3f(0.5f, 0.5f, 0.0f);
    glEnd();

    glPopMatrix();
}

