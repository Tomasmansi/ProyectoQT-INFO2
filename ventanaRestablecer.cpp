#include <QMessageBox>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include "ventanaRestablecer.h"

restablecer::restablecer(QWidget *parent) : QWidget(parent)
{
    setWindowTitle("Ventana Restablecer");
    setGeometry(300,50,350,350);
    setFixedSize(350,350);

    continuar = new QPushButton("Continuar",this);
    continuar->setGeometry(190, 300, 80, 40);

    salir = new QPushButton("Volver", this);
    salir->setGeometry(60, 300, 80, 40);

    lblDni= new QLabel("Ingrese numero de DNI:",this);
    lblDni->setGeometry(30,30,180,25);

    dni = new QLineEdit(this);
    dni->setGeometry(100, 70, 180, 25);

    connect(salir, SIGNAL(clicked()), this, SLOT(volverPrincipal()));
    connect(continuar, SIGNAL(clicked()), this, SLOT(verContinuar()));
}

void restablecer::setVentanaPrincipal(principal * inicio)
{                         ///
    puntPrincipal=inicio; ///GUARDO LA DIRRECCION PARA VOLVER AL PRINCIPIO
}                         ///

void restablecer::volverPrincipal()
{
    if(!puntPrincipal) return;
    hide();
    puntPrincipal->show();
}

void restablecer::verContinuar()
{
    FILE * archivo;    ///
    datoCuenta dato;   ///Estructura creada para guardar los datos en el archivo
                       ///

    QString auxDni;    //QString auxiliar para comparar el numero de ingresado con el del archivo
                                                      ///
    if(!(archivo = fopen("BASE DE DATOS.txt","r+b"))) ///abro archivo en modo lectura/escritura para escribir que se pudo reestablecer
    {                                                 ///
        QMessageBox msgBox;
        msgBox.setText("No hay usuarios creados.");
        msgBox.setWindowTitle("Error");
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.exec();
        return;
    }

    fseek(archivo,0,SEEK_SET);
    fread(&dato,sizeof(dato),1,archivo);
    while(!feof(archivo))
    {
        auxDni=dni->text();         //Guardo el valor del QLine para compararlo
        if(auxDni.toInt()==dato.dni)
        {                                                       /// Encuentro el usuario a restaurar
            fseek(archivo,(long)(-1*sizeof(dato)),SEEK_CUR);    /// Llevo la ventana al usuario a restaurar
            dato.contError=0;                                   /// Pongo el contador de error en cero
            fwrite(&dato,sizeof(dato),1,archivo);               ///

            if(!puntPrincipal) return;                      ///
            hide();                                         ///Regreso a la ventana principal
            puntPrincipal->show();                          ///
            QMessageBox msgBox;
            msgBox.setText("Usuario reestablecido.");
            msgBox.setWindowTitle("Error");
            msgBox.setIcon(QMessageBox::NoIcon);
            msgBox.exec();

            fclose(archivo);
            return;
        }
        fread(&dato,sizeof(dato),1,archivo);
    }


    QMessageBox msgBox;                                     ///
    msgBox.setText("No hay un usuario con ese dni.");       ///Si llega hasta aca es que no se encontro el usuario con ese DNI
    msgBox.setWindowTitle("Error");                         ///
    msgBox.setIcon(QMessageBox::Warning);
    msgBox.exec();
    return;

    fclose(archivo);
}
