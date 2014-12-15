#include "viewcomputerdialog.h"
#include "ui_viewcomputerdialog.h"

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


//   QPixmap pixmap(QString::fromStdString(car.getImagePath()));

//   int imageLabelWidth = ui->label_image->width();
//   QPixmap scaledPixMap = pixmap.scaledToWidth(imageLabelWidth);

//   ui->label_image->setPixmap(scaledPixMap)




}
