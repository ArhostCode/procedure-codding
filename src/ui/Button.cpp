//
// Created by ardyc-user on 17.09.2022.
//

#include "ui/Button.h"

Button::Button(int xpos, int ypos, int id, int sx, int sy) {
    this->posx = xpos;
    this->posy = ypos;
    this->sizeX = sx;
    this->sizeY = sy;
    this->id = id;
}

Button::Button(int xpos, int ypos, int id, int sx, int sy, std::string img) {
    this->posx = xpos;
    this->posy = ypos;
    this->sizeX = sx;
    this->sizeY = sy;
    this->id = id;
    this->isLoadedTexture = true;
    texture.loadFromFile(img, sf::IntRect(0, 0, sx, sy));
}