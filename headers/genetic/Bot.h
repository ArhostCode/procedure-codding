//
// Created by ardyc-user on 17.09.2022.
//

#ifndef AUTOMATE_BOT_H
#define AUTOMATE_BOT_H

#include <vector>
#include "iostream"

class Bot {
public:
    std::vector<int> commands;
    int fit = 0;

    void addCommand(int id);
};


#endif //AUTOMATE_BOT_H
