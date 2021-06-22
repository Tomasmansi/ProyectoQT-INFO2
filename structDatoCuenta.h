#pragma once
#include <QtGui>

struct pasajeDato : public QString /*ESTRUCTURA QUE GUARDA LOS DATOS*/
{                                  /*LA ESTRUCTURA HEREDA LA CLASS QSTRING*/
    public:
        QString usuario;
        QString clave;
        QString nombre;
        QString apellido;
        QString dni;
};

struct datoCuenta  /*ESTRUCTURA QUE GUARDA LOS DATOS*/
{
        char usuario[30];
        int clave;
        char nombre[30];
        char apellido[30];
        int dni;
        int contError;
        int dinero;
};
