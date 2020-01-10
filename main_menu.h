#ifndef MAIN_MENU_H
#define MAIN_MENU_H
#include <mainwindow.h>
#include "widget.h"

#include <QDialog>
#include <QDesktopServices>
#include <QFileDialog>
#include <QTextCodec>
#include <QSplitter>
#include <QListWidget>
#include "content.h"
#include "mysql.h"

namespace Ui {
class Main_menu;
}

class Main_menu : public QDialog
{
    Q_OBJECT

public:
    explicit Main_menu(QString name="",QWidget *parent = 0);
    ~Main_menu();

private slots:
    void on_ExitBtn_clicked();

    void on_loadJourneyBtn_clicked();

    void on_viewHistoryBtn_clicked();

    void on_changeInfoBtn_clicked();

private:
    Ui::Main_menu *ui;
    QString name;
    //QString id;
    Mysql *mysql;
};

#endif // MAIN_MENU_H
