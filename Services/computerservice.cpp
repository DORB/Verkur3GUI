#include "computerservice.h"

ComputerService::ComputerService()
{
}

void ComputerService::addComputer(const Computer &computer)
{
    computerRepository.addComputer(computer);
}

CompContainer ComputerService::getAllComputers(QString sortString)
{
    return computerRepository.getAllComputers(sortString);
}
