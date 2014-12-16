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

void ViewProgrammerDialog::on_button_view_programmer_close_clicked()
{
    close();
}

void ViewProgrammerDialog::setProgrammer(Person person)
{
    currentlyViewedPerson = person;

    QString name = QString::fromStdString(person.getWholeName());

    ui->label_programmer_name->setText(QString("<h2>%1</h2>").arg(name));

    QString lifespan = QString::fromStdString(person.getLifespan());

    ui->label_programmer_born->setText(QString("<h3>(%1)</h3>").arg(lifespan));


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

    ui->label_programmer_nationality->setText(QString("<h3>%1</h3>").arg(programmer_nationality));

    QString programmer_birth_year;

    if(person.getBY() != 0)
        programmer_birth_year = QString::fromStdString(utils::int2str(person.getBY()));
    else
        programmer_birth_year = "-";


    //ui->label_programmer_born->setText(programmer_birth_year);


//    QString programmer_death_year;
//    if(person.getDY() != 0)
//        programmer_death_year = QString::fromStdString(utils::int2str(person.getDY()));
//    else
//        programmer_death_year = "-";

//    ui->label_programmer_dead->setText(programmer_death_year);

    if(person.getSex() == "M")
    {
        if(person.getDY() == 0 )
            ui->label_programmer_sex->setText("Is a man");
        else
            ui->label_programmer_sex->setText("Was a man");
    }
    else
    {
        if(person.getDY() == 0 )
            ui->label_programmer_sex->setText("Is a woman");
        else
            ui->label_programmer_sex->setText("Was a woman");
    }

/*
    QString programmer_sex = QString::fromStdString(person.getSex());

    ui->label_programmer_sex->setText(programmer_sex)*/;

    if(getRelations())
    {
        ui->list_programmer_relations->clear();

        for(unsigned int i = 0; i < relatedComputers.size(); i++)
        {
            string item_str = relatedComputers[i].getName() + " (";
            item_str += utils::int2str(relatedComputers[i].getBuildYear()) + ")";
            ui->list_programmer_relations->addItem(QString::fromStdString(item_str));
        }
    }
    else
    {
        ui->label_programmer_relations->hide();
        ui->list_programmer_relations->hide();
    }
}

bool ViewProgrammerDialog::getRelations()
{
    qDebug() << QString::fromStdString(currentlyViewedPerson.getWholeName());

    relatedComputers = relationService.getRelations(currentlyViewedPerson);

    if(relatedComputers.size() > 0)
        return true;
    else
        return false;
}
