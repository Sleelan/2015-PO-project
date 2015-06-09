#include "upgradewindow.h"
#include "ui_upgradewindow.h"
#include "mainwindow.h"

upgradeWindow::upgradeWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::upgradeWindow)
{
    ui->setupUi(this);
    if (*Human.shipClass == 1)
    {
        if ((*Human.battleship::flagSpecialPowerOn))
        {
            Human.battleship::specialPowerOff();
            *Human.battleship::flagSpecialPowerOn = false;
        }
    }
    else if (*Human.shipClass == 2)
    {
        if ((*Human.cruiser::flagSpecialPowerOn))
        {
            Human.cruiser::specialPowerOff();
            *Human.cruiser::flagSpecialPowerOn = false;
        }
    }
    else
    {
        if ((*Human.destroyer::flagSpecialPowerOn))
        {
            Human.destroyer::specialPowerOff();
            *Human.destroyer::flagSpecialPowerOn = false;
        }
    }
    forceUpdate();
}

upgradeWindow::~upgradeWindow()
{
    delete ui;
}

void upgradeWindow::on_shieldUpButton_clicked()
{
    if (Scrap >= 10 + 5*Human.getMaxShields())
    {
        Scrap -= 10 + 5*Human.getMaxShields();
        Human.setMaxShields(Human.getMaxShields()+1);
    }
    forceUpdate();
}

void upgradeWindow::on_healthUpButton_clicked()
{
    if (Scrap >= 10 + Human.getMaxHealth())
    {
        Scrap -= 10 + Human.getMaxHealth();
        Human.setMaxHealth(Human.getMaxHealth()+5);
        Human.setHealth(Human.getHealth()+5);
    }
    forceUpdate();
}

void upgradeWindow::on_powUpButton_clicked()
{
    if (Scrap >= 10 + 5*Human.getWeaponPower())
    {
        Scrap -= 10 + 5*Human.getWeaponPower();
        Human.setWeaponPower(Human.getWeaponPower()+1);
    }
    forceUpdate();
}

void upgradeWindow::on_accUpButton_clicked()
{
    if (Scrap >= 10 + 5*Human.getAccuracy())
    {
        Scrap -= 10 + 5*Human.getAccuracy();
        Human.setAccuracy(Human.getAccuracy()+1);
    }
    forceUpdate();
}

void upgradeWindow::on_pierceUpButton_clicked()
{
    if (Scrap >= 50 + 15*Human.getPierce())
    {
         Scrap -= 50 + 15*Human.getPierce();
         Human.setPierce(Human.getPierce()+1);
    }
    forceUpdate();
}

void upgradeWindow::on_armorUpButton_clicked()
{
    if (Scrap >= 10 + 8*Human.getArmorLevel())
    {
        Scrap -= 10 + 8*Human.getArmorLevel();
        Human.setArmorLevel(Human.getArmorLevel()+1);
    }
    forceUpdate();
}

void upgradeWindow::on_engUpButton_clicked()
{
    if (Scrap >= 10 + 5*Human.getEnginesLevel())
    {
        Scrap -= 10 + 5*Human.getEnginesLevel();
        Human.setEnginesLevel(Human.getEnginesLevel()+1);
    }
    forceUpdate();
}

void upgradeWindow::forceUpdate()
{
    ui->lcdNumber->display(Human.getMaxShields());
    ui->lcdNumber_8->display(Human.getMaxHealth());
    ui->lcdNumber_2->display(Human.getWeaponPower());
    ui->lcdNumber_3->display(Human.getAccuracy());
    ui->lcdNumber_4->display(Human.getPierce());
    ui->lcdNumber_5->display(Human.getArmorLevel());
    ui->lcdNumber_6->display(Human.getEnginesLevel());
    ui->lcdNumber_7->display(Scrap);
    ui->lcdNumber_9->display(Human.getHealth());
    ui->lcdNumber_10->display(Human.getMaxHealth());
    ui->lcdNumber_14->display(10 + 5*Human.getMaxShields());
    ui->lcdNumber_15->display(10 + Human.getMaxHealth());
    ui->lcdNumber_16->display(10 + 5*Human.getWeaponPower());
    ui->lcdNumber_17->display(10 + 5*Human.getAccuracy());
    ui->lcdNumber_18->display(50 + 15*Human.getPierce());
    ui->lcdNumber_19->display(10 + 8*Human.getArmorLevel());
    ui->lcdNumber_20->display(10 + 5*Human.getEnginesLevel());
}

void upgradeWindow::on_pushButton_8_clicked()
{
    this->close();
}

void upgradeWindow::on_pushButton_7_clicked()
{
    if (Scrap >=3 && Human.getHealth() < Human.getMaxHealth())
    {
        Human.setHealth(Human.getHealth()+1);
        Scrap -= 3;
        forceUpdate();
    }
}
