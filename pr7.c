#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listaCircular.h"

int main(){
  nodo *lista, *elemento;
  int i, p;
  int hora[5]={2,5,8,17,20};
  int min[5]={5,15,20,30,45};
  int seg[5]={7,34,15,32,45};
  for(i=0;i<5;i++){
    elemento=crearNodo(hora[i], min[i], seg[i]);
    lista=inserta(&elemento,i,p);
  }
  eliminar(lista, &elemento, p);
  for(i=0;i<5;i++){
    siguiente(lista, &elemento);
	impNodo(lista, elemento);
  }
  return 0;
}
