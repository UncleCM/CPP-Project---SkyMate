// #include "mainwindow.h"
#include "signup.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Signup s;
    s.show();
    // MainWindow w;
    // w.show();
    return a.exec();
}
