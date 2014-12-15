#include "viewprogrammerdialog.h"
#include "ui_viewprogrammerdialog.h"
#include "utilities.h"

#include <QPixmap>


ViewProgrammerDialog::ViewProgrammerDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ViewProgrammerDialog)
{
    ui->setupUi(this);
}

ViewProgrammerDialog::~ViewProgrammerDialog()
{
    delete ui;
}

void ViewProgrammerDialog::on_pushButton_clicked()
{
    close();
}

void ViewProgrammerDialog::setProgrammer(Person person)
{
    ui->label_programmer_name->setText(QString("<h2>%1</h2>").arg(QString::fromStdString(person.toString())));

    QPixmap pixmap(QString::fromStdString(person.getImagePath()));

    int imageLabelWidth = ui->label_image_programmer->width();

    QPixmap scaledPixMap = pixmap.scaledToWidth(imageLabelWidth);

    ui->label_image_programmer->setPixmap(scaledPixMap);


    QString programmer_nationality = QString::fromStdString(person.getNationality());

    ui->label_programmer_nationality->setText(programmer_nationality);


    QString programmer_birth_year = QString::fromStdString(utils::int2str(person.getBY()));

    ui->label_programmer_born->setText(programmer_birth_year);


    QString programmer_death_year = QString::fromStdString(utils::int2str(person.getDY()));

    ui->label_programmer_dead->setText(programmer_death_year);


    QString programmer_sex = QString::fromStdString(person.getSex());

    ui->label_programmer_sex->setText(programmer_sex);



}
