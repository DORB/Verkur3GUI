#include "viewcomputerdialog.h"
#include "ui_viewcomputerdialog.h"
#include "utilities.h"

#include <QPixmap>
#include <QString>

ViewComputerDialog::ViewComputerDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ViewComputerDialog)
{
    ui->setupUi(this);
}

ViewComputerDialog::~ViewComputerDialog()
{
    delete ui;
}

void ViewComputerDialog::setComputer(Computer computer)
{
    currentlyViewedComputer = computer;

    QString name = QString::fromStdString(computer.getName());
    QString type = QString::fromStdString(computer.getType());
    ui->label_title_computer->setText(QString("<h1>%1</h1>").arg(name));
    ui->label_type_computer->setText(QString("<h2>(%2)</h2>").arg(type));

    QString failPic;

    failPic = ":/pics/Images/computer_unknown.png";

    if(computer.getimagePath() == "")
    {
        QPixmap pixmap(failPic);

        int imageLabelWidth = ui->label_image_computer->width();

        QPixmap scaledPixMap = pixmap.scaledToWidth(imageLabelWidth);

        ui->label_image_computer->setPixmap(scaledPixMap);
    }
    else
    {
        QPixmap pixmap(QString::fromStdString(computer.getimagePath()));

        int imageLabelWidth = ui->label_image_computer->width();

        QPixmap scaledPixMap = pixmap.scaledToWidth(imageLabelWidth);

        ui->label_image_computer->setPixmap(scaledPixMap);
    }


    bool computer_build = computer.getBuild();

    if(computer_build == true)
    {
        QString computer_build_year = QString::fromStdString(utils::int2str(computer.getBuildYear()));
        QString comp_build_year = QString("<h3><center>Was built in %1</center></h3>").arg(computer_build_year);
        ui->label_computer_built_year->setText(comp_build_year);
    }
    else
    {
        QString computer_build_year = QString::fromStdString(utils::int2str(computer.getBuildYear()));
        QString comp_build_year = QString("<h3><center>Was worked on in %1, but was not built</center></h3>").arg(computer_build_year);
        ui->label_computer_built_year->setText(comp_build_year);
    }
    if(getRelations())
    {
        ui->list_computer_relations->clear();

        for(unsigned int i = 0; i < relatedProgrammers.size(); i++)
        {
            string item_str = relatedProgrammers[i].getWholeName() + " (";
            item_str += relatedProgrammers[i].getLifespan() + ")";
            ui->list_computer_relations->addItem(QString::fromStdString(item_str));
        }
    }
    else
    {
        ui->label_relations_for_computer->setText("<center>Has no related Programmers.</center>");
        ui->list_computer_relations->hide();
    }
}

void ViewComputerDialog::on_button_close_window_computer_clicked()
{
    close();
}

bool ViewComputerDialog::getRelations()
{
    qDebug() << QString::fromStdString(currentlyViewedComputer.getName());

    relatedProgrammers = relationService.getRelations(currentlyViewedComputer);

    if(relatedProgrammers.size() > 0)
        return true;
    else
        return false;
}
