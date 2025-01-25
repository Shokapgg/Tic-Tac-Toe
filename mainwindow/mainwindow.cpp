#include "mainwindow.h"
#include "core.h"
#include "./ui_mainwindow.h"
#include <ctime>
#include <QPixmap>
#include <QGraphicsOpacityEffect>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Tic-tac-toe");
}

MainWindow::~MainWindow()
{
    delete ui;
    ui->centralwidget->setWindowOpacity(qreal(0)/100);
}


char spaces[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};

void MainWindow::setWin(short int num){
    MainWindow::disableAllBoxes();
    if(spaces[num] == 'X'){
        ui->gameStatus_textBox->setText("You Won");
    }
    else{
        ui->gameStatus_textBox->setText("You Lost");
    }
}

bool MainWindow::checkWinner() {
    //Horizontal checking
    if (spaces[0] != ' ' && spaces[0] == spaces[1] && spaces[1] == spaces[2]) {
        setWin(0);
        return true;
    }
    else if (spaces[3] != ' ' && spaces[3] == spaces[4] && spaces[4] == spaces[5]) {
        setWin(3);
        return true;
    }
    else if (spaces[6] != ' ' && spaces[6] == spaces[7] && spaces[7] == spaces[8]) {
        setWin(6);
        return true;
    }

    //Vertical checking
    else if (spaces[0] != ' ' && spaces[0] == spaces[3] && spaces[3] == spaces[6]) {
        setWin(0);
        return true;
    }
    else if (spaces[1] != ' ' && spaces[1] == spaces[4] && spaces[4] == spaces [7]) {
        setWin(1);
        return true;
    }
    else if (spaces[2] != ' ' && spaces[2] == spaces[5] && spaces[5] == spaces [8]) {
        setWin(2);
        return true;
    }

    //Cross checking
    else if (spaces[0] != ' ' && spaces[0] == spaces[4] && spaces[4] == spaces[8]) {
        setWin(0);
        return true;
    }
    else if (spaces[2] != ' ' && spaces[2] == spaces[4] && spaces[4] == spaces[6]) {
        setWin(2);
        return true;
    }
    return false;
}

bool MainWindow::checkTie() {
    for(int i = 0; i <= 8; i++) {
        if (spaces[i] == ' '){
            return false;
        }
    }
    ui->gameStatus_textBox->setText("It's a Tie");
    return true;
}


void MainWindow::getAIMove(){
    srand(time(NULL));
    while (0 == 0){
        short int temp = rand()%8;
        if (spaces[temp] == ' '){
            spaces[temp] = 'O';
            MainWindow::makeMove(temp, 'O');
            break;
        }
    }
}

void MainWindow::move(short int box){
    MainWindow::makeMove(box, 'X');
    spaces[box] = 'X';
    if(MainWindow::checkWinner() || MainWindow::checkTie()){
        return;
    }
    MainWindow::getAIMove();
    MainWindow::checkWinner();
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


