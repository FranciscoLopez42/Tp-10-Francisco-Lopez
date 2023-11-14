#include <stdio.h>
#include <stdlib.h>

int m(int choferes[3][7],int fila,int col) {
	for(fila=0;fila<3;fila++){
		printf("Ingrese los kilometros hechos por el chofer %d en la semana:\n",fila+1);
		for(col=0;col<7;col++){
			printf("Dia %d\n",col+1);
			scanf("%d",&choferes[fila][col]);
		}
	}
	printf("\n\n");
	
	return fila;
}

void mostrar(int choferes[3][7],int fila,int col) {
	int totalsemana=0;
	printf("\nKilometros conducidos:\n");
	for(fila=0;fila<3;fila++){
		printf("Chofer %d\n",fila+1);
		for(col=0;col<7;col++){
			printf("Dia %d: %d kilometros\n",col+1,choferes[fila][col]);
			totalsemana+=choferes[fila][col];
		}
		printf("Total de la semana: %d kilometros hechos\n",totalsemana);
	}
}

int main(){
	int choferes[3][7],totalsemana=0,fila=0,col=0;
	
	m(choferes,fila,col);
	mostrar(choferes,fila,col);
	
	system("pause");
	return 0;
}
