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
    void openAddView(); //capire se mettere const
    void salvaFile(); //capire se mettere const
    //void openModify() const; da implementare
    //void openSave() const; da implementare
    void resetListaClienti();
    void aggClienteContainer(const QStringList);

signals:

private:
    mainwindow* view;
    addClientWindow *addClientW;
    modifyClientWindow *ModifyClientW;
    model* m;
    QMap<unsigned int,unsigned int> indexTranslate;

};

#endif // CONTROLLER_H
