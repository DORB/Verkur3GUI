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
    QString year = QString::fromStdString(utils::int2str(computer.getBuildYear()));
    ui->label_title_computer->setText(QString("<h2>%1, %2</h2>").arg(name, year));

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



    QString computer_type = QString::fromStdString(computer.getType());

    ui->label_computer_type->setText(computer_type);


    QString computer_build_year = QString::fromStdString(utils::int2str(computer.getBuildYear()));

    ui->label_computer_year_built->setText(computer_build_year);


    bool computer_build = computer.getBuild();

    if(computer_build = 1 )
        ui->label_computer_build->setText("Yes");
    else
        ui->label_computer_build->setText("No");

    if(getRelations())
    {
        ui->list_computer_relations->clear();

        for(unsigned int i = 0; i < relatedProgrammers.size(); i++)
        {
            ui->list_computer_relations->addItem(QString::fromStdString(relatedProgrammers[i].getWholeName()));
        }
    }
    else
    {
        ui->label_relations_for_computer->hide();
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
