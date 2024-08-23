void imprimir_matriz(double **M, int renglones, int columnas, string nombre) {
    cout << "\n" << nombre << "\n";
    for (int i = 0; i < renglones; i++) {
        for (int j = 0; j < columnas; j++) {
            cout << "(" << i+1 << ", " << j+1 << "): " << M[i][j] << "\t";
        }
        cout << "\n";
    }
}