
#include <iostream>
#include "Matriz.h"
#include <iomanip>



void leerMatriz(int matriz[FILAS][COLS])
{
    std::cout << "Ingrese los valores de la matriz 3x3:\n";

    for (int i = 0; i < FILAS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            std::cout << "Elemento [" << i << "][" << j << "]: ";
            std::cin >> matriz[i][j];
        }
    }
}
void ImprimirMatriz(int matriz[FILAS][COLS]) {
    std::cout << "La Matriz es:\n\n";
    
    for (int i = 0; i < FILAS; i++) {

        for (int j = 0; j < COLS; j++) {
           
           std:: cout << std:: setw(5) << matriz[i][j];
        }
        std::cout << "\n\n";
    }

}
void SumaFilas(int matriz[FILAS][COLS]){
   std:: cout << "Suma de filas:\n";

    for (int i = 0; i < FILAS; i++)
    {
        int suma = 0;
        for (int j = 0; j < COLS; j++)
        {
            suma += matriz[i][j];
        }
       std:: cout << "Fila " << i + 1 << ": " << suma << std::endl;
    }
}
void SumaColumnas(int matriz[FILAS][COLS]){
    std::cout << "Suma de columnas:\n";

    for (int j = 0; j < COLS; j++)
    {
        int suma = 0;
        for (int i = 0; i < FILAS; i++)
        {
            suma += matriz[i][j];
        }
       std:: cout << "Columna " << j + 1 << ": " << suma << std:: endl;
    }
}


void SumaDiagonal(int matriz[FILAS][COLS]){
    int suma = 0;

    for (int i = 0; i < FILAS; i++)
    {
        suma += matriz[i][i];
    }

   std:: cout << "\nSuma de la diagonal principal: " << suma << std::endl;
}






int main()
{
    int matriz[FILAS][COLS];

    leerMatriz(matriz);
    ImprimirMatriz(matriz);
    SumaFilas(matriz);
    SumaColumnas(matriz);
    SumaDiagonal(matriz);

    return 0;
}

