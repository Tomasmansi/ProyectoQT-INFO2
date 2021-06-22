#include "ventanaCuenta.h"
#include "structDatoCuenta.h"

cuenta::cuenta(QWidget *parent) : QWidget(parent)
{
    setWindowTitle("Cuenta");
    setGeometry(300,50,300,300);
    setFixedSize(300,300);

    lblDatos = new QLabel("Bienvenido ",this);      ///
    QFont fuenteTitulo( "Arial", 15, QFont::Bold);  /// Titulo de la ventana
    lblDatos->setFont(fuenteTitulo);                ///
    lblDatos->setGeometry(60,12,150,40);

    lblSeleccionar = new QLabel("Seleccionar: ",this);
    lblSeleccionar->setFont(fuenteTitulo);
    lblSeleccionar->setGeometry(50,60,150,40);

    deposita = new QPushButton("Depositar",this);
    deposita->setGeometry(150, 90, 80, 40);

    extraer = new QPushButton("Extraer",this);
    extraer->setGeometry(150, 130, 80, 40);

    dineroButton = new QPushButton("Ver dinero",this);
    dineroButton->setGeometry(150, 170, 80, 40);

    salir = new QPushButton("Salir",this);
    salir->setGeometry(110, 250, 80, 40);

    puntExtraccion=NULL;
    puntDepositar=NULL;
    puntDinero=NULL;

    connect(deposita, SIGNAL(clicked()),this, SLOT(verDepositar()));
    connect(extraer, SIGNAL(clicked()),this, SLOT(verExtraer()));
    connect(dineroButton, SIGNAL(clicked()),this, SLOT(verDinero()));
    connect(salir, SIGNAL(clicked()), qApp, SLOT(quit()));
}

void cuenta::verExtraer()
{
    if(!puntExtraccion)
    {
        puntExtraccion = new extraccion();
        puntExtraccion->setCuenta(this); /*PARA PODER REGRESAR AL PRINCIPIO*/
        puntExtraccion->guardarPosicion(posicionUsuario);
    }
    hide();
    puntExtraccion->show();
}

void cuenta::verDepositar()
{
    if(!puntDepositar)
    {
        puntDepositar = new depositar();
        puntDepositar->setCuenta(this); /*PARA PODER REGRESAR AL PRINCIPIO*/
        puntDepositar->guardarPosicion(posicionUsuario);
    }
    hide();
    puntDepositar->show();
}

void cuenta::guardarPosicion(int pos)
{
    posicionUsuario=pos;
}

void cuenta::verDinero()
{
    FILE * archivo;
    datoCuenta dato;

    if(!(archivo = fopen("BASE DE DATOS.txt","rb")))
    {
        printf("\nERROR APERTURA DE DISCO.\n");
        exit(0);
    }

    fseek(archivo,(long)(posicionUsuario*sizeof(dato)),SEEK_SET); ///Llevo la ventana a la posicion del usuario ingresado
    fread(&dato,sizeof(dato),1,archivo);

    if(!puntDinero)                 ///
    {                               /// Creo la ventana Dinero
        puntDinero = new dinero();  ///
        puntDinero->setCuenta(this); /*Le paso la direccion para poder volver*/
    }
    puntDinero->setDinero(dato.dinero); /*Le paso el int de dinero del usuario */
    hide();
    puntDinero->show();
    fclose(archivo);
}
