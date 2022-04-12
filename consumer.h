#ifndef CONSUMER_H
#define CONSUMER_H

#include <QObject>
#include <QWaitCondition>
#include <QMutex>
#include <QThread>
#include <QRandomGenerator>
#include <QDebug>

class consumer : public QObject
{
    Q_OBJECT
public:
    explicit consumer(QObject *parent = nullptr, QMutex *mutex =nullptr, QWaitCondition *valueReady=nullptr,int *value=nullptr);

signals:

public slots:
    void run();

private:

    QMutex *m_mutex;
    QWaitCondition *m_valueReady;
    int *m_value;
};

#endif // CONSUMER_H
