#include "mainwindow.h"


mainwindow::mainwindow(QWidget *parent) : QWidget(parent), listaClienti(new viewListaClienti(this)),nomeClienteLabel (new QLabel(this)),
    cognomeClienteLabel(new QLabel(this)),codiceFClienteLabel(new QLabel(this)),LuogoDNLabel(new QLabel(this)),residenzaClienteLabel(new QLabel(this)),
    viaClienteLabel(new QLabel(this)), telefonoClienteLabel(new QLabel(this)), mailClienteLabel(new QLabel(this)),datadNClienteLabel(new QLabel(this)),studenteClienteLabel(new QLabel(this)),AbbonamentoPiscinaLabel(new QLabel(this)),
    nomeIstruttorePiscinaLabel(new QLabel(this)),corsoNuotoClienteLabel(new QLabel(this)), AbbonamentoPalestraLabel(new QLabel(this)),nomeIstruttorePalestraLabel(new QLabel(this)),schedaPalestraClienteLabel(new QLabel(this))
{
    setWindowTitle("China Fit");
    mainLayout = new QVBoxLayout(this);

    QMenuBar* menubar = new QMenuBar(this);
    QMenu* menu= new QMenu("File",menubar);
    QMenu* Info = new QMenu("Info",menubar);
    QAction* salva = new QAction("Salva",menu);
    QAction* infoProgetto = new QAction("Informazioni",Info);
    salva->setShortcut(Qt::Key_S | Qt::CTRL);
    QAction* esportaCsv = new QAction("Esporta csv clienti",menu);
    QAction* esportaPDF = new QAction("Esporta pdf clienti",menu);
    QAction* exit = new QAction("Esci",menu);
    menu->addAction(exit);
    menu->addAction(esportaCsv);
    menu->addAction(esportaPDF);
    menu->addAction(salva);
    Info->addAction(infoProgetto);
    menubar->addMenu(menu);
    menubar->addMenu(Info);
    mainLayout->addWidget(menubar);

    setMainWindowStyle();
    verticalSxLayout = new QVBoxLayout();
    verticalDxLayout = new QVBoxLayout();
    divH = new QHBoxLayout();

    mainLayout->addLayout(divH);
    divH->addLayout(verticalSxLayout);

    setLayout(mainLayout);

    //************** IMMAGINE ******************
    QHBoxLayout* imageLayout = new QHBoxLayout();

    QPixmap*  pix = new QPixmap(":/risorse/provachina.jpg");
    QLabel* image = new QLabel(this);
    image->setPixmap(*pix);
    imageLayout->addWidget(image);
    image->setMaximumWidth(350);
    image->setMaximumHeight(300);
    verticalDxLayout->addLayout(imageLayout);

    //************** FILTRI ********************

    QGroupBox *filtriGroup = new QGroupBox("Filtri");
    QGridLayout* filtriGrid = new QGridLayout();
    All = new QPushButton("Rimuovi filtro",this);
    palestraCheckFiltro = new QPushButton("Palestra",this);
    piscinaCheckFiltro = new QPushButton("Piscina",this);
    checkfiltrominorenne = new QPushButton("Minorenne",this);
    checkfiltromaggiorenne = new QPushButton("Maggiorenne",this);
    checkfiltrostudente = new QPushButton("Studente",this);
    checkVip = new QPushButton("Vip",this);
    checkfiltrocorsopiscina = new QPushButton("Corso nuoto",this);
    checkfiltroschedapalestra = new QPushButton("Scheda palestra",this);
    filtriGrid->addWidget(All,2,2); //tenere per primo, inizializzato per primo per impostare focus su questo
    filtriGrid->addWidget(piscinaCheckFiltro,0,0);
    filtriGrid->addWidget(palestraCheckFiltro,0,1);
    filtriGrid->addWidget(checkVip,0,2);
    filtriGrid->addWidget(checkfiltrominorenne,1,0);
    filtriGrid->addWidget(checkfiltromaggiorenne,1,1);
    filtriGrid->addWidget(checkfiltrostudente,1,2);
    filtriGrid->addWidget(checkfiltrocorsopiscina,2,0);
    filtriGrid->addWidget(checkfiltroschedapalestra,2,1);


    filtriGroup->setLayout(filtriGrid);
    verticalSxLayout->addWidget(filtriGroup);

    //************** CLIENTI ********************

    QGroupBox *clientiGroup = new QGroupBox("Lista Clienti");
    listaClienti->setSelectionMode(QAbstractItemView::SingleSelection);
    QVBoxLayout *layoutListaClienti = new QVBoxLayout();
    lineCerca = new QLineEdit(this);
    lineCerca->setPlaceholderText("Cerca");
    cercaHBottoni = new QHBoxLayout();
    cercaHBottoni->addWidget(lineCerca);
    layoutListaClienti->addLayout(cercaHBottoni);
    layoutListaClienti->addWidget(listaClienti);
    clientiGroup->setLayout(layoutListaClienti);
    addButton = new QPushButton("Aggiungi",this);
    addButton->setMinimumWidth(100);
    modButton = new QPushButton("Modifica",this);
    modButton->setMinimumWidth(100);
    removeButton = new QPushButton("Rimuovi",this);
    removeButton->setMinimumWidth(100);
    stampaPDFCliente = new QPushButton("Stampa Cliente", this);
    stampaPDFCliente->setMinimumWidth(100);

    verticalSxLayout->addWidget(clientiGroup);

    hLeftBottoni = new QHBoxLayout();
    verticalSxLayout->addLayout(hLeftBottoni);
    hLeftBottoni->addWidget(addButton);
    hLeftBottoni->addWidget(modButton);
    hLeftBottoni->addWidget(removeButton);
    hLeftBottoni->addWidget(stampaPDFCliente);

    //************** FORM ********************
    QGroupBox *clienteGroup = new QGroupBox("Dati Cliente");
    QLabel *nomeLabel = new QLabel(tr("Nome: "));
    QLabel *cognomeLabel = new QLabel(tr("Cognome: "));
    QLabel *codFiscLabel = new QLabel(tr("Codice Fiscale: "));
    QLabel *ldnLabel = new QLabel(tr("Luogo di nascita: "));
    QLabel *residenzaLabel = new QLabel(tr("Residenza: "));
    QLabel *viaLabel = new QLabel(tr("Via: "));
    QLabel *telefonoLabel = new QLabel(tr("Telefono: "));
    QLabel *mailLabel = new QLabel(tr("Mail: "));
    QLabel *dateNascitaLabel = new QLabel("Data di nascita: ");
    QLabel *studenteLabel = new QLabel("Studente: ");

    //************** PEZZO FORM PISCINA ********************

    QGroupBox *piscinaGroup = new QGroupBox("Piscina");
    QFormLayout *formPiscinaLayout = new QFormLayout();
    QLabel *dateScadPiscinaLabel = new QLabel("Data: ");
    QLabel *nomeIstruttorePiscina = new QLabel(tr("Nome istruttore: "));
    QLabel *corsoNuotoLabel = new QLabel("Corso nuoto: ");
    formPiscinaLayout->addRow(dateScadPiscinaLabel,AbbonamentoPiscinaLabel);
    formPiscinaLayout->addRow(nomeIstruttorePiscina,nomeIstruttorePiscinaLabel);
    formPiscinaLayout->addRow(corsoNuotoLabel,corsoNuotoClienteLabel);
    piscinaGroup->setLayout(formPiscinaLayout);

    //************** PEZZO FORM PALESTRA ********************

    QGroupBox *palestraGroup = new QGroupBox("Palestra");
    QFormLayout *formPalestraLayout = new QFormLayout();
    QLabel *dateScadPalestraLabel = new QLabel("Data: ");
    QLabel *nomeIstruttorePalestra = new QLabel(tr("Nome istruttore: "));
    QLabel *schedaPalestraLabel = new QLabel("Scheda palestra: ");
    formPalestraLayout->addRow(dateScadPalestraLabel,AbbonamentoPalestraLabel);
    formPalestraLayout->addRow(nomeIstruttorePalestra,nomeIstruttorePalestraLabel);
    formPalestraLayout->addRow(schedaPalestraLabel,schedaPalestraClienteLabel);
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
    formLayout->addRow(dateNascitaLabel,datadNClienteLabel );
    formLayout->addRow(studenteLabel,studenteClienteLabel);
    clienteGroup->setLayout(formLayout);
    divH->addWidget(clienteGroup);
    divH->addLayout(verticalDxLayout);
    verticalDxLayout->addWidget(piscinaGroup);
    verticalDxLayout->addWidget(palestraGroup);

    //************** PARTE GRAFICA **************************

    //aggiunta object name per css
    palestraCheckFiltro->setObjectName(QStringLiteral("palestraCheckFiltro"));
    piscinaCheckFiltro->setObjectName(QStringLiteral("piscinaCheckFiltro"));
    checkfiltrominorenne->setObjectName(QStringLiteral("checkfiltrominorenne"));
    checkfiltromaggiorenne->setObjectName(QStringLiteral("checkfiltromaggiorenne"));
    checkfiltrostudente->setObjectName(QStringLiteral("checkfiltrostudente"));
    checkVip->setObjectName(QStringLiteral("checkVip"));
    checkfiltrocorsopiscina->setObjectName(QStringLiteral("checkfiltrocorsopiscina"));
    checkfiltroschedapalestra->setObjectName(QStringLiteral("checkfiltroschedapalestra"));
    All->setObjectName(QStringLiteral("All"));

    clienteGroup->setObjectName(QStringLiteral("clienteGroup"));
    piscinaGroup->setObjectName(QStringLiteral("piscinaGroup"));
    palestraGroup->setObjectName(QStringLiteral("palestraGroup"));
    //clienteGroup->setMinimumWidth(350); commentati perchè li ho messi come css
    //palestraGroup->setMinimumWidth(250);

    //************** PARTE CONNECT **************************

    connect(addButton, SIGNAL(clicked()), this, SIGNAL(signOpenAddWindow()));
    connect(infoProgetto,SIGNAL(triggered()),this,SIGNAL(infoWindow()));
    connect(salva, SIGNAL(triggered()), this, SIGNAL(salvaFileMenu()));
    connect(esportaCsv, SIGNAL(triggered()), this, SIGNAL(signEsportaCsvClienti()));
    connect(esportaPDF, SIGNAL(triggered()), this, SIGNAL(signEsportaPDFClienti()));
    connect(lineCerca, SIGNAL(textChanged(const QString &)), this, SIGNAL(cercaRuntime()));
    connect(removeButton, SIGNAL(clicked()),this, SLOT(richiestaRimoz()));
    connect(modButton, SIGNAL(clicked()), this, SIGNAL(signOpenModWindow()));
    connect(listaClienti, SIGNAL(itemSelectionChanged()), this, SLOT(showInfoCliente()));
    connect(stampaPDFCliente,SIGNAL(clicked()), this, SLOT(richiestaPDF()));
    connect(piscinaCheckFiltro, SIGNAL(clicked()), this, SIGNAL(filtroPiscina()));
    connect(All,SIGNAL(clicked()),this,SIGNAL(filtroTutti()));
    connect(palestraCheckFiltro, SIGNAL(clicked()), this, SIGNAL(filtroPalestra()));
    connect(checkfiltromaggiorenne, SIGNAL(clicked()), this, SIGNAL(filtroMaggiorenne()));
    connect(checkfiltrominorenne, SIGNAL(clicked()) , this , SIGNAL(filtroMinorenne()));
    connect(checkfiltrostudente, SIGNAL(clicked()) , this , SIGNAL (filtroStudente()));
    connect(checkVip, SIGNAL(clicked()), this , SIGNAL(filtroVip()));
    connect(checkfiltrocorsopiscina, SIGNAL(clicked()), this , SIGNAL(filtroCorsoNuoto()));
    connect(checkfiltroschedapalestra, SIGNAL(clicked()), this , SIGNAL(filtroSchedaPalestra()));
    connect(palestraCheckFiltro, SIGNAL(clicked()), this, SLOT(coloriFiltroPalestra()));
    connect(checkfiltromaggiorenne, SIGNAL(clicked()), this, SLOT(coloriFiltroMaggiorenne()));
    connect(checkfiltrominorenne, SIGNAL(clicked()) , this , SLOT(coloriFiltroMinorenne()));
    connect(checkfiltrostudente, SIGNAL(clicked()) , this , SLOT (coloriFiltroStudente()));
    connect(checkVip, SIGNAL(clicked()), this , SLOT(coloriFiltroVip()));
    connect(checkfiltrocorsopiscina, SIGNAL(clicked()), this , SLOT(coloriFiltrocorso()));
    connect(checkfiltroschedapalestra, SIGNAL(clicked()), this , SLOT(coloriFiltroScheda()));
    connect(piscinaCheckFiltro, SIGNAL(clicked()), this, SLOT(coloriFiltroPiscina()));
}

void mainwindow::mostraClienti(const QStringList datiCliente)
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
    datadNClienteLabel->clear();
    datadNClienteLabel->setText(clienteDaVisualizzare->getDataN().toString("dd/MM/yyyy"));
    studenteClienteLabel->clear();
    AbbonamentoPiscinaLabel->clear();
    nomeIstruttorePiscinaLabel->clear();
    corsoNuotoClienteLabel->clear();
    AbbonamentoPalestraLabel->clear();
    nomeIstruttorePalestraLabel->clear();
    schedaPalestraClienteLabel->clear();
    if (clienteDaVisualizzare->getstudent()) {
        studenteClienteLabel->setText("Sì");
    }
    else
        studenteClienteLabel->setText("No");

    if (dynamic_cast<vip*>(clienteDaVisualizzare.pted) != nullptr) {
        auto clientevip = dynamic_cast<vip*>(clienteDaVisualizzare.pted);
        string istruttpisc = clientevip->getnomeistruttorepiscina();
        string istruttpal = clientevip->getnomeistruttorepalestra();
        QString nomepisc = QString :: fromStdString(istruttpisc);
        QString nomepale = QString :: fromStdString(istruttpal);
        AbbonamentoPiscinaLabel->setText(clientevip->getDataPiscina().toString("dd/MM/yyyy"));
        nomeIstruttorePiscinaLabel->setText(nomepisc);
        if (clientevip->iscorsonuoto()) {
            corsoNuotoClienteLabel->setText("Sì");
        }
        else
            corsoNuotoClienteLabel->setText("No");
        AbbonamentoPalestraLabel->setText(clientevip->getDataPalestra().toString("dd/MM/yyyy"));
        nomeIstruttorePalestraLabel->setText(nomepale);
        if (clientevip->isscheda()) {
            schedaPalestraClienteLabel->setText("Sì");
        }
        else
            schedaPalestraClienteLabel->setText("No");
    }
    else if (dynamic_cast<piscina*>(clienteDaVisualizzare.pted) != nullptr) {
        auto clientepis = dynamic_cast<piscina*>(clienteDaVisualizzare.pted);
        string istruttpisc = clientepis->getnomeistruttorepiscina();
        QString nomepisc = QString :: fromStdString(istruttpisc);
        AbbonamentoPiscinaLabel->setText(clientepis->getDataPiscina().toString("dd/MM/yyyy"));
        nomeIstruttorePiscinaLabel->setText(nomepisc);
        if (clientepis->iscorsonuoto()) {
            corsoNuotoClienteLabel->setText("Sì");
        }
        else
            corsoNuotoClienteLabel->setText("No");
    }
    else if (dynamic_cast<palestra*>(clienteDaVisualizzare.pted) != nullptr) {
        auto clientepal = dynamic_cast<palestra*>(clienteDaVisualizzare.pted);
        string istruttpal = clientepal->getnomeistruttorepalestra();
        QString nomepale = QString :: fromStdString(istruttpal);
        AbbonamentoPalestraLabel->setText(clientepal->getDataPalestra().toString("dd/MM/yyyy"));
        nomeIstruttorePalestraLabel->setText(nomepale);
        if (clientepal->isscheda()) {
            schedaPalestraClienteLabel->setText("Sì");
        }
        else
            schedaPalestraClienteLabel->setText("No");
    }
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
    datadNClienteLabel->clear();
    studenteClienteLabel->clear();
    AbbonamentoPiscinaLabel->clear();
    nomeIstruttorePiscinaLabel->clear();
    corsoNuotoClienteLabel->clear();
    AbbonamentoPalestraLabel->clear();
    nomeIstruttorePalestraLabel->clear();
    schedaPalestraClienteLabel->clear();
}

bool mainwindow::isSelected() const
{
    return listaClienti->isSomeoneSelected();
}

unsigned int mainwindow::getIndexSelected() const
{
    return listaClienti->getIndex();
}

void mainwindow::resetColoreFiltro()
{
    palestraCheckFiltro->setStyleSheet("background-color:#FFAE42;");
    piscinaCheckFiltro->setStyleSheet("background-color:#FFAE42;");
    checkfiltrominorenne->setStyleSheet("background-color:#FFAE42;");
    checkfiltromaggiorenne->setStyleSheet("background-color:#FFAE42;");
    checkfiltrostudente->setStyleSheet("background-color:#FFAE42;");
    checkVip->setStyleSheet("background-color:#FFAE42;");
    checkfiltrocorsopiscina->setStyleSheet("background-color:#FFAE42;");
    checkfiltroschedapalestra->setStyleSheet("background-color:#FFAE42;");
}


void mainwindow::setMainWindowStyle()
{
    QFile file(":risorse/style.css");
    file.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(file.readAll());
    setStyleSheet(styleSheet);
}

void mainwindow::closeEvent(QCloseEvent *)
{

    emit controllaModificato(); //commentato, sistemare dopo che ha mostrato message box
}


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

void mainwindow::richiestaPDF()
{
    if(listaClienti->isSomeoneSelected())
        emit signStampaPDFCliente(listaClienti->getIndex());
    else{
        nessunSelezionato();
    }

}

void mainwindow::coloriFiltroPalestra()
{
    palestraCheckFiltro->setStyleSheet("background-color:#3cb043;");
    piscinaCheckFiltro->setStyleSheet("background-color:#FFAE42;");
    checkfiltrominorenne->setStyleSheet("background-color:#FFAE42;");
    checkfiltromaggiorenne->setStyleSheet("background-color:#FFAE42;");
    checkfiltrostudente->setStyleSheet("background-color:#FFAE42;");
    checkVip->setStyleSheet("background-color:#FFAE42;");
    checkfiltrocorsopiscina->setStyleSheet("background-color:#FFAE42;");
    checkfiltroschedapalestra->setStyleSheet("background-color:#FFAE42;");

}

void mainwindow::coloriFiltroPiscina()
{
    palestraCheckFiltro->setStyleSheet("background-color:#FFAE42;");
    piscinaCheckFiltro->setStyleSheet("background-color:#3cb043;");
    checkfiltrominorenne->setStyleSheet("background-color:#FFAE42;");
    checkfiltromaggiorenne->setStyleSheet("background-color:#FFAE42;");
    checkfiltrostudente->setStyleSheet("background-color:#FFAE42;");
    checkVip->setStyleSheet("background-color:#FFAE42;");
    checkfiltrocorsopiscina->setStyleSheet("background-color:#FFAE42;");
    checkfiltroschedapalestra->setStyleSheet("background-color:#FFAE42;");

}


void mainwindow::coloriFiltroScheda()
{
    palestraCheckFiltro->setStyleSheet("background-color:#FFAE42;");
    piscinaCheckFiltro->setStyleSheet("background-color:#FFAE42;");
    checkfiltrominorenne->setStyleSheet("background-color:#FFAE42;");
    checkfiltromaggiorenne->setStyleSheet("background-color:#FFAE42;");
    checkfiltrostudente->setStyleSheet("background-color:#FFAE42;");
    checkVip->setStyleSheet("background-color:#FFAE42;");
    checkfiltrocorsopiscina->setStyleSheet("background-color:#FFAE42;");
    checkfiltroschedapalestra->setStyleSheet("background-color:#3cb043;");

}


void mainwindow::coloriFiltrocorso()
{
    palestraCheckFiltro->setStyleSheet("background-color:#FFAE42;");
    piscinaCheckFiltro->setStyleSheet("background-color:#FFAE42;");
    checkfiltrominorenne->setStyleSheet("background-color:#FFAE42;");
    checkfiltromaggiorenne->setStyleSheet("background-color:#FFAE42;");
    checkfiltrostudente->setStyleSheet("background-color:#FFAE42;");
    checkVip->setStyleSheet("background-color:#FFAE42;");
    checkfiltrocorsopiscina->setStyleSheet("background-color:#3cb043;");
    checkfiltroschedapalestra->setStyleSheet("background-color:#FFAE42;");

}


void mainwindow::coloriFiltroVip()
{
    palestraCheckFiltro->setStyleSheet("background-color:#FFAE42;");
    piscinaCheckFiltro->setStyleSheet("background-color:#FFAE42;");
    checkfiltrominorenne->setStyleSheet("background-color:#FFAE42;");
    checkfiltromaggiorenne->setStyleSheet("background-color:#FFAE42;");
    checkfiltrostudente->setStyleSheet("background-color:#FFAE42;");
    checkVip->setStyleSheet("background-color:#3cb043;");
    checkfiltrocorsopiscina->setStyleSheet("background-color:#FFAE42;");
    checkfiltroschedapalestra->setStyleSheet("background-color:#FFAE42;");

}


void mainwindow::coloriFiltroStudente()
{
    palestraCheckFiltro->setStyleSheet("background-color:#FFAE42;");
    piscinaCheckFiltro->setStyleSheet("background-color:#FFAE42;");
    checkfiltrominorenne->setStyleSheet("background-color:#FFAE42;");
    checkfiltromaggiorenne->setStyleSheet("background-color:#FFAE42;");
    checkfiltrostudente->setStyleSheet("background-color:#3cb043;");
    checkVip->setStyleSheet("background-color:#FFAE42;");
    checkfiltrocorsopiscina->setStyleSheet("background-color:#FFAE42;");
    checkfiltroschedapalestra->setStyleSheet("background-color:#FFAE42;");

}


void mainwindow::coloriFiltroMinorenne()
{
    palestraCheckFiltro->setStyleSheet("background-color:#FFAE42;");
    piscinaCheckFiltro->setStyleSheet("background-color:#FFAE42;");
    checkfiltrominorenne->setStyleSheet("background-color:#3cb043;");
    checkfiltromaggiorenne->setStyleSheet("background-color:#FFAE42;");
    checkfiltrostudente->setStyleSheet("background-color:#FFAE42;");
    checkVip->setStyleSheet("background-color:#FFAE42;");
    checkfiltrocorsopiscina->setStyleSheet("background-color:#FFAE42;");
    checkfiltroschedapalestra->setStyleSheet("background-color:#FFAE42;");

}


void mainwindow::coloriFiltroMaggiorenne()
{
    palestraCheckFiltro->setStyleSheet("background-color:#FFAE42;");
    piscinaCheckFiltro->setStyleSheet("background-color:#FFAE42;");
    checkfiltrominorenne->setStyleSheet("background-color:#FFAE42;");
    checkfiltromaggiorenne->setStyleSheet("background-color:#3cb043;");
    checkfiltrostudente->setStyleSheet("background-color:#FFAE42;");
    checkVip->setStyleSheet("background-color:#FFAE42;");
    checkfiltrocorsopiscina->setStyleSheet("background-color:#FFAE42;");
    checkfiltroschedapalestra->setStyleSheet("background-color:#FFAE42;");

}



