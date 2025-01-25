#ifndef CORE_H
#define CORE_H

#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <ctime>
#include <QPixmap>
#include <QGraphicsOpacityEffect>

void MainWindow::makeMove(short int box, char player){
    QPixmap X("D:/Projects/Qt Widgets/Tic-Tac-Toe/resources/X.png");
    QPixmap O("D:/Projects/Qt Widgets/Tic-Tac-Toe/resources/O.png");

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

#endif // CORE_H
