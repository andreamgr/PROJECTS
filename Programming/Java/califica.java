import java.util.Scanner;
public class califica {
    public static void main(String [] args){
        Scanner entrada =  new Scanner(System.in);
        int calif;
        System.out.println("Dame calificacion");
        calif = entrada.nextInt();
        if (calif >= 90 && calif <=100) 
        System.out.println("Felicidades");
        else {
           if (calif >= 80 && calif <=89) 
        System.out.println("Bien");
        else 
         if (calif >= 70 && calif <=79) 
        System.out.println("Regular");
        else 
        System.out.println("\n Deberas repetir el curso");

        }
        
        
    }
}