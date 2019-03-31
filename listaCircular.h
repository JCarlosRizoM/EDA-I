#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct lista{
  int hora,min,seg;
  
  struct lista *sig; 
  struct lista *ant;
}nodo;

void insertar(nodo **elemento, int i, int p);
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

nodo *inserta(nodo **elemento, int i, int p){
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

void eliminar(nodo *lista, nodo **elemento, int p){
	nodo *aux=primero;
	nodo *elim, *siguiente;
	int i;
	printf("Seleccione la posicion a eliminar: \n");
	scanf("%d", &p);
	if(p>=1){
		for(i=0 ; i<p-1 ; i++){
			aux=aux->sig;
		}
		elim=aux->sig;
		aux->sig=aux->sig->sig;
		elim=NULL;
		free(elim);
	}
	else if(p==0){
		aux=primero;
		elim=aux;
		aux=aux->sig;
		ultimo->sig=aux;
		elim=NULL;
		free(elim);
	}
	else{
		printf("Posicion no valida.\n\n");
	}
}

void impNodo(nodo *lista, nodo *e){
  nodo *aux=e;
  printf("Hora: %d \n", aux->hora);
  printf("Minutos: %d \n", aux->min);
  printf("Segundos: %d \n\n", aux->seg);
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
