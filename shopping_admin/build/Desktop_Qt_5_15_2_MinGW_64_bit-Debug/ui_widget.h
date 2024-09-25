/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QGridLayout *gridLayout_3;
    QTabWidget *tabWidget;
    QWidget *tab_2;
    QGridLayout *gridLayout_2;
    QWidget *widget_2;
    QGridLayout *gridLayout;
    QWidget *widget_8;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *pushButton_4;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_12;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_5;
    QTableWidget *tableWidget;
    QWidget *widget_6;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QPushButton *pushButton_11;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QLineEdit *lineEdit_2;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QLineEdit *lineEdit_3;
    QWidget *widget_9;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *pushButton_3;
    QWidget *widget_7;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QLineEdit *lineEdit_4;
    QWidget *tab;
    QGridLayout *gridLayout_4;
    QSpacerItem *verticalSpacer;
    QWidget *widget_15;
    QHBoxLayout *horizontalLayout_12;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QLabel *label_9;
    QTableWidget *tableWidget_2;
    QLabel *label_10;
    QWidget *tab_3;
    QWidget *widget_14;
    QVBoxLayout *verticalLayout;
    QWidget *widget_11;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_6;
    QLabel *label_7;
    QLineEdit *lineEdit_7;
    QPushButton *pushButton_7;
    QWidget *widget_10;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_5;
    QLineEdit *lineEdit_6;
    QWidget *widget_13;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_8;
    QLineEdit *lineEdit_9;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label;
    QLineEdit *lineEdit_5;
    QWidget *widget_12;
    QHBoxLayout *horizontalLayout_10;
    QPushButton *pushButton_6;
    QWidget *tab_4;
    QGridLayout *gridLayout_5;
    QTextEdit *textEdit;
    QLabel *label_12;
    QLabel *label_11;
    QWidget *widget_16;
    QHBoxLayout *horizontalLayout_13;
    QPushButton *pushButton_10;
    QLabel *label_13;
    QWidget *tab_5;
    QGridLayout *gridLayout_6;
    QLabel *label_15;
    QLabel *label_14;
    QTextEdit *textEdit_2;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(1124, 962);
        Widget->setStyleSheet(QString::fromUtf8("/**\346\255\243\345\270\270\346\203\205\345\206\265\344\270\213\346\240\267\345\274\217**/\n"
"QPushButton{\n"
"	font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"    color: #2f3640;\n"
"    background-color: #f5f6fa;\n"
"    border-color: #2f3640;\n"
"    border-radius: 15px;\n"
"    border-style: solid;\n"
"    border-width: 2px;\n"
"    padding: 5px;\n"
"}\n"
"\n"
"/**\351\274\240\346\240\207\345\201\234\347\225\231\345\234\250\346\214\211\351\222\256\344\270\212\347\232\204\346\240\267\345\274\217**/\n"
"QPushButton::hover{	\n"
"    color: #FFFFFF;\n"
"    background-color: #718093;\n"
"    border-color: #2f3640;\n"
"}\n"
"\n"
"/**\351\274\240\346\240\207\346\214\211\345\216\213\344\270\213\345\216\273\347\232\204\346\240\267\345\274\217**/\n"
"QPushButton::pressed,QPushButton::checked{\n"
"    color: #FFFFFF;\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 #273c75, stop:1 #487eb0);\n"
"}\n"
"\n"
"/**\346\214\211\351\222\256\345\244\261\350\203\275\346"
                        "\203\205\345\206\265\344\270\213\346\240\267\345\274\217**/\n"
"QPushButton::disabled{\n"
"    color: #FFFFFF;\n"
"    background-color: #dcdde1;\n"
"    border-color: #dcdde1;\n"
"}"));
        gridLayout_3 = new QGridLayout(Widget);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        tabWidget = new QTabWidget(Widget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setStyleSheet(QString::fromUtf8("QTabWidget::tab-bar { \n"
"	alignment: center; \n"
"} \n"
"\n"
"\n"
"\n"
"QTabBar::tab {\n"
"     background: gray;\n"
"     /*border: 2px solid #C4C4C3;*/\n"
"     border-bottom-color: #C2C7CB;\n"
"     border-top-left-radius: 8px;\n"
"     border-top-right-radius: 8px;\n"
"     min-width: 150px;\n"
"     min-height: 50px;\n"
"     padding: 15px;\n"
"font: italic 12pt \"Lucida Sans Typewriter\";\n"
" }\n"
"\n"
"QTabBar::tab:selected{\n"
"    background:qlineargradient(spread:pad,x1:0,y1:0,x2:0,y2:1,stop:0 #626262,stop:1 #545454);\n"
"}\n"
"\n"
"QTabBar::tab:!selected{\n"
"    margin-top:5px;\n"
"}\n"
"/*\345\233\233\344\270\252\344\270\213\345\261\236\347\225\214\351\235\242*/\n"
""));
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        gridLayout_2 = new QGridLayout(tab_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        widget_2 = new QWidget(tab_2);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        gridLayout = new QGridLayout(widget_2);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        widget_8 = new QWidget(widget_2);
        widget_8->setObjectName(QString::fromUtf8("widget_8"));
        horizontalLayout_5 = new QHBoxLayout(widget_8);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        pushButton_4 = new QPushButton(widget_8);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setMinimumSize(QSize(180, 60));
        pushButton_4->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout_5->addWidget(pushButton_4);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_2);

        pushButton_12 = new QPushButton(widget_8);
        pushButton_12->setObjectName(QString::fromUtf8("pushButton_12"));
        pushButton_12->setMinimumSize(QSize(180, 60));
        pushButton_12->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout_5->addWidget(pushButton_12);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer);

        pushButton_5 = new QPushButton(widget_8);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setMinimumSize(QSize(120, 60));
        pushButton_5->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_5->addWidget(pushButton_5);


        gridLayout->addWidget(widget_8, 2, 0, 1, 1);

        tableWidget = new QTableWidget(widget_2);
        if (tableWidget->columnCount() < 4)
            tableWidget->setColumnCount(4);
        QFont font;
        font.setPointSize(12);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setFont(font);
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setFont(font);
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setFont(font);
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        __qtablewidgetitem3->setFont(font);
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setMinimumSize(QSize(0, 300));
        tableWidget->setMaximumSize(QSize(16777215, 45654));
        tableWidget->setStyleSheet(QString::fromUtf8("QScrollBar::add-page:vertical, QScrollBar::sub-page:vertical \n"
"{\n"
"    background:rgba(255,255,255,10%);                            \n"
"}\n"
"\n"
"QScollBar::add-line:vertical, QScrollBar::sub-line:vertical  \n"
"{\n"
"    background:transparent;                                      \n"
"}\n"
""));

        gridLayout->addWidget(tableWidget, 1, 0, 1, 1);

        widget_6 = new QWidget(widget_2);
        widget_6->setObjectName(QString::fromUtf8("widget_6"));
        verticalLayout_2 = new QVBoxLayout(widget_6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        widget_3 = new QWidget(widget_6);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        horizontalLayout = new QHBoxLayout(widget_3);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_2 = new QLabel(widget_3);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(0, 50));
        label_2->setStyleSheet(QString::fromUtf8("font: 13pt \"\351\273\221\344\275\223\";"));

        horizontalLayout->addWidget(label_2);

        lineEdit = new QLineEdit(widget_3);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setMinimumSize(QSize(80, 50));
        lineEdit->setStyleSheet(QString::fromUtf8("font: italic 12pt \"Lucida Sans Typewriter\";"));
        lineEdit->setReadOnly(false);

        horizontalLayout->addWidget(lineEdit);

        pushButton_11 = new QPushButton(widget_3);
        pushButton_11->setObjectName(QString::fromUtf8("pushButton_11"));
        pushButton_11->setMinimumSize(QSize(120, 50));
        pushButton_11->setMaximumSize(QSize(80, 30));

        horizontalLayout->addWidget(pushButton_11);


        verticalLayout_2->addWidget(widget_3);

        widget_4 = new QWidget(widget_6);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        horizontalLayout_2 = new QHBoxLayout(widget_4);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_3 = new QLabel(widget_4);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMinimumSize(QSize(0, 50));
        label_3->setStyleSheet(QString::fromUtf8("font: 13pt \"\351\273\221\344\275\223\";"));

        horizontalLayout_2->addWidget(label_3);

        lineEdit_2 = new QLineEdit(widget_4);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setMinimumSize(QSize(0, 50));
        lineEdit_2->setStyleSheet(QString::fromUtf8("font: italic 12pt \"Lucida Sans Typewriter\";"));

        horizontalLayout_2->addWidget(lineEdit_2);


        verticalLayout_2->addWidget(widget_4);

        widget_5 = new QWidget(widget_6);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        horizontalLayout_3 = new QHBoxLayout(widget_5);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_4 = new QLabel(widget_5);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMinimumSize(QSize(0, 50));
        label_4->setStyleSheet(QString::fromUtf8("font: 13pt \"\351\273\221\344\275\223\";"));

        horizontalLayout_3->addWidget(label_4);

        lineEdit_3 = new QLineEdit(widget_5);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setMinimumSize(QSize(0, 50));
        lineEdit_3->setStyleSheet(QString::fromUtf8("font: italic 12pt \"Lucida Sans Typewriter\";"));

        horizontalLayout_3->addWidget(lineEdit_3);


        verticalLayout_2->addWidget(widget_5);

        widget_9 = new QWidget(widget_6);
        widget_9->setObjectName(QString::fromUtf8("widget_9"));
        widget_9->setMinimumSize(QSize(130, 70));
        widget_9->setMaximumSize(QSize(16777215, 60));
        widget_9->setLayoutDirection(Qt::LeftToRight);
        horizontalLayout_6 = new QHBoxLayout(widget_9);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        pushButton_3 = new QPushButton(widget_9);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setMinimumSize(QSize(120, 50));
        pushButton_3->setMaximumSize(QSize(80, 30));

        horizontalLayout_6->addWidget(pushButton_3);


        verticalLayout_2->addWidget(widget_9);

        widget_7 = new QWidget(widget_6);
        widget_7->setObjectName(QString::fromUtf8("widget_7"));
        widget_7->setMinimumSize(QSize(0, 75));
        horizontalLayout_4 = new QHBoxLayout(widget_7);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        pushButton_2 = new QPushButton(widget_7);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setMinimumSize(QSize(120, 60));

        horizontalLayout_4->addWidget(pushButton_2);

        pushButton = new QPushButton(widget_7);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setMinimumSize(QSize(120, 60));

        horizontalLayout_4->addWidget(pushButton);

        lineEdit_4 = new QLineEdit(widget_7);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        lineEdit_4->setMinimumSize(QSize(0, 50));
        lineEdit_4->setStyleSheet(QString::fromUtf8("font: italic 13pt \"Lucida Sans Typewriter\";"));

        horizontalLayout_4->addWidget(lineEdit_4);


        verticalLayout_2->addWidget(widget_7);


        gridLayout->addWidget(widget_6, 0, 0, 1, 1);


        gridLayout_2->addWidget(widget_2, 0, 0, 1, 1);

        tabWidget->addTab(tab_2, QString());
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        gridLayout_4 = new QGridLayout(tab);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        verticalSpacer = new QSpacerItem(1, 30, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_4->addItem(verticalSpacer, 4, 0, 1, 1);

        widget_15 = new QWidget(tab);
        widget_15->setObjectName(QString::fromUtf8("widget_15"));
        widget_15->setMinimumSize(QSize(0, 75));
        horizontalLayout_12 = new QHBoxLayout(widget_15);
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        pushButton_8 = new QPushButton(widget_15);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
        pushButton_8->setMinimumSize(QSize(120, 60));
        pushButton_8->setMaximumSize(QSize(180, 80));

        horizontalLayout_12->addWidget(pushButton_8);

        pushButton_9 = new QPushButton(widget_15);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));
        pushButton_9->setMinimumSize(QSize(180, 60));
        pushButton_9->setMaximumSize(QSize(200, 80));
        pushButton_9->setSizeIncrement(QSize(200, 80));

        horizontalLayout_12->addWidget(pushButton_9);


        gridLayout_4->addWidget(widget_15, 3, 0, 1, 1);

        label_9 = new QLabel(tab);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setMinimumSize(QSize(0, 50));

        gridLayout_4->addWidget(label_9, 0, 0, 1, 1);

        tableWidget_2 = new QTableWidget(tab);
        if (tableWidget_2->columnCount() < 4)
            tableWidget_2->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        __qtablewidgetitem4->setFont(font);
        tableWidget_2->setHorizontalHeaderItem(0, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        __qtablewidgetitem5->setFont(font);
        tableWidget_2->setHorizontalHeaderItem(1, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        __qtablewidgetitem6->setFont(font);
        tableWidget_2->setHorizontalHeaderItem(2, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        __qtablewidgetitem7->setFont(font);
        tableWidget_2->setHorizontalHeaderItem(3, __qtablewidgetitem7);
        tableWidget_2->setObjectName(QString::fromUtf8("tableWidget_2"));
        tableWidget_2->setMinimumSize(QSize(0, 600));
        tableWidget_2->setMaximumSize(QSize(16777215, 600));
        tableWidget_2->setStyleSheet(QString::fromUtf8("QScrollBar::add-page:vertical, QScrollBar::sub-page:vertical \n"
"{\n"
"    background:rgba(255,255,255,10%);                            \n"
"}\n"
"\n"
"QScollBar::add-line:vertical, QScrollBar::sub-line:vertical  \n"
"{\n"
"    background:transparent;                                      \n"
"}\n"
""));

        gridLayout_4->addWidget(tableWidget_2, 1, 0, 1, 1);

        label_10 = new QLabel(tab);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setMinimumSize(QSize(0, 30));

        gridLayout_4->addWidget(label_10, 2, 0, 1, 1);

        tabWidget->addTab(tab, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        widget_14 = new QWidget(tab_3);
        widget_14->setObjectName(QString::fromUtf8("widget_14"));
        widget_14->setGeometry(QRect(280, 80, 521, 571));
        verticalLayout = new QVBoxLayout(widget_14);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget_11 = new QWidget(widget_14);
        widget_11->setObjectName(QString::fromUtf8("widget_11"));
        horizontalLayout_9 = new QHBoxLayout(widget_11);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        label_6 = new QLabel(widget_11);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setMinimumSize(QSize(0, 50));

        horizontalLayout_9->addWidget(label_6);

        label_7 = new QLabel(widget_11);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setMinimumSize(QSize(0, 50));
        label_7->setStyleSheet(QString::fromUtf8("font: 13pt \"\351\273\221\344\275\223\";"));

        horizontalLayout_9->addWidget(label_7);

        lineEdit_7 = new QLineEdit(widget_11);
        lineEdit_7->setObjectName(QString::fromUtf8("lineEdit_7"));
        lineEdit_7->setMinimumSize(QSize(150, 50));
        lineEdit_7->setStyleSheet(QString::fromUtf8("font: italic 12pt \"Lucida Sans Typewriter\";"));
        lineEdit_7->setReadOnly(false);

        horizontalLayout_9->addWidget(lineEdit_7);

        pushButton_7 = new QPushButton(widget_11);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        pushButton_7->setMinimumSize(QSize(100, 50));

        horizontalLayout_9->addWidget(pushButton_7);


        verticalLayout->addWidget(widget_11);

        widget_10 = new QWidget(widget_14);
        widget_10->setObjectName(QString::fromUtf8("widget_10"));
        horizontalLayout_8 = new QHBoxLayout(widget_10);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_5 = new QLabel(widget_10);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setMinimumSize(QSize(0, 50));
        label_5->setStyleSheet(QString::fromUtf8("font: 13pt \"\351\273\221\344\275\223\";"));

        horizontalLayout_8->addWidget(label_5);

        lineEdit_6 = new QLineEdit(widget_10);
        lineEdit_6->setObjectName(QString::fromUtf8("lineEdit_6"));
        lineEdit_6->setMinimumSize(QSize(0, 50));
        lineEdit_6->setStyleSheet(QString::fromUtf8("font: italic 12pt \"Lucida Sans Typewriter\";"));

        horizontalLayout_8->addWidget(lineEdit_6);


        verticalLayout->addWidget(widget_10);

        widget_13 = new QWidget(widget_14);
        widget_13->setObjectName(QString::fromUtf8("widget_13"));
        horizontalLayout_11 = new QHBoxLayout(widget_13);
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        label_8 = new QLabel(widget_13);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setMinimumSize(QSize(0, 50));
        label_8->setStyleSheet(QString::fromUtf8("font: 13pt \"\351\273\221\344\275\223\";"));

        horizontalLayout_11->addWidget(label_8);

        lineEdit_9 = new QLineEdit(widget_13);
        lineEdit_9->setObjectName(QString::fromUtf8("lineEdit_9"));
        lineEdit_9->setMinimumSize(QSize(0, 50));
        lineEdit_9->setStyleSheet(QString::fromUtf8("font: italic 12pt \"Lucida Sans Typewriter\";"));

        horizontalLayout_11->addWidget(lineEdit_9);


        verticalLayout->addWidget(widget_13);

        widget = new QWidget(widget_14);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout_7 = new QHBoxLayout(widget);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(0, 50));
        label->setStyleSheet(QString::fromUtf8("font: 13pt \"\351\273\221\344\275\223\";"));

        horizontalLayout_7->addWidget(label);

        lineEdit_5 = new QLineEdit(widget);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));
        lineEdit_5->setMinimumSize(QSize(0, 50));
        lineEdit_5->setStyleSheet(QString::fromUtf8("font: italic 12pt \"Lucida Sans Typewriter\";"));

        horizontalLayout_7->addWidget(lineEdit_5);


        verticalLayout->addWidget(widget);

        widget_12 = new QWidget(widget_14);
        widget_12->setObjectName(QString::fromUtf8("widget_12"));
        horizontalLayout_10 = new QHBoxLayout(widget_12);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        pushButton_6 = new QPushButton(widget_12);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setMinimumSize(QSize(100, 80));
        pushButton_6->setMaximumSize(QSize(120, 16777215));

        horizontalLayout_10->addWidget(pushButton_6);


        verticalLayout->addWidget(widget_12);

        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        gridLayout_5 = new QGridLayout(tab_4);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        textEdit = new QTextEdit(tab_4);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setMaximumSize(QSize(16777215, 800));
        textEdit->setSizeIncrement(QSize(0, 800));
        textEdit->setStyleSheet(QString::fromUtf8("QTextEdit#textEdit\n"
"{\n"
"	background:rgba(0,0,0,0.1);\n"
"	color:rgba(255,100,255,0.8);\n"
" \n"
"	border-radius:2px;\n"
"	border:none;\n"
"	font-size:20px;\n"
"	font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}\n"
" \n"
"QScrollBar:vertical\n"
"{\n"
"       border: none;\n"
"       background: transparent;\n"
"       width: 6px;\n"
"}\n"
" \n"
"QScrollBar::handle:vertical\n"
"{\n"
"       background-color: rgba(255,255,255,1);\n"
"       min-height: 30px;\n"
"	  border-radius:3px;\n"
"	  width: 6px;\n"
"   }\n"
" \n"
"QScrollBar::add-line:vertical\n"
"{\n"
"       border: none;\n"
"       height: 0px;\n"
" }\n"
" \n"
" QScrollBar::sub-line:vertical\n"
"{\n"
"       border: none;\n"
"       height: 0px;\n"
"}\n"
" \n"
" QScrollBar::add-page:vertical,QScrollBar::sub-page:vertical\n"
" {	\n"
"	background:transparent;\n"
"      border-radius:3px;\n"
"}"));
        textEdit->setReadOnly(true);

        gridLayout_5->addWidget(textEdit, 1, 0, 1, 1);

        label_12 = new QLabel(tab_4);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setMinimumSize(QSize(0, 20));

        gridLayout_5->addWidget(label_12, 0, 0, 1, 1);

        label_11 = new QLabel(tab_4);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setMinimumSize(QSize(0, 40));

        gridLayout_5->addWidget(label_11, 2, 0, 1, 1);

        widget_16 = new QWidget(tab_4);
        widget_16->setObjectName(QString::fromUtf8("widget_16"));
        horizontalLayout_13 = new QHBoxLayout(widget_16);
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        pushButton_10 = new QPushButton(widget_16);
        pushButton_10->setObjectName(QString::fromUtf8("pushButton_10"));
        pushButton_10->setMinimumSize(QSize(160, 80));
        pushButton_10->setMaximumSize(QSize(160, 16777215));

        horizontalLayout_13->addWidget(pushButton_10);


        gridLayout_5->addWidget(widget_16, 3, 0, 1, 1);

        label_13 = new QLabel(tab_4);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setMinimumSize(QSize(0, 40));

        gridLayout_5->addWidget(label_13, 4, 0, 1, 1);

        tabWidget->addTab(tab_4, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QString::fromUtf8("tab_5"));
        gridLayout_6 = new QGridLayout(tab_5);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        label_15 = new QLabel(tab_5);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setMinimumSize(QSize(0, 80));

        gridLayout_6->addWidget(label_15, 2, 0, 1, 1);

        label_14 = new QLabel(tab_5);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setMinimumSize(QSize(100, 20));

        gridLayout_6->addWidget(label_14, 0, 0, 1, 1);

        textEdit_2 = new QTextEdit(tab_5);
        textEdit_2->setObjectName(QString::fromUtf8("textEdit_2"));
        textEdit_2->setStyleSheet(QString::fromUtf8("QTextEdit { background-color: #F2F4F9; font-size: 20px; color: #16181A; font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";border: 2px solid rgba(15, 38, 77, 0.12);color:rgba(255,100,255,0.8); }"));
        textEdit_2->setReadOnly(true);

        gridLayout_6->addWidget(textEdit_2, 1, 0, 1, 1);

        tabWidget->addTab(tab_5, QString());

        gridLayout_3->addWidget(tabWidget, 0, 0, 1, 1);


        retranslateUi(Widget);

        tabWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        pushButton_4->setText(QCoreApplication::translate("Widget", "\345\210\240\351\231\244\345\205\250\351\203\250\344\274\232\345\221\230\346\266\210\346\201\257", nullptr));
        pushButton_12->setText(QCoreApplication::translate("Widget", "\346\233\264\346\226\260\344\274\232\345\221\230\346\266\210\346\201\257", nullptr));
        pushButton_5->setText(QCoreApplication::translate("Widget", "\346\263\250\351\224\200\345\215\241", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("Widget", "\345\215\241\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("Widget", "\345\247\223\345\220\215", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("Widget", "\347\224\265\350\257\235", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("Widget", "\344\275\231\351\242\235", nullptr));
        label_2->setText(QCoreApplication::translate("Widget", "\345\215\241\345\217\267:", nullptr));
        lineEdit->setText(QString());
        pushButton_11->setText(QCoreApplication::translate("Widget", "\350\257\267\346\261\202\350\265\204\346\272\220", nullptr));
        label_3->setText(QCoreApplication::translate("Widget", "\345\247\223\345\220\215:", nullptr));
        lineEdit_2->setText(QString());
        label_4->setText(QCoreApplication::translate("Widget", "\347\224\265\350\257\235:", nullptr));
        lineEdit_3->setText(QString());
        pushButton_3->setText(QCoreApplication::translate("Widget", "\346\263\250\345\206\214", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Widget", "\346\237\245\350\257\242", nullptr));
        pushButton->setText(QCoreApplication::translate("Widget", "\345\205\205\345\200\274", nullptr));
        lineEdit_4->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("Widget", "\344\274\232\345\221\230\345\215\241\347\256\241\347\220\206", nullptr));
        pushButton_8->setText(QCoreApplication::translate("Widget", "\346\233\264\346\226\260", nullptr));
        pushButton_9->setText(QCoreApplication::translate("Widget", "\345\210\240\351\231\244", nullptr));
        label_9->setText(QString());
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget_2->horizontalHeaderItem(0);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("Widget", "\347\274\226\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget_2->horizontalHeaderItem(1);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("Widget", "\345\220\215\347\247\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget_2->horizontalHeaderItem(2);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("Widget", "\344\273\267\346\240\274", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget_2->horizontalHeaderItem(3);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("Widget", "\345\223\201\347\211\214", nullptr));
        label_10->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("Widget", "\345\234\250\345\224\256\345\225\206\345\223\201\346\237\245\350\257\242", nullptr));
        label_6->setText(QString());
        label_7->setText(QCoreApplication::translate("Widget", "\345\225\206\345\223\201\347\274\226\345\217\267: ", nullptr));
        lineEdit_7->setText(QString());
        pushButton_7->setText(QCoreApplication::translate("Widget", "\346\211\253\347\240\201\345\215\241\345\217\267", nullptr));
        label_5->setText(QCoreApplication::translate("Widget", "\345\225\206\345\223\201\345\220\215\347\247\260:", nullptr));
        label_8->setText(QCoreApplication::translate("Widget", "\345\225\206\345\223\201\344\273\267\346\240\274:", nullptr));
        label->setText(QCoreApplication::translate("Widget", "\345\225\206\345\223\201\345\223\201\347\211\214:", nullptr));
        pushButton_6->setText(QCoreApplication::translate("Widget", "\346\267\273\345\212\240\345\225\206\345\223\201", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("Widget", "\346\267\273\345\212\240\346\226\260\345\225\206\345\223\201", nullptr));
        label_12->setText(QString());
        label_11->setText(QString());
        pushButton_10->setText(QCoreApplication::translate("Widget", "\351\224\200\345\224\256\350\256\260\345\275\225", nullptr));
        label_13->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QCoreApplication::translate("Widget", "\351\224\200\345\224\256\350\256\260\345\275\225", nullptr));
        label_15->setText(QString());
        label_14->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QCoreApplication::translate("Widget", "\346\227\245\345\277\227", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
