
#include <iostream>
#include <string>
#include <limits>
#include "Flota.h"
#include "Vehiculo.h"

using namespace UNA;
void limpiarBuffer() {
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void mostrarMenu() {
    std::cout << "\n||--------------------------------------||\n";
	std::cout << "||     FlotaExpress - Menu Principal   ||\n";
	std::cout << "\n||--------------------------------------||\n";
	std::cout << "||1. Registrar vehiculo                 ||\n";
	std::cout << "||2. Buscar vehiculo por placa          ||\n";
	std::cout << "||3. Mostrar vehiculo por marca         ||\n";
	std::cout << "||4. Regristrar kilometros              ||\n";
	std::cout << "||5. Desactivar Vehiculo                ||\n";
	std::cout << "||6. Reactivar vehiculo                 ||\n";
	std::cout << "||7. Eliminar vehiculo                  ||\n";
	std::cout << "||8. Mostrar flota completa             ||\n";
	std::cout << "||9. Cantidad de vehiculos activos      ||\n";
	std::cout << "||10.Salir                              ||\n";
    std::cout << "||--------------------------------------||\n";
	std::cout << "  Seleccione una opcion: ";
}


int main()
{
    Flota flota;
    int opcion = 0;

    do {
        mostrarMenu();
        std::cin >> opcion;
        limpiarBuffer();

        switch (opcion) {

          
        case 1: {
            std::string placa, marca;
            int anio;
            double km;

            std::cout << "\n--- Regristar Vehiculo ---\n";
            std::cout << "Placa       : ";
            std::getline(std::cin, placa);
            std::cout << "Marca       : ";
            std::getline(std::cin, marca);
            std::cout << "Año         : ";
            std::cin >> anio;
            std::cout << "Kilometraje : ";
            std::cin >> km;
            limpiarBuffer();

          
            if (flota.buscarPorPlaca(placa) != nullptr) {
                std::cout << "[ERROR] La placa del vehiculo ya existe \"" << placa << "\".\n";
                break;
            }

            Vehiculo* v = new Vehiculo(placa, marca, anio, km, true);
            flota.agregar(v);
            break;
        }

             
        case 2: {
            std::string placa;
            std::cout << "\n--- Buscar por Placa ---\n";
            std::cout << "Placa: ";
            std::getline(std::cin, placa);

            Vehiculo* v = flota.buscarPorPlaca(placa);
            if (v != nullptr) {
                v->mostrar();
            }
            else {
                std::cout << "[INFO] No se encontro nigun vehiculo con la placa:  \""
                    << placa << "\".\n";
            }
            break;
        }

             
        case 3: {
            std::string marca;
            std::cout << "\n--- Mostrar placa ---\n";
            std::cout << "Marca: ";
            std::getline(std::cin, marca);
            flota.mostrarPorMarca(marca);
            break;
        }

            
        case 4: {
            std::string placa;
            double km;
            std::cout << "\n--- Regristar Kilometros ---\n";
            std::cout << "Placa    : ";
            std::getline(std::cin, placa);

            Vehiculo* v = flota.buscarPorPlaca(placa);
            if (v != nullptr) {
                std::cout << "Kilometro Registrado: ";
                std::cin >> km;
                limpiarBuffer();
                v->regristrarKilometros(km);
            }
            else {
                std::cout << "No se encontro la placa \""
                    << placa << "\".\n";
            }
            break;
        }

             
        case 5: {
            std::string placa;
            std::cout << "\n--- Desactivar Vehiculo ---\n";
            std::cout << "Placa: ";
            std::getline(std::cin, placa);

            Vehiculo* v = flota.buscarPorPlaca(placa);
            if (v != nullptr) {
                v->desactivar();
            }
            else {
                std::cout << "No se encontro el vehiculo \""
                    << placa << "\".\n";
            }
            break;
        }

            
        case 6: {
            std::string placa;
            std::cout << "\n--- Reactivar Vehiculo ---\n";
            std::cout << "Placa: ";
            std::getline(std::cin, placa);

            Vehiculo* v = flota.buscarPorPlaca(placa);
            if (v != nullptr) {
                v->activar();
            }
            else {
                std::cout << "No se encontro el vehiculo por placa \""
                    << placa << "\".\n";
            }
            break;
        }

            
        case 7: {
            std::string placa;
            std::cout << "\n--- Eliminar Vehiculo ---\n";
            std::cout << "Placa: ";
            std::getline(std::cin, placa);
            flota.elimiar(placa);
            break;
        }

            
        case 8: {
            flota.mostrarTodos();
            break;
        }

            
        case 9: {
            int activos = flota.contarActivos();
            std::cout << "\nVehiculos Activos " << activos << ".\n";
            break;
        }

          
        case 10: {
            std::cout << "\nCerrando FlotaExpress\n";
            break;
        }

        default:
            std::cout << "[ERROR] Opción inválida. Ingrese un número del 1 al 10.\n";
            break;
        }

    } while (opcion != 10);

    return 0;
}











