#include <QFile>
#include <vector>
namespace tf{


auto QGetStringDoubleB64(QString filename){


        QFile file(filename);
        file.open(QIODevice::ReadOnly);


    auto f_get = file.readLine();
    auto ft = QByteArray::fromBase64(f_get);
    auto ft2 = QByteArray::fromBase64(ft);









    return ft2.toStdString();







}















}
namespace wf {


auto QSaveData(QString filename, QString data){
     QFile file(filename);
     file.open(QIODevice::WriteOnly);

    file.write(data.toUtf8());

file.close();
//работает только если передать полную ссылку на файл
}



auto QSaveData_B64encoded(QString filename, QString data){
     QFile file(filename);
     file.open(QIODevice::Append);
     file.WriteOnly;

    file.write(data.toUtf8().toBase64());
file.close();
//работает только если передать полную ссылку на файл
}


auto QSaveAllData(QString filename,QString login, QString password){
     QFile file(filename);
     file.open(QIODevice::Append);
     file.WriteOnly;
file.write(login.toUtf8().toBase64());
file.write("\n");
file.write(password.toUtf8().toBase64());
file.write("\n");


file.close();
//работает только если передать полную ссылку на файл
}



auto QGetData(QString filename){
    QFile file(filename);
    file.open(QIODevice::ReadOnly);
    std::vector<std::pair<QString, QString>> vec;
    std::pair<QString, QString> temp_P;


    while(!file.atEnd()){

    auto fir_temp = file.readLine();
    auto sec_temp = file.readLine();

  auto ft = QByteArray::fromBase64(fir_temp);
  auto st = QByteArray::fromBase64(sec_temp);

    temp_P.first = QString::fromStdString(ft.toStdString());
    temp_P.second = QString::fromStdString(st.toStdString());
    vec.push_back(temp_P);



    }




     file.close();
     return vec;
}






auto QSaveData_DoubleB64encoded(QString filename, QString data){
     QFile file(filename);
     file.open(QIODevice::Append);
     file.WriteOnly;

    file.write(data.toUtf8().toBase64().toBase64());
file.close();
//работает только если передать полную ссылку на файл
}


auto QSavePair_Double(QString filename,std::pair<QString,QString> p){
     QFile file(filename);
     file.open(QIODevice::Append);
     file.WriteOnly;
file.write(p.first.toUtf8().toBase64().toBase64());
file.write("\n");
file.write(p.second.toUtf8().toBase64().toBase64());
file.write("\n");


file.close();
//работает только если передать полную ссылку на файл
}




auto QGetPair_Double(QString filename){
    QFile file(filename);
    file.open(QIODevice::ReadOnly);
    std::pair<QString, QString> pair;

    auto f_get = file.readLine();
    auto s_get = file.readLine();





auto ft = QByteArray::fromBase64(f_get);
auto st = QByteArray::fromBase64(s_get);


auto ft2 = QByteArray::fromBase64(ft);
auto st2 = QByteArray::fromBase64(st);






        pair.first = QString::fromStdString(ft2.toStdString());
        pair.second = QString::fromStdString(st2.toStdString());

return pair;



}






}
