import java.util.Scanner;
public class calorias {
    public static void main(String [] args){
        Scanner entrada =  new Scanner (System.in);
        int num, cal;
        String nombre;
        int acum = 0;
        int cont = 1;

        System.out.println("BIENVENIDO");
        System.out.println("Digita tu nombre: ");
        nombre = entrada.nextLine();
        System.out.println("Cuantos alimentos has comido hoy?");
        num = entrada.nextInt();
        
            System.out.println("Ingrese las calorias de cada 1 de los " +num+ " alimentos que consumiste hoy.");
            
            do {

                cal = entrada.nextInt();
                cont++;
                acum = acum + cal;
            }
            while (cont <= num );
            {
                System.out.println( nombre +", consumiste "+num+ " alimentos, la suma de las calorias totales consumidas es: " + acum );

            }


        
       
        }
    }