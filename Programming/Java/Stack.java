class Stack{





    
    ////////
    int Stack[];
    int top;
    int maxSize;

    Stack(int n){
        maxSize = n;
        Stack = new int[maxSize];
        top = 0 ;

    }
    void push (int n){
        if (top < maxSize){
            Stack[top] = n;
            top ++;
        }
    }
    void print (){
        for (int i = top-1; i>= 0; i--)
        System.out.println(i+ "|"+ Stack[i]+"|");
    }
}
