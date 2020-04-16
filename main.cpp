#include "cliente.h"
#include"mainwindow.h"
#include <QApplication>
#include<iostream>
using std::cout;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    mainwindow w;
    w.show();
    return a.exec();

}
