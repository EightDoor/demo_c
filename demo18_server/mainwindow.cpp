#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QHostInfo>
#include <QHostAddress>
#include <QAbstractSocket>
#include <QMessageBox>


void MainWindow::closeEvent(QCloseEvent *event)
{
    if(tcpServer->isListening()) {
        tcpServer->close();
    }

    event->accept();
}

QString MainWindow::getLocalIpA()
{
    QString hostName = QHostInfo::localHostName();
    QHostInfo hostInfo = QHostInfo::fromName(hostName);
    QString localIp = "";
    QList<QHostAddress> addList = hostInfo.addresses();
    if(addList.isEmpty()) return localIp;
    foreach(auto aHost, addList) {
        if(aHost.protocol() == QAbstractSocket::IPv4Protocol) {
              localIp = aHost.toString();
              break;
        }
    }
    return localIp;
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    labelListen = new QLabel("监听状态: ");
    labelListen->setMidLineWidth(200);
    ui->statusBar->addWidget(labelListen);
    labelSocketState = new QLabel("socket状态: ");
    labelListen->setMidLineWidth(200);
    ui->statusBar->addWidget(labelSocketState);

    setWindowTitle("服务器: " + getLocalIpA());
    tcpServer = new QTcpServer(this);

    connect(tcpServer, SIGNAL(newConnection()), this, SLOT(onNewConnected()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onNewConnected()
{
  tcpSocket = tcpServer->nextPendingConnection(); // 获取socket
  connect(tcpSocket, SIGNAL(connected()), this, SLOT(onClickConnect()));
  onClickConnect();
  connect(tcpSocket, SIGNAL(disconnected()), this, SLOT(onClickDisconnect()));
  connect(tcpSocket, SIGNAL(stateChanged(QAbstractSocket::SocketState)), this, SLOT(onClickStateChanged(QAbstractSocket::SocketState)));
  onClickStateChanged(tcpSocket->state());

  connect(tcpSocket, SIGNAL(readyRead()), this, SLOT(onSocketReadyRead()));
}


void MainWindow::on_actStart_triggered()
{
    QString Ip = ui->comboBoxIp->currentText();
    int port = ui->spinBoxPort->value();
    QHostAddress addr(Ip);

    tcpServer->listen(addr, port);
    ui->plainTextEdit->appendPlainText("**开始监听");
    ui->plainTextEdit->appendPlainText("**服务器Ip = " + tcpServer->serverAddress().toString());
    ui->plainTextEdit->appendPlainText("**服务器端口 = " + QString::number(tcpServer->serverPort()));
    ui->actStart->setEnabled(false);
    ui->actStop->setEnabled(true);

    labelListen->setText("监听状态: ing");
}


void MainWindow::on_actStop_triggered()
{
  if(tcpServer->isListening()) {
      tcpServer->close();
       ui->actStart->setEnabled(true);
       ui->actStop->setEnabled(false);
       ui->plainTextEdit->appendPlainText("**监听closed");
       labelListen->setText("监听状态: closed");
  }
}


void MainWindow::on_actClear_triggered()
{
    ui->plainTextEdit->clear();
}

void MainWindow::onClickConnect()
{
  ui->plainTextEdit->appendPlainText("**client socket connected");
  ui->plainTextEdit->appendPlainText("**peer address:" + tcpSocket->peerAddress().toString());
  ui->plainTextEdit->appendPlainText("**peer port" + QString::number(tcpSocket->peerPort()));
}

void MainWindow::onClickDisconnect()
{
 ui->plainTextEdit->appendPlainText("**client socket disconnected");
 tcpSocket->deleteLater();
}

void MainWindow::onClickStateChanged(QAbstractSocket::SocketState v)
{
    switch(v) {
     case QAbstractSocket::UnconnectedState:
        labelSocketState->setText("socket状态: UnconnectedState");
        break;
     case QAbstractSocket::HostLookupState:
        labelSocketState->setText("socket状态: HostLookupState");
        break;
    case QAbstractSocket::ConnectingState:
       labelSocketState->setText("socket状态: ConnectingState");
       break;
    case QAbstractSocket::ConnectedState:
       labelSocketState->setText("socket状态: ConnectedState");
       break;
    case QAbstractSocket::BoundState:
       labelSocketState->setText("socket状态: BoundState");
       break;
    case QAbstractSocket::ListeningState:
       labelSocketState->setText("socket状态: ListeningState");
       break;
    case QAbstractSocket::ClosingState:
       labelSocketState->setText("socket状态: ClosingState");
       break;
    }
}

void MainWindow::onSocketReadyRead()
{
    while(tcpSocket->canReadLine()) {
        ui->plainTextEdit->appendPlainText("[in]" + tcpSocket->readLine());
    }
}


void MainWindow::on_actWrite_clicked()
{
   if(!tcpSocket->isValid()) {
       QString msg = ui->lineEdit->text();
       ui->plainTextEdit->appendPlainText("[out] " + msg);
       ui->lineEdit->clear();
       ui->lineEdit->setFocus();

       QByteArray byte = msg.toUtf8();
       byte.append('\n');
       if(!tcpSocket->isValid()) {
           tcpSocket->write(byte);
       }else {
            QMessageBox::information(this, "", "当前没有其他连接，无法发送");
       }
   }else {
       QMessageBox::information(this, "", "当前没有连接");
   }
}
