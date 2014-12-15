#include "removecomputerdialog.h"
#include "ui_removecomputerdialog.h"

RemoveComputerDialog::RemoveComputerDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RemoveComputerDialog)
{
    ui->setupUi(this);   
}

RemoveComputerDialog::~RemoveComputerDialog()
{
    delete ui;
}

void RemoveComputerDialog::setComputer(const Computer& computer)
{
    QString comp_rem_name = QString::fromStdString(computer.getName());
    QString msg = QString("Are you sure you want to delete %1?").arg(comp_rem_name);
    ui->label_remove_computer_msg->setText(msg);

    computerRemoved = computer;
    qDebug() << QString::fromStdString(computer.getName());
}

void RemoveComputerDialog::on_button_remove_computer_cancel_clicked()
{
    close();
}

void RemoveComputerDialog::on_button_remove_computer_ok_clicked()
{
    computerService.removeComputer(computerRemoved);
    close();
}
