#include "computerservice.h"

ComputerService::ComputerService()
{
}

void ComputerService::addComputer(const Computer &computer)
{
    computerRepository.addComputer(computer);
}

void ComputerService::updateComputer(const Computer &computer)
{
    computerRepository.updateComputer(computer);
}

CompContainer ComputerService::getAllComputers(QString sortString, const bool& desc)
{
    return computerRepository.getAllComputers(sortString, desc);
}

void ComputerService::removeComputer(const Computer& computer)
{
    computerRepository.removeComputer(computer);
}

QPixmap ComputerService::getComputerPic(const Computer& computer)
{
    return computerRepository.getComputerPic(computer);
}
