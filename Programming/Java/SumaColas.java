import java.util.Collections;
import java.util.LinkedList;
import java.util.Queue;

public class SumaColas{
    public static void main (String[] args){
        LinkedList cola = new LinkedList<>();
        cola.push(8);
        cola.push(23);
        cola.push(3);

        int suma = 0;

        while (cola.size() >0 )
        suma += (int) cola.poll();
        System.out.print("La suma es "+ suma);
        
    }
}