#include "controller.h"

controller::controller(QObject *parent) : QObject(parent),view(new mainwindow()), addClientW(new addClientWindow(view))
{
    connect(view,SIGNAL(signOpenAddWindow()),this,SLOT(openAddView()));
    view->show();
}

void controller::openAddView()
{
    //addClientW->Clear(); metodo da aggiungere dopo dentro ad addClientWindow, pensare se è necessario per add
    addClientW->setModal(true);
    addClientW->show();
}
