#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
  int x;
  int y;

  struct lista *sig;
}nodo;

nodo *crearNodo(int x, int y){
  nodo *nuevo=(nodo*) malloc(sizeof(nodo));
  nuevo->x=x;
  nuevo->y=y;
  nuevo->sig=NULL;
  return nuevo;
}

nodo *insertar(nodo *lista, nodo *e){
  nodo *aux=e;
  nodo *ultimo, *cx, *cy;
  if(aux==NULL){
    aux=e;
    ultimo=e;
  }
  else{
  	aux->sig=ultimo;
    ultimo=aux;
    while(aux->x>aux->sig->x){
	  cx=aux->sig->x;
      cy=aux->sig->y;
	  aux->sig->x=aux->x;
	  aux->sig->y=aux->y;
      aux->x=cx;
      aux->y=cy;
      aux=aux->sig;
    }
  }
  lista=aux;
  return lista;
}
