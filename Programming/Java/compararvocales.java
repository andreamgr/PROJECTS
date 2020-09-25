// empieza a contar desde 0 
import java.util.Scanner;
public class compararvocales {
    public static void main(String [] args){
        Scanner entrada =  new Scanner(System.in);
        int i;
        int cont = 0; //iniciado en 0 por que en las palabras se empieza a contar un caracter desde 0 
        String palabra;

        System.out.println("Ingrse su palabra");
        palabra = entrada.nextLine(); //con el next lee hasta el primer espacio y con el nextLine te cuenta la frase completa con espacios 

        for (i=0 ; i < palabra.length(); i++)
        {
            if ((palabra.charAt(i)=='a')|| (palabra.charAt(i)=='e')||(palabra.charAt(i)=='i')||(palabra.charAt(i)=='o')||(palabra.charAt(i)=='u'))
            {
                cont++;
            }
           
        }
            System.out.println("El total de vocales es: "+cont);

        }
    }
