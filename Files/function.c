/* Kelompok    : CisituPlusNobel
/* File        : function.c */
/* Tanggal     : 29 Oktober 2018 */

#include "function.h"
#include <stdio.h>

void Interface(ROOM R, int room, Queue Q, Stack S, TabInt orders, JAM J, int life, int money)
/* Menulis Interface*/
{
  //KAMUS LOKAL
  int i;

  //ALGORITMA
  printf("MONEY : %d | ", money);

  printf("LIFE : %d | ", life);

  printf("TIME : ");
  TulisJAM(J);
  printf("\n");

  TulisMATRIKS(Elm(R,room)); printf("\n");
  
  if (!IsEmptyQueue(Q)){
    printf("WAITING CUST : \n");
    PrintQueue(Q);
  }

  if (!IsEmptyStackt(S)){
    printf("HAND : \n");
    PrintStackt(S);
  }

  if (!IsEmptyOrders(orders)){
    printf("ORDER : \n");
    TulisIsiTab(orders);
  }

  printf("\n");
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

void Place(Queue *Q, ROOM *R, POINT P, int room, TabInt *tables)
/* Menempatkan pelangan dengan Top of Queue ke dalam meja yang kososng */
{
  //KAMUS LOKAL
  int meja, table, i, j;
  Customer X;
  boolean found;

  //ALGORITMA
  if (!IsEmptyQueue(*Q)) {
    CekSebelahan(*R, room, P, &table);
    if (InfoHead(*Q).NbPeople == 4) {
      CekKosong4(*R, &meja);
      if ((meja != -999) && (table != -999) && (table % 2 == 1) && (IsKosong(*R,table))) {
        printf("Mengisi meja nomor %d\n", table);
        MakeFullTable4(R, table);
        DelQueue(Q, &X);
        X.NbTable = table;
        X.WaitTime = 30;
        // Add ke Array/List
        UbahEli(tables,X.NbTable,X);
      } else {
        CekKosong2(*R, &meja);
        if ((meja != -999) && (table != -999) && (IsKosong(*R,table))){
          i = Head(*Q);
          found = false;
          j = Tail(*Q) + 1;
          if (j > MaxEl(*Q)) {
            j = j - MaxEl(*Q);
          }
          while ((i != j) && !found) {
            if (Cust(*Q, i) == 2) {
              printf("Mengisi meja nomor %d\n", table);
              MakeFullTable2(R, table);
              DelEliQueue(Q,i,&X);
              X.NbTable = table;
              X.WaitTime = 30;
              // Add ke Array/List
              UbahEli(tables,X.NbTable,X);
              found = true;
            }
            i++;
            if (i > MaxEl(*Q)) {
              i = i - MaxEl(*Q);
            }
          }
        }
      }
    } else {
      CekKosong2(*R, &meja);
      if ((meja != -999) && ((table != -999)) && (IsKosong(*R,table))){
        printf("Mengisi meja nomor %d\n", table);
        MakeFullTable2(R, table);
        DelQueue(Q, &X);
        X.NbTable = table;
        X.WaitTime = 30;
        // Add ke array/list
        UbahEli(tables,X.NbTable,X);
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

void Order(ROOM *R, int room, POINT P, TabInt *orders, TabInt tables)
/* Mengambil order dari meja yang bersebelahan */
{
  //KAMUS LOKAL
  int meja;

  //ALGORITMA
  CekSebelahan(*R,room,P,&meja);
  if (meja != -999){
    //printf("%d\n",meja);
    UbahEli(orders,meja,ElmtArray(tables,meja));
    //printf("%d\n", ElmtArray((*orders),meja).Pesanan.Code);
    printf("Order berhasil! \n");
  }
}

void AddRemove(TabInt *orders, Queue *Q, Customer emptyOrder, JAM J, ROOM *R, POINT P, int *life, TabInt *tables)
/* Menambah Queue dan/atau mengurangi order berdasarkan waktu*/
{
  //KAMUS LOKAL
  int i,meja;
  Customer cust,X;

  //ALGORITMA
  for (i=1; i<=12; i++){
    if (ElmtArray((*orders),i).WaitTime != DataUndef){
      ElmtArray((*orders),i).WaitTime--;
    }
    if (ElmtArray((*tables),i).WaitTime != DataUndef){
      ElmtArray((*tables),i).WaitTime--;
    }
    if (ElmtArray((*tables),i).WaitTime == 0){
      meja = ElmtArray((*tables),i).NbTable;
      printf("Pengunjung meja %d pergi\n",meja);
      MakeEmptyTable(R,meja);
      UbahEli(orders,i,emptyOrder);
      UbahEli(tables,i,emptyOrder);
    }
  }

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

  if (!IsEmptyQueue(*Q)){
    if (WT(*Q, Head(*Q)) == 0) {
      DelQueue(Q, &X);
      (*life)--;
      //printf("Deleted\n");
    }
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

void  Recipe (BinTree *P)
/*Mencetak Resep yang digunakan pada Engi's Kitchen */
{
  //Kamus
  //Algoritma
  LoadTree(P);
  ShowBranch(*P);
}

/*FUNGSI PEMBANTU PUT */
void SearchBranch(BinTree *P, Stack * StackIn, Stack * StackOut)
/* I.S Isi awalnya harus piring, setiap pemanggilan rekursif, P merupakan isi yang pasti */
/* ada di dalam pohon resep */
/* F.S : */
/* Kalo Semua Bahan di StackIn sesuai alur resep, maka ret P akan merupakan BinTree uner */
/* Jika bahan di StackIn ada yang gak sesuai dengan alur resep, maka ret P pasti biner */
{
  //Kamus
  infotypeStackt X;
  //Algoritma
  if (!(IsUnerRight(*P) || IsUnerLeft(*P))){
    Pop(StackIn,&X); //Elemen pertama yang sudah dicek di rekursif sebelumnya
    Push(StackOut,X);
    if (InfoTop(*StackIn) == Akar(Left(*P))){
      *P = Left(*P);
      SearchBranch(P,StackIn,StackOut);
    }
    else if (InfoTop(*StackIn) == Akar(Right(*P))){
      *P = Right(*P);
      SearchBranch(P,StackIn,StackOut);
    }
    else{ //Elemen selanjutnya bukan kelanjutan bahan
      /*Do Nothing */
    }
  }
  else { //Sudah bahan Uner
    Pop(StackIn,&X);
    Push(StackOut, X);
  }
}

void Put (BinTree * P, Stack *Bahan,Stack *Food)
/* I.S : P, Bahan, dan Food semuanya harus sudah terdefinisi */
/* Prosedur ini mengecek apakah urutan bahan dalam Stack sudah benar dari bawah ke atas */
/* Jika benar , F.S semua bahan berurutan yang sesuai dengan resep yang ada pada BinTree dihilangkan,*/
/* dan makanan jadi ditambahkan pada Stack Food */
/* Jika tidak ada urutan bahan yang benar, tidak merubah apa-apa pada stack bahan dan stack food*/
{
  //Kamus
  Stack SIn, SOut;
  infotypeStackt X;
  //BinTree Px;
  //Algoritma
  CreateEmptyStackt(&SIn);
  CreateEmptyStackt(&SOut);
  while ((InfoTop(*Bahan) != 1) && (!IsEmptyStackt(*Bahan))){ //Cari piring di Stack
    Pop(Bahan,&X);
    Push(&SIn,X);
  }
  if (InfoTop(*Bahan) == 1){ //Kalo udah ketemu piring di Top Bahan
    //taro piring di SIn
    Pop(Bahan,&X);
    Push(&SIn,X);
    //Px = P; //Pindahin paddress piring ke Px
    SearchBranch(P, &SIn, &SOut); //Telusurin alur resepnya pake rekursif
    if (IsUnerLeft(*P) || IsUnerRight(*P)){ //Kalo sesuai resep
      //Pop Bahan Uner
      
      //Masukin makanan jadi ke Food
      if (IsUnerRight(*P)){
        Push(Food,Akar(Right(*P))); 
      }
      else if (IsUnerLeft(*P)){
        Push(Food, Akar(Left(*P)));
      }
      //Jika ada makanan yang sisa di SIn, balikin ke Stack Bahan
      while (!IsEmptyStackt(SIn)){
        Pop(&SIn,&X);
        Push(Bahan,X);
      }
    }
    else { //gak sesuai resep, balikin Bahan seperti sedia kala
      while(!(IsEmptyStackt(SOut))){
        Pop(&SOut,&X);
        Push(&SIn,X);
      }
      while(!(IsEmptyStackt(SIn))){
        Pop(&SIn,&X);
        Push(Bahan,X);
      }
    }
  }
  else { //Gak ada piring di stack Bahan 
    //Balikin SIn ke Bahan
    while (!IsEmptyStackt(SIn)){
      Pop(&SIn,&X);
      Push (Bahan, X);
    }
  }
}

//TESTER
/*
int main(){
  //Kamus
  BinTree Resep;
  Stack Hand,Food;
  infotypeStackt input;
  //Algoritma
  CreateEmptyStackt(&Hand);
  CreateEmptyStackt(&Food);
  Recipe(&Resep);
  puts("Masukan kode bahan : ");
  scanf("%d",&input);
  while(input != -999){
    Push(&Hand,input);
    puts("Masukan kode bahan : ");
    scanf("%d",&input);
  }
  printf("Stack Hand sebelum\n\n");
  PrintStackt(Hand);
  puts("\n");
  Put(&Resep, &Hand, &Food);
  printf("Stack Hand sesudah\n\n");
  PrintStackt(Hand);
  puts("\n");
  printf("Stack Food\n\n");
  PrintStackt(Food);
  puts("\n");  
  return 0;
}*/