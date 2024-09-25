#ifndef MYGPS_H
#define MYGPS_H

#include <QObject>

class mygps : public QObject
{
    Q_OBJECT
public:
    explicit mygps(QObject *parent = nullptr);

signals:

};

#endif // MYGPS_H
