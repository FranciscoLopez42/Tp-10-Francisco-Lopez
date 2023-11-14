#include <stdio.h>
#include <stdlib.h>

void leerVector(int vector[], int n) {
	int i;
	printf("Ingrese los elementos del vector: \n");
	for (i = 0; i < n; i++) {
		scanf("%d", &vector[i]);
	}
}

int reorganizarVectores(int vector1[], int vector2[], int n) {
	int i;
	for (i = 0; i < n; i++) {
		vector2[(i + 1) % n] = vector1[i];
	}
	return 0;
}

int main() {
	int n;
	int i;
	printf("Ingrese la cantidad de elementos que va a tener el vector: ");
	scanf("%d", &n);
	
	int vector1[n];
	int vector2[n];
	
	leerVector(vector1, n);
	
	reorganizarVectores(vector1, vector2, n);
	
	printf("El segundo vector reorganizado es: \n");
	for (i = 0; i < n; i++) {
		printf("%d ", vector2[i]);
	}
	
	system("pause");
	return 0;
}

