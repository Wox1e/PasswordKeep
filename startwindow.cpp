#include "startwindow.h"
#include "ui_startwindow.h"
#include <QFileDialog>

StartWindow::StartWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::StartWindow)
{
    ui->setupUi(this);


}

StartWindow::~StartWindow()
{
    delete ui;
}


void StartWindow::on_pushButton_2_clicked()
{
    auto filename = QFileDialog::getOpenFileName(this, "Open File", "/Documents","pkp files(*.pkp)");
//работает
// вместо /Documents можно написать стартовое место окна поиска

if(filename != "")
{
open_pack ow;
ow.sw = this->Psw;
ow.filename = filename;
ow.setWindowTitle("Open Container");
ow.setModal(1);
ow.exec();
}



}


void StartWindow::on_pushButton_clicked()
{

   QString filename = QFileDialog::getSaveFileName(this,"Save File", "Password Keep Package", "pkp (*.pkp)");
   QFile file(filename);
   file.open(QIODevice::Append);
   file.close();

   if(filename != "")
{
   new_pack nw;
   nw.setModal(1);
   nw.setWindowTitle("PasswordKeep");
   nw.filename = filename;
   nw.exec();
}
//полностью работает
//сохраняет запароленный файл


}









void StartWindow::on_pushButton_3_clicked(){
    mainwindow mw;
    mw.setModal(1);
    mw.exec();




};

void StartWindow::on_pushButton_7_clicked(){};










