#include <QPushButton>
#include <QLabel>

#include "ventanaDinero.h"
#include "ventanaCuenta.h"
#include "structDatoCuenta.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>

dinero::dinero(QWidget *parent) : QWidget(parent)
{
    setWindowTitle("Dinero en Cuenta");
    setGeometry(350,50,200,100);
    setFixedSize(200,200);

    lblDinero = new QLabel("Dinero en cuenta: ",this);   ///
    QFont fuenteTitulo( "Arial", 13, QFont::Bold);       /// Titulo de la ventana
    lblDinero->setFont(fuenteTitulo);                    ///
    lblDinero->setGeometry(25,10,200,40);

    volver = new QPushButton("Volver", this);
    volver->setGeometry(60, 140, 80, 40);

    connect(volver, SIGNAL(clicked()), this, SLOT(volverCuenta()));

    cantDinero = new QLabel(this);
    cantDinero->setFont(fuenteTitulo);
    cantDinero->setGeometry(40, 40, 200, 50);

    signoPeso = new QLabel("$", this);
    signoPeso->setFont(fuenteTitulo);
    signoPeso->setGeometry(30, 40, 30, 30);
}

void dinero::setCuenta(cuenta * pCuenta)
{
    puntCuenta=pCuenta; /*Para poder volver a la ventana Cuenta*/
}

void dinero::volverCuenta()
{
    if(!puntCuenta) return;
    hide();
    puntCuenta->show();
}

void dinero::setDinero(int plata)
{
    cantDinero->setNum(plata); /*Se guarda la cantidad de dinero en la cuenta en un QLabel para verlo en pantalla*/
}
