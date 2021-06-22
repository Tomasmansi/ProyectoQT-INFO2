#include "ventanaMirarUsuario.h"
#include "structDatoCuenta.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>

usuario::usuario(QWidget *parent) : QWidget(parent)
{
    setWindowTitle("Nueva Cuenta");
    setGeometry(300,30,500,550);
    setFixedSize(500,550);

    volver = new QPushButton("Volver", this);
    volver->setGeometry(200, 500, 80, 40);

    connect(volver, SIGNAL(clicked()), this, SLOT(volverPrincipal()));


    datos = new QWidget();                      ///
    tabWidget = new QTabWidget(this);           ///Creo una sub ventana donde estaran los datos de los usuarios en QLabel
    tabWidget->setGeometry(5, 50,400,700);     ///
    tabWidget->addTab(datos, "Datos Cuenta");

    scroll= new QScrollArea(this);              ///
    scroll->setGeometry( 10, 10, 410, 450 );    ///Creo un area desplazable
    scroll->setWidget (tabWidget);              ///

    lblUsuario = new QLabel("Usuario", tabWidget);
    QFont fuenteTitulo( "Arial", 9, QFont::Bold);
    lblUsuario->setFont(fuenteTitulo);
    lblUsuario->setGeometry(30, 5, 180, 70);

    lblNombre = new QLabel("Nombre", tabWidget);
    lblNombre->setFont(fuenteTitulo);
    lblNombre->setGeometry(150, 5, 180, 70);

    lblDni = new QLabel("DNI", tabWidget);
    lblDni->setFont(fuenteTitulo);
    lblDni->setGeometry(270, 5, 180, 70);

    mostrarUsuarios();
}

void usuario::setVentanaPrincipal(principal * inicio)
{
    puntPrincipal=inicio; /*GUARDO LA DIRRECCION PARA VOLVER AL PRINCIPIO*/
}

void usuario::volverPrincipal()
{
    if(!puntPrincipal) return;
    hide();
    liberarMemoria();
    puntPrincipal->show();
}

void usuario::mostrarUsuarios()
{
    FILE * archivo;
    datoCuenta dato;
    QString strUsuario;
    QString strNombre;
    QString strDni;
    int posicion;

    if(!(archivo = fopen("BASE DE DATOS.txt","rb"))) //abro archivo por el final
    {                                                 //Voy a escribir dato errado
        printf("\nERROR APERTURA DE DISCO.\n");
        QMessageBox msgBox; /*no se puede seguir en la app hasta cerrar la ventana de error*/
        msgBox.setText("No hay usuarios creados.");
        msgBox.setWindowTitle("Error");
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.exec();
        return;
        /*SI EL ARCHIVO NO EXISTE TENGO QUE DECIR QUE PRIMERO SE CREE USUARIOS*/
    }


    inicio=NULL;
    fseek(archivo,0,SEEK_SET);
    int i=0;
    fread(&dato,sizeof(dato),1,archivo); /*Leo datos de usuario*/
    while(!feof(archivo))
    {
        i=i+30;
        strUsuario.clear();
        strNombre.clear();
        strDni.clear();
        strNombre.append(dato.nombre);
        strNombre.append(" ");
        strNombre.append(dato.apellido);
        strUsuario.append(dato.usuario);
        strDni=strDni.number(dato.dni);

        nodo * nuevoNodo = new nodo;

        nuevoLabel(nuevoNodo,strUsuario,strNombre,strDni);

        nuevoNodo->datoLabelUsuario->setGeometry(30,i,180,25);
        nuevoNodo->datoLabelNombre->setGeometry(150,i,180,25);
        nuevoNodo->datoLabelDni->setGeometry(270,i,180,25);

        posicion++;
        fread(&dato,sizeof(dato),1,archivo);
    }
    fclose(archivo);
}

void usuario::nuevoLabel(nodo * dir,QString strUsuario,QString strNombre,QString strDni)
{
    QLabel * lblUsu = new QLabel( strUsuario ,datos);
    QLabel * lblNom = new QLabel( strNombre ,datos);
    QLabel * lblNumero = new QLabel( strDni ,datos);
    nodo * aux;

    dir->datoLabelUsuario = lblUsu;
    dir->datoLabelNombre = lblNom;
    dir->datoLabelDni = lblNumero;
    dir->sig = NULL;

    if(!inicio) /*ES EL PIMERO DE LA LISTA*/
    {
        inicio = dir; ;
        dir->sig = NULL;
        return;
    }
    aux=inicio;
	while(aux->sig) /*AGREGO POR EL FINAL*/
		aux=aux->sig;

	aux->sig=dir;
}

void usuario::liberarMemoria()
{
	nodo * p, * aux;

	p=inicio;
	aux=p;
	while(aux)
	{
		aux=p->sig;
		delete p->datoLabelUsuario;
		delete p->datoLabelNombre;
		delete p->datoLabelDni;
		p=aux;
	}
}
