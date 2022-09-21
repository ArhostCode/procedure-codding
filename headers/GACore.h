//
// Created by ardyc-user on 17.09.2022.
//

#ifndef AUTOMATE_GACORE_H
#define AUTOMATE_GACORE_H


#include "GABot.h"
#include "settings.h"
#include "values.h"


class GACore {
public:
    settings settings;

    void baubleSort(std::vector<GABot> &bots) {
        for (int i = 0; i < bots.size(); ++i) {
            for (int j = 0; j < bots.size() - i - 1; ++j) {
                if (bots.at(j).fit > bots.at(j + 1).fit) {
                    GABot b = bots.at(j);
                    bots.at(j) = bots.at(j + 1);
                    bots.at(j + 1) = b;
                }
            }
        }
    }

    std::vector<GABot> createNewPopulation(std::vector<GABot> bots) {
        std::vector<GABot> np;
        for (int i = 0; i < bots.size(); ++i) {
            GABot nbot;
            for (int j = 0; j < (settings).allCount(); ++j) {
                int r = rand() % (bots.size() / 4);
                if (bots[r].commands.size() > j) {
                    if (rand() % values::MUTATION_RATE == 1) {
                        nbot.addCommand(rand() % 7 + 1);
                    } else {
                        nbot.addCommand(bots[r].commands[j]);
                    }
                } else {
                    nbot.addCommand(rand() % 7 + 1);
                }
            }
            np.insert(np.begin(), nbot);
        }
        return np;
    }

     std::vector<GABot> createNewPopulationFromBest(std::vector<GABot> bots) {
        std::vector<GABot> np;
        for (int i = 0; i < bots.size(); ++i) {
            GABot nbot;
            for (int j = 0; j < (settings).allCount(); ++j) {
                if (bots[0].commands.size() > j) {
                    if (rand() % values::MUTATION_BEST_RATE == 1) {
                        nbot.addCommand(rand() % 7 + 1);
                    } else {
                        nbot.addCommand(bots[0].commands[j]);
                    }
                } else {
                    nbot.addCommand(rand() % 7 + 1);
                }
            }
            np.insert(np.begin(), nbot);
        }
        return np;
    }
};


#endif //AUTOMATE_GACORE_H
