#ifndef REMOVECOMPUTERDIALOG_H
#define REMOVECOMPUTERDIALOG_H

#include <QDialog>
#include "computer.h"
#include "computerservice.h"

namespace Ui {
class RemoveComputerDialog;
}

class RemoveComputerDialog : public QDialog
{
    Q_OBJECT

public:
    explicit RemoveComputerDialog(QWidget *parent = 0);
    ~RemoveComputerDialog();

    void setComputer(const Computer& computer);

private slots:
    void on_button_remove_computer_cancel_clicked();

    void on_button_remove_computer_ok_clicked();

private:
    Ui::RemoveComputerDialog *ui;

    Computer computerRemoved;
    ComputerService computerService;
};

#endif // REMOVECOMPUTERDIALOG_H
