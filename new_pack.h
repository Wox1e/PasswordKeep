#ifndef NEW_PACK_H
#define NEW_PACK_H

#include <QDialog>

namespace Ui {
class new_pack;
}

class new_pack : public QDialog
{
    Q_OBJECT

public:
    explicit new_pack(QWidget *parent = nullptr);
    ~new_pack();
QString filename = "";

private slots:
    void on_pushButton_clicked();

private:
    Ui::new_pack *ui;
};

#endif // NEW_PACK_H
