//
// Created by CScooller on 08.01.2022.
//

#ifndef LIFE_MAIN_HPP
#define LIFE_MAIN_HPP

const int HEIGHT = 40;
const int WIDTH = 80;
const int FPS = 24;

enum TMatrix {
    Main, Temp
};

enum ProcessingAction {
    RENDER, CLR, RANDOMIZE
};

void loopProcessing(bool (&screen)[2][WIDTH][HEIGHT], int ProcessingAction);

void logic(bool (&screen)[2][WIDTH][HEIGHT]);

bool randomBool();

#endif //LIFE_MAIN_HPP
