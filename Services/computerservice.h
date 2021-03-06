#ifndef COMPUTERSERVICE_H
#define COMPUTERSERVICE_H

#include "computer.h"
#include "computerrepository.h"

typedef vector<Computer> CompContainer;

class ComputerService
{
public:
    ComputerService();

    void addComputer(const Computer& computer);
    void removeComputer(const Computer& computer);
    void updateComputer(const Computer& computer);

    CompContainer getAllComputers(QString sortString, const bool& desc);

    QPixmap getComputerPic(const Computer &computer);
private:
    ComputerRepository computerRepository;

};

#endif // COMPUTERSERVICE_H
