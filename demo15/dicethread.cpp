#include "dicethread.h"
#include <QTime>
#include <QRandomGenerator>

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

void DiceThread::run()
{
    m_stop = false;
    m_seq = 0;
    while(!m_stop) {
        if(!m_Paused) {
            m_diceValue = QRandomGenerator::global()->bounded(6);
            m_seq ++;
            emit newValued(m_seq, m_diceValue);
        }
        msleep(500);
    }
    quit();
}
