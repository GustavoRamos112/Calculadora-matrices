double **Mult_matricial(double **A, int renglones_A, int columnas_A, double **B, int renglones_B, int columnas_B) {
    double **M_m = declarar(renglones_A, columnas_B);
    if (columnas_A == renglones_B) {
        for(int i = 0; i < renglones_A; i++) {
            for(int j = 0; j < columnas_B; j++) {
                for(int k = 0; k < columnas_A; k++){
                    M_m[i][j] += A[i][k]*B[k][j];
                }
            }
        }
        return M_m;
    }
    else {
        cout << "\nError, para poder hacer A*B (multiplicación matricial de A y B) el numero de columnas de A debe de ser igual al numero de renglones de B\n";
        return M_m;
    }
}
