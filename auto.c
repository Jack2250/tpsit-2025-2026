/*Esercizio - Strutture
Scrivere un programma in C che dopo aver dichiarato una struttura denominata Auto con i seguenti
campi: ModelloAuto, marca, cilindrata, prezzo, anno_immatricolazione, targa; determini:
1) Il prezzo + alto e quello + basso visualizzando anche il modello dell&#39;auto;
2) Ordinare la lista delle auto in base all&#39;anno d&#39;immatricolazione;
3) Visualizzare il nome delle auto a partire da un prezzo scelto dall&#39;utente.
4) Ricerchi un Auto scelta dall’utente (utilizzare il campo targa): visualizzando tutti i campi;
5) La media dei prezzi delle auto inserite;
6) Visualizzare le Auto con anno di immatricolazione scelto dall’utente;
*/

#include <stdio.h>

struct Auto{
    char modelloAuto[50];
    char marca[50];
    int cilindrata;
    double prezzo;
    int annoImmatricolazione;
    char targa[7];
};

void inserimentoAuto(struct Auto a, int nAuto){
    for(int i = 0;i< nAuto; i++){
        printf("Inserimento auto");
        printf("Inserisci il modello dell'auto");
    }
}

int main(){
    int nAuto;
    printf("Quante auto vuoi inserire?");
    scanf("%d",&nAuto);
    struct Auto collezioneAuto [nAuto];
    inserimentoAuto(collezioneAuto, nAuto);
    return 0;   
}
