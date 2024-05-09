#include <QLabel>
#include <QPropertyAnimation>
#include "iostream"
#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "QLineEdit"

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    inDistancia=ui->inDisancia;
    inVelcidad=ui->inVelocidad;
    btnCorrer=ui->btnCorrer;
    runnerMan=ui->runnerMan;

    connect(btnCorrer,&QPushButton::clicked,this,&MainWindow::setValues);

}

MainWindow::~MainWindow()
{
    delete ui;

}
void MainWindow::setValues(){
    float distancia=inDistancia->text().toFloat();
    float velocidad=inVelcidad->text().toFloat();
    if (distancia!=0 && velocidad !=0){
        float tiempo=distancia/velocidad;
        moveIt(tiempo);
    }
}

void MainWindow::moveIt(float t) {
    QPropertyAnimation *anim = new QPropertyAnimation(runnerMan, "pos", this);
    anim->setDuration(t*1000);
    anim->setStartValue(QPoint(70, 110));
    anim->setEndValue(QPoint(350, 110));
    anim->start();

}
