#ifndef AUTOMATE_ENGINE_HPP
#define AUTOMATE_ENGINE_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <vector>
#include "Field.h"
#include "settings.h"
#include "GABot.h"
#include "GACore.h"

using namespace sf;
using namespace std;

class Engine {
private:
    // Window
    Vector2f resolution;
    RenderWindow window;
    const unsigned int FPS = 60;
    static const Time TimePerFrame;


public:
    Field field;

    int bestPopFit = 0;

    settings settings;

    GACore core;

    Engine();

    void input();

    void draw();

    void run();

    void init();

    bool processFigure(int id);

    int processRandom();

    void train(int *best);

    void trainNetwork(GABot &bot);

    void train(GABot &bot);

    void trainNetwork2(GABot &bot);

    vector<string> text;
};


#endif //AUTOMATE_ENGINE_HPP
