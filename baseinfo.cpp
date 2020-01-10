#include "baseinfo.h"


BaseInfo::BaseInfo(QString username,QWidget *parent) : QWidget(parent)
{
    this->username=username;
    //左侧
    UserNameLabel =new QLabel(tr("用户名： "));
    UserNameLineEdit =new QLineEdit;
    UserNameLineEdit->setText(username);
    UserNameLineEdit->setEnabled(false);

    NameLabel =new QLabel(tr("姓名："));
    NameLineEdit = new QLineEdit;

    SexLabel = new QLabel(tr("性别："));
    SexComboBox =new QComboBox;
    SexComboBox->addItem(tr("女"));
    SexComboBox->addItem(tr("男"));

    DepartmentLabel =new QLabel(tr("旅游心愿："));
    DepartmentTextEdit =new QTextEdit;

    AgeLabel =new QLabel(tr("年龄："));
    AgeLineEdit =new QLineEdit;

    OtherLabel =new QLabel(tr("备注："));
    OtherLabel ->setFrameStyle(QFrame::WinPanel|QFrame::Sunken);//设置控件的风格，由形状和阴影两项配合设定

    LeftLayout =new QGridLayout();//因为不是主布局管理器，所以不用指定父窗口
    LeftLayout ->addWidget(UserNameLabel,0,0);  //用户名   向布局里加入需要的控件
    LeftLayout ->addWidget(UserNameLineEdit,0,1);

    LeftLayout->addWidget(NameLabel,1,0); //姓名
    LeftLayout->addWidget(NameLineEdit,1,1);

    LeftLayout->addWidget(SexLabel,2,0);//性别
    LeftLayout->addWidget(SexComboBox,2,1);

    LeftLayout->addWidget(DepartmentLabel,3,0);   //旅游心愿
    LeftLayout->addWidget(DepartmentTextEdit,3,1);

    LeftLayout->addWidget(AgeLabel,4,0);//年龄
    LeftLayout->addWidget(AgeLineEdit,4,1);

    LeftLayout->addWidget(OtherLabel,5,0,1,2); //其他，Widget（控件名，行，列，占用行数，占用列数）。

    LeftLayout->setColumnStretch(0,1);//设定两列分别占用空间的比例
    LeftLayout->setColumnStretch(1,3);

    //右侧
    HeadLabel =new QLabel(tr("头像："));
    HeadIconLabel =new QLabel;
    QPixmap icon("E:/fucking_program/src/app_icon.ico");
    HeadIconLabel->setPixmap(icon);
    HeadIconLabel->resize(icon.width(),icon.height());
    UpdateHeadBtn =new QPushButton(tr("更新"));

    TopRightLayout =new QHBoxLayout();//完成右上侧头像的选择区的布局
    TopRightLayout ->setSpacing(20);//设定各个控件之间的间距为20
    TopRightLayout ->addWidget(HeadLabel);
    TopRightLayout ->addWidget(HeadIconLabel);
    TopRightLayout ->addWidget(UpdateHeadBtn);

    IntroductionLabel =new QLabel(tr("个人说明："));
    IntroductionTextEdit =new QTextEdit;

    RightLayout =new QVBoxLayout();//完成右侧布局
    RightLayout ->setMargin(10);
    RightLayout ->addLayout(TopRightLayout);
    RightLayout ->addWidget(IntroductionLabel);
    RightLayout ->addWidget(IntroductionTextEdit);

    QGridLayout *mainLayout =new QGridLayout(this);//实现主布局，指定父窗口
    mainLayout->setMargin(15);//设定对话框的边距为15
    mainLayout->setSpacing(10);
    mainLayout->addLayout(LeftLayout,0,0);
    mainLayout->addLayout(RightLayout,0,1);
    mainLayout->setSizeConstraint(QLayout::SetFixedSize);//设定最优化显示
}

