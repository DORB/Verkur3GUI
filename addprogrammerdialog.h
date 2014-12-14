#ifndef ADDPROGRAMMERDIALOG_H
#define ADDPROGRAMMERDIALOG_H

#include <QDialog>
#include "utilities.h"
#include "personservice.h"
#include "computerservice.h"

namespace Ui {
class AddProgrammerDialog;
}

class AddProgrammerDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddProgrammerDialog(QWidget *parent = 0);
    ~AddProgrammerDialog();

private slots:
    void on_check_add_programmer_not_dead_toggled(bool checked);

    void on_button_add_programmer_clicked();

    void on_input_add_programmers_year_of_birth_textChanged(const QString &arg1);

    void on_button_cancel_add_programmer_clicked();

private:
    Ui::AddProgrammerDialog *ui;

    PersonService programmerService;
    ComputerService computerService;
};

#endif // ADDPROGRAMMERDIALOG_H
