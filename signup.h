#ifndef SIGNUP_H
#define SIGNUP_H

#include <QDialog>
#include "mysql.h"
#include <QMessageBox>
#include <QRegExp>
#include <mainwindow.h>

namespace Ui {
class Signup;
}

class Signup : public QDialog
{
    Q_OBJECT

public:
    explicit Signup(QWidget *parent = 0);
    ~Signup();


private slots:
    void on_signup_clicked();

    void on_goback_clicked();

private:
    Ui::Signup *ui;
    Mysql *mysql;
};

#endif // SIGNUP_H
