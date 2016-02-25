#include "employee.h"

Employee::Employee(QObject *parent = 0) : QObject(parent)
{
    m_lastname = "";
    m_firstname = "";
    m_id = -1;

}

QList<Employee*>* Employee::getEmployees()
{
    QList<Employee*> *empList = NULL;
    QEventLoop loop;
    QNetworkAccessManager mgr;
    QObject::connect(&mgr, SIGNAL(finished(QNetworkReply*)), &loop, SLOT(quit()));

    QNetworkRequest req(QUrl(QString("http://www.collisionprosoftware.com/employees.py")));
    QNetworkReply *reply = mgr.get(req);
    loop.exec();

    if(reply->error() != QNetworkReply::NoError)
        return NULL;
    else
    {
        empList = new QList<Employee*>();
        QByteArray data = reply->readAll();
        QJsonDocument doc(QJsonDocument::fromJson(data));
        QJsonArray arr = doc.array();
        foreach(QJsonValue val, arr)
        {
            QJsonArray empArray = val.toArray();
            QString lastname = empArray.at(0).toString();
            QString firstname = empArray.at(1).toString();
            int empid = empArray.at(2).toInt(-1);
            if(empid == -1)
                return NULL;
            Employee *emp = new Employee();
            emp->setLastName(lastname);
            emp->setFirstName(firstname);
            emp->setId(empid);
            empList->append(emp);
        }
    }
    delete reply;
    return empList;
}
