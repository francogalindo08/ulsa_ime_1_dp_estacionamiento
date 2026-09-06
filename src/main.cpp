#include <iostream>
#include <string>
#include <vector>
#include <cctype>

#include "RegistrarEntrada.h"
#include "RegistrarSalida.h"
#include "BuscarLugar.h"

using namespace std;

int main() {
    vector<string> codigosActivos; // codigos de los vehiculos que estan dentro
    int consecutivo = 0;           // se usa para armar codigos unicos
    string entrada;                // lo que teclea el usuario en cada vuelta

    cout << "=== Simulador de Acceso a Estacionamiento (version inicial) ===" << endl;
    cout << "- Teclea el tipo de vehiculo (ej. SUV, SEDAN, COMPACTO) para registrar una entrada." << endl;
    cout << "- Teclea el codigo que recibiste al entrar para registrar una salida." << endl;
    cout << "- Teclea SALIR para terminar el programa." << endl << endl;

    while (true) {
        cout << "> ";
        getline(cin, entrada);
        

        // Se trabaja con una copia en mayusculas solo para comparar,
        // sin perder el texto original que el usuario tecleo.
        string entradaMayus = entrada;
        for (char &c : entradaMayus) {
            c = toupper(c);
        }

        if (entradaMayus == "SALIR") {
            break;
        }

        // Se revisa si lo tecleado ya es un codigo activo (entonces es
        // una salida) o si es un texto nuevo (entonces es una entrada).
        bool esCodigoActivo = false;
        for (const string &codigo : codigosActivos) {
            if (codigo == entradaMayus) {
                esCodigoActivo = true;
                break;
            }
        }

        if (esCodigoActivo) {
            registrarSalida(entrada, codigosActivos);
        } else {
            registrarEntrada(entrada, consecutivo, codigosActivos);
        }
    }

    cout << "Programa terminado." << endl;
    return 0;
}