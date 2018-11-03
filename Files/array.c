/* Kelompok    : CisituPlusNobel
/* File        : array.c */
/* Tanggal     : 29 Oktober 2018 */

/* *** IMPLEMENTASI DARI HEADER *** */

#include "array.h"
#include <stdio.h>

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong  */
void MakeEmptyArray (OrderList * T)
/* I.S. T sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMaxArray-IdxMinArray+1 */
{
  NeffArray(*T) = 0;
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int NbElmtArray (OrderList T)
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
/* *** Daya tampung container *** */
{
  if (IsEmptyArray(T))
    return 0;
  else
    return(NeffArray(T));
}

int MaxNbElArray (OrderList T)
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
{
  return(IdxMaxArray);
}

/* *** Selektor INDEKS *** */
IdxType GetFirstIdxArray (OrderList T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T pertama */
{
  return(IdxMinArray);
}

IdxType GetLastIdxArray (OrderList T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T terakhir */
{
  return(GetFirstIdxArray(T)+NeffArray(T)-1);
}

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValidArray (OrderList T, IdxType i)
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/
{
  return((IdxMinArray <= i) && (IdxMaxArray >= i));
}

boolean IsIdxEffArray (OrderList T, IdxType i)
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T) */
{
  return((GetFirstIdxArray(T) <= i) && (GetLastIdxArray(T) >= i));
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmptyArray (OrderList T)
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
/* *** Test tabel penuh *** */
{
  return(NeffArray(T) == 0);
}

boolean IsFullArray (OrderList T)
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */
{
  return(NeffArray(T) == IdxMaxArray);
}



/* ********** OPERASI LAIN ********** */
void CopyTab (OrderList Tin, OrderList * Tout)
/* I.S. Tin terdefinisi, Tout sembarang */
/* F.S. Tout berisi salinan dari Tin (elemen dan ukuran identik) */
/* Proses : Menyalin isi Tin ke Tout */
{
  //KAMUS LOKAL
  int i;

  //ALGORITMA
  NeffArray(*Tout) = NeffArray(Tin);
  for(i=GetFirstIdxArray(Tin); i<=GetLastIdxArray(Tin); i++){
    ElmtArray(*Tout,i) = ElmtArray(Tin,i);
  }
}

OrderList InverseTab (OrderList T)
/* Menghasilkan tabel dengan urutan tempat yang terbalik, yaitu : */
/* elemen pertama menjadi terakhir, */
/* elemen kedua menjadi elemen sebelum terakhir, dst.. */
/* Tabel kosong menghasilkan tabel kosong */
{
  //KAMUS LOKAL
  OrderList temp;
  IdxType i;

  //ALGORITMA
  NeffArray(temp) = NeffArray(T);
  for(i=GetFirstIdxArray(T); i<=GetLastIdxArray(T); i++){
    ElmtArray(temp,i) = ElmtArray(T,(GetLastIdxArray(T)+1-i));
  }
  
  return temp;
}

boolean IsSimetris (OrderList T)
/* Menghasilkan true jika tabel simetrik */
/* Tabel disebut simetrik jika: */
/*      elemen pertama = elemen terakhir, */
/*      elemen kedua = elemen sebelum terakhir, dan seterusnya */
/* Tabel kosong adalah tabel simetris */
{
  return(IsEQ(T, InverseTab(T)));
}


/* ********** MENAMBAH ELEMEN ********** */
/* *** Menambahkan elemen terakhir *** */
void AddAsLastEl (OrderList * T, ElTypeArray X)
/* Proses: Menambahkan X sebagai elemen terakhir tabel */
/* I.S. Tabel T boleh kosong, tetapi tidak penuh */
/* F.S. X adalah elemen terakhir T yang baru */
{
  ElmtArray(*T,GetLastIdxArray(*T)+1) = X;
  NeffArray(*T)++;
}

void DelEli (OrderList * T, IdxType i, ElTypeArray * X)
/* Menghapus elemen ke-i tabel tanpa mengganggu kontiguitas */
/* I.S. Tabel tidak kosong, i adalah indeks efektif yang valid */
/* F.S. X adalah nilai elemen ke-i T sebelum penghapusan */
/*      Banyaknya elemen tabel berkurang satu */
/*      Tabel T mungkin menjadi kosong */
/* Proses : Geser elemen ke-i+1 s.d. elemen terakhir */
/*          Kurangi elemen efektif tabel */
{
	//KAMUS LOKAL
	IdxType j;
	
	//ALGORITMA
  *X = ElmtArray(*T,i);
  for(j=i; j<=GetLastIdxArray(*T)-1; j++){
    ElmtArray(*T,j) = ElmtArray(*T,j+1);
  }
  NeffArray(*T)--;
}

void ORDER (OrderList *T ,ElTypeArray Pesanan)
/* Memasukkan pesanan ke dalam OrderList*/
{
  //Kamus
  //Algoritmma
  AddAsLastEl(T, Pesanan);
}

//void PrintOrder (OrderList T)
/* Menampilkan pesanan yang ada pada orderList*/
/*{
  //KAMUS
  FILE *MenuList;
  char temp,MenuNumber,MenuItem[30];
  //Algoritma
  if (IsEmptyArray(T)){
    printf("Empty\n");
  }
  else{
    for (int i = 1; i <= GetLastIdxArray(T); i++){
      MenuList = fopen("FoodList.txt","r");
      if (MenuList == NULL){
        perror("Tidak bisa membaca Daftar Menu\n");
        break;
      }
      while (temp = fgetc(MenuList) != EOF){
        MenuNumber = temp;
        fgets(MenuItem, 30, MenuList);
        if(MenuNumber == (OrderCode(T,i) - '0')){
          printf("%s, %c\n",MenuItem, OrderTable(T,i));
        }
      }
      fclose(MenuList);
    }
  }
}*/
