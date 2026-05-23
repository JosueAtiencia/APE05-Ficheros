#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
using namespace std;

class Libro{
private:
    string codigo;
    string titulo;
    string autor;
    bool estadoDisponible = false;

public:
    void setCodigo(string c){ codigo = c; }
    void setTitulo(string t){ titulo = t; }
    void setAutor(string a){ autor = a; }
    void setEstado(bool e){ estadoDisponible = e; }

    string getCodigo(){ return codigo; }
    string getTitulo(){ return titulo; }
    string getAutor(){ return autor; }
    bool getEstadoDisponible(){ return estadoDisponible; }
};

int main() {

    int opcion, contadorPrestados, contadorDisponibles;
    bool condicionMenu;
    string codigo, titulo, autor, codigoBuscar;
    int estado;
    bool estadoL;
    vector<Libro> libros;

    fstream Archivo("Libros.csv", ios::out);
    string indice = "Codigo;Titulo;Autor;Estado";
    if(Archivo.is_open()){
        Archivo << indice << endl;
        Archivo.close();
    } else {
        cout << "No se pudo crear el archivo Libros.csv" << endl;
    }

    contadorPrestados = 0;
    contadorDisponibles = 0;

    do{
        cout << left
            << setw(20) << "--- Menu ---" << endl
            << setw(10) << "1 - Registrar libro" << endl
            << setw(10) << "2 - Buscar libro" << endl
            << setw(10) << "3 - Mostrar todos" << endl
            << setw(10) << "4 - Salir" << endl;

        cin >> opcion;

        if(cin.fail()){
            cin.clear();
            cin.ignore(10000,'\n');
            cout << "Entrada invalida" << endl;
            continue;
        }

        condicionMenu = opcion != 4;

        switch (opcion)
        {
        case 1:
        {
            cout << "Ingresar codigo" << endl;
            cin >> codigo;

            if(codigo.empty()){
                cout << "Codigo invalido" << endl;
                break;
            }

            bool duplicado = false;
            for(int i = 0; i < (int)libros.size(); i++){
                if(libros[i].getCodigo() == codigo){
                    duplicado = true;
                }
            }

            if(duplicado){
                cout << "Codigo ya existe" << endl;
                break;
            }

            Libro libro;
            libro.setCodigo(codigo);

            cout << "Ingresar titulo" << endl;
            cin.ignore(10000,'\n');
            getline(cin, titulo);

            if(titulo.empty()){
                cout << "Titulo invalido" << endl;
                break;
            }
            libro.setTitulo(titulo);

            cout << "Ingresar autor" << endl;
            getline(cin, autor);

            if(autor.empty()){
                cout << "Autor invalido" << endl;
                break;
            }
            libro.setAutor(autor);

            cout << "Ingrese disponibilidad" << endl
                << "1 - Disponible" << endl
                << "2 - No disponible" << endl;

            cin >> estado;

            if(cin.fail()){
                cin.clear();
                cin.ignore(10000,'\n');
                cout << "Entrada invalida" << endl;
                break;
            }

            if(estado != 1 && estado != 2){
                cout << "Opcion invalida" << endl;
                break;
            }

            if(estado == 1){
                estadoL = true;
                contadorDisponibles++;
            } else {
                estadoL = false;
                contadorPrestados++;
            }

            libro.setEstado(estadoL);
            libros.push_back(libro);

            fstream ArchivoApendice("Libros.csv", ios::app);
            if(ArchivoApendice.is_open()){
                ArchivoApendice << libro.getCodigo() << ";"
                                << libro.getTitulo() << ";"
                                << libro.getAutor() << ";"
                                << libro.getEstadoDisponible()
                                << endl;
                ArchivoApendice.close();
            } else {
                cout << "No se pudo abrir Libros.csv para escribir" << endl;
            }

            break;
        }

        case 2:
        {
            if(libros.empty()){
                cout << "No hay libros registrados" << endl;
                break;
            }

            cout << "Ingrese codigo a buscar: ";
            cin >> codigoBuscar;

            bool encontrado = false;

            for(int i = 0; i < (int)libros.size(); i++){
                if(libros[i].getCodigo() == codigoBuscar){
                    cout << left
                            << setw(10) << libros[i].getCodigo()
                            << setw(30) << libros[i].getTitulo()
                            << setw(30) << libros[i].getAutor()
                            << setw(20) << (libros[i].getEstadoDisponible() ? "Disponible" : "Prestado")
                            << endl;
                    encontrado = true;
                }
            }

            if(!encontrado){
                cout << "Libro no encontrado" << endl;
            }

            break;
        }

        case 3:
        {
            if(libros.empty()){
                cout << "No hay libros registrados" << endl;
                break;
            }

            cout << left
                    << setw(10) << "Codigo"
                    << setw(30) << "Titulo"
                    << setw(30) << "Autor"
                    << setw(20) << "Estado"
                    << endl;

            cout << string(100,'-') << endl;

            for(int i = 0; i < (int)libros.size(); i++){
                cout << left
                        << setw(10) << libros[i].getCodigo()
                        << setw(30) << libros[i].getTitulo()
                        << setw(30) << libros[i].getAutor()
                        << setw(20) << (libros[i].getEstadoDisponible() ? "Disponible" : "Prestado")
                        << endl;
            }

            break;
        }

        default:
            cout << "Opcion invalida" << endl;
            break;
        }

    }while(condicionMenu);

    return 0;
}