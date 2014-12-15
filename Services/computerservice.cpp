#include "computerservice.h"

ComputerService::ComputerService()
{
}

void ComputerService::addComputer(const Computer &computer)
{
    computerRepository.addComputer(computer);
}

CompContainer ComputerService::getAllComputers(QString sortString, const bool& desc)
{
    return computerRepository.getAllComputers(sortString, desc);
}

void ComputerService::removeComputer(const Computer& computer)
{
    computerRepository.removeComputer(computer);
}
