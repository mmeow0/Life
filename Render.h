//
// Created by Ajgul Tumerkina on 09.01.2022.
//

#ifndef LIFE_RENDER_H
#define LIFE_RENDER_H


#include <cstdio>
#include "main.h"

class Render {
    bool temp[ROWS][COLUMNS];
    int around;

public:
     void render(bool (&screen)[ROWS][COLUMNS]) {
        for (int i = 1; i < ROWS - 1; i++) {
            for (int j = 1; j < COLUMNS - 1; j++) {
                        if (j == 1) {
                            printf("\n");
                        }
                        if (screen[i][j]) {
                            printf("+");
                        } else {
                            printf(" ");
                        }
                    }
                }
    }

    void clear(bool (&screen)[ROWS][COLUMNS]) {
        for (int i = 1; i < ROWS - 1; i++) {
            for (int j = 1; j < COLUMNS - 1; j++) {
                screen[i][j] = false;
                if(i == j) screen[i][j] = true;
            }
        }
    }

    void random(bool (&screen)[ROWS][COLUMNS]) {
        for (int i = 1; i < ROWS - 1; i++) {
            for (int j = 1; j < COLUMNS - 1; j++) {
                screen[i][j] = randomBool();
            }
        }
    }
private:
    static bool randomBool() {
        return 0 + (rand() % (1 - 0 + 1)) == 1;
    }

};



#endif //LIFE_RENDER_H
