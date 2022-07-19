/*!
  *\file enlaceLista.h
  *\version 1.3
  *\date 30/03/2018
  *\author David Estrada Gonzalez
  *\brief biblioteca que contiene todas las operaiones basicas una lista
  */
#include <stdio.h>
#include <stdlib.h> 
#include <time.h>
#define primero 0
#define ultimo -1

/*!
  * struct->datos contiene el tipo de dato posee el nodo
  */
typedef struct
{
  int x;
}datos;

/*!
  * struct->Nodo plantilla del nodo 
  */
typedef struct nodo
{
  datos d;
  struct nodo* sig;
  struct nodo* ant;
}Nodo;

/*!
  * struct->Lista plantilla de la lista 
  */
typedef struct
{
  Nodo* inicio;
  Nodo* final;
  int tam;
}Lista;

// variables golbales necesarias.
Lista* L;
Lista* L1;
Lista* L2;
Nodo* nuevo;
int pos;

/*!
  *\brief creareInicializarLista crea una nueva lista y inicializa los parametros 
  *\return una lista sin elementos
  */
void creareInicializarLista();

/*!
  *\brief CrearNodo crea un nuevo nodo sin datos
  *\return un nodo sin datos
  */
Nodo* CrearNodo();

/*!
  *\brief Asignar_datos asigna un dato a un nodo por teclado
  *\param nuevo un nodo anteriormente creado 
  *\return un nodo con que ya contiene informacion
  */
void Asignar_datosNodo( Nodo* );

/*!
  *\brief TamanioLista muestra el numero de nodos que posee la lista 
  *\return tamanio de la lista, dato entero
  */
int TamanioLista( Lista* );

/*!
  *\brief insertar inserta un nodo a la lista por posicion, ya sea al principio, al final o en medio
  *\param lista una lista ya anteriormente creada, esta es la lista a la que se le insertara el nodo
  *\param nuevo nodo ya creado, este el nodo que se insertara a la lista
  *\param pos posicion en donde se incertara el nodo 
  *\return 1 si el nodo se incerto o -1 si no logro insertarse 
  */
int insertar( Lista*, Nodo*, int );

/*!
  *\brief mostrar imprime en pantalla todos los datos de la lista, en caso de que la lista no tenga datos, muestra un mensaje de erro
  *\param lista una lista ya creada 
  */
void mostrar( Lista* );

/*!
  *\brief eliminar elimina un nodo de la lista por posicion, ya sea al principio, al final o en medio
  *\param lista una lista ya anteriormente creada, esta es la lista a la que se le insertara el nodo
  *\param pos posicion del nodo que se desea eliminar
  *\return 1 si el nodo se elimino o -1 si no logro eliminarse 
  */
int eliminar( Lista*, int );

/*!
  *\brief borrarLista borra todos los elementos de la lista 
  *\param lista una lista ya anteriormente creada 
  */
int borrarLista( Lista* );

/*!
  *\brief consultarNodo busca un nodo segun su posicion 
  *\param lista una lista ya creada
  *\param pos la posicion del nodo a buscar
  *\return el valor del nodo o un -1 si la posicion es invalida
  */
int consultarNodo( Lista*, int );

/*!
  *\brief ModificarNodo cambia el valor de un nodo dada su posocion
  *\param lista lista en donde se encuentra el nodo 
  *\param pos posicion dode se encuentra el nodo que se desea modificar 
  *\return 1 si el nodo cambio efectivamente o -1 si no lo hizo
  */
int ModificarNodo( Lista*, int );

/*!
  *\brief copiarLista copia una lista ya dada y la pega en una nueva
  *\param lista una lista ya anteriormente creada
  *\return dos listas con el numero exacto de elementos 
  */
void copiarLista( Lista* );

/*!
  *\brief listaMitad corta una lista a la mitad y la otra mitad la incerta en una lista nueva
  *\param lista una lista ya anteriormente creada
  *\return dos listas con elemtos distintos 
  */
void listaMitad( Lista* );

/*!
  *\brief Menu_primcipal operadpor primcipal de la aplicacion, controla oso ditintos operadores
  *\                     del menu con un switch
  *\param lista una lista ya anteriormente creada
  */
void Menu_principal( Lista* );

/*!
  *\brief listaInversa invierte los datos de la lista 
  *\param lista una lista ya anteriormente creada
  *\return lista con los datos invertidos 
  */
void listaInversa( Lista* );

/*!
  *\brief primos busca los numeros primos de una lista y los separa en otra 
  *\param lista una lista ya anteriormente creada
  *\return lista que contiene solo numeros primos
  */
void primos( Lista* );


