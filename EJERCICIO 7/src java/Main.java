import java.io.*;
import java.util.Scanner;

class Cajero {

    private String usuario;
    private double saldo;

    Scanner sc = new Scanner(System.in);

    public void ingresarDatos() {

        System.out.print("Ingrese el nombre del usuario: ");
        usuario = sc.nextLine();

        System.out.print("Ingrese el saldo inicial: ");
        saldo = sc.nextDouble();
    }

    public void consultarSaldo() {
        System.out.println("\nSaldo actual: $" + saldo);
    }

    public void depositar() {

        double deposito;

        System.out.print("Ingrese la cantidad a depositar: ");
        deposito = sc.nextDouble();

        saldo += deposito;

        System.out.println("Deposito realizado correctamente.");
    }

    public void retirar() {

        double retiro;

        System.out.print("Ingrese la cantidad a retirar: ");
        retiro = sc.nextDouble();

        if (retiro <= saldo) {
            saldo -= retiro;
            System.out.println("Retiro realizado correctamente.");
        } else {
            System.out.println("Saldo insuficiente.");
        }
    }

    public void guardarArchivo() {

        try {

            FileWriter archivo = new FileWriter("cajero.txt");

            archivo.write("Usuario: " + usuario + "\n");
            archivo.write("Saldo: " + saldo + "\n");

            archivo.close();

        } catch (IOException e) {
            System.out.println("Error al guardar el archivo");
        }
    }

    public void mostrarArchivo() {

        try {

            BufferedReader archivo = new BufferedReader(new FileReader("cajero.txt"));

            String linea;

            System.out.println("\n===== DATOS GUARDADOS =====");

            while ((linea = archivo.readLine()) != null) {
                System.out.println(linea);
            }

            archivo.close();

        } catch (IOException e) {
            System.out.println("Error al leer el archivo");
        }
    }
}

public class Main {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        Cajero c = new Cajero();

        int opcion;

        c.ingresarDatos();

        do {

            System.out.println("\n===== CAJERO AUTOMATICO =====");
            System.out.println("1. Consultar saldo");
            System.out.println("2. Depositar dinero");
            System.out.println("3. Retirar dinero");
            System.out.println("4. Mostrar datos guardados");
            System.out.println("5. Salir");
            System.out.print("Seleccione una opcion: ");

            opcion = sc.nextInt();

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
                    System.out.println("Programa finalizado.");
                    break;

                default:
                    System.out.println("Opcion invalida.");
            }

        } while (opcion != 5);
    }
}