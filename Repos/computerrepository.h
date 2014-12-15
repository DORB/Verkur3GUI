#ifndef COMPUTERREPOSITORY_H
#define COMPUTERREPOSITORY_H

#include <vector>
#include <QDebug>
#include "computer.h"

typedef vector<Computer> CompContainer;

class ComputerRepository
{
public:
    ComputerRepository();

    void addComputer(const Computer& computer);
    void removeComputer(const Computer& computer);

    CompContainer getAllComputers(QString sortString, const bool& desc);

private:
    QSqlDatabase db;
};

#endif // COMPUTERREPOSITORY_H
