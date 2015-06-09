#ifndef UPGRADEWINDOW_H
#define UPGRADEWINDOW_H

#include <QDialog>

namespace Ui {
class upgradeWindow;
}

class upgradeWindow : public QDialog
{
    Q_OBJECT

public:
    explicit upgradeWindow(QWidget *parent = 0);
    ~upgradeWindow();
    void forceUpdate();

private slots:
    void on_shieldUpButton_clicked();

    void on_healthUpButton_clicked();

    void on_powUpButton_clicked();

    void on_accUpButton_clicked();

    void on_pierceUpButton_clicked();

    void on_armorUpButton_clicked();

    void on_engUpButton_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_7_clicked();

private:
    Ui::upgradeWindow *ui;
};

#endif // UPGRADEWINDOW_H
