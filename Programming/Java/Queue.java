public class Queue{
	//circular queue
	private static final int MAX_SIZE = 1024;
	private char[] queue;
	private int front;
	private int rear;
	private int close = 0;
	private int open = 0;

	public Queue(int capacity){
		queue = new char[capacity];
		front = 0; 
		rear = MAX_SIZE -1;
	}

	private int next(int r){
		return (r+1) % MAX_SIZE;
	}

	public void enqueue(char c) {
		if (!isFull()){
			check(c);
			rear = next(rear);
			queue[rear] = c;
		}
		else{
			throw new ArrayIndexOutOfBoundsException();
		}

	}

	public char dequeue() {
		if (!isEmpty()){
			char tm = queue[front];
			front = next(front);
			return tm;
		}
		else{
			throw new ArrayIndexOutOfBoundsException();
		}
	}

	public int size(){
		int size  = rear-front;
		return size;
	}

	public void cleanQueue(){
		front = 0;
		rear = MAX_SIZE - 1;
	}

	public char frontQ(){
		if (!isEmpty()){
			return queue[front];
		}
		else{
			throw new ArrayIndexOutOfBoundsException();
		}
	}

	public boolean isEmpty(){
		return front == next(rear);
	}

	public boolean isFull(){
		return front == next(next(rear));
	}

	public void printQueue(){
		if(!isEmpty()){
			for (int i= front; i<= rear; i++){
				System.out.println(queue[i]);
			}
		}
	}

	public void check(char c){
		if(c == '[' ||c == '{' ||c == '('){
			open++;
		}
		else{
			close++;
		}
		if(close > open){
			throw new ArithmeticException();
		}
	}
}