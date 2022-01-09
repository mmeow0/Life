//
// Created by Ajgul Tumerkina on 09.01.2022.
//



#include "Buttons.h"


Buttons::Buttons(QWidget *parent): QWidget(parent) {

    auto *vbox = new QVBoxLayout(this);
    auto *hbox = new QHBoxLayout();

    startButton = new QPushButton("Start", this);
    exitButton = new QPushButton("Quit", this);

    hbox->addWidget(startButton, 1, Qt::AlignRight);
    hbox->addWidget(exitButton, 0);

    vbox->addStretch(1);
    vbox->addLayout(hbox);
}