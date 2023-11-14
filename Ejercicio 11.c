#include <stdio.h>
#include <stdlib.h>

#define TORRES 7
#define PISOS 20
#define DEPARTAMENTOS 6

void ingresarDatos(int habitantes[][PISOS][DEPARTAMENTOS]) {
	for (int torre = 0; torre < TORRES; torre++) {
		for (int piso = 0; piso < PISOS; piso++) {
			for (int departamento = 0; departamento < DEPARTAMENTOS; departamento++) {
				printf("Ingrese la cantidad de habitantes en la torre %d, piso %d, departamento %d: ", torre + 1, piso + 1, departamento + 1);
				scanf("%d", &habitantes[torre][piso][departamento]);
			}
		}
	}
}

void calcularEstadisticas(int habitantes[][PISOS][DEPARTAMENTOS], int totalHabitantes, int habitantesPorTorre[TORRES], float promedioPorTorre, float promedioPorPiso) {
	totalHabitantes = 0;
	promedioPorTorre = 0;
	promedioPorPiso = 0;
	
	for (int torre = 0; torre < TORRES; torre++) {
		habitantesPorTorre[torre] = 0;
		
		for (int piso = 0; piso < PISOS; piso++) {
			for (int departamento = 0; departamento < DEPARTAMENTOS; departamento++) {
				totalHabitantes += habitantes[torre][piso][departamento];
				habitantesPorTorre[torre] += habitantes[torre][piso][departamento];
			}
		}
		
		promedioPorTorre += habitantesPorTorre[torre];
	}
	
	promedioPorTorre /= TORRES;
	promedioPorPiso = (float)(totalHabitantes) / (TORRES * PISOS * DEPARTAMENTOS);
}

void imprimirResultados(int totalHabitantes, int habitantesPorTorre[TORRES], float promedioPorTorre, float promedioPorPiso) {
	printf("a) Cantidad total de habitantes del complejo: %d\n", totalHabitantes);
	
	for (int torre = 0; torre < TORRES; torre++) {
		printf("b) Cantidad total de habitantes en la torre %d: %d\n", torre + 1, habitantesPorTorre[torre]);
	}
	
	printf("c) Cantidad promedio de habitantes por torre: %.2f\n", promedioPorTorre);
	printf("d) Cantidad promedio de habitantes por piso: %.2f\n", promedioPorPiso);
}

int main() {
	int habitantes[TORRES][PISOS][DEPARTAMENTOS];
	int totalHabitantes = 0;
	int habitantesPorTorre[TORRES];
	float promedioPorTorre = 0, promedioPorPiso = 0;
	
	ingresarDatos(habitantes);
	calcularEstadisticas(habitantes, totalHabitantes, habitantesPorTorre, promedioPorTorre, promedioPorPiso);
	imprimirResultados(totalHabitantes, habitantesPorTorre, promedioPorTorre, promedioPorPiso);
	
	system("pause");
	return 0;
}

