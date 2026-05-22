import java.io.*;
import java.util.ArrayList;
import java.util.Scanner;

class Contacto {
    String nombre;
    String telefono;
    String correo;

    Contacto(String nombre, String telefono, String correo) {
        this.nombre = nombre;
        this.telefono = telefono;
        this.correo = correo;
    }
}

public class Ejercicio4AgendaTelefonica {
    private final ArrayList<Contacto> contactos = new ArrayList<>();
    private final Scanner sc = new Scanner(System.in);

    public void cargarDesdeArchivo() {
        File archivo = new File("agenda.txt");
        if (!archivo.exists()) return;

        try (BufferedReader br = new BufferedReader(new FileReader(archivo))) {
            String linea;
            while ((linea = br.readLine()) != null) {
                String[] partes = linea.split(";");
                if (partes.length == 3) {
                    contactos.add(new Contacto(partes[0], partes[1], partes[2]));
                }
            }
        } catch (IOException e) {
            System.out.println("Error al leer archivo: " + e.getMessage());
        }
    }

    public void guardarTodo() {
        try (BufferedWriter bw = new BufferedWriter(new FileWriter("agenda.txt"))) {
            for (Contacto c : contactos) {
                bw.write(c.nombre + ";" + c.telefono + ";" + c.correo);
                bw.newLine();
            }
        } catch (IOException e) {
            System.out.println("Error al guardar archivo: " + e.getMessage());
        }
    }

    public void agregarContacto() {
        System.out.print("Nombre: ");
        String nombre = sc.nextLine();
        System.out.print("Telefono: ");
        String telefono = sc.nextLine();
        System.out.print("Correo: ");
        String correo = sc.nextLine();

        contactos.add(new Contacto(nombre, telefono, correo));
        guardarTodo();
        System.out.println("Contacto agregado correctamente.");
    }

    public void buscarContacto() {
        System.out.print("Ingrese el nombre a buscar: ");
        String busqueda = sc.nextLine();
        boolean encontrado = false;

        for (Contacto c : contactos) {
            if (c.nombre.equalsIgnoreCase(busqueda)) {
                System.out.println("\nEncontrado:");
                System.out.println("Nombre: " + c.nombre);
                System.out.println("Telefono: " + c.telefono);
                System.out.println("Correo: " + c.correo);
                encontrado = true;
            }
        }

        if (!encontrado) {
            System.out.println("No se encontro el contacto.");
        }
    }

    public void mostrarContactos() {
        if (contactos.isEmpty()) {
            System.out.println("No hay contactos registrados.");
            return;
        }

        System.out.println("\n--- Lista de contactos ---");
        for (Contacto c : contactos) {
            System.out.println("Nombre: " + c.nombre + " | Telefono: " + c.telefono + " | Correo: " + c.correo);
        }
    }

    public void menu() {
        int opcion;
        do {
            System.out.println("\n1. Agregar contacto");
            System.out.println("2. Buscar contacto");
            System.out.println("3. Mostrar contactos");
            System.out.println("0. Salir");
            System.out.print("Opcion: ");
            opcion = Integer.parseInt(sc.nextLine());

            switch (opcion) {
                case 1 -> agregarContacto();
                case 2 -> buscarContacto();
                case 3 -> mostrarContactos();
                case 0 -> System.out.println("Saliendo...");
                default -> System.out.println("Opcion invalida.");
            }
        } while (opcion != 0);
    }

    public static void main(String[] args) {
        Ejercicio4AgendaTelefonica app = new Ejercicio4AgendaTelefonica();
        app.cargarDesdeArchivo();
        app.menu();
    }
}