#ifndef REMOVEPROGRAMMERDIALOG_H
#define REMOVEPROGRAMMERDIALOG_H

#include <QDialog>

namespace Ui {
class RemoveProgrammerDialog;
}

class RemoveProgrammerDialog : public QDialog
{
    Q_OBJECT

public:
    explicit RemoveProgrammerDialog(QWidget *parent = 0);
    ~RemoveProgrammerDialog();

private:
    Ui::RemoveProgrammerDialog *ui;
};

#endif // REMOVEPROGRAMMERDIALOG_H
