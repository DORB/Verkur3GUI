#include "addcomputerdialog.h"
#include "ui_addcomputerdialog.h"

#include <QFileDialog>
#include <QDebug>

AddComputerDialog::AddComputerDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddComputerDialog)
{
    ui->setupUi(this);
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

void AddComputerDialog::on_button_add_new_computer_toggled(bool checked)
{

}
