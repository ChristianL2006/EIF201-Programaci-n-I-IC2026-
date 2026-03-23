#include "Flota.h"
#include <iomanip>
#include <iostream>

namespace UNA {
	Flota::Flota() : cantidad(0), capacidad(CAPACIDAD_INICIAL) {
		vehiculos = new Vehiculo * [capacidad];
	}

	Flota:: ~Flota(){
		for (int i = 0; i < cantidad; i++) {
			delete vehiculos[i];
		}
		delete[] vehiculos;
	}
	void Flota::redimensionar() {
		int nuevaCapacidad = capacidad * 2;
		Vehiculo** nuevoArreglo = new Vehiculo * [nuevaCapacidad];

		for (int i = 0; i < cantidad; i++) {
			nuevoArreglo[i] = vehiculos[i];

		}
		delete[] vehiculos;          
		vehiculos = nuevoArreglo;
		capacidad = nuevaCapacidad;

		std::cout << "Arreglo redimensionado. Nueva capacidad: " << capacidad << ".\n";
	}
	void Flota::agregar(Vehiculo* nuevo) {
		if (cantidad = capacidad) {
			redimensionar();
		}
		vehiculos[cantidad] = nuevo;
		cantidad++;
		std::cout << "[OK] Vehiculo " << nuevo->getPlaca() << " registrado en la flota.\n";
	}




}