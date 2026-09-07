#ifndef REGISTRAR_ENTRADA_H
#define REGISTRAR_ENTRADA_H

#include <iostream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;


inline string registrarEntrada(string textoIngresado, int &consecutivo, vector<string> &codigosActivos) {
   
    for (char &c : textoIngresado) {
        c = toupper(c);
    }

    return textoIngresado;
}

// Registra la entrada del vehiculo
string registrarEntrada(
    string tipo,
    int &consecutivo,
    int lugar,
    vector<string> &codigosActivos,
    vector<string> &tiposActivos,
    vector<int> &lugaresActivos
) {
    // Generar codigo
    consecutivo++;

    string codigo = tipo + to_string(consecutivo);

    // Guardar los datos del vehiculo
    codigosActivos.push_back(codigo);
    tiposActivos.push_back(tipo);
    lugaresActivos.push_back(lugar);

    // Salida
    cout << endl;
    cout << "Entrada registrada." << endl;
    cout << "Tipo de vehiculo: " << tipo << endl;
    cout << "Lugar asignado: " << lugar << endl;
    cout << "Codigo de acceso: " << codigo << endl;
    cout << endl;

    return codigo;
}

#endif