#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void calculate();

    void resultPrint(bool res);

    void on_firstElementTrue_clicked();

    void on_firstElementFalse_clicked();

    void on_secondElementTrue_clicked();

    void on_secondElementFalse_clicked();

    void on_oprators_ComboBox_currentIndexChanged(int index);

    void on_firstElementNot_CheckBox_stateChanged(int arg1);

    void on_secondElementNot_CheckBox_stateChanged(int arg1);

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
