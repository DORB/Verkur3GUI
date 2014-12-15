#include "personrepository.h"

PersonRepository::PersonRepository()
{
    db = utils::getDatabaseConnection();
}

void PersonRepository::addProgrammer(const Person& programmer)
{
    QSqlQuery query(db);

    query.prepare("INSERT INTO Programmers (first_name, last_name, birth_year, death_year, sex, nationality, imagePath) VALUES(:first_name, :last_name, :birth_year, :death_year, :sex, :nationality, :imagePath)");

    query.bindValue(":first_name", QString::fromStdString(programmer.getFName()));
    query.bindValue(":last_name", QString::fromStdString(programmer.getLName()));
    query.bindValue(":birth_year", QString::fromStdString(utils::int2str(programmer.getBY())));
    query.bindValue(":death_year", QString::fromStdString(utils::int2str(programmer.getDY())));
    query.bindValue(":sex", QString::fromStdString(programmer.getSex()));
    query.bindValue(":nationality", QString::fromStdString(programmer.getNationality()));
    query.bindValue(":imagePath", QString::fromStdString(programmer.getImagePath()));

    query.exec();
}

void PersonRepository::removeProgrammer(const Person &programmer)
{
    QSqlQuery query(db);

    query.prepare(QString("DELETE FROM Programmers WHERE ID = %1").arg(programmer.getID()));

    query.exec();
}

PersonContainer PersonRepository::getAllProgrammers(QString sortString)
{
    PersonContainer results;

    QSqlQuery query(db);
    query.prepare(QString("SELECT * FROM Programmers ORDER BY %1").arg(sortString));
    query.exec();

    while(query.next())
    {
        int id = query.value("ID").toInt();
        string first_name = query.value("first_name").toString().toStdString();
        string last_name = query.value("last_name").toString().toStdString();
        int birth_year = query.value("birth_year").toInt();
        int death_year = query.value("death_year").toInt();
        string sex = query.value("sex").toString().toStdString();
        string nationality = query.value("nationality").toString().toStdString();
        string imagePath = query.value("image_Path").toString().toStdString();

        results.push_back(Person(id, first_name, last_name, birth_year, death_year, sex, nationality, imagePath));
    }

    // qDebug() << results.size();

    return results;
}
