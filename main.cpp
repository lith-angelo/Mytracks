#include "mainwindow.h"
#include <QApplication>
#include <QPluginLoader>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("欢迎来到Mytracks!");
    w.show();

    return a.exec();
}

