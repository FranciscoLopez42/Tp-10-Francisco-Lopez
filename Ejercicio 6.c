#include <stdio.h>
#include <stdlib.h>

void leerMatriz(int matriz[][12], int filas, int columnas) {
	int i, j;
	printf("Ingrese los elementos de la matriz (%dx%d):\n", filas, columnas);
	for (i = 0; i < filas; i++) {
		for (j = 0; j < columnas; j++) {
			scanf("%d", &matriz[i][j]);
		}
	}
}

int sonDiagonalesIguales(int matriz1[][12], int matriz2[][12]) {
	int i;
	for (i = 0; i < 12; i++) {
		if (matriz1[i][i] != matriz2[i][i]) {
		}
	}
}

int main() {
	int matriz1[12][12];
	int matriz2[12][12];
	
	leerMatriz(matriz1, 12, 12);
	
	leerMatriz(matriz2, 12, 12);
	
	if (sonDiagonalesIguales(matriz1, matriz2)) {
		printf("Las diagonales principales son iguales.\n");
	} else {
		printf("Las diagonales principales no son iguales.\n");
	}
	
	system("pause");
	return 0;
}

