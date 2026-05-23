import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;

// Clase que representa a un Estudiante
class Estudiante {
    // Atributos de la clase
    private String cedula;
    private String nombre;
    private String carrera;
    private double promedio;

    // Constructor: inicializa todos los atributos
    public Estudiante(String cedula, String nombre, String carrera, double promedio) {
        this.cedula   = cedula;
        this.nombre   = nombre;
        this.carrera  = carrera;
        this.promedio = promedio;
    }

    // Método que imprime los datos del estudiante en consola
    public void mostrar() {
        System.out.println("Cedula:   " + cedula);
        System.out.println("Nombre:   " + nombre);
        System.out.println("Carrera:  " + carrera);
        System.out.printf ("Promedio: %.2f%n", promedio);
        System.out.println("----------------------------------");
    }

    // Getter del promedio (necesario para calcular el promedio general)
    public double getPromedio() {
        return promedio;
    }
}

// Clase principal
public class Main {

    // Método que lee el archivo y retorna una lista de objetos Estudiante
    public static ArrayList<Estudiante> leerArchivo(String ruta) {
        ArrayList<Estudiante> lista = new ArrayList<>();

        try (BufferedReader br = new BufferedReader(new FileReader(ruta))) {
            String linea;
            // Ciclo: leer línea por línea hasta el final del archivo
            while ((linea = br.readLine()) != null) {
                // Separar los campos usando el delimitador '|'
                String[] partes = linea.split("\\|");
                if (partes.length == 4) {
                    String cedula   = partes[0];
                    String nombre   = partes[1];
                    String carrera  = partes[2];
                    double promedio = Double.parseDouble(partes[3]);
                    // Crear objeto Estudiante y agregarlo a la lista
                    lista.add(new Estudiante(cedula, nombre, carrera, promedio));
                }
            }
        } catch (IOException e) {
            System.out.println("Error al leer el archivo: " + e.getMessage());
        }
        return lista;
    }

    // Método que muestra todos los registros de la lista
    public static void mostrarRegistros(ArrayList<Estudiante> lista) {
        System.out.println("===== LISTA DE ESTUDIANTES =====");
        // Ciclo: recorrer cada estudiante e invocar su método mostrar()
        for (Estudiante est : lista) {
            est.mostrar();
        }
    }

    // Método que cuenta y muestra el total de estudiantes
    public static int contarEstudiantes(ArrayList<Estudiante> lista) {
        int total = lista.size(); // El tamaño del arreglo es el total
        System.out.println("Total de estudiantes: " + total);
        return total;
    }

    // Método que calcula y muestra el promedio general
    public static void promedioGeneral(ArrayList<Estudiante> lista) {
        double sumaPromedios = 0;
        // Ciclo: acumular la suma de todos los promedios individuales
        for (Estudiante est : lista) {
            sumaPromedios += est.getPromedio();
        }
        double promGeneral = sumaPromedios / lista.size();
        System.out.printf("Promedio general: %.2f%n", promGeneral);
    }

    public static void main(String[] args) {
        String ruta = "estudiantes.txt";

        // Leer el archivo y cargar los datos en la lista
        ArrayList<Estudiante> lista = leerArchivo(ruta);

        // Verificar si hay registros antes de procesar
        if (lista.isEmpty()) {
            System.out.println("No hay registros en el archivo.");
            return;
        }

        // Mostrar todos los registros
        mostrarRegistros(lista);

        // Mostrar el total de estudiantes
        contarEstudiantes(lista);

        // Mostrar el promedio general
        promedioGeneral(lista);
    }
}
