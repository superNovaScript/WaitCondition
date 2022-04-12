#include "producer.h"

producer::producer(QObject *parent, QMutex *mutex, QWaitCondition *valueReady, int *value)
    : QObject{parent}
{

    m_mutex =mutex;
    m_valueReady = valueReady;
    m_value = value;

}

void producer::run()
{

        qInfo()<<"Producer running";
        QThread::currentThread()->msleep(3000);

        m_mutex->lock();
        qInfo()<<"Producer creating value";
        *m_value = QRandomGenerator::global()->bounded(1000);
        qInfo()<<"Producer waking up consumer";

        m_mutex->unlock();

        m_valueReady->wakeAll();
}
