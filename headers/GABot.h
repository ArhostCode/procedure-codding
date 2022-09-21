//
// Created by ardyc-user on 17.09.2022.
//

#ifndef AUTOMATE_GABOT_H
#define AUTOMATE_GABOT_H

#include <vector>
#include "iostream"

class GABot {

public:
    std::vector<int> commands;

    void addCommand(int id) {
        commands.insert(commands.end(), id);
    }

    int fit = 0;


};


#endif //AUTOMATE_GABOT_H
