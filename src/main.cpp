#include <iostream>
#include <string>
#include <vector>
#include <cctype>

#include "RegistrarEntrada.h"
#include "RegistrarSalida.h"
#include "BuscarLugar.h"

int main() {

    
    // LUGARES DEL ESTACIONAMIENTO
    // 0 = libre
    // 1 = ocupado
    

    int lugaresSedan[8] = {0};
    int lugaresSUV[5] = {0};
    int lugaresCompacto[10] = {0};

    
    // DATOS DE LOS VEHICULOS
    

    std::vector<std::string> codigosActivos;
    std::vector<std::string> tiposActivos;
    std::vector<int> lugaresActivos;

    int consecutivo = 0;

    std::string entrada;

   
    // ENTRADA
    

    std::cout << "========================================" << std::endl;
    std::cout << "     ESTACIONAMIENTO INTELIGENTE" << std::endl;
    std::cout << "========================================" << std::endl;

    std::cout << "Tipos disponibles:" << std::endl;
    std::cout << "SEDAN = 8 lugares" << std::endl;
    std::cout << "SUV = 5 lugares" << std::endl;
    std::cout << "COMPACTO = 10 lugares" << std::endl;
    std::cout << std::endl;

    std::cout << "Escribe SALIR para terminar." << std::endl;
    std::cout << std::endl;

    
    // PROGRAMA PRINCIPAL
    

    while (true) {

        std::cout << "> ";
        std::getline(std::cin, entrada);

        // Convertir a mayusculas
        std::string entradaMayus = entrada;

        for (char &c : entradaMayus) {
            c = static_cast<char>(std::toupper(static_cast<unsigned char>(c)));
        }

        
        // TERMINAR
        

        if (entradaMayus == "SALIR") {
            break;
        }

        
        // BUSCAR SI ES UN CODIGO
       

        bool esCodigoActivo = false;

        for (const std::string &codigo : codigosActivos) {

            if (codigo == entradaMayus) {
                esCodigoActivo = true;
                break;
            }
        }

        // =========================
        // SI ES UNA SALIDA
        // =========================

        if (esCodigoActivo) {

            registrarSalida(
                entradaMayus,
                codigosActivos,
                tiposActivos,
                lugaresActivos,
                lugaresSedan,
                lugaresSUV,
                lugaresCompacto
            );
        }

        // SI ES UNA ENTRADA
       

        else {

            int lugar = -2;

            if (entradaMayus == "SEDAN") {
                lugar = -1;
                for (int i = 0; i < 8; ++i) {
                    if (lugaresSedan[i] == 0) {
                        lugar = i+1;
                         lugaresSedan[i] = 1;   // ← MARCAR COMO OCUPADO
                        break;
                    }
                }
            }
            else if (entradaMayus == "SUV") {
                lugar = -1;
                for (int i = 0; i < 5; ++i) {
                    if (lugaresSUV[i] == 0) {
                        lugar = i+1;
                         lugaresSUV[i] = 1;   // ← MARCAR COMO OCUPADO
                        break;
                    }
                }
            }
            else if (entradaMayus == "COMPACTO") {
                lugar = -1;
                for (int i = 0; i < 10; ++i) {
                    if (lugaresCompacto[i] == 0) {
                        lugar = i+1;
                        lugaresCompacto[i] = 1;   // ← MARCAR COMO OCUPADO
                        break;
                    }
                }
            }

            // Tipo incorrecto
            if (lugar == -2) {

                std::cout << std::endl;
                std::cout << "ERROR: Tipo de vehiculo no valido." << std::endl;
                std::cout << "Solo puedes usar SEDAN, SUV o COMPACTO." << std::endl;
                std::cout << std::endl;
            }

            // No hay lugar
            else if (lugar == -1) {

                 std::cout << std::endl;
                 std::cout << "No hay lugares disponibles para "
                         << entradaMayus << "." << std::endl;
                 std::cout << std::endl;
            }

            // Si hay lugar
            else {

               registrarEntrada(
                    entradaMayus,
                    consecutivo,
                    lugar,
                    codigosActivos,
                    tiposActivos,
                    lugaresActivos
                );
            }
        }
    }

    std::cout << std::endl;
    std::cout << "Programa terminado." << std::endl;

    return 0;
}

