#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "utilities.h"
#include "addprogrammerdialog.h"
#include "addcomputerdialog.h"
#include "removecomputerdialog.h"
#include "removeprogrammerdialog.h"
#include "viewcomputerdialog.h"
#include "marryprogrammerdialog.h"
#include "viewprogrammerdialog.h"
#include "addrelationtoprogrammer.h"
#include "editprogrammerdialog.h"
#include "addrelationtocomputer.h"
#include "editcomputerdialog.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->mainToolBar->setVisible(false);
    ui->statusBar->setVisible(false);

    currentProgrammerSortColumn = "ID";
    currentProgrammerSortDesc = false;
    currentComputerSortColumn = "ID";
    currentComputerSortDesc = false;

    ui->input_search_programmers->setPlaceholderText("Search programmers...");
    ui->input_search_computers->setPlaceholderText("Search computers...");

    disableButtons();


    getAllComputers();
    getAllProgrammers();    
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::getAllProgrammers()
{
    currentProgrammers = programmerService.getAllProgrammers(currentProgrammerSortColumn, currentProgrammerSortDesc);
    displayAllProgrammers();
}

void MainWindow::getAllComputers()
{
    currentComputers = computerService.getAllComputers(currentComputerSortColumn, currentComputerSortDesc);
    displayAllComputers();
}

void MainWindow::displayAllProgrammers()
{
    ui->table_programmers->clearContents();

    ui->table_programmers->setRowCount(currentProgrammers.size());

    currentlyDisplayedProgrammers.clear();

    for(unsigned int i = 0; i < currentProgrammers.size(); ++i)
    {
        Person currentProgrammer = currentProgrammers[i];

        string searchString = ui->input_search_programmers->text().toStdString();

        if(currentProgrammer.contains(searchString))
        {
            QString progName = QString::fromStdString(currentProgrammer.getWholeName());
            QString progNationality = QString::fromStdString(currentProgrammer.getNationality());
            QString progBorn = QString::fromStdString(utils::int2str(currentProgrammer.getBY()));
            QString progDead = QString::fromStdString(utils::int2str(currentProgrammer.getDY()));
            QString progSex = QString::fromStdString(currentProgrammer.getSex());

            if(progDead == "0")
                progDead = "-";

            int currentRow = currentlyDisplayedProgrammers.size();

            ui->table_programmers->setItem(currentRow, 0, new QTableWidgetItem(progName));
            ui->table_programmers->setItem(currentRow, 1, new QTableWidgetItem(progNationality));
            ui->table_programmers->setItem(currentRow, 2, new QTableWidgetItem(progBorn));
            ui->table_programmers->setItem(currentRow, 3, new QTableWidgetItem(progDead));
            ui->table_programmers->setItem(currentRow, 4, new QTableWidgetItem(progSex));

            currentlyDisplayedProgrammers.push_back(currentProgrammer);
        }
    }

    ui->table_programmers->setRowCount(currentlyDisplayedProgrammers.size());

    ui->table_programmers->setColumnWidth(0, 300);
    ui->table_programmers->setColumnWidth(1, 170);
    ui->table_programmers->setColumnWidth(2, 50);
    ui->table_programmers->setColumnWidth(3, 50);
    ui->table_programmers->setColumnWidth(4, 30);
}

void MainWindow::displayAllComputers()
{
    ui->table_computers->clearContents();

    ui->table_computers->setRowCount(currentComputers.size());

    currentlyDisplayedComputers.clear();

    for(unsigned int i = 0; i < currentComputers.size(); ++i)
    {
        Computer currentComputer = currentComputers[i];

        string searchString = ui->input_search_computers->text().toStdString();

        if(currentComputer.contains(searchString))
        {
            QString compName = QString::fromStdString(currentComputer.getName());
            QString compType = QString::fromStdString(currentComputer.getType());
            QString compBuildYear = QString::fromStdString(utils::int2str(currentComputer.getBuildYear()));
            bool compBuiltTemp = currentComputer.getBuild();
            QString compBuilt;

            if(compBuiltTemp)
                compBuilt = "Yes";
            else
                compBuilt = "No";

            int currentRow = currentlyDisplayedComputers.size();

            ui->table_computers->setItem(currentRow, 0, new QTableWidgetItem(compName));
            ui->table_computers->setItem(currentRow, 1, new QTableWidgetItem(compType));
            ui->table_computers->setItem(currentRow, 2, new QTableWidgetItem(compBuildYear));
            ui->table_computers->setItem(currentRow, 3, new QTableWidgetItem(compBuilt));

            currentlyDisplayedComputers.push_back(currentComputer);
        }
    }

    ui->table_computers->setRowCount(currentlyDisplayedComputers.size());

    ui->table_computers->setColumnWidth(0, 300);
    ui->table_computers->setColumnWidth(1,180);
    ui->table_computers->setColumnWidth(2, 50);
}

void MainWindow::on_input_search_programmers_textChanged(const QString &arg1)
{
    displayAllProgrammers();
}

void MainWindow::on_input_search_computers_textChanged(const QString &arg1)
{
    displayAllComputers();
}

void MainWindow::on_tab_choice_tabBarClicked(int index)
{
    disableButtons();
    clearSelections();
}

void MainWindow::on_button_add_programmer_clicked()
{
    AddProgrammerDialog addProgrammerDialog;
    addProgrammerDialog.exec();

    clearSelectionAndDisableButtons();

    getAllProgrammers();
}

void MainWindow::on_action_new_programmer_triggered()
{
    AddProgrammerDialog addProgrammerDialog;
    addProgrammerDialog.exec();

    clearSelectionAndDisableButtons();

    getAllProgrammers();
}

void MainWindow::on_table_programmers_clicked(const QModelIndex &index)
{
    ui->button_remove_programmer->setEnabled(true);
    ui->button_add_relation_programmer->setEnabled(true);
    ui->button_view_programmer->setEnabled(true);
    ui->button_programmer_edit->setEnabled(true);
}

void MainWindow::on_button_remove_programmer_clicked()
{ 
    int index = ui->table_programmers->currentIndex().row();
    Person personRemoved = currentlyDisplayedProgrammers[index];

    RemoveProgrammerDialog removeProgrammerDialog;

    removeProgrammerDialog.setProgrammer(personRemoved);

    qDebug() << QString::fromStdString(personRemoved.getFName());

    removeProgrammerDialog.exec();

    clearSelectionAndDisableButtons();

    getAllProgrammers();
}

void MainWindow::on_table_programmers_doubleClicked(const QModelIndex &index)
{
    ViewProgrammerDialog viewProgrammerDialog;
    viewProgrammerDialog.setProgrammer(currentlyDisplayedProgrammers[index.row()]);
    viewProgrammerDialog.exec();

    clearSelectionAndDisableButtons();

    getAllProgrammers();
}

void MainWindow::on_button_remove_computer_clicked()
{
    int index = ui->table_computers->currentIndex().row();
    Computer computerRemoved = currentlyDisplayedComputers[index];

    RemoveComputerDialog removeComputerDialog;

    removeComputerDialog.setComputer(computerRemoved);

    // Veit ekki hvað er í gangi hér, en fallið að ofan virkar ekki nema
    // ég geri qDebug á þetta hér fyrir neðan. Mjög furðulegt.
    qDebug() << QString::fromStdString(computerRemoved.getName());

    removeComputerDialog.exec();

    clearSelectionAndDisableButtons();

    getAllComputers();
}

void MainWindow::on_dropdown_sort_by_currentIndexChanged(const QString &arg1)
{
    QString sort_by;

    if(arg1 == "First name")
        sort_by = "first_name";
    if(arg1 == "Last name")
        sort_by = "last_name";
    if(arg1 == "Nationality")
        sort_by = "nationality";
    if(arg1 == "Year of Birth")
        sort_by = "birth_year";
    if(arg1 == "Year of Death")
        sort_by = "death_year";
    if(arg1 == "Sex")
        sort_by = "sex";
    if(arg1 == "Inserted Order")
        sort_by = "ID";

    currentProgrammerSortColumn = sort_by;

    getAllProgrammers();
}

void MainWindow::on_dropdown_computers_sort_by_currentIndexChanged(const QString &arg1)
{
    QString sort_by;

    if(arg1 == "Name")
        sort_by = "name";
    if(arg1 == "Type")
        sort_by = "type";
    if(arg1 == "Build Year")
        sort_by = "year_built";
    if(arg1 == "Inserted Order")
        sort_by = "ID";

    currentComputerSortColumn  = sort_by;

    getAllComputers();
}

void MainWindow::on_button_add_computer_clicked()
{
   AddComputerDialog addComputerDialog;
   addComputerDialog.exec();

   clearSelectionAndDisableButtons();

   getAllComputers();
}

void MainWindow::on_checkbox_computers_descending_toggled(bool checked)
{
    if(checked)
        currentComputerSortDesc = true;
    else
        currentComputerSortDesc = false;

    getAllComputers();
}

void MainWindow::on_checkbox_programmer_descending_toggled(bool checked)
{
    if(checked)
        currentProgrammerSortDesc = true;
    else
        currentProgrammerSortDesc = false;

    getAllProgrammers();
}

void MainWindow::on_table_computers_doubleClicked(const QModelIndex &index)
{
    ViewComputerDialog viewComputerDialog;
    viewComputerDialog.setComputer(currentlyDisplayedComputers[index.row()]);
    viewComputerDialog.exec();

    clearSelectionAndDisableButtons();

    getAllComputers();
}
void MainWindow::on_action_new_computer_triggered()
{
    AddComputerDialog addComputerDialog;
    addComputerDialog.exec();

    clearSelectionAndDisableButtons();

    getAllComputers();
}

void MainWindow::on_action_New_Computer_triggered()
{
    AddComputerDialog addComputerDialog;
    addComputerDialog.exec();

    clearSelectionAndDisableButtons();

    getAllComputers();
}

void MainWindow::on_table_computers_customContextMenuRequested(const QPoint &pos)
{
    QMenu menu;

    menu.addAction(ui->action_view_Computer);
    menu.addAction(ui->action_New_Computer);
    menu.addAction(ui->action_new_relation_computer);
    menu.addAction(ui->action_Delete_Computer);
    menu.addAction(ui->action_Edit_Computer);

    menu.exec(ui->table_computers->viewport()->mapToGlobal(pos));
}

void MainWindow::on_table_programmers_customContextMenuRequested(const QPoint &pos)
{
    QMenu menu;

    menu.addAction(ui->action_view_Programmer);
    menu.addAction(ui->action_new_programmer);
    menu.addAction(ui->action_new_relation_programmer);
    menu.addAction(ui->action_Delete_Programmer);
    menu.addAction(ui->action_Edit_Programmer);

    menu.exec(ui->table_programmers->viewport()->mapToGlobal(pos));
}

void MainWindow::on_action_Delete_Computer_triggered()
{
    int index = ui->table_computers->currentIndex().row();
    Computer computerRemoved = currentlyDisplayedComputers[index];

    RemoveComputerDialog removeComputerDialog;

    removeComputerDialog.setComputer(computerRemoved);

    // Veit ekki hvað er í gangi hér, en fallið að ofan virkar ekki nema
    // ég geri qDebug á þetta hér fyrir neðan. Mjög furðulegt.
    qDebug() << QString::fromStdString(computerRemoved.getName());

    removeComputerDialog.exec();

    clearSelectionAndDisableButtons();

    getAllComputers();
}

void MainWindow::on_action_Delete_Programmer_triggered()
{
    int index = ui->table_programmers->currentIndex().row();
    Person personRemoved = currentlyDisplayedProgrammers[index];

    RemoveProgrammerDialog removeProgrammerDialog;

    removeProgrammerDialog.setProgrammer(personRemoved);

    qDebug() << QString::fromStdString(personRemoved.getFName());

    removeProgrammerDialog.exec();

    clearSelectionAndDisableButtons();

    getAllProgrammers();
}

void MainWindow::on_button_add_relation_programmer_clicked()
{
    int index = ui->table_programmers->currentIndex().row();
    Person programmerMarrying = currentlyDisplayedProgrammers[index];

    qDebug() << QString::fromStdString(programmerMarrying.getFName());

    AddRelationToProgrammer addRelationToProgrammer;
    addRelationToProgrammer.setProgrammer(programmerMarrying);
    addRelationToProgrammer.exec();

    clearSelectionAndDisableButtons();
}

void MainWindow::on_button_add_relation_computer_clicked()
{
    int index = ui->table_computers->currentIndex().row();
    Computer computerMarrying = currentlyDisplayedComputers[index];

    qDebug() << QString::fromStdString(computerMarrying.getName());

    AddRelationToComputer addRelationToComputer;
    addRelationToComputer.setComputer(computerMarrying);
    addRelationToComputer.exec();

    clearSelectionAndDisableButtons();
}

void MainWindow::on_table_computers_clicked(const QModelIndex &index)
{
    ui->button_remove_computer->setEnabled(true);
    ui->button_add_relation_computer->setEnabled(true);
    ui->button_view_computer->setEnabled(true);
    ui->button_edit_computer->setEnabled(true);
}

void MainWindow::on_action_new_relation_programmer_triggered()
{
    on_button_add_relation_programmer_clicked();
}

void MainWindow::on_action_new_relation_computer_triggered()
{
    on_button_add_relation_computer_clicked();
}

void MainWindow::on_action_Edit_Programmer_triggered()
{
    int index = ui->table_programmers->currentIndex().row();
    Person editProgrammer = currentlyDisplayedProgrammers[index];

    qDebug() << QString::fromStdString(editProgrammer.getFName());

    EditProgrammerDialog edit;
    edit.editProgrammer(editProgrammer);
    edit.exec();

    clearSelectionAndDisableButtons();

    getAllProgrammers();

}

void MainWindow::on_action_Edit_Computer_triggered()
{
    int index = ui->table_computers->currentIndex().row();
    Computer editComputer = currentlyDisplayedComputers[index];

    qDebug() << QString::fromStdString(editComputer.getName());

    EditComputerDialog edit;

    edit.editComputer(editComputer);

    edit.exec();

    clearSelectionAndDisableButtons();

    getAllComputers();
}

void MainWindow::on_action_view_Computer_triggered()
{
    QModelIndex index = ui->table_computers->currentIndex();
    on_table_computers_doubleClicked(index);
}

void MainWindow::on_action_view_Programmer_triggered()
{
    QModelIndex index = ui->table_programmers->currentIndex();
    on_table_programmers_doubleClicked(index);
}

void MainWindow::on_button_view_programmer_clicked()
{
    QModelIndex index = ui->table_programmers->currentIndex();
    on_table_programmers_doubleClicked(index);
}

void MainWindow::on_button_view_computer_clicked()
{
    QModelIndex index = ui->table_computers->currentIndex();
    on_table_computers_doubleClicked(index);
}

void MainWindow::disableButtons()
{
    ui->button_remove_programmer->setDisabled(true);
    ui->button_remove_computer->setDisabled(true);
    ui->button_add_relation_programmer->setDisabled(true);
    ui->button_add_relation_computer->setDisabled(true);
    ui->button_view_computer->setDisabled(true);
    ui->button_view_programmer->setDisabled(true);
    ui->button_programmer_edit->setDisabled(true);
    ui->button_edit_computer->setDisabled(true);
}

void MainWindow::clearSelections()
{
    ui->table_computers->clearSelection();
    ui->table_programmers->clearSelection();
}

void MainWindow::clearSelectionAndDisableButtons()
{
    disableButtons();
    clearSelections();
}

void MainWindow::on_button_programmer_edit_clicked()
{
    on_action_Edit_Programmer_triggered();
}

void MainWindow::on_button_edit_computer_clicked()
{
    on_action_Edit_Computer_triggered();
}
