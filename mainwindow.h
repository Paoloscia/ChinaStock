#ifndef GUI_H
#define GUI_H
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
#include "viewlistaclienti.h"

class mainwindow : public QWidget
{
    Q_OBJECT

public:
    mainwindow(QWidget *parent =nullptr);
    //~mainwindow();
    void mostraClienti(const QStringList); //era displayCatalog

private:
    //controllare quali non si usano!!!!
    QVBoxLayout* mainLayout;
    QGridLayout* gridLayout;
    QVBoxLayout* verticalDxLayout, *verticalSxLayout;
    QHBoxLayout* divH, *hLeftBottoni;
    QCheckBox* studenteCheckbox, *corsoNuotoCheckbox, *schedaPalestraCheckbox;
    QLineEdit* nomeLineEdit, *nomeIstruttorePiscinaEdit, *nomeIstruttorePalestraEdit,* cognomeLineEdit,*codFiscLineEdit,*ldnLineEdit,*residenzaLineEdit,*viaLineEdit,*telefonoLineEdit,*mailLineEdit;
    QCheckBox* All,*palestra,*piscina,*minorenne,*maggiorenne,*deseleziona;
    QLineEdit* lineCerca;
    QDateEdit* dateNascita,*dateScadPiscina,*dateScadPalestra;
    QPushButton* Cerca;
    QPushButton* addButton,*modButton,*removeButton;
    viewListaClienti *listaClienti;
    void setMainWindowStyle();
    //void handleSearchClick(); da implementare


signals:
    void signOpenAddWindow();
    void salvaFileMenu();
    //void clickedSearch(QString searchText); da implementare search

};

#endif // GUI_H
