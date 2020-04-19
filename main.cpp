#include "cliente.h"
#include"controller.h"
#include <QApplication>
#include<iostream>
using std::cout;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    controller y(nullptr);
    return a.exec();

}
