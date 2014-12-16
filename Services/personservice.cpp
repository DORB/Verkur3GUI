#include "personservice.h"

PersonService::PersonService()
{
}

void PersonService::addProgrammer(Person programmer)
{
    programmerRepository.addProgrammer(programmer);
}

void PersonService::updateProgrammer(const Person& programmer)
{
    programmerRepository.updateProgrammer(programmer);
}

PersonContainer PersonService::getAllProgrammers(QString sortString, const bool& desc)
{
    return programmerRepository.getAllProgrammers(sortString, desc);
}

void PersonService::removeProgrammer(const Person& programmer)
{
    programmerRepository.removeProgrammer(programmer);
}
