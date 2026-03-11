#include <iostream>
#include "Paqueterah.h"

double* crearRegistro(int& cantidad) {

	std::cout << "Ingrese la cantidad: ";
	std::cin >> cantidad;

	double* pesos = new double[cantidad];
	return pesos;


}
void ingresarPesos(double* pesos, int cantidad) {

	for (int i = 0; i < cantidad; i++) {
		do {
			std::cout << "Peso de Paquete" << i + 1 << " kg: ";
			std::cin >> pesos[i];
		} while (pesos[i] <= 0);

	}

}
double calcularPesoTotal(const double* pesos, int cantidad) {

	double suma = 0;
	for (int i = 0; i < cantidad; i++) {

		suma += pesos[i];

	}
	return suma;
}
int contarSobreLimite(const double* pesos, int cantidad, double limite) {
	int contar = 0;
	for (int i = 0; i < cantidad; i++) {
		if (pesos[i] > limite) {
			contar++;
			
		}
	}

	return contar;
}
const double* buscarMasPesado(const double* pesos, int cantidad) {
	const double* mayor = &pesos[0];
	for (int i = 0; i < cantidad; i++) {
		if (pesos[i] > *mayor) {
			mayor = &pesos[i];
		}
	}
	return mayor;
}