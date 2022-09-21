//
// Created by ardyc-user on 17.09.2022.
//

#ifndef AUTOMATE_BUTTON_H
#define AUTOMATE_BUTTON_H

#include <SFML/Graphics/Texture.hpp>
#include "string"

class Button {
public:
    int posx;
    int posy;
    sf::Texture texture;

    int sx;
    int sy;
    int id;

    std::string img = "null";

    Button(int xpos, int ypos, int id, int sx, int sy) {
        this->posx = xpos;
        this->posy = ypos;
        this->sx = sx;
        this->sy = sy;
        this->id = id;
    }

    Button(int xpos, int ypos, int id, int sx, int sy, std::string img) {
        this->posx = xpos;
        this->posy = ypos;
        this->sx = sx;
        this->sy = sy;
        this->id = id;
        this->img = img;
        texture.loadFromFile(img, sf::IntRect(0, 0, sx, sy));
    }

};


#endif //AUTOMATE_BUTTON_H
