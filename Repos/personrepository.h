#ifndef PERSONREPOSITORY_H
#define PERSONREPOSITORY_H

#include <vector>
#include <QDebug>
#include "person.h"

typedef vector<Person> PersonContainer;

class PersonRepository
{
public:
    PersonRepository();

    void addProgrammer(const Person& programmer);
    void removeProgrammer(const Person& programmer);

    PersonContainer getAllProgrammers(QString sortString, const bool& desc);

private:
    QSqlDatabase db;
};

#endif // PERSONREPOSITORY_H
