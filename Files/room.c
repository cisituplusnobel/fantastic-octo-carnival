/* Kelompok    : CisituPlusNobel
/* File        : room.c */
/* Tanggal     : 29 Oktober 2018 */

#include "room.h"


void MakeEmptyTable(ROOM *R, int table)
/*  Membuat meja menjadi kosong. Meja kosong ditandai dengan X. Procedure ini hanya merubah
    tampilan pada matriks saja.*/
{
  // KAMUS LOKAL
  int meja; //meja untuk menampung nilai table%4
  int ruang;
  char num[13][1];

  //ALGORITMA
  table--;
  meja = (table%4)+1;
  ruang = (table/4)+1;
  if (meja==1){
    ElmtMATRIKS(Elm(*R,ruang),1,2) = 'X';
    ElmtMATRIKS(Elm(*R,ruang),2,1) = 'X';
    ElmtMATRIKS(Elm(*R,ruang),2,3) = 'X';
    ElmtMATRIKS(Elm(*R,ruang),3,2) = 'X';
    ElmtMATRIKS(Elm(*R,ruang),2,2) = '1'; 
  } else if (meja==2){
    ElmtMATRIKS(Elm(*R,ruang),2,6) = 'X';
    ElmtMATRIKS(Elm(*R,ruang),2,8) = 'X';
    ElmtMATRIKS(Elm(*R,ruang),2,7) = '2';
  } else if (meja==3){
    ElmtMATRIKS(Elm(*R,ruang),6,2) = 'X';
    ElmtMATRIKS(Elm(*R,ruang),7,1) = 'X';
    ElmtMATRIKS(Elm(*R,ruang),7,3) = 'X';
    ElmtMATRIKS(Elm(*R,ruang),8,2) = 'X';
    ElmtMATRIKS(Elm(*R,ruang),7,2) = '3';
  } else if (meja==4){
    ElmtMATRIKS(Elm(*R,ruang),7,6) = 'X';
    ElmtMATRIKS(Elm(*R,ruang),7,8) = 'X';
    ElmtMATRIKS(Elm(*R,ruang),7,7) = '4';
  }
}

void MakeFullTable4(ROOM *R, int table)
/*  Membuat meja yang kapasitasnya 4 menjadi penuh. Meja penuh ditandai dengan C. Procedure 
    ini hanya merubah tampilan pada matriks saja.*/
{
  // KAMUS LOKAL
  int meja; //meja untuk menampung nilai table%4 + 1
  int ruang;
  char num[13][1];

  //ALGORITMA
  table--;
  meja = (table%4)+1;
  ruang = (table/4)+1;
  if (meja==1){
    ElmtMATRIKS(Elm(*R,ruang),1,2) = 'C';
    ElmtMATRIKS(Elm(*R,ruang),2,1) = 'C';
    ElmtMATRIKS(Elm(*R,ruang),2,3) = 'C';
    ElmtMATRIKS(Elm(*R,ruang),3,2) = 'C';
    ElmtMATRIKS(Elm(*R,ruang),2,2) = '1';
  } else if (meja==3){
    ElmtMATRIKS(Elm(*R,ruang),6,2) = 'C';
    ElmtMATRIKS(Elm(*R,ruang),7,1) = 'C';
    ElmtMATRIKS(Elm(*R,ruang),7,3) = 'C';
    ElmtMATRIKS(Elm(*R,ruang),8,2) = 'C';
    ElmtMATRIKS(Elm(*R,ruang),7,2) = '3';
  }
}

void MakeFullTable2(ROOM *R, int table)
/*  Membuat meja yang kapasitasnya 2 atau 4 menjadi penuh. Meja penuh ditandai dengan C. Procedure 
    ini hanya merubah tampilan pada matriks saja.*/
{
  // KAMUS LOKAL
  int meja; //meja untuk menampung nilai table%4 + 1
  int ruang;
  char num[13][1];

  //ALGORITMA
  table--;
  meja = (table%4)+1;
  ruang = (table/4)+1;
  if (meja==1){
    ElmtMATRIKS(Elm(*R,ruang),1,2) = 'X';
    ElmtMATRIKS(Elm(*R,ruang),2,1) = 'C';
    ElmtMATRIKS(Elm(*R,ruang),2,3) = 'C';
    ElmtMATRIKS(Elm(*R,ruang),3,2) = 'X';
    ElmtMATRIKS(Elm(*R,ruang),2,2) = '1';
  } else if (meja==3){
    ElmtMATRIKS(Elm(*R,ruang),6,2) = 'X';
    ElmtMATRIKS(Elm(*R,ruang),7,1) = 'C';
    ElmtMATRIKS(Elm(*R,ruang),7,3) = 'C';
    ElmtMATRIKS(Elm(*R,ruang),8,2) = 'X';
    ElmtMATRIKS(Elm(*R,ruang),7,2) = '3';     
  } else if (meja==2){
    ElmtMATRIKS(Elm(*R,ruang),2,6) = 'C';
    ElmtMATRIKS(Elm(*R,ruang),2,8) = 'C';
    ElmtMATRIKS(Elm(*R,ruang),2,7) = '2';
  } else if (meja==4){
    ElmtMATRIKS(Elm(*R,ruang),7,6) = 'C';
    ElmtMATRIKS(Elm(*R,ruang),7,8) = 'C';
    ElmtMATRIKS(Elm(*R,ruang),7,7) = '4';
  }
}

void MakeKitchen(ROOM *R)
/*  Membuat bentuk denah kitchen. Setiap tempat bahan makanan ditandai dengan M dan nampan ditandai
    dengan T */
{
  ElmtMATRIKS(Elm(*R,4),1,1) = 'M';
  ElmtMATRIKS(Elm(*R,4),2,1) = 'M';
  ElmtMATRIKS(Elm(*R,4),3,1) = 'M';
  ElmtMATRIKS(Elm(*R,4),4,1) = 'M';
  ElmtMATRIKS(Elm(*R,4),5,1) = 'M';
  ElmtMATRIKS(Elm(*R,4),6,1) = 'M';
  ElmtMATRIKS(Elm(*R,4),7,1) = 'M';
  ElmtMATRIKS(Elm(*R,4),8,1) = 'M'; 
  ElmtMATRIKS(Elm(*R,4),5,4) = 'M';
  ElmtMATRIKS(Elm(*R,4),5,5) = 'M';
  ElmtMATRIKS(Elm(*R,4),8,4) = 'M';
  ElmtMATRIKS(Elm(*R,4),8,5) = 'M';
  ElmtMATRIKS(Elm(*R,4),8,6) = 'M';
  ElmtMATRIKS(Elm(*R,4),8,7) = 'M';
  ElmtMATRIKS(Elm(*R,4),8,8) = 'M';
  ElmtMATRIKS(Elm(*R,4),1,8) = 'T';
}

boolean IsKosong(ROOM R, int table)
/*  Mengecek apakah meja kosong atau tidak. Proses pengecekan masih prmitif karena hanya melihat
    isi matriksnya (X atau C). Menghasilkan true jika meja kosong */
{
  //KAMUS LOKAL
  int meja, ruang;

  //ALGORITMA
  table--;
  meja = (table%4)+1;
  ruang = (table/4)+1;
  if (meja==1){
    if (ElmtMATRIKS(Elm(R,ruang),2,1) == 'C'){
      return false;
    }else{
      return true;
    }
  } else if (meja==2){
    if (ElmtMATRIKS(Elm(R,ruang),2,6) == 'C'){
      return false;
    }else{
      return true;
    }
  } else if (meja==3){
    if (ElmtMATRIKS(Elm(R,ruang),7,1) == 'C'){
      return false;
    } else{
      return true;
    }
  } else if (meja==4){
    if (ElmtMATRIKS(Elm(R,ruang),7,6) == 'C'){
      return false;
    }else{
      return true;
    }
  }
}

void CekKosong4(ROOM R, int *table)
/*  Melakukan pengecekan apakah terdapat meja dengan kapasitas 4 yang kosong. Pengeekan masih
    dilakukan primitif karena hanya meihat isi matriksnya saja (X atau C). Jika terdapat meja
    dengan kapasitas 4 yang kosong, maka room dan table akan diisi dengan ruangan dan nomor meja
    ditemukannya meja kosong. Jika tidak room dan table akan diisi dengan -999 */
{
  //KAMUS LOKAL
  int i;
  boolean kosong;

  //ALGORITMA
  i=1;
  kosong = false;
  *table = -999;
  while (i<=12 && !kosong){
    if (IsKosong(R,i)){
      kosong = true;
      *table = i;
    }else{
      i=i+2;
    }
  }
}

void CekKosong2(ROOM R, int *table)
/*  Melakukan pengecekan apakah terdapat meja dengan kapasitas 2 yang kosong. Pengeekan masih
    dilakukan primitif karena hanya meihat isi matriksnya saja (X atau C). Jika terdapat meja
    dengan kapasitas 2 yang kosong, maka room dan table akan diisi dengan ruangan dan nomor meja
    ditemukannya meja kosong. Jika tidak room dan table akan diisi dengan -999 */
{
  //KAMUS LOKAL
  int i;
  boolean kosong;

  //ALGORITMA
  i=2;
  kosong = false;
  *table = -999;
  while (i<=12 && !kosong){
    if (IsKosong(R,i)){
      kosong = true;
      *table = i;
    }else{
      i=i+2;
    }
  }
  i=1;
  while (i<=12 && !kosong){
    if (IsKosong(R,i)){
      kosong = true;
      *table = i;
    }else{
      i=i+2;
    }
  }
}

void CekSebelahan(ROOM R,int room, POINT P,int *table)
/*  Melakukan oengecekan apakah koordinat player (P) bersebelahan dengan salah satu meja
    Jika bersebelahan maka akan meja akan diisi dengan nomor meja yang bersebelahan*/
{
  if (room != 4){
    if ((Absis(P)==1 && Ordinat(P)==3) || (Absis(P)==3 && Ordinat(P)==1) || (Absis(P)==3 && Ordinat(P)==3)){
      *table = ((room-1)*4)+1;
    } else if ((Absis(P)==1 && Ordinat(P)==6) || (Absis(P)==1 && Ordinat(P)==7) || (Absis(P)==1 && Ordinat(P)==8) || (Absis(P)==3 && Ordinat(P)==6) || (Absis(P)==3 && Ordinat(P)==7) || (Absis(P)==3 && Ordinat(P)==8)){
      *table = ((room-1)*4)+2;
    } else if ((Absis(P)==6 && Ordinat(P)==1) || (Absis(P)==6 && Ordinat(P)==3) || (Absis(P)==8 && Ordinat(P)==3)){
      *table = ((room-1)*4)+3;
    } else if ((Absis(P)==6 && Ordinat(P)==6) || (Absis(P)==6 && Ordinat(P)==7) || (Absis(P)==6 && Ordinat(P)==8) || (Absis(P)==8 && Ordinat(P)==6) || (Absis(P)==8 && Ordinat(P)==7) || (Absis(P)==8 && Ordinat(P)==8)){
      *table = ((room-1)*4)+4;
    } else{
      *table = -999;
    }
  } else{
    *table = -999;
  }
}

void Inisalisasi(ROOM *R, POINT *P, JAM *J, Queue *Q, Stack *S, TabInt *orders, TabInt *tables, Customer *emptyOrder)
/*  Melakukan inisalisasi pada bentuk setiap room yaitu ruangan dalam representasi matriks, koordinat pemain,
    waktu pemain, antrian, stack of foods, array of orders, list of tables */
{
  //KAMUS LOKAL
  int i,j,k;
  Customer cust;

  //ALGORITMA
  for (i=1; i<=4; i++){
    MakeMATRIKS(8,8,&(Elm(*R,i)));
  }

  for (i=1; i<=4; i++){
    for (j=1; j<=8; j++){
      for (k=1; k<=8; k++){
        ElmtMATRIKS(Elm(*R,i),j,k) = ' ';
      }
    }
    if (i!=4){
      for (j=1; j<=12; j++){
        MakeEmptyTable(R,j);
      }
    }
  }
  MakeKitchen(R);
  *P = MakePOINT(4,4);
  *J = MakeJAM(0,0,0);
  CreateEmptyQueue(Q,10);
  cust.NbPeople = 4;
  cust.WaitTime = 31;
  cust.NbTable = -999;
  cust.Pesanan.Code = 1;
  cust.Pesanan.Price = 15000;
  AddQueue(Q, cust);

  CreateEmptyStackt(S);
  (*emptyOrder).NbPeople = DataUndef;
  (*emptyOrder).WaitTime = DataUndef;
  (*emptyOrder).NbTable = DataUndef;
  (*emptyOrder).Pesanan.Code = DataUndef;
  (*emptyOrder).Pesanan.Price = DataUndef;
  MakeEmpty(orders);
  for (i=1;i<=12;i++){
    AddEli(orders,*emptyOrder,i);
  }
  
  MakeEmpty(tables);
  for (i=1;i<=12;i++){
    AddEli(tables,*emptyOrder,i);
  }
}