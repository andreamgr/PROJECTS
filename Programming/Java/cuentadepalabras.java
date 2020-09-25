import java.util.Scanner;
public class cuentadepalabras {
    public static void main(String [] args){
        Scanner entrada =  new Scanner(System.in);
        String s;
        int contador = 1;
        int posicion;


        System.out.println("Dame la cadena");  
        s = entrada.nextLine();
        s = s.trim(); //elimina los posibles espacios en blanco al principio y al final 

        if (s.isEmpty()){
            contador = 0;
        } else{
            posicion = s.indexOf(" "); // se busca el primer espacio en blanco 
            while (posicion != -1){ // esto se hace mientras que se encuantre un espacio en blanco 
                contador++; // se cuenta una palabra
                posicion = s.indexOf(" ", posicion +1); //se busca el sig espacio en blanco
            }
        }
        System.out.println("El numero de palabras es: " + contador);
        }
    }