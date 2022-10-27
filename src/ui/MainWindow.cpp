//
// Created by e-gul on 12.10.2022.
//

#include "ui/MainWindow.h"
#include "Engine.hpp"

const int align = 10;

MainWindow::MainWindow(Engine engine) {
    this->engine = engine;
    resolution = Vector2f(900, 550);
    window.create(VideoMode(resolution.x, resolution.y), "Addition application", Style::Default);
    window.setFramerateLimit(FPS);
    font.loadFromFile("arial.ttf");
}

void MainWindow::run() {

    Bot bot;
    engine.settings.restore();

    auto future = std::async(std::launch::async, [&bot, this] {
        srand(time(NULL));
        this->engine.trainNetwork2(bot);
        return bot;
    });

    bool futureReady = false;

    bool cont = true;
    int k = 0;

    while (window.isOpen()) {
        input();
        if (!futureReady) {
            if (future.wait_for(0ms) == std::future_status::ready) {
                futureReady = true;
                engine.field.initialize();
                engine.settings.restore();
                bot.commands = future.get().commands;
            }
        }
        if (engine.settings.figSum() > 0 && cont && futureReady) {
            engine.processFigure(bot.commands[k]);
            if (k >= bot.commands.size() - 1) {
                cont = false;
                cout << engine.field.countFit();
                engine.text.insert(engine.text.end(), string("Score: ") + to_string(50 * 50 - engine.field.countFit()) + "/2500");
                engine.text.insert(engine.text.end(), string("Square: ") + to_string(engine.settings.squareCount) + "/" +
                                        to_string(engine.settings.squareCountMax));
                engine.text.insert(engine.text.end(),
                            string("Rect: ") + to_string(engine.settings.rectCount) + "/" + to_string(engine.settings.rectCountMax));
                engine.text.insert(engine.text.end(), string("Stairs: ") + to_string(engine.settings.stairsCount) + "/" +
                                        to_string(engine.settings.stairsCountMax));
                engine.text.insert(engine.text.end(), string("Stairs2: ") + to_string(engine.settings.stairsCount) + "/" +
                                        to_string(engine.settings.stairs2CountMax));
            }
            k += 1;
        }

        draw();
    }
}

void MainWindow::draw() {
    window.clear(Color::White);
    sf::RectangleShape shape(Vector2f(500, 500));
    shape.setFillColor(sf::Color(255, 255, 255));
    shape.setPosition(align, align);
    shape.setOutlineThickness(3.f);
    shape.setOutlineColor(sf::Color(0, 0, 0));
    window.draw(shape);

    for (int i = 0; i < 50; ++i) {
        for (int j = 0; j < 50; ++j) {
            sf::RectangleShape f(Vector2f(10, 10));
            f.setPosition(align + j * 10, align + i * 10);
            f.setOutlineThickness(1.f);
            f.setOutlineColor(sf::Color(0, 0, 0));
            switch (engine.field.field[j][i]) {
                case 0: {
                    f.setFillColor(sf::Color(255, 255, 255));
                    break;
                }
                case 1: {
                    f.setFillColor(sf::Color(255, 0, 0));
                    break;
                }
                case 2: {
                    f.setFillColor(sf::Color(0, 0, 255));
                    break;
                }
                case 3: {
                    f.setFillColor(sf::Color(0, 255, 0));
                    break;
                }
                case 4: {
                    f.setFillColor(sf::Color(255, 255, 0));
                    break;
                }
            }

            window.draw(f);
        }
    }
    for (int i = 0; i < engine.text.size(); ++i) {
        sf::Text t;
        t.setString(engine.text[i]);
        t.setFont(font);
        t.setPosition(550, 20 + i * 50);
        t.setFillColor(Color::Red);
        window.draw(t);
    }

    sf::Text bf;
    bf.setString("Best population fit " + to_string(engine.bestPopFit));
    bf.setFont(font);
    bf.setPosition(550, 400);
    bf.setFillColor(Color::Red);
    window.draw(bf);
    window.display();
}

void MainWindow::input() {
    Event event;

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
                engine.processFigure(1);
            }
            if (Keyboard::isKeyPressed(Keyboard::Num2)) {
                engine.processFigure(2);
            }
            if (Keyboard::isKeyPressed(Keyboard::Num3)) {
                engine.processFigure(3);
            }
            if (Keyboard::isKeyPressed(Keyboard::Num4)) {
                engine.processFigure(4);
            }
            if (Keyboard::isKeyPressed(Keyboard::Num5)) {
                engine.processFigure(5);
            }
            if (Keyboard::isKeyPressed(Keyboard::Num6)) {
                engine.processFigure(6);
            }
            if (Keyboard::isKeyPressed(Keyboard::Num7)) {
                engine.processFigure(7);
            }
        }

    }
}