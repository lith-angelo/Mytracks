#include "signup.h"
#include "ui_signup.h"

Signup::Signup(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Signup)
{
    ui->setupUi(this);
    //背景图片
        QPixmap bkgnd(":/image/bgp/bgp21.png");
        bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
        QPalette palette;
        palette.setBrush(QPalette::Background, bkgnd);
        this->setPalette(palette);

        //透明
        ui->mailEdit->setStyleSheet("background:transparent;border-width:0;border-style:outset");
        ui->usernameEdit->setStyleSheet("background:transparent;border-width:0;border-style:outset");
        ui->passwdEdit->setStyleSheet("background:transparent;border-width:0;border-style:outset");
        ui->passwd_againEdit->setStyleSheet("background:transparent;border-width:0;border-style:outset");

        //按钮形状
        ui->signup->setStyleSheet("QPushButton{background-color:black;color: white;border-radius: 10px;  border: 2px groove gray;border-style: outset;}""QPushButton:hover{background-color:white; color: black;}""QPushButton:pressed{background-color:rgb(85, 170, 255);border-style: inset; }"
                                                   );
        ui->goback->setStyleSheet("QPushButton{background-color:black;color: white;border-radius: 10px;  border: 2px groove gray;border-style: outset;}""QPushButton:hover{background-color:white; color: black;}""QPushButton:pressed{background-color:rgb(85, 170, 255);border-style: inset; }"
                                               );


}

Signup::~Signup()
{
    delete ui;
}



void Signup::on_signup_clicked()
{
    QString mail = ui->mailEdit->text(),username = ui->usernameEdit->text(),passwd = ui->passwdEdit->text(),passwd_again = ui->passwd_againEdit->text();
    //邮箱检验
    QRegExp re_mail("^([A-Za-z0-9_\\-\\.])+\\@([A-Za-z0-9_\\-\\.])+\\.([A-Za-z]{2,4})$");
    if(!re_mail.exactMatch(mail)){
        QMessageBox::information(this,"警告","邮箱不合法!");
        ui->mailEdit->setFocus();
        return;
    }
    //用户名检验
    QRegExp re_username("^[a-zA-Z0-9_]{6,16}$");
    if(!re_username.exactMatch(username)){
        QMessageBox::information(this,"警告","用户名不合法!");
        ui->mailEdit->setFocus();
        return;
    }
    //密码长度校验
    QRegExp re_passwd(".{6,20}");
    if(!re_passwd.exactMatch(passwd)){
        QMessageBox::information(this,"警告","密码长度不符合要求!");
        ui->mailEdit->setFocus();
        return;
    }
    //密码确认校验
    if(passwd != passwd_again){
        QMessageBox::information(this,"警告","两次输入的密码不一致!");
        ui->mailEdit->setFocus();
        return;
    }
    //执行注册事件
    mysql = new Mysql;
    mysql->connect();
    bool ret = mysql->signup(mail,username,passwd);
    qDebug()<<"这是ret"<<ret;
    if(ret)
    {
        QMessageBox::information(this,"提示","注册成功，前往登录吧~");
        this->hide();
        MainWindow *mainwindow = new MainWindow;
        mainwindow->show();
    }else{
        QMessageBox::warning(this,"提示","用户名已存在!");
    }

}

void Signup::on_goback_clicked()
{
    this->destroy();
    MainWindow *mainwindow = new MainWindow;
    mainwindow->setWindowTitle("欢迎来到Mytracks!");
    mainwindow->show();
}
