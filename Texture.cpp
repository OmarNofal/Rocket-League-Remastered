#include "Texture.h"


Texture::Texture() {

}

Texture::Texture(GLuint tex) {
    textureId = tex;
}

Texture Texture::loadTexture(std::string path) {

    int width, height, channels;

    stbi_set_flip_vertically_on_load(true);
    unsigned char* data = stbi_load(path.c_str(), &width, &height, &channels, 3);

    GLuint textureId;
    glEnable(GL_TEXTURE_2D);
    glGenTextures(1, &textureId);

    glBindTexture(GL_TEXTURE_2D, textureId);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    gluBuild2DMipmaps(GL_TEXTURE_2D, 3, width, height, GL_RGB, GL_UNSIGNED_BYTE, data);

    delete data;

    printf("Loaded texture with id: %dl", textureId);

    return Texture(textureId);
}

GLuint Texture::getTextureId()
{
    return textureId;
}


void Texture::activate() {
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, textureId);
}