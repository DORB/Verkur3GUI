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
    QString name = QString::fromStdString(person.getWholeName());
    QString lifespan = QString::fromStdString(person.getLifespan());

    ui->label_programmer_name->setText(QString("<h2>%1 (%2)</h2>").arg(name, lifespan));

    QString failPic;

    if(person.getSex() == "M")
        failPic = ":/pics/Images/man.png";
    else
        failPic = ":/pics/Images/woman.png";

    if(person.getImagePath() == "")
    {
        QPixmap pixmap(failPic);

        int imageLabelWidth = ui->label_image_programmer->width();

        QPixmap scaledPixMap = pixmap.scaledToWidth(imageLabelWidth);

        ui->label_image_programmer->setPixmap(scaledPixMap);
    }
    else
    {
        QPixmap pixmap(QString::fromStdString(person.getImagePath()));

        int imageLabelWidth = ui->label_image_programmer->width();

        QPixmap scaledPixMap = pixmap.scaledToWidth(imageLabelWidth);

        ui->label_image_programmer->setPixmap(scaledPixMap);
    }


    QString programmer_nationality = QString::fromStdString(person.getNationality());

    ui->label_programmer_nationality->setText(programmer_nationality);

    QString programmer_birth_year;

    if(person.getBY() != 0)
        programmer_birth_year = QString::fromStdString(utils::int2str(person.getBY()));
    else
        programmer_birth_year = "-";


    ui->label_programmer_born->setText(programmer_birth_year);


    QString programmer_death_year;
    if(person.getDY() != 0)
        programmer_death_year = QString::fromStdString(utils::int2str(person.getDY()));
    else
        programmer_death_year = "-";

    ui->label_programmer_dead->setText(programmer_death_year);


    QString programmer_sex = QString::fromStdString(person.getSex());

    ui->label_programmer_sex->setText(programmer_sex);



}
