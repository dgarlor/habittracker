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
    DatabaseConnection(QSqlDatabase &db);

signals:

    void insertedAction(int task_id);

    void insertedTask(int task_id);

    void updatedPosition(int position);

public slots:

    void insertAction(const int task_id);

    void insertTask(const QString &name, const int position=-1);

    void updatePosition(const int task_id, const int position);

protected:
    QSqlDatabase database;
};

#endif // DATABASECONNECTION_H
