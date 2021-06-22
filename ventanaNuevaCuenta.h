#pragma once

#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QWidget>
#include <QTabWidget>
#include <QRadioButton>
#include "ventanaPrincipal.h"

class principal;

class nuevaCuenta : public QWidget {  /*LA CLASS HEREDA LA CLASE QWIGDET*/

    Q_OBJECT

    private:
            QTabWidget * tabWidget; /*Creo dos ventanas*/
            QWidget * datosCuenta;
            QWidget * datosPersonales;
            QLabel * titulo;

            /*Ventana datos cuenta*/
            QLabel * lblUsuario;
            QLabel * lblClave;
            QLabel * lblClaveForma;

            QLineEdit * usuario; /*Campo para poner un nombre*/
            QLineEdit * clave;

            /*Ventana datos personales*/
            QLabel * lblNombre;
            QLabel * lblApellido;
            QLabel * lblDni;
            QLabel * lblSexo;

            QLineEdit * nombre; /*Campo para poner un nombre*/
            QLineEdit * apellido;
            QLineEdit * dni;
            QRadioButton * sexoM;
            QRadioButton * sexoF;

            QPushButton * volver;
            QPushButton * finalizar;
            principal * puntPrincipal; /*Para volver a la otra ventana*/

    public:
            nuevaCuenta(QWidget *parent = 0);
            void setVentanaPrincipal(principal *);
            void guardarCuenta();

    public slots:
            void volverPrincipal();
            void verFinalizar();
            int verificarDatos();
};
