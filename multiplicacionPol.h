#include <stdio.h>
float multiplicacion(float pol1[], float pol2[], int i, int j, int k);

float multiplicacion(float pol1[], float pol2[], int i, int j, int k){
	int m;
	float res[j];
	for (m=0; m<j; m++){ //(m=j; m>0; m--)       (m=0; m<j; m++)
			res[i+m] += pol1[i] * pol2[m];
			//printf("%d\n",m);
			//printf("%.2f x %.2f = %.2f\n",pol1[i],pol2[m],res[i+m]);
			printf(" ");
        }
	return res[i];
}
