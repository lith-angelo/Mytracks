#include<QLabel>
#include<QGridLayout>
#include<QLineEdit>
#include<QCheckBox>
#include<QStackedWidget>

#ifndef CONTACT_H
#define CONTACT_H

#include <QWidget>

class Contact : public QWidget
{
    Q_OBJECT
public:
    explicit Contact(QWidget *parent = 0);
private:
    QLabel *EmailLabel;
    QLineEdit *EmialLineEdit;

    QLabel *AddrLabel;
    QLineEdit *AddrLineEdit;

    QLabel *CodeLabel;
    QLineEdit *CodeLineEdit;

    QLabel *MoviTelLable;
    QLineEdit *MoviTelLineEdit;
    QCheckBox *MoviTelCheckBook;

    QLabel *ProTelLabel;
    QLineEdit *ProTelLineEdit;
    QGridLayout *mainLayout;




signals:

public slots:
};

#endif // CONTACT_H

