#ifndef DATABASECONNECTION_H
#define DATABASECONNECTION_H

#include <QObject>
#include <QString>


class DatabaseConnection : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString taskName1 MEMBER mTaskName1 NOTIFY taskName1Changed)
    Q_PROPERTY(QString taskName2 MEMBER mTaskName2 NOTIFY taskName2Changed)
    Q_PROPERTY(QString taskName3 MEMBER mTaskName3 NOTIFY taskName3Changed)


public:
    explicit DatabaseConnection(QObject *parent = 0);

signals:
    void insertNotified(int habit);
    void taskName1Changed(const QString &newName);
    void taskName2Changed(const QString &newName);
    void taskName3Changed(const QString &newName);

public slots:

    void insertEvent(const int &habit);

protected:
    QString mTaskName1;
    QString mTaskName2;
    QString mTaskName3;

};

#endif // DATABASECONNECTION_H
