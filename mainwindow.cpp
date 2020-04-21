#include "mainwindow.h"


mainwindow::mainwindow(QWidget *parent) : QWidget(parent)
{
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
    orizDxLayout = new QHBoxLayout();
    verticalSxLayout = new QVBoxLayout();
    verticalDxLayout = new QVBoxLayout();
    divH = new QHBoxLayout();

    mainLayout->addLayout(gridLayout);
    mainLayout->addLayout(divH);
    divH->addLayout(verticalSxLayout);
    divH->addLayout(orizDxLayout);

    setLayout(mainLayout);

    //************** FILTRI ********************

    All = new QCheckBox("All",this);
    palestra = new QCheckBox("Palestra",this);
    piscina = new QCheckBox("Piscina",this);
    minorenne = new QCheckBox("Minorenne",this);
    maggiorenne = new QCheckBox("Maggiorenne",this);
    deseleziona = new QCheckBox("Deseleziona Tutto",this);
    lineCerca = new QLineEdit(this);
    Cerca = new QPushButton("Cerca", this);

    gridLayout->addWidget(All,0,0);
    gridLayout->addWidget(palestra,1,0);
    gridLayout->addWidget(piscina,2,0);
    gridLayout->addWidget(minorenne,0,1);
    gridLayout->addWidget(maggiorenne,1,1);
    gridLayout->addWidget(deseleziona,2,1);
    gridLayout->addWidget(lineCerca,2,2);
    gridLayout->addWidget(Cerca,2,3);

    //************** CLIENTI ********************

    QGroupBox *clientiGroup = new QGroupBox("Clienti");
    viewListaClienti* elementi(new viewListaClienti(this));
    elementi->setSelectionMode(QAbstractItemView::SingleSelection);
    QVBoxLayout *layoutListaClienti = new QVBoxLayout();
    layoutListaClienti->addWidget(elementi);
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
    nomeLineEdit = new QLineEdit();
    //nomeLabel->setBuddy(nomeLineEdit); capire se sarebbe non necessario perchè teoricamente inserendo addrow con label e line edit viene assegnato come buddy

    QLabel *cognomeLabel = new QLabel(tr("Cognome: "));
    cognomeLineEdit = new QLineEdit();
    //cognomeLabel->setBuddy(cognomeLineEdit);

    QLabel *codFiscLabel = new QLabel(tr("Codice Fiscale: "));
    codFiscLineEdit = new QLineEdit();
    //codFiscLabel->setBuddy(codFiscLineEdit);

    QLabel *ldnLabel = new QLabel(tr("Luogo di nascita: "));
    ldnLineEdit = new QLineEdit();
    //ldnLabel->setBuddy(ldnLineEdit);

    QLabel *residenzaLabel = new QLabel(tr("Residenza: "));
    residenzaLineEdit = new QLineEdit();
    //residenzaLabel->setBuddy(residenzaLineEdit);

    QLabel *viaLabel = new QLabel(tr("Via: "));
    viaLineEdit = new QLineEdit();
    //viaLabel->setBuddy(viaLineEdit);

    QLabel *telefonoLabel = new QLabel(tr("Telefono: "));
    telefonoLineEdit = new QLineEdit();
    //telefonoLabel->setBuddy(telefonoLineEdit);

    QLabel *mailLabel = new QLabel(tr("Mail: "));
    mailLineEdit = new QLineEdit();
    //mailLabel->setBuddy(mailLineEdit);

    QLabel *dateNascitaLabel = new QLabel("Data di nascita: ");
    QDateEdit* dateNascita(new QDateEdit(QDate::currentDate(),this));
    dateNascita->setCalendarPopup(true);


    studenteCheckbox = new QCheckBox("Studente",this);

    //************** PEZZO FORM PISCINA ********************

    QGroupBox *piscinaGroup = new QGroupBox("Piscina");
    QFormLayout *formPiscinaLayout = new QFormLayout();

    QLabel *dateScadPiscinaLabel = new QLabel("Data: ");
    QDateEdit* dateScadPiscina(new QDateEdit(QDate::currentDate(),this));
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
    QDateEdit* dateScadPalestra(new QDateEdit(QDate::currentDate(),this));
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
    formLayout->addRow(nomeLabel, nomeLineEdit);
    formLayout->addRow(cognomeLabel, cognomeLineEdit);
    formLayout->addRow(codFiscLabel, codFiscLineEdit);
    formLayout->addRow(ldnLabel, ldnLineEdit);
    formLayout->addRow(residenzaLabel, residenzaLineEdit);
    formLayout->addRow(viaLabel, viaLineEdit);
    formLayout->addRow(telefonoLabel, telefonoLineEdit);
    formLayout->addRow(mailLabel, mailLineEdit);
    formLayout->addRow(dateNascitaLabel, dateNascita);
    formLayout->addRow(studenteCheckbox);

    orizDxLayout->addLayout(formLayout);
    orizDxLayout->addLayout(verticalDxLayout);
    verticalDxLayout->addWidget(piscinaGroup);
    verticalDxLayout->addWidget(palestraGroup);

    //************** PARTE CONNECT **************************


    connect(addButton, SIGNAL(clicked()), this, SIGNAL(signOpenAddWindow()));
    connect(salva, SIGNAL(triggered()), this, SIGNAL(salvaFileMenu()));

    //connect(Cerca, SIGNAL(clicked()), this, SLOT(handleSearchClick())); da implementare

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




