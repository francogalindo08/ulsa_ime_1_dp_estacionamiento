#ifndef BUSCAR_LUGAR_H
#define BUSCAR_LUGAR_H

#include <iostream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;


// Busca un lugar dependiendo del tipo de vehiculo
int buscarLugar(string tipo, int lugaresSedan[8], int lugaresSUV[5], int lugaresCompacto[10]) {

    // Procesamiento
    if (tipo == "SEDAN") {

        for (int i = 0; i < 8; i++) {
            if (lugaresSedan[i] == 0) {
                lugaresSedan[i] = 1;
                return i + 1;
            }
        }

        return -1;
    }

    else if (tipo == "SUV") {

        for (int i = 0; i < 5; i++) {
            if (lugaresSUV[i] == 0) {
                lugaresSUV[i] = 1;
                return i + 1;
            }
        }

        return -1;
    }

    else if (tipo == "COMPACTO") {

        for (int i = 0; i < 10; i++) {
            if (lugaresCompacto[i] == 0) {
                lugaresCompacto[i] = 1;
                return i + 1;
            }
        }

        return -1;
    }

    // Tipo de vehiculo incorrecto
    return -2;
}

#endif
