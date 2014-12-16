#ifndef PERSONREPOSITORY_H
#define PERSONREPOSITORY_H

#include <vector>
#include <QDebug>
#include <QFile>
#include <QByteArray>
#include <QVariant>
#include "person.h"

class PersonRepository
{
public:
    PersonRepository();

    void addProgrammer(const Person& programmer);
    void updateProgrammer(const Person &programmer);
    void removeProgrammer(const Person& programmer);
    PersonContainer getAllProgrammers(QString sortString, const bool& desc);
    QPixmap getProgrammerPic(const Person &programmer);
private:
    QSqlDatabase db;
};

#endif // PERSONREPOSITORY_H
