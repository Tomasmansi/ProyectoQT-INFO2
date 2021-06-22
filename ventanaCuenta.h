#pragma once

#include <QPushButton>
#include <QLabel>
#include <QApplication>

#include "ventanaAccederCuenta.h"
#include "ventanaExtraccion.h"
#include "ventanaDepositar.h"
#include "ventanaDinero.h"

class ingresarCuenta;
class extraccion;
class depositar;
class dinero;

class cuenta : public QWidget
{
    Q_OBJECT

    private:
            QPushButton * extraer;
            QPushButton * deposita;
            QPushButton * dineroButton;
            QPushButton * salir;
            QLabel * lblDatos;
            QLabel * lblSeleccionar;

            extraccion * puntExtraccion;
            dinero * puntDinero;
            depositar * puntDepositar;

            int posicionUsuario;

    public:
            cuenta(QWidget *parent = 0);
            void guardarPosicion(int);

    public slots:
            void verDepositar();
            void verExtraer();
            void verDinero();
};
