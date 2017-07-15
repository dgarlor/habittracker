#ifndef DATABASECONNECTION_H
#define DATABASECONNECTION_H

#include <QObject>
#include <QString>
#include <QSqlDatabase>

class DatabaseConnection : public QObject
{
    Q_OBJECT
//    Q_PROPERTY(QString taskName1 MEMBER mTaskName1 NOTIFY taskName1Changed)
//    Q_PROPERTY(QString taskName2 MEMBER mTaskName2 NOTIFY taskName2Changed)
//    Q_PROPERTY(QString taskName3 MEMBER mTaskName3 NOTIFY taskName3Changed)


public:
    //explicit DatabaseConnection(QObject *parent = 0);
    DatabaseConnection(QSqlDatabase &db);

signals:
    void insertNotified(int habit);

public slots:

    void insertEvent(const int &habit);

protected:
    QSqlDatabase database;
};

#endif // DATABASECONNECTION_H
