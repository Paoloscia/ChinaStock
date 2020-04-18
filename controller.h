#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include "mainwindow.h"
#include "model.h"
#include "addclientwindow.h"
#include "modifyclientwindow.h"

class controller : public QObject
{
    Q_OBJECT
public:
    explicit controller(QObject *parent = nullptr);
signals:

private:
    mainwindow* view;
    model* m;
    addClientWindow *addClientW;
    modifyClientWindow *ModifyClientW;

public slots:
    //void apriAggiungi() const;
};

#endif // CONTROLLER_H
