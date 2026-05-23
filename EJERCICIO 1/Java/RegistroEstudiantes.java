import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

// Clase que representa a un Estudiante
class Estudiante {
    // Atributos de la clase
    private String cedula;
    private String nombre;
    private String carrera;
    private double promedio;

    // Constructor: inicializa todos los atributos
    public Estudiante(String cedula, String nombre, String carrera, double promedio) {
        this.cedula  = cedula;
        this.nombre  = nombre;
        this.carrera = carrera;
        this.promedio = promedio;
    }

    // Método que guarda los datos del estudiante en el archivo
    public void guardarEnArchivo() {
        // 'true' activa el modo append: no sobreescribe registros anteriores
        try (BufferedWriter bw = new BufferedWriter(new FileWriter("estudiantes.txt", true))) {
            // Formatear la línea con separador '|'
            String linea = cedula + "|" + nombre + "|" + carrera + "|" + promedio;
            bw.write(linea);   // Escribir los datos
            bw.newLine();      // Agregar salto de línea al final del registro
            System.out.println("Estudiante registrado exitosamente en estudiantes.txt");
        } catch (IOException e) {
            // Manejo de error si no se puede escribir el archivo
            System.out.println("Error al escribir el archivo: " + e.getMessage());
        }
    }
}

// Clase principal con el método main
public class Main {
    public static void main(String[] args) {
        // Crear objeto Scanner para leer datos del teclado
        Scanner sc = new Scanner(System.in);

        // Solicitar y leer cada dato del estudiante
        System.out.print("Ingrese la cédula del estudiante: ");
        String cedula = sc.nextLine();

        System.out.print("Ingrese el nombre del estudiante: ");
        String nombre = sc.nextLine();

        System.out.print("Ingrese la carrera del estudiante: ");
        String carrera = sc.nextLine();

        System.out.print("Ingrese el promedio del estudiante: ");
        double promedio = sc.nextDouble();

        // Crear objeto Estudiante con los datos ingresados
        Estudiante est = new Estudiante(cedula, nombre, carrera, promedio);

        // Llamar al método que guarda en el archivo
        est.guardarEnArchivo();

        sc.close(); // Cerrar el Scanner
    }
}
