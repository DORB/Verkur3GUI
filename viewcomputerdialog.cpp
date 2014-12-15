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
    ui->label_title_computer->setText(QString("<h2>%1</h2>").arg(QString::fromStdString(computer.toString())));


    QPixmap pixmap(QString::fromStdString(computer.getimagePath()));

    int imageLabelWidth = ui->label_image_computer->width();

    QPixmap scaledPixMap = pixmap.scaledToWidth(imageLabelWidth);

    ui->label_image_computer->setPixmap(scaledPixMap);


    QString computer_type = QString::fromStdString(computer.getType());

    ui->label_computer_type->setText(computer_type);


    QString computer_build_year = QString::fromStdString(utils::int2str(computer.getBuildYear()));

    ui->label_computer_year_built->setText(computer_build_year);


    bool computer_build = computer.getBuild();

    if(computer_build = 1 )
        ui->label_computer_build->setText("Yes");
    else
        ui->label_computer_build->setText("No");
}

void ViewComputerDialog::on_button_close_window_computer_clicked()
{
    close();
}
