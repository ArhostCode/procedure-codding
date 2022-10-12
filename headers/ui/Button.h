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
    int sizeX;
    int sizeY;
    int id;
    bool isLoadedTexture = false;
    sf::Texture texture;

    Button(int xpos, int ypos, int id, int sx, int sy);

    Button(int xpos, int ypos, int id, int sx, int sy, std::string img);

};


#endif //AUTOMATE_BUTTON_H
