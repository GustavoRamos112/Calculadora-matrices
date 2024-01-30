#include <iostream>
#include <cmath>

using namespace std;
const int Max_renglones = 5;
const int Max_columnas = 5;

double Result_S[Max_renglones][Max_columnas];
double Result_R[Max_renglones][Max_columnas];
double Result_M_c[Max_renglones][Max_columnas];
double Result_M_m[Max_renglones][Max_columnas];
double Result_i[Max_renglones][Max_columnas];
double M_ij[Max_renglones][Max_columnas];
double cof[Max_renglones][Max_columnas];
double adj[Max_renglones][Max_columnas];

void imprimir_matriz(double M[][Max_columnas], int renglones, int columnas, string nombre);
void Suma(double A[][Max_columnas], int renglones_A, int columnas_A, double B[][Max_columnas], int renglones_B, int columnas_B);
void Resta(double A[][Max_columnas], int renglones_A, int columnas_A, double B[][Max_columnas], int renglones_B, int columnas_B);
void Mult_const(double constante, double A[][Max_columnas], int renglones_A, int columnas_A);
void Mult_matricial(double A[][Max_columnas], int renglones_A, int columnas_A, double B[][Max_columnas], int renglones_B, int columnas_B);
double Determinante(double A[][Max_columnas], int renglones_A, int columnas_A);
void menor(double A[][Max_columnas], int renglones_A, int columnas_A, int i, int j);
void cofac(double A[][Max_columnas], int renglones_A, int columnas_A);
void adjun(double A[][Max_columnas], int renglones_A, int columnas_A);
void inversa(double A[][Max_columnas], int renglones_A, int columnas_A);

int main(void) {
    
    int renglones_A = 3, columnas_A = 4;
    double A[renglones_A][Max_columnas] = {{2,4,-6,7},{1,3,2,1},{-4,3,-5,5}};

    int renglones_B = 3, columnas_B = 4;
    double B[renglones_B][Max_columnas] = {{0,1,6,-2},{2,3,4,3},{-2,1,4,4}};

    imprimir_matriz(A, renglones_A, columnas_A, "Matriz A");
    imprimir_matriz(B, renglones_B, columnas_B, "Matriz B");
    Suma(A, renglones_A, columnas_A, B, renglones_B, columnas_B);
    imprimir_matriz(Result_S, renglones_A, columnas_A, "Matriz A+B");
    Resta(A, renglones_A, columnas_A, B, renglones_B, columnas_B);
    imprimir_matriz(Result_R, renglones_A, columnas_A, "Matriz A-B");
    Mult_const(2, A, renglones_A, columnas_A);
    imprimir_matriz(Result_M_c, renglones_A, columnas_A, "Matriz 2*A");

    int renglones_C = 2, columnas_C = 3;
    double C[renglones_C][Max_columnas] = {{2,0,-3},{4,1,5}};

    int renglones_D = 3, columnas_D = 4;
    double D[renglones_D][Max_columnas] = {{7,-1,4,7},{2,5,0,-4},{-3,1,2,3}};

    imprimir_matriz(C, renglones_C, columnas_C, "Matriz C");
    imprimir_matriz(D, renglones_D, columnas_D, "Matriz D");
    Mult_matricial(C, renglones_C, columnas_C, D, renglones_D, columnas_D);
    imprimir_matriz(Result_M_m, renglones_C, columnas_D, "Matriz C*D");

    int renglones_E = 4, columnas_E = 4;
    double E[renglones_E][Max_columnas] = {{1,3,5,2},{0,-1,3,4},{2,1,9,6},{3,2,4,8}};
    imprimir_matriz(E, renglones_E, columnas_E, "Matriz E");
    cout << "det(E) = " << Determinante(E, renglones_E, columnas_E) << endl;

    int renglones_G = 3, columnas_G = 3;
    double G[renglones_G][Max_columnas] = {{2,4,6},{4,5,6},{3,1,-2}};
    imprimir_matriz(G, renglones_G, columnas_G, "Matriz G");
    inversa(G, renglones_G, columnas_G);
    //! cuando termina la funcion inversa de sacar al inversa, los valores de G cambian
    imprimir_matriz(G, renglones_G, columnas_G, "Matriz -G-");
    imprimir_matriz(Result_i, renglones_G, columnas_G, "Matriz G^-1");
    
    Mult_matricial(Result_i, renglones_G, columnas_G, G, renglones_G, columnas_G);
    imprimir_matriz(Result_M_m, renglones_G, columnas_G, "Matriz G^-1*G");
}

void imprimir_matriz(double M[][Max_columnas], int renglones, int columnas, string nombre) {
    cout << "\n" << nombre << "\n";
    for (int i = 0; i < renglones; i++) {
        for (int j = 0; j < columnas; j++) {
            cout << "(" << i+1 << ", " << j+1 << "): " << M[i][j] << "\t";
        }
        cout << "\n";
    }
}

void Suma(double A[][Max_columnas], int renglones_A, int columnas_A, double B[][Max_columnas], int renglones_B, int columnas_B) {
    if(renglones_A == renglones_B && columnas_A == columnas_B) {
        for (int i = 0; i < renglones_A; i++) {
            for (int j = 0; j < columnas_A; j++) {
                Result_S[i][j] = A[i][j]+B[i][j];
            }
        }
    }
    
    else {
        cout << "\nError las matrices tienen que tener el mismo numero de columnas y reglones\n";
    }
}

void Resta(double A[][Max_columnas], int renglones_A, int columnas_A, double B[][Max_columnas], int renglones_B, int columnas_B) {
    if(renglones_A == renglones_B && columnas_A == columnas_B) {
        for (int i = 0; i < renglones_A; i++) {
            for (int j = 0; j < columnas_A; j++) {
                Result_R[i][j] = A[i][j]-B[i][j];
            }
        }
    }
    
    else {
        cout << "\nError las matrices tienen que tener el mismo numero de columnas y reglones\n";
    }
}

void Mult_const(double constante, double A[][Max_columnas], int renglones_A, int columnas_A) {
    for (int i = 0; i < renglones_A; i++) {
        for (int j = 0; j < columnas_A; j++) {
            Result_M_c[i][j] = constante*A[i][j];
        }
    }
}

void Mult_matricial(double A[][Max_columnas], int renglones_A, int columnas_A, double B[][Max_columnas], int renglones_B, int columnas_B) {
    //! para depurar
    imprimir_matriz(A, renglones_A, columnas_A, "Matriz para depurar A");
    imprimir_matriz(B, renglones_B, columnas_B, "Matriz para depurar B");
    if (columnas_A == renglones_B) {
        for(int i = 0; i < renglones_A; i++) {
            for(int j = 0; j < columnas_B; j++) {
                Result_M_m[i][j] = 0;
                for(int k = 0; k < columnas_A; k++){
                    Result_M_m[i][j] += A[i][k]*B[k][j];
                }
            }
        }
    }
    else {
        cout << "\nError, para poder hacer A*B (multiplicación matricial de A y B) el numero de columnas de A debe de ser igual al numero de renglones de B\n";
    }
}

double Determinante(double A[][Max_columnas], int renglones_A, int columnas_A) {
    if (renglones_A == columnas_A) {
        double aux;
        double determinante = 1;
        for(int i = 0; i < renglones_A-1; i++){
            determinante *= A[i][i];
            if(A[i][i] == 0)
                return 0;
            else{
                
                for(int j = i+1; j < renglones_A; j++){
                    aux=-A[j][i];
                    for(int k = i; k < renglones_A; k++){
                        A[j][k] += aux*A[i][k]/A[i][i];
                    }
                
                }
            }
        
        }
        determinante *= A[renglones_A-1][renglones_A-1];
        return determinante;
    }
    else {
        cout << "\nError, la matriz debe de ser cuadrada\n";
        return 0;
    }
}

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

void cofac(double A[][Max_columnas], int renglones_A, int columnas_A) {
    for (int i = 0; i < renglones_A; i++) {
        for (int j = 0; j < columnas_A; j++) {
            menor(A, renglones_A, columnas_A, i+1, j+1);
            cof[i][j] = pow(-1, i+j)*Determinante(M_ij, renglones_A-1, columnas_A-1);
        }
    }
}

void adjun(double A[][Max_columnas], int renglones_A, int columnas_A) {
    for (int i = 0; i < renglones_A; i++) {
        for (int j = 0; j < columnas_A; j++) {
            adj[i][j] = cof[j][i];
        }
    }
}

void inversa(double A[][Max_columnas], int renglones_A, int columnas_A) {
    double M[renglones_A][Max_columnas];
    for (int i = 0; i < renglones_A; i++) {
        for (int j = 0; j < columnas_A; j++) {
            M[i][j] = A[i][j];
        }
    }
    if (renglones_A == columnas_A) {
        double det = Determinante(A, renglones_A, columnas_A);
        if (det != 0) {
            cofac(M, renglones_A, columnas_A);
            adjun(M, renglones_A, columnas_A);
            for (int i = 0; i < renglones_A; i++) {
                for (int j = 0; j < columnas_A; j++) {
                    Result_i[i][j] = (1/det)*adj[i][j];
                }
            }
        }

        else {
            cout << "\nLa matriz dada no es invertible pues su determinante es igual a cero\n";
        }
    }

    else {
        cout << "Error, la matriz tiene que ser cuadrada";
    }
}
