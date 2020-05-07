#include "controller.h"
//controller::controller(QObject *parent) : QObject(parent),view(new mainwindow()),m(new model("data.xml")), addClientW(new addClientWindow(view))   //versione nuova da implementare che pesca data.xml
controller::controller(QObject *parent) : QObject(parent),view(new mainwindow()), addClientW(new addClientWindow(view)), ModifyClientW(new modifyClientWindow(view)), m(new model("data.xml"))   //controllare ordine inizializzazione
{
    //CONNESSIONI A PAGINA MAINWINDOW
    connect(view,SIGNAL(signOpenAddWindow()),this,SLOT(openAddView()));
    connect(view,SIGNAL(signOpenModWindow()),this,SLOT(openModifyView()));
    connect(view,SIGNAL(salvaFileMenu()),this,SLOT(salvaFile()));
    connect(view,SIGNAL(richiestaRimozCliente(const unsigned int)),this,SLOT(rimuoviCliente(const unsigned int)));
    connect(view,SIGNAL(richiestaShowCliente(const unsigned int)),this,SLOT(mostraCliente(const unsigned int)));
    connect(view, SIGNAL(cercaRuntime()), this, SLOT(resetListaClienti()));
    connect(view, SIGNAL(filtroPiscina()), this, SLOT(filtraClientiPiscina()));
    connect(view, SIGNAL(filtroTutti()), this, SLOT(filtraTuttiClienti()));
    connect(view, SIGNAL(filtroPalestra()), this, SLOT(filtraClientiPalestra()));
    connect(view, SIGNAL(filtroMaggiorenne()), this, SLOT(filtraClientiMaggiorenni()));
    connect(view, SIGNAL(filtroMinorenne()), this, SLOT(filtraClientiMinorenni()));
    connect(view, SIGNAL(filtroStudente()), this, SLOT(filtraClientiStudenti()));
    connect(view,SIGNAL(controllaModificato()),this,SLOT(salvaIfModificato()));


    connect(view, SIGNAL(filtroVip()), this, SLOT(filtraClientiVip()));
    connect(view, SIGNAL(filtroCorsoPiscina()), this, SLOT(filtraClientiIstruttoriPiscina()));
    connect(view, SIGNAL(filtroSchedaPalestra()), this, SLOT(filtraClientiIStruttoriPalestra()));
    //connect(view, SIGNAL(updateSearch()), this, SLOT(resetListaClienti())); implementare!!!

    connect(m, SIGNAL(clienteAggiunto()), this, SLOT(resetListaClienti()));

    connect(m, SIGNAL(clienteRimosso()), this, SLOT(resetListaClienti()));

    //CONNESSIONI DA PAGINA ADDCLIENTWINDOW
    connect(addClientW, SIGNAL(inviaStringaCliente(const QStringList)), this, SLOT(aggClienteContainer(const QStringList)));
    connect(this, SIGNAL(pulisciCampi()), addClientW, SLOT(pulisciRighe()));
    connect(addClientW, SIGNAL(erroreInput(string)), this, SLOT(erroreInputRicevuto(string)));
    //connect(modifyClientW, SIGNAL(erroreInput()), this, SLOT(erroreInputRicevuto())); bisognerà implementare visualizzazione errore per modifywindow, qui e nella sua fase di costruzione sul costruttore del controller!!!

    connect(ModifyClientW, SIGNAL(rimpiazzaCliente(const unsigned int,const QStringList)), this, SLOT(rimpiazzaItem(const unsigned int, QStringList)));

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

void controller::openModifyView()
{
    if(view->isSelected()){
        ModifyClientW->caricaDati(m->getCampiCliente(view->getIndexSelected()), view->getIndexSelected());
        ModifyClientW->setModal(true);
        ModifyClientW->show();
    }
    else
        view->nessunSelezionato();
}

void controller::rimuoviCliente(const unsigned int indice){
    m->rimuoviCliente(indexTranslate[indice]);
    resetListaClienti();//viene chiamato già dalla connect?
}

void controller::rimpiazzaItem(const unsigned int indice, const QStringList stringaCliente)
{
    m->modificaItem(indexTranslate[indice], stringaCliente);
    resetListaClienti();  //viene chiamato già dalla connect?
}

void controller::mostraCliente(const unsigned int cliente){
    view->visualizzaDettagliCliente(m->mostraCliente(indexTranslate[cliente]));
}

void controller::salvaIfModificato()
{
    //mettere la richiesta "sei sicuro?"
    if (m->getModificato())
        emit salvaFile();
}

void controller::filtraClientiPiscina()
{
    m->filterPiscina();
    resetListaClienti();
}

void controller::filtraTuttiClienti()
{
    m->resetfiltro();
    resetListaClienti();
}

void controller::filtraClientiPalestra()
{
    m->filterPalestra();
    resetListaClienti();
}

void controller::filtraClientiMaggiorenni()
{
    m->filterMaggiorenne();
    resetListaClienti();
}

void controller::filtraClientiMinorenni()
{
    m->filterMinorenne();
    resetListaClienti();
}

void controller::filtraClientiStudenti()
{
    m->filterStudente();
    resetListaClienti();
}

void controller::filtraClientiVip()
{
    m->filterVip();
    resetListaClienti();
}

void controller::filtraClientiIstruttoriPiscina()
{
    m->filterCorsoPiscina();
    resetListaClienti();
}

void controller::filtraClientiIStruttoriPalestra()
{
    m->filterSchedaPalestra();
    resetListaClienti();
}

void controller::resetListaClienti() //implementato per mostrare la lista di clienti in mainwindow
{

    QString parolaNelCampoCerca = view->getParolaCercata();

    view->mostraClienti(m->getListaClientiFiltrata(parolaNelCampoCerca,indexTranslate));

    resetDettClienteView();
}

void controller::resetDettClienteView(){
    view->resetDettCliente();
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

void controller::erroreInputRicevuto(string motivo)
{
    addClientW->mostraErroreInput(motivo);
}
