#include "temperatura.h"
#include <iostream>
#include <iomanip>

double* crearRegistro(int& cantidadDias) {
	std::cout << "+-------------------------------------+" << std::endl;
	std::cout <<  "| Sistema de Registro de Temperaturas |" << std::endl;
	std::cout << "+-------------------------------------+" << std::endl;
	std::cout << "Ingrese la cantidad de dias a registrar: ";
	std::cin >> cantidadDias;
	while (cantidadDias < 0) {

		std::cout << "Error: debe ser mayor a cero, intentelo de nuevo: ";
		std::cin >> cantidadDias;
	}
	double* registro = new double[cantidadDias];
	return registro;
}

void ingresarTemperaturas(double* registro, int cantidad) {
	std::cout << std::endl << "Ingrese las temperaturas en grados Celsius:" << std::endl;
	for (int i = 0; i < cantidad; i++ ) {
			std::cout << " Dia" << (i + 1) << ":";
			std::cin >> registro[i]; // equivalente a *(registro + i)
		}
}
