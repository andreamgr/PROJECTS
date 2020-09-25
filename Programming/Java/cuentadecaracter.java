import java.util.Scanner;
public class cuentadecaracter {
    public static void main(String [] args){
        Scanner entrada =  new Scanner(System.in);
        String frase;
        char letra = 'm';
        int contador = 0;
        int posicion;


        System.out.println("Dame la cadena");  
        frase = entrada.nextLine();
        posicion = frase.indexOf(letra);


        while ( posicion != -1)
        {
            contador++;
            posicion = frase.indexOf(letra, posicion +1);

        }
        System.out.println("El total es: " + contador);
        }
    }