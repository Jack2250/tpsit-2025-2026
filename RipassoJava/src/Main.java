/*Esercizio: Gestore di Testi

GestoreTesti deve fare le seguenti cose:
-verificare la lunghezza della frase;
-verificare se è presente una parola (es. "Ciao mondo", cerca mondo);
-sostituire di una parola (es. "Ciao mondo", sostituisci mondo con Luca);
-conteggio vocali e consonanti;
-invertire una frase (es. "ciao", "oaic");
-estrarre una porzione di frase (.subString());
-tornare al menu principale;
-uscire dal programma.
 */

import java.util.Scanner;

import Utility.Tools;

public class Main {
    public static void main(String[] args) {
        boolean esci = true;
        Scanner sc = new Scanner(System.in);
        String[] opzioni = {"Gestore Testi", "Inserisci Frase", "Visualizza lunghezza frase", "Verifica se è presente una parola", "Sostituisci parola",
                "Conta vocali e consonanti", "Inverti frase", "Estrai una porzione di frase", "Esci"};

        do {
            System.out.println("Quale operazione vuoi eseguire?");
            int scelta = Tools.Menu(opzioni, sc);

            switch (scelta) {
                case 1 -> {

                }
                case 2 -> {
                }
                case 3 -> {

                }
                case 4 -> {

                }
                case 5 -> {

                }
                case 6 -> {

                }
                case 7 -> {

                }
                case 8 -> {
                    System.out.println("Uscita in corso");
                    esci = false;
                }
            }

        } while (esci);
    }
}