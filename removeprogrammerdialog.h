#ifndef REMOVEPROGRAMMERDIALOG_H
#define REMOVEPROGRAMMERDIALOG_H

#include <QDialog>
#include "person.h"
#include "personservice.h"

namespace Ui {
class RemoveProgrammerDialog;
}

class RemoveProgrammerDialog : public QDialog
{
    Q_OBJECT

public:
    explicit RemoveProgrammerDialog(QWidget *parent = 0);
    ~RemoveProgrammerDialog();

    void setProgrammer(const Person& person);

private slots:
    void on_button_remove_programmer_cancel_clicked();
    void on_button_remove_programmer_ok_clicked();

private:
    Ui::RemoveProgrammerDialog *ui;

    Person personRemoved;
    PersonService personService;
};

#endif // REMOVEPROGRAMMERDIALOG_H
