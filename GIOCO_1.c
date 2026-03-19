#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

/**FUNZIONE PER ESEGUIRE LO  SCAMBIO DELLE FACCE DELE TESSERE-->PRENDE
COME PARAMETRI IL PIANO DI GIOCO E LA TESSERA SCELTA DAL GIOCATORE**/
void change(int (*D)[][2], int *p)
{
    int swap;
    swap = (*D)[*p][0];
    (*D)[*p][0] = (*D)[*p][1];
    (*D)[*p][1] = swap;
}

/**FUNZIONE CHE PRENDE COME PARAMETRI:
 * ARRAY_APPO= ARRAY DELLE MIE TESSERE ;
 * ARRAY_APPO_1=ARRAY CAMPO DEL GIOCO;
 * POSIZIONE SCELTA DAL GIOCATORE;
 * SCELATA DELLA TESSERA ;
 * POSIZIONE LIBERA PER LA PROSSIMA MOSSA*/
int Check_Inserimento(int Array_appo[][2], int Array_appo_1[][2], int *posizone_1, int *Choice_1, int free_place)
{
    if (*posizone_1 == 0)
    {
        if (Array_appo[*Choice_1][1] == Array_appo_1[0][0])
            return 1;
    }
    else if (*posizone_1 == free_place - 1 && free_place > 1)
    {
        if (Array_appo[*Choice_1][0] == Array_appo_1[free_place - 2][1] && Array_appo[*Choice_1][1] == Array_appo_1[free_place - 1][0])
            return 1;
    }
    else if (*posizone_1 == free_place)
    {
        if (Array_appo[*Choice_1][0] == Array_appo_1[free_place - 1][1])
            return 1;
    }

    return 0;
}
/**FUNZIONE CHE PRENDE COME PARAMETRI :
 * DIM--> arry delle tessere;
 * ARRAY delle tessere del gioco;
 * SCELTA DELLA TESSERA DEL GIOCATORE;
 * LA POSIZIONE LIBERA DELLA PROSSIMA MOSSA;
 */
void Keep_UP(int dim, int (*Arr_2)[][2], int *choic_1, int free_1)
{
    int k = (*Arr_2)[free_1][0];
    int k_1 = (*Arr_2)[free_1][1];
    (*Arr_2)[free_1][0] = (*Arr_2)[*choic_1][0];
    (*Arr_2)[free_1][1] = (*Arr_2)[*choic_1][1];
    (*Arr_2)[*choic_1][0] = k;
    (*Arr_2)[*choic_1][1] = k_1;
}

/**Funzione controlla esistenza mosse per posizione attuale */
/**int AArr= array delle mie tessere
 * int AArr_1 =array del piano gioco
 * int posizione = posizione dove inserire la prossima tessera
 * int spostamneto = posizone da dove inziare a contare le tessere per il check
 */
int Mossa1(int dim, int (*AArr)[][2], int (*AArr_1)[][2], int spostamneto, int posizione_corrente)
{
    if (posizione_corrente > 1)
    {
        for (int i = spostamneto; i <= dim - 1; ++i)
        {
            if ((*AArr)[i][0] == (*AArr_1)[posizione_corrente - 1][1])
                return 1;
            else if ((*AArr)[i][1] == (*AArr_1)[posizione_corrente - 1][1])
                return 1;
            else if ((*AArr)[i][0] == (*AArr_1)[posizione_corrente - 2][1] && (*AArr)[i][1] == (*AArr_1)[posizione_corrente - 1][0])
                return 1;
            else if ((*AArr)[i][1] == (*AArr_1)[posizione_corrente - 2][1] && (*AArr)[i][0] == (*AArr_1)[posizione_corrente - 1][0])
                return 1;
            else if ((*AArr)[i][0] == (*AArr_1)[0][0])
                return 1;
            else if ((*AArr)[i][1] == (*AArr_1)[0][0])
                return 1;
        }
    }
    if (posizione_corrente <= 1)
    {
        for (int i = spostamneto; i <= dim - 1; ++i)
        {
            if ((*AArr)[i][0] == (*AArr_1)[0][1])
                return 1;
            else if ((*AArr)[i][1] == (*AArr_1)[0][1])
                return 1;
            else if ((*AArr)[i][0] == (*AArr_1)[0][0])
                return 1;
            else if ((*AArr)[i][1] == (*AArr_1)[0][0])
                return 1;
        }
    }

    return 0;
}
/**FUNZIONE CHE MANDA A SCHERMO LA POSIZIONE DELLE TESSERE RIMANENTI 
PRENDE COME PARAMETRO LA POSIZIONE DEL PIANO DI GIOCO LIBERA E LA DIM DELL PIANO DEL GIOCO STAMPA LE POSIZIONI SUCCESSIVE  */
void POISZIIONE_Tess(int pos, int dim)
{
    while (pos <= dim)
    {
        printf("<%d>\t", pos);
        ++pos;
    }
}
/**FUNZIONE CHE MANDA A SCHERMO LA POSIZIONE DELLE TESSERE  **/
void POISZIIONE_Tess_1(int pos, int dim)
{
    while (pos <= dim - 1)
    {
        printf("<%d>\t", pos);
        ++pos;
    }
}
void TESS_Up(int pp)
{
    /**FUNZIONE CHE MANDA A SCHERMO LA POSIZIONE DELLE TESSERE INSERITE DAL GIOCATORE (AGGIORNATE)**/
    for (int L = 0; L <= pp - 1;)
    {
        printf("<%d>\t", L);
        ++L;
    }
}
void diviorio()
{
    /**FUNZIONE DIVISORIO : divide il piano di gioco dalle tessere rimanenti **/
    for (int qg = 0; qg <= 10; ++qg)
    {
        printf("_____");
    }
    printf("\n");
}

/**Funzione Print_TE*/
/**STAMPA LE TESSERE  INSERITE DAL GIOCATORE AGGIORNATE MOSSA PER MOSSA**/
/** I PARAMETRI SONO LE TESSERE INSERITE PRECEDENTEMENTE FINO ALLA POSIZONE LIBERA -1 */
void Print_TE(int Arr_te[][2], int g)
{
    for (int x = 0; x < g; ++x)
    {
        printf("[%d,%d]\t", Arr_te[x][0], Arr_te[x][1]);
    }
}

/**Funzione Print_TE_1*/
/**STAMPA LE TESSERE  INSERITE DAL GIOCATORE AGGIORNATE MOSSA PER MOSSA**/
/** I PARAMETRI SONO LE TESSERE INSERITE PRECEDENTEMENTE FINO ALLA POSIZONE LIBERA -1 */

void Print_TE_1(int (*Arr_te)[][2], int g)
{
    for (int x = 0; x <= g; ++x)
    {
        printf("[%d,%d]\t", (*Arr_te)[x][0], (*Arr_te)[x][1]);
    }
}

/**FUNZIONE CHE PRENDE IL CAMPO DA GIOCO E INSERISCE LA TESSERA DEL GIOCATORE NELLA POSIZIONE SCELTA DAL GIOCATORE
 * Check= posizione scelta dal giocatore
 * free  place = posizione libera dove mettere la tessera
 * array_appo =Campo da gioco
 */
void Effe_Inserimento(int (*Array_appo)[][2], int Array_p[][2], int *Check_1, int Choice_1, int free_p)
{
    int k = 0;
    int k_1 = 0;
    if (*Check_1 == 0)
    {
        for(int i=0;i<free_p;++i){
         (*Array_appo)[free_p-i][0]=(*Array_appo)[free_p-i-1][0];
         (*Array_appo)[free_p-i][1]=(*Array_appo)[free_p-i-1][1];   
        }
        (*Array_appo)[0][0] = Array_p[Choice_1][0];
        (*Array_appo)[0][1] = Array_p[Choice_1][1];
    }

    if (*Check_1 == free_p - 1&&free_p>1)
    {
        (*Array_appo)[free_p][0] = (*Array_appo)[free_p - 1][0];
        (*Array_appo)[free_p][1] = (*Array_appo)[free_p - 1][1];
        (*Array_appo)[free_p - 1][0] = Array_p[Choice_1][0];
        (*Array_appo)[free_p - 1][1] = Array_p[Choice_1][1];
    }
    if (*Check_1 == free_p)
    {
        (*Array_appo)[free_p][0] = Array_p[Choice_1][0];
        (*Array_appo)[free_p][1] = Array_p[Choice_1][1];
    }
}

/**FUNZIONE CHE STAMPA LE TESSERE  INSERITE DAL GIOCATORE AGGIORNATE MOSSA PER MOSSA
 * I PARAMETRI SONO LE TESSERE INSERITE PRECEDENTEMENTE FINO ALLA POSIZONE LIBERA -1 */
void CICL(int R[][2], int g)
{
    int x = 0;
    while (x <= g)
    {
        printf("[%d,%d]\t", R[x][0], R[x][1]);
        ++x;
    }
}

/**STAMPA LE TESSERE  RIMANENTI**/
/** I PARAMETRI SONO LE TESSERE DEL GIOCATORE STAMPATE DALLA POSIZONE SUCCESSIVA A QUELLA OCCUPATA**/
void CICL1(int (*R)[][2], int g, int input)
{
    int v = g;
    while (v <= input - 1)
    {
        printf("[%d,%d]\t", (*R)[v][0], (*R)[v][1]);
        ++v;
    }
}

/**	 FUNZIONE PER SPOSTARE IL CURSORE A LATO**/
void PON()
{
    for (short int cs = 0; cs <= 5;)
    {
        printf("\t");
        ++cs;
    }
}

/**	 FUNZIONE PER SPOSTARE IL CURSORE A LATO di Choice DOVE CHOICE è LA POSIZIONE DELLA CARTA SCELTA DAL GIOCATORE **/
void PON_1(int choice)
{
    for (int cs = 0; cs <=choice-2;)
    {
        printf("\t");
        ++cs;
    }
}

/**FUNZIONE DIVISORIO : divide il piano di gioco dalle tessere rimanenti **/
void divi()
{
    for (short int qg = 0; qg <= 10; ++qg)
    {
        printf("_____");
    }
    printf("\n");
}

/**FUNZIONE CHE MANDA A SCHERMO LA POSIZIONE DELLE TESSERE RIMANENTI
* PRENDE COME PARAMETRO LA POSIZIONE DEL PIANO DI GIOCO LIBERA
E STAMPA LE POSIZIONI SUCCESSIVE  */
void FUN1(int pp, int input)
{
    int l = pp;
    while (l <= input - 1)
    {
        printf("<%d>\t", l);
        ++l;
    }
}
/**FUNZIONE CHE MANDA A SCHERMO LA POSIZIONE DELLE TESSERE INSERITE DAL GIOCATORE (AGGIORNATE)**/
void FUN(int pp)
{
    int L = 0;
    while (L <= pp)
    {
        printf("<%d>\t", L);
        ++L;
    }
}

/************************************************************MAIN ******************************************************************************/
int main()
{
    int input = 0;
RIPROVA:
    printf("inserisci numero tessere con cui vuoi giocare--> min :10, max: 20\n"); /**La Scelta va da 10--> a 24(massimo compreso) */
    scanf("%d", &input);                                                           /**IL Gicatore sceglie con quante tessere vuole giocare */
    if (input < 10 || input > 20)
        goto RIPROVA;
    int Piano_Gioco[input][2]; /**Inizializzo il Piano  di gioco con le tessere  */
    srand(time(NULL));          /**FUNZIONE SRAND */
    for (int i = 0; i < input; ++i)
    {
        for (int j = 0; j < 2; ++j)
        {
            int casuale = rand() % 7;
            if (casuale == 0)
                ++casuale;
            Piano_Gioco[i][j] = casuale;
        }
    }
    POISZIIONE_Tess_1(0, input);
    printf("\n");
    for (int i = 0; i <= input - 1; ++i)
    {

        for (int j = 0; j < 2; ++j)
        {
            if (j == 0)
                printf("[%d-", Piano_Gioco[i][j]);
            else
                printf("%d]", Piano_Gioco[i][j]);
        }
        printf("\t");
    }
    printf("\n");
    int Campo_Gioco[input][2]; /**Inzializzazione campo da gioco dove mettere le carte*/
cho_1:
    printf("scegli LA PRIMA tessera,per iniziare\n");
    int Choice = 0;
    scanf("%d", &Choice);
    if (Choice < 0 || Choice > input - 1)
        goto cho_1;
    Campo_Gioco[0][0] = Piano_Gioco[Choice][0];
    Campo_Gioco[0][1] = Piano_Gioco[Choice][1];
    int Punteggio = Campo_Gioco[0][0] + Campo_Gioco[0][1]; /**DICHIARAZIONE VARIABILE  DEL PUNTEGGIO */
    printf("ECCO LA TUA PRIMA TESSERA INSERITA\n");
    int free_palce = 0; /**Inizializzo variabile per contollo gioco quella che indica la posizione libera dove mettere la carta  */
    Keep_UP(input, &Piano_Gioco, &Choice, free_palce);
    free_palce += 1;
    TESS_Up(free_palce); /**Stampa il piano di gioco aggiornato */
    printf("\n");
    Print_TE(Campo_Gioco, free_palce);
    printf("\n");
    printf("CAMPO TESSERE AGGIORNATO SCEGLI DA QUI");
    printf("\n");
    FUN1(free_palce, input);
    free_palce = 1;
    printf("\n");
    CICL1(&Piano_Gioco, free_palce, input);
    printf("\n");
    free_palce = 1;
    printf("\n");
    int ms;
    char mod = '0';  /**var mod per scegliere modalità di gioco*/ 
    int choice = 0;  /**var choice  per scegliere la tessera desiderata*/ 
    int posizione = 0; /**var posizione  per scegliere posizione dove inserire la tessera  di gioco*/ 
    printf("SCEGLIERE N.TESSERA[]-->SCEGLIERE POSIZIONE[]--> SCEGLIERE[I]PER INSERIRE O [S] PER SWAP\n");
    while (free_palce <= input - 1) /**INIZIALIZZAZIONE LOOP PER IL GIOCO */
    {
        ms = Mossa1(input, &Piano_Gioco, &Campo_Gioco, free_palce, free_palce);
        if (ms != 1)
        {
            printf("NON CI SONO PIU TESSERE DISPONIBILI PER ATTUARE ALTRE MOSSE");
            exit(-1);
        }
    mos_w:
        printf("SCEGLIERE MOD--->[");
        scanf("%s", &mod);
        printf("\n");
        if (mod != 'i' && mod != 's')
            goto mos_w;
        if (free_palce == 0)
            ++free_palce;
        if (mod == 'i') /**modalità I per Inserire */
        {
        cho:
            printf("SCEGLIERE N.TESSERA -->[");
            scanf("%d", &choice);
            if (choice < free_palce &&
                choice >= input)
                goto cho;
        pos_m:
            printf("SCEGLIERE POSIZIONE--->[");
            scanf("%d", &posizione);
            if (posizione < 0)
                goto pos_m;
            if (posizione > free_palce)
                goto pos_m;
            if (posizione != 0 && posizione != free_palce && posizione != free_palce - 1)
                goto pos_m;

            printf("\n");

            if (Check_Inserimento(Piano_Gioco, Campo_Gioco, &posizione, &choice, free_palce) != 1)
            {
                printf("Tessera non valida\n");
                goto mos_w;
            }
            Effe_Inserimento(&Campo_Gioco, Piano_Gioco, &posizione, choice, free_palce);
            printf("ECCO LE TESSERE INSERITE DA TE \n");
            FUN(free_palce);
            printf("\n");
            Print_TE_1(&Campo_Gioco, free_palce);
            printf("\n");
            Punteggio += Piano_Gioco[choice][0] + Piano_Gioco[choice][1];
            PON();
            printf(" PUNTEGGIO\t****%hd****", Punteggio);
            PON();
            printf("\n");
            divi();
            int fo = free_palce + 1;
            printf("TESSERE RIMANENTI\n");
            PON();
            printf("<---- SCEGLI LA TESSERA DA QUI\n ");
            PON();
            printf("\n");
            FUN1(fo, input);
            printf("\n");
            Keep_UP(input, &Piano_Gioco, &choice, free_palce);
            fo = free_palce + 1;
            CICL1(&Piano_Gioco, fo, input);
            printf("\n");
            fo = 0;
            ++free_palce;
        }
        if (mod == 's')/**modalità S per swap  */
        {
        sce:
            printf("SCEGLIERE N.TESSERA -->[");
            scanf("%d", &choice);
            if (choice < free_palce && choice >= input)
                goto sce;
            printf("TESSERA <%d> ---> CAMBIATA\n ", choice);
            printf("\n");
            change(&Piano_Gioco, &choice);
            FUN1(free_palce, input);
            printf("\n");
            CICL1(&Piano_Gioco,free_palce, input);
            PON();
            printf("<---- SCEGLI LA TESSERA DA QUI\n ");
            PON_1(choice);
            printf(" ");
            printf("^\n");
            PON_1(choice);
            printf(" ");
            printf("|\n");
            divi();
            printf("\n");
            int la = free_palce - 1;
            printf("stampo di nuovo le tessere inserite\n");
            FUN(la);
            printf("\n");
            Print_TE_1(&Campo_Gioco, la);
            printf("\n");
            divi();
            printf("\n");
            PON();
            printf("PUNTEGGIO\t****%d****", Punteggio);
            printf("\n");
        }
    }

    return 0;
}
