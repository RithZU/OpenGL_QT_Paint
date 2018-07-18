#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <stdbool.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(&timer, SIGNAL(timeout()), ui->GLwidget, SLOT(updateGL()));
    timer.start();



}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btn_pencil_clicked()
{


    if(ui->btn_pencil->styleSheet()=="background-color : #bfbfbf")
    {

        ui->btn_pencil->setStyleSheet("background-color : red");
        ui->btn_line->setStyleSheet("background-color : #bfbfbf");
         ui->btn_circle->setStyleSheet("background-color : #bfbfbf");
         ui->btn_rect->setStyleSheet("background-color : #bfbfbf");
         ui->btn_triangle->setStyleSheet("background-color : #bfbfbf");


         ui->GLwidget->usePencil = true;
         ui->GLwidget->useLine = false;
         ui->GLwidget->useCircle = false;
         ui->GLwidget->useRect = false;
         ui->GLwidget->useTriangle = false;
    }




}

void MainWindow::on_btn_line_clicked()
{
    if(ui->btn_line->styleSheet()=="background-color : #bfbfbf")
    {

        ui->btn_line->setStyleSheet("background-color : red");
        ui->btn_pencil->setStyleSheet("background-color : #bfbfbf");
         ui->btn_circle->setStyleSheet("background-color : #bfbfbf");
         ui->btn_rect->setStyleSheet("background-color : #bfbfbf");
         ui->btn_triangle->setStyleSheet("background-color : #bfbfbf");

         ui->GLwidget->usePencil = false;
         ui->GLwidget->useLine = true;
         ui->GLwidget->useCircle = false;
         ui->GLwidget->useRect = false;
         ui->GLwidget->useTriangle = false;
    }

}
void MainWindow::on_btn_circle_clicked()
{
    if(ui->btn_circle->styleSheet()=="background-color : #bfbfbf")
    {

        ui->btn_circle->setStyleSheet("background-color : red");
        ui->btn_pencil->setStyleSheet("background-color : #bfbfbf");
        ui->btn_line->setStyleSheet("background-color : #bfbfbf");
        ui->btn_rect->setStyleSheet("background-color : #bfbfbf");
        ui->btn_triangle->setStyleSheet("background-color : #bfbfbf");

        ui->GLwidget->usePencil = false;
        ui->GLwidget->useLine = false;
        ui->GLwidget->useCircle = true;
        ui->GLwidget->useRect = false;
        ui->GLwidget->useTriangle = false;
    }
}


void MainWindow::on_sb_size_valueChanged(double arg1)
{
    this->ui->GLwidget->lWidth = arg1;
    this->ui->GLwidget->lWidthLine = arg1;
    this->ui->GLwidget->pointSize = arg1;
    this->ui->GLwidget->LineWidthRect = arg1;
    this->ui->GLwidget->LineWidthTri = arg1;

}





void MainWindow::on_btn_rect_clicked()
{

    if(ui->btn_rect->styleSheet()=="background-color : #bfbfbf")
    {

        ui->btn_circle->setStyleSheet("background-color : #bfbfbf");
        ui->btn_pencil->setStyleSheet("background-color : #bfbfbf");
        ui->btn_line->setStyleSheet("background-color : #bfbfbf");
        ui->btn_rect->setStyleSheet("background-color : red");
        ui->btn_triangle->setStyleSheet("background-color : #bfbfbf");

        ui->GLwidget->usePencil = false;
        ui->GLwidget->useLine = false;
        ui->GLwidget->useCircle = false;
        ui->GLwidget->useRect = true;
        ui->GLwidget->useTriangle = false;
    }
}



void MainWindow::on_btn_clear_clicked()
{
    ui->GLwidget->clearClicked = true;
}



void MainWindow::on_btn_triangle_clicked()
{
    if(ui->btn_triangle->styleSheet()=="background-color : #bfbfbf")
    {

        ui->btn_circle->setStyleSheet("background-color : #bfbfbf");
        ui->btn_pencil->setStyleSheet("background-color : #bfbfbf");
        ui->btn_line->setStyleSheet("background-color : #bfbfbf");
        ui->btn_rect->setStyleSheet("background-color : #bfbfbf");
        ui->btn_triangle->setStyleSheet("background-color : red");

        ui->GLwidget->usePencil = false;
        ui->GLwidget->useLine = false;
        ui->GLwidget->useCircle = false;
        ui->GLwidget->useRect = false;
        ui->GLwidget->useTriangle = true;
    }
}
