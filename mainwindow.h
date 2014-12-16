#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include "personservice.h"
#include "computerservice.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void disableButtons();
    void clearSelections();
private slots:
    void on_input_search_programmers_textChanged(const QString &arg1);

    void on_input_search_computers_textChanged(const QString &arg1);

    void on_tab_choice_tabBarClicked(int index);

    void on_button_add_programmer_clicked();

    void on_action_new_programmer_triggered();

    void on_table_programmers_clicked(const QModelIndex &index);

    void on_button_remove_programmer_clicked();

    void on_table_programmers_doubleClicked(const QModelIndex &index);

    void on_button_add_computer_clicked();

    void on_button_remove_computer_clicked();

    void on_dropdown_sort_by_currentIndexChanged(const QString &arg1);

    void on_dropdown_computers_sort_by_currentIndexChanged(const QString &arg1);

    void on_checkbox_computers_descending_toggled(bool checked);

    void on_checkbox_programmer_descending_toggled(bool checked);

    void on_table_computers_doubleClicked(const QModelIndex &index);

    void on_action_new_computer_triggered();

    void on_table_programmers_customContextMenuRequested(const QPoint &pos);

    void on_action_Delete_Programmer_triggered();

    void on_table_computers_customContextMenuRequested(const QPoint &pos);

    void on_action_New_Computer_triggered();

    void on_action_Delete_Computer_triggered();

    void on_button_add_relation_programmer_clicked();

    void on_action_Edit_Programmer_triggered();

    void on_button_add_relation_computer_clicked();

    void on_table_computers_clicked(const QModelIndex &index);

    void on_action_new_relation_programmer_triggered();

    void on_action_new_relation_computer_triggered();

    void on_action_Edit_Computer_triggered();

    void on_action_view_Computer_triggered();

    void on_action_view_Programmer_triggered();

    void on_button_view_programmer_clicked();

    void on_button_view_computer_clicked();

private:
    void getAllProgrammers();
    void displayAllProgrammers();

    void getAllComputers();
    void displayAllComputers();

    Ui::MainWindow *ui;

    PersonService programmerService;
    ComputerService computerService;

    PersonContainer currentProgrammers;
    PersonContainer currentlyDisplayedProgrammers;

    CompContainer currentComputers;
    CompContainer currentlyDisplayedComputers;

    QString currentProgrammerSortColumn;
    bool currentProgrammerSortDesc;
    QString currentComputerSortColumn;
    bool currentComputerSortDesc;
};

#endif // MAINWINDOW_H
