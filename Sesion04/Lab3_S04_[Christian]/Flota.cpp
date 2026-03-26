#include "Flota.h"
#include <iomanip>
#include <iostream>

namespace UNA {
	Flota::Flota() : cantidad(0), capacidad(CAPACIDAD_INICIAL) {
		vehiculos = new Vehiculo * [capacidad];
	}

	Flota:: ~Flota() {
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
	Vehiculo* Flota::buscarPorPlaca(std::string placa) {
		for (int i = 0; i < cantidad; i++) {
			if (vehiculos[i]->getPlaca() == placa) {
				return vehiculos[i];
			}
		}
		return nullptr;
	}
	void Flota::mostrarPorMarca(std::string marca)  {
		int encontrados = 0;
		for (int i = 0; i < cantidad; i++) {
			if (vehiculos[i]->getMarca() == marca) {
				vehiculos[i]->mostrar();
				encontrados++;
			}
		}


		if (encontrados == 0) {
			std::cout << "[INFO] No hay vehiculos de la marca \"" << marca << "\" en la flota.\n";
		}
		else {
			std::cout << "[INFO] Total de vehiculos de la marca \"" << marca
				<< "\": " << encontrados << ".\n";
		}



	}
	bool Flota::elimiar(std::string placa) {
		for (int i = 0; i < cantidad; i++) {
			if (vehiculos[i]->getPlaca() == placa) {
				if (vehiculos[i]->getActivo()) {
					std::cout << "[ERROR] El vehiculo " << placa
						<< " aun esta activo. Debe desactivarlo antes de darlo de baja.\n";
					return false;
				}

			}
		}
		std::cout << "[ERROR] No se encontro ningun vehiculo con la placa \"" << placa << "\N";
		return false;


	}

	int Flota::contarActivos()  {
		int activos = 0;
		for (int i = 0; i < cantidad; i++) {
			if (vehiculos[i]->getActivo()) {
				activos++;
			}
		}
		return activos;
	}

	void Flota::mostrarTodos()  {
		if (cantidad == 0) {
			std::cout << "[INFO] La flota esta vacia. No hay vehiculos registrados.\n";
			return;
		}
		std::cout << "\n========== FLOTA COMPLETA (" << cantidad << " vehiculo(s)) ==========\n";
		for (int i = 0; i < cantidad; i++) {
			vehiculos[i]->mostrar();
		}
	}


}