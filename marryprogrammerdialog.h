#ifndef MARRYPROGRAMMERDIALOG_H
#define MARRYPROGRAMMERDIALOG_H

#include <QDialog>
#include "person.h"
#include "computer.h"
#include "computerservice.h"
#include "personservice.h"

namespace Ui {
class MarryProgrammerDialog;
}

class MarryProgrammerDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MarryProgrammerDialog(QWidget *parent = 0);
    ~MarryProgrammerDialog();

    void setProgrammer(const Person& programmerMarrying);

private slots:
    void on_table_computers_activated(const QModelIndex &index);

    void on_table_computers_clicked(const QModelIndex &index);

    void on_pushButton_clicked();

private:
    void displayAllComputers();
    void getAllComputers();

    Ui::MarryProgrammerDialog *ui;

    Person programmerMarrying;
    Computer computerGettingMarried;
    /*
    PersonService personService;
    ComputerService computerService;

    CompContainer currentlyDisplayedComputers;
    CompContainer currentComputers;
    */

};

#endif // MARRYPROGRAMMERDIALOG_H
