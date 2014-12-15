#include "addcomputerdialog.h"
#include "ui_addcomputerdialog.h"

#include <QFileDialog>
#include <QDebug>

AddComputerDialog::AddComputerDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddComputerDialog)
{
    ui->setupUi(this);

    validate();
}

AddComputerDialog::~AddComputerDialog()
{
    delete ui;
}

void AddComputerDialog::on_button_browse_computer_image_clicked()
{
    QString filename = QFileDialog::getOpenFileName(
                    this,
                    "Browse for image",
                    "",
                    "Image files (*.jpg *.png *.bmp)"
                );
    ui->input_computers_image_path->setText(filename);

}




void AddComputerDialog::on_button_add_new_computer_clicked()
{
    string name = ui->input_add_computers_name->text().toStdString();
    string type = ui->input_add_computers_type->text().toStdString();
    int year_built = ui->input_add_computers_year->text().toInt();
    string imagePath =ui->input_computers_image_path->text().toStdString();

    bool build;

    if(ui->check_box_computer_built->isChecked())
        build = true;
    else
        build = false;

    utils::firstCap(name);
    utils::firstCap(type);

    Computer computer = Computer(0, name, type, year_built, build, imagePath);

    computerService.addComputer(computer);

    close();
}


void AddComputerDialog::on_input_add_computers_year_textChanged(const QString &arg1)
{
    std::string year_built =arg1.toStdString();

    QPalette *palette = new QPalette();

    if(arg1.toInt() >= 0 && utils::isYear(year_built))
    {
        palette->setColor(QPalette::Text,Qt::black);
        ui->input_add_computers_year->setPalette(*palette);
        year_built_valid = true;
    }
    else
    {
        palette->setColor(QPalette::Text,Qt::red);
        ui->input_add_computers_year->setPalette(*palette);
        year_built_valid = false;
    }

    validate();

    delete palette;
}

void AddComputerDialog::on_button_cancel_add_new_computer_clicked()
{
    close();
}

void AddComputerDialog::validate()
{
    bool valid = true;

    if(!name_valid)
        valid = false;
    else if(!type_valid)
        valid = false;
    else if(!year_built_valid)
        valid = false;

    if(valid)
        ui->button_add_new_computer->setEnabled(true);
    else
        ui->button_add_new_computer->setEnabled(false);
}



void AddComputerDialog::on_input_add_computers_name_textChanged(const QString &arg1)
{
    if(arg1 != "")
        name_valid = true;
    else
        name_valid = false;

    validate();
}


void AddComputerDialog::on_input_add_computers_type_textChanged(const QString &arg1)
{
    if(arg1 != "")
        type_valid = true;
    else
        type_valid = false;

    validate();
}
