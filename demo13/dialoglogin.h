#ifndef DIALOGLOGIN_H
#define DIALOGLOGIN_H

#include <QDialog>
#include <QMouseEvent>

namespace Ui {
class DialogLogin;
}

class DialogLogin : public QDialog
{
    Q_OBJECT

public:
    explicit DialogLogin(QWidget *parent = nullptr);
    ~DialogLogin();

private slots:
    void on_btnSubmit_clicked();
private:
    QString m_user;
    QString m_password;
    int m_tryCount = 0;
    bool m_moving;
    QPoint m_lastPos;
    void writeSettings();
    void readSettings();
    QString encrypt(const QString &str);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
private:
    Ui::DialogLogin *ui;
};

#endif // DIALOGLOGIN_H
