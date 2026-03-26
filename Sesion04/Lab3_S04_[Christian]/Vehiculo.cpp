#include "Vehiculo.h"
#include <iomanip>

namespace UNA {

	Vehiculo::Vehiculo(std::string placa, std::string marca, int anio, double kilometraje, bool activo) : placa(placa), marca(marca), anio(anio), kilometraje(kilometraje),
	activo(true){
	}

	//Getters
	std::string Vehiculo::getPlaca() const {
		return placa;
	}
	std::string Vehiculo::getMarca() const {
		return marca;
	}
	int Vehiculo::getAnio() const {
		return anio;
	}
	double Vehiculo::getKilometraje() const {
		return kilometraje;
	}
	bool Vehiculo::getActivo() const {
		return activo;
	}

	//----------------------------------------------------------//
	void Vehiculo::regristrarKilometros(double km) {
		if (!activo) {
			std::cout <<  "[ERROR]" << placa << " esta fuera de servicio no se puede registrar Kilometraje ";
			return;
		}
		
		if (km <= 0) {
			std::cout << "La cantidad de kilometros tiene que ser mayor a 0.\n";
			return;
		}
		kilometraje += km;
		std:: cout << "Se agregaron " << km <<"km al vehiculo" << placa << ". Kilometraje actual: " << kilometraje << " km.\n";
	}

	void Vehiculo::desactivar() {
		if (!activo) {
			std::cout << "El Vehiculo " << placa << "ya esta fuera de servicio. \n";
			return;
		}
		else {
			activo = false;
		}
		std::cout << "Vehiculo " << placa << "puesta ya fuera de servicio.\n";

	}

	void Vehiculo::activar() {
		if (activo) {
			std::cout << "El Vehiculo " << placa << "Ya estaba activo.\n";
			return;
		}
		activo = true;
		std::cout << "El Vehiculo " << placa << "se pondra en estado activo.\n";
	}

	void Vehiculo::mostrar() const {
		std::cout << "--------------------------------------------\n";
		std::cout <<  placa <<":  Placa el Vehiculo\n";
		std::cout << marca << ": Marca del Vehiculo\n";
		std::cout << anio << ": Anio del Vehivulo\n";
		std::cout << kilometraje << ": KM del Vehiculo\n";
		std::cout << "  Estado      : " << (activo ? "ACTIVO" : "FUERA DE SERVICIO") << "\n";
		std::cout << "--------------------------------------------\n";
	}






}