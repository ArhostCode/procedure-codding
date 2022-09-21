#include "engine.hpp"

const int align = 10;

int i1 = 0;
int j1 = 0;

int tps = 0;

void Engine::draw() {
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
            switch (field.field[j][i]) {
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
    for (int i = 0; i < text.size(); ++i) {
        sf::Text t;
        t.setString(text[i]);
        Font f;
        f.loadFromFile("arial.ttf");
        t.setFont(f);
        t.setPosition(550, 20 + i * 50);
        t.setFillColor(Color::Red);
        window.draw(t);
    }

    sf::Text bf;
    bf.setString("Best population fit " + to_string(bestPopFit));
    Font f;
    f.loadFromFile("arial.ttf");
    bf.setFont(f);
    bf.setPosition(550, 400);
    bf.setFillColor(Color::Red);
    window.draw(bf);

    window.display();
}
