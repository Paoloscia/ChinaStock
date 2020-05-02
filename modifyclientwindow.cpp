#include "modifyclientwindow.h"

modifyClientWindow::modifyClientWindow(QWidget *parent):addClientWindow(parent){setMinimumSize(200,200);}

void modifyClientWindow::caricaDati(const QStringList e, const unsigned int i){
    ind = i;

    QString dot= "\\.";
    QRegExp findDot(dot);

    abbonamentoPiscinaCheckbox->setChecked(e.at(17)=="true"? true : false);
    if (abbonamentoPiscinaCheckbox->isChecked()==true)
    {
        piscinaGroup->setVisible(true);
        dateScadPiscina->setDate(QDate::fromString(e.at(11)));
        nomeIstruttorePiscinaEdit->setText(e.at(12));
        corsoNuotoCheckbox->setChecked(e.at(13)=="true"? true : false);
    }
    else
        piscinaGroup->setVisible(false);

    abbonamentoPalestraCheckbox->setChecked(e.at(18)=="true"? true : false);
    if (abbonamentoPalestraCheckbox->isChecked()==true)
    {
        palestraGroup->setVisible(true);
        dateScadPalestra->setDate(QDate::fromString(e.at(14)));
        nomeIstruttorePalestraEdit->setText(e.at(15));
        schedaPalestraCheckbox->setChecked(e.at(16)=="true"? true : false);
    }
    else
        palestraGroup->setVisible(false);

    nomeLineEdit->setText(e.at(0));
    cognomeLineEdit->setText(e.at(1));
    codFiscLineEdit->setText(e.at(2));
    ldnLineEdit->setText(e.at(3));
    residenzaLineEdit->setText(e.at(4));
    viaLineEdit->setText(e.at(5));
    numeroviaLineEdit->setText(e.at(6));
    telefonoLineEdit->setText(e.at(7));
    mailLineEdit->setText(e.at(8));
    dateNascita->setDate(QDate::fromString(e.at(9)));
    studenteCheckbox->setChecked(e.at(10)=="true"? true : false);
}

void modifyClientWindow::confirm(){ //COPIARE IL CONFIRM DA ADD QUANTO è PRONTO E FARE LE MODIFICHE (CAMBIA SOLO UN EMIT)
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
            tmp->push_back(abbonamentoPiscinaCheckbox->isChecked()? "true":"false");    //17
            tmp->push_back(abbonamentoPalestraCheckbox->isChecked()? "true":"false");

            emit rimpiazzaCliente(ind, *tmp); //era replaceItems     DA FARE
            this->close();
        }
    }
