#pragma once

#include "WorldObject.h"
#include "Texture.h"
#include "glut.h"
#include <vector>
#include "glm/glm.hpp"
#include "tiny_obj_loader.h"


// The car
class Player : public WorldObject {


private:
	std::vector<glm::vec3> vertices;
	std::vector<glm::vec3> normals;
	std::vector<glm::vec3> triangleFaces;

	tinyobj::attrib_t attributes;
	std::vector<tinyobj::shape_t> shapes;

	Texture* texture;

public:

	Player(Texture* carTexture);
	void draw();


	glm::vec3 getForwardVector();
	glm::vec3 getUpVector();

	void move(float ds);
};