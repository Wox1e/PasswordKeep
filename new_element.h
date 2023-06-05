#ifndef NEW_ELEMENT_H
#define NEW_ELEMENT_H

#include <QDialog>

namespace Ui {
class new_element;
}

class new_element : public QDialog
{
    Q_OBJECT

public:
    explicit new_element(QWidget *parent = nullptr);
    ~new_element();
    QString login;
    QString password;
    struct passwordGenPolicy
    {
        passwordGenPolicy() {}

        bool useSpecChars;
        int charCount;

    };

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

    void on_progressBar_valueChanged(int value);

    void on_lineEdit_2_textChanged(const QString &arg1);

    void on_toolButton_clicked();

private:
    Ui::new_element *ui;
};

#endif // NEW_ELEMENT_H
