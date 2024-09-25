#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include"dialog.h"
#include<QMessageBox>
#include<QTcpSocket>
#include<QTimer>
#include<QDebug>
#include<QHostAddress>
#include<QTableWidgetItem>

#define M_IP "110.42.228.65"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    void myconnect();
    void disconnected_function();
    void read_buf();
    void connected_function();
    void table1_Init(int row,QString str);
    void table2_Init(int row,QString str);
    void any_init();

    void case1_getcode();
    void case2_commodity_zhuce();
    void case3_admin_zhuce();
    void case4_chongzhi();
    void case5_select();
    void case6_commodity_add();
    void case7_text1();
    void case8_admin_init();
    void case9_commodity_init();
    void case10_error();
    void case11_text2();
private slots:

    void on_pushButton_3_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_9_clicked();
    void on_pushButton_11_clicked();
    void on_pushButton_7_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_10_clicked();
    void on_pushButton_8_clicked(); 
    void on_pushButton_12_clicked();

private:

    LoadingDialog *dial=NULL;
    QTimer  *timer=NULL;
    QTcpSocket * socket=NULL;

    Ui::Widget *ui;
};
#endif // WIDGET_H
