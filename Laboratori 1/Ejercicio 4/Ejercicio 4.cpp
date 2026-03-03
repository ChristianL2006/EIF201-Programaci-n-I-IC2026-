

#include <iostream>
#include "Nombre.h"
#include <cctype>
using namespace std; 

string  obtenerPrimerNombre(const string& nombreCompleto)
{
    int pos = nombreCompleto.find(' '); 
    return nombreCompleto.substr(0, pos);
}

// Obtener primer apellido
string obtenerPrimerApellido(const string& nombreCompleto)
{
    int primeraPos = nombreCompleto.find(' ');
    int segundaPos = nombreCompleto.find(' ', primeraPos + 1);

    return nombreCompleto.substr(primeraPos + 1,
        segundaPos - primeraPos - 1);
}

// Contar vocales
int contarVocales(const string& nombreCompleto)
{
    int contador = 0;

    for (char c : nombreCompleto)
    {
        char letra = tolower(c);

        if (letra == 'a' || letra == 'e' ||
            letra == 'i' || letra == 'o' ||
            letra == 'u')
        {
            contador++;
        }
    }

    return contador;
}

// Convertir a mayúsculas
string convertirMayusculas(string nombreCompleto)
{
    for (char& c : nombreCompleto)
    {
        c = toupper(c);
    }

    return nombreCompleto;
}

// Longitud del nombre
int longitudNombre(const string& nombreCompleto)
{
    return nombreCompleto.length();
}

int main()
{
    string nombreCompleto;

    cout << "Ingrese su nombre completo (PrimerNombre PrimerApellido SegundoApellido): ";
    getline(cin, nombreCompleto); /*Eso lee con espacios el nombre*/

    cout << "\nPrimer nombre: "
        << obtenerPrimerNombre(nombreCompleto) << endl;

    cout << "Primer apellido: "
        << obtenerPrimerApellido(nombreCompleto) << endl;

    cout << "Cantidad de vocales: "
        << contarVocales(nombreCompleto) << endl;

    cout << "Nombre en mayusculas: "
        << convertirMayusculas(nombreCompleto) << endl;

    cout << "Longitud total: "
        << longitudNombre(nombreCompleto) << endl;

    return 0;
}