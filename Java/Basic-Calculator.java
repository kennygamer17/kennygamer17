import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner entrada = new Scanner(System.in);
        double num1,num2,resultado,desicion;
        boolean continuar = true;

        System.out.println("Digite 1 valor -> ");
        num1 = entrada.nextInt();
        System.out.println("Digite otro valor -> ");
        num2 = entrada.nextInt();


        System.out.println("Que desea hacer? ");


        while(continuar){
            do{
                System.out.println("---MENU----");
                System.out.println("\n(1)-Sumar entre si\n(2)-Restar entre si\n(3)-Multiplicar entre si\n(4)-Dividir entre si\n(5)-Salir");
                desicion = entrada.nextInt();
                if (desicion>5 || desicion<1){
                    System.out.println("Error..");
                }
            }while (desicion>5 || desicion<1);


            switch ((int) desicion){
                case 1: resultado = (num1+num2);
                    System.out.println("El resultado es: " + resultado);
                    break;
                case 2: resultado = (num1-num2);
                    System.out.println("El resultado es: " + resultado);
                    break;
                case 3: resultado = (num1*num2);
                    System.out.println("El resultado es: " + resultado);
                    break;
                case 4: resultado = (num1/num2);
                    System.out.println("El resultado es: " + resultado);
                    break;
                case 5:
                    System.out.println("Saliendo..... ");
                    continuar = false;
                    break;
                default: continuar = false; break;
            }
        }
    }
}
/*MADE BY: kennygamer17 on Github || Lexor_12 on YT*/
