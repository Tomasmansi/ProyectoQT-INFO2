#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QMessageBox>

#include "ventanaExtraccion.h"
#include "ventanaCuenta.h"
#include "structDatoCuenta.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>

extraccion::extraccion(QWidget *parent) : QWidget(parent)
{
    setWindowTitle("Extraccion");
    setGeometry(300,50,350,350);
    setFixedSize(350,350);

    continuar = new QPushButton("Continuar",this);
    continuar->setGeometry(190, 300, 80, 40);

    salir = new QPushButton("Volver", this);
    salir->setGeometry(60, 300, 80, 40);

    lblDinero = new QLabel("Ingrese dinero a extraer:",this);
    lblDinero->setGeometry(30,30,180,25);

    dinero = new QLineEdit(this);
    dinero->setValidator(new QRegExpValidator(QRegExp ("[0\\.\\- -9]{0,10}"),this));
    dinero->setGeometry(100, 70, 180, 25);

    connect(salir, SIGNAL(clicked()), this, SLOT(volverCuenta()));
    connect(continuar, SIGNAL(clicked()), this, SLOT(verContinuar()));
}

void extraccion::setCuenta(cuenta * pCuenta)
{
    puntCuenta=pCuenta;
}

void extraccion::volverCuenta()
{
    if(!puntCuenta) return;
    hide();
    puntCuenta->show();
}

void extraccion::verContinuar()
{
    FILE * archivo;
    datoCuenta dato;

    if(!(archivo = fopen("BASE DE DATOS.txt","r+b")))
    {
        printf("\nERROR APERTURA DE DISCO.\n");
        exit(0);
    }

    fseek(archivo,(long)(posicionUsuario*sizeof(dato)),SEEK_SET);
    fread(&dato,sizeof(dato),1,archivo);

    /*Si el monto ingresado es menor que el de deposito doy error*/

    QString auxDinero;
    auxDinero=dinero->text();/*Pasaje de QLineEdit a QString*/
    if(auxDinero.toInt()>dato.dinero)
    {
        QMessageBox msgBox;
        msgBox.setText("No dispone de ese dinero a extraer.");
        msgBox.setWindowTitle("Error");
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.exec();
        fclose(archivo);
        return;
    }

    if(dinero->text().length()==0)
    {
        QMessageBox msgBox;
        msgBox.setText("Complete el dinero a extraer");
        msgBox.setWindowTitle("Error");
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.exec();
        fclose(archivo);
        return;
    }

    fseek(archivo,(long)(-1*sizeof(dato)),SEEK_CUR);
    dato.dinero=dato.dinero-auxDinero.toInt();
    fwrite(&dato,sizeof(dato),1,archivo);

    if(!puntCuenta) return;
    hide();
    puntCuenta->show();
    fclose(archivo);
}

void extraccion::guardarPosicion(int pos)
{
    posicionUsuario=pos;
}
