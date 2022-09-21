#include <iostream>
#include "engine.hpp"
#include "settings_window.h"

void Engine::input() {
    Event event{};

    while (window.pollEvent(event)) {
        // Window closed
        if (event.type == Event::Closed) {
            window.close();
        }

        // Handle Keyboard Input
        if (event.type == Event::KeyPressed) {
            // Quit
            if (Keyboard::isKeyPressed(Keyboard::Escape)) {
                window.close();
            }

            if (Keyboard::isKeyPressed(Keyboard::Num1)) {
                processFigure(1);
            }
            if (Keyboard::isKeyPressed(Keyboard::Num2)) {
                processFigure(2);
            }
            if (Keyboard::isKeyPressed(Keyboard::Num3)) {
                processFigure(3);
            }
            if (Keyboard::isKeyPressed(Keyboard::Num4)) {
                processFigure(4);
            }
            if (Keyboard::isKeyPressed(Keyboard::Num5)) {
                processFigure(5);
            }
            if (Keyboard::isKeyPressed(Keyboard::Num6)) {
                processFigure(6);
            }
            if (Keyboard::isKeyPressed(Keyboard::Num7)) {
                processFigure(7);
            }
            if (Keyboard::isKeyPressed(Keyboard::Space)) {
                std::cout << field.countFit();
            }
        }

    }
}


void settings_window::input() {
    Event event{};

    while (window.pollEvent(event)) {
        // Window closed
        if (event.type == Event::Closed) {
            window.close();
        }

        // Handle Keyboard Input
        if (event.type == Event::KeyPressed) {
            // Quit
            if (Keyboard::isKeyPressed(Keyboard::Escape)) {
                window.close();
            }

        }

        if (event.type == Event::MouseButtonPressed) {

            for (auto &button: buttons) {
                int x = Mouse::getPosition(window).x;
                int y = Mouse::getPosition(window).y;


                if (y >= button.posy && y <= button.posy + button.sy && x >= button.posx && x <= button.posx + button.sx) {
                    if (button.id == 0) {
                        settings.squareCountMax -= 1;
                    }
                    if (button.id == 1) {
                        settings.rectCountMax -= 1;
                    }
                    if (button.id == 2) {
                        settings.stairsCountMax -= 1;
                    }
                    if (button.id == 3) {
                        settings.stairs2CountMax -= 1;
                    }
                    if (button.id == 4) {
                        settings.squareCountMax += 1;
                    }
                    if (button.id == 5) {
                        settings.rectCountMax += 1;
                    }
                    if (button.id == 6) {
                        settings.stairsCountMax += 1;
                    }
                    if (button.id == 7) {
                        settings.stairs2CountMax += 1;
                    }
                    if (button.id == 8) {
                        window.close();
                        Engine engine;
                        engine.settings = settings;
                        engine.init();
                        engine.run();
                    }
                }

            }
        }
    }
}

