//Itz En este caso usaremos memoria dinamica ayudandonos
//Itz de los apuntadores dobles
double **declarar(int a, int b) {
    int i, j;
    double **matrix;

    matrix = (double **)malloc(a*sizeof(double *));
    for(i = 0; i < a;i++) {
        matrix[i] = (double*)malloc(b*sizeof(double));
        for(j = 0; j < b; j++) {
            matrix[i][j] = 0;
        }
    }
    return matrix;
}