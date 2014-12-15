#ifndef VIEWCOMPUTERDIALOG_H
#define VIEWCOMPUTERDIALOG_H

#include <QDialog>
#include "computer.h"


namespace Ui {
class ViewComputerDialog;
}

class ViewComputerDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ViewComputerDialog(QWidget *parent = 0);
    ~ViewComputerDialog();

    void setComputer(Computer computer);

private:
    Ui::ViewComputerDialog *ui;
};

#endif // VIEWCOMPUTERDIALOG_H
