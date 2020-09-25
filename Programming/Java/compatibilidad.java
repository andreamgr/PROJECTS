import java.util.Scanner;
public class compatibilidad {
    public static void main(String [] args){
        int num, num1, num2, num3, num4;
        Scanner entrada =  new Scanner(System.in);
        System.out.println("TEST DE COMPATIBILIDAD");
        System.out.println("1.¿Cual es su comida preferida?");
        System.out.println(" 1.Pizza\n 2.Sushi\n 3.Mole\n 4.Chile en nogada\n 5.Chilaquiles");
        System.out.println("Digite su opcion");
        num = entrada.nextInt();
        switch (num)
        {
            case 1: System.out.println("2.¿Que deporte prefiere?");
            System.out.println(" 1.Atletismo\n 2.Patinaje\n 3.Futbol\n 4.Basquetbol\n 5.Box");
            System.out.println("Digite su opcion");
                num1 = entrada.nextInt();
                switch (num1)
                {
                   
                    case 2: System.out.println("3.¿Que prefiere hacer?");
                    System.out.println(" 1.Leer\n 2.Salir con amigos\n 3.Comer\n 4.Viajar\n 5.Ir al cine");
                    System.out.println("Digite su opcion");
                    num2 = entrada.nextInt();
                    switch (num2)
                    {
                        case 4: System.out.println("4.¿Que pais prefiere conocer?");
                        System.out.println(" 1.Grecia\n 2.Italia\n 3.Argentina\n 4.Alaska\n 5.Australia");
                        System.out.println("Digite su opcion");
                        num3 = entrada.nextInt();
                        switch (num3)
                        {
                            case 4: System.out.println("5.¿Que sabor de helado prefiere?");
                            System.out.println(" 1.Vainilla\n 2.Chocolate\n 3.Fresa\n 4.Galleta\n 5.Chocomenta");
                            System.out.println("Digite su opcion");
                            num4 = entrada.nextInt();
                            switch (num4)
                
                            {
                                case 3: System.out.println("¡Felicidades es 100% compatible!");
                                break;
                                case 1:
                                case 2:
                                case 4:
                                case 5: System.out.println("Es casi compatible, tiene un porcentaje de 80% de compatibilidad");
                                        break;
                                        default: System.out.println("El numero no es valido ");

                            }
                            case 1:
                            case 2:
                            case 3:
                            case 5: System.out.println("Lo lamento no es tan compatible, tiene un porcentaje de 60% de compatibilidad");
                                    break;
                                    default: System.out.println("El numero no es valido ");

                        }
                        case 5:
                        case 3:
                        case 2:
                        case 1: System.out.println("Lo lamento es poco compatible, tiene un porcentaje de 40% de compatibilidad");
                                break;
                                default: System.out.println("El numero no es valido ");


                    }
                    case 1:
                    case 3:
                    case 4:
                    case 5:System.out.println("Lo lamento es muy poco compatible, tiene un porcentaje de 20% de compatibilidad");
                            break;
                            default: System.out.println("El numero no es valido ");


                }
            case 2: 
            case 3: 
            case 4:
            case 5: System.out.println("Lo lamento no es compatible, tiene un porcentaje de 0% de compatibilidad");
                    break;
                    default: System.out.println("El numero no es valido ");
        }


    }
}