#include "marryprogrammerdialog.h"
#include "ui_marryprogrammerdialog.h"

MarryProgrammerDialog::MarryProgrammerDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MarryProgrammerDialog)
{
    ui->setupUi(this);
    ui->button_marry->setEnabled(false);

    ui->input_search_computers_marrying->setPlaceholderText("Search computers...");

    getAllComputers();
}

MarryProgrammerDialog::~MarryProgrammerDialog()
{
    delete ui;
}

void MarryProgrammerDialog::on_table_computers_activated(const QModelIndex &index)
{

}

void MarryProgrammerDialog::on_table_computers_clicked(const QModelIndex &index)
{
    ui->button_marry->setEnabled(true);
}


void MarryProgrammerDialog::setProgrammer(const Person &programmer)
{
    programmerMarrying = programmer;
    qDebug() << QString::fromStdString(programmer.getFName());
    ui->label_the_programmer->setText(QString("<h3>Who do you want %1 to marry?</h3>").arg(QString::fromStdString(programmerMarrying.getFName())));
}

void MarryProgrammerDialog::on_pushButton_clicked()
{
    close();
}


void MarryProgrammerDialog::getAllComputers()
{
    /*
    currentComputers = computerService.getAllComputers("ID", false);
    displayAllComputers();
    */
}

void MarryProgrammerDialog::displayAllComputers()
{
/*
    ui->table_computers_marrying->clearContents();

    ui->table_computers_marrying->setRowCount(currentComputers.size());

    currentlyDisplayedComputers.clear();

    for(unsigned int i = 0; i < currentComputers.size(); ++i)
    {
        Computer currentComputer = currentComputers[i];

        string searchString = ui->input_search_computers_marrying->text().toStdString();

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

            ui->table_computers_marrying->setItem(currentRow, 0, new QTableWidgetItem(compName));
            ui->table_computers_marrying->setItem(currentRow, 1, new QTableWidgetItem(compType));
            ui->table_computers_marrying->setItem(currentRow, 2, new QTableWidgetItem(compBuildYear));
            ui->table_computers_marrying->setItem(currentRow, 3, new QTableWidgetItem(compBuilt));

            currentlyDisplayedComputers.push_back(currentComputer);
        }
    }

    ui->table_computers_marrying->setRowCount(currentlyDisplayedComputers.size());

    ui->table_computers_marrying->setColumnWidth(0, 300);
    ui->table_computers_marrying->setColumnWidth(1,180);
    ui->table_computers_marrying->setColumnWidth(2, 50);
    */
}
