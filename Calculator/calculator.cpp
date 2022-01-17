#include "calculator.h"
#include "ui_calculator.h"
#include "QRegularExpression"


/*!
 * \brief calValue
 */
/*Holds the current value of the calculation*/
double calValue = 0.0;


 /*This will be defined the last math button clicked*/
bool addTrigger = false;
bool subtractionTrigger = false;
bool divideTrigger = false;
bool multiTrigger = false;
bool percentageTrigger = false;
bool squareTrigger = false;
bool cubeTrigger = false;


 /*Constructor*/
Calculator::Calculator(QWidget *parent) :

     /*The QMainWindow constructor is called*/
    QMainWindow(parent),

    /*Created UI member is assigned UI class*/
    ui(new Ui::Calculator)
{

     /*Setup the UI*/
    ui -> setupUi(this);

     /*Put 0.0 in Display*/
    ui -> Display -> setText(QString::number(calValue));

    // /*All the number buttons are assigned with references*/
    QPushButton *numberButtons[10];

     /*All the buutons are located by iterations*/
    for(int i = 0; i < 10; ++i)
    {
        /*!
         * \brief buttonName
         */
        QString buttonName = "ButtonNo" + QString::number(i);

         /*Buttons are identified by name and added to the array*/
        numberButtons[i] = Calculator::findChild<QPushButton *>(buttonName);

         /*NumberPressed() is called when the button is released.*/
        connect(numberButtons[i], SIGNAL(released()), this,
                SLOT(NumberPressed()));
    }

     /*Signals and slots  are connected to the math buttons*/
    connect(ui -> ButtonAdd, SIGNAL(released()), this,
            SLOT(MathButtonPressed()));

    connect(ui -> ButtonSubtract, SIGNAL(released()), this,
            SLOT(MathButtonPressed()));

    connect(ui -> ButtonDivide, SIGNAL(released()), this,
            SLOT(MathButtonPressed()));

    connect(ui -> ButtonMultiply, SIGNAL(released()), this,
            SLOT(MathButtonPressed()));

    connect(ui -> ButtonPercentage, SIGNAL(released()), this,
            SLOT(MathButtonPressed()));

    connect(ui -> ButtonSquare, SIGNAL(released()), this,
            SLOT(MathButtonPressed()));

    connect(ui -> ButtonCube, SIGNAL(released()), this,
            SLOT(MathButtonPressed()));


     /*Connects the equal button*/
    connect(ui -> ButtonEquals, SIGNAL(released()), this,
            SLOT(EqualButtonPressed()));

     /*Connects the change sign button*/
    connect(ui -> ButtonChangeSign, SIGNAL(released()), this,
            SLOT(ChangeNumberSign()));

     /*Connects the clear button*/
    connect(ui -> ButtonClear, SIGNAL(released()), this,
            SLOT(ClearButtonPressed()));
}


/*!
 * \brief Calculator::~Calculator
 */
Calculator::~Calculator()
{
    delete ui;
}


/*!
 * \brief Calculator::NumberPressed
 */
void Calculator::NumberPressed()
{
    /*!
     * \brief button
     */
    /*The pointer is returned to the button that was pressed*/
    QPushButton *button = (QPushButton *)sender();

    /*!
     * \brief butValue
     */
    /*Gets the number related to the button*/
    QString butValue = button -> text();

    /*!
     * \brief displayValue
     */
    /*Value is the display is acquired*/
    QString displayValue = ui -> Display -> text();

    if((displayValue.toDouble() == 0) || (displayValue.toDouble() == 0.0))
    {
        ui->Display->setText(butValue);
    }
    else
    {
        /*!
         * \brief newVal
         */
        /*The new number is allocated to the right side of the existing number*/
        QString newVal = displayValue + butValue;

        /*!
         * \brief dblNewVal
         */
        /*The double value of the number is taken*/
        double dblNewVal = newVal.toDouble();

         /*Up to 16 numbers are allowed to be displayed
         Before using the exponents*/
        ui -> Display -> setText(QString::number(dblNewVal, 'g', 16));
    }
}


/*!
 * \brief Calculator::MathButtonPressed
 */
void Calculator::MathButtonPressed()
{
     /*Cancel the previous math buttons that were clicked*/
    addTrigger = false;
    subtractionTrigger = false;
    divideTrigger = false;
    multiTrigger = false;
    percentageTrigger = false;
    squareTrigger = false;
    cubeTrigger = false;

    /*!
     * \brief displayVal
     */
    /*Store the current value in the Display*/
    QString displayVal = ui -> Display -> text();

    calValue = displayVal.toDouble();

    /*!
     * \brief button
     */
    /*A pointer is returned to the button that was clicked*/
    QPushButton *button = (QPushButton *)sender();

    /*!
     * \brief butValue
     */
    /*Math symbol is acquired*/
    QString butValue = button->text();


    if(QString::compare(butValue, "+", Qt::CaseInsensitive) == 0)
    {
        addTrigger = true;
    }
    else if(QString::compare(butValue, "-", Qt::CaseInsensitive) == 0)
    {
        subtractionTrigger = true;
    }
    else if(QString::compare(butValue, "/", Qt::CaseInsensitive) == 0)
    {
        divideTrigger = true;
    }
    else if(QString::compare(butValue, "*", Qt::CaseInsensitive) == 0)
    {
        multiTrigger = true;
    }
    else if(QString::compare(butValue, "%", Qt::CaseInsensitive) == 0)
    {
        percentageTrigger = true;
    }
    else if(QString::compare(butValue, "x^2", Qt::CaseInsensitive) == 0)
    {
        squareTrigger = true;
    }
    else
    {
        cubeTrigger = true;
    }

     /*Clear the display*/
    ui -> Display -> setText("");
}


/*!
 * \brief Calculator::EqualButtonPressed
 */
void Calculator::EqualButtonPressed()
{
    /*!
     * \brief solution
     */
    /*Holds the new calculation*/
    double solution = 0.0;

    /*!
     * \brief displayValue
     */
    /*Get the value in the display*/
    QString displayValue = ui -> Display -> text();

    /*!
     * \brief dblDisplayValue
     */
    double dblDisplayValue = displayValue.toDouble();

     /*Makes sure that the math button is pressed*/
    if(addTrigger || subtractionTrigger || divideTrigger || multiTrigger || percentageTrigger || squareTrigger || cubeTrigger )
    {
        if(addTrigger)
        {
            solution = calValue + dblDisplayValue;
        }
        else if(subtractionTrigger)
        {
            solution = calValue - dblDisplayValue;
        }
        else if(divideTrigger)
        {
            solution = calValue / dblDisplayValue;
        }
        else if(multiTrigger)
        {
            solution = calValue * dblDisplayValue;
        }
        else if(percentageTrigger)
        {
            solution = (calValue * dblDisplayValue) / 100;
        }
        else if(squareTrigger)
        {
            solution = calValue * calValue;
        }
        else
        {
            solution = calValue * calValue * calValue;
        }
    }

     /*Solution is displayed*/
    ui -> Display -> setText(QString::number(solution));

}


/*!
 * \brief Calculator::ChangeNumberSign
 */
void Calculator::ChangeNumberSign()
{
    /*!
     * \brief displayValue
     */
    /*Gets the value that is in the display*/
    QString displayValue = ui -> Display -> text();

     /*Checks whether the number is positive*/
    QRegularExpression reg("[-+]?[0-9.]*");

     /*The sign is changed if it is a number*/
    if(reg.match(displayValue).hasMatch())
    {
        /*!
         * \brief dblDisplayValue
         */
        double dblDisplayValue = displayValue.toDouble();

        /*!
         * \brief dblDisplayValueSign
         */
        double dblDisplayValueSign = -1 * dblDisplayValue;

         /*The solution is displayed*/
        ui -> Display -> setText(QString::number(dblDisplayValueSign));
    }
}


/*!
 * \brief Calculator::on_ButtonDecimalPoint_released
 */
void Calculator::on_ButtonDecimalPoint_released()
{
    ui -> Display -> setText(ui -> Display -> text() + ".");
}


/*!
 * \brief Calculator::ClearButtonPressed
 */
void Calculator::ClearButtonPressed()
{
    ui -> Display -> setText("0");
}
