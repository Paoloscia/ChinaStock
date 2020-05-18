#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QMessageBox>
#include <iostream>
#include<fstream>
#include <QPdfWriter>
#include <QPainter>
#include <QFileDialog>
#include "mainwindow.h"
#include "addclientwindow.h"
#include "modifyclientwindow.h"
#include "model.h"
#include "info.h"
using std::ofstream;
using std::endl;

class controller : public QObject
{
    Q_OBJECT

public:
    explicit controller(QObject *parent = nullptr);
    ~controller();
public slots:
    void openInfoWindow()const;
    void openAddView()const;
    void salvaFile();
    void openModifyView() const;
    void resetListaClienti();
    void resetDettClienteView() const;
    void aggClienteContainer(const QStringList);
    void erroreInputRicevuto(string);
    void erroreDataRicevuto();
    void rimuoviCliente(const unsigned int);
    void rimpiazzaItem(const unsigned int,const QStringList);
    void mostraCliente(const unsigned int);
    void salvaIfModificato();
    void filtraClientiPiscina();
    void filtraTuttiClienti();
    void filtraClientiPalestra();
    void filtraClientiMaggiorenni();
    void filtraClientiMinorenni();
    void filtraClientiStudenti();
    void filtraClientiVip();
    void filtraClientiIstruttoriPiscina();
    void filtraClientiIStruttoriPalestra();
    void resetColoreFiltroC() const;
    void stampaPDFCliente(const unsigned int) const;
    void esportaCsvClienti() const;
    void clienteRimossoShowBox();
    void esportaPDFClienti() const;

private:
    mainwindow* view;
    addClientWindow *addClientW;
    info *infoProgetto;
    modifyClientWindow *ModifyClientW;
    model* m;
    QMap<unsigned int,unsigned int> indexTranslate;
};

#endif // CONTROLLER_H
