#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "player.h"
#include "summit.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void forceUpdatePlayer ();
    QPixmap playerBattleship;
    QPixmap playerBattleshipDead;
    QPixmap playerCruiser;
    QPixmap playerCruiserDead;
    QPixmap playerDestroyer;
    QPixmap playerDestroyerDead;
    QPixmap enemyFighter;
    QPixmap enemyFighterDead;
    QPixmap enemyDestroyer;
    QPixmap enemyDestroyerDead;
    QPixmap enemyCruiser;
    QPixmap enemyCruiserDead;
    QPixmap enemyBomber;
    QPixmap enemyBomberDead;
    QPixmap enemyBoss;
    QPixmap enemyBossDead;

private slots:

    void on_attackButton_clicked();

    void on_upgradeButton_clicked();

    void on_jumpButton_clicked();

    void on_specPowerButton_clicked();

    void on_actionNew_Game_triggered();

    void on_actionChoose_Class_triggered();

    void forceUpdateEnemy ();

    void forceUpdateSector ();

private:
    Ui::MainWindow *ui;
};
extern summit Human;
extern int Scrap;
#endif // MAINWINDOW_H
