#include "controller.h"

controller::controller(QObject *parent) : QObject(parent),view(new mainwindow()), addClientW(new addClientWindow(view))   //view finale??
{
    connect(view,SIGNAL(signOpenAddWindow()),this,SLOT(openAddView()));
    view->show();
}

//pezzo per search da implementare
//controller::controller(model *mod, mainwindow *vw):m(mod),view(vw)
//{
//   connect(view, SIGNAL(clickedSearch(QString)),this, SLOT(search(QString))); // lui al posto di this ha messo m ! DA RIVEDERE!!

//}

void controller::openAddView()
{
    //addClientW->Clear(); metodo da aggiungere dopo dentro ad addClientWindow, pensare se è necessario per add
    addClientW->setModal(true);
    addClientW->show();
}

//void controller::openModify() const
//{
//    QStringList oldData= model->GetRecord(index);
//    modifyclientwindow->SetFields();
//    modWindow->setModal(true);
//    modWindow->show();

//}

/*void controller::openSave() const
{

}*/
