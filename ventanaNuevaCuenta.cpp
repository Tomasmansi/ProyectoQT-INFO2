#include "ventanaNuevaCuenta.h"
#include "ventanaPrincipal.h"
#include "structDatoCuenta.h"
#include <QIntValidator>
#include <QRegExpValidator>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;

nuevaCuenta::nuevaCuenta(QWidget *parent) : QWidget(parent)
{
    setWindowTitle("Nueva Cuenta");
    setGeometry(300,50,350,350);
    setFixedSize(350,350);

    titulo = new QLabel("Ingrese sus datos", this);     ///
    QFont fuenteTitulo( "Arial", 16, QFont::Bold);      ///Titulo de la ventana
    titulo->setFont(fuenteTitulo);                      ///
    titulo->setGeometry(5, 10, 200, 30);

    finalizar = new QPushButton("Finalizar",this);
    finalizar->setGeometry(190, 300, 80, 40);           ///
                                                        /// Botones de la ventana
    volver = new QPushButton("Volver", this);           ///
    volver->setGeometry(60, 300, 80, 40);

    connect(volver, SIGNAL(clicked()), this, SLOT(volverPrincipal()));  ///
    connect(finalizar, SIGNAL(clicked()), this, SLOT(verFinalizar()));  ///SLOTS para volver a la ventana principal
                                                                        ///     y para finalizar la creacion de la cuenta
    datosCuenta = new QWidget();            ///
    datosPersonales = new QWidget();        ///Creo dos sub-ventanas, una para datos de la cuenta(usuario,clave)
    tabWidget = new QTabWidget(this);       ///                       una para datos personales (nombre,apellido,dni,sexo)

    tabWidget->addTab(datosCuenta, "Datos Cuenta");
    tabWidget->addTab(datosPersonales, "Datos Personales");
    tabWidget->setGeometry(5, 50, 300, 250);

    /*Ventana datos de la cuenta*/
    lblUsuario = new QLabel("Usuario",datosCuenta);
    lblUsuario->setGeometry(30,30,180,25);

    usuario = new QLineEdit(datosCuenta);
    usuario->setGeometry(100, 30, 180, 25);

    lblClave = new QLabel("Clave",datosCuenta);
    lblClave->setGeometry(30,70,180,25);

    clave = new QLineEdit(datosCuenta);
    clave->setValidator( new QIntValidator(1000, 999999999, datosCuenta));
    clave->setEchoMode(clave->Password); /*CAMBIA EL MODO DE VER EL TEXTO A MODO PASSWORD*/
    clave->setGeometry(100, 70, 180, 25);

    lblClaveForma = new QLabel("Debe un numero con un maximo de 10 cifras.",datosCuenta);
    lblClaveForma->setGeometry(50,90,250,25);

    /*Ventana datos personales*/

    lblNombre = new QLabel("Nombre",datosPersonales);
    lblNombre->setGeometry(30,30,180,25);

    lblApellido= new QLabel("Apellido",datosPersonales);
    lblApellido->setGeometry(30,70,180,25);

    lblDni= new QLabel("DNI",datosPersonales);
    lblDni->setGeometry(30,110,180,25);

    lblSexo= new QLabel("Sexo",datosPersonales);
    lblSexo->setGeometry(30,160,180,25);

    nombre = new QLineEdit(datosPersonales);                                                       ///
    nombre->setValidator(new QRegExpValidator(QRegExp ("[A-Z\\.\\- a-z]{0,20}"),datosPersonales)); /// Permite que solo se ingresen letras y numeros
    nombre->setGeometry(100, 30, 180, 25);                                                         ///

    apellido = new QLineEdit(datosPersonales);
    apellido->setValidator(new QRegExpValidator(QRegExp ("[A-Z\\.\\- a-z]{0,20}"),datosPersonales));
    apellido->setGeometry(100, 70, 180, 25);

    dni = new QLineEdit(datosPersonales);
    dni->setValidator(new QRegExpValidator(QRegExp ("[0\\.\\- -9]{0,10}"),datosCuenta));
    dni->setGeometry(100, 110, 180, 25);

    sexoM = new QRadioButton("Masculino", datosPersonales);
    sexoM->setGeometry(100, 150, 180, 25);
    sexoF = new QRadioButton("Femenino", datosPersonales);
    sexoF->setGeometry(100,170,180,25);
}

void nuevaCuenta::setVentanaPrincipal(principal * inicio)
{
    puntPrincipal=inicio; /*GUARDO LA DIRECCION PARA VOLVER AL PRINCIPIO*/
}

void nuevaCuenta::volverPrincipal()
{
    if(!puntPrincipal) return;      ///
    hide();                         ///Regreso a la ventana principal
    puntPrincipal->show();          ///
}

void nuevaCuenta::verFinalizar()
{                                ///
    if(verificarDatos()) return; ///Si es verdadero los datos ingresados tienen algun error y retorna a la ventana para cambiar los datos o volver al principio
                                 ///
    guardarCuenta(); /*Si llega hasta aca se crea el nuevo usuario*/

    if(!puntPrincipal) return;
    hide();
    puntPrincipal->show();
}

int nuevaCuenta::verificarDatos()
 {
    FILE * archivo;
    datoCuenta dato; //Estructura creada para guardar los datos en el archivo

                                    ///
    if(usuario->text().length()==0) ///Verifica que se halla ingresado un usuario
    {                               ///
        QMessageBox msgBox;
        msgBox.setText("Ingrese un usuario");
        msgBox.setWindowTitle("Error");
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.exec();
        return 1;
    }

    if(usuario->text().length()>20)  ///Limite de caracteres
    {
        QMessageBox msgBox;
        msgBox.setText("El usuario no puede tener mas de 20 caracteres");
        msgBox.setWindowTitle("Error");
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.exec();
        return 1;
    }

    if(clave->text().length()==0) /*Verifica la clave*/
    {
        QMessageBox msgBox;
        msgBox.setText("Error ingrese una clave");
        msgBox.setWindowTitle("Error");
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.exec();
        return 1;
    }

    if(clave->text().length()>20)
    {
        QMessageBox msgBox;
        msgBox.setText("La clave no puede tener mas de 10 caracteres");
        msgBox.setWindowTitle("Error");
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.exec();
        return 1;
    }


    if(nombre->text().length()==0) /*Verifica el nombre */
    {
        QMessageBox msgBox;
        msgBox.setText("Ingrese un nombre");
        msgBox.setWindowTitle("Error");
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.exec();
        return 1;
    }


    if(apellido->text().length()==0)    /*Verificar el apellido*/
    {
        QMessageBox msgBox;
        msgBox.setText("Ingrese un apellido");
        msgBox.setWindowTitle("Error");
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.exec();
        return 1;
    }


    if(dni->text().length()==0) /*Verificar el dni*/
    {
        QMessageBox msgBox;
        msgBox.setText("Ingrese un dni");
        msgBox.setWindowTitle("Error");
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.exec();
        return 1;
    }


    if(!sexoF->isChecked() && !sexoM->isChecked()) /*Verificar sexo*/
    {
        QMessageBox msgBox;
        msgBox.setText("Debe indicar el sexo.");
        msgBox.setWindowTitle("Error");
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.exec();
        return 1;
    }

    ///
    ///Verificar que el nombre no este en la lista
    ///                                               ///
    if(!(archivo = fopen("BASE DE DATOS.txt","a+b"))) ///Si no existe, se lo crea
    {                                                 ///
        printf("\nERROR APERTURA DE DISCO.\n");
        exit(0);
    }

    fseek(archivo,0,SEEK_SET);

    QString auxUsuario;  ///
    QString auxDni;      /// Variables para hacer pasaje de QLineEdit a char* para guardar datos en el archivo
                         ///
                                    ///
    auxUsuario=usuario->text();     ///Guardar el QLineEdit en un QString
    auxDni=dni->text();             ///

    const char* strUsuario=auxUsuario.toStdString().c_str(); ///Guardo el QString en una const char

    fread(&dato,sizeof(dato),1,archivo);
    while(!feof(archivo))
    {
        if(!(strcmp(dato.usuario,strUsuario))) ///comprobar si hay usuario con ese nombre
        {
            QMessageBox msgBox;
            msgBox.setText("Ya hay un usuario con ese nombre.");
            msgBox.setWindowTitle("Error");
            msgBox.setIcon(QMessageBox::Warning);
            msgBox.exec();
            fclose(archivo);
            return 1;
        }

         if(dato.dni==auxDni.toInt()) ///Comprobar si hay usuario con ese dni
        {
            QMessageBox msgBox;
            msgBox.setText("Ya hay un usuario con ese dni.");
            msgBox.setWindowTitle("Error");
            msgBox.setIcon(QMessageBox::Warning);
            msgBox.exec();
            fclose(archivo);
            return 1;
        }
        fread(&dato,sizeof(dato),1,archivo);
    }
    fclose(archivo);

    return 0;
}

void nuevaCuenta::guardarCuenta()
{
    FILE * archivo;
    pasajeDato auxDato; ///Estructura para hacer el pasaje de QLine a char
    datoCuenta dato; ///Estructura creada para guardar los datos en el archivo
                                                      ///
    if(!(archivo = fopen("BASE DE DATOS.txt","a+b"))) ///Abro archivo por el final
    {                                                 ///Si no existe, se lo crea
        printf("\nERROR APERTURA DE DISCO.\n");
        exit(0);
    }

    auxDato.usuario=usuario->text();
    auxDato.clave=clave->text();         ///
    auxDato.nombre=nombre->text();       ///Paso los QlineEdit A QString
    auxDato.apellido=apellido->text();   ///
    auxDato.dni=dni->text();

    const char* strUsuario=auxDato.usuario.toStdString().c_str(); ///
    strcpy(dato.usuario,strUsuario);                              ///Paso los QString a const char*
    const char* strNombre=auxDato.nombre.toStdString().c_str();   ///
    strcpy(dato.nombre,strNombre);
    const char* strApellido=auxDato.apellido.toStdString().c_str();
    strcpy(dato.apellido,strApellido);


    dato.clave=auxDato.clave.toInt();   ///
    dato.dni=auxDato.dni.toInt();       ///Guardo los datos en la variables para escribir en el archivo
    dato.contError=0;                   ///Inicio el contador de error en cero
    dato.dinero=0;                      ///Inicio dinero de la cuenta en cero
    fseek(archivo,0,SEEK_END);          ///
    fwrite(&dato,sizeof(dato),1,archivo);

    usuario->clear();
    clave->clear();             ///
    nombre->clear();            ///Limpio los QLineEdit
    apellido->clear();          ///
    dni->clear();

    fclose(archivo);
}
