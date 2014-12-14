#include "addprogrammerdialog.h"
#include "ui_addprogrammerdialog.h"

AddProgrammerDialog::AddProgrammerDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddProgrammerDialog)
{
    ui->setupUi(this);
}

AddProgrammerDialog::~AddProgrammerDialog()
{
    delete ui;
}

void AddProgrammerDialog::on_check_add_programmer_not_dead_toggled(bool checked)
{
    if(checked)
    {
        ui->input_add_programmer_year_of_death->clear();
        ui->input_add_programmer_year_of_death->setDisabled(true);
    }
    else
        ui->input_add_programmer_year_of_death->setEnabled(true);
}

void AddProgrammerDialog::on_button_add_programmer_clicked()
{

}

void AddProgrammerDialog::on_input_add_programmers_year_of_birth_textChanged(const QString &arg1)
{
    std::string year_of_birth = ui->input_add_programmers_year_of_birth->text().toStdString();

    QPalette *palette = new QPalette();

    if(!utils::isYear(year_of_birth))
    {
        palette->setColor(QPalette::Text,Qt::red);
        ui->input_add_programmers_year_of_birth->setPalette(*palette);
        ui->button_add_programmer->setDisabled(true);
    }
    else
    {
        palette->setColor(QPalette::Text,Qt::black);
        ui->input_add_programmers_year_of_birth->setPalette(*palette);
        ui->button_add_programmer->setEnabled(true);
    }

    delete palette;
}
