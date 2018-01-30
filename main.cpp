#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    QTranslator translator;
    translator.load("zh_CN");
    a.installTranslator(&translator);


    w.setMinimumSize(700,900);
    w.show();

    return a.exec();
}
