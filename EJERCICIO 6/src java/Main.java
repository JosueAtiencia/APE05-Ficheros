import java.io.*;
import java.util.Scanner;

class Asistencia {

    private String nombre, fecha, estado;
    private int faltas = 0;

    Scanner sc = new Scanner(System.in);

    public void registrar() {

        System.out.print("Ingrese el nombre del estudiante: ");
        nombre = sc.nextLine();

        System.out.print("Ingrese la fecha: ");
        fecha = sc.nextLine();

        do {
            System.out.print("Ingrese el estado (Asistio/Falto): ");
            estado = sc.nextLine();

            if (!estado.equals("Asistio") && !estado.equals("Falto")) {
                System.out.println("Estado invalido. Intente nuevamente.");
            }

        } while (!estado.equals("Asistio") && !estado.equals("Falto"));

        if (estado.equals("Falto")) {
            faltas++;
        }
    }

    public void guardarArchivo() {

        try {
            FileWriter archivo = new FileWriter("asistencia.txt", true);

            archivo.write("Nombre: " + nombre + "\n");
            archivo.write("Fecha: " + fecha + "\n");
            archivo.write("Estado: " + estado + "\n");
            archivo.write("---------------------\n");

            archivo.close();

        } catch (IOException e) {
            System.out.println("Error al guardar el archivo");
        }
    }

    public void mostrarHistorial() {

        try {
            BufferedReader archivo = new BufferedReader(new FileReader("asistencia.txt"));

            String linea;

            System.out.println("\n===== HISTORIAL =====");

            while ((linea = archivo.readLine()) != null) {
                System.out.println(linea);
            }

            archivo.close();

        } catch (IOException e) {
            System.out.println("Error al leer el archivo");
        }
    }

    public void mostrarFaltas() {
        System.out.println("\nTotal de faltas: " + faltas);
    }
}

public class Main {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        Asistencia a = new Asistencia();

        int opcion;

        do {

            System.out.println("\n===== MENU =====");
            System.out.println("1. Registrar asistencia");
            System.out.println("2. Mostrar historial");
            System.out.println("3. Mostrar faltas");
            System.out.println("4. Salir");
            System.out.print("Seleccione una opcion: ");

            opcion = sc.nextInt();
            sc.nextLine();

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
                    System.out.println("Programa finalizado.");
                    break;

                default:
                    System.out.println("Opcion invalida.");
            }

        } while (opcion != 4);
    }
}