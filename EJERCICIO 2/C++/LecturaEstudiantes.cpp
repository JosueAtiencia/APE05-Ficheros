#include <iostream>
#include <fstream>    // Para manejo de archivos
#include <sstream>    // Para parsear cada línea
#include <string>
#include <vector>     // Para usar arreglo dinámico (vector)
using namespace std;

// Clase que representa a un Estudiante
class Estudiante {
private:
    string cedula;
    string nombre;
    string carrera;
    double promedio;

public:
    // Constructor: inicializa todos los atributos
    Estudiante(string cedula, string nombre, string carrera, double promedio) {
        this->cedula   = cedula;
        this->nombre   = nombre;
        this->carrera  = carrera;
        this->promedio = promedio;
    }

    // Método que imprime los datos del estudiante en consola
    void mostrar() {
        cout << "Cedula:   " << cedula   << endl;
        cout << "Nombre:   " << nombre   << endl;
        cout << "Carrera:  " << carrera  << endl;
        cout << "Promedio: " << promedio << endl;
        cout << "----------------------------------" << endl;
    }

    // Getter del promedio
    double getPromedio() {
        return promedio;
    }
};

// Función que lee el archivo y retorna un vector de objetos Estudiante
vector<Estudiante> leerArchivo(string ruta) {
    vector<Estudiante> lista;
    ifstream archivo(ruta);

    if (!archivo.is_open()) {
        cout << "Error: no se pudo abrir el archivo." << endl;
        return lista;
    }

    string linea;
    // Ciclo: leer línea por línea hasta el final del archivo
    while (getline(archivo, linea)) {
        stringstream ss(linea);
        string cedula, nombre, carrera, promedioStr;

        // Separar los campos usando el delimitador '|'
        getline(ss, cedula,      '|');
        getline(ss, nombre,      '|');
        getline(ss, carrera,     '|');
        getline(ss, promedioStr, '|');

        // Convertir el promedio de string a double
        double promedio = stod(promedioStr);

        // Crear objeto Estudiante y agregarlo al vector
        lista.push_back(Estudiante(cedula, nombre, carrera, promedio));
    }
    archivo.close();
    return lista;
}

// Función que muestra todos los registros
void mostrarRegistros(vector<Estudiante>& lista) {
    cout << "===== LISTA DE ESTUDIANTES =====" << endl;
    // Ciclo: recorrer cada estudiante e invocar su método mostrar()
    for (int i = 0; i < lista.size(); i++) {
        lista[i].mostrar();
    }
}

// Función que cuenta y muestra el total de estudiantes
int contarEstudiantes(vector<Estudiante>& lista) {
    int total = lista.size();
    cout << "Total de estudiantes: " << total << endl;
    return total;
}

// Función que calcula y muestra el promedio general
void promedioGeneral(vector<Estudiante>& lista) {
    double sumaPromedios = 0;
    // Ciclo: acumular la suma de todos los promedios individuales
    for (int i = 0; i < lista.size(); i++) {
        sumaPromedios += lista[i].getPromedio();
    }
    double promGeneral = sumaPromedios / lista.size();
    cout << "Promedio general: " << promGeneral << endl;
}

// Función principal
int main() {
    string ruta = "estudiantes.txt";

    // Leer el archivo y cargar los datos en el vector
    vector<Estudiante> lista = leerArchivo(ruta);

    // Verificar si hay registros antes de procesar
    if (lista.empty()) {
        cout << "No hay registros en el archivo." << endl;
        return 0;
    }

    // Mostrar todos los registros
    mostrarRegistros(lista);

    // Mostrar el total de estudiantes
    contarEstudiantes(lista);

    // Mostrar el promedio general
    promedioGeneral(lista);

    return 0;
}
