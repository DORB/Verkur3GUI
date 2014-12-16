#include "addrelationtoprogrammer.h"
#include "ui_addrelationtoprogrammer.h"

AddRelationToProgrammer::AddRelationToProgrammer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddRelationToProgrammer)
{
    ui->setupUi(this);

    ui->button_finish->setEnabled(false);
    ui->input_search_computers->setPlaceholderText("Search Computers...");

    getAllComputers();
}

AddRelationToProgrammer::~AddRelationToProgrammer()
{
    delete ui;
}

void AddRelationToProgrammer::getAllComputers()
{
    currentComputers = computerService.getAllComputers("ID", false);
    displayAllComputers();
}

void AddRelationToProgrammer::displayAllComputers()
{
    ui->list_computers_to_relate->clear();

    currentlyDisplayedComputers.clear();

    for(unsigned int i = 0; i < currentComputers.size(); i++)
    {
        Computer currentComputer = currentComputers[i];

        string searchString = ui->input_search_computers->text().toStdString();

        if(currentComputer.contains(searchString))
        {
            string item_str = currentComputer.getName() + " (";
            item_str += utils::int2str(currentComputer.getBuildYear()) + ")";
            ui->list_computers_to_relate->addItem(QString::fromStdString(item_str));

            currentlyDisplayedComputers.push_back(currentComputer);
        }
    }
}

void AddRelationToProgrammer::setProgrammer(const Person& programmer)
{
    currentProgrammer = programmer;

    QString prog_name = QString::fromStdString(currentProgrammer.getFName());
    ui->label_the_programmer->setText(QString("<h2>Add Relations for %1</h2>").arg(prog_name));

}

void AddRelationToProgrammer::on_button_cancel_clicked()
{
    close();
}

void AddRelationToProgrammer::on_list_computers_to_relate_clicked(const QModelIndex &index)
{
    ui->button_finish->setEnabled(true);
}


void AddRelationToProgrammer::on_input_search_computers_textChanged(const QString &arg1)
{
    displayAllComputers();
}

void AddRelationToProgrammer::on_button_finish_clicked()
{
    int index = ui->list_computers_to_relate->currentIndex().row();
    Computer chosenComputer = currentlyDisplayedComputers[index];

    relationService.addRelations(currentProgrammer, chosenComputer);

    close();
}
