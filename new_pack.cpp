#include "new_pack.h"
#include <QFile>
#include "ui_new_pack.h"

auto QSaveData_DoubleB64encoded(QString filename, QString data){
     QFile file(filename);
     file.open(QIODevice::Append);
     file.WriteOnly;

    file.write(data.toUtf8().toBase64().toBase64());
    file.write("\n");
file.close();
//работает только если передать полную ссылку на файл
}









new_pack::new_pack(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::new_pack)
{
    ui->setupUi(this);
}

new_pack::~new_pack()
{
    delete ui;
}

;







void new_pack::on_pushButton_clicked()
{
  auto pass = ui->lineEdit->text();

QSaveData_DoubleB64encoded(new_pack::filename, pass);

this->close();
}

