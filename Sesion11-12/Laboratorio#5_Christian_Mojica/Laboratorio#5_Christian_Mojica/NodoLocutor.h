#pragma once
#ifndef NODO_LOCUTOR_H
#define NODO_LOCUTOR_H

#include <iostream>
#include <string>

using namespace std;

namespace EIF201 {

	struct NodoLocutor {
		string nombre;
		NodoLocutor* siguiente;
		int turnosAsignados;

		NodoLocutor(const string& n) : nombre(n), siguiente(nullptr), turnosAsignados(0) {
			cout << "[Nodo Creado: " << n << "]" << endl;
		}
		~NodoLocutor() {
			cout << "[Nodo Eliminado: " << nombre << "]" << endl;
		}

	};




}

#endif