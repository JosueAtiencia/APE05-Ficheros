#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
using namespace std;

class Producto {
public:
    string codigo, nombre;
    int cantidad;
    double precio;

    double subtotal() const {
        return cantidad * precio;
    }
};

class Inventario {
private:
    vector<Producto> productos;

public:
    void registrarProductos() {
        int n;
        cout << "¿Cuantos productos desea registrar?: ";
        cin >> n;
        cin.ignore();

        ofstream archivo("inventario.txt");
        double totalInventario = 0.0;

        for (int i = 0; i < n; i++) {
            Producto p;
            cout << "\nProducto " << (i + 1) << endl;
            cout << "Codigo: ";
            getline(cin, p.codigo);
            cout << "Nombre: ";
            getline(cin, p.nombre);
            cout << "Cantidad: ";
            cin >> p.cantidad;
            cout << "Precio: ";
            cin >> p.precio;
            cin.ignore();

            productos.push_back(p);
            archivo << p.codigo << ";" << p.nombre << ";" << p.cantidad << ";" << p.precio << "\n";
            totalInventario += p.subtotal();
        }

        archivo.close();
        cout << "\nDatos guardados en inventario.txt\n";
        cout << fixed << setprecision(2);
        cout << "Valor total del inventario: $" << totalInventario << endl;
    }
};

int main() {
    Inventario inv;
    inv.registrarProductos();
    return 0;
}