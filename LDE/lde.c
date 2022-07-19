/*!
  *\file operLista.c
  *\version 1.4
  *\date 02/04/2018
  *\author David Estrada Gonzalez
  *\brief operaiones basicas de la lista doblemente enlazada
  */
#include "enlaceLista.h"

/*!
  *\brief creareInicializarLista crea una nueva lista y inicializa los parametros 
  *\return una lista sin elementos
  */
void creareInicializarLista(){
	int i;
	srand(time(NULL));
	// se crea la lista
	L=(Lista*)malloc( sizeof(Lista) );
	// se inicializa la lista.
    L->inicio = NULL;
	L->final = NULL;
 	L->tam = 0;
 	// se lenan los datos.
    for( i = 0; i < 100; i++ )
    {
       CrearNodo();
       nuevo->d.x = 1+rand()%((20+1)-1);
       insertar(L, nuevo, ultimo);
    }
    Menu_principal( L );
}

/*!
  *\brief CrearNodo crea un nuevo nodo sin datos
  *\return un nodo sin datos
  */
Nodo* CrearNodo(){
	 nuevo=(Nodo*)malloc( sizeof(Nodo) );
	 nuevo->sig=NULL;
	 nuevo->ant=NULL;
	 return nuevo;
}

/*!
  *\brief Asignar_datos asigna un dato a un nodo por teclado
  *\param nuevo un nodo anteriormente creado 
  *\return un nodo con que ya contiene informacion
  */
void Asignar_datosNodo( Nodo* nuevo ){
	printf("Ingresa el dato del nodo: ");
	scanf("%d",&nuevo->d.x);
}


/*!
  *\brief TamanioLista muestra el numero de nodos que posee la lista 
  *\return tamanio de la lista, dato entero
  */
int TamanioLista( Lista* lista ){
	if(lista==NULL){
		printf("No existe la lista.\n");
		Menu_principal( L );
	}
	 printf("La lista posee %d elementos\n",lista->tam);
	 Menu_principal( L );
}

/*!
  *\brief insertar inserta un nodo a la lista por posicion, ya sea al principio, al final o en medio
  *\param lista una lista ya anteriormente creada, esta es la lista a la que se le insertara el nodo
  *\param nuevo nodo ya creado, este el nodo que se insertara a la lista
  *\param pos posicion en donde se incertara el nodo 
  *\return 1 si el nodo se incerto o -1 si no logro insertarse 
  */
int insertar( Lista* lista, Nodo* nuevo, int pos ){
	Nodo* iterador;
	if(lista != NULL){
    //Caso lista vacia
		if( lista->inicio == NULL )
      {
      	    lista->inicio = nuevo;
     	    lista->final = nuevo;
      }
		//caso 1 al inicio
	  else if( pos == primero || pos == 1 )
      {
			  nuevo->sig = lista->inicio;
			  lista->inicio->ant=nuevo;
			  lista->inicio = nuevo;
	  }
    //caso 3 al final
      else if( pos == ultimo )
      {
       		  lista->final->sig = nuevo;
       		  nuevo->ant=lista->final;
			  lista->final = nuevo;
	  }
    //caso 2 intermedio
      else if( pos > primero+1 && pos <= lista->tam )
      {
            int i;
			iterador = lista->inicio;
			for( i=2; i<pos; i++ )
            {
				iterador = iterador->sig;
			}
			nuevo->sig = iterador->sig;
			iterador->sig = nuevo;
			nuevo->ant=iterador;
			nuevo->sig->ant=nuevo;
	  }
      else
      {
		return -1;
	  }
	  ( lista->tam )++; 
      return 1;
	}
   else
   {
   	free(lista);
   	Menu_principal( L );
	return -1;
   }
   Menu_principal( L );
}


/*!
  *\brief mostrar imprime en pantalla todos los datos de la lista, en caso de que la lista no tenga datos, muestra un mensaje de erro
  *\param lista una lista ya creada 
  */
void mostrar( Lista* lista )
{
  Nodo* iterador;
  printf("\n");
  if(lista!=NULL){
  	if(lista->inicio!=NULL){
  		iterador = lista->inicio;
  		while( iterador != lista->final )
  		{
    	   	 printf( "%d ", iterador->d.x );
    	   	 iterador = iterador->sig;
    
  		}	
  		printf( "%d ", iterador->d.x );
  	}
  	else{
  		printf("\nNo existen elementos en la lista\n");
  		lista=NULL;
	  }
  }
  else{
  	printf("\nLa lista esta vacia\n");
  	free(lista);
  }
}

/*!
  *\brief consultarNodo busca un nodo segun su posicion 
  *\param lista una lista ya creada
  *\param pos la posicion del nodo a buscar
  *\return el valor del nodo o un -1 si la posicion es invalida
  */
int consultarNodo( Lista* lista, int pos ){
	Nodo* iterador;
	int i;
	printf("Ingrese la posicion: ");
	scanf("%d",&pos);
	if(lista==NULL){
		printf("No existe la lista\n");
		Menu_principal( L );
	}
	else{
    	iterador=lista->inicio;
        if( pos==ultimo || pos==-1 ){
    		printf("%d\n",lista->final->d.x);
    		Menu_principal( L );
    		return 1;
    	}
    	else if( pos<= lista->tam){
    		for( i=1; i<pos; i++ )
            {
       	      iterador = iterador->sig;
     	    }
	        printf("%d\n",iterador->d.x);
	        Menu_principal( L );
	    	return 1;	
	    }
	    else {
	    	return -1;
	    }		
	}
	Menu_principal( L );
}

/*!
  *\brief ModificarNodo cambia el valor de un nodo dada su posocion
  *\param lista lista en donde se encuentra el nodo 
  *\param pos posicion dode se encuentra el nodo que se desea modificar 
  *\return 1 si el nodo cambio efectivamente o -1 si no lo hizo
  */ 
int ModificarNodo( Lista* lista, int pos ){
	Nodo* iterador;
	int i;
	int a;
	if(lista==NULL){
		printf("Lista vacia.\n");
		Menu_principal( L );
	}
	else{
     	iterador=lista->inicio;
        if( pos==ultimo || pos==-1 ){
        	scanf("%d",&a);
    		lista->final->d.x=a;
    		Menu_principal( L );
    		return 1;
    	}	
    	if( pos<= lista->tam){
     		for( i=1; i<pos; i++ )
              {
    			iterador = iterador->sig;
			  }
    		scanf("%d",&a);
    		iterador->d.x=a;
    		Menu_principal( L );
    		return 1;
    	}
    	else {
    		return -1;
	    }		
	}
	Menu_principal( L );
}

/*!
  *\brief borrarLista borra todos los elementos de la lista 
  *\param lista una lista ya anteriormente creada 
  */
int borrarLista( Lista* lista ){
	int i;
	if(lista==NULL){
		printf("No existe la lista\n");
		Menu_principal( L );
	}
	else{
    	while( lista->tam!=1 ){
     	   eliminar(lista,ultimo);
        }
        lista->inicio=NULL;
        lista->final=NULL;
        (lista->tam)--;
    	lista=NULL;
    	free(lista);
    	printf("Lista eliminada\n");
    	Menu_principal( L );
    	return 1;		
	}
}

/*!
  *\brief eliminar elimina un nodo de la lista por posicion, ya sea al principio, al final o en medio
  *\param lista una lista ya anteriormente creada, esta es la lista a la que se le insertara el nodo
  *\param pos posicion del nodo que se desea eliminar
  *\return 1 si el nodo se elimino o -1 si no logro eliminarse 
  */
int eliminar( Lista* lista, int pos ){
	Nodo* iterador, *aux;
	int i=0;
	if( lista!=NULL ){
		if( lista->inicio!=NULL ){
			//caso 1 (eliminar el primer nodo)
			if( pos==primero||pos==1 ){
				aux=lista->inicio;
				lista->inicio=aux->sig;
				free(aux);
				lista->inicio->ant=NULL;
			}
			//caso 2 (eliminar el ultimo nodo)
			else if( pos==ultimo||pos==lista->tam){
				     Nodo* aux_2;
				     aux=lista->inicio;
				     aux_2=lista->inicio->sig;
				     while( aux_2->sig!=NULL ){
				     	    aux_2=aux_2->sig;
				     	    aux=aux->sig;
					 }
					 aux->sig=NULL;
					 lista->final=aux;
					 free(aux_2);
			}
			//caso 3 (eliminar posicion dada)
			else if( pos>primero+1&&pos<lista->tam ){
				     iterador=lista->inicio;
				     for( i=2; i<pos; i++){
				     	  iterador=iterador->sig;
					 }
					 aux=iterador->sig;
					 iterador->sig=aux->sig;
					 aux->sig->ant=iterador;
					 free(aux);
			}
			//posicion invalida
			else{
				printf("Posicion no valida\n");
				Menu_principal( L );
			}
			(lista->tam)--;
			return 1;
		}
    	else{
     		lista=NULL;
     		printf("Lista vacia\n");
     		Menu_principal( L );
     		return -1;
	    }
	}
	else{
		free(lista);
		printf("No existe la lista\n");
		Menu_principal( L );
		return -1;
	}
}

/*!
  *\brief copiarLista copia una lista ya dada y la pega en una nueva
  *\param lista una lista ya anteriormente creada
  *\return dos listas con el numero exacto de elementos 
  */
void copiarLista( Lista* lista ){
   int i;
   Nodo* iterador;
   Nodo* iterador1;
   L1=(Lista*)malloc(sizeof(Lista));
   L1->inicio=NULL;
   L1->final=NULL;
   L1->tam=0;
   L1->tam=lista->tam;
   printf("\nLa lista original es: \n");
   mostrar(lista);
   if(lista!=NULL){
      if(lista->inicio!=NULL){
   		 iterador=lista->inicio;
   		 iterador1=iterador;
   		 printf("\nLa copia de la lista es: \n");
   		 for(i=0;i<L1->tam;i++){
   	    	 while(iterador!=lista->final->sig){
   	    	 	iterador1=iterador;
   	    	 	insertar(L1,iterador,ultimo);
   	    	 	printf("%d ",iterador1->d.x);
   	    	 	iterador=iterador->sig;
   	    	 	iterador1=iterador1->sig;
	    	 }   		 	
   		 }
    	 printf("\n");
   	  }
   	  else{
   	   	 printf("No existen elementos en la copia de la lista.\n");
   	  	 lista=NULL;
   	  }
   }
   else{
   	  printf("\nNo existe la lista\n");
   }
}

/*!
  *\brief listaMitad corta una lista a la mitad y la otra mitad la incerta en una lista nueva
  *\param lista una lista ya anteriormente creada
  *\return dos listas con elemtos distintos 
  */
void listaMitad( Lista* lista ){
	Nodo* iterador;
	Nodo* iterador1;
	Nodo* iterador2;
	int i,x=0;
	L2=(Lista*)malloc(sizeof(Lista));
	if(lista!=NULL){
		if(lista->inicio!=NULL){
			iterador=lista->inicio;
			for(i=0;i<((lista->tam)/2);i++){
				iterador=iterador->sig;
			}
			L2->inicio=NULL;
			L2->final=NULL;
			L2->tam=0;
			iterador1=iterador;
			printf("\nLa mitad de la lista es:\n");
			while(iterador!=lista->final->sig){
				iterador1=iterador;
				insertar(L2,iterador1,ultimo);
				printf("%d ",iterador1->d.x);
				iterador=iterador->sig;
				iterador1=iterador1->sig;
			}			
			iterador=lista->inicio;
			x=((lista->tam)/2);
			x=x-1;
			for(i=0;i<x;i++){
				iterador=iterador->sig;
			}
			iterador2=iterador;
			iterador=lista->final;
			while(iterador!=iterador2){
				eliminar(lista,ultimo);
				iterador=NULL;
				iterador=lista->final;
			}
			printf("\nLa otra midad de la lista es: \n");
			mostrar(lista);
		}
		else{
			printf("\nNo existen elementos en la lista\n");
		}
	}
	else{
		printf("No existe la lista\n");
	}
}

/*!
  *\brief listaInversa invierte los datos de la lista 
  *\param lista una lista ya anteriormente creada
  *\return lista con los datos invertidos 
  */
void listaInversa( Lista* lista ){
   int i;
   Nodo* iterador;
   L1=(Lista*)malloc(sizeof(Lista));
   L1->inicio=NULL;
   L1->final=NULL;
   L1->tam=0;
   printf("\nLa lista original es: \n");
   mostrar(lista);
   if(lista!=NULL){
      if(lista->inicio!=NULL){
   		 iterador=lista->inicio;
   		 printf("\nLa inversa de la lista es: \n");
   		 for(i=0;i<lista->tam;i++){
   	    	 while(iterador!=lista->final->sig){
   	    	 	CrearNodo();
   	    	 	nuevo->d.x=iterador->d.x;
   	    	 	insertar(L1,nuevo,primero);
   	    	 	iterador=iterador->sig;
	    	 }   		 	
   		 }
   		 mostrar(L1);
    	 printf("\n");
   	  }
   	  else{
   	   	 printf("No existen elementos en la copia de la lista.\n");
   	  	 lista=NULL;
   	  }
   }
   else{
   	  printf("\nNo existe la lista\n");
   }
}

/*!
  *\brief primos busca los numeros primos de una lista y los separa en otra 
  *\param lista una lista ya anteriormente creada
  *\return lista que contiene solo numeros primos
  */
void primos(Lista* lista){
	Nodo* iterador;
	int i, numero,contador=0;
	L1=(Lista*)malloc(sizeof(Lista));
    L1->inicio=NULL;
    L1->final=NULL;
    L1->tam=0;
	if( lista!=NULL ){
		if( lista->inicio!=NULL ){
			printf("La lista original es:\n");
			mostrar( lista );
			printf("\n");
			iterador=lista->inicio;
			while(iterador!=lista->final->sig){
				numero=iterador->d.x;
				for( i=1;i<=numero;i++ ){
					if(numero%i==0){
						(contador)++;
					}	
				}
				if( contador==2 ){
					CrearNodo();
					nuevo->d.x=numero;
					insertar( L1, nuevo, ultimo);
				}
				contador=0;
				iterador=iterador->sig;
			}
			printf("La lista de primos es:\n");
			mostrar( L1 );
		}
		else{
			printf("La lista no tiene elementos\n");
		}
	}
	else{
		printf("La lista no existe\n");
	}
}

/*!
  *\brief Menu_primcipal operadpor primcipal de la aplicacion, controla oso ditintos operadores
  *\                     del menu con un switch
  *\param lista una lista ya anteriormente creada
  */
void Menu_principal( Lista* lista ){
	int opcion;
	printf("\n\t\tMenu principal\n\n");
	printf("1. Crear lista\n2. Tamanio de la lista\n3. Crear nodo\n4. Insertar nodo\n5. Modificar nodo\n6. Consultar nodo\n7. Eliminar nodo\n8. Eliminar lista\n9. Mostrar lista\n10 Copiar lista\n11. Partir lista a la mitad\n12. Inversa\n13. primos\n14. salir");
	printf("\nIngrese la opcion que desea: ");
	scanf("%d",&opcion);
	if(opcion<1 || opcion>14){
		do{
			printf("Opcion no valida. Intente de nuevo\n");
			printf("\nIngrese la opcion que desea: ");
           	scanf("%d",&opcion);
           	switch(opcion){
    			 case 1: creareInicializarLista(); break;
	    		 case 2: TamanioLista( lista ); break;
	    		 case 3: CrearNodo(); Asignar_datosNodo( nuevo ); Menu_principal( lista ); break;
	    		 case 4: printf("Ingrese le posicion: "); scanf("%d",&pos); /*nuevo=nuevo->d.x;*/ insertar( lista, nuevo, pos ); Menu_principal( lista ); break;
    			 case 5: printf("Ingrese la posicion: "); scanf("%d",&pos); ModificarNodo( lista, pos ); break;
	    		 case 6: consultarNodo( lista, pos ); break;
	    		 case 7: printf("Ingrese la posicion: "); scanf("%d",&pos); eliminar( lista, pos ); Menu_principal( L ); break;
	    		 case 8: borrarLista( lista ); break;
	     		 case 9: mostrar( lista ); Menu_principal( L ); break;
	     		 case 10: copiarLista( lista ); Menu_principal( L ); break;
	    		 case 11: listaMitad( lista ); Menu_principal( L ); break;
	    		 case 12: listaInversa( lista ); Menu_principal( L ); break;
	    		 case 13: primos( lista ); Menu_principal( L ); break;
	    		 case 14: exit(0);
	           }
		}while(opcion<1 || opcion>14);
	}
	else{
		switch(opcion){
			case 1: creareInicializarLista(); break;
			case 2: TamanioLista( lista ); break;
			case 3: CrearNodo(); Asignar_datosNodo( nuevo ); Menu_principal( lista ); break;
			case 4: printf("Ingrese le posicion: "); scanf("%d",&pos); /*nuevo=nuevo->d.x;*/ insertar( lista, nuevo, pos ); Menu_principal( lista ); break;
			case 5: printf("Ingrese la posicion: "); scanf("%d",&pos); ModificarNodo( lista, pos ); break;
			case 6: consultarNodo( lista, pos ); break;
			case 7: printf("Ingrese la posicion: "); scanf("%d",&pos); eliminar( lista, pos ); Menu_principal( L ); break;
			case 8: borrarLista( lista ); break;
			case 9: mostrar( lista ); Menu_principal( L ); break;
			case 10: copiarLista( lista ); Menu_principal( L ); break;
			case 11: listaMitad( lista ); Menu_principal( L ); break;
			case 12: listaInversa(lista); Menu_principal( L ); break;
			case 13: primos( lista ); Menu_principal( L ); break;
			case 14: exit(0);
			
		}
	}
}
