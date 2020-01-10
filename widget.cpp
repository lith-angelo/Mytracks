#include "widget.h"
#include "ui_widget.h"
#include "exif.h"
#include <QFileDialog>
#include <typeinfo>




Widget::Widget(QString name,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->name=name;

    m_nRadius = 1000;//默认画圆半径
    m_strCity = "黄冈";

    ui->webView->load(QUrl("file:///C:/Users/97202/Desktop/0102code/map.html")); //导入URL。能否将html文件以资源文件添加进入

    //webView控件加载完成会发送信号，连接信号，槽实现
    connect(ui->webView,&QWebView::loadFinished,this,&Widget::finished);
    connect(ui->getBtn,&QPushButton::clicked,this,&Widget::getInfo);

    ui->getBtn->setStyleSheet("QPushButton{background-color:black;color: white;border-radius: 10px;  border: 2px groove gray;border-style: outset;}""QPushButton:hover{background-color:white; color: black;}""QPushButton:pressed{background-color:rgb(85, 170, 255);border-style: inset; }"
                                               );
    ui->saveBtn->setStyleSheet("QPushButton{background-color:black;color: white;border-radius: 10px;  border: 2px groove gray;border-style: outset;}""QPushButton:hover{background-color:white; color: black;}""QPushButton:pressed{background-color:rgb(85, 170, 255);border-style: inset; }"
                                               );
    ui->gobackBtn->setStyleSheet("QPushButton{background-color:black;color: white;border-radius: 10px;  border: 2px groove gray;border-style: outset;}""QPushButton:hover{background-color:white; color: black;}""QPushButton:pressed{background-color:rgb(85, 170, 255);border-style: inset; }");

}

Widget::~Widget()
{
    delete ui;
}


void Widget::finished()
{
//    QString a = MainWindow::ui->us
//    ui->User->setText("欢迎您"+a);
    frame = ui->webView->page()->mainFrame();//获取网页页面的主框架
    QString method = QString("SetCity(\"%1\")").arg(m_strCity);//调用js的SetCity进行目标城市设置

    frame->evaluateJavaScript(method);  //调用html文件的SetCity函数

}

void Widget::getInfo()
{
//    QWebFrame *frame = ui->webView->page()->mainFrame();
//    QVariant var = frame->evaluateJavaScript("ReturnLngLat()"); //调用js的ReturnLngLat返回目标点的经度和维度
//    QStringList strList = var.toStringList(); //var中保存的是目标点的经度和维度
//    int i;
//    for(i=0; i<strList.count(); i++)
//    {
//        QMessageBox::information(NULL, QObject::tr("Lng&Lat"), strList.at(i));
//    }
    QString filePath = "C:/Users/97202/Desktop/0102code/ExifDemo/image";
    QString strFile =  QFileDialog::getOpenFileName(0,"上传图片",filePath); //打开指定目录


    QPixmap image;
    image.load(strFile);
//    ui->pictureLbl->setScaledContents(true); //true 表明填充所有的可用空间
//    ui->pictureLbl->clear(); //先清空
//    ui->pictureLbl->setPixmap(image); //设置图片
//    ui->pictureLbl->show();

    //准备借助EXIF读取信息
    EXIFINFO exifInfo;  //结构体
    //将QString转换成const char*
    const char* picPath = strFile.toUtf8().data();
    qDebug()<<picPath;

    //绝对路径转相对路径，JS函数中接收绝对路径无法显示图片
    QString relativePath = strFile.replace("C:/Users/97202/Desktop/0102code/","");
    qDebug()<<relativePath.toUtf8().data();

    FILE *fp = fopen(picPath,"rb"); //C语言读写文件，以二进制的读文件

    if(fp) //表明打开成功
    {
        Cexif ce(&exifInfo); //调用构造函数，传入结构体指针，初始化对象ce
        bool b = ce.DecodeExif(fp);  //调用解析函数，解析Exif信息
        fclose(fp);
        if(b)
        {
            QString longitude = QString::number(exifInfo.Latitude);     //维度
            qDebug()<<longitude;
            QString latitude = QString ::number(exifInfo.Longitude);    //经度
            qDebug()<<latitude;
            QString des = ui->textEdit->toPlainText();
//            QString time = QString::number(exifInfo.DateTime);       //这里时间显示的有点问题，可以自己处理一下
//            QString method = QString("theLocation(\"%1\",\"%2\")").arg(latitude).arg(longitude);//调用js的theLocation进行照片的地图定位
//           frame->evaluateJavaScript(method);
            QString method1 = QString("showPicture(\"%1\",\"%2\",\"%3\",\"%4\")").arg(relativePath).arg(latitude).arg(longitude).arg(des);
            qDebug()<<method1;
            frame->evaluateJavaScript(method1);


            //保存路径
            str1.append(latitude);
            str2.append(longitude);
            path.append(relativePath);
            desc.append(des);
        }
        else
        {
            qDebug()<<tr("解析失败").toUtf8().data();
        }
    }
    else
    {
        qDebug()<<tr("文件打开失败！").toUtf8().data();
        QMessageBox::information(this,"提示","图片未打开成功，再尝试一次吧！");
    }
}



void Widget::on_saveBtn_clicked()
{
    QString file_path = QFileDialog::getSaveFileName(this, tr("Save File"),"D:/data.txt",tr("All files(*.*)"));
        if(!file_path.isEmpty())
        {
            //如果没有写后缀就自动加上
            if(QFileInfo(file_path).suffix().isEmpty())
            file_path.append(".txt");

            //将相关经纬度存入文件
            QFile aFile(file_path);
            //采用追加写文件的方式写入
            if (!aFile.open(QIODevice::Append | QIODevice::Text))
            {
                QMessageBox::warning(this,tr("warning"),QString("文件打开失败!"),QMessageBox::Ok);
            }
            else{
                QTextStream aStream(&aFile); //用文本流读取文件
                for(int i=0;i<desc.count();i++){
                    //写入文本流
                    aStream << str1[i] << "," << str2[i] << "," << path[i] << "," << desc[i] << endl;
                }
                aFile.close();//关闭文件
            }

            QMessageBox::information(this,tr("成功"),QStringLiteral("保存成功"),QMessageBox::Ok);
        }
        else
            QMessageBox::warning(this,tr("Path"),QString::fromLocal8Bit("未选择保存文件名"));




        QMessageBox message(QMessageBox::Warning,"提示","是否保存为图片？",QMessageBox::Yes|QMessageBox::No,NULL);
            if (message.exec()==QMessageBox::Yes)
            {
                int height = ui->webView->rect().height();
                int width = ui->webView->rect().width();
                QPixmap exportImage(width,height);
                exportImage.fill(Qt::white);
                QPainter painter(&exportImage);

                //抓取坐标轴
                QPixmap axisPixmap=QWidget::grab(QRect(ui->webView->rect()));
                painter.drawPixmap(10,10,axisPixmap);
                painter.end();
                QString file_path = QFileDialog::getSaveFileName(this, tr("Save File"),"D:/travel.png",tr("Images (*.png *.xpm *.jpg)"));
                if(!file_path.isEmpty())
                {
                    //如果没有写后缀就自动加上
                    if(QFileInfo(file_path).suffix().isEmpty())
                    file_path.append(".png");
                    exportImage.save(file_path);
                    QMessageBox::information(this,tr("成功"),QString("图片保存成功"),QMessageBox::Ok);
                }
                else
                    QMessageBox::warning(this,tr("Path"),QString::fromLocal8Bit("未选择保存文件名"));
            }
            else
            {
                qDebug()<<"clicked no\n";
            }


}

void Widget::on_historyBtn_clicked()
{
    QString filePath = "C:/Users/97202/Desktop/";
    QString strFile =  QFileDialog::getOpenFileName(0,"历史轨迹",filePath); //打开指定目录
    qDebug()<<"这是pdf的路径"<<strFile;
    QDesktopServices::openUrl(QUrl::fromLocalFile(strFile));



}

void Widget::on_gobackBtn_clicked()
{
    this->destroy();
    Main_menu *main_menu = new Main_menu(name);
    main_menu->setWindowTitle("主菜单");
    main_menu->show();
}


