#include <QCoreApplication>
#include <QWaitCondition>
#include <QMutex>
#include <QThread>
#include <QRandomGenerator>
#include <QDebug>
#include "consumer.h"
#include "producer.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QWaitCondition valueReady;
    QMutex mutex;
    QThread producerThread;
    QThread consumerTHread;
    int value = 0;

    producer * pr = new producer(nullptr,&mutex,&valueReady,&value);
    consumer * cr = new consumer(nullptr,&mutex,&valueReady,&value);

    pr->moveToThread(&producerThread);
    cr->moveToThread(&consumerTHread);

    QObject::connect(&producerThread,&QThread::started,pr,&producer::run);
    QObject::connect(&consumerTHread,&QThread::started,cr,&consumer::run);

    producerThread.start();
    consumerTHread.start();




    return a.exec();
}
