#include "mainwindow.h"
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



void MainWindow::makeMove(short int box, char player){
    QPixmap X("D:/Projects/Qt Widgets/Tic-Tac-Toe/X.png");
    QPixmap O("D:/Projects/Qt Widgets/Tic-Tac-Toe/O.png");

    switch(box){
    case 0:
        ui->box0->setEnabled(false);
        if(player == 'X'){
            ui->label0->setPixmap(X);
        }
        else {
            ui->label0->setPixmap(O);
        }
        break;
    case 1:
        ui->box1->setEnabled(false);
        if(player == 'X'){
            ui->label1->setPixmap(X);
        }
        else {
            ui->label1->setPixmap(O);
        }
        break;
    case 2:
        ui->box2->setEnabled(false);
        if(player == 'X'){
            ui->label2->setPixmap(X);
        }
        else {
            ui->label2->setPixmap(O);
        }
        break;
    case 3:
        ui->box3->setEnabled(false);
        if(player == 'X'){
            ui->label3->setPixmap(X);
        }
        else {
            ui->label3->setPixmap(O);
        }
        break;
    case 4:
        ui->box4->setEnabled(false);
        if(player == 'X'){
            ui->label4->setPixmap(X);
        }
        else {
            ui->label4->setPixmap(O);
        }
        break;
    case 5:
        ui->box5->setEnabled(false);
        if(player == 'X'){
            ui->label5->setPixmap(X);
        }
        else {
            ui->label5->setPixmap(O);
        }
        break;
    case 6:
        ui->box6->setEnabled(false);
        if(player == 'X'){
            ui->label6->setPixmap(X);
        }
        else {
            ui->label6->setPixmap(O);
        }
        break;
    case 7:
        ui->box7->setEnabled(false);
        if(player == 'X'){
            ui->label7->setPixmap(X);
        }
        else {
            ui->label7->setPixmap(O);
        }
        break;
    case 8:
        ui->box8->setEnabled(false);
        if(player == 'X'){
            ui->label8->setPixmap(X);
        }
        else {
            ui->label8->setPixmap(O);
        }
        break;

    }
}
void MainWindow::disableAllBoxes(){
    ui->box0->setEnabled(false);
    ui->box1->setEnabled(false);
    ui->box2->setEnabled(false);
    ui->box3->setEnabled(false);
    ui->box4->setEnabled(false);
    ui->box5->setEnabled(false);
    ui->box6->setEnabled(false);
    ui->box7->setEnabled(false);
    ui->box8->setEnabled(false);
}



void MainWindow::drawX(short int box){

}

void MainWindow::drawO(short int box){

}



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


