#include "personservice.h"

PersonService::PersonService()
{
}

void PersonService::addProgrammer(Person programmer)
{
    programmerRepository.addProgrammer(programmer);
}

PersonContainer PersonService::getAllProgrammers(QString sortString)
{
    return programmerRepository.getAllProgrammers(sortString);
}
