#include "controller.h"
//controller::controller(QObject *parent) : QObject(parent),view(new mainwindow()),m(new model("data.xml")), addClientW(new addClientWindow(view))   //versione nuova da implementare che pesca data.xml
controller::controller(QObject *parent) : QObject(parent),view(new mainwindow()), addClientW(new addClientWindow(view))   //controllare ordine inizializzazione
{
    connect(view,SIGNAL(signOpenAddWindow()),this,SLOT(openAddView()));
    connect(view,SIGNAL(salvaFileMenu()),this,SLOT(salvaFile()));

    //connect(view, SIGNAL(updateSearch()), this, SLOT(refreshCatalog())); implementare!!!

    //connect(m, SIGNAL(clienteAggiunto()), this, SLOT(resetListaClienti()));

    //connect(m, SIGNAL(catalogRemoved()), this, SLOT(refreshCatalog())); implementare!!!

    //CONNESSIONI DA PAGINA ADDCLIENTWINDOW
    connect(addClientW, SIGNAL(inviaStringaCliente(const QStringList)), this, SLOT(aggClienteContainer(const QStringList)));

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

void controller::salvaFile()
{
    m->salva();
}

void controller::resetListaClienti()
{
    //QString filter=mainW->getResearchWord();
    //mainW->displayCatalog(modello->getFilteredCatalog(filter,indexTranslate));

    //view->mostraClienti(); da completare, capire cosa passare dentro a mostraClienti
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

void controller::aggClienteContainer(const QStringList dettagli)
{
    //if(details.first()=="null") FINIRE DI IMPLEMENTARE FUNZIONE CON CONTROLLI
    //    view->displayInputError();
//    else {
//        if(details[1]=="null")
//            view->displayInputError();
//        else{
//            if(!m->checkIfExistIntoCatalog(dettagli))
                m->aggNelContainer(dettagli); //FARLO CON CONNECT!!!!
//            else{
//                m->displayTheElementExist();
//            }
//        }
//    }
}
