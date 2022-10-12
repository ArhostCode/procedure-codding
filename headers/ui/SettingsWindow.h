//
// Created by ardyc-user on 17.09.2022.
//

#ifndef AUTOMATE_SETTINGSWINDOW_H
#define AUTOMATE_SETTINGSWINDOW_H

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
using namespace sf;
#include <vector>
#include "Settings.h"
#include "Button.h"

using namespace std;

class SettingsWindow {
public:
    sf::Texture texture;
    SettingsWindow();
    Settings settings;
    vector<Button> buttons;
    void run();
    void input();
    void draw();
    RenderWindow window;
};


#endif //AUTOMATE_SETTINGSWINDOW_H
