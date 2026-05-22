#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;

class Contacto {
public:
    string nombre, telefono, correo;
};

class Agenda {
private:
    vector<Contacto> contactos;

public:
    void cargarDesdeArchivo() {
        ifstream archivo("agenda.txt");
        string linea;

        while (getline(archivo, linea)) {
            stringstream ss(linea);
            Contacto c;
            getline(ss, c.nombre, ';');
            getline(ss, c.telefono, ';');
            getline(ss, c.correo, ';');
            if (!c.nombre.empty()) contactos.push_back(c);
        }
        archivo.close();
    }

    void guardarTodo() {
        ofstream archivo("agenda.txt");
        for (const auto &c : contactos) {
            archivo << c.nombre << ";" << c.telefono << ";" << c.correo << "\n";
        }
        archivo.close();
    }

    void agregarContacto() {
        Contacto c;
        cin.ignore();
        cout << "Nombre: ";
        getline(cin, c.nombre);
        cout << "Telefono: ";
        getline(cin, c.telefono);
        cout << "Correo: ";
        getline(cin, c.correo);

        contactos.push_back(c);
        guardarTodo();
        cout << "Contacto agregado correctamente.\n";
    }

    void buscarContacto() {
        cin.ignore();
        string busqueda;
        cout << "Ingrese el nombre a buscar: ";
        getline(cin, busqueda);

        bool encontrado = false;
        for (const auto &c : contactos) {
            if (c.nombre == busqueda) {
                cout << "\nEncontrado:\n";
                cout << "Nombre: " << c.nombre << "\nTelefono: " << c.telefono
                     << "\nCorreo: " << c.correo << "\n";
                encontrado = true;
            }
        }
        if (!encontrado) cout << "No se encontro el contacto.\n";
    }

    void mostrarContactos() {
        if (contactos.empty()) {
            cout << "No hay contactos registrados.\n";
            return;
        }

        cout << "\n--- Lista de contactos ---\n";
        for (const auto &c : contactos) {
            cout << "Nombre: " << c.nombre
                 << " | Telefono: " << c.telefono
                 << " | Correo: " << c.correo << "\n";
        }
    }
};

int main() {
    Agenda agenda;
    agenda.cargarDesdeArchivo();

    int opcion;
    do {
        cout << "\n1. Agregar contacto\n2. Buscar contacto\n3. Mostrar contactos\n0. Salir\nOpcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: agenda.agregarContacto(); break;
            case 2: agenda.buscarContacto(); break;
            case 3: agenda.mostrarContactos(); break;
            case 0: cout << "Saliendo...\n"; break;
            default: cout << "Opcion invalida.\n";
        }
    } while (opcion != 0);

    return 0;
}