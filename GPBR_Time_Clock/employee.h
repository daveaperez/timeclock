#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <QCoreApplication>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>
#include <QUrlQuery>

class Employee : public QObject
{

    Q_OBJECT

public:
    Employee(QObject *parent);
    static QList<Employee*> getEmployees();

    QString lastname() { return m_lastname; }
    QString firstname() { return m_firstname; }
    int id() { return m_id; }

signals:

public slots:

private:
    QString m_lastname, m_firstname;
    int m_id;

};

#endif // EMPLOYEE_H
