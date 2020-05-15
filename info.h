#ifndef INFO_H
#define INFO_H

#include <QDialog>
#include<QMenuBar>
#include<QVBoxLayout>
#include<QCheckBox>
#include<QGroupBox>
#include<QVBoxLayout>
#include<QLabel>
#include <QFormLayout>
#include <QGroupBox>
#include <QPushButton>
#include <iostream>
#include <QWidget>

using std::string;
class info : public QDialog //inserito qdialog al posto di qwidget
{
    Q_OBJECT
public:
   info(QWidget *parent =nullptr);
    //~addClientWindow(); DA FARE!!!
protected:
    QHBoxLayout* mainLayout;
    QVBoxLayout *v1, *v2, *v3;
    QHBoxLayout *o1, *o2, *o3;
    //QGroupBox* piscinaGroup,* palestraGroup;
};

#endif // INFO_H
