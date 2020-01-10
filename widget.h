#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QUrl>
#include <QWebView>
#include <QWebFrame>
#include <QMessageBox>
#include <mainwindow.h>
#include <QPainter>
#include <QtPrintSupport/QPrinter>
#include <QDesktopServices>
#include <main_menu.h>
#include <QVector>
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QString name,QWidget *parent = 0);
    ~Widget();

    int m_nRadius;//默认画圆半径
    QString m_strCity ;


protected slots:
    void finished();
    void getInfo();

private slots:


    void on_saveBtn_clicked();

    void on_historyBtn_clicked();

    void on_gobackBtn_clicked();


private:
    Ui::Widget *ui;
    QWebFrame *frame;
    QString name;

    QVector<QString> str1;
    QVector<QString> str2;
    QVector<QString> path;
    QVector<QString> desc;
};

#endif // WIDGET_H
