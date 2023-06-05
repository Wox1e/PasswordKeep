#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QListWidgetItem>
#include <QDialog>
#include <deque>
#include <new_element.h>
#include <edit_element.h>

namespace Ui {
class mainwindow;
}

class mainwindow : public QDialog
{
    Q_OBJECT

public:
    explicit mainwindow(QWidget *parent = nullptr);
    ~mainwindow();
QString filename;
int row;
QListWidgetItem *clickedItem;
private slots:
    void on_pushButton_clicked();


    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);

    void on_listWidget_doubleClicked(const QModelIndex &index);

    void on_pushButton_2_clicked();

    void on_listWidget_itemClicked(QListWidgetItem *item);

    void on_pushButton_3_clicked();

private:
    Ui::mainwindow *ui;

public:
    struct element
    {
        element() {}
        int id;
        QString login;
        QString password;
    };
    std::deque<element> elementList;
    std::vector<std::pair<QString,QString>> pList;
    auto GetUI(){
        return ui;
    }
QString password;

Ui::mainwindow *gui = ui;
protected:
    void closeEvent(QCloseEvent *event) override;
    void showEvent(QShowEvent *ev) override;



public:
    auto AddListWidget(){
        QListWidget *qw = new QListWidget;
        return qw;
    }
    QListWidget* tempLw;
    auto addElement(std::pair<QString,QString> p,QListWidget *qw)
    {
        element newEl;
        newEl.login = p.first;
        newEl.password = p.second;

        elementList.push_back(newEl);
        QListWidgetItem *listWidgetItem = new QListWidgetItem();
        QVariant qv(elementList.size());
        listWidgetItem->setData(512,qv);
        listWidgetItem->setText(newEl.login);
        qw->addItem(listWidgetItem);
        qDebug()<<"addItem -> "<<listWidgetItem->text();
        qDebug()<<"Item.data() = "<<listWidgetItem->data(512).toInt();

       // ui->listWidget->addItem(listWidgetItem);
        //дописать
       // tempLw = qw;


    }


};




#endif // MAINWINDOW_H
//18:53

