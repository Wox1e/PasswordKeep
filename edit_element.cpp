#include "edit_element.h"
#include "ui_edit_element.h"
#include <QMessageBox>

edit_element::edit_element(QWidget *parent) :


    QDialog(parent),
    ui(new Ui::edit_element)
{
    ui->setupUi(this);

}


edit_element::~edit_element()
{
    delete ui;
}

void edit_element::setBeforeData(QString bl,QString bp){
    this->bPassword = bp;
    this->bLogin = bl;
    this->ui->lineEdit->setText(this->bLogin);
    this->ui->lineEdit_2->setText(this->bPassword);
    this->login = this->bLogin;
    this->password = bPassword;

}


void edit_element::on_pushButton_3_clicked()
{

    if(ui->lineEdit->text()== "" || ui->lineEdit_2->text()==""){
        QMessageBox qm;
        qm.warning(this,"Ошибка","Поля не могут быть пустыми");
        //this->close();
       // password = bPassword;
        //login = bLogin;

    }
    else{



            if(ui->lineEdit->text() != ""){
                 login = ui->lineEdit->text();

                }


                if(ui->lineEdit_2->text() != ""){
                    password = ui->lineEdit_2->text();

                    }

this->close();

    }
}

