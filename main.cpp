#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "databaseconnection.h"
#include "initdb.h"
#include "sqlquerymodel.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    // Create our database connection class
    qInfo()<<" --Open MyHabits!";
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("/Users/dgarcia/code/myhabits2.db");

    if (!db.open()){
        //std::cout<<db.lastError().text().toStdString();
        qInfo()<<" xx Problem opening db";
        return -1;
    }

    qInfo()<<" -- Initialize InitDb";
    std::cout<<initDDb(db).text().toStdString();


    DatabaseConnection dbconnector(db);

    SqlQueryModel  habitsSqlModel(0);
    habitsSqlModel.setQuery("SELECT current.position, task.name, task.id FROM current JOIN task ON current.task_id = task.id ORDER BY current.position ASC",db);




    QQmlApplicationEngine engine;

    //qmlRegisterUncreatableType<DatabaseConnection>("DatabaseConnectionEnum", 1, 0, "DatabaseConnection", "only used for module type enums");
    engine.rootContext()->setContextProperty("dbconnector", &dbconnector);
    engine.rootContext()->setContextProperty("habitsModel", &habitsSqlModel);

    engine.load(QUrl(QLatin1String("qrc:/main.qml")));

    return app.exec();
}
