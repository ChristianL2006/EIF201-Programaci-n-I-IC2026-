#include "Flota.h"
#include <iomanip> 
#include <iostream>

namespace UNA {

    Flota::Flota() : cantidad(0), capacidad(3) {
        vehiculos = new Vehiculo * [capacidad];
    }

    Flota::~Flota() {
       
        for (int i = 0; i < cantidad; i++) {
            delete vehiculos[i];
        }
       
        delete[] vehiculos;
    }

    void Flota::redimensionar() {
        int nuevaCapacidad = capacidad * 2;
        Vehiculo** nuevo = new Vehiculo * [nuevaCapacidad];
        for (int i = 0; i < cantidad; i++) {
            nuevo[i] = vehiculos[i];
        }
        delete[] vehiculos;
        vehiculos = nuevo;
        capacidad = nuevaCapacidad;
        std::cout << "Arreglo redimensionado. Nueva capacidad: " << capacidad << "\n";
    }

    void Flota::agregar(Vehiculo* nuevo) {
        if (cantidad == capacidad) {
            redimensionar();
        }
        vehiculos[cantidad++] = nuevo;
        std::cout << "Vehiculo " << nuevo->getPlaca() << " registrado en la flota.\n";
    }

    Vehiculo* Flota::buscarPorPlaca(std::string placa) {
        for (int i = 0; i < cantidad; i++) {
            if (vehiculos[i]->getPlaca() == placa) {
                return vehiculos[i];
            }
        }
        return nullptr;
    }

    void Flota::mostrarPorMarca(std::string marca) {
        int encontrados = 0;
        for (int i = 0; i < cantidad; i++) {
            if (vehiculos[i]->getMarca() == marca) {
                vehiculos[i]->mostrar();
                encontrados++;
            }
        }
        if (encontrados == 0) {
            std::cout << "No hay vehiculos de la marca \"" << marca << "\" registrados.\n";
        }
        else {
            std::cout << "Total de vehiculos de la marca \"" << marca << "\": " << encontrados << "\n";
        }
    }

    bool Flota::eliminar(std::string placa) {
        for (int i = 0; i < cantidad; i++) {
            if (vehiculos[i]->getPlaca() == placa) {
                if (vehiculos[i]->getActivo()) {
                    std::cout << "El vehiculo " << placa
                        << " esta activo. Debe desactivarlo antes de darlo de baja.\n";
                    return false;
                }
               
                delete vehiculos[i];
                for (int j = i; j < cantidad - 1; j++) {
                    vehiculos[j] = vehiculos[j + 1];
                }
                cantidad--;
                std::cout << "Vehiculo " << placa << " eliminado de la flota.\n";
                return true;
            }
        }
        std::cout << "No se encontro un vehiculo con placa \"" << placa << "\".\n";
        return false;
    }

    int Flota::contarActivos()  {
        int total = 0;
        for (int i = 0; i < cantidad; i++) {
            if (vehiculos[i]->getActivo()) total++;
        }
        return total;
    }

    void Flota::mostrarTodos() {
        if (cantidad == 0) {
            std::cout << "La flota esta vacia. No hay vehiculos registrados.\n";
            return;
        }
        std::cout << "========== Flota Completa (" << cantidad << " vehiculo(s)) ==========\n";
        for (int i = 0; i < cantidad; i++) {
            vehiculos[i]->mostrar();
        }
    }

} 