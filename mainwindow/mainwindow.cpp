#include "mainwindow.h"
#include "core.h"
#include "./ui_mainwindow.h"
#include <ctime>
#include <QPixmap>
#include <QGraphicsOpacityEffect>
#include <QJsonDocument>
#include <tuple>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Tic-tac-toe");
    ui->centralwidget->setWindowOpacity(qreal(0)/100);
    MainWindow::disableAllBoxes();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_newGame_button_released()
{
    MainWindow::setBoxesBlank();
    ui->gameStatus_textBox->setText("");                               //settings:
    readJson();                                                        //0: "gamemode"
    if(get<0>(settings) == 0){                                         //1: "ai_level"
        if (get<2>(settings) == 0) {                                   //2: "start_against_ai"
            player = 'X';                                              //3: "pvp_mode"
            opponent = 'O';
            enableAllBoxes();
        }
        else {
            player = 'O';
            opponent = 'X';
            getAIMove(0);
            if(MainWindow::checkWinner() || MainWindow::checkTie()){
                return;
            }
            enableAllBoxes();
        }
    }
    else if (get<0>(settings) == 1){    //"online pvp not implemented yet"
        if (get<3>(settings) == 0) {
            player = 'X';
            opponent = 'O';
            enableAllBoxes();
        }
        else if (get<3>(settings) == 1) {

        }
        else {

        }
    }
    MainWindow::enableAllBoxes();
}

void MainWindow::on_box0_released()
{
    move(0);
}
void MainWindow::on_box1_released()
{
    move(1);
}
void MainWindow::on_box2_released()
{
    move(2);
}
void MainWindow::on_box3_released()
{
    move(3);
}
void MainWindow::on_box4_released()
{
    move(4);
}
void MainWindow::on_box5_released()
{
    move(5);
}
void MainWindow::on_box6_released()
{
    move(6);
}
void MainWindow::on_box7_released()
{
    move(7);
}
void MainWindow::on_box8_released()
{
    move(8);
}
