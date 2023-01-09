#pragma once


#include "WorldObject.h"

#include "Texture.h"


class Ground: public WorldObject {


private:
	Texture* texture;

public:
	Ground(Texture* t) : texture(t), 
		WorldObject{ 
			{
				0.0f, 0.0f, 0.0f
			}, 
			{
				0.0f, 0.0f, 0.0f
			}, 
			{ 
				600.0f, 1.0f, 898.87f
			} 
	}
	{};

	void draw() {
		texture->activate();
		activateTransformationMatrix();
		glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 0.0f);  glVertex3f(0.5f, 0.0f, 0.5f);
		glTexCoord2f(5.0f, 0.0f);  glVertex3f(0.5f, 0.0f, -0.5f);
		glTexCoord2f(5.0f, 5.0f);  glVertex3f(-0.5f, 0.0f, -0.5f);
		glTexCoord2f(0.0f, 5.0f);  glVertex3f(-0.5f, 0.0f, 0.5f);
		glPopMatrix();  
		glEnd();
	};

};