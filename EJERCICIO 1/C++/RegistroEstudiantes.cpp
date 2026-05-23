#include <iostream>
#include <fstream>   // Para manejo de archivos
#include <string>
using namespace std;

// Clase que representa a un Estudiante
class Estudiante {
private:
    // Atributos de la clase
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

    // Método que guarda los datos del estudiante en el archivo
    void guardarEnArchivo() {
        // ios::app activa el modo append: no sobreescribe registros anteriores
        ofstream archivo("estudiantes.txt", ios::app);

        if (archivo.is_open()) {
            // Escribir los datos separados por '|' y terminar con salto de línea
            archivo << cedula << "|" << nombre << "|"
                    << carrera << "|" << promedio << endl;
            archivo.close(); // Cerrar el flujo de escritura
            cout << "Estudiante registrado exitosamente en estudiantes.txt" << endl;
        } else {
            // Manejo de error si no se puede abrir/crear el archivo
            cout << "Error: no se pudo abrir el archivo." << endl;
        }
    }
};

// Función principal
int main() {
    string cedula, nombre, carrera;
    double promedio;

    // Solicitar y leer cada dato del estudiante
    cout << "Ingrese la cedula del estudiante: ";
    getline(cin, cedula);

    cout << "Ingrese el nombre del estudiante: ";
    getline(cin, nombre);

    cout << "Ingrese la carrera del estudiante: ";
    getline(cin, carrera);

    cout << "Ingrese el promedio del estudiante: ";
    cin >> promedio;

    // Crear objeto Estudiante con los datos ingresados
    Estudiante est(cedula, nombre, carrera, promedio);

    // Llamar al método que guarda en el archivo
    est.guardarEnArchivo();

    return 0;
}