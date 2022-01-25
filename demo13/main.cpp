#include "mainwindow.h"

#include <QApplication>
#include <dialoglogin.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DialogLogin *dlg = new DialogLogin;
    if(dlg->exec() == QDialog::Accepted) {
        MainWindow w;
        w.show();
        return a.exec();
    }
    return 0;
}
