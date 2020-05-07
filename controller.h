#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QMessageBox>
#include "mainwindow.h"
#include "addclientwindow.h"
#include "modifyclientwindow.h"
#include "model.h"


class controller : public QObject
{
    Q_OBJECT
public:
    explicit controller(QObject *parent = nullptr);
public slots:
    void openAddView(); //capire se mettere const
    void salvaFile(); //capire se mettere const
    void openModifyView(); //capire se mettere const
    //void openSave() const; da implementare
    void resetListaClienti();
    void resetDettClienteView();
    void aggClienteContainer(const QStringList);
    void erroreInputRicevuto(string);
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

signals:
    void pulisciCampi();
private:
    mainwindow* view;
    addClientWindow *addClientW;
    modifyClientWindow *ModifyClientW;
    model* m;
    QMap<unsigned int,unsigned int> indexTranslate;

};

#endif // CONTROLLER_H
