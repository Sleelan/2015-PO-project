#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    extern summit Human;
    static int playerClass;
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
