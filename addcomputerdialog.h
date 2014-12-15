#ifndef ADDCOMPUTERDIALOG_H
#define ADDCOMPUTERDIALOG_H

#include <QDialog>
#include "utilities.h"
#include "computerservice.h"
#include "personservice.h"

namespace Ui {
class AddComputerDialog;
}

class AddComputerDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddComputerDialog(QWidget *parent = 0);
    ~AddComputerDialog();

private slots:
    void on_button_browse_computer_image_clicked();

    void on_button_add_new_computer_clicked();

    void on_input_add_computers_year_textChanged(const QString &arg1);

    void on_button_cancel_add_new_computer_clicked();

    void on_input_add_computers_name_textChanged(const QString &arg1);

    void on_input_add_computers_type_textChanged(const QString &arg1);

private:
    Ui::AddComputerDialog *ui;

    ComputerService computerService;

    void validate();

    bool name_valid;
    bool type_valid;
    bool year_built_valid;
};

#endif // ADDCOMPUTERDIALOG_H
