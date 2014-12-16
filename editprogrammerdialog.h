#ifndef EDITPROGRAMMERDIALOG_H
#define EDITPROGRAMMERDIALOG_H

#include <QDialog>

namespace Ui {
class EditProgrammerDialog;
}

class EditProgrammerDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EditProgrammerDialog(QWidget *parent = 0);
    ~EditProgrammerDialog();

private:
    Ui::EditProgrammerDialog *ui;
};

#endif // EDITPROGRAMMERDIALOG_H
