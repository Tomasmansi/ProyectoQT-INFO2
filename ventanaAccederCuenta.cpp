#include "ventanaAccederCuenta.h"
#include "ventanaPrincipal.h"
#include "structDatoCuenta.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;

ingresarCuenta::ingresarCuenta(QWidget *parent) : QWidget(parent)
{
    setWindowTitle("Ingresar Cuenta");
    setGeometry(300,50,300,300);
    setFixedSize(300,300);

    titulo = new QLabel("Ingrese usuario y clave", this);
    QFont fuenteTitulo( "Arial", 14, QFont::Bold);
    titulo->setFont(fuenteTitulo);
    titulo->setGeometry(30, 10, 260, 30);

    lblUsuario = new QLabel("Usuario:",this);
    lblUsuario->setGeometry(30,60,180,25);

    lblClave= new QLabel("Clave",this);
    lblClave->setGeometry(30,100,180,25);

    usuario = new QLineEdit(this);
    usuario->setGeometry(100, 60, 180, 25);

    clave = new QLineEdit(this);
    clave->setEchoMode(clave->Password); /*CAMBIA EL MODELO DE QLINE A PASSWORD*/
    clave->setGeometry(100, 100, 180, 25);

    ingresar = new QPushButton("Ingresar", this);
    ingresar->setGeometry(180, 200, 80, 40);

    volver = new QPushButton("Volver", this);
    volver->setGeometry(50, 200, 80, 40);


    puntPrincipal=NULL;
    puntCuenta=NULL;
    /*Volver al menu principal*/
    connect(volver, SIGNAL(clicked()), this, SLOT(volverPrincipal()));

    /*Ir a Cuenta*/
    connect(ingresar, SIGNAL(clicked()), this, SLOT(verCuenta()));

    hide();
}

void ingresarCuenta::setVentanaPrincipal(principal * inicio)
{
    puntPrincipal=inicio; /*GUARDO LA DIRRECCION PARA VOLVER AL PRINCIPIO*/
}

void ingresarCuenta::volverPrincipal()
{
    if(!puntPrincipal) return;
    hide();
    puntPrincipal->show();
}

void ingresarCuenta::verCuenta()
{
    FILE * archivo;
    datoCuenta dato; ///Estructura creada para guardar los datos en el archivo
    int encontrado=0;

    /*VERIFICACION DE DATOS*/
                                    ///
    if(usuario->text().length()==0) ///Verificacion de usuario ingresado
    {                               ///
        QMessageBox msgBox;
        msgBox.setText("Complete su nombre de usuario");
        msgBox.setWindowTitle("Error");
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.exec();
        return;
    }

    if(clave->text().length()==0) ///Verificacion de clave ingresada
    {
        QMessageBox msgBox;
        msgBox.setText("Ingrese una clave");
        msgBox.setWindowTitle("Error");
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.exec();
        return;
    }

    /*VERIFICAR SI EL NOMBRE INGRESADO ESTA EN LA BASE DE DATOS*/
                                                      ///
    if(!(archivo = fopen("BASE DE DATOS.txt","r+b"))) ///Modo escritura/lectura para poder bloquear la cuenta si se ingreso 3 veces mal la contraseña
    {                                                 ///
        QMessageBox msgBox;
        msgBox.setText("No hay usuarios creados.");
        msgBox.setWindowTitle("Error");
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.exec();
        return;
    }

    fseek(archivo,0,SEEK_SET);
                        ///
    QString auxUsuario; ///Guardara el usuario que se ingresa
    QString auxClave;   ///Guardara la clave que se ingresa
                        ///
    int posicion;       ///Se guarda la posicion del usuario en el archivo
                                ///
    auxUsuario=usuario->text(); ///Pasaje de QLineEdit a QString*/
    auxClave=clave->text();     ///
                                                             ///
    const char* strUsuario=auxUsuario.toStdString().c_str(); ///Pasaje de Qstring a const char*/
                                                             ///
    fread(&dato,sizeof(dato),1,archivo); ///Leo datos de usuario
    while(!feof(archivo))
    {                                           ///
        if(!(strcmp(dato.usuario,strUsuario)))  ///Si el usuario ingresado esta en la base de datos
        {                                       ///

            /*SI INGRESA LA CONTRASEÑA 3 VECES MAL SE BLOQUEA*/
                                 ///
            if(dato.contError>2) ///Si ingresa la cuenta esta bloqueada
            {                    ///
                    QMessageBox msgBox;
                    msgBox.setText("La cuenta esta bloqueada.Se debe reestablecer");
                    msgBox.setWindowTitle("Error");
                    msgBox.setIcon(QMessageBox::Warning);
                    msgBox.exec();
            }
            else
            {                                       ///
                if(auxClave.toInt()==dato.clave)    ///Si la clave es igual a la ingresada
                {                                   ///
                    encontrado=1;
                /*PERMITE INGRESAR*/
                    if(!puntCuenta)                 ///
                    {                               ///Creo la nueva ventana Cuenta
                        puntCuenta = new cuenta();  ///
                                                                            ///
                        fseek(archivo,(long)(-1*sizeof(dato)),SEEK_CUR);    ///Guardar la posicion del usuario en el archivo
                        posicion=ftell(archivo)/sizeof(dato);               /// Una vez que se ingresa a esta ventana ya no se puede volver a la principal
                        puntCuenta->guardarPosicion(posicion);              ///
                    }
                    hide();
                    puntCuenta->show();
                }
                else
                {
                    /*Si llega aca es que la clave esta mal*/

                    QMessageBox msgBox;
                    msgBox.setText("clave ingresado incorrecto");
                    msgBox.setWindowTitle("Error");
                    msgBox.setIcon(QMessageBox::Warning);
                    msgBox.exec();

                    fseek(archivo,(long)(-1*sizeof(dato)),SEEK_CUR); ///
                    dato.contError=dato.contError+1;                 /// Incrementa el contador de error para bloquear la cuenta
                    fwrite(&dato,sizeof(dato),1,archivo);            ///
                    fclose(archivo);
                    return;
                }
            }
        }
        fread(&dato,sizeof(dato),1,archivo);
    }

    if(!encontrado)
    {
            QMessageBox msgBox;                     ///
            msgBox.setText("Usuario denegado.");    ///Si llega aca el usuario ingresado no esta en la base de datos
            msgBox.setWindowTitle("Error");         ///
            msgBox.setIcon(QMessageBox::Warning);
            msgBox.exec();
            return;
    }
    fclose(archivo);
}
