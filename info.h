#ifndef INFO_H
#define INFO_H

#include <QDialog>
#include<QVBoxLayout>
#include<QGroupBox>
#include<QVBoxLayout>
#include<QLabel>
#include <QFormLayout>
#include <QWidget>

using std::string;
class info : public QDialog
{
    Q_OBJECT
public:
   info(QWidget *parent =nullptr);
protected:
    QHBoxLayout* mainLayout;
    QFormLayout* formLayout, *formLayout2, *formLayout3;
    QVBoxLayout *v1, *v2;
    QHBoxLayout *ImageLayout1, *ImageLayout2, *ImageLayout3;
    QGroupBox *Elia, *Amedeo, *Paolo;
};

#endif // INFO_H
