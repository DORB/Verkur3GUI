#ifndef ADDRELATIONTOCOMPUTER_H
#define ADDRELATIONTOCOMPUTER_H

#include <QDialog>
#include "personservice.h"
#include "relationservice.h"

namespace Ui {
class AddRelationToComputer;
}

class AddRelationToComputer : public QDialog
{
    Q_OBJECT

public:
    explicit AddRelationToComputer(QWidget *parent = 0);
    ~AddRelationToComputer();

    void setComputer(const Computer& computer);
    void getAllProgrammers();
    void displayAllProgrammers();

private slots:
    void on_input_search_programmers_textChanged(const QString &arg1);

    void on_button_cancel_clicked();

    void on_button_finish_clicked();

    void on_list_programmers_to_relate_clicked(const QModelIndex &index);

private:
    Ui::AddRelationToComputer *ui;

    PersonService programmerService;
    RelationService relationService;

    Computer currentComputer;
    PersonContainer currentProgrammers;
    PersonContainer currentlyDisplayedProgrammers;
};

#endif // ADDRELATIONTOCOMPUTER_H
