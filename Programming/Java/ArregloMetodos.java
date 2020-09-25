import java.util.Scanner;
public class ArregloMetodos {

    public static void leerArreglo (double A[], int NUM){
        Scanner entrada = new Scanner(System.in);
        System.out.println("Dame los datos de A");
        for (int i=0; i<NUM; i++)
            A[i] = entrada.nextDouble();

    }

    public static void imprimePositivos (double A[], int NUM){
        for (int i=0; i<NUM; i++){
            if(A[i]>0)
            System.out.println("El valor " +A[i]+ " es prositivo");
        }
    }

    public static void imprimeNegativos (double A[], int NUM){
        for (int i=0; i<NUM; i++){
            if(A[i]<0)
            System.out.println("El valor " +A[i]+ " es negativo");
        }

    }


    public static void main(String[] arg){
        int NUM = 10;
        double  A[] = new double [NUM];
        leerArreglo(A, NUM);
        imprimePositivos(A, NUM);
        imprimeNegativos(A, NUM);

    }
}