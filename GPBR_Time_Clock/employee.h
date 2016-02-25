#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <QCoreApplication>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>
#include <QUrlQuery>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>

class Employee : public QObject
{

    Q_OBJECT

public:
    Employee(QObject *parent);
    static QList<Employee*>* getEmployees();

    QString lastname() { return m_lastname; }
    void setLastName(QString value) { m_lastname = value; }
    QString firstname() { return m_firstname; }
    void setFirstName(QString value) { m_firstname = value; }
    int id() { return m_id; }
    void setId(int value) { m_id = value; }

signals:

public slots:

private:
    QString m_lastname, m_firstname;
    int m_id;

};

#endif // EMPLOYEE_H
