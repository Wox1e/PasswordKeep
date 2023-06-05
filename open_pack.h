#ifndef OPEN_PACK_H
#define OPEN_PACK_H
#include "startwindow.h"
#include <QDialog>

namespace Ui {
class open_pack;
}

class open_pack : public QDialog
{
    Q_OBJECT

public:
    explicit open_pack(QWidget *parent = nullptr);
    ~open_pack();
QString filename = "";
class StartWindow *sw;

private slots:
    void on_pushButton_clicked();

private:
    Ui::open_pack *ui;
};

#endif // OPEN_PACK_H
