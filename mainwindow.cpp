#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{   //背景图片
    ui->setupUi(this);
    QPixmap bkgnd("E:/fucking_program/src/bgp/bgp21.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);

    //透明
    ui->usrLineEdit->setStyleSheet("background:transparent;border-width:0;border-style:outset");
    ui->pwdLineEdit->setStyleSheet("background:transparent;border-width:0;border-style:outset");

    //按钮形状
    ui->loginBtn->setStyleSheet("QPushButton{background-color:black;color: white;border-radius: 10px;  border: 2px groove gray;border-style: outset;}""QPushButton:hover{background-color:white; color: black;}""QPushButton:pressed{background-color:rgb(85, 170, 255);border-style: inset; }"
                                               );
    ui->exitBtn->setStyleSheet("QPushButton{background-color:black;color: white;border-radius: 10px;  border: 2px groove gray;border-style: outset;}""QPushButton:hover{background-color:white; color: black;}""QPushButton:pressed{background-color:rgb(85, 170, 255);border-style: inset; }"
                                           );
    ui->register_Btn->setStyleSheet("QPushButton{background-color:black;color: white;border-radius: 10px;  border: 2px groove gray;border-style: outset;}""QPushButton:hover{background-color:white; color: black;}""QPushButton:pressed{background-color:rgb(85, 170, 255);border-style: inset; }"
                                 );
    //设置默认回车
     connect(ui->pwdLineEdit, SIGNAL(returnPressed()), ui->loginBtn, SIGNAL(clicked()), Qt::UniqueConnection);
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_register_Btn_clicked()
{
    this->close();
    Signup *signup =new Signup;
    signup->setWindowTitle("注册");
    signup->show();

}

void MainWindow::on_loginBtn_clicked()
{
    QString username = ui->usrLineEdit->text();
    QString passwd = ui->pwdLineEdit->text();
    //检验用户名或密码是否为空
    if(username=="" || passwd==""){
            QMessageBox::information(this,"警告","输入不能为空",QMessageBox::Ok);  ui->usrLineEdit->setFocus(); return; }
    //检验用户名是否合法
    QRegExp re_username("^[a-zA-Z0-9_]{3,16}$");
    if(!re_username.exactMatch(username)){
        QMessageBox::information(this,"警告","用户名不合法!");
        ui->usrLineEdit->setFocus();
        return;
    }
    //执行登录事件
    mysql = new Mysql;
    mysql->connect();
    if(mysql->login(username,passwd)){
        name = ui->usrLineEdit->text();
        this->hide();
//        Widget *widget =new Widget(name,pwd);
//        widget->setWindowTitle("来上传旅途照片吧~");
//        widget->show();
        Main_menu *main_menu = new Main_menu(name);
        main_menu->setWindowTitle("主菜单");
        main_menu->show();
    }else{
        QMessageBox::warning(this,"登录","用户名或密码错误!");
    }
}
