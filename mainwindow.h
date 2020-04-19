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

private:

    QVBoxLayout* mainLayout;
    QGridLayout* gridLayout;
    QVBoxLayout* verticalDxLayout, *verticalSxLayout;
    QHBoxLayout* divH, *hLeftBottoni, *orizDxLayout;
    QCheckBox* studenteCheckbox, *corsoNuotoCheckbox, *schedaPalestraCheckbox;
    QLineEdit* nomeLineEdit, *nomeIstruttorePiscinaEdit, *nomeIstruttorePalestraEdit,* cognomeLineEdit,*codFiscLineEdit,*ldnLineEdit,*residenzaLineEdit,*viaLineEdit,*telefonoLineEdit,*mailLineEdit;
    QCheckBox* All,*palestra,*piscina,*minorenne,*maggiorenne,*deseleziona;
    QLineEdit* lineCerca;
    QPushButton* Cerca;
    QPushButton* addButton,*modButton,*removeButton;
    viewListaClienti *elementi;
    void setMainWindowStyle();
    void addMenu();

signals:
    void signOpenAddWindow();
};

#endif // GUI_H
