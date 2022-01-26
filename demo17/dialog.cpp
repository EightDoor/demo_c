#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

QString Dialog::protecoName(QAbstractSocket::NetworkLayerProtocol protocol)
{
    switch(protocol) {
        case QAbstractSocket::IPv4Protocol:
        return "Ipv4 protocol";
        break;
    case QAbstractSocket::IPv6Protocol:
    return "Ipv6 protocol";
    break;
    case QAbstractSocket::AnyIPProtocol:
    return "any protocol";
    break;
    default:
        return "Unknown Network layer Protocol";
    }
}


void Dialog::on_pushButton_clicked()
{
    QString hostName = QHostInfo::localHostName();
    ui->plainTextEdit->appendPlainText(hostName);
    QHostInfo hostinfo = QHostInfo::fromName(hostName);

    QList<QHostAddress> addList = hostinfo.addresses();
    if(addList.isEmpty()) return;

    bool show;
    foreach(auto aHost, addList) {
        if(ui->checkBox->isChecked()) {
           show = aHost.protocol() == QAbstractSocket::IPv4Protocol;
        }else {
            show = true;
        }

        if(show) {
            ui->plainTextEdit->appendPlainText(protecoName(aHost.protocol()));
            ui->plainTextEdit->appendPlainText("本机ip地址: " + aHost.toString());
            ui->plainTextEdit->appendPlainText("");
        }
    }
}


void Dialog::on_pushButton_5_clicked()
{
    ui->plainTextEdit->clear();
}


void Dialog::on_pushButton_4_clicked()
{
  // 异步的方式
  QString hostName = ui->lineEdit->text();
  ui->plainTextEdit->appendPlainText("正在查询的主机信息：" + hostName);
  QHostInfo::lookupHost(hostName, this, SLOT(lookupHostInfo(QHostInfo)));
}

void Dialog::lookupHostInfo(const QHostInfo &host)
{
    QList<QHostAddress> addList = host.addresses();
    if(addList.isEmpty()) return;

    bool show;
    foreach(auto aHost, addList) {
        if(ui->checkBox->isChecked()) {
           show = aHost.protocol() == QAbstractSocket::IPv4Protocol;
        }else {
            show = true;
        }

        if(show) {
            ui->plainTextEdit->appendPlainText(protecoName(aHost.protocol()));
            ui->plainTextEdit->appendPlainText("ip地址: " + aHost.toString());
            ui->plainTextEdit->appendPlainText("");
        }
    }
}


void Dialog::on_pushButton_2_clicked()
{
    QList<QHostAddress> addList = QNetworkInterface::allAddresses();
    if(addList.isEmpty()) return;

    bool show;
    foreach(auto aHost, addList) {
        if(ui->checkBox->isChecked()) {
           show = aHost.protocol() == QAbstractSocket::IPv4Protocol;
        }else {
            show = true;
        }

        if(show) {
            ui->plainTextEdit->appendPlainText(protecoName(aHost.protocol()));
            ui->plainTextEdit->appendPlainText("ip地址: " + aHost.toString());
            ui->plainTextEdit->appendPlainText("");
        }
    }
}


void Dialog::on_pushButton_3_clicked()
{
    QList<QNetworkInterface> list = QNetworkInterface::allInterfaces();
    foreach(auto aInterface, list) {
        if(!aInterface.isValid()) return;

        ui->plainTextEdit->appendPlainText("设备名称: " + aInterface.humanReadableName());
        ui->plainTextEdit->appendPlainText("硬件地址: " + aInterface.hardwareAddress());
        QList<QNetworkAddressEntry> entryList = aInterface.addressEntries();
        foreach(auto aEntry, entryList) {
            ui->plainTextEdit->appendPlainText("IP地址: " + aEntry.ip().toString());
            ui->plainTextEdit->appendPlainText("子网掩码: " + aEntry.netmask().toString());
            ui->plainTextEdit->appendPlainText("广播地址: " + aEntry.broadcast().toString());
        }

        ui->plainTextEdit->appendPlainText("");
    }
}

