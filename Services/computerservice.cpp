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

void ComputerService::removeComputer(const Computer& computer)
{
    computerRepository.removeComputer(computer);
}
