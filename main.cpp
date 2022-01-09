#include <random>
#include <unistd.h>
#include "life.h"
#include "main.h"


int main(int argc, char *argv[]) {

    QApplication app(argc, argv);
    Life window;
    window.setWindowTitle("Life");
    window.show();
    return app.exec();
}
