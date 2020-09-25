import java.lang.Math;
import java.io.*;
import java.util.Scanner;
import javax.swing.JOptionPane;
public class juegofinal {

    public static void main (String[] args) throws IOException {
        String nombre;
        int numero;
        Scanner entrada = new Scanner(System.in);

        System.out.print("       ***                       ***\n");
        System.out.println("     ****   BIENVENIDO AL JUEGO  ****");
        System.out.println("     ****         A JUGAR          ****");
        System.out.print("       ***                       ***\n" );
        System.out.println("Por favor introduzca su nombre ");
        nombre = entrada.nextLine();

        String q1 = "La estructura de codigo _______ nos permite repetir la ejecucion de una secuencia de instrucciones\n" + " a) While\n b) Do while\n c) For";
        String q2 = "Un _________ es una variable cuyo valor se incrementa(++) o decrementa (–) en una cantidad constante\n" + " a) Acumulador\n b) Contador\n c) Ciclo";
        String q3 = "Un/Una ________ en Java es un conjunto de instrucciones definidas dentro de una clase\n" + " a) Metodo\n b) Centinela\n c) Entrada";
        String q4 = "Un ______ se utiliza para devolver un valor.\n" + " a) Void\n b) Programa\n c) Return";
        String q5 = "Una variable _______ es una asociación entre un nombre y un grupo de localidades.\n" + " a) Int\n b) Char\n c) Arreglo";
        String q6 = "Un arreglo de 2 dimensiones tambien es conocida como _______.\n" + " a) Agrupacion\n b) Matriz\n c) Secuencia";
        String q7 = "La estructura compañera de las matrices son dos ciclos de ________.\n" + " a) While\n b) For anidados\n c) Do while";
        String q8 = "Metodos que realizan un proceso y devuelven un valor basado en sus cálculos (en C son conocidos como ________).\n" + " a) Funciones\n b) Clases\n c) Procedimientos";
        String q9 = "Metodos que realizan un proceso y no devuelven un valor (en C son conocidos como ________)\n" + " a) Funciones\n b) Procedimientos\n c) Clases";
        String q10 = "Un _______ es el conjunto de clases, interfaces, recursos, etc para la construcción de gráficos de 2 dimensiones\n" + " a) Swing\n b) Pack\n c) JOptionPane"; 
    
        Pregunta[] preguntas = {
            new Pregunta (q1, "a"),
            new Pregunta (q2, "b"),
            new Pregunta (q3, "a"),
            new Pregunta (q4, "c"),
            new Pregunta (q5, "c"),
            new Pregunta (q6, "b"),
            new Pregunta (q7, "b"),
            new Pregunta (q8, "a"),
            new Pregunta (q9, "b"),
            new Pregunta (q10, "a"),    
        };
        puntuacion (preguntas);
    }

    public static void puntuacion (Pregunta [] preguntas) throws IOException {
        int opf;
        String nombre;
        int puntaje = 0;
        Scanner entrada = new Scanner(System.in);
        nombre = entrada.nextLine();
        for (int i = 0; i < preguntas.length; i++){
            System.out.println(preguntas[i].resp);
            String respuesta = entrada.nextLine();
            if (respuesta.equals(preguntas[i].respuesta)) {
            puntaje++;
            System.out.println("        ***");
            System.out.println("       ****");
            System.out.println("     ******");
            System.out.println(" *** **********");
            System.out.println(" *** **********");
            System.out.println(" *** *********");
            System.out.println(" *** ********");
            }else {
                System.out.println(" *** ********");
                System.out.println(" *** *********");
                System.out.println(" *** **********");
                System.out.println(" *** **********");
                System.out.println("     ******");
                System.out.println("       ****");
                System.out.println("        ***");
            }
        }
        System.out.println("Tu puntuaje fue: " + puntaje +" de "+ preguntas.length);
        if (puntaje>5){
            main1 ();
        }else{
        System.out.println("NO ALCANZO EL PUNTAJE PARA PASAR AL MUNDO 2");
        System.out.println("Juegue en el Mundo 1 otra vez");
        System.out.println("MUCHA SUERTE!!");
        System.out.println("");
        System.out.println("1. Desea jugar otra vez?");
        System.out.println("2. SALIR");
        opf=entrada.nextInt();
        if (opf==1){
            main (null);
        }else { /*
System.out.println("           ____________________________          ");
System.out.println("   ________|  ____   _____    _   _    |_______   ");
System.out.println("   \       |  |__      |      |\  |    |      /    ");
System.out.println("    \      |  |      __|__    | \_|    |     /      ");
System.out.println("    /      |___________________________|     \       ");
System.out.println("  _/__________)                    (__________\_     ");*/
            }
        }
    }
        //comienza el juego del gato
        //metodos
        public static String impr_tablero(String juego[][], String tablero){
            System.out.println("   0   1   2");
            System.out.println("0 "+juego[0][0]+" | "+juego[0][1]+"  | "+juego[0][2]);
            System.out.println("  ___________");
            System.out.println("1 "+juego[1][0]+" | "+juego[1][1]+"  | "+juego[1][2]);
            System.out.println("  ___________");
            System.out.println("2 " +juego[2][0]+" | "+juego[2][1]+"  | "+juego[2][2]);
            return tablero;
        }
        public static void maq_victoria(String juego[][], int n){
            if (juego[0][0]== "o" && juego[0][1]== "o" && juego [0][2]== "o") {
                System.out.println("Lo lamento, perdio");
            }
            if (juego[1][0]== "o" && juego[1][1]== "o" && juego [1][2]== "o") {
                System.out.println("Lo lamento, perdio");
            }
            if (juego[2][0]== "o" && juego[2][1]== "o" && juego [2][2]== "o") {
                System.out.println("Lo lamento, perdio");
            }
            if (juego[0][0]== "o" && juego[1][0]== "o" && juego [2][0]== "o") {
                System.out.println("Lo lamento, perdio");
            }
            if (juego[0][1]== "o" && juego[1][1]== "o" && juego [2][1]== "o") {
                System.out.println("Lo lamento, perdio");
            }
            if (juego[0][2]== "o" && juego[1][2]== "o" && juego [2][2]== "o") {
                System.out.println("Lo lamento, perdio");
            }
            //diagonales faltan
            if (juego[0][0]== "o" && juego[1][1]== "o" && juego [2][2]== "o") {
                System.out.println("Lo lamento, perdio");
            }
            if (juego[0][2]== "o" && juego[1][1]== "o" && juego [2][0]== "o") {
                System.out.println("Lo lamento, perdio");
            } else System.out.print("");
        }

        public static void jug_victoria(String juego[][], int n){
            if (juego[0][0]== "x" && juego[0][1]== "x" && juego [0][2]== "x") {
                System.out.println("Felicidades, gano");
            }
            if (juego[1][0]== "x" && juego[1][1]== "x" && juego [1][2]== "x") {
                System.out.println("Felicidades, gano");
            }
            if (juego[2][0]== "x" && juego[2][1]== "x" && juego [2][2]== "x") {
                System.out.println("Felicidades, gano");
            }
            if (juego[0][0]== "x" && juego[1][0]== "x" && juego [2][0]== "x") {
                System.out.println("Felicidades, gano");
            }
            if (juego[0][1]== "x" && juego[1][1]== "x" && juego [2][1]== "x"){
                System.out.println("Felicidades, gano");
            }
            if (juego[0][2]== "x" && juego[1][2]== "x" && juego [2][2]== "x"){
                System.out.println("Felicidades, gano");
            }
            //diagonales faltan
            if (juego[0][0]== "x" && juego[1][1]== "x" && juego [2][2]== "x") {
                System.out.println("Felicidades, gano");
            }
            if (juego[0][2]== "x" && juego[1][1]== "x" && juego [2][0]== "x") {
                System.out.println("Felicidades, gano"); 
            } System.out.print(""); 

        }

        
        //main principal del gato
        public static void main1 () throws IOException {
            Scanner entrada =new Scanner(System.in);
            String juego[][];
            String maq_victoria, jug_victoria, victoria, victoria2;
            juego = new String[3][3];//matrices
            int n=0;
            int fila, columna, datob2;
        /*  System.out.println("            ________________________________________________" );
            System.out.println("   ________|  _____   _  _  _   _  ____    ___       ___    |_______" );
            System.out.println("   \       |  |\_/|   |  |  |\  |  |  _|  |   |      ___|   |      /" );
            System.out.println("    \      |  |   |   |__|  | \_|  |___|  |___|     |___    |     /" );
            System.out.println("    /      |________________________________________________|     \_");
            System.out.println("  _/__________)                                         (__________\_");
            System.out.println("");*/
            System.out.println("BIENVENIDO, A JUGAR"); 
            System.out.println("");
            for (int i=0; i<=2; i++ ) {
                for (int j=0; j<=2; j++){
                    juego[i][j]=" ";
                }
            }
            String tablero= " ";
            impr_tablero(juego, tablero);
            tablero = impr_tablero(juego, tablero);
            //tablero
            while (n<10) { //ciclo
                System.out.println("Es su tuno.");
                System.out.println("Fila:");
                fila = entrada.nextInt();
                System.out.println("Columna:");
                columna = entrada.nextInt();
                 //comprobar si la jugada existe
                while (juego[fila][columna]== "x" || juego[fila][columna]== "o" ) { 
                    //comparacion
                    System.out.println("Pruebe con otra jugada");
                    System.out.println("Fila:");
                    fila = entrada.nextInt();
                    System.out.println("Columna:");
                    columna = entrada.nextInt();
                }//termina el 2 while
                juego[fila][columna] = "x";
                impr_tablero(juego, tablero);
                tablero = impr_tablero(juego, tablero);
                System.out.println("" +tablero);
                n=n+1;
                System.out.println("Turno de la computadora");
                System.out.println("Fila:");
                int datob;
                datob = (int)(Math.random()*3)+0;
                System.out.println("Columna:");
                datob2 = (int)(Math.random()*3)+0;
                System.out.println("Numeros elegidos "+datob+" segundo"+datob2);
                //comprobar si la jugada existe
                while (juego[datob][datob2]== "o" || juego[datob][datob2]== "x" ) {
                    System.out.println("Turno de la computadora");
                    datob = (int)(Math.random()*3)+0;
                    datob2 = (int)(Math.random()*3)+0;
                }//fin del while
                juego[datob][datob2] = "O";
                // jugador O
                //MENSAJES DE TU TURNO CON DIALOG
                //llama al metodo tablero
                impr_tablero(juego, tablero);
                tablero = impr_tablero(juego, tablero);
                System.out.println("" +tablero);
                n=n+1;//cantidad de jugadas permitidas
                //VICTORIA
                jug_victoria(juego, n);
                maq_victoria(juego, n);
                } 
                JOptionPane.showMessageDialog(null, "GAME OVER", "MUNDO 2", JOptionPane.INFORMATION_MESSAGE);

            }
        public static void premios (){
        int premio;
        System.out.println("FELICIDADES PUEDES ESCOGER TU PREMIO");
        System.out.println ("      **        ****************      ");
        System.out.println ("     *  *        *****_♛_*****     ");
        System.out.println ("     *  *         ***********     ");
        System.out.println ("     ****             ***            ");
        System.out.println ("    ******            ***                 ");
        System.out.println ("   ***♛***           ***       ");
        System.out.println ("1.  ******   2.   ***********       ");
        Scanner entrada;
        premio = entrada.nextInt();
        if (premio==1)
        System.out.println("Felicidades ya tienes una medalla!");
        else 
        System.out.println("Felicidades ya tienen un trofeo!");


        }


    }

    
    
