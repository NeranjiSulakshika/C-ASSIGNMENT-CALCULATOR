#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE

namespace Ui
{
    class Calculator;
}

QT_END_NAMESPACE

class Calculator : public QMainWindow
{
    // The base class is declared as a QObject
    // For all the Qt objects
    // Events are handled by QObjects
    Q_OBJECT


public:

    // A constructor is by passed 0
    // Does not have a parent
    Calculator(QWidget *parent = 0);
    ~Calculator();


private:
    Ui::Calculator *ui;


    // These are executed when a signal is
    // Submitted (Ex. Number button is clicked)
private slots:
    void NumberPressed();
    void MathButtonPressed();
    void EqualButtonPressed();
    void ChangeNumberSign();
    void on_ButtonDecimalPoint_released();
    void ClearButtonPressed();
};

#endif
