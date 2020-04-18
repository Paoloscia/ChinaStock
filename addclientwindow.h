#ifndef ADDCLIENTWINDOW_H
#define ADDCLIENTWINDOW_H

#include <QWidget>
#include<QGridLayout>
#include<QMenuBar>
#include<QVBoxLayout>
#include<QGridLayout>
#include<QCheckBox>
#include<QGroupBox>
#include<QHBoxLayout>
#include<QLabel>
#include <QFormLayout>
#include <QLineEdit>
#include <QDateEdit>
#include <QDate>
#include <QGroupBox>
#include <QPushButton>
#include <QFile>

class addClientWindow : public QWidget
{
    Q_OBJECT
public:
    addClientWindow(QWidget *parent =nullptr);
    //~addClientWindow(); DA FARE!!!
private:
    QVBoxLayout* mainLayout;
    QGridLayout* gridLayout;
    QVBoxLayout* verticalDxLayout, *verticalSxLayout;
    QHBoxLayout *oriz,* divH, *hLeftBottoni, *orizDxLayout, *hdestraBottoni, *orizSxLayout;
    QCheckBox* studenteCheckbox, *studente2Checkbox, *corsoNuotoCheckbox, *schedaPalestraCheckbox;
    QLineEdit* nomeLineEdit, *nomeIstruttorePiscinaEdit, *nomeIstruttorePalestraEdit,* cognomeLineEdit,*codFiscLineEdit,*ldnLineEdit,*residenzaLineEdit,*viaLineEdit,*telefonoLineEdit,*mailLineEdit;
    QCheckBox* All,*palestra,*piscina,*minorenne,*maggiorenne,*deseleziona;
    QLineEdit* lineCerca;
    QPushButton* Cerca;
    QPushButton* salvaButton, *annullaButton;
};

#endif // ADDCLIENTWINDOW_H
