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
    void openAddView();
    void openModify() const;
    void openSave() const;

signals:

private:
    mainwindow* view;
    model* m;
    addClientWindow *addClientW;
    modifyClientWindow *ModifyClientW;

};

#endif // CONTROLLER_H
