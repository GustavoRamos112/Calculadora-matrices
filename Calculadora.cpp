#include <iostream>
#include <cmath>

using namespace std;
//? Definimos el maximo de renglones y columnas para nuestras matrices
const int Max_renglones = 5;
const int Max_columnas = 5;
//? Definimos globalmente nuestras matrices resultado delas operaciones realizadas.
double Result_S[Max_renglones][Max_columnas];
double Result_R[Max_renglones][Max_columnas];
double Result_M_c[Max_renglones][Max_columnas];
double Result_M_m[Max_renglones][Max_columnas];
double Result_i[Max_renglones][Max_columnas];
double M_ij[Max_renglones][Max_columnas];
double cof[Max_renglones][Max_columnas];
double adj[Max_renglones][Max_columnas];

void imprimir_matriz(double M[][Max_columnas], int renglones, int columnas, string nombre);
//? Declaramos una subrutina para cada una de las operaciones, usamos como argumento [][Max_columnas]
//? pues c++ no nos permite usar [][] para una matriz, cosa contraria con arrays
void Suma(double A[][Max_columnas], int renglones_A, int columnas_A, double B[][Max_columnas], int renglones_B, int columnas_B);
void Resta(double A[][Max_columnas], int renglones_A, int columnas_A, double B[][Max_columnas], int renglones_B, int columnas_B);
void Mult_const(double constante, double A[][Max_columnas], int renglones_A, int columnas_A);
void Mult_matricial(double A[][Max_columnas], int renglones_A, int columnas_A, double B[][Max_columnas], int renglones_B, int columnas_B);
double Determinante(double A[][Max_columnas], int renglones_A, int columnas_A);
void menor(double A[][Max_columnas], int renglones_A, int columnas_A, int i, int j);
//? Estas ultimas nos sirven para hayar la matriz inversa
void cofac(double A[][Max_columnas], int renglones_A, int columnas_A);
void adjun(double A[][Max_columnas], int renglones_A, int columnas_A);
void inversa(double A[][Max_columnas], int renglones_A, int columnas_A);

int main(void) {
    //? Definimos las matrices con las que trabajaremos.
    int renglones_A = 3, columnas_A = 4;
    double A[renglones_A][Max_columnas] = {{2,4,-6,7},{1,3,2,1},{-4,3,-5,5}};

    int renglones_B = 3, columnas_B = 4;
    double B[renglones_B][Max_columnas] = {{0,1,6,-2},{2,3,4,3},{-2,1,4,4}};
    //? Imprimimos las matrices.
    imprimir_matriz(A, renglones_A, columnas_A, "Matriz A");
    imprimir_matriz(B, renglones_B, columnas_B, "Matriz B");
    //? Hacemos todas las operaciones binarias con estas matrices e
    //? imprimimos los resultados.
    Suma(A, renglones_A, columnas_A, B, renglones_B, columnas_B);
    imprimir_matriz(Result_S, renglones_A, columnas_A, "Matriz A+B");
    Resta(A, renglones_A, columnas_A, B, renglones_B, columnas_B);
    imprimir_matriz(Result_R, renglones_A, columnas_A, "Matriz A-B");
    Mult_const(2, A, renglones_A, columnas_A);
    imprimir_matriz(Result_M_c, renglones_A, columnas_A, "Matriz 2*A");
    //? Con otro caso distinto, probamos que la multiplicacion sigue funcionando
    int renglones_C = 2, columnas_C = 3;
    double C[renglones_C][Max_columnas] = {{2,0,-3},{4,1,5}};

    int renglones_D = 3, columnas_D = 4;
    double D[renglones_D][Max_columnas] = {{7,-1,4,7},{2,5,0,-4},{-3,1,2,3}};

    imprimir_matriz(C, renglones_C, columnas_C, "Matriz C");
    imprimir_matriz(D, renglones_D, columnas_D, "Matriz D");
    Mult_matricial(C, renglones_C, columnas_C, D, renglones_D, columnas_D);
    imprimir_matriz(Result_M_m, renglones_C, columnas_D, "Matriz C*D");
    //? Probamos que el determinante tambien sea correcto
    int renglones_E = 4, columnas_E = 4;
    double E[renglones_E][Max_columnas] = {{1,3,5,2},{0,-1,3,4},{2,1,9,6},{3,2,4,8}};
    imprimir_matriz(E, renglones_E, columnas_E, "Matriz E");
    cout << "det(E) = " << Determinante(E, renglones_E, columnas_E) << endl;
    //? Probamos que la inversa tambien funcione
    int renglones_G = 3, columnas_G = 3;
    double G[renglones_G][Max_columnas] = {{2,4,6},{4,5,6},{3,1,-2}};
    imprimir_matriz(G, renglones_G, columnas_G, "Matriz G");
    inversa(G, renglones_G, columnas_G);

    imprimir_matriz(G, renglones_G, columnas_G, "Matriz -G-");
    imprimir_matriz(Result_i, renglones_G, columnas_G, "Matriz G^-1");
    //? Rectificamos que al hacer A*A^-1 = I
    Mult_matricial(Result_i, renglones_G, columnas_G, G, renglones_G, columnas_G);
    imprimir_matriz(Result_M_m, renglones_G, columnas_G, "Matriz G^-1*G");
}
//? La subrutina para imprimir las matrices.
void imprimir_matriz(double M[][Max_columnas], int renglones, int columnas, string nombre) {
    //? Primero imprimrmos el nombre.
    cout << "\n" << nombre << "\n";
    for (int i = 0; i < renglones; i++) {
        for (int j = 0; j < columnas; j++) {
            //? Imprimimos la matriz renglon a renglon indicando dentro
            //? del parentesis la posicion dentro de la matriz
            cout << "(" << i+1 << ", " << j+1 << "): " << M[i][j] << "\t";
        }
        cout << "\n";
    }
}
//Itz La suma de matrices se hace termino a termino, para sumar dos matrices A y B
//Itz estas tienen que tener el mismo tamaño (mismos renglones y columnas).
void Suma(double A[][Max_columnas], int renglones_A, int columnas_A, double B[][Max_columnas], int renglones_B, int columnas_B) {
    //? Devuelve un mensaje de error sino se cumple al condicion establecida.
    if(renglones_A != renglones_B && columnas_A != columnas_B) {
        cout << "\nError las matrices tienen que tener el mismo numero de columnas y reglones\n";
        cout << "Codigo de error: 1";        
    }
    //? Hace la suma y guarda el resultado en la matriz global Result_S.
    for (int i = 0; i < renglones_A; i++) {
        for (int j = 0; j < columnas_A; j++) {
            Result_S[i][j] = A[i][j]+B[i][j];
        }
    }
}
//Itz La resta de matrices se hace termino a termino, para restar dos matrices A y B
//Itz estas tienen que tener el mismo tamaño (mismos renglones y columnas).
void Resta(double A[][Max_columnas], int renglones_A, int columnas_A, double B[][Max_columnas], int renglones_B, int columnas_B) {
    //? Devuelve un mensaje de error sino se cumple al condicion establecida.
    if(renglones_A != renglones_B && columnas_A != columnas_B) {
        cout << "\nError las matrices tienen que tener el mismo numero de columnas y reglones\n";
        cout << "Codigo de error: 1";        
    }
    //? Hace la resta y guarda el resultado en la matriz global Result_R.
    for (int i = 0; i < renglones_A; i++) {
        for (int j = 0; j < columnas_A; j++) {
            Result_R[i][j] = A[i][j]-B[i][j];
        }
    }
}
//Itz Al hacer a*A, donde a es una constante y A una matriz de nxm, a multiplica
//Itz a todos los elementos de dicha matriz a
void Mult_const(double constante, double A[][Max_columnas], int renglones_A, int columnas_A) {
    for (int i = 0; i < renglones_A; i++) {
        for (int j = 0; j < columnas_A; j++) {
            //? Se hace la multiplicacion termino a termino y se almacena en
            //? la matriz global Result_M_c
            Result_M_c[i][j] = constante*A[i][j];
        }
    }
}
//Itz El termino (i, j) de la matriz resultante de la multiplicacion de matrices A*B
//Itz esta definido como el producto punto entre el renglon i-esimo de A y la
//Itz columna j-esima de B, por esto mismo, para que A*B se pueda hacer, B tiene que
//Itz tener la misma cantidad de renglones como tiene A de columnas.
void Mult_matricial(double A[][Max_columnas], int renglones_A, int columnas_A, double B[][Max_columnas], int renglones_B, int columnas_B) {
    //? En caso de no cumplirse nuestra condicion, dara un codigo de error
    if (columnas_A != renglones_B) {
        cout << "\nError, para poder hacer A*B (multiplicación matricial de A y B) el numero de columnas de A debe de ser igual al numero de renglones de B\n";
        cout << "Cdigo de error: 2";
    }

    for(int i = 0; i < renglones_A; i++) {
        for(int j = 0; j < columnas_B; j++) {
            //? Por si acaso, se inicializa en cero cada termino de la matriz
            //? Result_M_m y ahi almacenamos el termino
            Result_M_m[i][j] = 0;
            for(int k = 0; k < columnas_A; k++){
                Result_M_m[i][j] += A[i][k]*B[k][j];
            }
        }
    }
}
//Itz A manera sencilla, el determinante es meramente el hipervolumen del cuerpo formado si tomamos cada vector
//Itz de dicha matriz como una arista de este, por esto mismo, la matriz tiene que ser cuadrada (nxn).
//Itz La manera mas sencilla de calcular lso determinantes, es triangular la matriz y multiplicar solo
//Itz los terminos en la diagonal.
double Determinante(double A[][Max_columnas], int renglones_A, int columnas_A) {
    if (renglones_A != columnas_A) {
        cout << "\nError, la matriz debe de ser cuadrada\n";
        cout << "Cdigo de error: 3";
        return 3;
    }

    double aux;
    double determinante = 1;
    for(int i = 0; i < renglones_A-1; i++){
        determinante *= A[i][i];
        //? Si durante la triangulacion algun termino de la diagonal es 0,
        //? el determinante sera cero.
        if(A[i][i] == 0) {
            return 0;
        }
        else {
            for(int j = i+1; j < renglones_A; j++){
                aux = -A[j][i];
                for(int k = i; k < renglones_A; k++){
                    A[j][k] += aux*A[i][k]/A[i][i];
                }
            }
        } 
    }
    determinante *= A[renglones_A-1][renglones_A-1];
    return determinante;
}
//Itz Para calcular la matriz menor (i, j) de una matriz A, simplemente eliminamos
//Itz el renglon i y la columna j.
void menor(double A[][Max_columnas], int renglones_A, int columnas_A, int i, int j) {
    for (int a = 0; a < renglones_A; a++) {
        for (int b = 0; b < columnas_A; b++) {
            if (a < i-1) {
                if (b < j-1) {
                    M_ij[a][b] = A[a][b];
                }
                else if (b > j-1) {
                    M_ij[a][b-1] = A[a][b];
                }
            }
            else if (a > i-1) {
                if (b < j-1) {
                    M_ij[a-1][b] = A[a][b];
                }
                else if (b > j-1) {
                    M_ij[a-1][b-1] = A[a][b];
                }
            }
        }
    }
}
//Itz El termino (i, j) de la matriz de cofactores es -1^(i+j)*det(matriz menor (i, j)).
void cofac(double A[][Max_columnas], int renglones_A, int columnas_A) {
    for (int i = 0; i < renglones_A; i++) {
        for (int j = 0; j < columnas_A; j++) {
            menor(A, renglones_A, columnas_A, i+1, j+1);
            cof[i][j] = pow(-1, i+j)*Determinante(M_ij, renglones_A-1, columnas_A-1);
        }
    }
}
//Itz En terminos sencillos, la matriz adjunta es la matriz de cofactores volteada.
//Itz Dicho de otra forma, el termino (i, j) de la adjunta de A (adj(A)) es
//Itz el termino (j, i) de la matriz de cofactores de A. 
void adjun(double A[][Max_columnas], int renglones_A, int columnas_A) {
    for (int i = 0; i < renglones_A; i++) {
        for (int j = 0; j < columnas_A; j++) {
            adj[i][j] = cof[j][i];
        }
    }
}
//Itz La matriz inversa A^-1 es aquella que al multiplicarla por A da como resultado
//Itz la matriz identidad, la manera en que lo calculamos aqui es:
//Itz A^-1=1/det(A)*adj(A), por esto mismo, det(A) tiene que ser distinto de cero.
void inversa(double A[][Max_columnas], int renglones_A, int columnas_A) {    
    if (renglones_A == columnas_A) {
        cout << "\nError, la matriz debe de ser cuadrada\n";
        cout << "Cdigo de error: 4";
    }

    double det = Determinante(A, renglones_A, columnas_A);

    if (det == 0) {
        cout << "La matriz no es invertible";
    }

    cofac(A, renglones_A, columnas_A);
    adjun(A, renglones_A, columnas_A);
    for (int i = 0; i < renglones_A; i++) {
        for (int j = 0; j < columnas_A; j++) {
            Result_i[i][j] = (1/det)*adj[i][j];
        }
    }
}
