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

class mainwindow : public QWidget
{
    Q_OBJECT

public:
    mainwindow(QWidget *parent =nullptr);
    //~mainwindow();

private:

    QVBoxLayout* mainLayout;
    QVBoxLayout* verticalDxLayout, *verticalSxLayout;
    QGridLayout* gridLayout;
    QHBoxLayout* divH, *hLeftBottoni;
    QVBoxLayout* Layoutsinistra;
    QCheckBox* studenteCheckbox, *corsoNuotoCheckbox, *schedaPalestraCheckbox;
    QLineEdit* nomeLineEdit, *nomeIstruttorePiscinaEdit, *nomeIstruttorePalestraEdit,* cognomeLineEdit,*codFiscLineEdit,*ldnLineEdit,*residenzaLineEdit,*viaLineEdit,*telefonoLineEdit,*mailLineEdit;
    QCheckBox* All,*palestra,*piscina,*minorenne,*maggiorenne,*deseleziona;
    QPushButton* AggCliente;//era AddClient
    QLineEdit* lineCerca;//era search
    QPushButton* Cerca;
    void addMenu();
};

#endif // GUI_H
