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

private slots:
    void on_button_close_window_computer_clicked();

private:
    Ui::ViewComputerDialog *ui;
};

#endif // VIEWCOMPUTERDIALOG_H
