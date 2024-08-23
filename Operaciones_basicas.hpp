double **Suma(double **A, int renglones_A, int columnas_A, double **B, int renglones_B, int columnas_B) {    
    double **sum = declarar(renglones_A, columnas_A);
    if(renglones_A == renglones_B && columnas_A == columnas_B) {
        for (int i = 0; i < renglones_A; i++) {
            for (int j = 0; j < columnas_A; j++) {
                sum[i][j] = A[i][j]+B[i][j];
            }
        }
        return sum;
    }
    
    else {
        cout << "\nError las matrices tienen que tener el mismo numero de columnas y reglones\n";
        return sum;
    }
}

double **Resta(double **A, int renglones_A, int columnas_A, double **B, int renglones_B, int columnas_B) {    
    double **res = declarar(renglones_A, columnas_A);
    if(renglones_A == renglones_B && columnas_A == columnas_B) {
        for (int i = 0; i < renglones_A; i++) {
            for (int j = 0; j < columnas_A; j++) {
                res[i][j] = A[i][j]-B[i][j];
            }
        }
        return res;
    }
    
    else {
        cout << "\nError las matrices tienen que tener el mismo numero de columnas y reglones\n";
        return res;
    }
}

double **Mult_const(double constante, double **A, int renglones_A, int columnas_A) {
    double **M_c = declarar(renglones_A, columnas_A); 
    for (int i = 0; i < renglones_A; i++) {
        for (int j = 0; j < columnas_A; j++) {
            M_c[i][j] = constante*A[i][j];
        }
    }
    return M_c;
}
