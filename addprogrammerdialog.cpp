#include "addprogrammerdialog.h"
#include "ui_addprogrammerdialog.h"

AddProgrammerDialog::AddProgrammerDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddProgrammerDialog)
{
    ui->setupUi(this);
    // ui->button_add_programmer->setDisabled(true);
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
    string first_name = ui->input_add_programmers_first_name->text().toStdString();
    string last_name = ui->input_add_programmers_last_name->text().toStdString();
    string nationality = ui->input_add_programmers_nationality->text().toStdString();
    int year_of_birth = ui->input_add_programmers_year_of_birth->text().toInt();
    int year_of_death = ui->input_add_programmer_year_of_death->text().toInt();
    string sex = ui->input_add_programmer_sex->text().toStdString();

    Person programmer = Person(0, first_name, last_name, year_of_birth, year_of_death, sex, nationality);

    programmerService.addProgrammer(programmer);

    close();
}

void AddProgrammerDialog::on_input_add_programmers_year_of_birth_textChanged(const QString &arg1)
{
    std::string year_of_birth = ui->input_add_programmers_year_of_birth->text().toStdString();

    QPalette *palette = new QPalette();

    if(!utils::isYear(year_of_birth))
    {
        palette->setColor(QPalette::Text,Qt::red);
        ui->input_add_programmers_year_of_birth->setPalette(*palette);
        // ui->button_add_programmer->setDisabled(true);
    }
    else
    {
        palette->setColor(QPalette::Text,Qt::black);
        ui->input_add_programmers_year_of_birth->setPalette(*palette);
        // ui->button_add_programmer->setEnabled(true);
    }

    delete palette;
}

void AddProgrammerDialog::on_button_cancel_add_programmer_clicked()
{
    close();
}
