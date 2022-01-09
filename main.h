//
// Created by Ajgul Tumerkina on 09.01.2022.
//

#ifndef LIFE_MAIN_H
#define LIFE_MAIN_H
#include <random>
const int ROWS = 40;
const int COLUMNS = 80;
const int FPS = 24;

enum ACTION{
    render, clear, rndm
};

void logic(bool (&screen)[ROWS][COLUMNS]);



#endif //LIFE_MAIN_H
