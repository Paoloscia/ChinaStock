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
public slots:
    void openAddView();
signals:

private:
    mainwindow* view;
    model* m;
    addClientWindow *addClientW;
    modifyClientWindow *ModifyClientW;

};

#endif // CONTROLLER_H
