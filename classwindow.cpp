#include "classwindow.h"
#include "ui_classwindow.h"
#include "player.h"

classwindow::classwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::classwindow)
{
    ui->setupUi(this);
}

classwindow::~classwindow()
{
    delete ui;
}

void classwindow::on_bshipButton_clicked()
{
    playerClass = 1;
}

void classwindow::on_crusButton_clicked()
{
    playerClass = 2;
}

void classwindow::on_dstrButton_clicked()
{
    playerClass = 3;
}

void classwindow::on_confrmButton_clicked()
{
    this->close();
}
