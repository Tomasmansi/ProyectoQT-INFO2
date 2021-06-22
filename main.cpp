#include <QApplication>

#include "ventanaPrincipal.h"

int main(int argc, char* argv[])
{
    QApplication app(argc, argv); /*CREO UNA APP*/
    principal * principio = new principal(); /*INTANCIO UN OBJETO P1*/

    principio->show(); /*MUESTRO LA VENTANA P1*/

    return app.exec();
}
