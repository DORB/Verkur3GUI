#ifndef EDITPROGRAMMERDIALOG_H
#define EDITPROGRAMMERDIALOG_H

#include <QDialog>
#include "person.h"
#include "personservice.h"

namespace Ui {
class EditProgrammerDialog;
}

class EditProgrammerDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EditProgrammerDialog(QWidget *parent = 0);
    ~EditProgrammerDialog();

public slots:
    void editProgrammer(const Person &programmer);
    void on_button_cancel_add_programmer_clicked();
    void on_button_add_programmer_clicked();

private:
    Ui::EditProgrammerDialog *ui;
    Person currentProgrammer;
    PersonService programmerService;

    void validate();

    bool first_name_valid;
    bool last_name_valid;
    bool nationality_valid;
    bool year_of_birth_valid;
    bool year_of_death_valid;
    bool sex_valid;
};

#endif // EDITPROGRAMMERDIALOG_H
