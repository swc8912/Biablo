#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QMainWindow>

namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void DeleteItem();
    void MainListSet();
    void addTableItem(char* str, int x, int y, char* name);

private:
    Ui::MainWindow *ui;

private slots:
    void on_mainList_cellClicked(int row, int column);
    void on_airTempUp_clicked();
    void on_airTempDown_clicked();
    void on_airPowerUp_clicked();
    void on_airPowerDown_clicked();
    void on_Power_4_clicked();
    void on_Back_4_clicked();
    void on_lightBrUp_clicked();
    void on_lightBrDown_clicked();
    void on_Power_2_clicked();
    void on_Back_2_clicked();
    void on_refTemUp_clicked();
    void on_refTemDown_clicked();
    void on_Power_3_clicked();
    void on_Back_3_clicked();
    void on_tvVoUp_clicked();
    void on_tvVoDown_clicked();
    void on_tvChUp_clicked();
    void on_tvChDown_clicked();
    void on_Power_clicked();
    void on_Back_clicked();
    void on_mainReg_clicked();
    void on_mainLight_clicked();
    void on_mainAir_clicked();
    void on_mainTv_clicked();
    void on_mainStart_clicked();


};

#endif // MAINWINDOW_H
