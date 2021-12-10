#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    calculate();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::resultPrint(bool res){
    if(res){
        ui->result_Line->setText("TRUE");
        ui->result_Line->setStyleSheet("QLineEdit { background: rgb(0, 255, 0); }");
    }
    else{
        ui->result_Line->setText("FALSE");
        ui->result_Line->setStyleSheet("QLineEdit { background: rgb(255, 0, 0); }");
    }
}

void Widget::calculate(){
    int operand = ui->oprators_ComboBox->currentIndex();
    bool firstElement = 0, secondElement = 0;
    if(ui->firstElement_comboBox->currentIndex() == 0){
        firstElement = 1;
    }
    else {
        firstElement = 0;
    }
    if(ui->secondElement_comboBox->currentIndex() == 0){
        secondElement = 1;
    }
    else {
        secondElement = 0;
    }
    ui->firstElement_Label->setVisible(1);
    ui->firstElement_comboBox->setVisible(1);
    switch (operand) {
    case 0:
        resultPrint(firstElement or secondElement);
        break;
    case 1:
        resultPrint(firstElement and secondElement);
        break;
    case 2:
        resultPrint(not (firstElement) or secondElement);
        break;
    case 3:
        resultPrint(firstElement == secondElement);
        break;
    case 4:
        resultPrint(firstElement ^ secondElement);
        break;
    case 5:
        resultPrint(not(firstElement) and not(secondElement));
        break;
    case 6:
        ui->firstElement_Label->setVisible(0);
        ui->firstElement_comboBox->setVisible(0);
        resultPrint(not(secondElement));
        break;
    }
}




void Widget::on_oprators_ComboBox_currentIndexChanged(int index)
{
    calculate();
}




void Widget::on_firstElement_comboBox_currentIndexChanged(int index)
{
    calculate();
}


void Widget::on_secondElement_comboBox_currentIndexChanged(int index)
{
    calculate();
}

