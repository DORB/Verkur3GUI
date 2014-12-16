#include "editprogrammerdialog.h"
#include "ui_editprogrammerdialog.h"
#include "ui_addprogrammerdialog.h"

EditProgrammerDialog::EditProgrammerDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditProgrammerDialog)
{
    ui->setupUi(this);
}

EditProgrammerDialog::~EditProgrammerDialog()
{
    delete ui;
}

void EditProgrammerDialog::editProgrammer(const Person& programmer)
{
    currentProgrammer = programmer;

    ui->input_add_programmers_first_name->setText(QString::fromStdString(programmer.getFName()));
    ui->input_add_programmers_last_name->setText(QString::fromStdString(programmer.getLName()));
    ui->input_add_programmers_nationality->setText(QString::fromStdString(programmer.getNationality()));
    ui->input_add_programmers_year_of_birth->setText(QString::fromStdString(utils::int2str(programmer.getBY())));
    ui->input_add_programmer_year_of_death->setText(QString::fromStdString(utils::int2str(programmer.getDY())));
    if(programmer.getSex() == "M")
        ui->radio_male->setChecked(true);
    else
        ui->radio_female->setChecked(true);
}

void EditProgrammerDialog::on_button_add_programmer_clicked()
{
    string first_name = ui->input_add_programmers_first_name->text().toStdString();
    string last_name = ui->input_add_programmers_last_name->text().toStdString();
    string nationality = ui->input_add_programmers_nationality->text().toStdString();
    int year_of_birth = ui->input_add_programmers_year_of_birth->text().toInt();
    int year_of_death = ui->input_add_programmer_year_of_death->text().toInt();
    string imagePath = ui->Input_image_path->text().toStdString();

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


    Person programmer = Person(0, first_name, last_name, year_of_birth, year_of_death, sex, nationality, imagePath);

    programmerService.addProgrammer(programmer);

    close();
}


void EditProgrammerDialog::on_button_cancel_add_programmer_clicked()
{
    close();
}

void EditProgrammerDialog::validate()
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




