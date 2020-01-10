#include<QLineEdit>
#include<QComboBox>
#include<QTextEdit>
#include<QGridLayout>
#include<QPushButton>

#ifndef BASEINFO_H
#define BASEINFO_H
#include <QWidget>
#include <QLabel>

class BaseInfo : public QWidget
{
    Q_OBJECT
public:
    explicit BaseInfo(QString username,QWidget *parent = 0);
private:
    //左侧
    QLabel *UserNameLabel;
    QLabel *NameLabel;
    QLabel *SexLabel;
    QLabel *DepartmentLabel;
    QLabel *AgeLabel;
    QLabel *OtherLabel;
    QLineEdit *UserNameLineEdit;
    QLineEdit *NameLineEdit;
    QComboBox *SexComboBox;//组合框
    QTextEdit *DepartmentTextEdit;
    QLineEdit *AgeLineEdit;
    QGridLayout *LeftLayout;//网格布局

    //右侧
    QLabel *HeadLabel; //右上角部分
    QLabel *HeadIconLabel;
    QPushButton *UpdateHeadBtn;
    QHBoxLayout *TopRightLayout;//水平盒布局

    QLabel *IntroductionLabel;
    QTextEdit *IntroductionTextEdit;
    QVBoxLayout *RightLayout;//垂直盒布局

    QString username;

signals:

public slots:
};


#endif // BASEINFO_H

