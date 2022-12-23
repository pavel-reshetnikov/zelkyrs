#include "mainwindow.h"
#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit->setValidator(new QIntValidator(0, 100, this) );
    ui->lineEdit_3->setValidator(new QIntValidator(0, 100, this) );
    ui->lineEdit_2->setValidator(new QIntValidator(0, 100, this) );
    ui->lineEdit_4->setValidator(new QIntValidator(0, 100, this) );
    ui->label_8->setText("               ");
    ui->label_9->setText("               ");
    ui->label_10->setText("               ");
    ui->label->setText("               ");
}
MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_pushButton_clicked()
{
bool ret = false;
    double age = 0;
    age = ui->lineEdit->text().toDouble();
    if (age == 0){
        ui->label_8->setText("Введите возраст!");
    ret=true;
    }
    else{
        ui->label_8->setText("               ");
    }
    double mass = 0;
    mass = ui->lineEdit_2->text().toDouble();
    if (mass == 0){
        ui->label_9->setText("Введите вес!");
    ret=true;
    }
    else{
        ui->label_9->setText("               ");
    }

    double puls = 0;
    puls = ui->lineEdit_3->text().toDouble();
    if (puls == 0){
        ui->label_10->setText("Введите пульс!");
    ret=true;
    }
    else{
        ui->label_10->setText("               ");
    }
    double time = 0;
    time = ui->lineEdit_4->text().toDouble();
    if (time == 0){
      ui->label->setText("Введите время!");
    ret=true;
    }
    else{
        ui->label->setText("               ");
    }
    if (ret == true){
        ui->label_11->setText("Потрачено ккал: ");
        return;
    }
    int kkal;
   kkal = ((age * 0.2017)+(mass*0.9036)+(puls*0.6309)-55.0969)*(time/4.184);

    std::string strkkal = std::to_string(kkal);
    QString qstr_kkal= QString::fromStdString(strkkal);
   ui->label_11->setText("Потрачено ккал: " + qstr_kkal );
}

