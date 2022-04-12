#ifndef PRODUCER_H
#define PRODUCER_H

#include <QObject>
#include <QWaitCondition>
#include <QMutex>
#include <QThread>
#include <QRandomGenerator>
#include <QDebug>

class producer : public QObject
{
    Q_OBJECT
public:
    explicit producer(QObject *parent = nullptr, QMutex *mutex =nullptr, QWaitCondition *valueReady=nullptr,int *value=nullptr);

signals:

public slots:
    void run();

private:
   QMutex *m_mutex;
   QWaitCondition *m_valueReady;
   int *m_value;

};

#endif // PRODUCER_H
