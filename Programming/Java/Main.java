
import java.util.Scanner;
import java.util.Stack;
import java.util.Queue;

class Main {
    public static void main (String [] args ){
        
       

        Queue q = new Queue();
        q.cargar();
        System.out.println(q.Mostrar_todos());


        int num_stack;
        int oper; 
        Scanner sc = new Scanner(System.in);
        //System.out.println("Cantidad de la pila");
        num_stack = sc.nextInt();

       // System.out.println("digite las operaciones");
        for(int i=1; i<=num_stack; i++){
            oper = sc.nextInt();
        }
        

        //push añadir elemento 
        //pop sacar el ultimo 
        //peek ver el ultimo 
        //empty 


        
    }
}