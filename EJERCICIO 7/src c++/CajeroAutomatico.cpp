#include <iostream>
#include <fstream>
using namespace std;

class Cajero {
private:
    string usuario;
    float saldo;

public:
    void ingresarDatos() {
        cout << "Ingrese el nombre del usuario: ";
        cin.ignore();
        getline(cin, usuario);

        cout << "Ingrese el saldo inicial: ";
        cin >> saldo;
    }

    void consultarSaldo() {
        cout << "\nSaldo actual: $" << saldo << endl;
    }

    void depositar() {
        float deposito;

        cout << "Ingrese la cantidad a depositar: ";
        cin >> deposito;

        saldo += deposito;

        cout << "Deposito realizado correctamente." << endl;
    }

    void retirar() {
        float retiro;

        cout << "Ingrese la cantidad a retirar: ";
        cin >> retiro;

        if (retiro <= saldo) {
            saldo -= retiro;
            cout << "Retiro realizado correctamente." << endl;
        } else {
            cout << "Saldo insuficiente." << endl;
        }
    }

    void guardarArchivo() {
        ofstream archivo("cajero.txt");

        archivo << "Usuario: " << usuario << endl;
        archivo << "Saldo: " << saldo << endl;

        archivo.close();
    }

    void mostrarArchivo() {
        ifstream archivo("cajero.txt");
        string linea;

        cout << "\n===== DATOS GUARDADOS =====" << endl;

        while (getline(archivo, linea)) {
            cout << linea << endl;
        }

        archivo.close();
    }
};

int main() {

    Cajero c;
    int opcion;

    c.ingresarDatos();

    do {
        cout << "\n===== CAJERO AUTOMATICO =====" << endl;
        cout << "1. Consultar saldo" << endl;
        cout << "2. Depositar dinero" << endl;
        cout << "3. Retirar dinero" << endl;
        cout << "4. Mostrar datos guardados" << endl;
        cout << "5. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {

        case 1:
            c.consultarSaldo();
            break;

        case 2:
            c.depositar();
            c.guardarArchivo();
            break;

        case 3:
            c.retirar();
            c.guardarArchivo();
            break;

        case 4:
            c.mostrarArchivo();
            break;

        case 5:
            cout << "Programa finalizado." << endl;
            break;

        default:
            cout << "Opcion invalida." << endl;
        }

    } while (opcion != 5);

    return 0;
}