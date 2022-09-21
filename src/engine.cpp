#include <iostream>
#include <thread>
#include "engine.hpp"
#include "GABot.h"
#include "GACore.h"
#include "values.h"
#include "future"

const sf::Time Engine::TimePerFrame = seconds(1.f / 60.f);


Engine::Engine() {
    resolution = Vector2f(900, 550);
    window.create(VideoMode(resolution.x, resolution.y), "Automate", Style::Default);
    window.setFramerateLimit(FPS);
}


void Engine::run() {
//    int bf[settings.allCount];
//    train(bf);

    GABot bot;


    auto future = std::async(std::launch::async, [&bot, this] {
        this->trainNetwork2(bot);
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
                field.init();
                settings.restore();
                bot.commands = future.get().commands;
            }
        }
        if (settings.figSum() > 0 && cont && futureReady) {
            processFigure(bot.commands[k]);
            if (k >= bot.commands.size() - 1) {
                cont = false;
                cout << field.countFit();
                text.insert(text.end(), string("Score: ") + to_string(50 * 50 - field.countFit()) + "/2500");
                text.insert(text.end(), string("Square: ") + to_string(settings.squareCount) + "/" +
                                        to_string(settings.squareCountMax));
                text.insert(text.end(),
                            string("Rect: ") + to_string(settings.rectCount) + "/" + to_string(settings.rectCountMax));
                text.insert(text.end(), string("Stairs: ") + to_string(settings.stairsCount) + "/" +
                                        to_string(settings.stairsCountMax));
                text.insert(text.end(), string("Stairs2: ") + to_string(settings.stairsCount) + "/" +
                                        to_string(settings.stairs2CountMax));
            }
            k += 1;
        }

        draw();
    }
}

void Engine::init() {
    Engine::field.init();
    core.settings = settings;
}

bool Engine::processFigure(int id) {
    switch (id) {
        case 1: {
            if (settings.squareCount > 0) {
                for (int i = 0; i < 50; ++i) {
                    for (int j = 0; j < 50; ++j) {
                        if (field.canDrawSquare(j, i)) {
                            field.drawSquare(j, i);
                            settings.squareCount -= 1;
                            return true;
                        }
                    }
                }
            }
            break;
        }
        case 2: {
            if (settings.rectCount > 0) {
                for (int i = 0; i < 50; ++i) {
                    for (int j = 0; j < 50; ++j) {
                        if (field.canDrawRect(j, i)) {
                            field.drawRect(j, i);
                            settings.rectCount -= 1;
                            return true;
                        }
                    }
                }
            }
            break;
        }
        case 3: {
            if (settings.stairsCount > 0) {
                for (int i = 0; i < 50; ++i) {
                    for (int j = 0; j < 50; ++j) {
                        if (field.canDrawStairs(j, i)) {
                            field.drawStairs(j, i);
                            settings.stairsCount -= 1;
                            return true;
                        }
                    }
                }
            }
            break;
        }
        case 4: {
            if (settings.stairs2Count > 0) {
                for (int i = 0; i < 50; ++i) {
                    for (int j = 0; j < 50; ++j) {
                        if (field.canDrawStairs2(j, i)) {
                            field.drawStairs2(j, i);
                            settings.stairs2Count -= 1;
                            return true;
                        }
                    }
                }
            }
            break;
        }
        case 5: {
            if (settings.rectCount > 0) {
                for (int i = 0; i < 50; ++i) {
                    for (int j = 0; j < 50; ++j) {
                        if (field.canDrawRectR(j, i)) {
                            field.drawRectR(j, i);
                            settings.rectCount -= 1;
                            return true;
                        }
                    }
                }
            }
            break;
        }
        case 6: {
            if (settings.stairsCount > 0) {
                for (int i = 0; i < 50; ++i) {
                    for (int j = 0; j < 50; ++j) {
                        if (field.canDrawStairsR(j, i)) {
                            field.drawStairsR(j, i);
                            settings.stairsCount -= 1;
                            return true;
                        }
                    }
                }
            }
            break;
        }
        case 7: {
            if (settings.stairs2Count > 0) {
                for (int i = 0; i < 50; ++i) {
                    for (int j = 0; j < 50; ++j) {
                        if (field.canDrawStairs2R(j, i)) {
                            field.drawStairs2R(j, i);
                            settings.stairs2Count -= 1;
                            return true;
                        }
                    }
                }
            }
            break;
        }
    }
    return false;
}

int Engine::processRandom() {
    int i = rand() % 7 + 1;
    while ((i == 1 && settings.squareCount <= 0) || (((i == 2) || (i == 5)) && settings.rectCount <= 0) ||
           (((i == 3) || (i == 6)) && settings.stairsCount <= 0) ||
           (((i == 4) || (i == 7)) && settings.stairs2Count <= 0)) {
        i = rand() % 7 + 1;
    }
    if (!processFigure(i)) {
        if (settings.squareCount > 0) {
            if (!processFigure(1)) {
                return 100;
            } else return 1;
        } else {
            return 100;
        }
    }

    return
            i;
}

void Engine::train(GABot &bot) {
    int bestFit = 100000;
    int now[settings.allCount()];
    int iter = 0;
    for (int i = 0; i < 10000; ++i) {
        field.init();
        iter = 0;
        settings.restore();
        while (settings.figSum() > 0) {
            int k = processRandom();
            if (k == 100)
                break;
            now[iter] = k;
            iter += 1;
        }
        if (field.countFit() < bestFit) {
            bot.commands.clear();
            for (int j = 0; j < settings.allCount(); ++j) {
                bot.commands.insert(bot.commands.end(), now[j]);
            }
            bestFit = field.countFit();
        }
    }
}

void Engine::trainNetwork(GABot &bot) {
    vector<GABot> bots;
    int iter = 0;
    for (int i = 0; i < values::POP_COUNT; ++i) {
        field.init();
        iter = 0;
        settings.restore();
        GABot bot;
        while (settings.figSum() > 0) {
            int k = processRandom();
            if (k == 100)
                break;
            bot.addCommand(k);
            iter += 1;
        }
        bot.fit = field.countFit();
        bots.insert(bots.begin(), bot);
    }

    vector<GABot> np = bots;

    for (int j = 0; j < values::GEN_COUNT; ++j) {
        core.baubleSort(np);
        cout << np[0].fit << endl;
        cout << np[0].commands.size() << endl;
        np = core.createNewPopulation(np);
        for (int i = 0; i < np.size(); ++i) {
            field.init();
            iter = 0;
            settings.restore();
            while (iter < np[i].commands.size()) {
                int k = np[i].commands[iter];
                if (k == 100)
                    break;
                processFigure(k);
                iter += 1;
            }
            np[i].fit = field.countFit();
        }

    }
    core.baubleSort(np);
    bot.commands = np[0].commands;
    cout << np[0].fit << endl;
}


void Engine::trainNetwork2(GABot &bot) {
    vector<GABot> bots;
    int iter = 0;
    for (int i = 0; i < values::POP_COUNT; ++i) {
        field.init();
        iter = 0;
        settings.restore();
        GABot bot;
        while (settings.figSum() > 0) {
            int k = processRandom();
            bot.addCommand(k);
            if (k == 100)
                break;

            iter += 1;
        }

        bot.fit = field.countFit();
        bots.insert(bots.begin(), bot);
    }

    vector<GABot> np = bots;
    GABot best;
    best.fit = 10000;
    for (int j = 0; j < values::GEN_COUNT; ++j) {
        core.baubleSort(np);
        bestPopFit = np[0].fit;
        np = core.createNewPopulation(np);

        for (int i = 0; i < np.size(); ++i) {
            field.init();
            iter = 0;
            settings.restore();
            while (iter < np[i].commands.size()) {
                int k = np[i].commands[iter];
                if (k == 100)
                    break;
                processFigure(k);
                iter += 1;
            }
            np[i].fit = field.countFit();
            if (np[i].fit < best.fit) {
                best.commands = np[i].commands;
                best.fit = np[i].fit;
            }
        }

    }

    np.at(0) = best;
    for (int j = 0; j < values::GEN_BEST_COUNT; ++j) {
        core.baubleSort(np);
        bestPopFit = np[0].fit;
        cout << j << " Generation - " << np[0].fit << endl;
        np = core.createNewPopulationFromBest(np);
        for (int i = 0; i < np.size(); ++i) {
            field.init();
            iter = 0;
            settings.restore();
            while (iter < np[i].commands.size()) {
                int k = np[i].commands[iter];
                if (k == 100)
                    break;
                processFigure(k);
                iter += 1;
            }
            np[i].fit = field.countFit();
        }

    }
    core.baubleSort(np);
    bot.commands = np[0].commands;
    cout << np[0].fit << endl;
}

