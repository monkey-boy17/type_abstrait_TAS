#include "tas.c"

int main(){

    TasMin t;
    creerTas(&t, 'A');
    printf("%c\n", t.arbre[1]);

    return 0;
}
