#ifndef MYSQL_H
#define MYSQL_H
#include <QSql>
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlQuery>
#include <QString>
#include <QSqlRecord>
class Mysql
{
public:
    Mysql();
    void connect();
    bool login(QString username,QString passwd);
    bool signup(QString mail, QString username, QString passwd);
    QString queryUserId(QString username);
private:
    QSqlQuery *query;
};


#endif // MYSQL_H
