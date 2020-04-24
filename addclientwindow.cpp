#include "addclientwindow.h"

addClientWindow::addClientWindow(QWidget *parent) : QDialog(parent) //messo qdialog
{

    mainLayout = new QVBoxLayout(this);
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
    dateNascita = (new QDateEdit(QDate::currentDate(),this));
    dateNascita->setCalendarPopup(true);


    studenteCheckbox = new QCheckBox("Studente",this);
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
    salvaButton = new QPushButton("Salva",this);
    annullaButton = new QPushButton("Annulla",this);

    hdestraBottoni = new QHBoxLayout();
    verticalDxLayout->addLayout(hdestraBottoni);
    hdestraBottoni->addWidget(salvaButton);
    hdestraBottoni->addWidget(annullaButton);

    //************** PARTE CONNECT **************************

    connect(annullaButton, SIGNAL(clicked()), this, SLOT(close()));
    connect(salvaButton, SIGNAL(clicked()), this, SLOT(confirm()));

}

void addClientWindow::confirm()
{
    QStringList *tmp = new QStringList();
    tmp->push_back(nomeLineEdit->text());
    tmp->push_back(cognomeLineEdit->text());
    tmp->push_back(codFiscLineEdit->text());
    tmp->push_back(ldnLineEdit->text());
    tmp->push_back(residenzaLineEdit->text());
    tmp->push_back(viaLineEdit->text());
    tmp->push_back(telefonoLineEdit->text());
    tmp->push_back(mailLineEdit->text());
    tmp->push_back(dateNascita->date().toString());
    tmp->push_back(studenteCheckbox->isChecked()? "true":"false");
    tmp->push_back(dateScadPiscina->date().toString());
    tmp->push_back(nomeIstruttorePiscinaEdit->text());
    tmp->push_back(corsoNuotoCheckbox->isChecked()? "true":"false");
    tmp->push_back(dateScadPalestra->date().toString());
    tmp->push_back(nomeIstruttorePalestraEdit->text());
    tmp->push_back(schedaPalestraCheckbox->isChecked()? "true":"false");
    //emit inputError(); capire come controllare se ci sono errori di input
    emit inviaStringaCliente(*tmp); //era sendItemsDetails
    this->close();
    //QDialog::accept();
    //emit finished(); capire come fare a salvare dati!
}
