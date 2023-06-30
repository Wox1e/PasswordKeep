#ifndef MAINWINDOW_EXTRA_H
#define MAINWINDOW_EXTRA_H
#include <deque>
#include <QDialog>

namespace Ui {
class mainwindow_extra;
}

class mainwindow_extra : public QDialog
{
    Q_OBJECT

public:
    explicit mainwindow_extra(QWidget *parent = nullptr);
    ~mainwindow_extra();
    std::deque<std::pair<QString,QString>> ListOfPair;

private slots:
    void on_pushButton_clicked();

private:
    Ui::mainwindow_extra *ui;
};

#endif // MAINWINDOW_EXTRA_H
