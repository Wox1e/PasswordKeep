#ifndef EDIT_ELEMENT_H
#define EDIT_ELEMENT_H

#include <QDialog>

namespace Ui {
class edit_element;
}

class edit_element : public QDialog
{
    Q_OBJECT

public:
    //edit_element::edit_element(QWidget *parent, QString bPass, QString bLog);
    explicit edit_element(QWidget *parent = nullptr);
    edit_element(QString log,QString pas){
        password = pas;
        login = log;

    }
    ~edit_element();
QString login;
QString password;

QString bPassword = "";
QString bLogin = "";

private slots:
void on_pushButton_3_clicked();

private:
    Ui::edit_element *ui;

public:
void setBeforeData(QString bp,QString bl);




};



#endif // EDIT_ELEMENT_H
