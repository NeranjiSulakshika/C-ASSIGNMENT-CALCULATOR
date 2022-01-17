#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE

namespace Ui
{
    class Calculator;
}

/*!
 * \brief The Calculator class
 */
QT_END_NAMESPACE


/*!
 * \brief The Calculator class
 */
class Calculator : public QMainWindow
{
     /*The base class is declared as a QObject
     For all the Qt objects
     Events are handled by QObjects*/
    Q_OBJECT


    /*!
 * \brief Calculator
 * \param parent
 */
public:

     /*A constructor is by passed 0
     Does not have a parent*/
    Calculator(QWidget *parent = 0);
    ~Calculator();


    /*!
 * \brief ui
 */
private:
    Ui::Calculator *ui;


     /*These are executed when a signal is
     Submitted (Ex. Number button is clicked)*/
private slots:
    /*!
     * \brief NumberPressed
     */
    void NumberPressed();
    /*!
     * \brief MathButtonPressed
     */
    void MathButtonPressed();
    /*!
     * \brief EqualButtonPressed
     */
    void EqualButtonPressed();
    /*!
     * \brief ChangeNumberSign
     */
    void ChangeNumberSign();
    /*!
     * \brief on_ButtonDecimalPoint_released
     */
    void on_ButtonDecimalPoint_released();
    /*!
     * \brief ClearButtonPressed
     */
    void ClearButtonPressed();
};

#endif
