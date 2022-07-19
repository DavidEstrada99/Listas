# Listas
En este repositorio se colocan las siguientes estructuras de datos en lenguaje C
1. Lista simplemente enlazada
2. Lista doblemente enlazada
3. Lista circular 
4. Lista circular doblemente enlazada

Por defecto las listas utilizan datos del tipo entero

Cada una de las 4 estructuras tienen las siguentes operaciones definidas 
1. void creareInicializarLista(); 
2. Nodo* CrearNodo();
3. void Asignar_datosNodo( Nodo* );
4. int TamanioLista( Lista* );
5. int insertar( Lista*, Nodo*, int );
6. void mostrar( Lista* );
7. int eliminar( Lista*, int );
8. borrarLista( Lista* );
9. int consultarNodo( Lista*, int );
10. int ModificarNodo( Lista*, int );
11. void copiarLista( Lista* );
12. void listaMitad( Lista* );
13. void listaInversa( Lista* );
14. void primos( Lista* );

Ademas de esto se cuenta tambien con una funcion de menu en el cual el usuario podra probar cada una de las funciones de dichas estructuras. 
