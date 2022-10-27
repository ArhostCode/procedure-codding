//
// Created by ardyc-user on 17.09.2022.
//

#include "Settings.h"

int Settings::figSum() {
    return stairs2Count + stairsCount + rectCount + squareCount;
}

void Settings::restore() {
    squareCount = squareCountMax;
    rectCount = rectCountMax;
    stairs2Count = stairs2CountMax;
    stairsCount = stairsCountMax;
}

int Settings::allCount() {
    return stairs2CountMax + stairsCountMax + rectCountMax + squareCountMax;
}