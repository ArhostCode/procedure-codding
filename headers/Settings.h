//
// Created by ardyc-user on 17.09.2022.
//

#ifndef AUTOMATE_SETTINGS_H
#define AUTOMATE_SETTINGS_H


class Settings {

public:

    int squareCountMax = 50;
    int rectCountMax = 50;
    int stairsCountMax = 50;
    int stairs2CountMax = 50;

    int squareCount = squareCountMax;
    int rectCount = rectCountMax;
    int stairsCount = stairsCountMax;
    int stairs2Count = stairs2CountMax;

    int allCount();

    int figSum();

    void restore();

};


#endif //AUTOMATE_SETTINGS_H
