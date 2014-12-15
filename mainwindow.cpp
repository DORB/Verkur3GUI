#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "utilities.h"
#include "addprogrammerdialog.h"
#include "addcomputerdialog.h"
#include "removecomputerdialog.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    currentProgrammerSortColumn = "ID";
    currentProgrammerSortDesc = false;
    currentComputerSortColumn = "ID";
    currentComputerSortDesc = false;

    ui->input_search_programmers->setPlaceholderText("Search programmers...");
    ui->input_search_computers->setPlaceholderText("Search computers...");

    ui->button_remove_programmer->setDisabled(true);

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
    switch(index)
    {
    case 0: displayAllProgrammers(); break;
    case 1: displayAllComputers(); break;
    }
}

void MainWindow::on_button_add_programmer_clicked()
{
    AddProgrammerDialog addProgrammerDialog;
    addProgrammerDialog.exec();

    getAllProgrammers();
}

void MainWindow::on_action_new_programmer_triggered()
{
    AddProgrammerDialog addProgrammerDialog;
    addProgrammerDialog.exec();

    getAllProgrammers();
}

void MainWindow::on_table_programmers_clicked(const QModelIndex &index)
{
    ui->button_remove_programmer->setEnabled(true);
    // qDebug() << index;
}

void MainWindow::on_button_remove_programmer_clicked()
{
    /*
    int index = ui->table_programmers->currentIndex().row();

    RemoveProgrammerDialog removeProgrammerDialog;
    removeProgrammerDialog.setProgrammer(currentlyDisplayedProgrammers[index]);
    removeProgrammerDialog.exec();

    getAllProgrammers();
    */
}

void MainWindow::on_table_programmers_doubleClicked(const QModelIndex &index)
{
    // qDebug() << index.row();
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
