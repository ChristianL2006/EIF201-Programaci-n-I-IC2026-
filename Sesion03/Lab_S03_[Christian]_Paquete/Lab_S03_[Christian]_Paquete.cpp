// Lab_S03_[Christian]_Paquete.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include "Paqueterah.h"

int main()
{
    int cantidad;

    double* pesos = crearRegistro(cantidad);

    ingresarPesos(pesos, cantidad);

    double total = calcularPesoTotal(pesos, cantidad);

    double promedio = total / cantidad;

    double limite;
    std::cout << "Ingrese el limite de peso:";
    std::cin >> limite;

    int sobreLimite = contarSobreLimite(pesos, cantidad, limite);

    const double* masPesado = buscarMasPesado(pesos, cantidad);

    std::cout << "\n--- RESULTADOS ---\n";
    std::cout << "Peso total: " << total << " kg\n";
    std::cout << "Promedio: " << promedio << " kg\n";
    std::cout << "Paquetes sobre el limite:" << sobreLimite << std::endl;
    std::cout << "Paquete mas pesado: " << *masPesado << " kg\n";

    delete[] pesos;


}

