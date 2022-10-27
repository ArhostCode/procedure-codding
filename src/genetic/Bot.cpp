//
// Created by ardyc-user on 17.09.2022.
//

#include "genetic/Bot.h"

void Bot::addCommand(int id) {
    commands.insert(commands.end(), id);
}