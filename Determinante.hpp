double Determinante(double **A, int renglones_A, int columnas_A) {
    double determinante = 0, aux = 0;

    int c;

    if(renglones_A == 2 && columnas_A == 2) {
        determinante = A[0][0]*A[1][1] - A[1][0]*A[0][1];
        return determinante;
    }

    else {
        for(int j = 0; j < renglones_A; j++){

            double **menor = declarar(renglones_A-1, renglones_A-1);

            for(int k = 1; k < renglones_A; k++){
                c = 0;
                for(int l = 0; l < renglones_A; l++){
                    if(l!=j){
                        menor[k-1][c] = A[k][l];
                        c++;
                    }
                }
            }
            aux = pow(-1, 2+j)*A[0][j]*Determinante(menor, renglones_A-1, renglones_A-1);
            determinante += aux;
        }
    }
    return determinante;
}