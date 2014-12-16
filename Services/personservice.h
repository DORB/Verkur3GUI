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
    void removeProgrammer(const Person& programmer);

    PersonContainer getAllProgrammers(QString sortString, const bool& desc);

    void updateProgrammer(const Person &programmer);
    QPixmap getProgrammerPic(const Person &programmer);
private:
    PersonRepository programmerRepository;
};

#endif // PERSONSERVICE_H
