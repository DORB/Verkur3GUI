#ifndef COMPUTERREPOSITORY_H
#define COMPUTERREPOSITORY_H

#include <vector>
#include <QDebug>
#include "computer.h"

class ComputerRepository
{
public:
    ComputerRepository();

    void addComputer(const Computer& computer);
    void updateComputer(const Computer& computer);
    void removeComputer(const Computer& computer);

    CompContainer getAllComputers(QString sortString, const bool& desc);

    QPixmap getComputerPic(const Computer &computer);
private:
    QSqlDatabase db;
};

#endif // COMPUTERREPOSITORY_H
