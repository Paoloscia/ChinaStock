#include "cliente.h"
#include"controller.h"
#include <QApplication>
#include<iostream>
using std::cout;
/*
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    controller y(nullptr);
    return a.exec();
}
*/
//---PROVA CONTAINER---
int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    Container<int>* c = new Container<int>();
    c->aggiungiDietro(1);
    c->aggiungiDavanti(2);
    c->aggiungiDietro(3);
    c->rimuovi(2);
    for(auto it = c->inizio(); it != c->fine(); ++it)
        cout<<*it<<" ";
    //cout<<c->size()<<std::endl; BISOGNA FARE LA SIZE!!!
    cout<<"FINE";
    return a.exec();

}
