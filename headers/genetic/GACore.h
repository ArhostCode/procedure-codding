//
// Created by ardyc-user on 17.09.2022.
//

#ifndef AUTOMATE_GACORE_H
#define AUTOMATE_GACORE_H


#include "Bot.h"
#include "Settings.h"
#include "Values.h"


class GACore {

private:


public:
    Settings settings;

    void sort(std::vector<Bot> &bots);

    std::vector<Bot> createNewPopulation(std::vector<Bot> bots);

    std::vector<Bot> createNewPopulationFromBest(std::vector<Bot> bots);
};


#endif //AUTOMATE_GACORE_H
