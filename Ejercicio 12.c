#include <stdio.h>
#include <stdlib.h>

#define SEMANAS 4
#define DIAS 7

void ingresarVentas(int ventas[][DIAS]) {
	printf("Ingrese las ventas diarias de la tienda María Shop:\n");
	
	for (int semana = 0; semana < SEMANAS; semana++) {
		printf("Semana %d:\n", semana + 1);
		for (int dia = 0; dia < DIAS; dia++) {
			printf("Día %d: ", dia + 1);
			scanf("%d", &ventas[semana][dia]);
		}
	}
}

int calcularTotalSemana(int ventas[], int dias) {
	int total = 0;
	for (int dia = 0; dia < dias; dia++) {
		total += ventas[dia];
	}
	return total;
}

float calcularPromedioSemana(int ventas[], int dias) {
	int total = calcularTotalSemana(ventas, dias);
	return (float)total / dias;
}

int encontrarSemanaMayorVenta(int ventas[][DIAS]) {
	int mayorVenta = 0;
	int semanaMayorVenta = 0;
	
	for (int semana = 0; semana < SEMANAS; semana++) {
		int totalSemana = calcularTotalSemana(ventas[semana], DIAS);
		if (totalSemana > mayorVenta) {
			mayorVenta = totalSemana;
			semanaMayorVenta = semana + 1;
		}
	}
	
	return semanaMayorVenta;
}

void imprimirEstadisticas(int ventas[][DIAS]) {
	printf("\nEstadísticas de ventas de María Shop:\n");
	
	for (int semana = 0; semana < SEMANAS; semana++) {
		int totalSemana = calcularTotalSemana(ventas[semana], DIAS);
		float promedioSemana = calcularPromedioSemana(ventas[semana], DIAS);
		
		printf("Semana %d:\n", semana + 1);
		printf("  Total de ventas: %d\n", totalSemana);
		printf("  Promedio de ventas: %.2f\n", promedioSemana);
	}
	
	int semanaMayorVenta = encontrarSemanaMayorVenta(ventas);
	printf("\nLa semana con mayor venta fue la semana %d.\n", semanaMayorVenta);
}

int main() {
	int ventas[SEMANAS][DIAS];
	
	ingresarVentas(ventas);
	imprimirEstadisticas(ventas);
	
	system("pause");
	return 0;
}

