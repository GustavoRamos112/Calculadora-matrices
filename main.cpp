#include <iostream>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <fstream>
#include <string>

using namespace std;
//? Importamos las librerias
#include "Declarar_matrices.hpp"
#include "Imprimir_matrices.hpp"
#include "Operaciones_basicas.hpp"
#include "Multiplicacion_matricial.hpp"
#include "Determinante.hpp"
#include "Inversa.hpp"

#include "Exportar_datos.hpp"

//? Declaramos todas las variables que usaremos despues
string operacion;
double constante;
int renglones_A, columnas_A, renglones_B, columnas_B;

#include "Leer_datos.hpp"
#include "Leer_matrices.hpp"

int main (void) {

    leer_datos("mat.dat");

    double **Matriz_A = Leer_Matriz_A("mat.dat");
    double **Matriz_B = Leer_Matriz_B("mat.dat");

    if(operacion == "suma") {
        Exportar_datos(Suma(Matriz_A, renglones_A, columnas_A, Matriz_B, renglones_B, columnas_B), renglones_A, columnas_A, operacion);
    }
    else if(operacion == "resta") {
        Exportar_datos(Resta(Matriz_A, renglones_A, columnas_A, Matriz_B, renglones_B, columnas_B), renglones_A, columnas_A, operacion);
    }
    else if(operacion == "multiplicacion") {
        Exportar_datos(Mult_matricial(Matriz_A, renglones_A, columnas_A, Matriz_B, renglones_B, columnas_B), renglones_A, columnas_B, operacion);
    }
    else if(operacion == "c_multiplicacion") {
        Exportar_datos(Mult_const(constante, Matriz_A, renglones_A, columnas_A), renglones_A, columnas_A, operacion);
    }
    else if(operacion == "inversa") {
        Exportar_datos(Inversa(Matriz_A, renglones_A, columnas_A), renglones_A, columnas_A, operacion);
    }
    return 0;
}
