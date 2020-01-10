#include<QPushButton>
#include "baseinfo.h"
#include "contact.h"
#include "detail.h"
#include "mysql.h"

#ifndef CONTENT_H
#define CONTENT_H

#include <QDialog>

class Content : public QFrame
{
    Q_OBJECT

public:
    Content(QString username,QWidget *parent = 0);
    QStackedWidget *stack;//定义堆栈窗口
    QPushButton *AmendBtn;//定义修改键
    QPushButton *CloseBtn;//定义关闭键

    BaseInfo *baseInfo;
    Contact *contact;
    Detail *detail;
    ~Content();

private:
    Mysql *mysql;
    QString username;
};

#endif // CONTENT_H

