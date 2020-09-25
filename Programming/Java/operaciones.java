import java.util.Scanner;
import java.lang.Math;
public class operaciones  {
        public static void main(String [] args){
        Scanner entrada =  new Scanner(System.in);
        double dato1, dato2;
        System.out.println("Dame un numero entero");
        dato1 = entrada.nextDouble();
        System.out.println("Dame un segundo numero entero");
        dato2 = entrada.nextDouble();
        System.out.println("La potencia es: " + Math.pow(dato1,dato2));
        System.out.println("Su raiz cuadrada es: " + Math.sqrt(dato1));
        System.out.println("Su valor absoluto es: " + Math.abs(dato1));
        System.out.println("El valor entero mas cercano del numero es: " + Math.floor(dato2));
        System.out.println("Esta es la raiz del primer dato elevado al segundo: " + Math.sqrt(Math.pow(dato1,dato2)));


          
    }
}