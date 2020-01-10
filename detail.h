#include<QLabel>
#include<QComboBox>
#include<QLineEdit>
#include<QTextEdit>
#include<QGridLayout>

#ifndef DETAIL_H
#define DETAIL_H
#include <QWidget>

class Detail : public QWidget
{
    Q_OBJECT
public:
    explicit Detail(QWidget *parent = 0);
private:
    QLabel *NationalLabel;
    QComboBox *NationalComboBox;//联合布局
    QLabel *ProvinceLabel;
    QComboBox *ProvinceComboBox;
    QLabel *CityLabel;
    QLineEdit *CityLineEdit;
    QLabel *IntroductLabel;
    QTextEdit *IntroductTextEdit;
    QGridLayout *mainLayout;//网络布局


signals:

public slots:
};

#endif // DETAIL_H

