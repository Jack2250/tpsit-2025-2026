/*Esercizio – Preparazione verifica
Scrivere un programma in C che dopo aver dichiarato una struttura denominata Persona con i
seguenti campi: Nome, Cognome, età, codice fiscale, reddito annuo, anno_nascita,residenza(città) ;
determini:
1) La persona con reddito annuo più alto e quella con reddito annuo più basso.Visualizzare
per entrambe: nome, cognome, città e reddito.
2) Ordinare la lista delle persone in base all’anno di nascita** (dal più anziano al più
giovane), e visualizzarla.
3) Consentire all’utente di cercare una persona inserendo il codice fiscale..
4) Visualizzare tutte le persone con reddito superiore o uguale a un valore scelto dall’utente.
5) Calcolare la media dei redditi delle persone registrate nel sistema.
6) Visualizzare tutte le persone nate in un anno specifico, scelto dall’utente;
7) Visualizzare l'elenco delle persone raggruppate per città di residenza, indicando per
ciascuna città: Quante persone vi risiedono, L’età media dei residenti
*/

#include <stdio.h>

    struct Persona{
    char nome [50];
    char cognome [50];
    int eta;
    char codiceFiscale[17];
    int redditoAnnuo;
    int annoNascita;
    char citta [50];
    };

void inserimento(struct Persona p[], int nPersone){
    for(int i = 0; i<nPersone; i++){
        printf("Inserisci la %d persona\n", i+1);
        printf("Nome: ");
        scanf("%s",p[i].nome);
        printf("\nCognome: ");
        scanf("%s",p[i].cognome);
        printf("\nEtà: ");
        scanf("%d",p[i].eta);
        printf("\nCodice Fiscale: ");
        scanf("%s",p[i].codiceFiscale);
        printf("\nReddito annuo: ");
        scanf("%d",p[i].redditoAnnuo);
        printf("\nAnno di nascita: ");
        scanf("%d",p[i].annoNascita);
        printf("\nCittà: ");
        scanf("%s",p[i].citta);
    }
}

    int main(){
        int uscita = 0;
        int scelta, nPersone;
        struct Persona collezionePersone[10];
    do{
        printf("1.Inserimento Persone \n2.Visualizza Persone \n3.Visualliza reddito annuo più alto e piùà basso \n4.Ordina in base all'anno di nascita (dal più anziano) \n5.Cerca persona tramite codice fiscale \n6.Visualizza persone in base al reddito \n"); 
        printf("7.Calcolo media dei redditi \n8.Visualizza persone in base al reddito \n9.Opzionale \n10.Uscita \n");
        printf("Quale operazione vuoi eseguire? \n");
        scanf("%d",&scelta);
        
    switch(scelta){
    case 1:
        printf("Quante persone vuoi inserire?");
        scanf("%d",&nPersone);
        inserimento(collezionePersone, nPersone);
    break;
    
    case 2:
        
    break;
    
    case 3:
        
    break;
        
    case 4:
        
    break;
        
    case 5:
        
    break;
        
    case 6:
        
    break;
    
    case 7:
        
    break;
        
    case 8:
    
    break;
        
    /*case 9:
        
    break;
    }*/
        
    case 10:
    uscita = 1;
    printf("Uscita in corso..");
    break;
    }
    }while(uscita == 0);
    
        
    return 0;
    
}
