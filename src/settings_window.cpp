//
// Created by ardyc-user on 17.09.2022.
//
#include <iostream>
#include "settings_window.h"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

settings_window::settings_window() {
    Vector2f resolution = Vector2f(900, 550);
    window.create(VideoMode(resolution.x, resolution.y), "Automate_Settings", Style::Default);
    window.setFramerateLimit(60);
    buttons.insert(buttons.end(), Button(400, 75, 0, 20, 20, "minus (1).png"));
    buttons.insert(buttons.end(), Button(400, 105, 1, 20, 20, "minus (1).png"));
    buttons.insert(buttons.end(), Button(400, 135, 2, 20, 20, "minus (1).png"));
    buttons.insert(buttons.end(), Button(400, 165, 3, 20, 20, "minus (1).png"));

    buttons.insert(buttons.end(), Button(470, 75, 4, 20, 20, "plus (1).png"));
    buttons.insert(buttons.end(), Button(470, 105, 5, 20, 20, "plus (1).png"));
    buttons.insert(buttons.end(), Button(470, 135, 6, 20, 20, "plus (1).png"));
    buttons.insert(buttons.end(), Button(470, 165, 7, 20, 20, "plus (1).png"));

    buttons.insert(buttons.end(), Button(700, 400, 8, 100, 100, "start.png"));

    texture.loadFromFile("back.png", sf::IntRect(0, 0, 900, 550));

}

void settings_window::run() {
    while (window.isOpen()) {
        input();
        draw();
    }
}

void settings_window::draw() {
    window.clear(Color::White);
    sf::Sprite sprite;
    sprite.setTexture(texture);
    window.draw(sprite);


    sf::Text t;
    t.setString("Settings for app");
    Font f;
    f.loadFromFile("arial.ttf");
    t.setFont(f);
    t.setPosition(20, 20);
    t.setFillColor(Color::Blue);
    window.draw(t);

    sf::Text t1;
    t1.setString("Square count: " + std::to_string(settings.squareCountMax));
    t1.setFont(f);
    t1.setPosition(30, 70);
    t1.setScale(0.8, 0.8);
    t1.setFillColor(Color::Blue);
    window.draw(t1);

    sf::Text t2;
    t2.setString("Rect count: " + std::to_string(settings.rectCountMax));
    t2.setFont(f);
    t2.setPosition(30, 100);
    t2.setScale(0.8, 0.8);
    t2.setFillColor(Color::Blue);
    window.draw(t2);

    sf::Text t3;
    t3.setString("Stairs count: " + std::to_string(settings.stairsCountMax));
    t3.setFont(f);
    t3.setPosition(30, 130);
    t3.setScale(0.8, 0.8);
    t3.setFillColor(Color::Blue);
    window.draw(t3);

    sf::Text t4;
    t4.setString("Stairs2 count: " + std::to_string(settings.stairs2CountMax));
    t4.setFont(f);
    t4.setPosition(30, 160);
    t4.setScale(0.8, 0.8);
    t4.setFillColor(Color::Blue);
    window.draw(t4);

    for (auto &button: buttons) {
        if(button.img == "null") {
            sf::RectangleShape s;
            s.setSize(Vector2f(button.sx, button.sy));
            s.setPosition(button.posx, button.posy);
            s.setFillColor(Color::Blue);
            window.draw(s);
        }else {
            sf::Sprite s;
            s.setTexture(button.texture);
            s.setPosition(button.posx, button.posy);
            window.draw(s);
        }
    }


    window.display();
}


