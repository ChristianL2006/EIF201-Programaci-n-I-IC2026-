#ifndef FLOTA_H
#define FLOTA_H

#include "Vehiculo.h"
#include <iostream>

namespace UNA {
	class Flota
	{
	private:
		Vehiculo** vehiculos;
		int cantidad;
		int capacidad;

		static const int CAPACIDAD_INICIAL = 3;

		void redimensionar();

	public:
		Flota();
		~Flota();

		//Metodos
		void agregar(Vehiculo* nuevo);
		Vehiculo* buscarPorPlaca(std::string placa);
		void mostrarPorPlaca(std::string Marca);
		bool elimiar(std::string placa);
		int contarActivos();
		void mostrarTodos();
		

	};

}

#endif
