//Resulaelva los siguientes ejercicios en C++ utilizando las librerias filesystem.h y windows.h
// para este mismo codigo integrarle una fucion que sgrgue texto alos archivos creados, los archivos deben de tener la misma cantidad de lineas segun su numero de archivo por ejemplo: file 1 debe de tener una linea de texto en su contenido, file2 debe de tener dos lineas y asi susecibamente
//crear una funcion que pregunte al usuario cuantos archivos desea crear, si la cantidad de archivos a crear es par los archivo debe de almacenarlos en el directorio de ""escritorio y subcarpeta "par" , de lo contrariosi el numero proporciondo por el usuario es imparar los archivos debe de almacenarlos en el mismo directorio en una carpeta llamada "impar", los archivos deben de tener el nombre con el siguiente formato file 1, file2...file10 y asi susesibamente
#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>
#include "windows.h"

using namespace std;
void crearArchivos(int cantidad);
void agregarTexto();

int main() {
    int opc;
    cout << "Bienvenido al Programa de Manejo de Archivos" << endl;
    do {
        cout << "------------------------------------------------------------------------" << endl;
        cout << "Elija una opcion a realizar" << endl;
        cout << "[1] Crear Archivos" << endl;
        cout << "[0] Salir" << endl;
        cin >> opc;
        switch (opc) {
            case 1:
                cout << "Opcion seleccionada -> Crear Archivos" << endl;
                int cantidad;
                cout << "Ingrese la cantidad de archivos que desea crear" << endl;
                cin >> cantidad;
                crearArchivos(cantidad);
                break;
            case 2:
                cout << "Opcion seleccionada -> Renombrar archivos" << endl;
                //renombrar();
                break;
            case 0:
                cout << "Gracias por Utilizar el Programa" << endl;
                break;
            default:
                cout << "Opcion incorrecta, vuelva a intentarlo" << endl;
                break;
        }
    } while (opc != 0);
    return 0;
}

void crearArchivos(int cantidad){
    string nombreArchivo = "file";
    if (cantidad % 2 == 0){
        cout << "Cantidad de Archivos par" << endl;
        for (int i = 0; i < cantidad; ++i) {
            ofstream file;
            file.open("C:/Users/USUARIO/Documents/par/" + nombreArchivo + to_string(i + 1) + ".txt");
            agregarTexto();
            for (int j = 0; j < i+1; ++j) {
                file << "linea de texto" << endl;
            }
            file.close();
        }
        cout << " Archivos creados con Exito" << endl;

    }else{
        cout << "Cantidad de Archivos impar" << endl;
        for (int i = 0; i < cantidad; ++i) {
            ofstream file;
            file.open("C:/Users/USUARIO/Desktop/impar/" + nombreArchivo + to_string(i + 1) + ".txt");
            agregarTexto();
            for (int j = 0; j < i+1; ++j) {
                file << "linea de texto" << endl;
            }
            file.close();
        }
        cout << " Archivos creados con Exito" << endl;

    }
}

void agregarTexto(){
    cout << "Agregando texto..." << endl;
}

int contarArchivosDeDirectorio(){
    WIN32_FIND_DATA findFileData;
    HANDLE          hFind;
    int cantidadDeArchivos=0;
    hFind = FindFirstFile("C:/Users/USUARIO/Documents/par/*", &findFileData);

    if (hFind == INVALID_HANDLE_VALUE){
        cout << "Ruta incorrecta" << endl;
    }else{
        while (FindNextFile(hFind, &findFileData)!=0){
            cantidadDeArchivos=cantidadDeArchivos+1;
        }
    }
    return cantidadDeArchivos-1;
}