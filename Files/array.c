/* Kelompok    : CisituPlusNobel
/* File        : array.c */
/* Tanggal     : 29 Oktober 2018 */

/* *** IMPLEMENTASI DARI HEADER *** */

#include "array.h"
#include <stdio.h>

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong  */
void MakeEmpty (TabInt * T)
/* I.S. T sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin+1 */
{
  Neff(*T) = 0;
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int NbElmtArray (TabInt T)
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
/* *** Daya tampung container *** */
{
  if (IsEmpty(T))
    return 0;
  else
    return(Neff(T));
}

int MaxNbEl (TabInt T)
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
{
  return(IdxMax);
}

/* *** Selektor INDEKS *** */
IdxType GetFirstIdx (TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T pertama */
{
  return(IdxMin);
}

IdxType GetLastIdx (TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T terakhir */
{
  return(GetFirstIdx(T)+Neff(T)-1);
}

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValidArray (TabInt T, IdxType i)
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/
{
  return((IdxMin <= i) && (IdxMax >= i));
}

boolean IsIdxEffArray (TabInt T, IdxType i)
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T) */
{
  return((GetFirstIdx(T) <= i) && (GetLastIdx(T) >= i));
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmpty (TabInt T)
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
/* *** Test tabel penuh *** */
{
  return(Neff(T) == 0);
}

boolean IsFull (TabInt T)
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */
{
  return(Neff(T) == IdxMax);
}

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi tabel dari pembacaan *** */

void TulisIsi (TabInt T)
/* Proses : Menuliskan isi tabel dengan traversal */
/* I.S. T boleh kosong */
/* F.S. Jika T tidak kosong : indeks dan elemen tabel ditulis berderet ke bawah */
/*      Jika T kosong : Hanya menulis "Tabel kosong" */
/* Contoh: Jika isi Tabel: [1, 20, 30, 50]
   Maka tercetak di layar:
   [1]1
   [2]20
   [3]30
   [4]50
*/
{
  //KAMUS LOKAL
  int i;

  //ALGORITMA
  if (IsEmpty(T))
    printf("Tabel kosong\n");
  else
    for (i=GetFirstIdx(T); i<=(GetLastIdx(T)); i++){
      //printf("[%d]%d\n", i, ElmtArray(T,i));
    }
}

void TulisIsiTab (TabInt T)
/* Proses : Menuliskan isi tabel dengan traversal, tabel ditulis di antara kurung siku; 
   antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
   di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. T boleh kosong */
/* F.S. Jika T tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika tabel kosong : menulis [] */
{
  //KAMUS LOKAL
  IdxType i;

  //ALGORITMA
  if (!IsEmpty(T)){
    for (i=GetFirstIdx(T); i<=(GetLastIdx(T)); i++){
      if (ElmtArray(T,i).Pesanan.Code != -999){
        printf("%s, %d\n", menu[ElmtArray(T,i).Pesanan.Code],i);
      }
    }
  }
}

boolean IsSame(ElTypeArray X1, ElTypeArray X2)
/**/
{
  return ((X1.NbPeople == X2.NbPeople) && (X1.WaitTime == X2.WaitTime) && (X1.NbTable == X2.NbTable) && (X1.Pesanan.Code == X2.Pesanan.Code));
    
}

/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika tabel : Penjumlahan, pengurangan, perkalian, ... *** */
/* ********** SEARCHING ********** */
/* ***  Perhatian : Tabel boleh kosong!! *** */
IdxType Search1 (TabInt T, ElTypeArray X)
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X */
/* Jika tidak ada, mengirimkan IdxUndef */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong */
/* Memakai skema search TANPA boolean */
{
  //KAMUS LOKAL
  IdxType i, temp;

  //ALGORITMA
   if (IsEmpty(T) == false){
    temp = IdxUndef;
    for(i=GetLastIdx(T); i>=GetFirstIdx(T); i--){
      if (IsSame(ElmtArray(T,i), X))
        temp = i;
    }
    return temp;
  }else
    return IdxUndef;
}

IdxType Search2 (TabInt T, ElTypeArray X)
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X */
/* Jika tidak ada, mengirimkan IdxUndef */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong */
/* Memakai skema search DENGAN boolean Found */
{
  //KAMUS LOKAL
  int i;
  boolean Found;

  //ALGORITMA
  if (IsEmpty(T) == false){
    i = GetFirstIdx(T);
    Found = false;
    while ((i<= GetLastIdx(T)) && (Found == false)){
      if (IsSame(ElmtArray(T,i), X))
         Found = true;
      else
        i++;
    }

    if (Found == true)
      return i;
    else
      return IdxUndef;

  }else return IdxUndef;
}

boolean SearchB (TabInt T, ElTypeArray X)
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan true, jika tidak ada menghasilkan false */
/* Memakai Skema search DENGAN boolean */
{
  //KAMUS LOKAL
  int i;
  boolean Found;

  //ALGORITMA
  if (IsEmpty(T) == false){
    i = GetFirstIdx(T);
    Found = false;
    while ((i<= GetLastIdx(T)) && (Found == false)){
      if (IsSame(ElmtArray(T,i), X))
         Found = true;
      else
        i++;
    }

    return Found;

  }else return false;
}

boolean SearchSentinel (TabInt T, ElTypeArray X)
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan true, jika tidak ada menghasilkan false */
/* dengan metoda sequential search dengan sentinel */
/* Untuk sentinel, manfaatkan indeks ke-0 dalam definisi array dalam Bahasa C 
   yang tidak dipakai dalam definisi tabel */
{
  //KAMUS LOKAL
  IdxType i;

  //ALGORITMA
  ElmtArray(T,0) = X;
  i = GetLastIdx(T);
  while((i>0) && !(IsSame(ElmtArray(T,i), X))){
    i--;
  }
  return (i>0);
}


/* ********** OPERASI LAIN ********** */
void CopyTab (TabInt Tin, TabInt * Tout)
/* I.S. Tin terdefinisi, Tout sembarang */
/* F.S. Tout berisi salinan dari Tin (elemen dan ukuran identik) */
/* Proses : Menyalin isi Tin ke Tout */
{
  //KAMUS LOKAL
  int i;

  //ALGORITMA
  Neff(*Tout) = Neff(Tin);
  for(i=GetFirstIdx(Tin); i<=GetLastIdx(Tin); i++){
    ElmtArray(*Tout,i) = ElmtArray(Tin,i);
  }
}

/* ********** MENAMBAH ELEMEN ********** */
/* *** Menambahkan elemen terakhir *** */
void AddAsLastEl (TabInt * T, ElTypeArray X)
/* Proses: Menambahkan X sebagai elemen terakhir tabel */
/* I.S. Tabel T boleh kosong, tetapi tidak penuh */
/* F.S. X adalah elemen terakhir T yang baru */
{
  ElmtArray(*T,GetLastIdx(*T)+1) = X;
  Neff(*T)++;
}

void AddEli (TabInt * T, ElTypeArray X, IdxType i)
/* Menambahkan X sebagai elemen ke-i tabel tanpa mengganggu kontiguitas 
   terhadap elemen yang sudah ada */
/* I.S. Tabel tidak kosong dan tidak penuh */
/*      i adalah indeks yang valid. */
/* F.S. X adalah elemen ke-i T yang baru */
/* Proses : Geser elemen ke-i+1 s.d. terakhir */
/*          Isi elemen ke-i dengan X */
{
	//KAMUS LOKAL
	IdxType j;
	
	//ALGORITMA
  Neff(*T)++;
  for(j=GetLastIdx(*T); j>=i+1; j--){
    ElmtArray(*T,j) = ElmtArray(*T,j-1);
  }
  ElmtArray(*T,i) = X;
}

/* ********** MENGHAPUS ELEMEN ********** */
void DelLastEl (TabInt * T, ElTypeArray * X)
/* Proses : Menghapus elemen terakhir tabel */
/* I.S. Tabel tidak kosong */
/* F.S. X adalah nilai elemen terakhir T sebelum penghapusan, */
/*      Banyaknya elemen tabel berkurang satu */
/*      Tabel T mungkin menjadi kosong */
{
  *X = ElmtArray(*T,GetLastIdx(*T)); 
  Neff(*T)--;
}

void DelEli (TabInt * T, IdxType i, ElTypeArray * X)
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
  for(j=i; j<=GetLastIdx(*T)-1; j++){
    ElmtArray(*T,j) = ElmtArray(*T,j+1);
  }
  Neff(*T)--;
}

void UbahEli (TabInt * T, IdxType i, ElTypeArray X)
/* */
{	
	//ALGORITMA
  ElmtArray((*T),i) = X;
}

/* ********** TABEL DGN ELEMEN UNIK (SETIAP ELEMEN HANYA MUNCUL 1 KALI) ********** */
void AddElUnik (TabInt * T, ElTypeArray X)
/* Menambahkan X sebagai elemen terakhir tabel, pada tabel dengan elemen unik */
/* I.S. Tabel T boleh kosong, tetapi tidak penuh */
/*      dan semua elemennya bernilai unik, tidak terurut */
/* F.S. Jika tabel belum penuh, menambahkan X sbg elemen terakhir T, 
        jika belum ada elemen yang bernilai X. 
		Jika sudah ada elemen tabel yang bernilai X maka I.S. = F.S. 
		dan dituliskan pesan "nilai sudah ada" */
/* Proses : Cek keunikan dengan sequential search dengan sentinel */
/*          Kemudian tambahkan elemen jika belum ada */
{
  if (SearchSentinel(*T, X) == true)
    printf("Nilai sudah ada\n");
  else{
    AddAsLastEl (&(*T), X);
	}
}

boolean IsEmptyOrders (TabInt T)
/**/
{
  //KAMUS LOKAL
  boolean found;
  int i;

  //ALGORITMA
  i=1;
  found = false;
  while (i != 12 && !found){
    if (ElmtArray(T,i).NbTable != DataUndef){
      found = true;
    } else{
      i++;
    }
  }
  return !found;
}
