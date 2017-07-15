#include "databaseconnection.h"
#include <QtDebug>
#include <QtSql>
#include <iostream>
using namespace std;

DatabaseConnection::DatabaseConnection(QSqlDatabase &db) :
    QObject(0), database(db)
{
}

//DatabaseConnection::DatabaseConnection(QObject *parent) : QObject(parent)
//{
//}

void DatabaseConnection::insertEvent(const int &habit){
   if( !database.open())
   {
       qInfo()<<"ERROR: Database is not open"<<endl;
       return;
   }

   QSqlQuery q;
   if (!q.prepare(QLatin1String("insert into action(task_id) values(?)"))){
       qInfo()<<"ERROR: preparation command: "<< q.lastError();
       return;
   }

   q.addBindValue(habit);
   if(!q.exec()){
       qInfo()<<"ERROR: Problem executing insert"<<endl;
       qInfo()<<q.lastError()<<endl;
       return;
   }

   qInfo()<<" Inserted "<<q.lastInsertId();
   emit insertNotified(habit);
}
