#include "mysql.h"
Mysql::Mysql()
{

}

void Mysql :: connect(){

    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("127.0.0.1");
    db.setUserName("root");
    db.setPassword("root");
    db.setDatabaseName("tong_you");
    if(db.open()){
        qDebug()<<"Connect Database Successfully!";
        return;

    }else{
        qDebug()<<"Connect Database Failed!";
        return;
    }

}

bool Mysql :: login(QString username,QString passwd){
   QString sql = QString("select * from users where username='%1' and passwd=md5('%2')").arg(username).arg(passwd);
   query = new QSqlQuery;
   query->exec(sql);
   query->last();
   int record = query->at()+1;
   if(record==0) return false;
   return true;
}

bool Mysql :: signup(QString mail, QString username, QString passwd){
    QString sql = QString("select * from user where username='%1'").arg(username);
    query = new QSqlQuery;
    query->exec(sql);
    query->last();
    int record = query->at()+1;
    if(record != 0)
        return false;
    sql = QString("insert into users (username,passwd,mail) values('%1',md5('%2'),'%3')").arg(username).arg(passwd).arg(mail);
    qDebug()<<"这是sql语句"<<sql;
    bool ret = query->exec(sql);
    return ret;
}

QString Mysql::queryUserId(QString username){
    QString sql = QString("select id from users where username='%1'").arg(username);
    query = new QSqlQuery;
    query->exec(sql);
    QSqlRecord rec = query->record();
    while(query->next()){
        int idcol = rec.indexOf("id");
        QString id =query->value(idcol).toString();
        return id;
    }

}

