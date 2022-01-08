#include <iostream>
#include <random>
#include <unistd.h>
#include <sys/ioctl.h>
#include <sys/time.h>


const int HEIGHT = 75;
const int WIDTH = 245;
const int FPS = 24;

const int ACTION_RENDER_IT = 0;
const int ACTION_CLR = 1;
const int ACTION_RAND = 2;

void render(bool (&screen)[WIDTH][HEIGHT], int action);


void logic(bool (&screen)[WIDTH][HEIGHT]);

bool randomBool() {
    struct timeval tp;
    gettimeofday(&tp, NULL);
    long int ms = tp.tv_sec * 1000 + tp.tv_usec / 1000;
    return 0 + (rand() % (1 - 0 + 1)) == 1;
}


int main() {

    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

    int height = w.ws_row;
    printf ("lines %d\n", w.ws_row);
    int width = w.ws_col;
    printf ("columns %d\n", w.ws_col);

    std::cout << "Hello, World!" << std::endl;

    bool screen[WIDTH][HEIGHT];

    render(screen, ACTION_CLR);
    render(screen, ACTION_RAND);

    screen[5][2] = true;

    int cnt = 0;

    //MAIN LOOP
    while (true == 1) {
        logic(screen);


        render(screen, ACTION_RENDER_IT);
        printf("\n %d ", ++cnt);
        usleep(1000000 / FPS);

    }


    return 0;
}

void render(bool (&screen)[WIDTH][HEIGHT], int action) {
    //system("clear");
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            switch (action) {
                case ACTION_RENDER_IT: {
                    if (j == 0) {
                        printf("\n");
                    }
                    if (screen[i][j]) {
                        printf("+");
                    } else {
                        printf(" ");
                    }
                    break;
                }
                case ACTION_CLR: {
                    screen[i][j] = false;
                    if(i == j) screen[i][j] = true;
                    break;
                }
                case ACTION_RAND: {

                    screen[i][j] = randomBool();
                    break;
                }
                default: {
                }
            }
        }
    }
}

void logic(bool (&screen)[WIDTH][HEIGHT]) {
    bool temp[WIDTH][HEIGHT];
    std::copy(&screen[0][0], &screen[0][0] + WIDTH * HEIGHT, &temp[0][0]);
    //printf("\n ---");
    //render(temp, ACTION_RENDER_IT);

    int around;
    for (int i = 1; i < HEIGHT - 1; i++) {
        for (int j = 1; j < WIDTH - 1; j++) {
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
