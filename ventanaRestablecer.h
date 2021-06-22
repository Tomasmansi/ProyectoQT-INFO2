#pragma once /*SOLAMENTE COPIA UNA VEZ LA CABEZA*/

#include <QWidget>
#include <QLabel>
#include <QTextEdit>
#include <QPushButton>
#include "ventanaPrincipal.h"
#include "structDatoCuenta.h"

class principal;

class restablecer : public QWidget {  /*LA CLASS HEREDA LA CLASE QWIGDET*/

    Q_OBJECT

    private:
            QLabel * lblDni;
            QLineEdit * dni;
            QPushButton * continuar;
            QPushButton * salir;

            principal * puntPrincipal;

    public:
            restablecer(QWidget *parent = 0);
            void setVentanaPrincipal(principal *);
    public slots:
        void volverPrincipal();
        void verContinuar();
};
