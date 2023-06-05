#include "new_element.h"
#include <string>
#include "ui_new_element.h"
#include <QtGui/QPalette>


int getPasswordDiffValue(std::string password) {
    int k = 0;
    std::string arr[] = {",",".","!","#","$","%","^","*","&","(",")","_","/","=","+","-"};
    char arr2[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    k += 7 * password.size();
    if (password.find("qwerty") != password.npos) k -= 20;
    if (password.find("123") != password.npos) k -= 20;
    if (password.find("a1b2c3") != password.npos) k -= 10;
    if (password.find("abc") != password.npos) k -= 20;
    if (password.find("321") != password.npos) k -= 10;

    for (auto el:arr)
    {
        if (password.find(el) != password.npos) k += 10;

    }

    for (auto el:arr2)
    {
        if (password.find(el) != password.npos) k += 5;
    }



    if (k > 100) k = 100;
    if (k < 0) k = 0;
    return k;
}


std::string gen_random_String(const int len) {
    static const char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";
    std::string tmp_s;
    tmp_s.reserve(len);

    for (int i = 0; i < len; ++i) {
        tmp_s += alphanum[rand() % (sizeof(alphanum) - 1)];
    }

    return tmp_s;
}

std::string gen_random_String_useSpecialChars(const int len) {
    static const char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz"
        ".,!@#$%^&*(/)_+=/*-.|\<>}{[]";
    std::string tmp_s;
    tmp_s.reserve(len);

    for (int i = 0; i < len; ++i) {
        tmp_s += alphanum[rand() % (sizeof(alphanum) - 1)];
    }

    return tmp_s;
}


new_element::new_element(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::new_element)
{
    ui->setupUi(this);
   // ui->progressBar->setValue(0);
}

new_element::~new_element()
{
    delete ui;
}

void new_element::on_pushButton_3_clicked()
{

password = ui->lineEdit_2->text();
login = ui->lineEdit ->text();
    this->close();

}


void new_element::on_pushButton_clicked()
{
    srand(time(NULL));
    std::string tmp = "";
    auto itNum = rand()%10+5;
    qDebug() << itNum;
    for (int i = 0; i < itNum; ++i) {

        tmp = tmp + gen_random_String_useSpecialChars(1);

    }

qDebug()<<QString::fromStdString(tmp);
ui->lineEdit_2->setText(QString::fromStdString(tmp));

}


void new_element::on_progressBar_valueChanged(int value)
{
    ui->progressBar->setValue(value);
}


void new_element::on_lineEdit_2_textChanged(const QString &arg1)
{
    ui->progressBar->setValue(getPasswordDiffValue(ui->lineEdit_2->text().toStdString()));
}


void new_element::on_toolButton_clicked()
{


}

