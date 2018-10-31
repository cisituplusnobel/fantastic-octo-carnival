#include <stdio.h>
#include <string.h>
#include "matriks.h"
#include "point.h"
#include "jam.h"
#include "queue.h"

#define RMin 1
#define RMax 100

typedef struct{
  MATRIKS Mem[RMax+1];
} ROOM;

#define Elm(R,i) (R).Mem[(i)]

void MakeEmptyTable(ROOM *R, int room, int table)
/**/

{
  if (room==1 && table==1){
    Elmt(Elm(*R,1),1,2) = 'X';
    Elmt(Elm(*R,1),2,1) = 'X';
    Elmt(Elm(*R,1),2,3) = 'X';
    Elmt(Elm(*R,1),3,2) = 'X';
    Elmt(Elm(*R,1),2,2) = '1';
  } else if (room==1 && table==2){
    Elmt(Elm(*R,1),2,6) = 'X';
    Elmt(Elm(*R,1),2,8) = 'X';
    Elmt(Elm(*R,1),2,7) = '2';
  } else if (room==1 && table==3){
    Elmt(Elm(*R,1),6,2) = 'X';
    Elmt(Elm(*R,1),7,1) = 'X';
    Elmt(Elm(*R,1),7,3) = 'X';
    Elmt(Elm(*R,1),8,2) = 'X';
    Elmt(Elm(*R,1),7,2) = '3';
  } else if (room==1 && table==4){
    Elmt(Elm(*R,1),7,6) = 'X';
    Elmt(Elm(*R,1),7,8) = 'X';
    Elmt(Elm(*R,1),7,7) = '4';      
  } else if ((room==2 || room==3) && table==1){
    Elmt(Elm(*R,room),1,3) = 'X';
    Elmt(Elm(*R,room),2,2) = 'X';
    Elmt(Elm(*R,room),2,4) = 'X';
    Elmt(Elm(*R,room),3,3) = 'X';
    Elmt(Elm(*R,room),2,3) = '1'; 
  } else if ((room==2 || room==3) && table==2){
    Elmt(Elm(*R,room),2,6) = 'X';
    Elmt(Elm(*R,room),2,8) = 'X';
    Elmt(Elm(*R,room),2,7) = '2';
  } else if ((room==2 || room==3) && table==3){
    Elmt(Elm(*R,room),6,2) = 'X';
    Elmt(Elm(*R,room),7,1) = 'X';
    Elmt(Elm(*R,room),7,3) = 'X';
    Elmt(Elm(*R,room),8,2) = 'X';
    Elmt(Elm(*R,room),7,2) = '3';
  } else if ((room==2 || room==3) && table==4){
    Elmt(Elm(*R,room),7,6) = 'X';
    Elmt(Elm(*R,room),7,8) = 'X';
    Elmt(Elm(*R,room),7,7) = '4';
  }
}

void MakeFullTable(ROOM *R, int room, int table)
/**/

{
  if (room==1 && table==1){
    Elmt(Elm(*R,1),1,2) = 'C';
    Elmt(Elm(*R,1),2,1) = 'C';
    Elmt(Elm(*R,1),2,3) = 'C';
    Elmt(Elm(*R,1),3,2) = 'C';
    Elmt(Elm(*R,1),2,2) = '1';
  } else if (room==1 && table==2){
    Elmt(Elm(*R,1),2,6) = 'C';
    Elmt(Elm(*R,1),2,8) = 'C';
    Elmt(Elm(*R,1),2,7) = '2';
  } else if (room==1 && table==3){
    Elmt(Elm(*R,1),6,2) = 'C';
    Elmt(Elm(*R,1),7,1) = 'C';
    Elmt(Elm(*R,1),7,3) = 'C';
    Elmt(Elm(*R,1),8,2) = 'C';
    Elmt(Elm(*R,1),7,2) = '3';
  } else if (room==1 && table==4){
    Elmt(Elm(*R,1),7,6) = 'C';
    Elmt(Elm(*R,1),7,8) = 'C';
    Elmt(Elm(*R,1),7,7) = '4';      
  } else if ((room==2 || room==3) && table==1){
    Elmt(Elm(*R,room),1,3) = 'C';
    Elmt(Elm(*R,room),2,2) = 'C';
    Elmt(Elm(*R,room),2,4) = 'C';
    Elmt(Elm(*R,room),3,3) = 'C';
    Elmt(Elm(*R,room),2,3) = '1'; 
  } else if ((room==2 || room==3) && table==2){
    Elmt(Elm(*R,room),2,6) = 'C';
    Elmt(Elm(*R,room),2,8) = 'C';
    Elmt(Elm(*R,room),2,7) = '2';
  } else if ((room==2 || room==3) && table==3){
    Elmt(Elm(*R,room),6,2) = 'C';
    Elmt(Elm(*R,room),7,1) = 'C';
    Elmt(Elm(*R,room),7,3) = 'C';
    Elmt(Elm(*R,room),8,2) = 'C';
    Elmt(Elm(*R,room),7,2) = '3';
  } else if ((room==2 || room==3) && table==4){
    Elmt(Elm(*R,room),7,6) = 'C';
    Elmt(Elm(*R,room),7,8) = 'C';
    Elmt(Elm(*R,room),7,7) = '4';
  }
}

void MakeKitchen(ROOM *R)
/**/
{
  Elmt(Elm(*R,4),1,1) = 'M';
  Elmt(Elm(*R,4),2,1) = 'M';
  Elmt(Elm(*R,4),3,1) = 'M';
  Elmt(Elm(*R,4),4,1) = 'M';
  Elmt(Elm(*R,4),5,1) = 'M';
  Elmt(Elm(*R,4),6,1) = 'M';
  Elmt(Elm(*R,4),7,1) = 'M';
  Elmt(Elm(*R,4),8,1) = 'M'; 
  Elmt(Elm(*R,4),5,4) = 'M';
  Elmt(Elm(*R,4),5,5) = 'M';
  Elmt(Elm(*R,4),8,4) = 'M';
  Elmt(Elm(*R,4),8,5) = 'M';
  Elmt(Elm(*R,4),8,6) = 'M';
  Elmt(Elm(*R,4),8,7) = 'M';
  Elmt(Elm(*R,4),8,8) = 'M';
  Elmt(Elm(*R,4),1,8) = 'T';
}

boolean IsKosong(ROOM R, int room, int table)
/**/
{
  if (room==1 && table==1){
    if (Elmt(Elm(R,1),1,2) == 'C'){
      return false;
    }else{
      return true;
    }
  } else if (room==1 && table==2){
    if (Elmt(Elm(R,1),2,6) == 'C'){
      return false;
    } else{
      return true;
    }
  } else if (room==1 && table==3){
    if (Elmt(Elm(R,1),6,2) == 'C'){
      return false;
    }else{
      return true;
    }
  } else if (room==1 && table==4){
    if (Elmt(Elm(R,1),7,6) == 'C'){
      return false;
    }else{
      return true;
    }
  } else if ((room==2 || room==3) && table==1){
    if (Elmt(Elm(R,room),1,3) == 'C'){
      return false;
    }else{
      return true;
    }
  } else if ((room==2 || room==3) && table==2){
    if (Elmt(Elm(R,room),2,6) == 'C'){
      return false;
    }else{
      return true;
    }
  } else if ((room==2 || room==3) && table==3){
    if (Elmt(Elm(R,room),6,2) == 'C'){
      return false;
    } else{
      return true;
    }
  } else if ((room==2 || room==3) && table==4){
    if (Elmt(Elm(R,room),7,6) = 'C'){
      return false;
    }else{
      return true;
    }
  }
}

void IsKosong4(ROOM R, int *room, int *table)
{
  //KAMUS LOKAL
  int i,j;
  boolean kosong;

  //ALGORITMA
  i=1;
  kosong = false;
  *room = -999;
  *table = -999;
  while (i<=3 && !kosong){
    j=1;
    while (j<=4 && !kosong){
      if (IsKosong(R,i,j)){
        kosong = true;
        *room = i;
        *table = j;
      }else{
        j=j+2;
      }
    }
    i++;
  }
}

void IsKosong2(ROOM R, int *room, int *table)
{
  //KAMUS LOKAL
  int i,j;
  boolean kosong;

  //ALGORITMA
  i=1;
  kosong = false;
  while (i<=3 && !kosong){
    j=2;
    *room = -999;
    *table = -999;
    while (j<=4 && !kosong){
      if (IsKosong(R,i,j)){
        kosong = true;
        *room = i;
        *table = j;
      }else{
        j=j+2;
      }
    }
    i++;
  }
}

void Inisalisasi(ROOM *R, POINT *P, JAM *J, Queue *Q)
/* Melakukan inisalisasi pada bentuk setiap room
yaitu ruangan */
{
  //KAMUS LOKAL
  int i,j,k;

  //ALGORITMA
  for (i=1; i<=4; i++){
    MakeMATRIKS(8,8,&(Elm(*R,i)));
  }

  for (i=1; i<=4; i++){
    for (j=1; j<=8; j++){
      for (k=1; k<=8; k++){
        Elmt(Elm(*R,i),j,k) = ' ';
      }
    }
    for (j=1; j<=4; j++){
      MakeEmptyTable(R,i,j);
    }
  }
  MakeKitchen(R);
  *P = MakePOINT(4,4);
  *J = MakeJAM(0,0,0);
  CreateEmpty(Q,5);
  Add(Q, 4);
}

int main(){
  //KAMUS LOKAL
  ROOM R;
  POINT P,temp;
  JAM J;
  Queue Q;
  char C1,C2;
  int i,X,room,ruang,meja;

  //ALGORITMA
  Inisalisasi(&R, &P, &J, &Q);
  Elmt(Elm(R,1),Absis(P),Ordinat(P)) = 'P';
  room = 1;
  TulisMATRIKS(Elm(R,room));
  printf("\n");
  printf("COMMAND = ");
  scanf("%c%c", &C2, &C1);
  
  while(true){
    if (C2=='D'){
      if (Absis(P) == 8 && Ordinat(P) == 5 && (room == 1 || room == 2)){
        Elmt(Elm(R,room),Absis(P),Ordinat(P)) = ' ';
        if (room == 1){
          room = 4;
        }else{
          room = 3;
        }
        Absis(temp) = 1; Ordinat(temp) = 5;
        Elmt(Elm(R,room),Absis(temp),Ordinat(temp)) = 'P';
      }
      else if (Elmt(Elm(R,room),Absis(P)+1,Ordinat(P)) == ' '){
        temp = PlusDelta(P,1,0);
        Elmt(Elm(R,room),Absis(P),Ordinat(P)) = ' ';
        Elmt(Elm(R,room),Absis(temp),Ordinat(temp)) = 'P';
      }
      J = NextDetik(J);
    }else if (C2=='U'){
      if (Absis(P) == 1 && Ordinat(P) == 5 && (room == 4 || room == 3)){
        Elmt(Elm(R,room),Absis(P),Ordinat(P)) = ' ';
        if (room == 4){
          room = 1;
        }else{
          room = 2;
        }
        Absis(temp) = 8; Ordinat(temp) = 5;
        Elmt(Elm(R,room),Absis(temp),Ordinat(temp)) = 'P';
      }
      else if (Elmt(Elm(R,room),Absis(P)-1,Ordinat(P)) == ' '){
        temp = PlusDelta(P,-1,0);
        Elmt(Elm(R,room),Absis(P),Ordinat(P)) = ' ';
        Elmt(Elm(R,room),Absis(temp),Ordinat(temp)) = 'P';
      }
      J = NextDetik(J);
    }else if (C2=='L'){
      if (Absis(P) == 2 && Ordinat(P) == 1 && (room == 2 || room == 3)){
        Elmt(Elm(R,room),Absis(P),Ordinat(P)) = ' ';
        if (room == 2){
          room = 1;
        }else{
          room = 4;
        }
        Absis(temp) = 5; Ordinat(temp) = 8;
        Elmt(Elm(R,room),Absis(temp),Ordinat(temp)) = 'P';
      }
      else if (Elmt(Elm(R,room),Absis(P),Ordinat(P)-1) == ' '){
        temp = PlusDelta(P,0,-1);
        Elmt(Elm(R,room),Absis(P),Ordinat(P)) = ' ';
        Elmt(Elm(R,room),Absis(temp),Ordinat(temp)) = 'P';
      }
      J = NextDetik(J);
    }else if (C2=='R'){
      if (Absis(P) == 5 && Ordinat(P) == 8 && (room == 1 || room == 4)){
        Elmt(Elm(R,room),Absis(P),Ordinat(P)) = ' ';
        if (room == 1){
          room = 2;
        }else{
          room = 3;
        }
        Absis(temp) = 2; Ordinat(temp) = 1;
        Elmt(Elm(R,room),Absis(temp),Ordinat(temp)) = 'P';
      }
      else if (Elmt(Elm(R,room),Absis(P),Ordinat(P)+1) == ' '){
        temp = PlusDelta(P,0,1);
        Elmt(Elm(R,room),Absis(P),Ordinat(P)) = ' ';
        Elmt(Elm(R,room),Absis(temp),Ordinat(temp)) = 'P';
      }
      J = NextDetik(J);
    }else if(C2=='P'){
      if (!IsEmpty(Q)){
        i=Head(Q);
        while(i!=Tail(Q)){
          if (InfoHead(Q) == 4){
            (IsKosong4(R,&ruang,&meja));
            if (ruang != -999){
              MakeFullTable(&R,ruang,meja);
              Del(&Q, &X);
            }
            else{
              
            }
          }else{
            (IsKosong2(R,&ruang,&meja));
            if (ruang != -999){
              MakeFullTable(&R,ruang,meja);
              Del(&Q, &X);
            }        
          }
          i++;
        }
        J = NextDetik(J);
      }
    }else if(C2='T'){
      printf("RUANG 1 \n"); TulisMATRIKS(Elm(R,1)); printf("\n\n");
      printf("RUANG 2 \n"); TulisMATRIKS(Elm(R,2)); printf("\n\n");
      printf("RUANG 3 \n"); TulisMATRIKS(Elm(R,3)); printf("\n\n");
      printf("DAPUR \n"); TulisMATRIKS(Elm(R,4)); printf("\n\n");
    }
    Absis(P) = Absis(temp); Ordinat(P) = Ordinat(temp);
    TulisMATRIKS(Elm(R,room)); printf("\n");
    printf("TIME : ");
    TulisJAM(J);
    printf("ANTRIAN : \n");

    if (!IsEmpty(Q)){
      if (Tail(Q) >= Head(Q)){
        for (i=Head(Q); i<= Tail(Q); i++){
          printf("%d\n", Q.T[i]);
        }
      } else{
        i=Head(Q);
        while (i!=Tail(Q)){
          printf("%d\n", Q.T[i]);
          i++;
          if (i>MaxEl(Q)){
            i = i-MaxEl(Q);
          }
        }
      }
    }

    printf("COMMAND = ");
    scanf("%c%c", &C2, &C1);
    if (JAMToDetik(J)%15 == 0){
      if (JAMToDetik(J)%2 == 0){
        Add(&Q, 2);
      } else{
        Add(&Q, 4);
      }
    }
  }

  return 0;
}