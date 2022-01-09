//
// Created by Ajgul Tumerkina on 09.01.2022.
//

#ifndef LIFE_LIFE_H
#define LIFE_LIFE_H
#include "UI/Qt.h"


class Life : public QWidget {
public:
    Life(QWidget *parent = nullptr);
    void setRect(QRect);

protected:
    void timerEvent(QTimerEvent *);


private:
    QRect rect;
    static const int ROWS = 70;
    static const int COLUMNS = 70;
    static const int SIZE = 10;
    static const int DELAY = 140;
    int timerId;
    bool screen[ROWS][COLUMNS];
    bool temp[ROWS][COLUMNS];
    bool inGame = false;



    void initGame();
    void startGame();
    void update();
    void doDrawing();

    static bool randomBool() {
        return 0 + (rand() % (1 - 0 + 1)) == 1;
    }
};


#endif //LIFE_LIFE_H
