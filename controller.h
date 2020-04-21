#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include "mainwindow.h"
#include "addclientwindow.h"
#include "modifyclientwindow.h"
#include "model.h"


class controller : public QObject
{
    Q_OBJECT
public:
    explicit controller(QObject *parent = nullptr);
    controller(model *mod, mainwindow *vw); //mod = model , vw=view

public slots:
    void openAddView(); //capire se mettere const
    void salvaFile(); //capire se mettere const
    //void openModify() const; da implementare
    //void openSave() const; da implementare

signals:

private:
    mainwindow* view;
    model* m;
    addClientWindow *addClientW;
    modifyClientWindow *ModifyClientW;

};

#endif // CONTROLLER_H
