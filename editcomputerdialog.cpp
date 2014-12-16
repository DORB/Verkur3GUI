#include "editcomputerdialog.h"
#include "ui_editcomputerdialog.h"

EditComputerDialog::EditComputerDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditComputerDialog)
{
    ui->setupUi(this);
}

EditComputerDialog::~EditComputerDialog()
{
    delete ui;
}

void EditComputerDialog::editComputer(const Computer& computer)
{
    currentComputer = computer;

    ui->input_add_computers_name->setText(QString::fromStdString(computer.getName()));
    ui->input_add_computers_year->setText(QString::fromStdString(utils::int2str(computer.getBuildYear())));
    ui->input_add_computers_type->setText(QString::fromStdString(computer.getType()));
    ui->input_computers_image_path->setText(QString::fromStdString(computer.getimagePath()));

    bool wasBuilt = computer.getBuild();

    if(wasBuilt)
        ui->check_box_computer_built->setChecked(true);
    else
        ui->check_box_computer_built->setChecked(false);
}
