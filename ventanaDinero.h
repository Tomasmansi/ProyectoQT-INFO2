#pragma once

#include <QPushButton>
#include <QLabel>

#include "ventanaCuenta.h"

class cuenta;

class dinero: public QWidget {

    Q_OBJECT

    private:
        QPushButton * volver;
        QLabel * cantDinero;
        QLabel * lblDinero;
        QLabel * signoPeso;

        cuenta * puntCuenta;

    public:
        dinero(QWidget *parent = 0);
        void setDinero(int);
        void setCuenta(cuenta *);

    public slots:
        void volverCuenta();
};

