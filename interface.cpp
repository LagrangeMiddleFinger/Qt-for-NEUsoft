#include "interface.h"
#include "ui_interface.h"
#include "qtimer.h"
#include "qdatetime.h"

interface::interface(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::interface)
{
    ui->setupUi(this);
    timerupdate();
    QTimer *timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(timerupdate()));
    timer->start(1000);
}

interface::~interface()
{
    delete ui;
}

void interface::timerupdate(void)
{
    QDateTime time = QDateTime::currentDateTime();
    QString str = time.toString("hh:mm:ss");
    count += 1;
    ui->label_time->setText(str);
}
void interface::timerupdate2(void)
{
    QString s;
    QString m;
    QString time;
    QString h;
    int s1;
    int m1;
    int h1;
    QString s2;
    QString m2;
    QString time2;
    QString h2;
    if(count == 60)
    {
        countminute += 1;
        count = 0;
        s = QString::number(count);
        m = QString::number(countminute);
        h = QString::number(counthour);
        time = h + ":" + m + ":" + s;
    }
    else
    {
        s = QString::number(count);
        m = QString::number(countminute);
        h = QString::number(counthour);
        time = h + ":" + m + ":" + s;
    }

    if(countminute == 60)
    {
        counthour += 1;
        countminute = 0;
        s = QString::number(count);
        m = QString::number(countminute);
        h = QString::number(counthour);
        time = h + ":" + m + ":" + s;
    }
    else
    {
        s = QString::number(count);
        m = QString::number(countminute);
        h = QString::number(counthour);
        time = h + ":" + m + ":" + s;
    }
    ui->label_time_2->setText(time);

    s1 = 60 - count;
    m1 = 59 - countminute;
    h1 = 7 - counthour;
    s2 = QString::number(s1);
    m2 = QString::number(m1);
    h2 = QString::number(h1);
    time2 = h2 + ":" + m2 + ":" + s2;
    ui->label_time_3->setText(time2);
}

void secondw::on_pushButton_clicked()
{
    QTimer *timer2 = new QTimer(this);
    connect(timer2,SIGNAL(timeout()),this,SLOT(timerupdate2()));
    timer2->start(1000);
}

