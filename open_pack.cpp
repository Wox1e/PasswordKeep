#include "open_pack.h"
#include "ui_open_pack.h"
#include <QFile>
//#include <deque>
#include <QMessageBox>
#include <mainwindow.h>
//#include "startwindow.h"

struct element
{
    element() {}
    int id;
    QString login;
    QString password;

};

auto QGetStringDoubleB64(QString filename){


        QFile file(filename);
        file.open(QIODevice::ReadOnly);


    auto f_get = file.readLine();
    auto ft = QByteArray::fromBase64(f_get);
    auto ft2 = QByteArray::fromBase64(ft);


    return QString::fromStdString(ft2.toStdString());
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
    qDebug()<<"Getting Data Started...";
    qDebug()<<"_____________";
    QString correctPassword  = QGetStringDoubleB64(this->filename);
    if(isCorrect(correctPassword,ui->lineEdit->text())){

        QFile file(filename);
        file.open(QIODevice::ReadOnly);
std::vector<std::pair<QString,QString>> tmpList;
std::pair<QString,QString> tmp;
file.readLine();
while (!file.atEnd())
  {
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
       mw.setWindowTitle("PasswordKeep");
       qDebug()<<"mainwindow created";
       mw.pList = tmpList;
      // mw.tempLw = mw.AddListWidget();
       mw.password = correctPassword;
       mw.filename = filename;
      // for (auto el : tmpList) {
      //    mw.addElement(el,mw.tempLw);
      // }

//Проверить код сверху (получает два логина)








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

