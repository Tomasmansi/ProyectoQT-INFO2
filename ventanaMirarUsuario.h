#pragma once /*SOLAMENTE COPIA UNA VEZ LA CABEZA*/

#include <QWidget>
#include <QLabel>
#include <QTextEdit>
#include <QPushButton>
#include <QScrollArea>
#include "ventanaPrincipal.h"
#include "structDatoCuenta.h"
#include "ventanaPrincipal.h"

class principal;

class nodo : public QLabel {
    public:
    nodo * sig;
    QLabel * datoLabelUsuario;
    QLabel * datoLabelNombre;
    QLabel * datoLabelDni;
};

class usuario : public QWidget {  /*LA CLASS HEREDA LA CLASE QWIGDET*/

    Q_OBJECT

    private:
        QTabWidget * tabWidget; /*Creo dos ventanas*/
        /*ventana datos*/
        QWidget * datos;
        QLabel * lblUsuario;
        QLabel * lblNombre;
        QLabel * lblApellido;
        QLabel * lblDni;

        nodo * inicio;

        QScrollArea * scroll;

        /*ventana exterior*/
        QPushButton * volver;
        principal * puntPrincipal;

        /*Para eliminar datos*/
        int cantidadDatos;
        QLabel * puntLabel;
    public:
        usuario(QWidget *parent = 0);
        void liberarMemoria();
        void setVentanaPrincipal(principal *);
        void mostrarUsuarios();
        void nuevoLabel(nodo *, QString , QString,QString);

    public slots:
        void volverPrincipal();
};

