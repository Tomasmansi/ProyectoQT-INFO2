#include <QApplication>
#include <QWidget>
#include <QPushButton>

#include "ventanaPrincipal.h"

principal::principal(QWidget *parent) : QWidget(parent)
{
    setWindowTitle("Bienvenido a banco X");
    setGeometry(300,50,300,400);
    setFixedSize(300,400);

    titulo = new QLabel("Bienvenido", this);        ///
    QFont fuenteTitulo( "Arial", 13, QFont::Bold);  /// Titulo de la ventana
    titulo->setFont(fuenteTitulo);                  ///
    titulo->setGeometry(15, 10, 260, 30);

    seleccion= new QLabel("Seleccione una opcion:", this);
    seleccion->setFont(fuenteTitulo);
    seleccion->setGeometry(15, 30, 260, 30);

    accederCuenta = new QPushButton("Ingresar", this);
    accederCuenta->setGeometry(60, 80, 180, 40);

    crearCuenta = new QPushButton("Nueva cuenta", this);
    crearCuenta->setGeometry(60, 120, 180, 40);

    restablecerButton = new QPushButton("Reestablecer cuenta", this);
    restablecerButton->setGeometry(60, 160, 180, 40);

    mirarUsuario = new QPushButton("Datos usuarios", this);
    mirarUsuario->setGeometry(60, 210, 180, 40);

    salir = new QPushButton("Salir", this);
    salir->setGeometry(60, 330, 180, 40);

    puntAcceder=NULL;
    puntNuevaCuenta=NULL;
    puntMirarUsuario=NULL;
    puntRestablecer=NULL;

    connect(accederCuenta, SIGNAL(clicked()), this, SLOT(verAccederCuenta()));      ///
    connect(crearCuenta, SIGNAL(clicked()), this, SLOT(verCrearCuenta()));          /// SLOTS para ir a otras ventanas
    connect(mirarUsuario, SIGNAL(clicked()), this, SLOT(verMirarUsuario()));        ///
    connect(restablecerButton, SIGNAL(clicked()), this, SLOT(verRestablecer()));
    connect(salir, SIGNAL(clicked()), qApp, SLOT(quit()));
}

void principal::verAccederCuenta()
{
    if(!puntAcceder)
    {
        puntAcceder = new ingresarCuenta();
        puntAcceder->setVentanaPrincipal(this); /*PARA PODER REGRESAR AL PRINCIPIO*/
    }
    hide();
    puntAcceder->show();
}

void principal::verCrearCuenta()
{
    if(!puntNuevaCuenta)
    {
        puntNuevaCuenta = new nuevaCuenta();
        puntNuevaCuenta->setVentanaPrincipal(this); /*PARA PODER REGRESAR AL PRINCIPIO*/
    }
    hide();
    puntNuevaCuenta->show();
}

void principal::verMirarUsuario()
{
    if(!puntMirarUsuario)
    {
        puntMirarUsuario = new usuario();
        puntMirarUsuario->setVentanaPrincipal(this);
    }
    hide();
    puntMirarUsuario->mostrarUsuarios();
    puntMirarUsuario->show();
}

void principal::verRestablecer()
{                                           /// Si la ventana no esta creada
    if(!puntRestablecer)                    /// Creo la ventana
    {                                       ///
        puntRestablecer = new restablecer();
        puntRestablecer->setVentanaPrincipal(this); ///Guardo la direccion de la ventana principal
    }
    hide();
    puntRestablecer->show();
}
