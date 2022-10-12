#ifndef AUTOMATE_ENGINE_HPP
#define AUTOMATE_ENGINE_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <vector>
#include "Field.h"
#include "Settings.h"
#include "genetic/Bot.h"
#include "genetic/GACore.h"

using namespace sf;
using namespace std;

class Engine {
public:
    Field field;

    int bestPopFit = 0;

    Settings settings;

    GACore core;

    void initialize();

    bool processFigure(int id);

    int processRandom();

    void trainNetwork(Bot &bot);

    void train(Bot &bot);

    void trainNetwork2(Bot &bot);

    vector<string> text;
};


#endif //AUTOMATE_ENGINE_HPP
