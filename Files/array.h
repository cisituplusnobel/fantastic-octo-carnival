/* MODUL TABEL INTEGER */
/* Berisi definisi dan semua primitif pemrosesan tabel integer */
/* Penempatan elemen selalu rapat kiri */
/* Versi I : dengan banyaknya elemen didefinisikan secara eksplisit,
   memori tabel statik */

#ifndef ARRAY_H
#define ARRAY_H

#include "datatype.h"
#include "boolean.h"

/*  Kamus Umum */
#define IdxMaxArray 12
/* Indeks maksimum array, sekaligus ukuran maksimum array dalam C */
#define IdxMinArray 1
/* Indeks minimum array */
#define IdxUndefArray -999
/* Indeks NbTable tak terdefinisi*/

/* Definisi elemen dan koleksi objek */
typedef int IdxType;  /* type indeks */
typedef Order ElTypeArray;   /* type elemen tabel */
typedef struct {
	ElTypeArray TI[IdxMaxArray+1]; /* memori tempat penyimpan elemen (container) */
	int NeffArray; /* >=0, banyaknya elemen efektif */
} OrderList;

/* Indeks yang digunakan [IdxMinArray..IdxMaxArray] */
/* Jika T adalah OrderList, cara deklarasi dan akses: */
/* Deklarasi : T : OrderList */
/* Maka cara akses:
   T.NeffArray  untuk mengetahui banyaknya elemen
   T.TI    untuk mengakses seluruh nilai elemen tabel
   T.TI[i] untuk mengakses elemen ke-i */
/* Definisi :
  Tabel kosong: T.NeffArray = 0
  Definisi elemen pertama : T.TI[i] dengan i=1
  Definisi elemen terakhir yang terdefinisi: T.TI[i] dengan i=T.NeffArray */

/* ********** SELEKTOR ********** */
#define NeffArray(T)   (T).NeffArray
#define TI(T)     (T).TI
#define ElmtArray(T,i) (T).TI[(i)]
#define OrderCode(T,i) (T).TI[(i)].Code
#define OrderPrice(T,i) (T).TI[(i)].Price
#define OrderTable(T,i) (T).TI[(i)].NbTable


/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong  */
void MakeEmptyArray (OrderList * T);
/* I.S. T sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMaxArray-IdxMinArray+1 */

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int NbElmtArray (OrderList T);
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
/* *** Daya tampung container *** */
int MaxNbElArray (OrderList T);
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
/* *** Selektor INDEKS *** */
IdxType GetFirstIdxArray (OrderList T);
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T pertama */
IdxType GetLastIdxArray (OrderList T);
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T terakhir */

/* ********** Test Indeks yang valid ********** */

boolean IsIdxValidArray (OrderList T, IdxType i);
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/
boolean IsIdxEffArray (OrderList T, IdxType i);
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T) */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmptyArray (OrderList T);
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
/* *** Test tabel penuh *** */
boolean IsFullArray (OrderList T);
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */

/* ********** OPERASI LAIN ********** */
void CopyTab (OrderList Tin, OrderList * Tout);
/* I.S. Tin terdefinisi, Tout sembarang */
/* F.S. Tout berisi salinan dari Tin (elemen dan ukuran identik) */
/* Proses : Menyalin isi Tin ke Tout */
OrderList InverseTab (OrderList T);
/* Menghasilkan tabel dengan urutan tempat yang terbalik, yaitu : */
/* elemen pertama menjadi terakhir, */
/* elemen kedua menjadi elemen sebelum terakhir, dst.. */
/* Tabel kosong menghasilkan tabel kosong */
boolean IsSimetris (OrderList T);
/* Menghasilkan true jika tabel simetrik */
/* Tabel disebut simetrik jika: */
/*      elemen pertama = elemen terakhir, */
/*      elemen kedua = elemen sebelum terakhir, dan seterusnya */
/* Tabel kosong adalah tabel simetris */

/* ********** MENAMBAH ELEMEN ********** */
/* *** Menambahkan elemen terakhir *** */
void AddAsLastEl (OrderList * T, ElTypeArray X);
/* Proses: Menambahkan X sebagai elemen terakhir tabel */
/* I.S. Tabel T boleh kosong, tetapi tidak penuh */
/* F.S. X adalah elemen terakhir T yang baru */
void DelEli (OrderList * T, IdxType i, ElTypeArray * X);
/* Menghapus elemen ke-i tabel tanpa mengganggu kontiguitas */
/* I.S. Tabel tidak kosong, i adalah indeks efektif yang valid */
/* F.S. X adalah nilai elemen ke-i T sebelum penghapusan */
/*      Banyaknya elemen tabel berkurang satu */
/*      Tabel T mungkin menjadi kosong */
/* Proses : Geser elemen ke-i+1 s.d. elemen terakhir */
/*          Kurangi elemen efektif tabel */
void ORDER (OrderList *T ,ElTypeArray Pesanan);
/* Memasukkan pesanan ke dalam OrderList*/

void PrintOrder(OrderList T)
/* Menampilkan pesanan yang ada pada orderList*/

#endif
