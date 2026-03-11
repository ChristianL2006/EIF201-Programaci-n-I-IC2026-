#ifndef PAQUETES_H
#define PAQUETES_H

// Crea dinámicamente el arreglo de pesos y solicita la cantidad de paquetes
double* crearRegistro(int& cantidad);

// Lee el peso en kg de cada paquete (debe ser mayor a 0)
void ingresarPesos(double* pesos, int cantidad);

// Calcula y retorna la suma de todos los pesos del arreglo
double calcularPesoTotal(const double* pesos, int cantidad);

// Cuenta y retorna cuántos paquetes tienen un peso mayor al límite dado
int contarSobreLimite(const double* pesos, int cantidad, double limite);

// Retorna un puntero al elemento con el mayor peso del arreglo
// En caso de empate retorna el primero encontrado
const double* buscarMasPesado(const double* pesos, int cantidad);

#endif
