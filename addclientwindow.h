#ifndef ADDCLIENTWINDOW_H
#define ADDCLIENTWINDOW_H

#include <QDialog>
#include<QGridLayout>
#include<QVBoxLayout>
#include<QCheckBox>
#include<QGroupBox>
#include<QHBoxLayout>
#include<QLabel>
#include <QFormLayout>
#include <QLineEdit>
#include <QDateEdit>
#include <QDate>
#include <QPushButton>
#include <QStringList>
#include<QMessageBox>
using std::string;

class addClientWindow : public QDialog
{
    Q_OBJECT
public:
    addClientWindow(QWidget *parent =nullptr);
    void mostraErroreInput(string);
    void clienteAggiunto();
    void mostraErroreData();
public slots:
    virtual void confirm();
    void mostraPiscina();
    void mostraPalestra();
    void pulisciRighe();
signals:
    void inviaStringaCliente(const QStringList);
    void erroreInput(string);
    void erroreDatax();
protected:
    QVBoxLayout* verticalDxLayout;
    QHBoxLayout* mainLayout, *hdestraBottoni;
    QCheckBox* studenteCheckbox, *studente2Checkbox, *corsoNuotoCheckbox, *schedaPalestraCheckbox, *abbonamentoPiscinaCheckbox, *abbonamentoPalestraCheckbox;
    QLineEdit* nomeLineEdit,* cognomeLineEdit,*codFiscLineEdit,*ldnLineEdit,*residenzaLineEdit,*viaLineEdit,*numeroviaLineEdit,*telefonoLineEdit,*mailLineEdit, *nomeIstruttorePiscinaEdit, *nomeIstruttorePalestraEdit;
    QDateEdit* dateNascita,*dateScadPiscina,*dateScadPalestra;
    QPushButton* salvaButton,*annullaButton;
    QGroupBox* piscinaGroup,* palestraGroup;
};

#endif // ADDCLIENTWINDOW_H
