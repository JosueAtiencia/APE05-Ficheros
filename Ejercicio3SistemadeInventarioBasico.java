import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Locale;
import java.util.Scanner;

class Producto {
    String codigo;
    String nombre;
    int cantidad;
    double precio;

    double subtotal() {
        return cantidad * precio;
    }
}

public class Ejercicio3SistemadeInventarioBasico {
    private final ArrayList<Producto> productos = new ArrayList<>();

    public void registrarProductos() {
        Scanner sc = new Scanner(System.in);
        sc.useLocale(Locale.US);

        System.out.print("¿Cuantos productos desea registrar?: ");
        int n = Integer.parseInt(sc.nextLine());

        double totalInventario = 0.0;

        try (FileWriter fw = new FileWriter("inventario.txt")) {
            for (int i = 0; i < n; i++) {
                Producto p = new Producto();
                System.out.println("\nProducto " + (i + 1));
                System.out.print("Codigo: ");
                p.codigo = sc.nextLine();
                System.out.print("Nombre: ");
                p.nombre = sc.nextLine();
                System.out.print("Cantidad: ");
                p.cantidad = Integer.parseInt(sc.nextLine());
                System.out.print("Precio: ");
                p.precio = Double.parseDouble(sc.nextLine());

                productos.add(p);
                fw.write(p.codigo + ";" + p.nombre + ";" + p.cantidad + ";" + p.precio + "\n");
                totalInventario += p.subtotal();
            }

            System.out.println("\nDatos guardados en inventario.txt");
            System.out.printf("Valor total del inventario: $%.2f%n", totalInventario);

        } catch (IOException e) {
            System.out.println("Error al escribir el archivo: " + e.getMessage());
        }
    }

    public static void main(String[] args) {
        Ejercicio3SistemadeInventarioBasico app = new Ejercicio3SistemadeInventarioBasico();
        app.registrarProductos();
    }
}