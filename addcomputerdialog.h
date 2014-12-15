#ifndef ADDCOMPUTERDIALOG_H
#define ADDCOMPUTERDIALOG_H

#include <QDialog>

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

    void on_button_add_new_computer_toggled(bool checked);

private:
    Ui::AddComputerDialog *ui;
};

#endif // ADDCOMPUTERDIALOG_H
