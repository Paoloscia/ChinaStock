#include "mainwindow.h"


mainwindow::mainwindow(QWidget *parent) : QWidget(parent), listaClienti(new viewListaClienti(this)),nomeClienteLabel (new QLabel(this)),
    cognomeClienteLabel(new QLabel(this)),codiceFClienteLabel(new QLabel(this)),LuogoDNLabel(new QLabel(this)),residenzaClienteLabel(new QLabel(this)),
    viaClienteLabel(new QLabel(this)), telefonoClienteLabel(new QLabel(this)), mailClienteLabel(new QLabel(this)), datadNClienteLabel(new QLabel(this)),AbbonamentoPiscinaLabel(new QLabel(this)),
    nomeIstruttorePiscinaLabel(new QLabel(this)), AbbonamentoPalestraLabel(new QLabel(this)),nomeIstruttorePalestraLabel(new QLabel(this))
{
    setWindowTitle("China Fit");
    mainLayout = new QVBoxLayout(this);

    QMenuBar* menubar = new QMenuBar(this);
    QMenu* menu= new QMenu("File",menubar);
    QAction* salva = new QAction("Salva",menu);
    QAction* exit = new QAction("Esci",menu);
    menu->addAction(exit);
    menu->addAction(salva);
    menubar->addMenu(menu);
    mainLayout->addWidget(menubar);

    setMainWindowStyle();
    gridLayout = new QGridLayout();
    verticalSxLayout = new QVBoxLayout();
    verticalDxLayout = new QVBoxLayout();
    divH = new QHBoxLayout();

    mainLayout->addLayout(gridLayout);
    mainLayout->addLayout(divH);
    divH->addLayout(verticalSxLayout);

    setLayout(mainLayout);

    //************** FILTRI ********************

    All = new QCheckBox("All",this);
    palestraCheckFiltro = new QCheckBox("Palestra",this);
    piscinaCheckFiltro = new QCheckBox("Piscina",this);
    minorenne = new QCheckBox("Minorenne",this);
    maggiorenne = new QCheckBox("Maggiorenne",this);
    deseleziona = new QCheckBox("Deseleziona Tutto",this);
    lineCerca = new QLineEdit(this);
    gridLayout->addWidget(All,0,0);
    gridLayout->addWidget(palestraCheckFiltro,1,0);
    gridLayout->addWidget(piscinaCheckFiltro,2,0);
    gridLayout->addWidget(minorenne,0,1);
    gridLayout->addWidget(maggiorenne,1,1);
    gridLayout->addWidget(deseleziona,2,1);
    gridLayout->addWidget(lineCerca,2,2);
    gridLayout->addWidget(Cerca,2,3);

    //************** CLIENTI ********************

    QGroupBox *clientiGroup = new QGroupBox("Clienti");
    listaClienti->setSelectionMode(QAbstractItemView::SingleSelection);
    QVBoxLayout *layoutListaClienti = new QVBoxLayout();
    layoutListaClienti->addWidget(listaClienti);
    clientiGroup->setLayout(layoutListaClienti);
    addButton = new QPushButton("Aggiungi",this);
    modButton = new QPushButton("Modifica",this);
    removeButton = new QPushButton("Rimuovi",this);

    verticalSxLayout->addWidget(clientiGroup);
    hLeftBottoni = new QHBoxLayout();
    verticalSxLayout->addLayout(hLeftBottoni);
    hLeftBottoni->addWidget(addButton);
    hLeftBottoni->addWidget(modButton);
    hLeftBottoni->addWidget(removeButton);

    //************** FORM ********************

    QLabel *nomeLabel = new QLabel(tr("Nome: "));
    QLabel *cognomeLabel = new QLabel(tr("Cognome: "));
    QLabel *codFiscLabel = new QLabel(tr("Codice Fiscale: "));
    QLabel *ldnLabel = new QLabel(tr("Luogo di nascita: "));
    QLabel *residenzaLabel = new QLabel(tr("Residenza: "));
    QLabel *viaLabel = new QLabel(tr("Via: "));
    QLabel *telefonoLabel = new QLabel(tr("Telefono: "));
    QLabel *mailLabel = new QLabel(tr("Mail: "));
    QLabel *dateNascitaLabel = new QLabel("Data di nascita: ");
    dateNascita = (new QDateEdit(QDate::currentDate(),this));
    dateNascita->setCalendarPopup(true);


    studenteCheckbox = new QCheckBox("Studente",this);

    //************** PEZZO FORM PISCINA ********************

    QGroupBox *piscinaGroup = new QGroupBox("Piscina");
    QFormLayout *formPiscinaLayout = new QFormLayout();

    QLabel *dateScadPiscinaLabel = new QLabel("Data: ");
    dateScadPiscina = (new QDateEdit(QDate::currentDate(),this));
    dateScadPiscina->setCalendarPopup(true);
    QLabel *nomeIstruttorePiscinaLabel = new QLabel(tr("Nome istruttore: "));
    nomeIstruttorePiscinaEdit = new QLineEdit();
    corsoNuotoCheckbox = new QCheckBox("Corso nuoto",this);

    formPiscinaLayout->addRow(dateScadPiscinaLabel,dateScadPiscina);
    formPiscinaLayout->addRow(nomeIstruttorePiscinaLabel,nomeIstruttorePiscinaEdit);
    formPiscinaLayout->addRow(corsoNuotoCheckbox);
    piscinaGroup->setLayout(formPiscinaLayout);

    //************** PEZZO FORM PALESTRA ********************

    QGroupBox *palestraGroup = new QGroupBox("Palestra");
    QFormLayout *formPalestraLayout = new QFormLayout();

    QLabel *dateScadPalestraLabel = new QLabel("Data: ");
    dateScadPalestra = (new QDateEdit(QDate::currentDate(),this));
    dateScadPalestra->setCalendarPopup(true);
    QLabel *nomeIstruttorePalestraLabel = new QLabel(tr("Nome istruttore: "));
    nomeIstruttorePalestraEdit = new QLineEdit();
    schedaPalestraCheckbox = new QCheckBox("Scheda palestra",this);

    formPalestraLayout->addRow(dateScadPalestraLabel,dateScadPalestra);
    formPalestraLayout->addRow(nomeIstruttorePalestraLabel,nomeIstruttorePalestraEdit);
    formPalestraLayout->addRow(schedaPalestraCheckbox);
    palestraGroup->setLayout(formPalestraLayout);

    QFormLayout *formLayout = new QFormLayout();
    formLayout->setFormAlignment(Qt::AlignLeft);
    formLayout->addRow(nomeLabel, nomeClienteLabel);
    formLayout->addRow(cognomeLabel, cognomeClienteLabel);
    formLayout->addRow(codFiscLabel, codiceFClienteLabel);
    formLayout->addRow(ldnLabel, LuogoDNLabel);
    formLayout->addRow(residenzaLabel, residenzaClienteLabel);
    formLayout->addRow(viaLabel, viaClienteLabel);
    formLayout->addRow(telefonoLabel, telefonoClienteLabel);
    formLayout->addRow(mailLabel, mailClienteLabel);
    formLayout->addRow(dateNascitaLabel, dateNascita);
    formLayout->addRow(studenteCheckbox);

    divH->addLayout(formLayout);
    divH->addLayout(verticalDxLayout);
    verticalDxLayout->addWidget(piscinaGroup);
    verticalDxLayout->addWidget(palestraGroup);

    //************** PARTE CONNECT **************************


    connect(addButton, SIGNAL(clicked()), this, SIGNAL(signOpenAddWindow()));
    connect(salva, SIGNAL(triggered()), this, SIGNAL(salvaFileMenu()));
    connect(lineCerca, SIGNAL(textChanged(const QString &)), this, SIGNAL(cercaRuntime()));
    connect(removeButton, SIGNAL(clicked()),this, SLOT(richiestaRimoz()));
    connect(modButton, SIGNAL(clicked()), this, SIGNAL(signOpenModWindow()));
    connect(listaClienti, SIGNAL(itemSelectionChanged()), this, SLOT(showInfoCliente()));

}

void mainwindow::mostraClienti(const QStringList datiCliente) //datiCliente pesca i dati salvati da schermata aggiungi/modifica cliente quando viene ciclato
{
    listaClienti->reset();
    listaClienti->clear();
    auto it = datiCliente.begin();
    while(it!=datiCliente.end()){
        listaClienti->addItem(*it);
        ++it;
    }
}

const QString mainwindow::getParolaCercata() const
{
    return lineCerca->text();
}

void mainwindow::nessunSelezionato()
{
    QMessageBox rimuoviNonSelezionato;
    rimuoviNonSelezionato.critical(this,"Nessun cliente selezionato","Selezionare un cliente");
}

void mainwindow::visualizzaDettagliCliente(deepPointer<cliente> clienteDaVisualizzare){
    if (dynamic_cast<vip*>(clienteDaVisualizzare.pted) != nullptr) {
        auto clientevip = dynamic_cast<vip*>(clienteDaVisualizzare.pted);
        string istruttpisc = clientevip->getnomeistruttorepiscina();
        string istruttpal = clientevip->getnomeistruttorepalestra();
        cout<<"il cliente è un vip!!! "<<"istr piscina = "<<istruttpisc<<"istr palestra = "<<istruttpal<<endl;
//
    }
    else if (dynamic_cast<piscina*>(clienteDaVisualizzare.pted) != nullptr) {
        auto clientepis = dynamic_cast<piscina*>(clienteDaVisualizzare.pted);
        string istruttpisc = clientepis->getnomeistruttorepiscina();
        cout<<"il cliente è un piscina!!! istr piscina = "<<istruttpisc<<endl;
//        auto clientevip = dynamic_cast<vip *>(clienteDaVisualizzare);
    }
    else if (dynamic_cast<palestra*>(clienteDaVisualizzare.pted) != nullptr) {
        auto clientepal = dynamic_cast<palestra*>(clienteDaVisualizzare.pted);
        string istruttpal = clientepal->getnomeistruttorepalestra();
        cout<<"il cliente è un palestra!!! istr palestra = "<<istruttpal<<endl;
//        auto clientevip = dynamic_cast<vip *>(clienteDaVisualizzare);
    }
    QString nome = QString::fromStdString(clienteDaVisualizzare->getnome());
    nomeClienteLabel->clear();
    nomeClienteLabel->setText(nome);
    QString cognome = QString::fromStdString(clienteDaVisualizzare->getcognome());
    cognomeClienteLabel->clear();
    cognomeClienteLabel->setText(cognome);
    QString codiceFiscale = QString::fromStdString(clienteDaVisualizzare->getcodfiscale());
    codiceFClienteLabel->clear();
    codiceFClienteLabel->setText(codiceFiscale);
    QString LuogoDN = QString:: fromStdString(clienteDaVisualizzare->getluogo());
    LuogoDNLabel->clear();
    LuogoDNLabel->setText(LuogoDN);
    QString residenza = QString:: fromStdString(clienteDaVisualizzare->getres());
    residenzaClienteLabel->clear();
    residenzaClienteLabel->setText(residenza);
    QString via = QString:: fromStdString(clienteDaVisualizzare->getvia());
    viaClienteLabel->clear();
    viaClienteLabel->setText(via);
    QString telefono =  QString:: fromStdString(clienteDaVisualizzare->getnumerotel());
    telefonoClienteLabel->clear();
    telefonoClienteLabel->setText(telefono);
    QString mail =  QString:: fromStdString(clienteDaVisualizzare->getmail());
    mailClienteLabel->clear();
    mailClienteLabel->setText(mail);
    //QString dataNascita =  QString:: fromStdString(clienteDaVisualizzare->getAnnoN());capire come mostrare data
    //datadNClienteLabel->clear();
    //datadNClienteLabel->setDate(dataNascita);
    //QString IstruttorePiscina =  QString:: fromStdString(clienteDaVisualizzare->));
    //bisognerà fare controllo con cast per decidere che campi prendere in base al tipo di cliente
}

void mainwindow::resetDettCliente()
{
    nomeClienteLabel->clear();
    cognomeClienteLabel->clear();
    codiceFClienteLabel->clear();
    LuogoDNLabel->clear();
    residenzaClienteLabel->clear();
    viaClienteLabel->clear();
    telefonoClienteLabel->clear();
    mailClienteLabel->clear();
    //mettere tutta la lista dei dettagli cliente da resettare nella view!!!
}

bool mainwindow::isSelected() const
{
    return listaClienti->isSomeoneSelected();
}

unsigned int mainwindow::getIndexSelected() const
{
    return listaClienti->getIndex();
}


void mainwindow::setMainWindowStyle()
{
    QFile file(":risorse/style.css");
    file.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(file.readAll());
    setStyleSheet(styleSheet);
}


/*
void mainwindow::handleSearchClick()
{
    QString searchText = searchInput->text();
    emit clickedSearch(searchText);

}
*/


void mainwindow::richiestaRimoz()
{
    if(listaClienti->isSomeoneSelected())
        emit richiestaRimozCliente(listaClienti->getIndex());
    else{
        nessunSelezionato();
    }
}

void mainwindow::showInfoCliente(){
    if(listaClienti->isSomeoneSelected()) //vedere se serve davvero
        //refreshMainW; bisogna implementare
        emit richiestaShowCliente(listaClienti->getIndex());
}


