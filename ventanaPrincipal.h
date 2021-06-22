#pragma once /*SOLAMENTE COPIA UNA VEZ LA CABEZA*/

#include <QWidget>
#include <QLabel>
#include <QTextEdit>
#include <QPushButton>

#include "ventanaAccederCuenta.h"
#include "ventanaNuevaCuenta.h"
#include "ventanaMirarUsuario.h"
#include "ventanaRestablecer.h"

class ingresarCuenta;
class nuevaCuenta;
class usuario;
class restablecer;

class principal : public QWidget {  /*LA CLASS HEREDA LA CLASE QWIGDET*/

    Q_OBJECT

private:
    QPushButton * accederCuenta; /*AGREGAR UN BOTON A LA VENTANA*/
    QPushButton * crearCuenta;
    QPushButton * restablecerButton;
    QPushButton * mirarUsuario;
    QPushButton * salir;
    QLabel * titulo;
    QLabel * seleccion;

    ingresarCuenta * puntAcceder; /*PUNTERO DE TIPO CLASS PARA PODER IR A LA OTRA VENTANA*/
    nuevaCuenta * puntNuevaCuenta;
    usuario * puntMirarUsuario;
    restablecer * puntRestablecer;

public:
    principal(QWidget *parent = 0);


public slots:   /*EVENTO O METODO LLAMADOS POR QT*/
    void verAccederCuenta(); /*DENTRO PUEDO TRABAJAR CON QT (COMO SHOW O HIDENT)*/
    void verCrearCuenta();
    void verMirarUsuario();
    void verRestablecer();
};

