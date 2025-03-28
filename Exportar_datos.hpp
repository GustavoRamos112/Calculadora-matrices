void Exportar_datos(double **A, int renglones_A, int columnas_A, string operacion) {
    ofstream resultado;
    resultado.open("../Resultado.dat", fstream::out);
    resultado << "renglones = " << renglones_A << "\n"
              << "columnas = " << columnas_A << "\n"
              << "operacion = " << operacion << "\n";
    
    for (int i = 0; i < renglones_A; i++) {
        resultado << "{";
        for (int j = 0; j < columnas_A; j++) {
            resultado << A[i][j];
            (j == columnas_A-1 ) ? resultado << "": resultado << ",";
        }
        resultado << "}";
        (i == renglones_A-1 ) ? resultado << "": resultado << "\n";
    }

    resultado.close();
}
