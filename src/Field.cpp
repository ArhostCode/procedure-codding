#include "Field.h"

void Field::init() {
    for (int i = 0; i < 50; ++i) {
        for (int j = 0; j < 50; ++j) {
            field[i][j] = 0;
        }
    }
}

void Field::drawSquare(int xpos, int ypos) {
    field[xpos][ypos] = 1;
    field[xpos + 1][ypos] = 1;
    field[xpos][ypos + 1] = 1;
    field[xpos + 1][ypos + 1] = 1;
}

void Field::drawRect(int xpos, int ypos) {
    field[xpos][ypos] = 2;
    field[xpos + 1][ypos] = 2;
    field[xpos + 2][ypos] = 2;
    field[xpos][ypos + 1] = 2;
    field[xpos + 1][ypos + 1] = 2;
    field[xpos + 2][ypos + 1] = 2;
}

void Field::drawRectR(int xpos, int ypos) {
    field[xpos][ypos] = 2;
    field[xpos + 1][ypos] = 2;
    field[xpos][ypos + 1] = 2;
    field[xpos + 1][ypos + 1] = 2;
    field[xpos][ypos + 2] = 2;
    field[xpos + 1][ypos + 2] = 2;
}

void Field::drawStairs(int xpos, int ypos) {
    field[xpos][ypos] = 3;
    field[xpos + 1][ypos] = 3;
    field[xpos][ypos + 1] = 3;
    field[xpos + 1][ypos + 1] = 3;

    field[xpos + 2][ypos + 1] = 3;
    field[xpos + 2][ypos] = 3;

    field[xpos + 3][ypos + 1] = 3;
    field[xpos + 3][ypos] = 3;
    field[xpos + 3][ypos + 2] = 3;
    field[xpos + 3][ypos + 3] = 3;
    field[xpos + 3][ypos + 4] = 3;

    field[xpos + 4][ypos + 1] = 3;
    field[xpos + 4][ypos] = 3;

    field[xpos + 4][ypos + 2] = 3;
    field[xpos + 4][ypos + 3] = 3;
    field[xpos + 4][ypos + 4] = 3;

}

void Field::drawStairsR(int xpos, int ypos) {
    field[xpos][ypos] = 3;
    field[xpos][ypos + 1] = 3;
    field[xpos + 1][ypos] = 3;
    field[xpos + 1][ypos + 1] = 3;

    field[xpos + 2][ypos] = 3;
    field[xpos + 2][ypos + 1] = 3;
    field[xpos + 3][ypos] = 3;
    field[xpos + 3][ypos + 1] = 3;
    field[xpos + 4][ypos] = 3;
    field[xpos + 4][ypos + 1] = 3;

    field[xpos][ypos + 3] = 3;
    field[xpos + 1][ypos + 3] = 3;
    field[xpos][ypos + 2] = 3;
    field[xpos + 1][ypos + 2] = 3;
    field[xpos][ypos + 4] = 3;
    field[xpos + 1][ypos + 4] = 3;

}

void Field::drawStairs2(int xpos, int ypos) {
    field[xpos][ypos] = 4;
    field[xpos + 1][ypos] = 4;
    field[xpos][ypos + 1] = 4;
    field[xpos + 1][ypos + 1] = 4;

    field[xpos + 2][ypos + 1] = 4;
    field[xpos + 2][ypos] = 4;

    field[xpos + 3][ypos + 1] = 4;
    field[xpos + 3][ypos] = 4;
    field[xpos + 3][ypos + 2] = 4;
    field[xpos + 3][ypos + 3] = 4;
    field[xpos + 3][ypos + 4] = 4;

    field[xpos + 4][ypos + 1] = 4;
    field[xpos + 4][ypos] = 4;

    field[xpos + 4][ypos + 2] = 4;
    field[xpos + 4][ypos + 3] = 4;
    field[xpos + 4][ypos + 4] = 4;

    field[xpos + 5][ypos + 3] = 4;
    field[xpos + 5][ypos + 4] = 4;

    field[xpos + 6][ypos + 3] = 4;
    field[xpos + 6][ypos + 4] = 4;

    field[xpos + 7][ypos + 3] = 4;
    field[xpos + 7][ypos + 4] = 4;

}

void Field::drawStairs2R(int xpos, int ypos) {
    field[xpos][ypos] = 4;
    field[xpos + 1][ypos] = 4;
    field[xpos][ypos + 1] = 4;
    field[xpos + 1][ypos + 1] = 4;
    field[xpos][ypos + 2] = 4;
    field[xpos + 1][ypos + 2] = 4;
    field[xpos][ypos + 3] = 4;
    field[xpos + 1][ypos + 3] = 4;
    field[xpos][ypos + 4] = 4;
    field[xpos + 1][ypos + 4] = 4;

    field[xpos + 2][ypos + 3] = 4;
    field[xpos + 2][ypos + 4] = 4;
    field[xpos + 3][ypos + 3] = 4;
    field[xpos + 3][ypos + 4] = 4;

    field[xpos + 4][ypos + 3] = 4;
    field[xpos + 4][ypos + 4] = 4;

    field[xpos + 4][ypos + 5] = 4;
    field[xpos + 3][ypos + 5] = 4;
    field[xpos + 4][ypos + 6] = 4;
    field[xpos + 3][ypos + 6] = 4;
    field[xpos + 4][ypos + 7] = 4;
    field[xpos + 3][ypos + 7] = 4;


}

bool Field::canDrawRect(int xpos, int ypos) {
    if (xpos + 2 < 50 && ypos + 1 < 50) {
        if (field[xpos][ypos] == 0 &&
            field[xpos + 1][ypos] == 0 &&
            field[xpos + 2][ypos] == 0 &&
            field[xpos][ypos + 1] == 0 &&
            field[xpos + 1][ypos + 1] == 0 &&
            field[xpos + 2][ypos + 1] == 0)
            return true;
    }
    return false;
}

bool Field::canDrawRectR(int xpos, int ypos) {
    if (xpos + 1 < 50 && ypos + 2 < 50) {
        if (field[xpos][ypos] == 0 &&
            field[xpos + 1][ypos] == 0 &&
            field[xpos][ypos + 1] == 0 &&
            field[xpos + 1][ypos + 1] == 0 &&
            field[xpos][ypos + 2] == 0 &&
            field[xpos + 1][ypos + 2] == 0)
            return true;
    }
    return false;
}

bool Field::canDrawSquare(int xpos, int ypos) {
    if (xpos + 1 < 50 && ypos + 1 < 50) {
        if (field[xpos][ypos] == 0 &&
            field[xpos + 1][ypos] == 0 &&
            field[xpos][ypos + 1] == 0 &&
            field[xpos + 1][ypos + 1] == 0)
            return true;
    }
    return false;
}


bool Field::canDrawStairs(int xpos, int ypos) {
    if (xpos + 4 < 50 && ypos + 4 < 50) {
        if (field[xpos][ypos] == 0 &&
            field[xpos + 1][ypos] == 0 &&
            field[xpos][ypos + 1] == 0 &&
            field[xpos + 1][ypos + 1] == 0 &&
            field[xpos + 2][ypos + 1] == 0 &&
            field[xpos + 2][ypos] == 0 &&
            field[xpos + 3][ypos + 1] == 0 &&
            field[xpos + 3][ypos] == 0 &&
            field[xpos + 3][ypos + 2] == 0 &&
            field[xpos + 3][ypos + 3] == 0 &&
            field[xpos + 3][ypos + 4] == 0 &&
            field[xpos + 4][ypos + 1] == 0 &&
            field[xpos + 4][ypos] == 0 &&
            field[xpos + 4][ypos + 2] == 0 &&
            field[xpos + 4][ypos + 3] == 0 &&
            field[xpos + 4][ypos + 4] == 0)
            return true;
    }
    return false;
}

bool Field::canDrawStairsR(int xpos, int ypos) {
    if (xpos + 4 < 50 && ypos + 4 < 50) {
        if (field[xpos][ypos] == 0 &&
            field[xpos][ypos + 1] == 0 &&
            field[xpos + 1][ypos] == 0 &&
            field[xpos + 1][ypos + 1] == 0 &&

            field[xpos + 2][ypos] == 0 &&
            field[xpos + 2][ypos + 1] == 0 &&
            field[xpos + 3][ypos] == 0 &&
            field[xpos + 3][ypos + 1] == 0 &&
            field[xpos + 4][ypos] == 0 &&
            field[xpos + 4][ypos + 1] == 0 &&

            field[xpos][ypos + 3] == 0 &&
            field[xpos + 1][ypos + 3] == 0 &&
            field[xpos][ypos + 2] == 0 &&
            field[xpos + 1][ypos + 2] == 0 &&
            field[xpos][ypos + 4] == 0 &&
            field[xpos + 1][ypos + 4] == 0)
            return true;
    }
    return false;
}



bool Field::canDrawStairs2(int xpos, int ypos) {
    if (ypos + 4 < 50 && xpos + 7 < 50) {
        if (field[xpos][ypos] == 0 &&
            field[xpos + 1][ypos] == 0 &&
            field[xpos][ypos + 1] == 0 &&
            field[xpos + 1][ypos + 1] == 0 &&
            field[xpos + 2][ypos + 1] == 0 &&
            field[xpos + 2][ypos] == 0 &&
            field[xpos + 3][ypos + 1] == 0 &&
            field[xpos + 3][ypos] == 0 &&
            field[xpos + 3][ypos + 2] == 0 &&
            field[xpos + 3][ypos + 3] == 0 &&
            field[xpos + 3][ypos + 4] == 0 &&
            field[xpos + 4][ypos + 1] == 0 &&
            field[xpos + 4][ypos] == 0 &&
            field[xpos + 4][ypos + 2] == 0 &&
            field[xpos + 4][ypos + 3] == 0 &&
            field[xpos + 4][ypos + 4] == 0 &&
            field[xpos + 5][ypos + 3] == 0 &&
            field[xpos + 5][ypos + 4] == 0 &&
            field[xpos + 6][ypos + 3] == 0 &&
            field[xpos + 6][ypos + 4] == 0 &&
            field[xpos + 7][ypos + 3] == 0 &&
            field[xpos + 7][ypos + 4] == 0)
            return true;
    }
    return false;
}

bool Field::canDrawStairs2R(int xpos, int ypos) {
    if (ypos + 7 < 50 && xpos + 4 < 50) {
        if (field[xpos][ypos] == 0 &&
            field[xpos + 1][ypos] == 0 &&
            field[xpos][ypos + 1] == 0 &&
            field[xpos + 1][ypos + 1] == 0 &&
            field[xpos][ypos + 2] == 0 &&
            field[xpos + 1][ypos + 2] == 0 &&
            field[xpos][ypos + 3] == 0 &&
            field[xpos + 1][ypos + 3] == 0 &&
            field[xpos][ypos + 4] == 0 &&
            field[xpos + 1][ypos + 4] == 0 &&

            field[xpos + 2][ypos + 3] == 0 &&
            field[xpos + 2][ypos + 4] == 0 &&
            field[xpos + 3][ypos + 3] == 0 &&
            field[xpos + 3][ypos + 4] == 0 &&

            field[xpos + 4][ypos + 3] == 0 &&
            field[xpos + 4][ypos + 4] == 0 &&

            field[xpos + 4][ypos + 5] == 0 &&
            field[xpos + 3][ypos + 5] == 0 &&
            field[xpos + 4][ypos + 6] == 0 &&
            field[xpos + 3][ypos + 6] == 0 &&
            field[xpos + 4][ypos + 7] == 0 &&
            field[xpos + 3][ypos + 7] == 0)
            return true;
    }
    return false;
}

int Field::countFit() {
    int fit = 0;
    for (int i = 0; i < 50; ++i) {
        for (int j = 0; j < 50; ++j) {
            if (field[i][j] != 0)
                continue;
//
//            if (i - 1 < 0 && field[i + 1][j] != 0) {
//                fit += 1;
//                continue;
//            }
//            if (j - 1 < 0 && field[i][j + 1] != 0) {
//                fit += 1;
//                continue;
//            }
//
//            if (j + 1 > 50 && field[i][j - 1] != 0) {
//                fit += 1;
//                continue;
//            }
//
//            if (i + 1 > 50 && field[i - 1][j] != 0) {
//                fit += 1;
//                continue;
//            }
//
//            if (i - 1 < 0 || j - 1 < 0 || i + 1 > 50 || j + 1 > 50)
//                continue;
//
//            if (field[i - 1][j] != 0 && field[i + 1][j] != 0) {
//                fit += 1;
//                continue;
//            }
//
//            if (field[i][j - 1] != 0 && field[i][j + 1] != 0) {
//                fit += 1;
//                continue;
//            }
            fit += 1;

//            if (field[i - 1][j - 1] != 0 && field[i + 1][j + 1] != 0) {
//                fit += 1;
//                continue;
//            }
//            if (field[i - 1][j + 1] != 0 && field[i + 1][j - 1] != 0) {
//                fit += 1;
//                continue;
//            }
        }
    }
    return fit;
}



