import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

class Estudiante {

    private String nombre;
    private double nota1, nota2, nota3, promedio;

    Scanner sc = new Scanner(System.in);

    public void ingresarDatos() {
        System.out.print("Ingrese el nombre del estudiante: ");
        nombre = sc.nextLine();

        System.out.print("Ingrese la nota 1: ");
        nota1 = sc.nextDouble();

        System.out.print("Ingrese la nota 2: ");
        nota2 = sc.nextDouble();

        System.out.print("Ingrese la nota 3: ");
        nota3 = sc.nextDouble();
    }

    public void calcularPromedio() {
        promedio = (nota1 + nota2 + nota3) / 3;
    }

    public void mostrarResultado() {
        System.out.println("\n===== RESULTADOS =====");
        System.out.println("Nombre: " + nombre);
        System.out.println("Promedio: " + promedio);

        if (promedio >= 7) {
            System.out.println("Estado: APROBADO");
        } else {
            System.out.println("Estado: REPROBADO");
        }
    }

    public void guardarArchivo() {
        try {
            FileWriter archivo = new FileWriter("notas.txt", true);

            archivo.write("Nombre: " + nombre + "\n");
            archivo.write("Promedio: " + promedio + "\n");

            if (promedio >= 7) {
                archivo.write("Estado: APROBADO\n");
            } else {
                archivo.write("Estado: REPROBADO\n");
            }

            archivo.write("------------------------\n");

            archivo.close();

            System.out.println("\nDatos guardados en notas.txt");

        } catch (IOException e) {
            System.out.println("Error al guardar el archivo");
        }
    }
}

public class Main {
    public static void main(String[] args) {

        Estudiante e = new Estudiante();

        e.ingresarDatos();
        e.calcularPromedio();
        e.mostrarResultado();
        e.guardarArchivo();
    }
}