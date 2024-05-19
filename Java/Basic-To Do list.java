import java.util.ArrayList;
import java.util.Scanner;
import java.util.List;

public class Main {
    public static void main(String[] args) {
        Scanner entrada = new Scanner(System.in);
        List<String> tasks = new ArrayList<>();
        boolean continuar = true;
        int decision;
        String tarea;

        System.out.println("Bienvenido a mi programa xd");

        while (continuar) {
            do {
                System.out.println("+---MENU---+");
                System.out.println("\n(1)-Agregar tarea\n(2)-Borrar tarea\n(3)-Ver tareas\n(4)-Salir");
                decision = entrada.nextInt();
                entrada.nextLine(); // Consumir el carácter de nueva línea
            } while (decision > 4 || decision < 1);

            switch (decision) {
                case 1:
                    System.out.println("Digite la tarea a continuacion -> ");
                    tarea = entrada.nextLine();
                    tasks.add(tarea);
                    System.out.println("Se agrego correctamente la tarea -> '" + tarea + "'");
                    break;
                case 2:
                    System.out.println("Digite el nombre de la tarea a eliminar -> ");
                    tarea = entrada.nextLine();
                    tasks.remove(tarea);
                    System.out.println("Se removio correctamente la tarea -> '" + tarea + "'");
                    break;
                case 3:
                    System.out.println("[----TAREAS ACTUALES--]\n");
                    System.out.println(tasks + "\n");
                    break;
                case 4:
                    System.out.println("Saliendo.....");
                    continuar = false;
                    break;
                default:
                    continuar = false;
                    break;
            }
        }
    }
}
/*MADE BY: kennygamer17 on Github || Lexor_12 on YT*/
