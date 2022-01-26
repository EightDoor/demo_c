#include "dicethread.h"
#include <QTime>
#include <QRandomGenerator>
#include <QMutexLocker>

DiceThread::DiceThread(QObject *parent)
    : QThread{parent}
{

}

void DiceThread::diceBegin()
{
    m_Paused = false;
}

void DiceThread::dicePause()
{
    m_Paused = true;
}

void DiceThread::stopThread()
{
    m_stop = true;
}

bool DiceThread::readValue(int *req, int *diceValue)
{
//    QMutexLocker locker(&mutex);
    if(mutex.tryLock()) {
        *req = m_seq;
        *diceValue = m_diceValue;
        mutex.unlock();
        return true;
    }
    return false;
}

void DiceThread::run()
{
    m_stop = false;
    m_seq = 0;
    while(!m_stop) {
        if(!m_Paused) {
            mutex.lock();
            m_seq ++;
            msleep(50);
            m_diceValue = 100;
            msleep(50);
            m_diceValue = 200;
            msleep(50);
            m_diceValue = QRandomGenerator::global()->bounded(1000);
            msleep(50);
            m_diceValue = QRandomGenerator::global()->bounded(6);
            mutex.unlock();
        }
        msleep(500);
    }
    quit();
}
