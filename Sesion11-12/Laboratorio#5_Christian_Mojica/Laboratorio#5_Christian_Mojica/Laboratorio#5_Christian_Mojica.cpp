#include "HistorialDoble.h"
#include "RotacionCircular.h"
using namespace EIF201;

int main() {

    // ─────────────────────────────────────────
    // MÓDULO A — HistorialDoble
    // ─────────────────────────────────────────
    cout << "\n=== MODULO A: HistorialDoble ===" << endl;
    {
        HistorialDoble h;

        // Inserción
        h.insertarAlFinal("rock1");
        h.insertarAlFinal("pop7");
        h.insertarAlFinal("jazz3");
        h.insertarAlInicio("clas5");
        h.insertarEnPosicion("folk2", 2);
        h.insertarAntesDe("jazz3", "bosa1");
        h.insertarDespuesDe("pop7", "soul4");

        h.imprimirCronologico();
     

        h.imprimirInverso();
       

        // Búsqueda
        cout << "Posicion jazz3: " << h.obtenerPosicion("jazz3") << endl; // 6
        cout << "Cancion en pos 0: " << h.obtenerEnPosicion(0) << endl; // clas5
        cout << "jazz3 existe: " << (h.existeCancion("jazz3") ? "si" : "no") << endl; // si
        cout << "Pos desde final pop7: " << h.obtenerPosicionDesdeElFinal("pop7") << endl; // 3

        // Eliminación
        h.eliminarPrimera("bosa1");
        h.eliminarCabeza();
        h.eliminarCola();
        h.eliminarEnPosicion(1);
        h.eliminarUltima("pop7");

        h.imprimirCronologico();


        cout << "Cantidad: " << h.getCantidad() << endl; // 2

    }


    // ─────────────────────────────────────────
    // MÓDULO B — RotacionCircular
    // ─────────────────────────────────────────
    cout << "\n=== MODULO B: RotacionCircular ===" << endl;
    {
        RotacionCircular r;

    
        r.insertarAlFinal("Maria");
        r.insertarAlFinal("Carlos");
        r.insertarAlFinal("Adriana");
        r.insertarAlInicio("Diego");
        r.insertarDespuesDe("Carlos", "Elena");

        r.imprimirRotacion();
        

        // Búsqueda
        cout << "Carlos existe: " << (r.existeLocutor("Carlos") ? "si" : "no") << endl; // si
        cout << "Posicion Carlos: " << r.obtenerPosicion("Carlos") << endl; // 2
        cout << "Turno actual: " << r.turnoActual() << endl; // Diego

        // Rotación
        r.simularTurnos(7);
       

        // Eliminación
        r.eliminarLocutor("Carlos");
        r.eliminarTurnoActual();
        r.imprimirRotacion();
       

        cout << "Cantidad: " << r.getCantidad() << endl;

        r.eliminarLocutor("Adriana");
        while (!r.estaVacia()) r.eliminarTurnoActual();

        cout << "Vacia: " << (r.estaVacia() ? "si" : "no") << endl; // si
        cout << "Siguiente vacia: '" << r.siguiente() << "'" << endl; // ''
    }

    return 0;
}

//*RadioFM/
//├── NodoHistorial.h // struct NodoHistorial -> Nodo lista Doblemente enlazada
//├── HistorialDoble.h // declaración de la clase HistorialDoble
//├── HistorialDoble.cpp // implementación de todos los métodos
//├── NodoLocutor.h // struct NodoLocutor -> Nodo lista circular.
//├── RotacionCircular.h // declaración de la clase RotacionCircular
//├── RotacionCircular.cpp // implementación de todos los métodos
//└── main.cpp // escenarios de prueba únicamente