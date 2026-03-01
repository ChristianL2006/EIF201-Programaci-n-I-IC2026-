#ifndef MATRIZ_H
#define MATRIZ_H

#include <iostream>

const int FILAS = 3;
const int COLS = 3;

void leerMatriz(int matriz[FILAS][COLS]);
void ImprimirMatriz(int matriz[FILAS][COLS]);
void SumaFilas(int matriz[FILAS][COLS]);
void SumaColumnas(int matriz[FILAS][COLS]);
void SumaDiagonal(int matriz[FILAS][COLS]);

#endif
