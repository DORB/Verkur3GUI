#include "addprogrammerdialog.h"
#include "ui_addprogrammerdialog.h"

AddProgrammerDialog::AddProgrammerDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddProgrammerDialog)
{
    ui->setupUi(this);
    // ui->button_add_programmer->setDisabled(true);

    validate();
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
        year_of_death_valid = true;
    }
    else
    {
        ui->input_add_programmer_year_of_death->setEnabled(true);
        year_of_death_valid = false;
    }

    validate();
}

void AddProgrammerDialog::on_button_add_programmer_clicked()
{
    string first_name = ui->input_add_programmers_first_name->text().toStdString();
    string last_name = ui->input_add_programmers_last_name->text().toStdString();
    string nationality = ui->input_add_programmers_nationality->text().toStdString();
    int year_of_birth = ui->input_add_programmers_year_of_birth->text().toInt();
    int year_of_death = ui->input_add_programmer_year_of_death->text().toInt();

    if(ui->check_add_programmer_not_dead->isChecked())
        year_of_death = 0;

    string sex;

    if(ui->radio_male->isChecked())
        sex = "M";
    else
        sex = "F";

    // Utilitization:

    utils::trimWS(first_name);
    utils::firstCap(first_name);
    utils::trimWS(last_name);
    utils::firstCap(last_name);
    utils::trimWS(nationality);
    utils::firstCap(nationality);


    Person programmer = Person(0, first_name, last_name, year_of_birth, year_of_death, sex, nationality);

    programmerService.addProgrammer(programmer);

    close(); 
}

void AddProgrammerDialog::on_input_add_programmers_year_of_birth_textChanged(const QString &arg1)
{
    std::string year_of_birth = arg1.toStdString();

    QPalette *palette = new QPalette();

    if(arg1.toInt() >= 0 && utils::isYear(year_of_birth))
    {
        palette->setColor(QPalette::Text,Qt::black);
        ui->input_add_programmers_year_of_birth->setPalette(*palette);
        year_of_birth_valid = true;
    }
    else
    {
        palette->setColor(QPalette::Text,Qt::red);
        ui->input_add_programmers_year_of_birth->setPalette(*palette);
        year_of_birth_valid = false;
    }

    validate();

    delete palette;


}

void AddProgrammerDialog::on_button_cancel_add_programmer_clicked()
{
    close();
}

void AddProgrammerDialog::validate()
{
    bool valid = true;

    if(!first_name_valid)
        valid = false;
    else if(!last_name_valid)
        valid = false;
    else if(!nationality_valid)
        valid = false;
    else if(!year_of_birth_valid)
        valid = false;
    else if(!year_of_death_valid)
        valid = false;
    else if(!sex_valid)
        valid = false;

    if(valid)
        ui->button_add_programmer->setEnabled(true);
    else
        ui->button_add_programmer->setEnabled(false);
}

void AddProgrammerDialog::on_input_add_programmers_first_name_textChanged(const QString &arg1)
{
    if(arg1 != "")
        first_name_valid = true;
    else
        last_name_valid = false;

    validate();
}

void AddProgrammerDialog::on_input_add_programmers_last_name_textChanged(const QString &arg1)
{
    if(arg1 != "")
        last_name_valid = true;
    else
        last_name_valid = false;

    validate();
}

void AddProgrammerDialog::on_input_add_programmers_nationality_textChanged(const QString &arg1)
{
    if(arg1 != "")
        nationality_valid = true;
    else
        nationality_valid = false;

    validate();
}

void AddProgrammerDialog::on_input_add_programmer_year_of_death_textChanged(const QString &arg1)
{
    std::string year_of_death = arg1.toStdString();

    QPalette *palette = new QPalette();

    if(arg1.toInt() >= ui->input_add_programmers_year_of_birth->text().toInt())
    {
        palette->setColor(QPalette::Text,Qt::black);
        ui->input_add_programmer_year_of_death->setPalette(*palette);
        year_of_death_valid = true;
    }
    else
    {
        palette->setColor(QPalette::Text,Qt::red);
        ui->input_add_programmer_year_of_death->setPalette(*palette);
        year_of_death_valid = false;
    }

    validate();

    delete palette;
}

void AddProgrammerDialog::on_radio_male_toggled(bool checked)
{
    sex_valid = true;

    validate();
}

void AddProgrammerDialog::on_radio_female_toggled(bool checked)
{
    sex_valid = true;

    validate();
}
