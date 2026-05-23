#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <fstream>
#include <limits>
using namespace std;

class Producto {
private:
    string productoNombre;
    double cantidad;
    double precio;
    double totalProducto;

public:
    void setProductoNombre(string p){ productoNombre = p; }
    void setCantidad(double c){ cantidad = c; }
    void setPrecio(double p){ precio = p; }
    void setTotalProducto(double t){ totalProducto = t; }

    string getProductoNombre(){ return productoNombre; }
    double getCantidad(){ return cantidad; }
    double getPrecio(){ return precio; }
    double getTotalProducto(){ return totalProducto; }
};

int main() {

    Producto p;
    string producto;
    double precioP, cantidadP;
    bool menuOpcion;
    int opcionMenu;
    int contador;
    string cliente;
    string cedula;

    vector<Producto> productos;

    
    ofstream Facturar("factura.csv");
    if (Facturar.is_open()) {
        Facturar << "Cantidad;Producto;Precio;Total" << endl;
        Facturar.close();
    }

    do {
        productos.clear();

        cout << "\nSistema facturacion\n"
                << "1 - Ingresar nueva factura\n"
                << "2 - Mostrar Historial de ventas\n"
                << "3 - Salir\n";

        cin >> opcionMenu;
        menuOpcion = opcionMenu != 3;

        switch (opcionMenu)
        {
        case 1:
        {
            double iva, subtotal, total;
            double totalPagar = 0;

            cout << "Ingresa el nombre del cliente\n";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, cliente);

            cout << "Ingresa el numero de cedula\n";
            cin >> cedula;

            cout << "Cuantos productos ingresara\n";
            cin >> contador;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            for (int i = 0; i < contador; i++)
            {
                cout << "Ingresa el nombre\n";
                getline(cin, producto);
                p.setProductoNombre(producto);

                cout << "Ingresa el precio\n";
                cin >> precioP;

                cout << "Ingresa la cantidad\n";
                cin >> cantidadP;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                p.setPrecio(precioP);
                p.setCantidad(cantidadP);
                p.setTotalProducto(cantidadP * precioP);

                productos.push_back(p);
            }

            cout << left
                    << setw(10) << "Nombre:" << cliente
                    << setw(10) << " "
                    << setw(10) << "Cedula:" << cedula << endl;

            cout << string(80,'-') << endl;

            cout << fixed << setprecision(2);

            cout << left
                    << setw(10) << "Cantidad"
                    << setw(30) << "Producto"
                    << setw(10) << "Precio"
                    << setw(10) << "Subtotal"
                    << endl;

            for (int i = 0; i < productos.size(); i++)
            {
                cout << left
                        << setw(10) << productos[i].getCantidad()
                        << setw(30) << productos[i].getProductoNombre()
                        << setw(10) << productos[i].getPrecio()
                        << setw(10) << productos[i].getTotalProducto()
                        << endl;

                totalPagar += productos[i].getTotalProducto();
            }

            subtotal = totalPagar;
            iva = subtotal * 0.15;
            total = subtotal + iva;

            cout << "Subtotal: " << subtotal << endl;
            cout << "IVA: " << iva << endl;
            cout << "Total: " << total << endl;

            // Guardar en archivo
            ofstream Registro("factura.csv", ios::app);

            if (Registro.is_open())
            {
                for (int i = 0; i < productos.size(); i++)
                {
                    Registro << productos[i].getCantidad() << ";"
                                << productos[i].getProductoNombre() << ";"
                                << productos[i].getPrecio() << ";"
                                << productos[i].getTotalProducto() << endl;
                }
                Registro.close();
            }

            break;
        }

        case 2:
        {
            ifstream Registro("factura.csv");

            cout << "\nRegistro:\n";

            if (Registro.is_open())
            {
                string linea;
                while (getline(Registro, linea))
                {
                    cout << linea << endl;
                }
                Registro.close();
            }
            else
            {
                cout << "No se pudo abrir el archivo.\n";
            }

            break;
        }

        default:
        {
            cout << "Opcion invalida, intentalo de nuevo\n";
            break;
        }
        }

    } while (menuOpcion);

    return 0;
}