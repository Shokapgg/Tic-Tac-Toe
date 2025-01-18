#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void disableBox(short int box);
    void disableAllBoxes();
    void drawX(short int box);
    void drawO(short int box);
    void setWin(short int num);
    bool checkWinner();
    bool checkTie();
    void getAIMove();
    void move(short int box);
    void on_box0_released();
    void on_box1_released();
    void on_box2_released();
    void on_box3_released();
    void on_box4_released();
    void on_box5_released();
    void on_box6_released();
    void on_box7_released();
    void on_box8_released();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
