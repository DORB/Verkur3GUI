#ifndef ADDRELATIONTOPROGRAMMER_H
#define ADDRELATIONTOPROGRAMMER_H

#include <QDialog>
#include "computerservice.h"
#include "relationservice.h"

namespace Ui {
class AddRelationToProgrammer;
}

class AddRelationToProgrammer : public QDialog
{
    Q_OBJECT

public:
    explicit AddRelationToProgrammer(QWidget *parent = 0);
    ~AddRelationToProgrammer();

    void setProgrammer(const Person &programmer);
    void getAllComputers();
    void displayAllComputers();
private slots:
    void on_button_cancel_clicked();

    void on_list_computers_to_relate_clicked(const QModelIndex &index);

    void on_input_search_computers_textChanged(const QString &arg1);

    void on_button_finish_clicked();

private:
    Ui::AddRelationToProgrammer *ui;

    ComputerService computerService;
    RelationService relationService;

    Person currentProgrammer;
    CompContainer currentlyDisplayedComputers;
    CompContainer currentComputers;
};

#endif // ADDRELATIONTOPROGRAMMER_H
