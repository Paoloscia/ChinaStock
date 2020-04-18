#include "cliente.h"
#include"mainwindow.h"
#include"addclientwindow.h"
#include <QApplication>
#include<iostream>
using std::cout;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    mainwindow w;
    addClientWindow x;
    w.show();
    x.show();
    return a.exec();

}
