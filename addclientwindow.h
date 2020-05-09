#ifndef ADDCLIENTWINDOW_H
#define ADDCLIENTWINDOW_H

//#include <QWidget> commentato perchè ho messo public QDialog, guardare assieme
#include <QDialog>
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
#include <QStringList>
#include <iostream>
#include<QMessageBox>
using std::string;
class addClientWindow : public QDialog //inserito qdialog al posto di qwidget
{
    Q_OBJECT
public:
    addClientWindow(QWidget *parent =nullptr);
    //~addClientWindow(); DA FARE!!!
    void mostraErroreInput(string);
public slots:
    virtual void confirm();
    void mostraPiscina();
    void mostraPalestra();
    void pulisciRighe();
signals:
    void inviaStringaCliente(const QStringList);
    void erroreInput(string);
protected:
    //controllare quali non si usano!!!!
    QHBoxLayout* mainLayout;
    QGridLayout* gridLayout;
    QVBoxLayout* verticalDxLayout;
    QHBoxLayout *oriz, *hdestraBottoni;
    QCheckBox* studenteCheckbox, *studente2Checkbox, *corsoNuotoCheckbox, *schedaPalestraCheckbox;
    QLineEdit* nomeLineEdit,* cognomeLineEdit,*codFiscLineEdit,*ldnLineEdit,*residenzaLineEdit,*viaLineEdit,*numeroviaLineEdit,*telefonoLineEdit,*mailLineEdit, *nomeIstruttorePiscinaEdit, *nomeIstruttorePalestraEdit;
    QCheckBox* abbonamentoPiscinaCheckbox, *abbonamentoPalestraCheckbox;
    QLineEdit* lineCerca;
    QDateEdit* dateNascita,*dateScadPiscina,*dateScadPalestra;
    QPushButton* Cerca;
    QPushButton* salvaButton,*annullaButton;
    QGroupBox* piscinaGroup,* palestraGroup;
};

#endif // ADDCLIENTWINDOW_H
