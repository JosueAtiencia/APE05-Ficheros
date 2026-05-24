#include <iostream>
#include <fstream>
using namespace std;

class Estudiante {
private:
    string nombre;
    float nota1, nota2, nota3, promedio;

public:
    void ingresarDatos() {
        cout << "Ingrese el nombre del estudiante: ";
        cin.ignore();
        getline(cin, nombre);

        cout << "Ingrese la nota 1: ";
        cin >> nota1;

        cout << "Ingrese la nota 2: ";
        cin >> nota2;

        cout << "Ingrese la nota 3: ";
        cin >> nota3;
    }

    void calcularPromedio() {
        promedio = (nota1 + nota2 + nota3) / 3;
    }

    void mostrarResultado() {
        cout << "\n===== RESULTADOS =====" << endl;
        cout << "Nombre: " << nombre << endl;
        cout << "Promedio: " << promedio << endl;

        if (promedio >= 7) {
            cout << "Estado: APROBADO" << endl;
        } else {
            cout << "Estado: REPROBADO" << endl;
        }
    }

    void guardarArchivo() {
        ofstream archivo("notas.txt", ios::app);

        archivo << "Nombre: " << nombre << endl;
        archivo << "Promedio: " << promedio << endl;

        if (promedio >= 7) {
            archivo << "Estado: APROBADO" << endl;
        } else {
            archivo << "Estado: REPROBADO" << endl;
        }

        archivo << "------------------------" << endl;

        archivo.close();
    }
};

int main() {
    Estudiante e;

    e.ingresarDatos();
    e.calcularPromedio();
    e.mostrarResultado();
    e.guardarArchivo();

    cout << "\nDatos guardados en el archivo notas.txt" << endl;

    return 0;
}