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

public slots:
    void editComputer(const Computer &computer);
private:
    Ui::EditComputerDialog *ui;
    Computer currentComputer;

};

#endif // EDITCOMPUTERDIALOG_H
