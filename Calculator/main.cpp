#include "calculator.h"

#include <QApplication>

//The main method
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Calculator w;
    w.show();

    return a.exec();
}
