#include "removeprogrammerdialog.h"
#include "ui_removeprogrammerdialog.h"

RemoveProgrammerDialog::RemoveProgrammerDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RemoveProgrammerDialog)
{
    ui->setupUi(this);
}

RemoveProgrammerDialog::~RemoveProgrammerDialog()
{
    delete ui;
}
