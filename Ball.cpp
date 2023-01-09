#include "Ball.h"
#include "Texture.h"



Ball::Ball(Texture* tex) : WorldObject(
    { 0.0f, 0.0f, 0.0f },
    { 0.0f, 0.0f, 0.0f },
    { 1.0f, 1.0f, 1.0f }
), ballTexture{ tex }  {


}


void Ball::draw() {

    ballTexture->activate();
    GLUquadric* quad = gluNewQuadric();
    gluQuadricTexture(quad, GL_TRUE);
    gluQuadricOrientation(quad, GLU_OUTSIDE);
    glLoadIdentity();
    gluSphere(quad, 10.0f, 32, 32);

}

