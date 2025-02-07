#ifndef CORE_H
#define CORE_H

#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <ctime>
#include <QPixmap>
#include <QJsonDocument>
#include <QJsonObject>
#include <tuple>
#include <QFile>

char spaces[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
char player = 'X';
char opponent = 'O';
std::tuple<short int, short int, short int, short int> settings;
short int moveNum = 0;

void MainWindow::makeMove(short int box, char currentPlayer){
    QPixmap X(":/resources/X.png");
    QPixmap O(":/resources/O.png");

    switch(box){
    case 0:
        ui->box0->setEnabled(false);
        if(currentPlayer == 'X'){
            ui->label0->setPixmap(X);
        }
        else {
            ui->label0->setPixmap(O);
        }
        break;
    case 1:
        ui->box1->setEnabled(false);
        if(currentPlayer == 'X'){
            ui->label1->setPixmap(X);
        }
        else {
            ui->label1->setPixmap(O);
        }
        break;
    case 2:
        ui->box2->setEnabled(false);
        if(currentPlayer == 'X'){
            ui->label2->setPixmap(X);
        }
        else {
            ui->label2->setPixmap(O);
        }
        break;
    case 3:
        ui->box3->setEnabled(false);
        if(currentPlayer == 'X'){
            ui->label3->setPixmap(X);
        }
        else {
            ui->label3->setPixmap(O);
        }
        break;
    case 4:
        ui->box4->setEnabled(false);
        if(currentPlayer == 'X'){
            ui->label4->setPixmap(X);
        }
        else {
            ui->label4->setPixmap(O);
        }
        break;
    case 5:
        ui->box5->setEnabled(false);
        if(currentPlayer == 'X'){
            ui->label5->setPixmap(X);
        }
        else {
            ui->label5->setPixmap(O);
        }
        break;
    case 6:
        ui->box6->setEnabled(false);
        if(currentPlayer == 'X'){
            ui->label6->setPixmap(X);
        }
        else {
            ui->label6->setPixmap(O);
        }
        break;
    case 7:
        ui->box7->setEnabled(false);
        if(currentPlayer == 'X'){
            ui->label7->setPixmap(X);
        }
        else {
            ui->label7->setPixmap(O);
        }
        break;
    case 8:
        ui->box8->setEnabled(false);
        if(currentPlayer == 'X'){
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

void MainWindow::enableAllBoxes(){
    ui->box0->setEnabled(true);
    ui->box1->setEnabled(true);
    ui->box2->setEnabled(true);
    ui->box3->setEnabled(true);
    ui->box4->setEnabled(true);
    ui->box5->setEnabled(true);
    ui->box6->setEnabled(true);
    ui->box7->setEnabled(true);
    ui->box8->setEnabled(true);
}

void MainWindow::setBoxesBlank(){
    QPixmap blank(":/resources/blank.png");
    ui->label0->setPixmap(blank);
    ui->label1->setPixmap(blank);
    ui->label2->setPixmap(blank);
    ui->label3->setPixmap(blank);
    ui->label4->setPixmap(blank);
    ui->label5->setPixmap(blank);
    ui->label6->setPixmap(blank);
    ui->label7->setPixmap(blank);
    ui->label8->setPixmap(blank);
    spaces[0] = ' ';
    spaces[1] = ' ';
    spaces[2] = ' ';
    spaces[3] = ' ';
    spaces[4] = ' ';
    spaces[5] = ' ';
    spaces[6] = ' ';
    spaces[7] = ' ';
    spaces[8] = ' ';
}

void MainWindow::setWin(short int num){
    MainWindow::disableAllBoxes();
    if(spaces[num] == player){
        if(get<3>(settings) == 0){
            ui->gameStatus_textBox->setText("X Won");
        }
        else {
            ui->gameStatus_textBox->setText("You Won");
        }
    }
    else{
        if(get<3>(settings) == 0){
            ui->gameStatus_textBox->setText("O Won");
        }
        else {
            ui->gameStatus_textBox->setText("You Lost");
        }
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

void MainWindow::getAIMove(short int difficulty){           //difficulty:
    srand(time(NULL));                                      //0: easy
    if (difficulty == 0) {                                  //1: medium
        while (0 == 0){                                     //2: hard (unbeatable)
            short int temp = rand()%9;
            if (spaces[temp] == ' '){
                spaces[temp] = opponent;
                MainWindow::makeMove(temp, opponent);
                break;
            }
        }
    }
}

void MainWindow::move(short int box){
    if (get<3>(settings) == 0){
        if (moveNum == 0){
            MainWindow::makeMove(box, player);
            spaces[box] = player;
            if(MainWindow::checkWinner() || MainWindow::checkTie()){
                return;
            }
            MainWindow::makeMove(box, opponent);
            spaces[box] = opponent;
            if(MainWindow::checkWinner() || MainWindow::checkTie()){
                return;
            }
            moveNum = 1;
        }
        else {
            moveNum = 0;
            MainWindow::makeMove(box, player);
            spaces[box] = player;
            if(MainWindow::checkWinner() || MainWindow::checkTie()){
                return;
            }
            MainWindow::makeMove(box, opponent);
            spaces[box] = opponent;
            if(MainWindow::checkWinner() || MainWindow::checkTie()){
                return;
            }
        }
    }
    else {
        MainWindow::makeMove(box, player);
        spaces[box] = player;
        if(MainWindow::checkWinner() || MainWindow::checkTie()){
            return;
        }
        MainWindow::getAIMove(0);
        if(MainWindow::checkWinner() || MainWindow::checkTie()){
            return;
        }
    }
}

void readJson(){
    QString val;
    QFile file;
    file.setFileName("settings.json");
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    val = file.readAll();
    file.close();
    qWarning() << val;
    QJsonDocument d = QJsonDocument::fromJson(val.toUtf8());
    QJsonObject sett2 = d.object();

    QJsonValue value = sett2.value(QString("gamemode"));    //reading of "gamemode"
    if (value == "pve"){
        get<0>(settings) = 0;
    }
    else {
        get<0>(settings) = 1;
    }

    value = sett2.value(QString("ai_level"));               //reading of "ai_level"
    if (value == "easy"){
        get<1>(settings) = 0;
    }
    else if (value == "medium"){
        get<1>(settings) = 1;
    }
    else {
        get<1>(settings) = 2;
    }

    value = sett2.value(QString("start_against_ai"));       //reading of "start_against_ai"
    if (value == "x"){
        get<2>(settings) = 0;
    }
    else {
        get<2>(settings) = 1;
    }

    value = sett2.value(QString("pvp_mode"));               //reading of "pvp_mode"
    if (value == "local"){
        get<3>(settings) = 0;
    }
    else if (value == "casual") {
        get<3>(settings) = 1;
    }
    else {
        get<3>(settings) = 2;
    }
}

#endif // CORE_H
