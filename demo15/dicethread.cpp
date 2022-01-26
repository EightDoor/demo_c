#include "dicethread.h"
#include <QTime>
#include <QRandomGenerator>

DiceThread::DiceThread(QObject *parent)
    : QThread{parent}
{
  m_stop = false;
  m_seq = 0;
  while(!m_stop) {
      if(!m_Paused) {
          m_diceValue = QRandomGenerator::global()->bounded(10);
          m_seq ++;
          emit newValued(m_seq, m_diceValue);
      }
  }
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

}
