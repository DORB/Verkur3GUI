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
    void addRelations(const Person &programmer, const Computer &computer);
private:
    RelationRepository relationRepository;
};

#endif // RELATIONSERVICE_H
