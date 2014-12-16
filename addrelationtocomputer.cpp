#include "addrelationtocomputer.h"
#include "ui_addrelationtocomputer.h"

AddRelationToComputer::AddRelationToComputer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddRelationToComputer)
{
    ui->setupUi(this);

    ui->button_finish->setEnabled(false);
    ui->input_search_programmers->setPlaceholderText("Search Programmers...");

    getAllProgrammers();
}

AddRelationToComputer::~AddRelationToComputer()
{
    delete ui;
}

void AddRelationToComputer::getAllProgrammers()
{
    currentProgrammers = programmerService.getAllProgrammers("first_name", false);
    displayAllProgrammers();
}

void AddRelationToComputer::displayAllProgrammers()
{
    ui->list_programmers_to_relate->clear();

    currentlyDisplayedProgrammers.clear();

    for(unsigned int i = 0; i < currentProgrammers.size(); i++)
    {
        Person currentProgrammer = currentProgrammers[i];

        string searchString = ui->input_search_programmers->text().toStdString();

        if(currentProgrammer.contains(searchString))
        {
            string item_str = currentProgrammer.getWholeName() + " (";
            item_str += currentProgrammer.getLifespan() + ")";
            ui->list_programmers_to_relate->addItem(QString::fromStdString(item_str));

            currentlyDisplayedProgrammers.push_back(currentProgrammer);
        }
    }
}

void AddRelationToComputer::setComputer(const Computer &computer)
{
    currentComputer = computer;

    QString comp_name = QString::fromStdString(currentComputer.getName());
    ui->label_the_computer->setText(QString("<h2>Add Relations for %1").arg(comp_name));
}

void AddRelationToComputer::on_input_search_programmers_textChanged(const QString &arg1)
{
    displayAllProgrammers();
}

void AddRelationToComputer::on_button_cancel_clicked()
{
    close();
}

void AddRelationToComputer::on_button_finish_clicked()
{
    int index = ui->list_programmers_to_relate->currentIndex().row();
    Person chosenProgrammer = currentlyDisplayedProgrammers[index];

    relationService.addRelations(chosenProgrammer, currentComputer);

    close();
}

void AddRelationToComputer::on_list_programmers_to_relate_clicked(const QModelIndex &index)
{
    ui->button_finish->setEnabled(true);
}
