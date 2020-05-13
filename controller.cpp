#include "controller.h"
controller::controller(QObject *parent) : QObject(parent),view(new mainwindow()), addClientW(new addClientWindow(view)), ModifyClientW(new modifyClientWindow(view)), m(new model("data.xml"))
{
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
    connect(view, SIGNAL(signStampaPDFCliente()), this, SLOT(stampaPDFCliente()));
    connect(view, SIGNAL(signEsportaCsvClienti()), this, SLOT(esportaCsvClienti()));
    connect(view, SIGNAL(filtroVip()), this, SLOT(filtraClientiVip()));
    connect(view, SIGNAL(filtroCorsoNuoto()), this, SLOT(filtraClientiIstruttoriPiscina()));
    connect(view, SIGNAL(filtroSchedaPalestra()), this, SLOT(filtraClientiIStruttoriPalestra()));

    connect(m, SIGNAL(clienteAggiunto()), this, SLOT(resetListaClienti()));
    connect(m, SIGNAL(clienteRimosso()), this, SLOT(resetListaClienti()));
    connect(m, SIGNAL(resetColoreFiltroM()), this, SLOT(resetColoreFiltroC()));

    connect(addClientW, SIGNAL(inviaStringaCliente(const QStringList)), this, SLOT(aggClienteContainer(const QStringList)));
    connect(addClientW, SIGNAL(erroreInput(string)), this, SLOT(erroreInputRicevuto(string)));

    //connect(modifyClientW, SIGNAL(erroreInput()), this, SLOT(erroreInputRicevuto())); bisognerà implementare visualizzazione errore per modifywindow, qui e nella sua fase di costruzione sul costruttore del controller!!!  --- RISOLTO?
    connect(ModifyClientW, SIGNAL(rimpiazzaCliente(const unsigned int,const QStringList)), this, SLOT(rimpiazzaItem(const unsigned int, QStringList)));
    resetListaClienti();
    view->show();
}

void controller::openAddView()
{
    addClientW->pulisciRighe();
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
}

void controller::rimpiazzaItem(const unsigned int indice, const QStringList stringaCliente)
{
    m->modificaItem(indexTranslate[indice], stringaCliente);
    resetListaClienti();
}

void controller::mostraCliente(const unsigned int cliente){
    view->visualizzaDettagliCliente(m->mostraCliente(indexTranslate[cliente]));
}

void controller::salvaIfModificato()
{
    if (m->getModificato())
        if(QMessageBox::question(view, "ChinaFit","Desideri salvare le modifiche?")==QMessageBox::Yes){
            emit salvaFile();
        }
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

void controller::resetColoreFiltroC()
{
    view->resetColoreFiltro();
}

void controller::stampaPDFCliente() const
{

}

void controller::esportaCsvClienti() const
{
    //bisogna aggiungere che si può scegliere dove salvarlo!
    ofstream myfile("test.csv"); //crea file e lo apre

    //ofstream myfile; alternativa, creo prima oggetto file e poi lo apro
    //myfile.open("test.csv");
    QStringList listaClienti = m->getListaClientiCsv();

    myfile<<"Nome,Cognome,Codice fiscale,Luogo di nascita,Residenza,Via,Telefono,Mail,Data di nascita,Studente"<<endl;
    auto it = listaClienti.begin();
    while(it!=listaClienti.end()){
        myfile<<it->toStdString()<<endl;
        ++it;
    }
    //emit successoEsportCsv(); bisogna mettere message box che si apre quando ho fatto esportazione
    myfile.close();
}

void controller::resetListaClienti()
{
    QString parolaNelCampoCerca = view->getParolaCercata();
    view->mostraClienti(m->getListaClientiFiltrata(parolaNelCampoCerca,indexTranslate));
    resetDettClienteView();
}

void controller::resetDettClienteView(){
    view->resetDettCliente();
}

void controller::aggClienteContainer(const QStringList dettagli)
{
    //if(details.first()=="null") FINIRE DI IMPLEMENTARE FUNZIONE CON CONTROLLI
    //    view->displayInputError();
//    else {
//        if(details[1]=="null")
//            view->displayInputError();
//        else{
//            if(!m->checkIfExistIntoCatalog(dettagli))
                m->aggNelContainer(dettagli);
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
