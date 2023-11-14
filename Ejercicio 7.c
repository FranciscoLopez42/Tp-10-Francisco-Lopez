#include <stdio.h>
#include <stdlib.h>

void ingresarMatriz(int matriz[12][19]) {
	printf("Ingrese los elementos de la matriz (12x19):\n");
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 19; j++) {
			scanf("%d", &matriz[i][j]);
		}
	}
}

void cambiarNegativosACero(int matriz[12][19]) {
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 19; j++) {
			if (matriz[i][j] < 0) {
				matriz[i][j] = 0;
			}
		}
	}
}

void imprimirMatriz(int matriz[12][19]) {
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 19; j++) {
			printf("%d ", matriz[i][j]);
		}
		printf("\n");
	}
}

int main() {
	int matriz[12][19];
	
	ingresarMatriz(matriz);
	
	printf("\nMatriz original:\n");
	imprimirMatriz(matriz);
	
	cambiarNegativosACero(matriz);
	
	printf("\nMatriz con elementos negativos cambiados a cero:\n");
	imprimirMatriz(matriz);
	
	system("pause");
	return 0;
}
