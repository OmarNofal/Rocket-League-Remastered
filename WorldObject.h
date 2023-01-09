#pragma once

#include "glm/glm.hpp"
#include "glut.h"
#include "glm/gtc/matrix_transform.hpp"
  
// abstract class.
// each entity to be placed in the world must inherit from this class
class WorldObject {


private:
	glm::vec3 translation;
	glm::vec3 rotation;
	glm::vec3 scale;

	bool isVisible = true;

public:

	WorldObject() = delete;
	WorldObject(
		glm::vec3 translation = glm::vec3{ 0.0f, 0.0f, 0.0f },
		glm::vec3 rotation = glm::vec3{ 0.0f, 0.0f, 0.0f },
		glm::vec3 scale = glm::vec3{ 1.0f, 1.0f, 1.0f }
	) : translation(translation), rotation(rotation), scale(scale) {	
	};

	glm::vec3 getTranslation() { return translation; };
	glm::vec3 getRotation() { return rotation; };
	glm::vec3 getScale() { return scale; };

	void setTranslation(glm::vec3 newTranslation) {
		translation = newTranslation;
	};

	void setRotation(glm::vec3 newRotation) {
		rotation = newRotation;
	};

	void setScale(glm::vec3 newScale) {
		scale = newScale;
	};

	bool getIsVisible() {
		return isVisible;
	};

	void setVisibility(bool visibility) {
		isVisible = visibility;
	}


	// Don't forget to pop the matrix
	void activateTransformationMatrix() {
		glMatrixMode(GL_MODELVIEW);
		glPushMatrix();
		glLoadIdentity();
		glTranslatef(translation.x, translation.y, translation.z);
		glRotatef(rotation.x, 1.0f, 0.0, 0.0);
		glRotatef(rotation.y, 0.0, 1.0f, 0.0);
		glRotatef(rotation.z, 0.0, 0.0, 1.0f);
		glScalef(scale.x, scale.y, scale.z);
	}

	glm::mat4x4 getRotationMatrix() {
		const auto rotation = getRotation();
		// rotate around the three axes.
		return
			glm::rotate(
				glm::rotate(
					glm::rotate(
						glm::mat4(1),
						glm::radians(rotation.z),
						{ 0.0f, 0.0f, 1.0f }
					),
					glm::radians(rotation.y),
					{ 0.0f, 1.0f, 0.0f }
				),
				glm::radians(rotation.x),
				{ 1.0f, 0.0f, 0.0f }
		);
	}

	virtual void draw() = 0;
};