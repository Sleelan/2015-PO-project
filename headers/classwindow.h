#ifndef CLASSWINDOW_H
#define CLASSWINDOW_H

#include <QDialog>

namespace Ui {
class classwindow;
}

class classwindow : public QDialog
{
    Q_OBJECT

public:
    explicit classwindow(QWidget *parent = 0);
    ~classwindow();

private slots:
    void on_bshipButton_clicked();

    void on_crusButton_clicked();

    void on_dstrButton_clicked();

    void on_confrmButton_clicked();

private:
    Ui::classwindow *ui;
};

#endif // CLASSWINDOW_H
