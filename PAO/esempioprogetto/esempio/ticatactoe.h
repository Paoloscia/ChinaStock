#ifndef TICATACTOE_H
#define TICATACTOE_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class TicaTacToe; }
QT_END_NAMESPACE

class TicaTacToe : public QWidget
{
    Q_OBJECT

public:
    TicaTacToe(QWidget *parent = nullptr);
    ~TicaTacToe();

private:
    Ui::TicaTacToe *ui;
};
#endif // TICATACTOE_H
