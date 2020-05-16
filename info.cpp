#include "info.h"

info::info(QWidget *parent) : QDialog(parent)
{
    setMinimumSize(800,500);
    setWindowTitle("Informazioni Progetto ");
    mainLayout = new QHBoxLayout(this);
    setLayout(mainLayout);

 /**************ELIA****************************************/
    QGroupBox *Elia = new QGroupBox("");
    QFormLayout *formLayout = new QFormLayout();
    QLabel *nomeElia = new QLabel(tr("Nome : Elia"));
    QLabel *cognomeElia = new QLabel(tr("Cognome : Rech"));
    QLabel *matricolaElia = new QLabel(tr("Matricola : 1123583"));
    QLabel *emailElia = new QLabel(tr("Mail : elia.rech@studenti.unipd.it"));

    QHBoxLayout *ImageLayout = new QHBoxLayout();
    QPixmap*  pix = new QPixmap(":/risorse/utenteinfo.jpg");
    QLabel* image = new QLabel(this);
    image->setAlignment(Qt::AlignRight);
    image->setPixmap(*pix);
    ImageLayout->addWidget(image);
    image->setMaximumWidth(300);
    image->setMaximumHeight(300);

    formLayout->setFormAlignment(Qt::AlignRight);
    formLayout->addRow(nomeElia);
    formLayout->addRow(cognomeElia);
    formLayout->addRow(matricolaElia);
    formLayout->addRow(emailElia);
    Elia->setLayout(formLayout);

    /**************AMEDEO****************************************/
    QGroupBox *Amedeo = new QGroupBox("");
    QFormLayout *formLayout2 = new QFormLayout();
    QLabel *nomeAmedeo = new QLabel(tr("Nome: Amedeo"));
    QLabel *cognomeAmedeo = new QLabel(tr("Cognome: Meggiolaro"));
    QLabel *matricolaAmedeo = new QLabel(tr("Matricola : XXXXXXXX"));
    QLabel *emailAmedeo = new QLabel(tr("Mail : amedeo.meggiolaro@studenti.unipd.it"));

    QHBoxLayout *ImageLayout2 = new QHBoxLayout();
    QPixmap*  pix2 = new QPixmap(":/risorse/utenteinfo.jpg");
    QLabel* image2 = new QLabel(this);
    image2->setAlignment(Qt::AlignRight);
    image2->setPixmap(*pix2);
    ImageLayout2->addWidget(image2);

    image2->setMaximumWidth(300);
    image2->setMaximumHeight(300);

    formLayout2->addRow(nomeAmedeo);
    formLayout2->addRow(cognomeAmedeo);
    formLayout2->addRow(matricolaAmedeo);
    formLayout2->addRow(emailAmedeo);
    Amedeo->setLayout(formLayout2);

    /**************PAOLO****************************************/
    QGroupBox *Paolo = new QGroupBox("");
    QFormLayout *formLayout3 = new QFormLayout();
    QLabel *nomePaolo = new QLabel(tr("Nome: Paolo"));
    QLabel *cognomePaolo = new QLabel(tr("Cognome: Scialpi"));
    QLabel *matricolaPaolo = new QLabel(tr("Matricola : XXXXXXX"));
    QLabel *emailPaolo = new QLabel(tr("Mail : paolo.scialpi@studenti.unipd.it"));

    QHBoxLayout *ImageLayout3 = new QHBoxLayout();
    QPixmap*  pix3 = new QPixmap(":/risorse/utenteinfo.jpg");
    QLabel* image3 = new QLabel(this);
    image3->setAlignment(Qt::AlignRight);
    image3->setPixmap(*pix3);
    ImageLayout3->addWidget(image3);
    image3->setMaximumWidth(300);
    image3->setMaximumHeight(300);

    formLayout3->addRow(nomePaolo);
    formLayout3->addRow(cognomePaolo);
    formLayout3->addRow(matricolaPaolo);
    formLayout3->addRow(emailPaolo);
    Paolo->setLayout(formLayout3);


    v1 = new QVBoxLayout();
    v2 = new QVBoxLayout();
    mainLayout->addLayout(v1);
    mainLayout->addLayout(v2);
    v1->addWidget(Amedeo);
    v1->addWidget(Paolo);
    v1->addWidget(Elia);
    v2->addLayout(ImageLayout);
    v2->addLayout(ImageLayout2);
    v2->addLayout(ImageLayout3);
}
