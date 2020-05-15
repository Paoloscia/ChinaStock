#include "addclientwindow.h"
addClientWindow::addClientWindow(QWidget *parent) : QDialog(parent),abbonamentoPiscinaCheckbox(new QCheckBox("Abbonato a piscina",this)),abbonamentoPalestraCheckbox(new QCheckBox("Abbonato a palestra",this)),piscinaGroup (new QGroupBox("Piscina",this)),palestraGroup (new QGroupBox("Palestra",this))
{
    setMinimumSize(700,400);
    setWindowTitle("Finestra aggiunta clienti");
    mainLayout = new QHBoxLayout(this);

    setLayout(mainLayout);

    QLabel *nomeLabel = new QLabel(tr("Nome(*): "));
    nomeLineEdit = new QLineEdit();
    nomeLineEdit->setPlaceholderText("es. Carlo");
    //nomeLabel->setBuddy(nomeLineEdit); capire se sarebbe non necessario perchè teoricamente inserendo addrow con label e line edit viene assegnato come buddy

    QLabel *cognomeLabel = new QLabel(tr("Cognome(*): "));
    cognomeLineEdit = new QLineEdit();
    cognomeLineEdit->setPlaceholderText("es. Rossi");

    QLabel *codFiscLabel = new QLabel(tr("Codice Fiscale(*): "));
    codFiscLineEdit = new QLineEdit();
    codFiscLineEdit->setValidator(new QRegExpValidator(QRegExp("[A-Z0-9]{0,20}")));
    codFiscLineEdit->setPlaceholderText("es. PDYGZF45B63M297E");

    QLabel *ldnLabel = new QLabel(tr("Luogo di nascita: "));
    ldnLineEdit = new QLineEdit();
    ldnLineEdit->setPlaceholderText("es. Padova");

    QLabel *residenzaLabel = new QLabel(tr("Residenza: "));
    residenzaLineEdit = new QLineEdit();
    residenzaLineEdit->setPlaceholderText("es. Villafranca");

    QLabel *viaLabel = new QLabel(tr("Via: "));
    viaLineEdit = new QLineEdit();
    viaLineEdit->setPlaceholderText("es. via Giusti");

    QLabel *numeroLabel = new QLabel(tr("Numero Via:"));
    numeroviaLineEdit = new QLineEdit();
    numeroviaLineEdit->setValidator(new QRegExpValidator(QRegExp("[0-9]{1,3}[/]{1}[a-z]{1}")));
    numeroviaLineEdit->setPlaceholderText("es. 112/b");

    QLabel *telefonoLabel = new QLabel(tr("Telefono: ")); 
    telefonoLineEdit = new QLineEdit();
    telefonoLineEdit->setValidator(new QRegExpValidator(QRegExp("[+]{1}[0-9]{0,3}[0-9]{15}")));
    telefonoLineEdit->setPlaceholderText("es. +393481232567");

    QLabel *mailLabel = new QLabel(tr("Mail: "));
    mailLineEdit = new QLineEdit();
    mailLineEdit->setPlaceholderText("es. carlorossi@gmail.com");

    QLabel *dateNascitaLabel = new QLabel("Data di nascita: ");
    dateNascita = (new QDateEdit(QDate::currentDate(),this));
    dateNascita->setCalendarPopup(true);

    studenteCheckbox = new QCheckBox("Studente",this);

    //************** PEZZO FORM PISCINA ********************
    QFormLayout *formPiscinaLayout = new QFormLayout();

    QLabel *dateScadPiscinaLabel = new QLabel("Data: ");
    dateScadPiscina = (new QDateEdit(QDate::currentDate(),this));
    dateScadPiscina->setCalendarPopup(true);
    QLabel *nomeIstruttorePiscinaLabel = new QLabel(tr("Nome istruttore: "));
    nomeIstruttorePiscinaEdit = new QLineEdit();
    nomeIstruttorePiscinaEdit->setPlaceholderText("es. Lisa Dotti");
    corsoNuotoCheckbox = new QCheckBox("Corso nuoto",this);

    formPiscinaLayout->addRow(dateScadPiscinaLabel,dateScadPiscina);
    formPiscinaLayout->addRow(nomeIstruttorePiscinaLabel,nomeIstruttorePiscinaEdit);
    formPiscinaLayout->addRow(corsoNuotoCheckbox);
    piscinaGroup->setLayout(formPiscinaLayout);

    //************** PEZZO FORM PALESTRA ********************
    QFormLayout *formPalestraLayout = new QFormLayout();

    QLabel *dateScadPalestraLabel = new QLabel("Data: ");
    dateScadPalestra = (new QDateEdit(QDate::currentDate(),this));
    dateScadPalestra->setCalendarPopup(true);
    QLabel *nomeIstruttorePalestraLabel = new QLabel(tr("Nome istruttore: "));
    nomeIstruttorePalestraEdit = new QLineEdit();
    nomeIstruttorePalestraEdit->setPlaceholderText("es. Giulia Lucchi");
    schedaPalestraCheckbox = new QCheckBox("Scheda palestra",this);

    formPalestraLayout->addRow(dateScadPalestraLabel,dateScadPalestra);
    formPalestraLayout->addRow(nomeIstruttorePalestraLabel,nomeIstruttorePalestraEdit);
    formPalestraLayout->addRow(schedaPalestraCheckbox);
    palestraGroup->setLayout(formPalestraLayout);
    nomeLineEdit->setFixedWidth(280);
    cognomeLineEdit->setFixedWidth(280);
    codFiscLineEdit->setFixedWidth(280);
    ldnLineEdit->setFixedWidth(280);
    residenzaLineEdit->setFixedWidth(280);
    viaLineEdit->setFixedWidth(280);
    numeroviaLineEdit->setFixedWidth(280);
    telefonoLineEdit->setFixedWidth(280);
    mailLineEdit->setFixedWidth(280);
    dateNascita->setFixedWidth(280);

    QFormLayout *formLayout = new QFormLayout();
    formLayout->setFormAlignment(Qt::AlignLeft);
    formLayout->addRow(nomeLabel, nomeLineEdit);
    formLayout->addRow(cognomeLabel, cognomeLineEdit);
    formLayout->addRow(codFiscLabel, codFiscLineEdit);
    formLayout->addRow(ldnLabel, ldnLineEdit);
    formLayout->addRow(residenzaLabel, residenzaLineEdit);
    formLayout->addRow(viaLabel, viaLineEdit);
    formLayout->addRow(numeroLabel, numeroviaLineEdit);
    formLayout->addRow(telefonoLabel, telefonoLineEdit);
    formLayout->addRow(mailLabel, mailLineEdit);
    formLayout->addRow(dateNascitaLabel, dateNascita);
    formLayout->addRow(studenteCheckbox);
    formLayout->addRow(abbonamentoPiscinaCheckbox);
    formLayout->addRow(abbonamentoPalestraCheckbox);

    mainLayout->addLayout(formLayout);
    verticalDxLayout = new QVBoxLayout();
    mainLayout->addLayout(verticalDxLayout);

    verticalDxLayout->addWidget(piscinaGroup);
    verticalDxLayout->addWidget(palestraGroup);
    salvaButton = new QPushButton("Salva",this);
    annullaButton = new QPushButton("Annulla",this);
    salvaButton->setFixedWidth(70);
    annullaButton->setFixedWidth(70);


    hdestraBottoni = new QHBoxLayout();
    hdestraBottoni->setAlignment(Qt::AlignBottom | Qt::AlignRight);
    verticalDxLayout->addLayout(hdestraBottoni);
    hdestraBottoni->addWidget(salvaButton);
    hdestraBottoni->addWidget(annullaButton);

    piscinaGroup->setVisible(false);
    palestraGroup->setVisible(false);

    //************** PARTE CONNECT **************************

    connect(annullaButton, SIGNAL(clicked()), this, SLOT(close()));
    connect(salvaButton, SIGNAL(clicked()), this, SLOT(confirm()));
    connect(abbonamentoPiscinaCheckbox,SIGNAL(clicked()), this, SLOT(mostraPiscina()));
    connect(abbonamentoPalestraCheckbox,SIGNAL(clicked()), this, SLOT(mostraPalestra()));

}

void addClientWindow::mostraErroreInput(string motivo)
{
    QMessageBox erroreInputBox;
    if (motivo== "mancaLineEdit")
        erroreInputBox.critical(this,"Errore di inputazione","Compilare i campi obbligatori (*) per poter procedere");
    else if (motivo =="mancaCheckBox")
        erroreInputBox.critical(this,"Errore di inputazione","selezionare almeno uno degli abbonamenti tra piscina e palestra per poter procedere");

    //erroreInputBox.setMinimumSize(600,600); non prende setminimumsize capire perchè quando si sistemerà graficamente codice
}

void addClientWindow::clienteAggiunto()
{
    QMessageBox clienteAggiuntoBox;
    clienteAggiuntoBox.information(this,"Cliente aggiunto","Il cliente è stato aggiunto con successo!");
}

void addClientWindow::confirm()
{
    if (nomeLineEdit->text()=="" || cognomeLineEdit->text()=="" || codFiscLineEdit->text()==""){
        emit erroreInput("mancaLineEdit");
    }
    else if (!abbonamentoPiscinaCheckbox->isChecked() && !abbonamentoPalestraCheckbox->isChecked()) {
        emit erroreInput("mancaCheckBox");
    }
    else
    {
        QStringList *tmp = new QStringList();
        tmp->push_back(nomeLineEdit->text());
        tmp->push_back(cognomeLineEdit->text());
        tmp->push_back(codFiscLineEdit->text());
        tmp->push_back(ldnLineEdit->text());
        tmp->push_back(residenzaLineEdit->text());
        tmp->push_back(viaLineEdit->text());
        tmp->push_back(numeroviaLineEdit->text());
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
        tmp->push_back(abbonamentoPiscinaCheckbox->isChecked()? "true":"false");
        tmp->push_back(abbonamentoPalestraCheckbox->isChecked()? "true":"false");

        emit inviaStringaCliente(*tmp); //era sendItemsDetails
        this->close();
        clienteAggiunto();
        //QDialog::accept(); capire se servono queste due righe commentate
        //emit finished();
    }
}

void addClientWindow::mostraPiscina()
{
    if (abbonamentoPiscinaCheckbox->isChecked()==true)
        piscinaGroup->setVisible(true);
    else
        piscinaGroup->setVisible(false);

}

void addClientWindow::mostraPalestra()
{
    if (abbonamentoPalestraCheckbox->isChecked()==true)
        palestraGroup->setVisible(true);
    else
        palestraGroup->setVisible(false);
}

//la prima volta che entra fa una pulizia inutile visto che sono già tutti vuoti
void addClientWindow::pulisciRighe()
{
    nomeLineEdit->setText("");
    cognomeLineEdit->setText("");
    codFiscLineEdit->setText("");
    ldnLineEdit->setText("");
    residenzaLineEdit->setText("");
    viaLineEdit->setText("");
    numeroviaLineEdit->setText("");
    telefonoLineEdit->setText("");
    mailLineEdit->setText("");
    dateNascita->setDate(QDate::currentDate());
    studenteCheckbox->setChecked(false);
    dateScadPiscina->setDate(QDate::currentDate());
    nomeIstruttorePiscinaEdit->setText("");
    corsoNuotoCheckbox->setChecked(false);
    dateScadPalestra->setDate(QDate::currentDate());
    nomeIstruttorePalestraEdit->setText("");
    schedaPalestraCheckbox->setChecked(false);
    abbonamentoPiscinaCheckbox->setChecked(false);
    abbonamentoPalestraCheckbox->setChecked(false);
    piscinaGroup->setVisible(false);
    palestraGroup->setVisible(false);
}
