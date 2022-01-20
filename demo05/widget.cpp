#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    uchar i;
    //    qDebug() << qBound(1, 10, 20);
    qDebug("Ok:%d", qFuzzyCompare(1.00001,1.0000));

    QSet<QString> set;
    set << "dog" << "cat" << "tiger";
    if(set.contains("cat")) {
        qDebug() << "the set has cat";
    }

    QMap<QString, int> map;
    map["one"] = 1;
    map["two"] = 2;
    map["three"] = 3;
    map.insert("four", 4);
    map.remove("two");
    int num1 = map["one"];
    int num2 = map.value("two");
    int num3 = map["five"];
    int timeout = map.value("TIMEOUT", 30);
    qDebug() << num1 << num2 << num3 << timeout;

    QMultiMap<QString, int> map1, map2, map3;
    map1.insert("plenty", 100);
    map2.insert("plenty", 2000);
    map3.insert("plenty", 5000);
    map3 = map1 + map2;
    qDebug() << map3.size();
    qDebug() << "打印数据";
    QList<int> values = map3.values("plenty");
    foreach(int i, values) qDebug() << i;

    // 删除奇数项
    QList<int> list;
    list << 1 << 2 << 3 << 4 << 5;
    QMutableListIterator<int> v(list);
    while(v.hasNext()) {
        if(v.next() % 2 != 0) {
            v.remove();
        }
    }
    qDebug() << "删除奇数项";
    for(int a = 0; a < list.length(); a ++) {
        qDebug() << a;
    }

    // 删除键
    QMap<QString, QString> map10;
    map10.insert("Parial", "France");
    map10.insert("New York", "USA");
    map10.insert("Mexico City", "USA");
    map10.insert("Moscow", "Russia");

    QMutableMapIterator<QString, QString> l(map10);
    while(l.hasNext()) {
        if(l.next().key().endsWith("City")) {
            l.remove();
        }
    }

    // 顺序容器迭代器的用法
    QList<QString> list10;
    list10 << "A" << "B" << "C" << "D";
    QList<QString>::const_iterator(y);
    qDebug() << "顺序容器迭代器的用法";
    for (y = list10.constBegin(); y!=list10.constEnd(); ++y) {
        qDebug() << *y;
    }

    // 关联容器迭代器的用法
    QMap<int, int> map11;
    map11.insert(1, 11);
    map11.insert(2, 22);
    qDebug() << "关联容器迭代器的用法";
    QMap<int, int>::const_iterator(info);
    for(info = map11.constBegin(); info != map11.constEnd(); ++info) {
        qDebug() << info.key() << ":" << info.value();
    }
}

Widget::~Widget()
{
    delete ui;
}

