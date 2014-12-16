#include "relationrepository.h"

RelationRepository::RelationRepository()
{
    db = utils::getDatabaseConnection();
}

CompContainer RelationRepository::getRelations(const Person& programmer)
{
    QString p_ID = QString::fromStdString(utils::int2str(programmer.getID()));

    QSqlQuery query(db);

    query.prepare(QString("SELECT * FROM Programmers p INNER JOIN Owners u ON u.p_ID = p.ID INNER JOIN Computers c ON u.c_ID = c.ID WHERE p.ID = %1").arg(p_ID));

    query.exec();

    CompContainer results;

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

PersonContainer RelationRepository::getRelations(const Computer& computer)
{
    QString c_ID = QString::fromStdString(utils::int2str(computer.getID()));

    QSqlQuery query(db);

    query.prepare(QString("SELECT * FROM Programmers p INNER JOIN Owners u ON u.p_ID = p.ID INNER JOIN Computers c ON u.c_ID = c.ID WHERE c.ID = %1").arg(c_ID));

    query.exec();

    PersonContainer results;

    while(query.next())
    {
        int id = query.value("ID").toInt();
        string first_name = query.value("first_name").toString().toStdString();
        string last_name = query.value("last_name").toString().toStdString();
        int birth_year = query.value("birth_year").toInt();
        int death_year = query.value("death_year").toInt();
        string sex = query.value("sex").toString().toStdString();
        string nationality = query.value("nationality").toString().toStdString();
        string imagePath = query.value("imagePath").toString().toStdString();

        results.push_back(Person(id, first_name, last_name, birth_year, death_year, sex, nationality, imagePath));
    }

    return results;
}
