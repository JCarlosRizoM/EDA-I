#include <stdio.h>
#include <stdlib.h>
#include "listaOrdenada.h"

int main(){
  nodo *lista=NULL, *elemento;
  int i;
  elemento=crearNodo(4,8);
  lista=insertar(lista, elemento);
  elemento=crearNodo(7,5);
  lista=insertar(lista, elemento);
  elemento=crearNodo(1,2);
  lista=insertar(lista, elemento);
  
  printf("(%d,",lista->x);
  printf("%d)\n",lista->y);
  
  printf("(%d,",lista->sig->x);
  printf("%d)\n",lista->sig->y);
  
  printf("(%d,",lista->sig->sig->x);
  printf("%d)\n",lista->sig->sig->y);
  return 0;
}
