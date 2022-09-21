//
// Created by ardyc-user on 16.09.2022.
//

#ifndef AUTOMATE_FIELD_H
#define AUTOMATE_FIELD_H


class Field {
public:
    int field[50][50];

    void init();

    void drawSquare(int xpos, int ypos);

    void drawRect(int xpos, int ypos);
    void drawRectR(int xpos, int ypos);

    void drawStairs(int xpos, int ypos);
    void drawStairsR(int xpos, int ypos);

    void drawStairs2(int xpos, int ypos);
    void drawStairs2R(int xpos, int ypos);

    bool canDrawRect(int xpos, int ypos);
    bool canDrawRectR(int xpos, int ypos);

    bool canDrawSquare(int xpos, int ypos);

    bool canDrawStairs(int xpos, int ypos);
    bool canDrawStairsR(int xpos, int ypos);

    bool canDrawStairs2(int xpos, int ypos);
    bool canDrawStairs2R(int xpos, int ypos);

    int countFit();

};



#endif //AUTOMATE_FIELD_H
