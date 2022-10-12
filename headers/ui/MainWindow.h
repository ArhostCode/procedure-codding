//
// Created by e-gul on 12.10.2022.
//

#ifndef AUTOMATE_MAINWINDOW_H
#define AUTOMATE_MAINWINDOW_H

#include <SFML/System/Time.hpp>

#include <SFML/Graphics.hpp>
#include <vector>
#include "Field.h"
#include "Engine.hpp"
#include "future"

using namespace sf;
using namespace std;

class MainWindow {
private:
    Vector2f resolution;
    RenderWindow window;
    const unsigned int FPS = 60;
    Engine engine;
    Font font;

public:

    MainWindow(Engine engine);

    void input();

    void draw();

    void run();

};


#endif //AUTOMATE_MAINWINDOW_H
