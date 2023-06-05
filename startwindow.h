#ifndef STARTWINDOW_H
#define STARTWINDOW_H
#pragma once
#include <QMainWindow>
#include "open_pack.h"
#include <QMessageBox>
#include "new_pack.h"
#include <edit_element.h>
#include <mainwindow.h>
#include <new_element.h>

QT_BEGIN_NAMESPACE
namespace Ui { class StartWindow; }
QT_END_NAMESPACE

class StartWindow : public QMainWindow
{
    Q_OBJECT

public:
    StartWindow(QWidget *parent = nullptr);
    ~StartWindow();
    class StartWindow *Psw;

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_7_clicked();

private:
    Ui::StartWindow *ui;
};
#endif // STARTWINDOW_H
