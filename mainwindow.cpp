#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "utilities.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    currentProgrammerSortColumn = "ID";

    ui->input_search_programmers->setPlaceholderText("Search programmers...");

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
}

void MainWindow::on_input_search_programmers_textChanged(const QString &arg1)
{
    displayAllProgrammers();
}
