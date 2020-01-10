#include "content.h"

Content::Content(QString username,QWidget *parent)
    : QFrame(parent)
{
    this->username=username;
    stack =new QStackedWidget(this);//创建一个QStackedWdiget对象
    stack->setFrameStyle(QFrame::Panel|QFrame::Raised);//对堆栈窗口的显示风格进行设置
    baseInfo =new BaseInfo(username);//在堆栈窗口中插入“基本信息”，"联系方式“，”详细资料“
    contact =new Contact();
    detail =new Detail();
    stack->addWidget(baseInfo);//往stack里添加控件
    stack->addWidget(contact);
    stack->addWidget(detail);
    AmendBtn =new QPushButton(tr("修改"));
    CloseBtn =new QPushButton(tr("关闭"));
    QHBoxLayout *BtnLayout =new QHBoxLayout;//水平布局
    BtnLayout->addStretch(2);//增加伸缩量，按比例分配空间
    BtnLayout->addWidget(AmendBtn);
    BtnLayout->addWidget(CloseBtn);//这段代码用于创建两个按钮，并且利用QHBoxLayout对其进行布局

    QVBoxLayout *RightLayout =new QVBoxLayout(this);//对整体进行布局
    RightLayout->setMargin(10);//设置边缘，布局与四周的距离
    RightLayout->setSpacing(6);//设置间隔，布局与下边框的距离
    RightLayout->addWidget(stack);
    RightLayout->addLayout(BtnLayout);


}

Content::~Content()
{

}

