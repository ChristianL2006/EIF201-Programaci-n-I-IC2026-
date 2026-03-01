
#include <iostream>
#include "Ejercicio 2.h"

void ArregloInvertido(const int original[], int invertido[], int largo) {
	for (int i = 0; i < largo; i++) {
		invertido[i] = original[largo - 1 - i];
	}
}


int main()
{
	int largo;

	do {
		std::cout << "Ingrese el Largor, Maximo 20:";
		std::cin >> largo;
		if (largo <= 0 || largo > 20) {
			std::cout << "Tamaño Invalido.";
		}
	} while (largo <= 0 || largo > 20); {

		int original[20];
		int invertido[20];

		for (int i = 0; i < largo; i++) {
			std:: cout << "Ingrese el valor " << i + 1 << ": ";
			std::cin >> original[i];

		}
		ArregloInvertido(original, invertido, largo);

		// Mostrar arreglo original
		std::cout << "\nArreglo original:\n";
		for (int i = 0; i < largo; i++)
		{
			std::cout << original[i] << " ";
		}

		// Mostrar arreglo invertido
		std::cout << "\n\nArreglo invertido:\n";
		for (int i = 0; i < largo; i++)
		{
			std::cout << invertido[i] << " ";
		}

		return 0;
	}
	
	
	
	
	
	
	
	
}

