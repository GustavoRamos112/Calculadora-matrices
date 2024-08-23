string extraer(string cadena, string subcadena) {
    string cad_sub = cadena.substr(subcadena.size(), cadena.size());
    return cad_sub;
}

vector<string> leer_archivo (string nombre) {
    ifstream archivo(nombre);
    vector <string> lineas;
    string linea;
    //? Se leen todas las lineas y se guardan en <<lineas>>.
    while (getline(archivo, linea)) {
        lineas.push_back(linea);
    }
    archivo.close();
    return lineas;
}

int leer_datos(string nombre) {
    vector<string> lineas = leer_archivo(nombre);

    vector<string> contenidos{"operacion = ", "constante = ", "renglones_A = ", "columnas_A = ", "{", "renglones_B = ", "columnas_B = "};
    //? Comprobamos que la operacion, la constante y la dimension de la matriz A
    //? hayan sido leidos correctamente.
    for (int i = 0; i < 4; i++) {
        if (lineas[i].find(contenidos[i]) == string::npos) {
            cout << "\nError, contenido leido incorrecto\n";
            cout << "Codigo de error " << i+1 << endl;
        }
    }
    //? Extraemos los datos que ya rectificamos, fueron leidos correctamente.
    operacion = extraer(lineas[0], contenidos[0]);
    constante = stod(extraer(lineas[1], contenidos[1]));
    renglones_A = stoi(extraer(lineas[2], contenidos[2]));
    columnas_A = stoi(extraer(lineas[3], contenidos[3]));
    //? Comprobamos que la matriz fue leida correctamente.
    for (int i = 4; i < 4+renglones_A; i++) {
        if (lineas[i].find(contenidos[4]) == string::npos) {
            cout << "\nError, matriz leida incorrecta\n";
            cout << "Codigo de error " << i+1 << endl;
        }
    }
    
    //? Comprobamos que la dimension de la matriz B fue leida correctamente
    if (lineas[4+renglones_A].find(contenidos[5]) == string::npos && lineas[5+renglones_A].find(contenidos[5]) == string::npos) {
        cout << "\nError, contenido leido incorrecto\n";
        cout << "Codigo de error " << 4+renglones_A << endl;
    }
    //? Extraemos la dimension de la matriz B
    renglones_B = stoi(extraer(lineas[3+renglones_A+1], contenidos[5]));
    columnas_B = stoi(extraer(lineas[3+renglones_A+2], contenidos[6]));    
    return 0;
}