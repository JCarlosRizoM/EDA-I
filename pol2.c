#include <stdio.h>
#include "sumaPol.h"
#include "multiplicacionPol.h"
#include "potenciaPol.h"

int captura(float n);
int imprimir(float pol3[], int i, int j);

int main(){
	int a, i, j, k, m, pot;
	printf("¿Que operacion desea realizar?\n");
	printf("1. Suma\n");
	printf("2. Multiplicacion\n");
	printf("3. Potencia\n");
	scanf("%d", &a);
	printf("Ingrese la el mayor exponente del primer polinomio: ");
	scanf("%i", &j);
	printf("Ingrese la el mayor exponente del segundo polinomio: ");
	scanf("%i", &k);
	int e=0;
	float pol1[j], pol2[k], pol3[j], n;
	printf("PRIMER POLINOMIO: \n");
	for(i=0; i<=j; i++){
		if(e!=0){
			printf("Introduce el coeficiente del exponente %d:   ", e);	
		}
		else{
			printf("Introduce el coeficiente de la constante:   ", e);	
		}
		pol1[i]=captura(n);
    	e++;
	}
	e=0;
	printf("SEGUNDO POLINOMIO: \n");
	for(i=0; i<=k; i++){
		if(e!=0){
			printf("Introduce el coeficiente del exponente %d:   ", e);	
		}
		else{
			printf("Introduce el coeficiente de la constante:   ", e);	
		}
		pol2[i]=captura(n);
    	e++;
	}
	switch(a){
		case 1:
			if(k>j){
				m=k;
				for(i=0; i<=m; i++){
					pol3[i]=suma(pol1, pol2, i, j, k);
				}
				j=k;
				for(i=m; i>=0; i--){
					imprimir(pol3, i, j);
				}
			}
			else{
				for(i=0; i<=j; i++){
					pol3[i]=suma(pol1, pol2, i, j, k);
				}
				for(i=j; i>=0; i--){
					imprimir(pol3, i, j);
				}
			}
		break;
		
		case 2:
			j=j+k;
			pol3[j];
			for(i=0; i<=j; i++){// (i=0; i<=j; i++)         (i=j; i>0; i--)
				pol3[i]=multiplicacion(pol1, pol2, i,j,k);
			}
			for(i=0; i<=j; i++){//(i=0; i<=j; i++)       (i=j; i>=0; i--)
				imprimirMulti(pol3, i, j);
				//printf("\t i = %d\n", i);
			}
		break;
		
		case 3:
			printf("Ingrese la potencia a elevar el primer polinomio: ");
			scanf("%d", &pot);
			j=j+pot;
			for(i=0; i<=j; i++){
				pol3[i]=potencia(pol1, pot, i, j);
			}
			for(i=0; i<=j; i++){
				imprimir(pol3, i, j);
			}
		break;
		
		default:
			printf("Opcion no valida. \n");
		break;
	}
	
	return 0;
}

int captura(float n){
	scanf("%f", &n);
	return n;
}

int imprimir(float pol3[], int i, int j){
	if(i==0){
		if(pol3[i]!=0){
			if((pol3[i]>0)&&(pol3[i+1]!=0)){
				printf("+%.2f", pol3[i]);
			}
			else if((pol3[i]>0)&&(pol3[i+1]==0)){
				printf("%.2f", pol3[i]);
			}
			/*else if(pol3[i]<0){
				printf("%.2f", pol3[i]);
			}*/
		}
	}
	
	else if(i==1){
		if(pol3[i]!=0){
			if((pol3[i]>0)&&(pol3[i+1]!=0)){
				printf("+%.2fx", pol3[i]);	
			}
			else if((pol3[i]>0)&&(pol3[i+1]==0)){
				printf("%.2fx", pol3[i]);	
			}
			/*else if(pol3[i]<0){
				printf("%.2fx", pol3[i]);	
			}*/
		}
	}
	
	else{
		if(pol3[i]!=0){
			if((pol3[i]>0)&&(pol3[i+1]!=0)){
				printf("+%.2fx^%d", pol3[i],j-i);
			}
			else if((pol3[i]>0)&&(pol3[i+1]==0)){
				printf("%.2fx^%d", pol3[i],j-i);
			}
			/*else if(pol3[i]<0){
				printf("%.2fx^%d", pol3[i],j);
			}*/
		}
	}
}

int imprimirMulti(float pol3[], int i, int j){
	if(i==0){
		if(pol3[i]!=0){
			if((pol3[i]>0)&&(pol3[i-1]!=0)){
				printf("+%.2f", pol3[i]);
			}
			else if((pol3[i]>0)&&(pol3[i-1]==0)){
				printf("%.2f", pol3[i]);
			}
		}
	}
	
	else if(i==1){
		if(pol3[i]!=0){
			if((pol3[i]>0)&&(pol3[i-1]!=0)){
				printf("+%.2fx", pol3[i]);	
			}
			else if((pol3[i]>0)&&(pol3[i-1]==0)){
				printf("%.2fx", pol3[i]);	
			}
		}
	}
	
	else{
		if(pol3[i]!=0){
			if((pol3[i]>0)&&(pol3[i-1]!=0)){
				printf("+%.2fx^%d", pol3[i],i);
			}
			else if((pol3[i]>0)&&(pol3[i-1]==0)){
				printf("%.2fx^%d", pol3[i],i);
			}
		}
	}
}
