#include "ticatactoe.h"
#include "ui_ticatactoe.h"

TicaTacToe::TicaTacToe(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TicaTacToe)
{
    ui->setupUi(this);
}

TicaTacToe::~TicaTacToe()
{
    delete ui;
}

