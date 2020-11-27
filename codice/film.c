// gestione FILM
// rinominare in main.c

#include <stdio.h>
#include <string.h>


typedef struct new_movie {
    char title[200];
    char type[200];
    int year;
} movie;


#define MAX_FILMS 100

// prototipi:

int add(movie f[],int numFilm); //chiede i dati per un nuovo film, lo aggiunge nella posizione corretta e restituisce il numero di film aggiornato.

void print(movie f[],int numFilm); //stampa la lista dei film.

movie search(movie f[],int numFilm, char * title); //cerca un film nella lista in base al titolo e restituisce l’elemento dell’array che contiene tale film.

int delete(movie f[],int numFilm,char * title); //rimuove un film senza lasciare buchi e restituisce il numero di film aggiornato.

int main() {

    int numFilm=0;

    movie film[MAX_FILMS];
    int i;
    
    for (i=0; i<6; i++) {
        numFilm = add(film, numFilm);
    }
    print(film, numFilm);
    
    printf("Done!\n");
    printf("cerco Bonny e Clyde \n");
    movie m = search(film , numFilm, "Bonnie and Clyde");
    printf("trovato :%s lo cancello \n",m.type);
    
    numFilm=delete(film , numFilm, "Bonnie and Clyde");
    printf("ora i film sono ...%d \n",numFilm);
    print(film, numFilm);
    return 0;
}

// fake f. add per testare velocemente:


movie fakeReadMovie(){
    static int presi = 0;
    movie films[MAX_FILMS] = {
        {"The Seven Samurai", "guerra", 1954},
        { "Bonnie and Clyde", "gangster", 1967},
        { "Reservoir Dogs", "dramma", 1992},
        { "Airplane!", "comico" , 1980},
        { "Pan's Labyrinth!", "mith" , 2006},
        {"Doctor Zhivago", "drama", 1965},
    };
    movie m = films[presi];
    presi++;
    return m;
}

// f. di appoggio: se array per definizione ordinato, cerco con FOR dove inserirlo:
int posizInserimento(int anno, movie f[], int numFilm){
    int i;
    for (i=0; i<numFilm; i++) {
        if  (anno <f[i].year){
            return i;
        }
    }
    return numFilm;

}
// f. di appoggio:
// un array e' cmq un array di puntatori.. non mi serve dire da dove... gli passo quello corretto..
// ma attenzione al  numero elemewnti!
// ma devo partire dal FONDO
// per ipotesi (vedi la add) gia ho testato che HO SPAZIO in fondo.
void scalaInSu(movie f[], int numFilm){
    int i;
    
    //printf("\n========\n");
    //print(f, numFilm);

    for (i=0; i<numFilm; i++) {
        f[numFilm-i] = f[numFilm-i-1];
    }
    //print(f, numFilm+1);
}

int add(movie f[],int numFilm) //chiede i dati per un nuovo film, lo aggiunge nella posizione corretta e restituisce il numero di film aggiornato.
{
    if (numFilm == MAX_FILMS-1){
        printf("al max! impossibile aggiungere\n");
        return numFilm;
    }

    // chiamata reale:
    //movie m = readMovie();
    
    // fake x testare:
    movie m = fakeReadMovie();

    int nuovaPos = posizInserimento(m.year, f, numFilm);
    
    if (nuovaPos == numFilm){
        f[numFilm] = m;
    }else{
        scalaInSu(f+nuovaPos, numFilm-nuovaPos);
        f[nuovaPos] = m;
    }

    // x testare:
    print(f, numFilm+1);

    return numFilm+1;
}

// f. di "apppoggio": stampa singolo film:
void printFilm(movie f)
{
    printf("%-20s %-20s %5d\n", f.title, f.type, f.year );
}

void print(movie f[],int numFilm) //stampa la lista dei film.
{
    printf("\n-------\n");
    int i;
    for (i=0; i<numFilm; i++) {
        printFilm(f[i]);
        
    }
}
movie search(movie f[],int numFilm, char *title)
//cerca un film nella lista in base al titolo e restituisce l’elemento dell’array che contiene tale film.
{
    movie m = {"","",0};
    
    int i;
    for (i=0; i<numFilm; i++) {
        
        if (strcmp(f[i].title,title)==0)
            m =f[i];
        }
    return m;
}

//rimuove un film senza lasciare buchi e restituisce il numero di film aggiornato.
int delete(movie f[],int numFilm,char * title)
{
    int i=0,j;
    
    for (i=0; i<numFilm; i++) {
        if (strcmp(f[i].title,title)==0)
            break;
    }
    printf("trovato %d %s\n", i,f[i].type);
    // quando esco dal ciclo i si è incrementato di 1
    
    for (j=i; j<numFilm; j++) {
        f[j] = f[j+1];
    }
    return numFilm-1;

}
