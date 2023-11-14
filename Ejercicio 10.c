#include <stdio.h>
#include <stdlib.h>

#define FILAS 3
#define COLUMNAS 3

void m(int matriz[FILAS][COLUMNAS]) {
	printf("Introduce los valores para la matriz de 10x10:\n");
	for (int i = 0; i < FILAS; i++) {
		for (int j = 0; j < COLUMNAS; j++) {
			scanf("%d", &matriz[i][j]);
		}
	}
}

void sumas(int matriz[FILAS][COLUMNAS],int suma_filas[FILAS],int suma_columnas[COLUMNAS]) {
	for (int i = 0; i < FILAS; i++) {
		suma_filas[i] = 0;
		for (int j = 0; j < COLUMNAS; j++) {
			suma_filas[i] += matriz[i][j];
		}
	}
	
	for (int j = 0; j < COLUMNAS; j++) {
		suma_columnas[j] = 0;
		for (int i = 0; i < FILAS; i++) {
			suma_columnas[j] += matriz[i][j];
		}
	}
	
	printf("\nSuma de cada fila:\n");
	for (int i = 0; i < FILAS; i++) {
		printf("Fila %d: %d\n", i + 1, suma_filas[i]);
	}
	
	printf("\nSuma de cada columna:\n");
	for (int j = 0; j < COLUMNAS; j++) {
		printf("Columna %d: %d\n", j + 1, suma_columnas[j]);
	}
}

int main() {
	int matriz[FILAS][COLUMNAS];
	int suma_filas[FILAS];
	int suma_columnas[COLUMNAS];
	
	m(matriz);
	sumas(matriz,suma_filas,suma_columnas);
	
	system("pause");
	return 0;
}
