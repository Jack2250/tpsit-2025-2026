import java.util.Scanner;

public class GestoreTesti {
    public String inserisciFrase(Scanner sc) {
        String frase;
        return frase = sc.nextLine();
    }

    public int lunghezzaFrase(String frase) {
        return frase.length();
    }

    public int cercaParola(String frase, String parola) {
        if (frase.contains(parola))
            return frase.indexOf(parola);

        return -1;
    }

    public String sostituisciParola(String frase, String parola, Scanner sc) {
        System.out.println("Quale parola vuoi scrivere");
        parola = sc.nextLine();
        return frase.replace("frase", "parola");
    }

    public void convertiInMinuscolo(String frase) {
        frase = frase.toLowerCase();
    }

    public int contaVocali(String frase) {
        convertiInMinuscolo(frase);
        int contaVocali = 0;
        for (int i = 0; i < frase.length(); i++) {
            if (frase.charAt(i) == 'a' || frase.charAt(i) == 'e' || frase.charAt(i) == 'i' || frase.charAt(i) == 'o' || frase.charAt(i) == 'u') {
                contaVocali++;
            }
        }
        return contaVocali;
    }

    public int contaConsonanti(String frase) {
        convertiInMinuscolo(frase);
        int contaConsonanti = 0;
        for (int i = 0; i < frase.length(); i++) {
            if (frase.charAt(i) != 'a' && frase.charAt(i) != 'e' && frase.charAt(i) != 'i' && frase.charAt(i) != 'o' && frase.charAt(i) != 'u') {
                contaConsonanti++;
            }
        }
        return contaConsonanti;
    }

    public String invertiFrase(String frase) {
        String stringaInvertita = "";

        for (int i = 0; i < frase.length(); i++) {
            stringaInvertita = frase.charAt(i) + stringaInvertita;
        }

        return stringaInvertita;
    }

    public String estraiPorzioneDiFrase(String frase, Scanner sc) {
        System.out.println("Da quale posizione vuoi estrarre la stringa?");
        int posizione = sc.nextInt();
        return frase.substring(posizione);
    }
}