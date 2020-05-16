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
class info : public QDialog
{
    Q_OBJECT
public:
   info(QWidget *parent =nullptr);
protected:
    QHBoxLayout* mainLayout;
    QVBoxLayout *v1, *v2;
    QHBoxLayout *ImageLayout1, *ImageLayout2, *ImageLayout3;
};

#endif // INFO_H
