#include <iostream>
#include <fstream>
using namespace std;

class Asistencia {
private:
    string nombre, fecha, estado;
    int faltas = 0;

public:
    void registrar() {
        cout << "Ingrese el nombre del estudiante: ";
        cin.ignore();
        getline(cin, nombre);

        cout << "Ingrese la fecha: ";
        getline(cin, fecha);

        do {
            cout << "Ingrese el estado (Asistio/Falto): ";
            getline(cin, estado);

            if (estado != "Asistio" && estado != "Falto") {
                cout << "Estado invalido. Intente nuevamente.\n";
            }

        } while (estado != "Asistio" && estado != "Falto");

        if (estado == "Falto") {
            faltas++;
        }
    }

    void guardarArchivo() {
        ofstream archivo("asistencia.txt", ios::app);

        archivo << "Nombre: " << nombre << endl;
        archivo << "Fecha: " << fecha << endl;
        archivo << "Estado: " << estado << endl;
        archivo << "---------------------" << endl;

        archivo.close();
    }

    void mostrarHistorial() {
        ifstream archivo("asistencia.txt");
        string linea;

        cout << "\n===== HISTORIAL =====\n";

        while (getline(archivo, linea)) {
            cout << linea << endl;
        }

        archivo.close();
    }

    void mostrarFaltas() {
        cout << "\nTotal de faltas: " << faltas << endl;
    }
};

int main() {

    Asistencia a;
    int opcion;

    do {
        cout << "\n===== MENU =====" << endl;
        cout << "1. Registrar asistencia" << endl;
        cout << "2. Mostrar historial" << endl;
        cout << "3. Mostrar faltas" << endl;
        cout << "4. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {

        case 1:
            a.registrar();
            a.guardarArchivo();
            break;

        case 2:
            a.mostrarHistorial();
            break;

        case 3:
            a.mostrarFaltas();
            break;

        case 4:
            cout << "Programa finalizado." << endl;
            break;

        default:
            cout << "Opcion invalida." << endl;
        }

    } while (opcion != 4);

    return 0;
}