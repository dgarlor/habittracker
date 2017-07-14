#include "databaseconnection.h"

#include<iostream>

using namespace std;

DatabaseConnection::DatabaseConnection(QObject *parent) : QObject(parent)
{
    mTaskName1=QString("Arreglar la barba");
    mTaskName2=QString("Leer algo tecnico");
    mTaskName3=QString("Hacer algo de la casa");
}

void DatabaseConnection::insertEvent(const int &habit){
   cout<<" -- Slot insertEvent: "<<habit<<endl;
    emit insertNotified(habit);
}
