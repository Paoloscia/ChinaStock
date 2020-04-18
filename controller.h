#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include "mainwindow.h"
#include "model.h"

class controller : public QObject
{
    Q_OBJECT
public:
    explicit controller(model* model,QObject *parent = nullptr);

signals:

private:
    mainwindow* view;
    model* model;
};

#endif // CONTROLLER_H
