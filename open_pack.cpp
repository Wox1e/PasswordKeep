#include "open_pack.h"
#include "ui_open_pack.h"
#include <QFile>
#include <QMessageBox>
#include <mainwindow.h>
#include <SHA256.h>
#pragma once


auto SHA256_encr(QString data)

{
    SHA256 sh;
    sh.update(data.toStdString());
    auto outdata = SHA256::toString(sh.digest()).erase(0,33);
    return outdata;

}


struct element
{
    element() {}
    int id;
    QString login;
    QString password;

};

auto GetHash(QString filename){


        QFile file(filename);
        file.open(QIODevice::ReadOnly);

        return file.readLine();
}


bool isCorrect(QString cp, QString ep){
    return ep == cp;
}






open_pack::open_pack(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::open_pack)
{
    ui->setupUi(this);
}

open_pack::~open_pack()
{
    delete ui;
}


void open_pack::on_pushButton_clicked()
{
    QFile file(filename);





    qDebug()<<"Getting Data Started...";
    qDebug()<<"_____________";
    auto correctHash  = GetHash(this->filename);
    auto userHash = QString::fromStdString(SHA256_encr(ui->lineEdit->text()));

    if(correctHash.size() > 31) correctHash.erase(correctHash.begin() + 31, correctHash.end());


    qDebug() << "userHash = "<< userHash;
    qDebug() << "correctHash = "<< correctHash;

    if(isCorrect(correctHash,userHash)){
            file.open(QIODevice::ReadOnly);
        file.readLine();



    std::vector<std::pair<QString,QString>> tmpList;
    std::pair<QString,QString> tmp;
    qDebug() << "Getting Log&Pass";

while (!file.atEnd())
  {

        qDebug() << "-iteration-";
        auto f_get = file.readLine();
        auto ft = QByteArray::fromBase64(f_get);
        auto ft2 = QByteArray::fromBase64(ft);
        tmp.first = ft2;

        auto f2_get = file.readLine();
        auto ft3 = QByteArray::fromBase64(f2_get);
        auto ft4 = QByteArray::fromBase64(ft3);

        tmp.second = ft4;
        qDebug()<<"login = "<<tmp.first;
        qDebug()<<"password = "<<tmp.second;
        tmpList.push_back(tmp);
  }
qDebug()<<"_____________";

       mainwindow mw;
        mw.cor_Hash = correctHash;
       mw.setWindowTitle("PasswordKeep");
       qDebug()<<"mainwindow created";
       mw.pList = tmpList;
      // mw.tempLw = mw.AddListWidget();
       //mw.password = correctHash;
       mw.filename = filename;
      // for (auto el : tmpList) {
      //    mw.addElement(el,mw.tempLw);
      // }

//Проверить код сверху (получает два логина)


       file.close();






       this->close();
       qDebug()<<"open_pack_window closed";
       this->sw->close();
       qDebug()<<"startwindow closed";

       //qDebug()<<"lw.count = "<<mw.tempLw->count();
      // qDebug()<<"\n";
       qDebug()<<"mw.exec() called";
       mw.exec();

    }






}

