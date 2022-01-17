#include "calculator.h"

#include <QApplication>

/*!
 * \brief qMain
 * \param argc
 * \param argv
 * \return
 */
/*The main method*/
int main(int argc, char *argv[])
{
    /*!
     * \brief a
     * \return
     */
    QApplication a(argc, argv);
    Calculator w;
    w.show();

    return a.exec();
}
