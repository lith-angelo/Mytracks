#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "mysql.h"
#include "main_menu.h"
#include "signup.h"
#include "widget.h"
#include <QSqlQuery>
#include <QMessageBox>
#include <QString>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:


    void on_register_Btn_clicked();

    void on_loginBtn_clicked();

private:
    Ui::MainWindow *ui;
    Mysql *mysql;
    QString name;
};

#endif // MAINWINDOW_H
