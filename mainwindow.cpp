#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "utilities.h"
#include "addprogrammerdialog.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    currentProgrammerSortColumn = "ID";
    currentComputerSortColumn = "ID";

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
    currentProgrammers = programmerService.getAllProgrammers(currentProgrammerSortColumn);
    displayAllProgrammers();
}

void MainWindow::getAllComputers()
{
    currentComputers = computerService.getAllComputers(currentComputerSortColumn);
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
    int index = ui->table_programmers->currentIndex().row();

    programmerService.removeProgrammer(currentlyDisplayedProgrammers[index]);
    getAllProgrammers();
}

void MainWindow::on_table_programmers_doubleClicked(const QModelIndex &index)
{
    qDebug() << index.row();
}
