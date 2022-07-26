#include "tas.h"




void creerTas(TasMin *t, char x) {
    t->taille = 1;
    t->s = 1;
    t->arbre[1] = x;

}

char valeur(TasMin *t ) {
    return t->arbre[1];

}

void entasser(TasMin *t,char x) {
    t->taille ++;
    t->s ++;
    t->arbre[t->s] =x;
    reorganiserAsc(t);

}

void reorganiserAsc(TasMin *t, int s) {
    if(s != RACINE) {
        if(t->arbre[s] < pere(t,s)) {
            permuter(t, s, s/2);

        }

    }


}


char pere(TasMin *t, int s) {
    return t->arbre[s/2];

}


void permuter(TasMin *t, int s1, int s2) {
    char a = t->arbre[s1];
    t->arbre[s1] = t->arbre[s2];
    t->arbre[s2] =a;

}


void supprimer(TasMin *t) {
    t->taille --;
    t->arbre[RACINE] = t->arbre[t->s];
    t->s --;
    reorganiserDsc(t, RACINE);
}


void reorganiserDsc(TasMin *t, int s) {
    char fg = filsG(t,s);
    char fd = filsD(t,s);
    char v = getValeur(t,s);
    if(fg <= fd && fg < v) {
        permuter(t, s, s*2);
        reorganiserDsc(t, s*2);
    }else if (fd < v){
         permuter(t, s, s*2+1);
        reorganiserDsc(t, s*2+1);

    }
}

char getValeur(TasMin *t, int s) {
    return t->arbre[s];
}

