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


    if (ui->firstElementTrue->isChecked()){
        firstElement = 1;
    }
    else{
        firstElement = 0;
    }
    if(ui->secondElementTrue->isChecked()){
        secondElement = 1;
    }
    else{
        secondElement = 0;
    }


    if (ui->firstElementNot_CheckBox->isChecked()){
        firstElement = !firstElement;
    }
    if (ui->secondElementNot_CheckBox->isChecked()){
        secondElement = !secondElement;
    }

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
    }
}



void Widget::on_firstElementTrue_clicked()
{
    calculate();
}


void Widget::on_firstElementFalse_clicked()
{
    calculate();
}


void Widget::on_secondElementTrue_clicked()
{
    calculate();

}


void Widget::on_secondElementFalse_clicked()
{
    calculate();
}

void Widget::on_oprators_ComboBox_currentIndexChanged(int index)
{
    calculate();
}


void Widget::on_firstElementNot_CheckBox_stateChanged(int arg1)
{
    calculate();
}



void Widget::on_secondElementNot_CheckBox_stateChanged(int arg1)
{
    calculate();
}

