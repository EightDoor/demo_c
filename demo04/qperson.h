#ifndef QPERSON_H
#define QPERSON_H

#include <QObject>

class QPerson : public QObject
{
    Q_OBJECT

    Q_CLASSINFO("author", "Arxibye")
    Q_CLASSINFO("company", "NCHL")
    Q_CLASSINFO("version", "1.0")
    Q_PROPERTY(unsigned age READ age WRITE setAge NOTIFY ageChanged)
    Q_PROPERTY(QString name MEMBER m_name)
    Q_PROPERTY(int score MEMBER m_score)
public:
    explicit QPerson(QString name, QObject *parent = nullptr);
    unsigned age();
    void setAge(unsigned value);
    void incAge();
private:
    unsigned m_age = 10;
    QString m_name;
    int m_score = 79;
signals:
    void ageChanged(unsigned value);
};

#endif // QPERSON_H
