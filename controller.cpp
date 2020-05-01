#include "controller.h"
//controller::controller(QObject *parent) : QObject(parent),view(new mainwindow()),m(new model("data.xml")), addClientW(new addClientWindow(view))   //versione nuova da implementare che pesca data.xml
controller::controller(QObject *parent) : QObject(parent),view(new mainwindow()), addClientW(new addClientWindow(view)), m(new model("data.xml"))   //controllare ordine inizializzazione
{
    //CONNESSIONI A PAGINA MAINWINDOW
    connect(view,SIGNAL(signOpenAddWindow()),this,SLOT(openAddView()));
    connect(view,SIGNAL(salvaFileMenu()),this,SLOT(salvaFile()));
    connect(view,SIGNAL(richiestaRimozCliente(const unsigned int)),this,SLOT(rimuoviCliente(const unsigned int)));

    //connect(view, SIGNAL(updateSearch()), this, SLOT(refreshCatalog())); implementare!!!

    connect(m, SIGNAL(clienteAggiunto()), this, SLOT(resetListaClienti()));

    connect(m, SIGNAL(clienteRimosso()), this, SLOT(resetListaClienti()));

    //CONNESSIONI DA PAGINA ADDCLIENTWINDOW
    connect(addClientW, SIGNAL(inviaStringaCliente(const QStringList)), this, SLOT(aggClienteContainer(const QStringList)));
    connect(this, SIGNAL(pulisciCampi()), addClientW, SLOT(pulisciRighe()));
    connect(addClientW, SIGNAL(erroreInput()), this, SLOT(erroreInputRicevuto()));
    //connect(modifyClientW, SIGNAL(erroreInput()), this, SLOT(erroreInputRicevuto())); bisognerà implementare visualizzazione errore per modifywindow, qui e nella sua fase di costruzione sul costruttore del controller!!!

    view->show();
}

//pezzo per search da implementare
//controller::controller(model *mod, mainwindow *vw):m(mod),view(vw)
//{
//   connect(view, SIGNAL(clickedSearch(QString)),this, SLOT(search(QString))); // lui al posto di this ha messo m ! DA RIVEDERE!!

//}

void controller::openAddView()
{
    emit pulisciCampi();
    //addClientW->Clear(); metodo da aggiungere dopo dentro ad addClientWindow, pensare se è necessario per add
    addClientW->setModal(true);
    addClientW->show();
}

void controller::salvaFile()
{
    m->salva();
}

void controller::rimuoviCliente(const unsigned int cliente){
    m->rimuoviCliente(indexTranslate[cliente]);
    //refreshCatalog(); bisogna implementare reset della lista clienti
}

void controller::resetListaClienti() //implementato per mostrare la lista di clienti in mainwindow
{
    QString filtro = view->getParolaCercata();

    view->mostraClienti(m->getListaClientiFiltrata(filtro,indexTranslate));
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

void controller::erroreInputRicevuto()
{
    addClientW->mostraErroreInput();
}
