#pragma once

#include "glm/glm.hpp"

  
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
		glm::vec3 translation, 
		glm::vec3 rotation, 
		glm::vec3 scale
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


	virtual void draw() = 0;
};