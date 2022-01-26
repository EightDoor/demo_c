#ifndef DICETHREAD_H
#define DICETHREAD_H
#include <QThread>
#include <QMutex>

class DiceThread : public QThread
{
    Q_OBJECT
public:
    explicit DiceThread(QObject *parent = nullptr);
    void diceBegin();
    void dicePause();
    void stopThread();
    bool readValue(int *req, int *diceValue);
protected:
    void run() Q_DECL_OVERRIDE;
private:
    int m_seq = 0;
    int m_diceValue;
    bool m_stop = false;
    bool m_Paused = true;
    QMutex mutex;
public slots:

};


#endif // DICETHREAD_H
