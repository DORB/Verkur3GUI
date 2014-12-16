#ifndef RELATIONSERVICE_H
#define RELATIONSERVICE_H

#include <QDebug>
#include "relationrepository.h"

class RelationService
{
public:
    RelationService();
    PersonContainer getRelations(const Computer &computer);
    CompContainer getRelations(const Person &programmer);
private:
    RelationRepository relationRepository;
};

#endif // RELATIONSERVICE_H
