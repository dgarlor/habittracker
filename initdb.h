#ifndef INITDB_H
#define INITDB_H


#include <QtSql>
#include <iostream>
#include <QtDebug>

QSqlError initDDb(QSqlDatabase &db)
{

    QStringList tables = db.tables();
    if (tables.contains("action", Qt::CaseInsensitive)
        && tables.contains("task", Qt::CaseInsensitive)
        && tables.contains("current", Qt::CaseInsensitive)
            ){
        qInfo()<<" --Already exists!";
        return QSqlError();
    }

    QSqlQuery q;
    if (!q.exec(QLatin1String("create table task(id integer primary key, name varchar)")))
        return q.lastError();
    if (!q.exec(QLatin1String("create table action(id INTEGER PRIMARY KEY, timestamp  DEFAULT CURRENT_TIMESTAMP NOT NULL, task_id INTEGER)")))
        return q.lastError();
    if (!q.exec(QLatin1String("create table current(id integer primary key, position integer, task_id integer)")))
        return q.lastError();

    // Add tasks
    if (!q.prepare(QLatin1String("insert into task(name) values(?)")))
        return q.lastError();
    q.addBindValue(QLatin1String("Eat Slowly"));
    q.exec();
    qInfo()<<" Inserted "<<q.lastInsertId();
    q.addBindValue(QLatin1String("Only news in the morning"));
    q.exec();
    qInfo()<<" Inserted "<<q.lastInsertId();
    q.addBindValue(QLatin1String("No games"));
    q.exec();
    qInfo()<<" Inserted "<<q.lastInsertId();

    // Add current
    if (!q.prepare(QLatin1String("insert into current(position,task_id) values(?,?)")))
        return q.lastError();
    q.addBindValue(QVariant(1));
    q.addBindValue(QVariant(3));
    q.exec();
    qInfo()<<" Inserted "<<q.lastInsertId();
    QVariantList second;
    q.addBindValue(QVariant(2));
    q.addBindValue(QVariant(1));
    q.exec();
    qInfo()<<" Inserted "<<q.lastInsertId();
    q.addBindValue(QVariant(3));
    q.addBindValue(QVariant(2));
    q.exec();
    qInfo()<<" Inserted "<<q.lastInsertId();

    return QSqlError();
}


#endif // INITDB_H
