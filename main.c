#include <stdio.h>
#include <stdlib.h>
#include "pilhas.h"

/*
 * SELL YOUR SOUL FOR UNDERSTAND THIS SHIT OR PAY A BEE FOR JOAO KKKKKKKKKKK
 */

int get_size(Pilha *p){
    return p->tamanho;
}

void cria_jogo(Pilha *p1, Pilha *p2, Pilha *p3, Pilha *p4, Pilha *p5, Pilha *p6, Pilha *p7, Pilha *p8, Pilha *p9, Pilha *p10, Pilha *p11, Pilha *p12){
    p1->topo = NULL;
    p1->tamanho = 0;
    p1->same = 0;
    p2->topo = NULL;
    p2->tamanho = 0;
    p2->same = 0;
    p3->topo = NULL;
    p3->tamanho = 0;
    p3->same = 0;
    p4->topo = NULL;
    p4->tamanho = 0;
    p4->same = 0;
    p5->topo = NULL;
    p5->tamanho = 0;
    p5->same = 0;
    p6->topo = NULL;
    p6->tamanho = 0;
    p6->same = 0;
    p7->topo = NULL;
    p7->tamanho = 0;
    p7->same = 0;
    p8->topo = NULL;
    p8->tamanho = 0;
    p8->same = 0;
    p9->topo = NULL;
    p9->tamanho = 0;
    p9->same = 1;
    p10->topo = NULL;
    p10->tamanho = 0;
    p10->same = 1;
    p11->topo = NULL;
    p11->tamanho = 0;
    p11->same = 1;
    p12->topo = NULL;
    p12->tamanho = 0;
    p12->same = 1;
}
void mover_cartas(Pilha *ant, Pilha *dest){
    if(dest->same == 1){
        if (ant->topo->numCarta < dest->topo->numCarta){
            if(ant->topo->naipe == dest->topo->naipe && ant->topo->cor == dest->topo->cor){
            Cartas *temp;
            temp = &ant->topo;
            ant->topo = ant->topo->ant;
            temp->ant = dest->topo;
            dest->topo = temp;
            dest->tamanho++;
            ant->tamanho--;
            printf("Carta  movida!");
        } else {
            printf("Esta pilha requer cartas do mesmo naipe e mesma cor!");
        }
        } else {
            printf("A carta é maior que a carta que está na pilha de destino!");
        }
    } else {
        if(ant->topo->numCarta < dest->topo->numCarta){
            if(ant->topo->cor != dest->topo->cor){
                Cartas *temp;
                temp = &ant->topo;
            ant->topo = ant->topo->ant;
            temp->ant = dest->topo;
            dest->topo = temp;
            dest->tamanho++;
            ant->tamanho--;
            printf("Carta  movida!");
            } else {
                printf("As cartas tem cores iguais!");
            }
        } else {
            printf("A carta é maior que a carta que está na pilha de destino!");
        }
    }
}
void quitGame(int *op, Pilha *p1, Pilha *p2, Pilha *p3, Pilha *p4, Pilha *p5, Pilha *p6, Pilha *p7, Pilha *p8, Pilha *p9, Pilha *p10, Pilha *p11, Pilha *p12){
    freePilha(&p1);freePilha(&p2);freePilha(&p3);freePilha(&p4); freePilha(&p5);freePilha(&p6);freePilha(&p7);freePilha(&p8);freePilha(&p9);freePilha(&p10);freePilha(&p11); freePilha(&p12);
    printf("Obrigado por jogar! Agora va trabalhar! :D");
    op = 99;
}
void freePilha(Pilha *p){
    Cartas *temp;
    temp = p->topo;
    p->topo = temp->ant;
    p->tamanho--;
    free(temp);
    if(p->tamanho > 0){
        freePilha(&p);
    }
}
void printPilhas( Pilha *p1, Pilha *p2, Pilha *p3, Pilha *p4, Pilha *p5, Pilha *p6, Pilha *p7, Pilha *p8, Pilha *p9, Pilha *p10, Pilha *p11, Pilha *p12){
    Cartas *ant1 = &p1->topo, *ant2 = &p2->topo, *ant3 = &p3->topo,*ant4 = &p4->topo,*ant5 = &p5->topo,*ant6 = &p6->topo,*ant7 = &p7->topo, *ant8 = &p8->topo, *ant9 = &p9->topo,*ant10 = &p10->topo,*ant11 = &p11->topo, *ant12 = &p12->topo;
    printf("1   |  2  |  3  |  4  |  5  |  6  |  7  |  %c  |  %c  | %c | %c \n\n", 3, 4, 5, 6);
    int i = 0;
     if(ant1->ant != NULL && ant2 != NULL && ant3 != NULL && ant4 != NULL && ant5 != NULL && ant6 != NULL && ant7 != NULL && ant8 != NULL && ant9 != NULL && ant10 != NULL && ant11 != NULL && ant12 != NULL){
    for(;;){
        printf("%d[%c][%c]|%d[%c][%c]|%d[%c][%c]|%d[%c][%c]|%d[%c][%c]|%d[%c][%c]|%d[%c][%c]|%d[%c][%c]|%d[%c][%c]|%d[%c][%c]|%d[%c][%c]|%d[%c][%c] \n\n", ant1->numCarta, ant1->naipe, ant1->cor,ant2->numCarta, ant2->naipe, ant2->cor,ant3->numCarta, ant3->naipe, ant3->cor,ant4->numCarta, ant4->naipe, ant4->cor,ant5->numCarta, ant5->naipe, ant5->cor,ant6->numCarta, ant6->naipe, ant6->cor,ant7->numCarta, ant7->naipe, ant7->cor,ant8->numCarta, ant8->naipe, ant8->cor,ant9->numCarta, ant9->naipe, ant9->cor,ant10->numCarta, ant10->naipe, ant10->cor,ant11->numCarta, ant11->naipe, ant11->cor,ant12->numCarta, ant12->naipe, ant12->cor);
        if(ant1->ant == NULL && ant2->ant == NULL && ant3->ant == NULL && ant4->ant == NULL && ant5->ant == NULL && ant6->ant == NULL && ant7->ant == NULL && ant8->ant == NULL && ant9->ant == NULL && ant10->ant == NULL && ant11->ant == NULL && ant12->ant == NULL){
            break;
        }
        ant1 = &ant1->ant;
        ant2 = &ant2->ant;
        ant3 = &ant3->ant;
        ant4 = &ant4->ant;
        ant5 = &ant5->ant;
        ant6 = &ant6->ant;
        ant7 = &ant7->ant;
        ant8 = &ant8->ant;
        ant9 = &ant9->ant;
        ant10 = &ant10->ant;
        ant11 = &ant11->ant;
        ant12 = &ant12->ant;
    }
     }
}

void simulate(Pilha *p, int cardNum, char naipe, char color){
    Cartas *card;
    card = malloc(sizeof(Cartas));
    card->ant = &p->topo;
    card->cor = color;
    card->naipe = naipe;
    card->numCarta = cardNum;
    p->topo = &card;
    p->tamanho++;
}


int main()
{
    Pilha *p1, *p2,*p3,*p4,*p5,*p6,*p7,*p8,*p9,*p10,*p11,*p12;
    int op = 0;
    int pil, numcarta;
    char naipe, cor;
    p1 = malloc(sizeof(Pilha));p2 = malloc(sizeof(Pilha));p3 = malloc(sizeof(Pilha));p4 = malloc(sizeof(Pilha));p5 = malloc(sizeof(Pilha));p6 = malloc(sizeof(Pilha));p7 = malloc(sizeof(Pilha));p8 = malloc(sizeof(Pilha));p9 = malloc(sizeof(Pilha));p10 = malloc(sizeof(Pilha));p11 = malloc(sizeof(Pilha));p12 = malloc(sizeof(Pilha));
    cria_jogo(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12);
    printf("Paciencia \t\t(muuuuita mesmo :P )\n\n\n");
   do {
        printPilhas(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12);
        switch(op){
        case 1:
           printf("Digite a pilha a inserir:\n");
           scanf("%d", &pil);
           printf("Digite o naipe:\n");
           naipe = getc(stdin);
           printf("Digite a cor:\n");
           cor = getc(stdin);
           printf("Digite o numero da carta (K, J, L TRANSFORME NO RESPECTIVO NUMERO) \n");
           scanf("%d", &numcarta);
           switch(pil){
        case 1:
            simulate(p1, numcarta, naipe, cor);
            break;
            case 2:
            simulate(p2, numcarta, naipe, cor);
            break;
            case 3:
            simulate(p3, numcarta, naipe, cor);
            break;
            case 4:
            simulate(p4, numcarta, naipe, cor);
            break;
            case 5:
            simulate(p5, numcarta, naipe, cor);
            break;
            case 6:
            simulate(p6, numcarta, naipe, cor);
            break;
            case 7:
            simulate(p7, numcarta, naipe, cor);
            break;
            case 8:
            simulate(p8, numcarta, naipe, cor);
            break;
            case 9:
            simulate(p9, numcarta, naipe, cor);
            break;
            case 10:
            simulate(p10, numcarta, naipe, cor);
            break;
            case 11:
            simulate(p11, numcarta, naipe, cor);
            break;
            case 12:
            simulate(p12, numcarta, naipe, cor);
            break;
            default:
                printf("A pilha digitada nao existe");
           }
            printPilhas(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12);
            break;
        default:
            printf("\n");
        }

        scanf("%d", &op);
        system("cls");
   } while(op != 99);


    return 0;
}
