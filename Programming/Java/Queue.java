
import java.util.LinkedList;
import java.util.Queue;
class Queue{

   private LinkedList cola;

    public Queue(){
        this.cola = new LinkedList();

    }
    public void offer (Object e){
        this.cola.offer(e);

    }
    public void pool(){
        this.cola.pool();

    }
    public void cargar(){
       Random r = new Random() ;
       for (int i =0; i<= 10; i++){
           offer (r.nextInt(50));
       }
    }
    public void Mostrar_todos(){
        for(int i= 0; i< cola.size(); i++){
            cola.get(i);
        }
    }
      

   

}