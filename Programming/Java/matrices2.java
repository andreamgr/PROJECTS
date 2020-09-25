import java.util.Scanner;
import java.lang.Math;
class matrices2 {
    static Scanner entrada = new Scanner (System.in);
    static int i,j;

    public static void llena (float a[][]) {
        float numero;
        System.out.println("Dame los datos del arreglo");
        for (i=0; i<5; i++) 
            for (j=0; j<4; j++){
                numero =(float) (Math.random()* 10 )+1;
                a[i][j]= numero;
            }

}

    public static void imprime (float a[][]){
    System.out.println("Arreglo lleno");
        for (i=0; i<5; i++){
            for (j=0; j<4; j++){
                System.out.printf("\t %.2f", a[i][j]); //para poner decimales 
            }
                System.out.println("");
        }
    }

    public static void diagonal (float a[][]){
            for (i=0; i<5; i++){
                for (j=0; j<4; j++){
                    if (i==j)
                    System.out.printf("\t %.2f", a[i][j]); 
                }
                    System.out.println("");
            }
    }

    public static void minimo (float a[][]){
        float min=a[0][0];
        for (i=0; i<5; i++)
            for (j=0; j<4; j++){
                if (a[i][j]<min)
                min = a[i][j];
            }
        
        System.out.printf("El minimo es: %.2f",min);
        System.out.println();
}


    public static void maximo (float a[][]){
        float max=a[0][0];
        for (i=0; i<5; i++){
            for (j=0; j<4; j++){
                if (a[i][j]>max)
                max = a[i][j];
        }
    }
    System.out.printf("El maximo es: %.2f \n",max);
}

public static void Transpuesta (float a[][]){
        for (j=0; j<5; j++){
            for (i=0; i<4; i++){
                System.out.printf("\t %.2f", a[i][j]); 
            }
                System.out.println("");
        }
    }




public static void main (String []args) {
    
    float a[][]=new float [5][4];
    int op=0;
    while (op != 7){
        System.out.println("Selecciona una opcion");
        System.out.println(" 1.Llena \n 2.Imprime  \n 3.Diagonal  \n 4.Minimo \n 5.Maximo \n 6.Transpuesta \n 7.Salir");
        op = entrada.nextInt();
        switch (op){
            case 1: llena (a); 
            break;
            case 2: imprime (a);
            break;
            case 3: diagonal (a);
            break;
            case 4: minimo (a);
            break;
            case 5: maximo (a);
            break;
            case 6: Transpuesta (a);
            break; 
            default: System.out.println("Opcion no valida");

        }
    }
}
}
