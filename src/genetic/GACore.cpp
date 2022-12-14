//
// Created by ardyc-user on 17.09.2022.
//

#include "genetic/GACore.h"

std::vector<Bot> GACore::createNewPopulationFromBest(std::vector<Bot> bots) {
    std::vector<Bot> np;
    for (int i = 0; i < bots.size(); ++i) {
        Bot nbot;
        for (int j = 0; j < (settings).allCount(); ++j) {
            if (bots[0].commands.size() > j) {
                if (rand() % Values::MUTATION_BEST_RATE == 1) {
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


std::vector<Bot> GACore::createNewPopulation(std::vector<Bot> bots) {
    std::vector<Bot> np;
    for (int i = 0; i < bots.size(); ++i) {
        Bot nbot;
        for (int j = 0; j < (settings).allCount(); ++j) {
            int r = rand() % (bots.size() / 4);
            if (bots[r].commands.size() > j) {
                if (rand() % Values::MUTATION_RATE == 1) {
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

void GACore::sort(std::vector<Bot> &bots) {
    for (int i = 0; i < bots.size(); ++i) {
        for (int j = 0; j < bots.size() - i - 1; ++j) {
            if (bots.at(j).fit > bots.at(j + 1).fit) {
                Bot b = bots.at(j);
                bots.at(j) = bots.at(j + 1);
                bots.at(j + 1) = b;
            }
        }
    }
}