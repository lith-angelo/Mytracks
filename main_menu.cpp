#include "main_menu.h"
#include "ui_main_menu.h"

Main_menu::Main_menu(QString name,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Main_menu)
{
    ui->setupUi(this);

    QPixmap bkgnd("E:/fucking_program/src/bgp/bgp1.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);

    ui->webView->load(QUrl("file:///C:/Users/97202/Desktop/0102code/map.html")); //导入URL。能否将html文件以资源文件添加进入


    this->name=name;



    ui->user->setText("欢迎您 "+name);
}

Main_menu::~Main_menu()
{
    delete ui;
}


//返回登陆界面
void Main_menu::on_ExitBtn_clicked()
{
    this->destroy();
    MainWindow *mainwindow = new MainWindow;
    mainwindow->setWindowTitle("欢迎来到Mytracks!");
    mainwindow->show();
}

//载入行程
void Main_menu::on_loadJourneyBtn_clicked()
{
    this->destroy();
    Widget *widget = new Widget(name);
    widget->setWindowTitle("来上传旅途照片吧~");
    widget->show();
}

//浏览记录
void Main_menu::on_viewHistoryBtn_clicked()
{
//    QString filePath = "D:/";
//    QString strFile =  QFileDialog::getOpenFileName(0,"历史轨迹",filePath); //打开指定目录
//    QDesktopServices::openUrl(QUrl::fromLocalFile(strFile));
    QString file_path = QFileDialog::getOpenFileName(this,tr("open a file."),"D:/",tr("All files(*.*)"));
        if (file_path.isEmpty()) {
            QMessageBox::warning(this, "Warning!", "Failed to open the file!");
        }

        int num = 0;
        QString str1[10];   //经度组
        QString str2[10];   //纬度组
        QString path[10];   //图片路径组
        QString des[10];    //图片描述组

        QFile aFile(file_path);
        if (!aFile.exists()) //文件不存在
            QMessageBox::warning(this,tr("warning"),QString("数据文件不存在!"),QMessageBox::Ok);
        else if (!aFile.open(QIODevice::ReadOnly | QIODevice::Text))
            QMessageBox::warning(this,tr("warning"),QString("文件打开失败!"),QMessageBox::Ok);
        else {
            QTextStream aStream(&aFile); //用文本流读取文件

            int i = 0;
            while(!aStream.atEnd()){
                QString line = aStream.readLine();
                QStringList part = line.split(",");
                str1[i] = part[0];
                str2[i] = part[1];
                des[i] = part[3];

                QString filePath = part[2];
                QString relPath = filePath.replace("D:/QT TEST/TEST/","");
                path[i] = relPath;

                i++;
            }

            num = i;

            aFile.close();//关闭文件
        }

        QWebFrame *frame = ui->webView->page()->mainFrame();

        for(int i=0;i<num;i++){
            QString method = QString("showPicture(\"%1\",\"%2\",\"%3\",\"%4\")").arg(path[i]).arg(str1[i]).arg(str2[i]).arg(des[i]);
            frame->evaluateJavaScript(method);
        }


}

//更改信息
void Main_menu::on_changeInfoBtn_clicked()
{

        QSplitter *splitterMain =new QSplitter(Qt::Horizontal,0);//水平分割窗口，作为主布局
        splitterMain->setOpaqueResize(true);//可调整大小

        QListWidget *list=new QListWidget(splitterMain);//在新建的主窗口的左侧插入一个QlistWidget作为条目选择框

        list->insertItem(0,QObject::tr("基本信息"));
        list->insertItem(1,QObject::tr("联系方式"));
        list->insertItem(1,QObject::tr("详细资料"));

        Content *content=new Content(name,splitterMain);//在水平分割窗的右侧窗口中插入content类对象

        QObject::connect(list,SIGNAL(currentRowChanged(int)),content->stack,SLOT(setCurrentIndex(int)));//连接列表框中的currentRowChanged()信号与堆栈窗的setCurrentIndex()槽函数

        splitterMain->setWindowTitle(QObject::tr("修改资料"));//主布局的标题
        splitterMain->setMinimumSize(splitterMain->minimumSize());//设置主布局框即水平分割窗的最小尺寸
        splitterMain->setMaximumSize(splitterMain->maximumSize());//设置主布局框的最大尺寸
        splitterMain->show();

}
