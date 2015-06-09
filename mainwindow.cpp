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

void MainWindow::on_attackButton_clicked()
{
    QPixmap playerBattleshipDead("D:/Kody/QT/Projekt/Images/PBsD.png");
    QPixmap playerCruiserDead("D:/Kody/QT/Projekt/Images/PCrD.png");
    QPixmap playerDestroyerDead("D:/Kody/QT/Projekt/Images/PDrD.png");
    QPixmap enemyFighterDead ("D:/Kody/QT/Projekt/Images/EFtD.png");
    QPixmap enemyDestroyerDead ("D:/Kody/QT/Projekt/Images/EDrD.png");
    QPixmap enemyCruiserDead ("D:/Kody/QT/Projekt/Images/ECrD.png");
    QPixmap enemyBomberDead ("D:/Kody/QT/Projekt/Images/EBmD.png");
    QPixmap enemyBossDead ("D:/Kody/QT/Projekt/Images/EBsD.png");
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
                        if (*AI.enemyClass == 1)
                            ui->label_pic_enemy->setPixmap(enemyFighterDead);
                        else if (*AI.enemyClass == 2)
                            ui->label_pic_enemy->setPixmap(enemyDestroyerDead);
                        else if  (*AI.enemyClass == 3)
                            ui->label_pic_enemy->setPixmap(enemyBomberDead);
                        else if (*AI.enemyClass == 4)
                            ui->label_pic_enemy->setPixmap(enemyCruiserDead);
                        else if (*AI.enemyClass == 5)
                            ui->label_pic_enemy->setPixmap(enemyBossDead);
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
                    if (*AI.enemyClass == 1)
                        ui->label_pic_enemy->setPixmap(enemyFighterDead);
                    else if (*AI.enemyClass == 2)
                        ui->label_pic_enemy->setPixmap(enemyDestroyerDead);
                    else if  (*AI.enemyClass == 3)
                        ui->label_pic_enemy->setPixmap(enemyBomberDead);
                    else if (*AI.enemyClass == 4)
                        ui->label_pic_enemy->setPixmap(enemyCruiserDead);
                    else if (*AI.enemyClass == 5)
                        ui->label_pic_enemy->setPixmap(enemyBossDead);
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
                        if (*Human.shipClass == 1)
                            ui->label_pic_player->setPixmap(playerBattleshipDead);
                        else if (*Human.shipClass == 2)
                            ui->label_pic_player->setPixmap(playerCruiserDead);
                        else
                            ui->label_pic_player->setPixmap(playerDestroyerDead);
                    }
                }
            }
            else
            {
                Human.setHealth(Human.getHealth() - (AI.getWeaponPower() - (Human.getArmorLevel() - AI.getPierce())));
                if (Human.getHealth() <= 0)
                {
                    *Human.flagIsDead = true;
                    if (*Human.shipClass == 1)
                        ui->label_pic_player->setPixmap(playerBattleshipDead);
                    else if (*Human.shipClass == 2)
                        ui->label_pic_player->setPixmap(playerCruiserDead);
                    else
                        ui->label_pic_player->setPixmap(playerDestroyerDead);
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
    QPixmap enemyFighter("D:/Kody/QT/Projekt/Images/EFt.png");
    QPixmap enemyDestroyer ("D:/Kody/QT/Projekt/Images/EDr.png");
    QPixmap enemyCruiser ("D:/Kody/QT/Projekt/Images/ECr.png");
    QPixmap enemyBomber ("D:/Kody/QT/Projekt/Images/EBm.png");
    QPixmap enemyBoss ("D:/Kody/QT/Projekt/Images/EBs.png");
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
    if (*AI.enemyClass == 1)
        ui->label_pic_enemy->setPixmap(enemyFighter);
    else if (*AI.enemyClass == 2)
        ui->label_pic_enemy->setPixmap(enemyDestroyer);
    else if  (*AI.enemyClass == 3)
        ui->label_pic_enemy->setPixmap(enemyBomber);
    else if (*AI.enemyClass == 4)
        ui->label_pic_enemy->setPixmap(enemyCruiser);
    else if (*AI.enemyClass == 5)
        ui->label_pic_enemy->setPixmap(enemyBoss);
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
    QPixmap playerBattleship ("D:/Kody/QT/Projekt/Images/PBs.png");
    QPixmap playerCruiser("D:/Kody/QT/Projekt/Images/PCr.png");
    QPixmap playerDestroyer("D:/Kody/QT/Projekt/Images/PDr.png");
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
       if (*Human.shipClass == 1)
           ui->label_pic_player->setPixmap(playerBattleship);
       else if (*Human.shipClass == 2)
           ui->label_pic_player->setPixmap(playerCruiser);
       else
           ui->label_pic_player->setPixmap(playerDestroyer);
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
