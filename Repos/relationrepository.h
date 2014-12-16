#ifndef RELATIONREPOSITORY_H
#define RELATIONREPOSITORY_H

#include "person.h"
#include "computer.h"

class RelationRepository
{
public:
    RelationRepository();
    CompContainer getRelations(const Person &programmer);
    PersonContainer getRelations(const Computer &computer);

private:
    QSqlDatabase db;
};

#endif // RELATIONREPOSITORY_H
