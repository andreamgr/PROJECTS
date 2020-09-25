import java.util.Scanner;
import java.lang.Math;
public class areas1 {
    public static void main(String [] args){
        int num;
        Double  radio, area1, area2, area3, area4, altura, base;
        Scanner entrada =  new Scanner(System.in);
        System.out.println(" 1. Calcular area de un circulo\n 2. Calcular area de un triangulo\n 3. Calcular area de un rectangulo\n 4. Calcular area de un cilindro\n");
        System.out.println("Introduzca el numero del area que desea calcular");
        num = entrada.nextInt();
        switch (num)
        {
            case 1: 
            System.out.print("Digite el radio \n");
            radio =entrada.nextDouble();
            area1= Math.PI * (radio *radio);
            System.out.println("El area del circulo es: "+ area1);
            break;

            case 2: 
            System.out.print("Digite la base \n");
            base =entrada.nextDouble();
            System.out.print("Digite la altura \n");
            altura =entrada.nextDouble();
            area2= (base * altura) / 2;
            System.out.println("El area del triangulo es: "+ area2);
            break;

            case 3: 
            System.out.print("Digite la base \n");
            base =entrada.nextDouble();
            System.out.print("Digite la altura \n");
            altura =entrada.nextDouble();
            area3= (base * altura);
            System.out.println("El area del rectangulo es: "+ area3);
            break;

            case 4:
            System.out.print("Digite la altura \n");
            altura =entrada.nextDouble();
            System.out.print("Digite el radio \n");
            radio =entrada.nextDouble();
            area4= 2 * Math.PI* (radio * altura) + Math.PI * (radio * radio);
            System.out.println("El area del cilindro es: "+ area4);
            break;
            
            default: System.out.println("Opcion invalida");
        }


    }
}