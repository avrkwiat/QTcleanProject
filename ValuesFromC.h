#ifndef ValuesFromC_H
#define ValuesFromC_H

#include <QObject>
#include <QDate>

class ValuesFromC : public QObject
{
    Q_OBJECT
    Q_PROPERTY( QString name READ name WRITE setName NOTIFY nameChanged )

public:
    QString name() const;
    void setName(const QString& name );
signals:
    void nameChanged();
private:
    QString m_name;
};

#endif // ValuesFromC_H
