#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "classwindow.h"
#include "enemy.h"
#include "upgradewindow.h"

int playerClass;
summit Human;
enemy AI;
int humanShieldCooldown;
int aiShieldCooldown;
int Scrap;

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
    if (*AI.flagIsDead == false && *Human.flagIsDead == false)
    {
        int hitModifier;
        hitModifier = (AI.getEnginesLevel()  - Human.getAccuracy()) * 10;
        int result = rand() % 100 + 1;
        if (result >= hitModifier + 20)
        {
            if (AI.getShields())
            {
                AI.setShields(AI.getShields() - 1 - (Human.getPierce() / 2));
                aiShieldCooldown = turnNumber + 5;
                if (AI.getShields() < 0)
                {
                    AI.setShields(0);
                    AI.setHealth(AI.getHealth() - (Human.getWeaponPower() - (AI.getArmorLevel() - Human.getPierce())));
                    if (AI.getHealth() <= 0)
                    {
                        *AI.flagIsDead = true;
                        Scrap += 30 + sectorNumber * 5 + rand() %10;
                    }
                }
            }
            else
            {
                AI.setHealth(AI.getHealth() - (Human.getWeaponPower() - (AI.getArmorLevel() - Human.getPierce())));
                if (AI.getHealth() <= 0)
                {
                    *AI.flagIsDead = true;
                    Scrap += 30 + sectorNumber * 5 + rand() %10;
                }
            }
        }
    forceUpdateEnemy();
    forceUpdatePlayer();
    }
    if (*AI.flagIsDead == false)
    {
        int hitModifier;
        hitModifier = (Human.getEnginesLevel()  - AI.getAccuracy()) * 10;
        int result = rand() % 100 + 1;
        if (result >= hitModifier + 20)
        {
            if (Human.getShields())
            {
                Human.setShields(Human.getShields() - 1 - (AI.getPierce() / 2));
                humanShieldCooldown = turnNumber + 5;
                if (Human.getShields() < 0)
                {
                    Human.setShields(0);
                    Human.setHealth(Human.getHealth() - (AI.getWeaponPower() - (Human.getArmorLevel() - AI.getPierce())));
                    if (Human.getHealth() <= 0)
                    {
                        *Human.flagIsDead = true;
                    }
                }
            }
            else
            {
                Human.setHealth(Human.getHealth() - (AI.getWeaponPower() - (Human.getArmorLevel() - AI.getPierce())));
                if (Human.getHealth() <= 0)
                {
                    *Human.flagIsDead = true;
                }
            }
        }
    }
    else;
    turnNumber++;
    if (humanShieldCooldown == turnNumber)
        Human.setShields(Human.getMaxShields());
    if (aiShieldCooldown == turnNumber)
        AI.setShields(AI.getMaxShields());
    forceUpdateSector();
    forceUpdateEnemy();
    forceUpdatePlayer();
}

void MainWindow::on_upgradeButton_clicked()
{
    upgradeWindow upgradewindow;
    upgradewindow.setModal(true);
    upgradewindow.exec();
}

void MainWindow::on_jumpButton_clicked()
{
    if (zoneNumber < 9)
    {
        zoneNumber++;
        AI.rollEnemy(sectorNumber);
    }
    else if (zoneNumber == 9)
    {
        zoneNumber++;
        AI.rollBoss(sectorNumber);
    }
    else if  (zoneNumber == 10)
    {
        zoneNumber = 1;
        sectorNumber++;
        AI.rollEnemy(sectorNumber);
    }
    turnNumber = 1;
    Human.setShields(Human.getMaxShields());
    this->forceUpdateSector();
    this->forceUpdateEnemy();
    this->forceUpdatePlayer();
}

void MainWindow::on_specPowerButton_clicked()
{
    if (*Human.shipClass == 1)
    {
        if (!(*Human.battleship::flagSpecialPowerOn))
        {
            Human.battleship::specialPowerOn();
            *Human.battleship::flagSpecialPowerOn = true;
        }
        else
        {
            Human.battleship::specialPowerOff();
            *Human.battleship::flagSpecialPowerOn = false;
        }
    }
    else if (*Human.shipClass == 2)
    {
        if (!(*Human.cruiser::flagSpecialPowerOn))
        {
            Human.cruiser::specialPowerOn();
            *Human.cruiser::flagSpecialPowerOn = true;
        }
        else
        {
            Human.cruiser::specialPowerOff();
            *Human.cruiser::flagSpecialPowerOn = false;
        }
    }
    else
    {
        if (!(*Human.destroyer::flagSpecialPowerOn))
        {
            Human.destroyer::specialPowerOn();
            *Human.destroyer::flagSpecialPowerOn = true;
        }
        else
        {
            Human.destroyer::specialPowerOff();
            *Human.destroyer::flagSpecialPowerOn = false;
        }
    }
    forceUpdatePlayer();
}

void MainWindow::on_actionNew_Game_triggered()
{
       if (*Human.battleship::flagSpecialPowerOn)
       {
           Human.battleship::specialPowerOff();
           *Human.battleship::flagSpecialPowerOn = false;
       }
       if (*Human.cruiser::flagSpecialPowerOn)
       {
           Human.cruiser::specialPowerOff();
           *Human.cruiser::flagSpecialPowerOn = false;
       }
       if (*Human.destroyer::flagSpecialPowerOn)
       {
           Human.destroyer::specialPowerOff();
           *Human.destroyer::flagSpecialPowerOn = false;
       }
       Human.createClass(playerClass);
       turnNumber = 0;
       zoneNumber = 0;
       sectorNumber = 1;
       Scrap = 0;
       this->forceUpdateSector();
       this->forceUpdatePlayer();
}

void MainWindow::on_actionChoose_Class_triggered()
{
    classwindow classwindow;
    classwindow.setModal(true);
    classwindow.exec();
}

void MainWindow::forceUpdatePlayer()
{
    ui->lcdNumber_5->display(Human.getHealth());
    ui->lcdNumber_6->display(Human.getMaxHealth());
    ui->lcdNumber_7->display(Human.getShields());
    ui->lcdNumber_8->display(Human.getMaxShields());
    ui->lcdNumber->display(Human.getWeaponPower());
    ui->lcdNumber_10->display(Human.getAccuracy());
    ui->lcdNumber_2->display(Human.getPierce());
    ui->lcdNumber_3->display(Human.getArmorLevel());
    ui->lcdNumber_4->display(Human.getEnginesLevel());
    ui->lcdNumber_20->display(Scrap);

}

void MainWindow::forceUpdateEnemy()
{
    ui->lcdNumber_12->display(AI.getHealth());
    ui->lcdNumber_13->display(AI.getMaxHealth());
    ui->lcdNumber_11->display(AI.getShields());
    ui->lcdNumber_9->display(AI.getMaxShields());
    ui->lcdNumber_14->display(AI.getWeaponPower());
    ui->lcdNumber_18->display(AI.getAccuracy());
    ui->lcdNumber_17->display(AI.getPierce());
    ui->lcdNumber_15->display(AI.getArmorLevel());
    ui->lcdNumber_16->display(AI.getEnginesLevel());
}

void MainWindow::forceUpdateSector()
{
    ui->lcdNumber_19->display(turnNumber);
    ui->lcdNumber_24->display(zoneNumber);
    ui->lcdNumber_25->display(sectorNumber);
}
