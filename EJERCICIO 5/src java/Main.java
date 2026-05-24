import java.io.*;
import java.util.Scanner;

class Estudiante {

    private String nombre;
    private double nota1, nota2, nota3, promedio;

    // Método para registrar estudiante
    public void registrar() {

        Scanner sc = new Scanner(System.in);

        System.out.print("Ingrese el nombre del estudiante: ");
        nombre = sc.nextLine();

        System.out.print("Ingrese nota 1: ");
        nota1 = sc.nextDouble();

        System.out.print("Ingrese nota 2: ");
        nota2 = sc.nextDouble();

        System.out.print("Ingrese nota 3: ");
        nota3 = sc.nextDouble();

        promedio = (nota1 + nota2 + nota3) / 3;
    }

    // Método para mostrar resultado
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

    // Método para guardar en archivo
    public void guardarArchivo() {

        try {

            FileWriter archivo = new FileWriter("estudiantes.txt", true);

            archivo.write("Nombre: " + nombre + "\n");
            archivo.write("Promedio: " + promedio + "\n");

            if (promedio >= 7) {
                archivo.write("Estado: APROBADO\n");
            } else {
                archivo.write("Estado: REPROBADO\n");
            }

            archivo.write("------------------------\n");

            archivo.close();

            System.out.println("\nDatos guardados correctamente.");

        } catch (IOException e) {

            System.out.println("Error al guardar archivo.");
        }
    }

    // Método para mostrar historial
    public void mostrarHistorial() {

        try {

            BufferedReader archivo =
                    new BufferedReader(new FileReader("estudiantes.txt"));

            String linea;

            System.out.println("\n===== HISTORIAL =====");

            while ((linea = archivo.readLine()) != null) {
                System.out.println(linea);
            }

            archivo.close();

        } catch (IOException e) {

            System.out.println("No existen registros.");
        }
    }
}

public class Main {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        Estudiante e = new Estudiante();

        int opcion;

        do {

            System.out.println("\n===== MENU =====");
            System.out.println("1. Registrar estudiante");
            System.out.println("2. Mostrar historial");
            System.out.println("3. Salir");
            System.out.print("Seleccione una opcion: ");

            opcion = sc.nextInt();

            switch (opcion) {

                case 1:

                    e.registrar();
                    e.mostrarResultado();
                    e.guardarArchivo();

                    break;

                case 2:

                    e.mostrarHistorial();

                    break;

                case 3:

                    System.out.println("Programa finalizado.");
                    break;

                default:

                    System.out.println("Opcion invalida.");
            }

        } while (opcion != 3);
    }
}