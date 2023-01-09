



#include "Player.h"
#include <iostream>
#include "stb_image.h"
#include "glm/gtc/matrix_transform.hpp"


Player::Player(Texture* carTexture) : WorldObject(
    { 0.0f, 0.0f, 0.0f },
    { -90.0f, 0.0f, 0.0f },
    { 1.0f, 1.0f, 1.0f }),
    texture(carTexture)
{


    std::string inputfile = "res/RCCar/10600_RC_Car_SG_v2_L3.obj";
    tinyobj::ObjReaderConfig reader_config;
    reader_config.mtl_search_path = "res/RCCar/"; // Path to material files

    tinyobj::ObjReader reader;

    if (!reader.ParseFromFile(inputfile, reader_config)) {
        if (!reader.Error().empty()) {
            std::cerr << "TinyObjReader: " << reader.Error();
        }
        exit(1);
    }

    if (!reader.Warning().empty()) {
        std::cout << "TinyObjReader: " << reader.Warning();
    }

    auto& attrib = reader.GetAttrib();
    auto& shapes = reader.GetShapes();

    this->attributes = attrib;
    this->shapes = shapes;
};



void Player::draw() {

    activateTransformationMatrix();
    texture->activate();
    glBegin(GL_TRIANGLES);
    glMatrixMode(GL_MODELVIEW);
    size_t index_offset = 0;
    for (size_t f = 0; f < shapes[0].mesh.num_face_vertices.size(); f++) {
        size_t fv = size_t(shapes[0].mesh.num_face_vertices[f]);

        // Loop over vertices in the face.
        for (size_t v = 0; v < fv; v++) {
            // access to vertex
            tinyobj::index_t idx = shapes[0].mesh.indices[index_offset + v];
            tinyobj::real_t vx = attributes.vertices[3 * size_t(idx.vertex_index) + 0];
            tinyobj::real_t vy = attributes.vertices[3 * size_t(idx.vertex_index) + 1];
            tinyobj::real_t vz = attributes.vertices[3 * size_t(idx.vertex_index) + 2];



            // Check if `normal_index` is zero or positive. negative = no normal data
            if (idx.normal_index >= 0) {
                tinyobj::real_t nx = attributes.normals[3 * size_t(idx.normal_index) + 0];
                tinyobj::real_t ny = attributes.normals[3 * size_t(idx.normal_index) + 1];
                tinyobj::real_t nz = attributes.normals[3 * size_t(idx.normal_index) + 2];
            }

            // Check if `texcoord_index` is zero or positive. negative = no texcoord data
            if (idx.texcoord_index >= 0) {
                tinyobj::real_t tx = attributes.texcoords[2 * size_t(idx.texcoord_index) + 0];
                tinyobj::real_t ty = attributes.texcoords[2 * size_t(idx.texcoord_index) + 1];

                glTexCoord2f(tx, ty);
            }


            glVertex3f(vx, vy, vz);

        }
        index_offset += fv;
    }
    glPopMatrix();
    glEnd();
};


void Player::move(float ds) {

    const float velocity = 60.0f;

    const auto forwardVector = getForwardVector();

    setTranslation(getTranslation() + forwardVector * velocity * ds);

};


glm::vec3 Player::getForwardVector() {

    
    const auto rotationMatrix = getRotationMatrix();

    // multiply by the original forward vector and cast it to vec3
    return glm::vec3((rotationMatrix * glm::vec4{0.0f, -1.0f, 0.0f, 1.0f}));

}


glm::vec3 Player::getUpVector() {
    const auto rotationMatrix = getRotationMatrix();

    return glm::vec3((rotationMatrix * glm::vec4{ 0.0f, 1.0f, 0.0f, 1.0f }));
}