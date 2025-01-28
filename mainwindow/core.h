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

extern char spaces[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};

void MainWindow::makeMove(short int box, char player){
    QPixmap X(":/resources/X.png");
    QPixmap O(":/resources/O.png");

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

std::tuple<short int, short int, short int, short int> readJson(std::tuple<short int, short int, short int, short int> values){
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
        get<0>(values) = 0;
    }
    else {
        get<0>(values) = 1;
    }

    value = sett2.value(QString("ai_level"));               //reading of "ai_level"
    if (value == "easy"){
        get<1>(values) = 0;
    }
    else if (value == "medium"){
        get<1>(values) = 1;
    }
    else {
        get<1>(values) = 2;
    }

    value = sett2.value(QString("start_against_ai"));       //reading of "gamemode"
    if (value == "x"){
        get<2>(values) = 0;
    }
    else {
        get<2>(values) = 1;
    }

    value = sett2.value(QString("pvp_mode"));               //reading of "pvp_mode"
    if (value == "casual"){
        get<2>(values) = 0;
    }
    else {
        get<2>(values) = 1;
    }

    return values;
}

#endif // CORE_H
