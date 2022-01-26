#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QHostInfo>
#include <QNetworkInterface>
#include <QAbstractSocket>

QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();
private:
    QString protecoName(QAbstractSocket::NetworkLayerProtocol protocol);
private slots:
    void on_pushButton_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_4_clicked();

    void lookupHostInfo(const QHostInfo &host);
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::Dialog *ui;
};
#endif // DIALOG_H
