#include "startwindow.h"
#include <QApplication>
#include "open_pack.h"



int main(int argc, char *argv[])
{



    QApplication a(argc, argv);
    StartWindow w;
    w.setWindowTitle("PasswordKeep");
    w.Psw = &w;
    w.show();

    return a.exec();
}
