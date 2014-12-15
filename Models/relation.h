#ifndef RELATION_H
#define RELATION_H

#include <string>
#include "person.h"
#include "computer.h"

using namespace std;

class Relation
{
public:
    Relation();
    Relation(const Person& person, const Computer& comp);
    int getPID() const;
    string getPname() const;
    string getPlife() const;
    string getPnationality() const;
    int getCID() const;
    string getCname() const;
    string getCtype() const;
    int getCyearBuilt() const;
private:
    Person p;
    Computer c;
};

#endif // RELATION_H

