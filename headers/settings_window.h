//
// Created by ardyc-user on 17.09.2022.
//

#ifndef AUTOMATE_SETTINGS_WINDOW_H
#define AUTOMATE_SETTINGS_WINDOW_H

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
using namespace sf;
#include <vector>
#include "settings.h"
#include "Button.h"

using namespace std;

class settings_window {
public:
    sf::Texture texture;
    settings_window();
    settings settings;
    vector<Button> buttons;
    void run();
    void input();
    void draw();
    RenderWindow window;
};


#endif //AUTOMATE_SETTINGS_WINDOW_H
