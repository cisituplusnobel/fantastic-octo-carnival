#include <stdio.h>
#include <stdlib.h>
#include "matriks.h"
#include "point.h"
#include "jam.h"
#include "queue.h"
#include "stackt.h"
#include "array.h"
#include "room.h"
#include "function.h"
#include "boolean.h"
#include "datatype.h"

int main(){
  //KAMUS LOKAL
  ROOM R;
  POINT P;
  JAM J;
  Queue Q;
  Stack S;
  char C1,C2;
  int room, life, money;
  TabInt orders,tables;
	Customer emptyOrder;

  //ALGORITMA
  Inisalisasi(&R, &P, &J, &Q, &S, &orders, &tables, &emptyOrder, &life, &money);
  ElmtMATRIKS(Elm(R,1),Absis(P),Ordinat(P)) = 'P';
  room = 1;

  while(true){
    system("clear");
    Interface(R, room, Q, S, orders, J, life, money);

    printf("COMMAND = ");
    scanf("%c%c", &C2, &C1);
    switch (C2){
      case 'D': //GD
        Go(&R,&P, C2, &room);
        break;
      case 'U': //GU
        Go(&R,&P, C2, &room);
        break;
      case 'L': //GL
        Go(&R,&P, C2, &room);
        break;
      case 'R': //GR
        Go(&R,&P, C2, &room);
        break;								      
			case 'P': //PLACE
				Place(&Q, &R, P, room, &tables);
        break;
      case 'T': //TAKE
				Take(P, &S, R, room);
        break;
      case 'H': //CH
				CH(&S);
        break;
      case 'O': //ORDER
				Order(&R, room, P, &orders, tables);
        break;
      default :
        printf("RUANG 1 \n"); TulisMATRIKS(Elm(R,1)); printf("\n\n");
        printf("RUANG 2 \n"); TulisMATRIKS(Elm(R,2)); printf("\n\n");
        printf("RUANG 3 \n"); TulisMATRIKS(Elm(R,3)); printf("\n\n");
        printf("DAPUR \n"); TulisMATRIKS(Elm(R,4)); printf("\n\n");
    }

		J = NextDetik(J);
		AddRemove(&orders, &Q, emptyOrder, J, &R, P, &life, &tables);
  }
}