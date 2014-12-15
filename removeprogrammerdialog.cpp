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

void RemoveProgrammerDialog::setProgrammer(const Person &person)
{
    QString programmer_rem_name = QString::fromStdString(person.getFName());
    QString msg = QString("Are you sure you want to delete %1?").arg(programmer_rem_name);
    ui->label_remove_programmer_msg->setText(msg);

    personRemoved = person;
    qDebug() << QString::fromStdString(person.getFName());
}

void RemoveProgrammerDialog::on_button_remove_programmer_cancel_clicked()
{
    close();
}

void RemoveProgrammerDialog::on_button_remove_programmer_ok_clicked()
{
    personService.removeProgrammer(personRemoved);
    close();
}

