#include "employee.h"

Employee::Employee(QObject *parent = 0) : QObject(parent)
{
    m_lastname = "";
    m_firstname = "";
    m_id = -1;

}

QList<Employee*> Employee::getEmployees()
{
    QList<Employee*> empList;
    QEventLoop loop;
    QNetworkAccessManager mgr;
    QObject::connect(&mgr, SIGNAL(finished(QNetworkReply*)), &loop, SLOT(quit()));

    QNetworkRequest req(QUrl(QString("http://www.collisionprosoftware.com/employees.py")));
    QNetworkReply *reply = mgr.get(req);
    loop.exec();

    if(reply->error() != QNetworkReply::NoError)
        qDebug() << "Failed";
    else
    {
        QString data = QString(reply->readAll());
        QStringList lines;
        lines = data.split('\n', QString::KeepEmptyParts);

        int i;
        for (i = 0; i < lines.count(); i++)
        {
            QString line = lines[i];
            QStringList sep = line.split(",");
            QString lastname = sep[0];
            lastname = lastname.replace("\"", "", Qt::CaseInsensitive);
            qDebug() << lastname;
        }
    }
    delete reply;
    return empList;
}
