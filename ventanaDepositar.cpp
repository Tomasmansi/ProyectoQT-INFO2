#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QMessageBox>

#include "ventanaDepositar.h"
#include "ventanaCuenta.h"
#include "structDatoCuenta.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>

depositar::depositar(QWidget *parent) : QWidget(parent)
{
    setWindowTitle("Depositar");
    setGeometry(300,50,350,350);
    setFixedSize(350,350);

    continuar = new QPushButton("Continuar",this);
    continuar->setGeometry(190, 300, 80, 40);

    salir = new QPushButton("Volver", this);
    salir->setGeometry(60, 300, 80, 40);

    lblDinero = new QLabel("Ingrese dinero a depositar:",this);
    lblDinero->setGeometry(30,30,180,25);

    dinero = new QLineEdit(this);
    dinero->setValidator(new QRegExpValidator(QRegExp ("[0\\.\\- -9]{0,10}"),this));
    dinero->setGeometry(100, 70, 180, 25);

    connect(salir, SIGNAL(clicked()), this, SLOT(volverCuenta()));
    connect(continuar, SIGNAL(clicked()), this, SLOT(verContinuar()));
}

void depositar::setCuenta(cuenta * pCuenta)
{
    puntCuenta=pCuenta;
}

void depositar::volverCuenta()
{
    if(!puntCuenta) return;
    hide();
    puntCuenta->show();
}

void depositar::guardarPosicion(int pos)
{
    posicionUsuario=pos; /*Guarda la posicion del usuario al que se accedio en forma de acceso directo*/
}

void depositar::verContinuar()
{
    FILE * archivo;
    datoCuenta dato;
    QString auxDinero;

    if(!(archivo = fopen("BASE DE DATOS.txt","r+b")))
    {
        printf("\nERROR APERTURA DE DISCO.\n");
        exit(0);
    }
                                                                    ///
    fseek(archivo,(long)(posicionUsuario*sizeof(dato)),SEEK_SET);   ///Llevo la ventana a la posicion del usuario ingresado
    fread(&dato,sizeof(dato),1,archivo);                            ///

    auxDinero=dinero->text();                   ///Paso de QLine a Qstring
    dato.dinero=dato.dinero+auxDinero.toInt();  ///Le sumo el dinero ingresado al que ya tenia en cuenta
                                                ///
    fseek(archivo,(long)(-1*sizeof(dato)),SEEK_CUR);    ///Regreso la ventana
    fwrite(&dato,sizeof(dato),1,archivo);               ///Escribo el total del dinero
                                                        ///
    if(!puntCuenta) return;
    hide();
    puntCuenta->show();
    fclose(archivo);
}


