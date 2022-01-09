#include <random>
#include <unistd.h>
#include "Render.h"


bool randomBool() {
    return 0 + (rand() % (1 - 0 + 1)) == 1;
}


int main() {
    Render render;
    bool screen[ROWS][COLUMNS];
    render.clear(screen);
    render.random(screen);
    int cnt = 0;

    //MAIN LOOP
    while (true == 1) {
        logic(screen);
        render.render(screen);
        printf("\n %d ", ++cnt);
        usleep(1000000 / FPS);

    }

    return 0;
}



void logic(bool (&screen)[ROWS][COLUMNS]) {
    bool temp[ROWS][COLUMNS];
    std::copy(&screen[0][0], &screen[0][0] + ROWS * COLUMNS, &temp[0][0]);
    //printf("\n ---");
    //render(temp, ACTION_RENDER_IT);
    int around;
    for (int i = 1; i < ROWS - 1; i++) {
        for (int j = 1; j < COLUMNS - 1; j++) {
            around = temp[i-1][j-1] + temp[i][j-1] + temp[i+1][j-1] +
                     temp[i-1][j] + temp[i+1][j] +
                     temp[i-1][j+1] + temp[i][j+1] + temp[i+1][j+1];
            if(temp[i][j]) {
                if(around > 3 || around < 2) {
                    screen[i][j] = false;
                }
            } else {
                if(around == 3) {
                    screen[i][j] = true;
                }
            }
        }
    }

}
