#include "personrepository.h"

PersonRepository::PersonRepository()
{
    db = utils::getDatabaseConnection();
}

void PersonRepository::addProgrammer(const Person& programmer)
{
    QSqlQuery query(db);

    query.prepare("INSERT INTO Programmers (first_name, last_name, birth_year, death_year, sex, nationality, imagePath, pic) VALUES(:first_name, :last_name, :birth_year, :death_year, :sex, :nationality, :imagePath, :pic)");

    query.bindValue(":first_name", QString::fromStdString(programmer.getFName()));
    query.bindValue(":last_name", QString::fromStdString(programmer.getLName()));
    query.bindValue(":birth_year", QString::fromStdString(utils::int2str(programmer.getBY())));
    query.bindValue(":death_year", QString::fromStdString(utils::int2str(programmer.getDY())));
    query.bindValue(":sex", QString::fromStdString(programmer.getSex()));
    query.bindValue(":nationality", QString::fromStdString(programmer.getNationality()));
    query.bindValue(":imagePath", QString::fromStdString(programmer.getImagePath()));

    if(programmer.getImagePath() != "")
    {
        qDebug() << QString::fromStdString(programmer.getImagePath());

        QFile file(QString::fromStdString(programmer.getImagePath()));
        if(!file.open(QIODevice::ReadOnly)) { qDebug() << "virkar ekki"; return; }

        QByteArray byteArray = file.readAll();

        query.bindValue(":pic", QVariant(byteArray));
    }
    else
    {
        query.bindValue(":pic", QVariant());
    }
    /*
    QFile file(QString::fromStdString(programmer.getImagePath()));
    if(!file.open(QIODevice::ReadOnly)) { qDebug() << "virkar ekki"; return; }

    QByteArray byteArray = file.readAll();

    query.bindValue(":pic", QVariant(byteArray));
    */

    query.exec();
    qDebug() << query.executedQuery();
}

void PersonRepository::updateProgrammer(const Person& programmer)
{
    QSqlQuery query(db);

    if(programmer.getImagePath() != "")
        query.prepare("UPDATE Programmers SET first_name = :first_name, last_name = :last_name, birth_year = :birth_year, death_year = :death_year, sex = :sex, nationality = :nationality, imagePath = :imagePath, pic = :pic WHERE ID = :ID");
    else
        query.prepare("UPDATE Programmers SET first_name = :first_name, last_name = :last_name, birth_year = :birth_year, death_year = :death_year, sex = :sex, nationality = :nationality WHERE ID = :ID");


    query.bindValue(":first_name", QString::fromStdString(programmer.getFName()));
    query.bindValue(":last_name", QString::fromStdString(programmer.getLName()));
    query.bindValue(":birth_year", QString::fromStdString(utils::int2str(programmer.getBY())));
    query.bindValue(":death_year", QString::fromStdString(utils::int2str(programmer.getDY())));
    query.bindValue(":sex", QString::fromStdString(programmer.getSex()));
    query.bindValue(":nationality", QString::fromStdString(programmer.getNationality()));
    query.bindValue(":imagePath", QString::fromStdString(programmer.getImagePath()));
    query.bindValue(":ID", QString::fromStdString(utils::int2str(programmer.getID())));

    if(programmer.getImagePath() != "")
    {
        qDebug() << QString::fromStdString(programmer.getImagePath());

        QFile file(QString::fromStdString(programmer.getImagePath()));
        if(!file.open(QIODevice::ReadOnly)) { qDebug() << "virkar ekki"; return; }

        QByteArray byteArray = file.readAll();

        query.bindValue(":pic", QVariant(byteArray));
    }

    query.exec();
}

void PersonRepository::removeProgrammer(const Person &programmer)
{
    QSqlQuery query(db);

    query.prepare(QString("DELETE FROM Programmers WHERE ID = %1").arg(programmer.getID()));

    query.exec();
}

PersonContainer PersonRepository::getAllProgrammers(QString sortString, const bool& desc)
{
    PersonContainer results;
    QString order;
    if(desc)
        order = "DESC";
    else
        order = "";

    QSqlQuery query(db);
    query.prepare(QString("SELECT ID,first_name,last_name,birth_year,death_year,sex,nationality,imagePath FROM Programmers ORDER BY %1 %2").arg(sortString, order));
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
        string imagePath = query.value("imagePath").toString().toStdString();

        results.push_back(Person(id, first_name, last_name, birth_year, death_year, sex, nationality, imagePath));
    }

    // qDebug() << results.size();

    return results;
}

QPixmap PersonRepository::getProgrammerPic(const Person& programmer)
{
    QSqlQuery query(db);
    query.prepare(QString("SELECT pic FROM Programmers WHERE ID = %1").arg(QString::fromStdString(utils::int2str(programmer.getID()))));
    query.exec();

    // query.first();
    QByteArray array;
    QPixmap pixmap;

    while(query.next())
    {
        array = query.value(0).toByteArray();
        pixmap.loadFromData(array);
    }

    return pixmap;
}
