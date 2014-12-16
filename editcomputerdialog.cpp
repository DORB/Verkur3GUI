#include "editcomputerdialog.h"
#include "ui_editcomputerdialog.h"

#include <QFileDialog>

EditComputerDialog::EditComputerDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditComputerDialog)
{
    ui->setupUi(this);

    //validate();
}

EditComputerDialog::~EditComputerDialog()
{
    delete ui;
}

void EditComputerDialog::on_button_browse_computer_image_clicked()
{
    QString filename = QFileDialog::getOpenFileName(
                    this,
                    "Browse for image",
                    "",
                    "Image files (*.jpg *.png *.bmp)"
                );
    ui->input_computers_image_path->setText(filename);

}

void EditComputerDialog::editComputer(const Computer& computer)
{
    currentComputer = computer;

    ui->input_edit_computers_name->setText(QString::fromStdString(computer.getName()));
    ui->input_edit_computers_year->setText(QString::fromStdString(utils::int2str(computer.getBuildYear())));
    ui->input_edit_computers_type->setText(QString::fromStdString(computer.getType()));
    ui->input_computers_image_path->setText(QString::fromStdString(computer.getimagePath()));

    bool wasBuilt = computer.getBuild();

    if(wasBuilt)
        ui->check_box_computer_built->setChecked(true);
    else
        ui->check_box_computer_built->setChecked(false);
}

void EditComputerDialog::on_button_edit_computer_clicked()
{
    string name = ui->input_edit_computers_name->text().toStdString();
    string type = ui->input_edit_computers_type->text().toStdString();
    int year_built = ui->input_edit_computers_year->text().toInt();
    string imagePath =ui->input_computers_image_path->text().toStdString();

    bool build;

    if(ui->check_box_computer_built->isChecked())
        build = true;
    else
        build = false;

    utils::firstCap(name);
    utils::firstCap(type);

    Computer computer = Computer(currentComputer.getID(), name, type, year_built, build, imagePath);

    computerService.updateComputer(computer);

    close();
}

void EditComputerDialog::validate()
{
    bool valid = true;

    if(!name_valid)
        valid = false;
    else if(!type_valid)
        valid = false;
    else if(!year_built_valid)
        valid = false;

    if(valid)
        ui->button_edit_computer->setEnabled(true);
    else
        ui->button_edit_computer->setEnabled(false);
}

void EditComputerDialog::on_input_edit_computers_year_textChanged(const QString &arg1)
{
    std::string year_built =arg1.toStdString();

    QPalette *palette = new QPalette();

    if(arg1.toInt() >= 0 && utils::isYear(year_built))
    {
        palette->setColor(QPalette::Text,Qt::black);
        ui->input_edit_computers_year->setPalette(*palette);
        year_built_valid = true;
    }
    else
    {
        palette->setColor(QPalette::Text,Qt::red);
        ui->input_edit_computers_year->setPalette(*palette);
        year_built_valid = false;
    }

    validate();

    delete palette;
}

void EditComputerDialog::on_button_cancel_edit_computer_clicked()
{
    close();
}

void EditComputerDialog::on_input_edit_computers_name_textChanged(const QString &arg1)
{
    if(arg1 != "")
        name_valid = true;
    else
        name_valid = false;

    validate();
}


void EditComputerDialog::on_input_edit_computers_type_textChanged(const QString &arg1)
{
    if(arg1 != "")
        type_valid = true;
    else
        type_valid = false;

    validate();
}
