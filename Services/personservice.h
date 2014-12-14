#ifndef PERSONSERVICE_H
#define PERSONSERVICE_H

#include "person.h"
#include "personrepository.h"

typedef vector<Person> PersonContainer;

class PersonService
{
public:
    PersonService();

    void addProgrammer(Person programmer);
    void removeProgrammer(Person programmer);

    PersonContainer getAllProgrammers(QString sortString);

private:
    PersonRepository programmerRepository;
};

#endif // PERSONSERVICE_H
