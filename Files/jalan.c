#include <stdio.h>
#include <conio.h>
#include "mesinkar\mesinkata.h"
#include "mesinkar\mesinkar.h"
#include <stdlib.h>

#define row 10
#define col 10

static FILE * pita;
char str[100];

typedef struct {
    char rep;
    char info;
} InfoPos;

typedef InfoPos field[row][col];

typedef struct {
    int xp;
    int yp;
    int to_room;
} door;

typedef struct {
    field room;
    door door1;
    door door2;
    int NO;
} ROOM;

int i, j;
int x, y;


int chartoint (char a) {
    switch (a) {
        case '0' : return 0;
        case '1' : return 1;
        case '2' : return 2;
        case '3' : return 3;
        case '4' : return 4;
        case '5' : return 5;
        case '6' : return 6;
        case '7' : return 7;
        case '8' : return 8;
        case '9' : return 9;
    }
}

void flfield (field *F) {
    for (i=1;i<=row;i++){
        for (j=1;j<=col;j++) {
            (*F)[i][j].rep=' ';
            (*F)[i][j].info='-';
        }
    }
}


void prtfield (field F) {
    for (i=row-1;i>=1;i--) {
        for (j=col-1;j>=1;j--) {
            printf("%c",F[i][j].rep);
        }
        printf("\n");
    }
}

boolean IsDoor (field F,int x, int y) {
    return ( F[x][y].info=='P' );
}

void changepos (field *F) {
    char key = getch();
    int val = key;

    switch (val) {
        case 119  :
            if (x!=row&&((*F)[x+1][y].rep==' '||(*F)[x+1][y].rep=='P')) {
                (*F)[x+1][y].rep = 'O';
                if (IsDoor(*F,x,y)) { (*F)[x][y].rep='P'; }
                else { (*F)[x][y].rep=' '; }
                x=x+1;
            }
            break;
        case 115 :
            if (x!=1&&((*F)[x-1][y].rep==' '||(*F)[x-1][y].rep=='P')) {
                (*F)[x-1][y].rep = 'O';
                if (IsDoor(*F,x,y)) { (*F)[x][y].rep='P'; }
                else { (*F)[x][y].rep=' '; }
                x=x-1;
            }
            break;
        case 97:
            if (y!=col&&((*F)[x][y+1].rep==' '||(*F)[x][y+1].rep=='P')) {
            (*F)[x][y+1].rep = 'O';
            if (IsDoor(*F,x,y)) { (*F)[x][y].rep='P'; }
            else { (*F)[x][y].rep=' '; }
            y=y+1;
            }
            break;
        case 100:
            if (y!=1&&((*F)[x][y-1].rep==' '||(*F)[x][y-1].rep=='P')) {
            (*F)[x][y-1].rep = 'O';
            if (IsDoor(*F,x,y)) { (*F)[x][y].rep='P'; }
            else { (*F)[x][y].rep=' '; }
            y=y-1;
            }
            break;
    }
}

void loadroom (ROOM gameroom[4]) {
    START();
    int i, xp, yp;
    for (i=0;i<4;i++) {
        flfield(&(gameroom[i].room));
        gameroom[i].NO = chartoint(CC);
        ADV(); IgnoreBlank();
        gameroom[i].door1.xp = chartoint(CC);
        ADV(); IgnoreBlank();
        gameroom[i].door1.yp = chartoint(CC);
        ADV(); IgnoreBlank();
        gameroom[i].room[gameroom[i].door1.xp][gameroom[i].door1.yp].rep = 'P';
        gameroom[i].room[gameroom[i].door1.xp][gameroom[i].door1.yp].info = 'P';
        gameroom[i].door1.to_room = chartoint(CC);
        ADV(); IgnoreBlank();
        gameroom[i].door2.xp = chartoint(CC);
        ADV(); IgnoreBlank();
        gameroom[i].door2.yp = chartoint(CC);
        ADV(); IgnoreBlank();
        gameroom[i].room[gameroom[i].door2.xp][gameroom[i].door2.yp].rep = 'P';
        gameroom[i].room[gameroom[i].door2.xp][gameroom[i].door2.yp].info = 'P';
        gameroom[i].door2.to_room = chartoint(CC);
        ADV(); IgnoreBlank();
        while (CC!=',' && i!=0 && CC!='.') {
            xp = chartoint(CC);
            ADV(); IgnoreBlank();
            yp = chartoint(CC);
            ADV(); IgnoreBlank();
            gameroom[i].room[xp][yp].rep='T';
            gameroom[i].room[xp+1][yp].rep='X';
            gameroom[i].room[xp-1][yp].rep='X';
            if (chartoint(CC)==4) {
                gameroom[i].room[xp][yp+1].rep='X';
                gameroom[i].room[xp][yp-1].rep='X';
            }
            ADV(); IgnoreBlank();
        }
        fgets(str,50,pita);
        ADV();ADV();
    }
}

int main () {

    ROOM gameroom[4];
    x = row/2; y = col/2;
    int croom=1;
    int prevroom;
    loadroom(gameroom);
    gameroom[croom].room[x][y].rep = 'O';

    while (1) {
        prtfield(gameroom[croom].room);
        changepos(&(gameroom[croom].room));
        if (IsDoor(gameroom[croom].room,x,y)) {
                prevroom = croom;
            if (gameroom[croom].door1.xp==x&&gameroom[croom].door1.yp==y) {
                croom = gameroom[croom].door1.to_room;
                if (gameroom[croom].door1.to_room==prevroom) {
                    x=gameroom[croom].door1.xp;
                    y=gameroom[croom].door1.yp;
                } else {
                    x=gameroom[croom].door2.xp;
                    y=gameroom[croom].door2.yp;
                }
            } else {
                croom = gameroom[croom].door2.to_room;
                if (gameroom[croom].door1.to_room==prevroom) {
                    x=gameroom[croom].door1.xp;
                    y=gameroom[croom].door1.yp;
                } else {
                    x=gameroom[croom].door2.xp;
                    y=gameroom[croom].door2.yp;
                }
            }
        }
        system("cls");
    }

    return 0;
}
