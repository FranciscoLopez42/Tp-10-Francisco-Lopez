#include <stdio.h>
#include <stdlib.h>

#define NUM_CHOFERES 5
#define DIAS_TRABAJADOS 6

void ingresarDatosChofer(int legajos[], int horasTrabajadas[][DIAS_TRABAJADOS], float sueldoPorHora[], char nombres[][50], int i) {
	printf("\nIngresando datos para el chofer %d:\n", i + 1);
	
	printf("Ingrese el número de legajo: ");
	scanf("%d", &legajos[i]);
	
	printf("Ingrese el nombre del chofer: ");
	scanf("%s", nombres[i]);
	
	printf("Ingrese las horas trabajadas cada día de la semana:\n");
	for (int j = 0; j < DIAS_TRABAJADOS; j++) {
		printf("Día %d: ", j + 1);
		scanf("%d", &horasTrabajadas[i][j]);
	}
	
	printf("Ingrese el sueldo por hora: ");
	scanf("%f", &sueldoPorHora[i]);
}

void calcularTotalHorasSemanal(int horasTrabajadas[][DIAS_TRABAJADOS], int totalHorasSemana[], int cantidadChoferes) {
	for (int i = 0; i < cantidadChoferes; i++) {
		totalHorasSemana[i] = 0;
		for (int j = 0; j < DIAS_TRABAJADOS; j++) {
			totalHorasSemana[i] += horasTrabajadas[i][j];
		}
	}
}

void calcularSueldoSemanal(int totalHorasSemana[], float sueldoPorHora[], float sueldoSemanal[], int cantidadChoferes) {
	for (int i = 0; i < cantidadChoferes; i++) {
		sueldoSemanal[i] = totalHorasSemana[i] * sueldoPorHora[i];
	}
}

int choferConMasHorasLunes(int horasTrabajadas[][DIAS_TRABAJADOS], int cantidadChoferes) {
	int maxHorasLunes = horasTrabajadas[0][0];
	int choferMasHoras = 0;
	
	for (int i = 1; i < cantidadChoferes; i++) {
		if (horasTrabajadas[i][0] > maxHorasLunes) {
			maxHorasLunes = horasTrabajadas[i][0];
			choferMasHoras = i;
		}
	}
	
	return choferMasHoras;
}

void imprimirReporte(int legajos[], char nombres[][50], int totalHorasSemana[], float sueldoSemanal[], float totalEmpresa, int cantidadChoferes) {
	printf("\nReporte de la compañía de transporte:\n");
	printf("=======================================\n");
	
	for (int i = 0; i < cantidadChoferes; i++) {
		printf("Nombre: %s\n", nombres[i]);
		printf("Legajo: %d\n", legajos[i]);
		printf("Total de horas trabajadas a la semana: %d\n", totalHorasSemana[i]);
		printf("Sueldo semanal: %.2f\n", sueldoSemanal[i]);
		printf("---------------------------------------------------\n");
	}
	
	printf("Total a pagar por la empresa: %.2f\n", totalEmpresa);
}

int main() {
	int legajos[NUM_CHOFERES];
	int horasTrabajadas[NUM_CHOFERES][DIAS_TRABAJADOS];
	float sueldoPorHora[NUM_CHOFERES];
	char nombres[NUM_CHOFERES][50];
	
	for (int i = 0; i < NUM_CHOFERES; i++) {
		ingresarDatosChofer(legajos, horasTrabajadas, sueldoPorHora, nombres, i);
	}
	
	int totalHorasSemana[NUM_CHOFERES];
	calcularTotalHorasSemanal(horasTrabajadas, totalHorasSemana, NUM_CHOFERES);
	
	float sueldoSemanal[NUM_CHOFERES];
	calcularSueldoSemanal(totalHorasSemana, sueldoPorHora, sueldoSemanal, NUM_CHOFERES);
	
	float totalEmpresa = 0;
	for (int i = 0; i < NUM_CHOFERES; i++) {
		totalEmpresa += sueldoSemanal[i];
	}
	
	int choferMasHorasLunes = choferConMasHorasLunes(horasTrabajadas, NUM_CHOFERES);
	printf("\nEl chofer que trabaja más horas el día lunes es: %s\n", nombres[choferMasHorasLunes]);
	
	imprimirReporte(legajos, nombres, totalHorasSemana, sueldoSemanal, totalEmpresa, NUM_CHOFERES);
	
	system("pause");
	return 0;
}
