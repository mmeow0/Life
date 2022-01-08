//
// Created by CScooller on 08.01.2022.
//

#ifndef LIFE_MAIN_H
#define LIFE_MAIN_H

const int HEIGHT = 75;
const int WIDTH = 245;
const int FPS = 24;

const int ACTION_RENDER_IT = 0;
const int ACTION_CLR = 1;
const int ACTION_RAND = 2;

void render(bool (&screen)[WIDTH][HEIGHT], int action);


void logic(bool (&screen)[WIDTH][HEIGHT]);

bool randomBool();

#endif //LIFE_MAIN_H
