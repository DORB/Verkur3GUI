#include "computerrepository.h"

ComputerRepository::ComputerRepository()
{
    db = utils::getDatabaseConnection();
}

void ComputerRepository::addComputer(const Computer &computer)
{
    QSqlQuery query(db);

    query.prepare("INSERT INTO Computers (name, year_built, type, build, imagePath) VALUES (:name, :year_built, :type, :build, :imagePath)");

    query.bindValue(":name", QString::fromStdString(computer.getName()));
    query.bindValue(":year_built", QString::fromStdString(utils::int2str(computer.getBuildYear())));
    query.bindValue(":type", QString::fromStdString(computer.getType()));
    query.bindValue(":build", QString::fromStdString(utils::int2str(computer.getBuild())));
    query.bindValue(":imagePath", QString::fromStdString(computer.getimagePath()));

    query.exec();

}

void ComputerRepository::updateComputer(const Computer &computer)
{
    QSqlQuery query(db);

    query.prepare("UPDATE Computers SET name = ':name' year_built = :year_built type = ':type' build = :build imagePath = ':imagePath' WHERE ID = :ID");

    query.bindValue(":name", QString::fromStdString(computer.getName()));
    query.bindValue(":year_built", QString::fromStdString(utils::int2str(computer.getBuildYear())));
    query.bindValue(":type", QString::fromStdString(computer.getType()));
    query.bindValue(":build", QString::fromStdString(utils::int2str(computer.getBuild())));
    query.bindValue(":imagePath", QString::fromStdString(computer.getimagePath()));
    query.bindValue(":ID", QString::fromStdString(utils::int2str(computer.getID())));

    // qDebug() << query.value();

    query.exec();
}

void ComputerRepository::removeComputer(const Computer &computer)
{
    QSqlQuery query(db);

    query.prepare(QString("DELETE FROM Computers WHERE ID = %1").arg(computer.getID()));

    query.exec();
}

CompContainer ComputerRepository::getAllComputers(QString sortString, const bool& desc)
{
    CompContainer results;

    QString order;
    if(desc)
        order = "DESC";
    else
        order = "";

    QSqlQuery query(db);
    query.prepare(QString("SELECT * FROM Computers ORDER BY %1 %2").arg(sortString, order));
    query.exec();

    while(query.next())
    {
        int id = query.value("ID").toInt();
        string name = query.value("name").toString().toStdString();
        string type = query.value("type").toString().toStdString();
        int year_built = query.value("year_built").toInt();
        bool build = query.value("build").toBool();
        string imagePath = query.value("imagePath").toString().toStdString();

        results.push_back(Computer(id, name, type, year_built, build, imagePath));
    }

    return results;
}
