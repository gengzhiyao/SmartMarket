#include "cppcode.h"
#include<QDebug>

Cppcode::Cppcode(QObject *parent) : QObject(parent)
{
    timer=new QTimer(this);

    socket=new QTcpSocket(this);
    gpsInfo = new GPSInfo(this);

    connect_function();
    timer->start(800);

}

void Cppcode::disconnected_function()
{
     timer->start(800);
     emit sendstart(2);
}

void Cppcode::getData()
{
    socket->write("2");
}

void Cppcode::getText()
{
    QString str="3"+phone;
    socket->write(str.toUtf8());
}

QStringList Cppcode::setgps()
{
    nowLongitude = gpsInfo->nowLongitude;  //精度
    nowLatitude = gpsInfo->nowLatitude;   //纬度
    QStringList li;

    li<<QString::number(nowLongitude, 'f', 7)<<QString::number(nowLatitude, 'f', 7);

    return li;
}



void Cppcode::connected_function()
{
    timer->stop();
    socket->write("100001");
    emit sendstart(1);
}

void Cppcode::connect_function()
{
    connect(socket,&QTcpSocket::connected,this,&Cppcode::connected_function);
    connect(socket,&QTcpSocket::readyRead,this,&Cppcode::read_buf);
    connect(socket,&QTcpSocket::disconnected,this,&Cppcode::disconnected_function);

    connect(timer,&QTimer::timeout,[=](){
        socket->connectToHost(QHostAddress(M_IP),8888);

    });


}

void Cppcode::read_buf()
{
    QByteArray array=socket->readLine();
    QString swi=array;
    swi.chop(1);
    int a=swi.toInt();
    switch (a)
    {
    case 1:emit sendstart(3);   //成功
        break;

    case 2: emit sendstart(4);    //失败
        break;

    case 3:table_init();
        break;

    case 4:{
       QByteArray array=socket->readAll();
       QString str=array;
       if(str.size()==0)str="空";
       emit shouText(str);
        }
        break;

    case 5:{
     QByteArray array=socket->readAll();
     QString str=array;
     //QString str="$GPGLL,2547.35222,N,11306.12283,E,111129.00,A,A*6D";
     QStringList li=str.split(",");

     emit mcugps(QString::number(li.at(3).toDouble()/100,'f', 7),
                 QString::number(li.at(1).toDouble()/100,'f', 7));
     }
        break;  
    }

    socket->readAll();
}

void Cppcode::table_init()
{
        QByteArray array=socket->readAll();
        QString array_str=array;
        array_str.replace("\n","#");

        emit shouData(array_str.split("#"),array_str.split("#").size());

}

void Cppcode::denglu(QString name, QString num)
{

    if(name.isEmpty() || num.isEmpty() || num.size()!=11)
    {
        emit sendstart(5);
        return;
    }
    socket->write(QString("1%1#%2").arg(name).arg(num).toUtf8());
}

void Cppcode::setphone(QString str)
{
    phone=str;
}


