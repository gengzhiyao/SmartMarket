#ifndef CPPCODE_H
#define CPPCODE_H

#include <QObject>
#include<QHostAddress>
#include<QTcpSocket>
#include<QTcpServer>
#include<QTimer>
#include"gpsinfo.h"

#define M_IP "110.42.228.65"

class Cppcode : public QObject
{
    Q_OBJECT
public:
    explicit Cppcode(QObject *parent = nullptr);
    QTcpSocket *socket=NULL;

    void connect_function();
    void connected_function();
    void disconnected_function();
    void read_buf();
    void table_init();

  Q_INVOKABLE  void getData();
  Q_INVOKABLE  void getText();
  Q_INVOKABLE  QStringList setgps();
  Q_INVOKABLE  void denglu(QString name,QString num);
  Q_INVOKABLE  void setphone(QString str);


signals:
     void sendstart(int x);
     void shouData(QStringList li,int sizi);
     void shouText(QString str);
     void mcugps(QString name,QString num);

private:
     QString  phone;
     QTimer * timer=NULL;
     GPSInfo *gpsInfo;
     double nowLongitude=0.0;
     double nowLatitude=0.0;

};

#endif // CPPCODE_H
