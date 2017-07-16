#include "databaseconnection.h"
#include <QtDebug>
#include <QtSql>
#include <iostream>
using namespace std;

// SQL COMMANDS
static const char *SQL_INSERT_ACTION="INSERT INTO action(task_id) VALUES(?)";
static const char *SQL_INSERT_TASK = "insert into task(name) values(?)";
static const char *SQL_UPDATE_POSITION = "UPDATE current SET task_id = ? WHERE position = ?";

DatabaseConnection::DatabaseConnection(QSqlDatabase &db) :
    QObject(0), database(db)
{
}

void DatabaseConnection::insertAction(const int task_id){
   if( !database.open())
   {
       qInfo()<<"ERROR: Database is not open"<<endl;
       return;
   }

   QSqlQuery q;
   if (!q.prepare(QLatin1String(SQL_INSERT_ACTION))){
       qInfo()<<"ERROR: preparation command: "<< q.lastError();
       return;
   }

   q.addBindValue(task_id);
   if(!q.exec()){
       qInfo()<<"ERROR: Problem executing insert"<<endl;
       qInfo()<<q.lastError()<<endl;
       return;
   }

   qInfo()<<" Inserted Action: "<<q.lastInsertId();
   emit insertedAction(task_id);
}

void DatabaseConnection::insertTask(const QString &name, const int position){

    if( !database.open())
    {
        qInfo()<<"ERROR: Database is not open"<<endl;
        return;
    }
    // Insert task into the table
    QSqlQuery q;
    if (!q.prepare(QLatin1String(SQL_INSERT_TASK))){
        qInfo()<<"ERROR: preparation command: "<< q.lastError();
        return;
    }

    q.addBindValue(name);
    if(!q.exec()){
        qInfo()<<"ERROR: Problem executing insert"<<endl;
        qInfo()<<q.lastError()<<endl;
        return;
    }

    qInfo()<<" Inserted Task: "<<q.lastInsertId();
    int task_id= q.lastInsertId().toInt();
    emit insertedAction(task_id);

    // Assign task into the selection position
    if( position < 0)
        return;

    // Insert new task to the selected position
    updatePosition(task_id,position);

}

void DatabaseConnection::updatePosition(const int task_id, const int position){

    if( !database.open())
    {
        qInfo()<<"ERROR: Database is not open"<<endl;
        return;
    }
    // Insert task into the table
    QSqlQuery q;
    if (!q.prepare(QLatin1String(SQL_UPDATE_POSITION))){
        qInfo()<<"ERROR: preparation command: "<< q.lastError();
        return;
    }

    q.addBindValue(task_id);
    q.addBindValue(position);

    if(!q.exec()){
        qInfo()<<"ERROR: Problem executing insert"<<endl;
        qInfo()<<q.lastError()<<endl;
        return;
    }

    qInfo()<<" Updated Position";
    emit updatedPosition(position);
}
