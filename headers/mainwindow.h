#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_actionSave_triggered();

    void on_actionLoad_triggered();

    void on_attackButton_clicked();

    void on_upgradeButton_clicked();

    void on_jumpButton_clicked();

    void on_specPowerButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
