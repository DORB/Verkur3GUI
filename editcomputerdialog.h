#ifndef EDITCOMPUTERDIALOG_H
#define EDITCOMPUTERDIALOG_H

#include <QDialog>
#include "computer.h"
#include "computerservice.h"

namespace Ui {
class EditComputerDialog;
}

class EditComputerDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EditComputerDialog(QWidget *parent = 0);
    ~EditComputerDialog();

    void editComputer(const Computer &computer);

private slots:
    void on_button_cancel_edit_computer_clicked();
    void on_button_edit_computer_clicked();
    void on_input_edit_computers_year_textChanged(const QString &arg1);
    void on_button_browse_computer_image_clicked();
    void on_input_edit_computers_name_textChanged(const QString &arg1);
    void on_input_edit_computers_type_textChanged(const QString &arg1);
private:
    Ui::EditComputerDialog *ui;
    Computer currentComputer;
    ComputerService computerService;

    void validate();
    bool name_valid;
    bool type_valid;
    bool year_built_valid;

};

#endif // EDITCOMPUTERDIALOG_H
