#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listaCircular.h"

int main(){
  nodo *lista, *elemento;
  int i, p=0;
  int hora[5]={2,5,8,17,20};
  int min[5]={5,15,20,30,45};
  int seg[5]={7,34,15,32,45};
  
  int hora2[5]={1,3,4,6,7};
  int min2[5]={13,14,18,22,27};
  int seg2[5]={30,35,40,35,30};
  
  for(i=0;i<5;i++){
    elemento=crearNodo(hora[i], min[i], seg[i]);
    lista=insertarNodo(&elemento,i,p);
  }
/*-----------------------------------------------------------Función Insertar------------------------------------------------------*/
  insertarElemento(lista, &elemento,p,hora2[p], min2[p], seg2[p]);
  for(i=0;i<5;i++){
    siguiente(lista, &elemento);
	impNodo(lista, elemento);
  }
  insertarElemento(lista, &elemento,p,hora2[p+1], min2[p+1], seg2[p]+1);
  for(i=0;i<5;i++){
    siguiente(lista, &elemento);
	impNodo(lista, elemento);
  }
	/*-----------------------------------------Esta parte solo imprime con la función anterior---------------------------------*/
  for(i=0;i<5;i++){
    anterior(lista, &elemento);
	impNodo(lista, elemento);
  }
  /*----------------------Descomentar esta sección de código para poner en funcionamiento la función eliminar----------------------*
  eliminar(lista, &elemento, p);
  for(i=0;i<5;i++){
    siguiente(lista, &elemento);
	impNodo(lista, elemento);
  }
  eliminar(lista, &elemento, p);
  for(i=0;i<5;i++){
    anterior(lista, &elemento);
	impNodo(lista, elemento);
  }*/
  return 0;
}
