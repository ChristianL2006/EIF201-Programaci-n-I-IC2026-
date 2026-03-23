#ifndef VEHICULO_H
#define VEHICULO_H
#include <iostream>
#include <string>
namespace UNA {
	class Vehiculo
	{
	private:
		std::string placa;
		std::string marca;
		int anio;
		double kilometraje;
		bool activo;

	public:
		Vehiculo(std::string placa, std::string marca, int anio, double kilometraje, bool activo);

		//Get
		std::string getPlaca() const;
		std::string getMarca() const;
		int getAnio() const;
		double getKilometraje()const;
		bool getActivo() const;

		//Metodos
		void regristrarKilometros(double km);
		void desactivar();
		void activar();
		void mostrar() const;
	};

}

#endif