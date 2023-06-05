#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <deque>
#include <QFile>
#include <QCloseEvent>
#include <QClipboard>
template <typename T>
auto moveDeque(std::deque<T>p, int u)
{
    std::deque<T> q;

    for(int i=0; i<p.size(); i++)
        q.push_back(p[(i-u) % p.size()]);

     return q;
 }
auto QSavePair_Double(std::pair<QString,QString> p,QString filename){
     QFile file(filename);
    // qDebug()<<"filename = "<<filename;
     file.open(QIODevice::Append);
     //file.WriteOnly;

file.write(p.first.toUtf8().toBase64().toBase64());
file.write("\n");
file.write(p.second.toUtf8().toBase64().toBase64());
file.write("\n");


file.close();
//работает только если передать полную ссылку на файл
}


auto QSaveData_Double(QString filename,std::deque<std::pair<QString,QString>> pl,QString pass){
    QFile file(filename);
    qDebug()<<"filename = "<<filename;
    file.open(QIODevice::WriteOnly);

    file.write(pass.toUtf8().toBase64().toBase64());
    file.write("\n");
    file.close();

    for(auto el:pl){

        QSavePair_Double(el,filename);

    }

    file.close();

}







mainwindow::mainwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::mainwindow)
{
    ui->setupUi(this);


}

/*
struct element
{
    element() {}
    int id;
    QString login;
    QString password;

};
*/

//std::deque<element> elementList;

mainwindow::~mainwindow()
{


    delete ui;
}



void mainwindow::showEvent(QShowEvent *ev){
    qDebug()<<"mainwindow::showEvent called";

    for (auto el : this->pList) {

        element newEl;
        newEl.login = el.first;
        newEl.password = el.second;
        newEl.id = ui->listWidget->count()+1;




        elementList.push_back(newEl);
        QListWidgetItem *listWidgetItem = new QListWidgetItem(newEl.login);
        QVariant qv(elementList.size());
        listWidgetItem->setData(512,qv);
        listWidgetItem->setText(newEl.login);
        ui->listWidget->addItem(listWidgetItem);
    }


ev->accept();

}






void mainwindow::on_pushButton_clicked()
{
element newEl;
new_element ne;
ne.setWindowTitle("PasswordKeep");
ne.setModal(1);
ne.exec();



while(ne.isActiveWindow()) {

}

if (ne.login == "" || ne.password == ""){
    QMessageBox qm;
    qm.warning(this,"Ошибка","Поля не могут быть пустыми");

}
else
{


newEl.login = ne.login;
newEl.password = ne.password;
newEl.id = ui->listWidget->count()+1;




elementList.push_back(newEl);
QListWidgetItem *listWidgetItem = new QListWidgetItem(newEl.login);
QVariant qv(elementList.size());
listWidgetItem->setData(512,qv);
listWidgetItem->setText(newEl.login);
ui->listWidget->addItem(listWidgetItem);
}

}







void mainwindow::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{

    QVariant qv = item->data(512);
    qDebug() << qv.toInt();

    edit_element eew;
    eew.setWindowTitle("PasswordKeep");

    eew.setBeforeData(elementList[qv.toInt()-1].login,elementList[qv.toInt()-1].password);

    //eew.bLogin = elementList[qv.toInt()-1].login;
   // eew.bPassword = elementList[qv.toInt()-1].password;

    eew.setModal(1);
    eew.exec();

    elementList[qv.toInt()-1].login = eew.login;
    elementList[qv.toInt()-1].password = eew.password;

    item->setText(eew.login);

    // дописать

}


void mainwindow::on_listWidget_doubleClicked(const QModelIndex &index){}









void mainwindow::on_pushButton_2_clicked(){
   // ui->listWidget->removeItemWidget(clickedItem);
QMessageBox qm;
auto ans = qm.question(this,"", "Вы уверены?",  QMessageBox::Yes|QMessageBox::No);



/*
if(ans == QMessageBox::Yes){
   auto selItem = ui->listWidget->selectedItems();
    qDeleteAll(selItem);
auto id = selItem.front()->data(512).toInt();
qDebug() << id;

auto it = elementList.begin();
std::advance(it,id);
if(it != elementList.end()) elementList.erase(it);


std::deque<element> tmpList;
for (int i = 0; i < id; i++) {
   tmpList[i] = elementList[i];
}

for (int i = id; i < elementList.size()-1 ; i++) {
    tmpList[i] = elementList[i++];
    qDebug() << i;
}


elementList.clear();
elementList = tmpList;


}
*/

if(ans == QMessageBox::Yes){
    qDebug()<<"____________";
    auto selItem = ui->listWidget->selectedItems();
    qDeleteAll(selItem);
    auto id = selItem.front()->data(512).toInt();
    qDebug() <<"id = "<< id;
    auto it = elementList.begin();
    std::advance(it,id);
    auto lwCount = ui->listWidget->count() + 1;
    //elementList.erase(it);
    qDebug()<<"listWidget->count = "<<lwCount;
    for(int i = id-1; i < lwCount-1; ++i)
    {
        qDebug()<<"i = "<<i;
        QVariant qv((ui->listWidget->item(i)->data(512)).toInt()-1);
        ui->listWidget->item(i++)->setData(512,qv);
        qDebug()<<"data = "<< qv.toInt();
        qDebug()<<"sad";
    }



    id--;
    auto iter = elementList.begin();
    std::advance(iter,id);
    qDebug() <<"id = "<<id;
    qDebug()<< iter->login <<" erased";
    if(it != elementList.end()) elementList.erase(iter);



    //лютый говнокод
    //НИКОГДА НЕ ТРОГАТЬ!!!!!
    //доделать
}





}

void mainwindow::on_listWidget_itemClicked(QListWidgetItem *item){}





void mainwindow::on_pushButton_3_clicked()
{
   auto selItem = ui->listWidget->selectedItems().back();
  auto it = elementList.begin();
  qDebug() << selItem->data(512).toInt();
  std::advance(it,selItem->data(512).toInt()-1);
  auto text = it->password;
   qDebug() << text;
   QApplication::clipboard()->setText(text);

}

void mainwindow::closeEvent(QCloseEvent *event)
{
    std::deque<std::pair<QString,QString>> pairList;
    std::pair<QString,QString> tmp;

    for (auto el : elementList) {
       tmp.first = el.login;
       tmp.second = el.password;
       pairList.push_back(tmp);
    }

   // for (auto el : pairList) {
    //   QSavePair_Double(this->filename,el);
   // }
    QSaveData_Double(this->filename,pairList,password);


event->accept();
}

