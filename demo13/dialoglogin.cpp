#include "dialoglogin.h"
#include "ui_dialoglogin.h"
#include <QMessageBox>
#include <QSettings>
#include <QCryptographicHash>
#include <QDebug>

DialogLogin::DialogLogin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogLogin)
{
    ui->setupUi(this);
    readSettings();
    setAttribute(Qt::WA_DeleteOnClose);
    setWindowFlags(Qt::SplashScreen);
}

DialogLogin::~DialogLogin()
{
    delete ui;
}

void DialogLogin::on_btnSubmit_clicked()
{
    QString user = ui->lineEditUser->text().trimmed();
    QString password = ui->lineEditPassword->text().trimmed();
    if(user == m_user && encrypt(password) == m_password) {
        writeSettings();
        accept();
    }else {
        m_tryCount ++;
        if(m_tryCount > 3) {
            QMessageBox::warning(this, "err", "错误次数过多，强行退出");
            reject();
        }else {
            QMessageBox::warning(this, "err", "用户名或者密码错误");
        }
    }
}

void DialogLogin::readSettings() {
     QSettings settings("AXB-Qt", "demo13");
     bool saved = settings.value("saved", false).toBool();
     m_user = !settings.value("UserName", "admin").toString().isEmpty() ?settings.value("UserName", "admin").toString(): "admin";
     QString defaultPassword = encrypt("123456");
     m_password = !settings.value("Password", defaultPassword).toString().isEmpty() ? settings.value("Password", defaultPassword).toString(): defaultPassword;
     if(saved) {
         ui->lineEditUser->setText(m_user);
     }

     ui->checkBox->setChecked(saved);
}

QString DialogLogin::encrypt(const QString &str)
{
    QByteArray btArray;
    btArray.append(str.toUtf8().toBase64());
    QCryptographicHash hash(QCryptographicHash::Md5);
    hash.addData(btArray);
    QByteArray resultArray =  hash.result();

    QString md5 = resultArray.toHex();
    return md5;
}

void DialogLogin::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton) {
        m_moving = true;
        m_lastPos = event->globalPos()-pos();
    }

    return QDialog::mousePressEvent(event);
}

void DialogLogin::mouseMoveEvent(QMouseEvent *event)
{
 if(m_moving && (event->buttons() && Qt::LeftButton)) {
        move(event->globalPos()-m_lastPos);
        m_lastPos = event->globalPos()-pos();
 }
 return QDialog::mouseMoveEvent(event);
}

void DialogLogin::mouseReleaseEvent(QMouseEvent *event)
{
  m_moving = false;
  return QDialog::mouseReleaseEvent(event);
}
void DialogLogin::writeSettings()
{
 QSettings settings("AXB-Qt", "demo13");
 settings.setValue("UserName", m_user);
 settings.setValue("Password", m_password);
 settings.setValue("saved", ui->checkBox->isChecked());
}

