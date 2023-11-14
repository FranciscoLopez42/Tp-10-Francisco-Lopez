#include <stdio.h>
#include <stdlib.h>

void imprimirMatriz(int matriz[][6], int filas, int columnas) {
	printf("Ingrese los elementos de la matriz (%d x %d):\n", filas, columnas);
	for (int i = 0; i < filas; i++) {
		for (int j = 0; j < columnas; j++) {
			scanf("%d", &matriz[i][j]);
		}
	}
	
	printf("La matriz es:\n");
	for (int i = 0; i < filas; i++) {
		for (int j = 0; j < columnas; j++) {
			printf("%d ", matriz[i][j]);
		}
		printf("\n");
	}
}

void contarNegativos(int matriz[][6], int filas, int columnas, int *contadorNegativos) {
	*contadorNegativos = 0;
	for (int i = 0; i < filas; i++) {
		for (int j = 0; j < columnas; j++) {
			if (matriz[i][j] < 0) {
				(*contadorNegativos)++;
			}
		}
	}
}

int contarDiagonalCero(int matriz[][6], int filas, int columnas) {
	int contadorDiagonalCero = 0;
	for (int i = 0; i < filas && i < columnas; i++) {
		if (matriz[i][i] == 0) {
			contadorDiagonalCero++;
		}
	}
	return contadorDiagonalCero;
}

int main() {
	int filas = 5;
	int columnas = 6;
	int matriz[filas][6];
	
	imprimirMatriz(matriz, filas, columnas);
	
	int negativos;
	contarNegativos(matriz, filas, columnas, &negativos);
	int diagonalCero = contarDiagonalCero(matriz, filas, columnas);
	
	printf("\nCantidad de elementos negativos en la matriz: %d\n", negativos);
	printf("Cantidad de elementos de la diagonal principal iguales a cero: %d\n", diagonalCero);
	
	system("pause");
	return 0;
}

