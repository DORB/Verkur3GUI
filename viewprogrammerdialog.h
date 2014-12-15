#ifndef VIEWPROGRAMMERDIALOG_H
#define VIEWPROGRAMMERDIALOG_H

#include <QDialog>
#include "person.h"

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

private slots:
    void on_pushButton_clicked();

private:
    Ui::ViewProgrammerDialog *ui;
};

#endif // VIEWPROGRAMMERDIALOG_H
