#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "personservice.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_input_search_programmers_textChanged(const QString &arg1);

private:
    void getAllProgrammers();
    void displayAllProgrammers();

    Ui::MainWindow *ui;

    PersonService programmerService;

    PersonContainer currentProgrammers;
    PersonContainer currentlyDisplayedProgrammers;

    QString currentProgrammerSortColumn;
};

#endif // MAINWINDOW_H
