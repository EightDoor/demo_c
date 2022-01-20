#include "qperson.h"

QPerson::QPerson(QString name, QObject *parent)
    : QObject{parent}
{
    m_name = name;
}

unsigned QPerson::age()
{
    return m_age;
}

void QPerson::setAge(unsigned value)
{
    m_age = value;
    emit ageChanged(value);
}

void QPerson::incAge()
{
  m_age ++;
  emit ageChanged(m_age);
}
