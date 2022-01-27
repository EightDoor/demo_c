#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QTcpServer>
#include <QLabel>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

protected:
    void closeEvent(QCloseEvent *event);
private:
    QLabel *labelListen;
    QLabel *labelSocketState;
    QTcpServer *tcpServer;
    QTcpSocket *tcpSocket;
    QString getLocalIpA();
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void onNewConnected();
    void on_actStart_triggered();

    void on_actStop_triggered();

    void on_actClear_triggered();

    void onClickConnect();
    void onClickDisconnect();
    void onClickStateChanged(QAbstractSocket::SocketState v);
    void onSocketReadyRead();

    void on_actWrite_clicked();
private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
