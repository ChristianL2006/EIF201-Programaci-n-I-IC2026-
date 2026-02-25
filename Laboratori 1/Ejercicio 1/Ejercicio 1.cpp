
#include <iostream>
#include "Estadistica.h"


int main()
{
	const int Tam = 10;
	int Arreglo[Tam];

	std::cout << "Ingrese 10 Numeros positivos: ";
	for (int i = 0; i < Tam; i++) {
		std::cout << "\nNumero " << i + 1 << ": ";
		std::cin >> Arreglo[i];
	}

	int Mayor = ObMayor(Arreglo, Tam);
	int Menor = ObMenor(Arreglo, Tam);
	int suma = SumaArreglo(Arreglo, Tam);
	double Promedio = CPromedio(Arreglo, Tam);

  

	std::cout << "\nMayor es: " << Mayor;
	std::cout << "\nMenor es: " << Menor;
	std::cout << "\nLa suma del Arreglo es: " << suma;
	std::cout << "\nEl Promedio es: " << Promedio << "\n";
}


int ObMayor(int Arreglo[], int Tam) {
	int Mayor = Arreglo[0];
	for (int i = 1; i < Tam; i++) {
		if (Arreglo[i] > Mayor) {
			Mayor = Arreglo[i];

		}
	}
	return Mayor;
}

int ObMenor(int Arreglo[], int Tam) {
	int Menor = Arreglo[0];
	for (int i = 1; i < Tam; i++) {
		if (Arreglo[i] < Menor) {
			Menor = Arreglo[i];
		}

	}

	return Menor;
}
int SumaArreglo(int Arreglo[], int Tam) {
	int suma = 0;
	for (int i = 0; i < Tam; i++) {
		suma += Arreglo[i];
	}

	return suma;
}

double CPromedio(int Arreglo[], int Tam) {
	int suma = SumaArreglo(Arreglo, Tam);
	return (double)suma / Tam;

}

33