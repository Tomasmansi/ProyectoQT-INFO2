#pragma once

#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include "ventanaCuenta.h"

class cuenta;

class depositar : public QWidget
{
    Q_OBJECT

    private:
            QLabel * lblDinero;
            QLineEdit * dinero;
            QPushButton * continuar;
            QPushButton * salir;

            cuenta * puntCuenta;
            int posicionUsuario;

    public:
            depositar(QWidget *parent = 0);
            void setCuenta(cuenta *);
            void guardarPosicion(int);

    public slots:
            void volverCuenta();
            void verContinuar();
};
