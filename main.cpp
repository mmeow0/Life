#include <iostream>
#include <unistd.h>
#include <sys/ioctl.h>
#include <random>
#include "main.hpp"

int main() {

    struct winsize window{};
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &window);

    printf("lines %d\n", window.ws_row);
    printf("columns %d\n", window.ws_col);

    std::cout << "Hello, World!" << std::endl;

    bool screen[2][WIDTH][HEIGHT];

    loopProcessing(screen, ProcessingAction::CLR);
    loopProcessing(screen, ProcessingAction::RANDOMIZE);

    int cnt = 0;

    //MAIN LOOP
    while (true == 1) {
        logic(screen);


        loopProcessing(screen, ProcessingAction::RENDER);
        printf("\n %d ", ++cnt);
        usleep(1000000 / FPS);

    }
}

void loopProcessing(bool (&screen)[2][WIDTH][HEIGHT], int ProcessingAction) {
    system("clear");
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            switch (ProcessingAction) {
                case ProcessingAction::RENDER : {
                    if (j == 0) {
                        printf("\n");
                    }
                    if (screen[TMatrix::Main][i][j]) {
                        printf("+");
                    } else {
                        printf(" ");
                    }
                    break;
                }
                case ProcessingAction::CLR: {
                    screen[TMatrix::Main][i][j] = false;
                    //if (i == j) screen[TMatrix::Main][i][j] = true;
                    break;
                }
                case ProcessingAction::RANDOMIZE: {

                    screen[TMatrix::Main][i][j] = randomBool();
                    break;
                }
                default: {
                }
            }
        }
    }
}

void logic(bool (&screen)[2][WIDTH][HEIGHT]) {
    //bool temp[WIDTH][HEIGHT];
    std::copy(&screen[TMatrix::Main][0][0], &screen[TMatrix::Main][0][0] + WIDTH * HEIGHT,
              &screen[TMatrix::Temp][0][0]);
    //printf("\n ---");
    //loopProcessing(temp, ACTION_RENDER_IT);

    int around;
    for (int i = 1; i < HEIGHT - 1; i++) {
        for (int j = 1; j < WIDTH - 1; j++) {
            around = screen[TMatrix::Temp][i - 1][j - 1] +
                     screen[TMatrix::Temp][i][j - 1] +
                     screen[TMatrix::Temp][i + 1][j - 1] +
                     screen[TMatrix::Temp][i - 1][j] +
                     screen[TMatrix::Temp][i + 1][j] +
                     screen[TMatrix::Temp][i - 1][j + 1] +
                     screen[TMatrix::Temp][i][j + 1] +
                     screen[TMatrix::Temp][i + 1][j + 1];
            if (&screen[TMatrix::Temp][i][j]) {
                if (around > 3 || around < 2) {
                    screen[TMatrix::Main][i][j] = false;
                }
            } else {
                if (around == 3) {
                    screen[TMatrix::Main][i][j] = true;
                }
            }
        }
    }

}

bool randomBool() {
    std::random_device random_device; // create object for seeding
    std::mt19937 engine{random_device()}; // create engine and seed it
    std::uniform_int_distribution<> dist(0,9); // create distribution for integers with [0; 9] range
    auto random_number = dist(engine); // finally get a pseudo-random integer number
    return random_number > 3;
}
