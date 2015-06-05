#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionSave_triggered()
{

}

void MainWindow::on_actionLoad_triggered()
{

}


void MainWindow::on_attackButton_clicked()
{

}

void MainWindow::on_upgradeButton_clicked()
{

}

void MainWindow::on_jumpButton_clicked()
{

}

void MainWindow::on_specPowerButton_clicked()
{

}
