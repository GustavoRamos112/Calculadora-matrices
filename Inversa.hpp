double **menor(double **A, int renglones_A, int columnas_A, int i, int j) {
    double **M_ij = declarar(renglones_A-1, columnas_A-1);
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
    return M_ij;
}

double **cofac(double **A, int renglones_A, int columnas_A) {
    double **M_ij;
    double **cof = declarar(renglones_A, columnas_A);
    for (int i = 0; i < renglones_A; i++) {
        for (int j = 0; j < columnas_A; j++) {
            M_ij = menor(A, renglones_A, columnas_A, i+1, j+1);
            cof[i][j] = pow(-1, i+j)*Determinante(M_ij, renglones_A-1, columnas_A-1);
        }
    }
    return cof;
}

double **adjun(double **A, int renglones_A, int columnas_A) {
    double **cof = cofac(A, renglones_A, columnas_A);
    double **adj = declarar(renglones_A, columnas_A);
    for (int i = 0; i < renglones_A; i++) {
        for (int j = 0; j < columnas_A; j++) {
            adj[i][j] = cof[j][i];
        }
    }
    return adj;
}

double **Inversa(double **A, int renglones_A, int columnas_A) {
    double **inv = declarar(renglones_A, columnas_A);
    if (renglones_A == columnas_A) {
        double det = Determinante(A, renglones_A, columnas_A);
        if (det != 0) {
            double **adj = adjun(A, renglones_A, columnas_A);
            for (int i = 0; i < renglones_A; i++) {
                for (int j = 0; j < columnas_A; j++) {
                    inv[i][j] = (1/det)*adj[i][j];
                }
            }
            return inv;
        }

        else {
            cout << "\nLa matriz dada no es invertible pues su determinante es igual a cero\n";
            return inv;
        }
    }

    else {
        cout << "Error, la matriz tiene que ser cuadrada";
        return inv;
    }
}
