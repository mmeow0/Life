//
// Created by Ajgul Tumerkina on 09.01.2022.
//

#ifndef LIFE_BUTTONS_H
#define LIFE_BUTTONS_H


#include "Qt.h"

class Buttons : public QWidget {

public:
    Buttons(QWidget *parent = nullptr);

private:
    QPushButton *startButton;
    QPushButton *exitButton;
};

#endif //LIFE_BUTTONS_H
