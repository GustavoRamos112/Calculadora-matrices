double **Leer_Matriz_A (string nombre){
    double **M = declarar(renglones_A, columnas_A);

    vector<string> lineas = leer_archivo(nombre);
    string piv_1, piv_2;
    //? x para los renglones y y para las columnas
    int x = 0, y = 0;
    //!cout << endl;
    for (int j = 4; j < 4+renglones_A; j++) {
        y = 0;
        for (int k = 1; k < lineas[j].size(); k++) {
            piv_1 = lineas[j][k];
            if (piv_1 == ",") {
                //!cout << "(" << x << ", " << y << ") = " << piv_2 << " ";
                M[x][y] = stod(piv_2);
                piv_2 = "";
                y++;
            }
            else if (piv_1 == "}") {
                //!cout << "(" << x << ", " << y << ") = " << piv_2 << endl;
                M[x][y] = stod(piv_2);
                piv_2 = "";
                y++;
            }
            else {
                piv_2 += lineas[j][k];
            }
        }
        x++;
    }
    return M;
}

double **Leer_Matriz_B (string nombre){
    if (columnas_B == 0 && renglones_B == 0){
        double **M = declarar(1, 1);

        return M;
    }

    double **M = declarar(renglones_B, columnas_B);

    vector<string> lineas = leer_archivo(nombre);
    string piv_1, piv_2;
    //? x para los renglones y y para las columnas
    int x = 0, y = 0;
    //!cout << endl;
    for (int j = 6+renglones_A; j < 6+renglones_A+renglones_B; j++) {
        y = 0;
        for (int k = 1; k < lineas[j].size(); k++) {
            piv_1 = lineas[j][k];
            if (piv_1 == ",") {
                //!cout << "(" << x << ", " << y << ") = " << piv_2 << " ";
                M[x][y] = stod(piv_2);
                piv_2 = "";
                y++;
            }
            else if (piv_1 == "}") {
                //!cout << "(" << x << ", " << y << ") = " << piv_2 << endl;
                M[x][y] = stod(piv_2);
                piv_2 = "";
            }
            else {
                piv_2 += lineas[j][k];
            }
        }
        x++;
    }
    return M;
}