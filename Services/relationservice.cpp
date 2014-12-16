#include "relationservice.h"

RelationService::RelationService()
{
}

PersonContainer RelationService::getRelations(const Computer& currentlyViewedComputer)
{
    return relationRepository.getRelations(currentlyViewedComputer);
}

CompContainer RelationService::getRelations(const Person& currentlyViewedPerson)
{
    return relationRepository.getRelations(currentlyViewedPerson);
}

void RelationService::addRelations(const Person& programmer, const Computer& computer)
{
    relationRepository.addRelations(programmer, computer);
}
