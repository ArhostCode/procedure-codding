//
// Created by ardyc-user on 17.09.2022.
//

#ifndef AUTOMATE_SETTINGS_H
#define AUTOMATE_SETTINGS_H


class settings {

public:
    int allCount() {
        return stairs2CountMax + stairsCountMax + rectCountMax + squareCountMax;
    }

    int squareCount = squareCountMax;
    int rectCount = rectCountMax;
    int stairsCount = stairsCountMax;
    int stairs2Count = stairs2CountMax;

    int figSum() {
        return stairs2Count + stairsCount + rectCount + squareCount;
    }

    void restore() {
        squareCount = squareCountMax;
        rectCount = rectCountMax;
        stairs2Count = stairs2CountMax;
        stairsCount = stairsCountMax;
    }

    int squareCountMax = 50;
    int rectCountMax = 50;
    int stairsCountMax = 50;
    int stairs2CountMax = 50;

};


#endif //AUTOMATE_SETTINGS_H
