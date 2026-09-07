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