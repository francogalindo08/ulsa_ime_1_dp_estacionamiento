ifndef REGISTRAR_SALIDA_H
#define REGISTRAR_SALIDA_H

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cctype>

using namespace std;

// registrarSalida
// -----------------
// Recibe el codigo que el usuario recibio al entrar y lo busca dentro
// de la lista de codigos activos. Si lo encuentra, lo elimina de la
// lista (el vehiculo ya salio) y confirma la salida. Si no lo
// encuentra, avisa que el codigo no es valido, sin modificar nada.
inline bool registrarSalida(string codigo, vector<string> &codigosActivos) {
    for (char &c : codigo) {
        c = toupper(c);
    }

    return find(codigosActivos.begin(), codigosActivos.end(), codigo) != codigosActivos.end();
}

  bool registrarSalida(
    string codigo,
    vector<string> &codigosActivos,
    vector<string> &tiposActivos,
    vector<int> &lugaresActivos,
    int lugaresSedan[],
    int lugaresSUV[],
    int lugaresCompacto[]
 // Buscar el codigo
    for (int i = 0; i < codigosActivos.size(); i++) {

        if (codigosActivos[i] == codigo) {

            string tipo = tiposActivos[i];
            int lugar = lugaresActivos[i];

            // Liberar el lugar
            if (tipo == "SEDAN") {
                lugaresSedan[lugar - 1] = 0;
            }

            else if (tipo == "SUV") {
                lugaresSUV[lugar - 1] = 0;
            }

            else if (tipo == "COMPACTO") {
                lugaresCompacto[lugar - 1] = 0;
            }

            // Eliminar el vehiculo
            codigosActivos.erase(codigosActivos.begin() + i);
            tiposActivos.erase(tiposActivos.begin() + i);
            lugaresActivos.erase(lugaresActivos.begin() + i);

            cout << endl;
            cout << "Salida registrada." << endl;
            cout << "Codigo: " << codigo << endl;
            cout << "Lugar " << lugar << " liberado." << endl;
            cout << endl;

            return true;
        }
    }

    cout << endl;
    cout << "Codigo no encontrado." << endl;
    cout << endl;

    return false;
}

#endif