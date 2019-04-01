#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct lista{
  int hora,min,seg;
  
  struct lista *sig; 
  struct lista *ant;
}nodo;

void insertarElemento(nodo *lista, nodo **elemento, int p, int h, int m, int s);
void eliminar(nodo *lista, nodo **elemento, int p);
void siguiente(nodo *lista, nodo **pivote);
void anterior(nodo *lista, nodo **pivote);
void impNodo(nodo *lista, nodo *e);

nodo* primero=NULL;
nodo* ultimo=NULL;

nodo *crearNodo(int h, int m, int s){
  nodo *nuevo=(nodo*) malloc(sizeof(nodo));
  nuevo->hora=h;
  nuevo->min=m;
  nuevo->seg=s;
  nuevo->sig=NULL;
  nuevo->ant=NULL;
  return nuevo;
}

nodo *insertarNodo(nodo **elemento, int i, int p){
  nodo *aux=*elemento;
  if(primero==NULL){
	primero=aux;
    primero->sig=NULL;
    primero->ant=NULL;
    ultimo=primero;
  }
  else{
    ultimo->sig=aux;
    aux->sig=NULL;
    aux->ant=ultimo;
    ultimo=aux;
    }
}

void insertarElemento(nodo *lista, nodo **elemento, int p, int h, int m, int s){
	nodo *aux=lista;
	aux=primero;
	nodo *siguiente, *anterior;
	int i;
	if((p>=1)&&(p<=4)){
		for(i=0 ; i<=p-1 ; i++){
			aux=aux->sig;
			if(i==p-1){
				anterior=aux;
			}
		}
		siguiente=aux->sig;
		aux=ultimo;
		for(i=4;i>p;i--){
			aux->hora=aux->ant->hora;
			aux->min=aux->ant->min;
			aux->seg=aux->ant->seg;
			aux=aux->ant;
		}
		anterior->sig=siguiente;
		siguiente->ant=anterior;
		aux->hora=h;
		aux->min=m;
		aux->seg=s;
	}
	else if(p==0){
		anterior=ultimo;
		siguiente=primero;
		aux=ultimo;
		for(i=4;i>p;i--){
			aux->hora=aux->ant->hora;
			aux->min=aux->ant->min;
			aux->seg=aux->ant->seg;
			aux=aux->ant;
		}
		anterior->sig=siguiente;
		siguiente->ant=anterior;
		aux->hora=h;
		aux->min=m;
		aux->seg=s;
	}
	else{
		printf("Posicion no valida.\n\n");
	}
}

void eliminar(nodo *lista, nodo **elemento, int p){
	nodo *aux=lista;
	aux=primero;
	nodo *siguiente, *anterior;
	int i;
	if((p>=1)&&(p<=4)){
		for(i=0 ; i<=p-1 ; i++){
			aux=aux->sig;
			if(i==p-1){
				anterior=aux;
			}
		}
		siguiente=aux->sig;
		while(aux->sig!=ultimo->sig){
			aux->hora=aux->sig->hora;
			aux->min=aux->sig->min;
			aux->seg=aux->sig->seg;
			aux=aux->sig;
		}
		anterior->sig=siguiente;
		siguiente->ant=anterior;
		ultimo->hora=0;
		ultimo->min=0;
		ultimo->seg=0;
	}
	else if(p==0){
		anterior=ultimo;
		siguiente=primero;
		while(aux->sig!=NULL){
			aux->hora=aux->sig->hora;
			aux=aux->sig;
		}
		anterior->sig=siguiente;
		siguiente->ant=anterior;
		ultimo->hora=0;
		ultimo->min=0;
		ultimo->seg=0;
	}
	else{
		printf("Posicion no valida.\n\n");
	}
}

void impNodo(nodo *lista, nodo *e){
  if(e!=NULL){
  	printf("Hora: %d \n", e->hora);
  	printf("Minutos: %d \n", e->min);
	printf("Segundos: %d \n\n", e->seg);	
  }
  else{
  	printf("No hay lista existente. \n");
  }
}       

void siguiente(nodo *lista, nodo **pivote){
  nodo *aux=*pivote;
  printf("------------Siguiente-----------------\n");
  if(aux==NULL){
    aux=primero;
  }
  else{
	aux=*pivote;
  }
  if(aux->sig==NULL){
    aux->sig=primero;//CIRCULAR
  }
  if(primero!=NULL){
    aux=aux->sig;
  }
  *pivote=aux;
}

void anterior(nodo *lista, nodo **pivote){
  nodo *aux=*pivote;
  printf("------------Anterior-----------------\n");
  if(aux==NULL){
    aux=ultimo;
  }
  else{
	aux=*pivote;
  }
  if(aux->ant==NULL){
    aux->ant=ultimo;//CIRCULAR
  }
  if(ultimo!=NULL){
    aux=aux->ant;
  }
  *pivote=aux;
}
