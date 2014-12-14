#ifndef ADDPROGRAMMERDIALOG_H
#define ADDPROGRAMMERDIALOG_H

#include <QDialog>
#include "utilities.h"

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

private:
    Ui::AddProgrammerDialog *ui;
};

#endif // ADDPROGRAMMERDIALOG_H
