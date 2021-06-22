#pragma once /*SOLAMENTE COPIA UNA VEZ LA CABEZA*/

#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QMessageBox>

#include "ventanaPrincipal.h"
#include "ventanaCuenta.h"

class principal; /* ojo */
class cuenta;

class ingresarCuenta : public QWidget {  /*LA CLASS HEREDA LA CLASE QWIGDET*/

    Q_OBJECT

    private:
            QLabel * lblUsuario;
            QLabel * lblClave;
            QLineEdit * usuario; /*CAMPO PARA ESCRIBIR NOMBRE*/
            QLineEdit * clave; /*CAMPO PARA ESCRIBIR CONTRASEÑA*/
            QPushButton * ingresar; /*BOTON PARA INGRESAR*/
            QPushButton * volver;   /*BOTON PARA VOLVER*/
            QLabel * titulo;

            principal * puntPrincipal; /*PUNTERO PARA PODER VOLVER AL PRINCIPIO*/
            cuenta * puntCuenta; /*Puntero para ir a la ventana cuenta*/

    public:
            ingresarCuenta(QWidget *parent = 0);
            void setVentanaPrincipal(principal *);

    public slots:
            void volverPrincipal();
            void verCuenta();
};
