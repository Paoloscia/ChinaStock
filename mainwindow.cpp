#include "mainwindow.h"


mainwindow::mainwindow(QWidget *parent) : QWidget(parent)
{
    mainLayout = new QVBoxLayout(this);
    addMenu();
    gridLayout = new QGridLayout();
    verticalSxLayout = new QVBoxLayout();
    verticalDxLayout = new QVBoxLayout();
    divH = new QHBoxLayout();

    mainLayout->addLayout(gridLayout);
    mainLayout->addLayout(divH);
    divH->addLayout(verticalSxLayout);
    divH->addLayout(verticalDxLayout);

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
   // QFormLayout *formClientiLayout = new QFormLayout();
   // clientiGroup->setLayout(formClientiLayout);
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

    QLabel *dateLabel = new QLabel("Data: ");
    QDateEdit* date(new QDateEdit(QDate::currentDate(),this));

    studenteCheckbox = new QCheckBox("Studente",this);

    //************** PEZZO FORM PISCINA ********************

    QGroupBox *piscinaGroup = new QGroupBox("Piscina");
    QFormLayout *formPiscinaLayout = new QFormLayout();

    QLabel *dateScadPiscinaLabel = new QLabel("Data: ");
    QDateEdit* dateScadPiscina(new QDateEdit(QDate::currentDate(),this));
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
    formLayout->addRow(dateLabel, date);
    formLayout->addRow(studenteCheckbox);

    verticalDxLayout->addLayout(formLayout);
    verticalDxLayout->addWidget(piscinaGroup);
    verticalDxLayout->addWidget(palestraGroup);

}

void mainwindow::addMenu()
{
    //Creare la barra del menu,poi il menu e poi le sue azioni
    QMenuBar* menubar = new QMenuBar(this);
    QMenu* menu= new QMenu("File",menubar);
    QAction* salva = new QAction("Esci",menu);
    QAction* salvaconnome = new QAction("Salva con Nome",menu);
    QAction* exit = new QAction("Salva",menu);


    // Aggiungo le azioni al menu
    menu->addAction(exit);
    menu->addAction(salvaconnome);
    menu->addAction(salva);

    //aggiungo il menu alla barra
    menubar->addMenu(menu);
    // aggiungo la barra del menu
    mainLayout->addWidget(menubar);


}

