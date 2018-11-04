/* Kelompok    : CisituPlusNobel
/* File        : function.c */
/* Tanggal     : 29 Oktober 2018 */

#include "function.h"
#include <stdio.h>

void Interface(ROOM R, int room, Queue Q, Stack S, TabInt orders, JAM J)
/* Menulis Interface*/
{
  //KAMUS LOKAL
  int i;

  //ALGORITMA
  TulisMATRIKS(Elm(R,room)); printf("\n");
  
  printf("TIME : ");
  TulisJAM(J);
  
  printf("WAITING CUST : \n");
  PrintQueue(Q);

  printf("HAND : \n");
  PrintStackt(S);

  printf("ORDER : \n");
  TulisIsiTab(orders);

}

void Go(ROOM *R, POINT *P, char C, int *room)
/*  Procesure Go terdiri dari 4 perintah yaitu Go Up, Go Down, Go Left, Go Right */
{
  //KAMUS LOKAL
  POINT temp;

  //ALGORITMA
  Absis(temp) = Absis(*P);
  Ordinat(temp) = Ordinat(*P);
  switch (C){
    case 'D':
      if (Absis(*P) == 8 && Ordinat(*P) == 5 && (*room == 1 || *room == 2)){
        ElmtMATRIKS(Elm(*R,*room),Absis(*P),Ordinat(*P)) = ' ';
        if (*room == 1){
          *room = 4;
        }else{
          *room = 3;
        }
        Absis(temp) = 1; Ordinat(temp) = 5;
        ElmtMATRIKS(Elm(*R,*room),Absis(temp),Ordinat(temp)) = 'P';
      }
      else if (ElmtMATRIKS(Elm(*R,*room),Absis(*P)+1,Ordinat(*P)) == ' '){
        temp = PlusDelta(*P,1,0);
        ElmtMATRIKS(Elm(*R,*room),Absis(*P),Ordinat(*P)) = ' ';
        ElmtMATRIKS(Elm(*R,*room),Absis(temp),Ordinat(temp)) = 'P';
      }
      break;
    case 'U':
      if (Absis(*P) == 1 && Ordinat(*P) == 5 && (*room == 4 || *room == 3)){
        ElmtMATRIKS(Elm(*R,*room),Absis(*P),Ordinat(*P)) = ' ';
        if (*room == 4){
          *room = 1;
        }else{
          *room = 2;
        }
        Absis(temp) = 8; Ordinat(temp) = 5;
        ElmtMATRIKS(Elm(*R,*room),Absis(temp),Ordinat(temp)) = 'P';
      }
      else if (ElmtMATRIKS(Elm(*R,*room),Absis(*P)-1,Ordinat(*P)) == ' '){
        temp = PlusDelta(*P,-1,0);
        ElmtMATRIKS(Elm(*R,*room),Absis(*P),Ordinat(*P)) = ' ';
        ElmtMATRIKS(Elm(*R,*room),Absis(temp),Ordinat(temp)) = 'P';
      }
      break;
    case 'L':
      if (Absis(*P) == 5 && Ordinat(*P) == 1 && (*room == 2 || *room == 3)){
        ElmtMATRIKS(Elm(*R,*room),Absis(*P),Ordinat(*P)) = ' ';
        if (*room == 2){
          *room = 1;
        }else{
          *room = 4;
        }
        Absis(temp) = 5; Ordinat(temp) = 8;
        ElmtMATRIKS(Elm(*R,*room),Absis(temp),Ordinat(temp)) = 'P';
      }
      else if (ElmtMATRIKS(Elm(*R,*room),Absis(*P),Ordinat(*P)-1) == ' '){
        temp = PlusDelta(*P,0,-1);
        ElmtMATRIKS(Elm(*R,*room),Absis(*P),Ordinat(*P)) = ' ';
        ElmtMATRIKS(Elm(*R,*room),Absis(temp),Ordinat(temp)) = 'P';
      }
      break;
    case 'R':
      if (Absis(*P) == 5 && Ordinat(*P) == 8 && (*room == 1 || *room == 4)){
        ElmtMATRIKS(Elm(*R,*room),Absis(*P),Ordinat(*P)) = ' ';
        if (*room == 1){
          *room = 2;
        }else{
          *room = 3;
        }
        Absis(temp) = 5; Ordinat(temp) = 1;
        ElmtMATRIKS(Elm(*R,*room),Absis(temp),Ordinat(temp)) = 'P';
      }
      else if (ElmtMATRIKS(Elm(*R,*room),Absis(*P),Ordinat(*P)+1) == ' '){
        temp = PlusDelta(*P,0,1);
        ElmtMATRIKS(Elm(*R,*room),Absis(*P),Ordinat(*P)) = ' ';
        ElmtMATRIKS(Elm(*R,*room),Absis(temp),Ordinat(temp)) = 'P';
      }
      break;
  }
  Absis(*P) = Absis(temp);
  Ordinat(*P) = Ordinat(temp);
  //printf("<%d, %d>\n", Absis(*P), Ordinat(*P));
}

void Place(Queue *Q, ROOM *R)
/* Menempatkan pelangan dengan Top of Queue ke dalam meja yang kososng */
{
  //KAMUS LOKAL
  int meja, i, j;
  Customer X;
  boolean found;

  //ALGORITMA
  if (!IsEmptyQueue(*Q)) {
    if (InfoHead(*Q).NbPeople == 4) {
      CekKosong4(*R, &meja);
      if (meja != -999) {
        printf("Mengisi meja nomor %d\n", meja);
        MakeFullTable4(R, meja);
        DelQueue(Q, &X);
        X.NbTable = meja;
        X.WaitTime = 30;
        // Add ke Array/List
       // UbahEli(&tables,X.NbTable,X);
      } else {
        CekKosong2(*R, &meja);
        if (meja != -999) {
          i = Head(*Q);
          found = false;
          j = Tail(*Q) + 1;
          if (j > MaxEl(*Q)) {
            j = j - MaxEl(*Q);
          }
          while ((i != j) && !found) {
            if (Cust(*Q, i) == 2) {
              printf("Mengisi meja nomor %d\n", meja);
              MakeFullTable2(R, meja);
              DelEliQueue(Q,i,&X);
              X.NbTable = meja;
              X.WaitTime = 30;
              // Add ke Array/List
              //UbahEli(&tables,X.NbTable,X);
              found = true;
            }
            i++;
            if (i > MaxEl(*Q)) {
              i = i - MaxEl(*Q);
            }
          }
        } else {
          printf("Semua Meja Penuh!\n");
        }
      }
    } else {
      CekKosong2(*R, &meja);
      if (meja != -999){
        printf("Mengisi meja nomor %d\n", meja);
        MakeFullTable2(R, meja);
        DelQueue(Q, &X);
        X.NbTable = meja;
        X.WaitTime = 30;
        // Add ke array/list
        //UbahEli(&tables,X.NbTable,X);
      } else {
        printf("Semua Meja Penuh!\n");
      }
    }
  }
}

void Take(POINT P, Stack *S, ROOM R, int room)
/*Mengambil bahan makanan di dekat player */
{
  if (room==4){
    if((ElmtMATRIKS(Elm(R,room),Absis(P)+1,Ordinat(P)) == 'M')||(ElmtMATRIKS(Elm(R,room),Absis(P)-1,Ordinat(P)) == 'M')||(ElmtMATRIKS(Elm(R,room),Absis(P),Ordinat(P)+1) == 'M')||(ElmtMATRIKS(Elm(R,room),Absis(P),Ordinat(P)-1) == 'M')){
      if (Absis(P)==1 && Ordinat(P)==2){
        Push(S,1);
      }
      else if (Absis(P)==2 && Ordinat(P)==2){
        Push (S,2);
      }
      else if (Absis(P)==3 && Ordinat(P)==2){
        Push (S,3);
      }
      else if (Absis(P)==4 && Ordinat(P)==2){
        Push (S,4);
      }
      else if (Absis(P)==5 && Ordinat(P)==2){
        Push (S,5);
      }
      else if (Absis(P)==6 && Ordinat(P)==2){
        Push (S,6);
      }
      else if (Absis(P)==7 && Ordinat(P)==2){
        Push (S,7);
      }
      else if (Absis(P)==8 && Ordinat(P)==2){
        Push (S,8);
      }
      else if ((Absis(P)==5 && Ordinat(P)==3)||(Absis(P)==4 && Ordinat(P)==4)||(Absis(P)==6 && Ordinat(P)==4)){
        Push (S,9);
      }
      else if ((Absis(P)==5 && Ordinat(P)==6)||(Absis(P)==4 && Ordinat(P)==5)||(Absis(P)==6 && Ordinat(P)==5)){
        Push (S,10);
      }
      else if ((Absis(P)==8 && Ordinat(P)==3)||(Absis(P)==7 && Ordinat(P)==4)){
        Push (S,11);
      }
      else if (Absis(P)==7 && Ordinat(P)==5){
        Push (S,12);
      }
      else if (Absis(P)==7 && Ordinat(P)==6){
        Push (S,13);
      }
      else if (Absis(P)==7 && Ordinat(P)==7){
        Push (S,14);
      }
      else if (Absis(P)==7 && Ordinat(P)==8){
        Push (S,15);
      } 
    }
  }
}

void CH(Stack *S)
/* Membuang semua bahan makanan yang ada di tangan */
{
  if(!IsEmptyStackt(*S)){
    CreateEmptyStackt(S);
  }
}

void Order(ROOM *R, int room, POINT P)
/* Mengambil order dari meja yang bersebelahan */
{
/*  //KAMUS LOKAL
  int meja;

  //ALGORITMA
  CekSebelahan(*R,room,P,&meja);
  if (meja != -999){
    //printf("%d\n",meja);
    //UbahEli(&orders,(room-1)*4+meja,ElmtArray(tables,(room-1)*4+meja));
  }*/
}

void AddRemove(TabInt *orders, Queue *Q, Customer emptyOrder, JAM J, ROOM *R, POINT P)
/* Menambah Queue dan/atau mengurangi order berdasarkan waktu*/
{
  //KAMUS LOKAL
  int i;
  Customer cust,X;

  //ALGORITMA
/*  for (i=1; i<=12; i++){
    ElmtArray(orders,i).WaitTime--;
    ElmtArray(tables,i).WaitTime--;
    if (ElmtArray(orders,i).WaitTime==0){
      meja = ElmtArray(tables,i).NbTable;
      printf("Pengunjung ruangan %d meja %d pergi\n",ruang,meja);
      MakeEmptyTable(&R,meja);
      UbahEli(orders,i,emptyOrder);
      //UbahEli(&tables,i,emptyOrder);
    }
  }*/
  if (!IsEmptyQueue(*Q)){
    if (Tail(*Q) >= Head(*Q)){
      for (i=Head(*Q); i<=Tail(*Q); i++){
        WT(*Q,i)--;
      }
    } else{
      i=Head(*Q);
      while (i!=Tail(*Q)){
        WT(*Q,i)--;
        i++;
        if (i>MaxEl(*Q)){
          i = i-MaxEl(*Q);
        }
      }
    }
  }

  if (WT(*Q, Head(*Q)) == 0) {
    DelQueue(Q, &X);
    //printf("Deleted\n");
  }

  if (JAMToDetik(J)%13 == 0){
    if ((JAMToDetik(J)+Absis(P)+Ordinat(P))%2 == 0){
      cust.NbPeople = 4;
    } else{
      cust.NbPeople = 2;
    }
    cust.NbTable = -999;
    cust.Pesanan.Code = ((JAMToDetik(J)+Absis(P)+Ordinat(P))%8)+1;
    cust.WaitTime = 30;
    AddQueue(Q, cust);
  }
}