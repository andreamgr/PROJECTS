 //cuando n es > 0
//mover n discos de Orig a Dest
//1. mover n-1 diascos de Orig a Temp
//2. mover disco n de Orig a Dest
//3. mover n-1 discos Temp a Dest
import java.util.Scanner;


class Hanoi{ //es el main 

    public static void hanoi(int n, String orig, String dest, String temp){ //metodo, investigar caso de valores por referencia 
        if (n> 0){
            //System.out.println("Mover "+ (n-1)+ "discos de "+orig+"al"+temp);
            hanoi(n-1, orig, temp, dest);
            System.out.println("Mueve el disco "+ n+ " de "+orig+ " a "+dest);
            //System.out.println("Mover "+ (n-1)+ "discos de "+temp+"al"+dest);
            hanoi(n-1, temp, dest, orig);
            
        }
        
    }
    public static void main(String[] args) { //ma y tap
        Scanner sc = new Scanner (System.in);
        int n = sc.nextInt();
        hanoi(n, "Torre A", "Torre C", "Torre B");

    }
}