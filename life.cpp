//
// Created by Ajgul Tumerkina on 09.01.2022.
//


#include "life.h"

Life::Life(QWidget *parent) : QWidget(parent) {
    setStyleSheet("background-color:green;");
    cell.load("red_apple.png");
    setFixedSize(ROWS*SIZE, COLUMNS*SIZE);
    initGame();
    startGame();
}


void Life::initGame() {
    for (int i = 1; i < ROWS - 1; i++) {
        for (int j = 1; j < COLUMNS - 1; j++) {
            screen[i][j] = randomBool();
        }
    }
    timerId = startTimer(DELAY);
}

void Life::startGame() {
    inGame = true;

}



void Life::timerEvent(QTimerEvent *e) {
    Q_UNUSED(e);
    if (inGame) {
        update();
    }
    repaint();
}

void Life::update() {
    std::copy(&screen[0][0], &screen[0][0] + ROWS * COLUMNS, &temp[0][0]);
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

void Life::paintEvent(QPaintEvent *e) {
    Q_UNUSED(e);
    doDrawing();
}

void Life::doDrawing() {
    QPainter qp(this);
    for (int i = 1; i < ROWS - 1; i++) {
        for (int j = 1; j < COLUMNS - 1; j++) {
           if(screen[i][j]){
               qp.fillRect(i*SIZE, j*SIZE, SIZE, SIZE, QColor(46 + i%(255-46), 139, 83, 255));
           }
           else{
              qp.fillRect(i*SIZE, j*SIZE, SIZE, SIZE, QColor(240, 255, 240, 255));
           }
        }
    }

}