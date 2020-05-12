#include"controller.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    controller y(nullptr);
    return a.exec();
}

