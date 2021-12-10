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

    void on_oprators_ComboBox_currentIndexChanged(int index);
    void on_firstElement_comboBox_currentIndexChanged(int index);

    void on_secondElement_comboBox_currentIndexChanged(int index);

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
