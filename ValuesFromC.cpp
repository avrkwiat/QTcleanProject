#include "ValuesFromC.h"

QString ValuesFromC::name() const
{
    return m_name;
}

void ValuesFromC::setName(const QString &name)
{
    if ( name == m_name )
        return;
    m_name = name;
    emit nameChanged();
}


