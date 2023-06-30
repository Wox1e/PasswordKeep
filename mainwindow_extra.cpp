#include "mainwindow_extra.h"
#include "ui_mainwindow_extra.h"

mainwindow_extra::mainwindow_extra(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::mainwindow_extra)
{
    ui->setupUi(this);



}

mainwindow_extra::~mainwindow_extra()
{
    delete ui;
}

void mainwindow_extra::on_pushButton_clicked()
{
    //debug

    for(auto el:ListOfPair){
        qDebug() << "first = " << el.first;
        qDebug() << "second = " << el.second;
    }
    //



}

