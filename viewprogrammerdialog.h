#ifndef VIEWPROGRAMMERDIALOG_H
#define VIEWPROGRAMMERDIALOG_H

#include <QDialog>
#include "person.h"
#include "relationservice.h"
#include "personservice.h"

namespace Ui {
class ViewProgrammerDialog;
}

class ViewProgrammerDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ViewProgrammerDialog(QWidget *parent = 0);
    ~ViewProgrammerDialog();

    void setProgrammer(Person person);
    bool getRelations();

private slots:
    void on_button_view_programmer_close_clicked();

private:
    Ui::ViewProgrammerDialog *ui;

    RelationService relationService;
    PersonService programmerService;
    Person currentlyViewedPerson;
    CompContainer relatedComputers;
};

#endif // VIEWPROGRAMMERDIALOG_H
