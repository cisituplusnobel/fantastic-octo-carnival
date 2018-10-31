/* Kelompok    : CisituPlusNobel
/* File        : listlinierc */
/* Tanggal     : 29 Oktober 2018 */

#include "listlinier.h"
#include <stdio.h>
#include <stdlib.h>

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmpty (List L)
/* Mengirim true jika list kosong */
{
	return(First(L) == Nil);
}
/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty (List *L)
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */
{
	First(*L) = Nil;
}

/****************** Manajemen Memori ******************/
address Alokasi (infotype X)
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
{
	//KAMUS LOKAL
	address P;

	//ALGORITMA
	P = (address) malloc (sizeof(ElmtList));
	if (P == Nil)
		return Nil;
	else{
		Info(P) = X;
		Next(P) = Nil;
		return P;
	}
}

void Dealokasi (address *P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
{
	free(*P);
}

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address Search (List L, infotype X)
/* Mencari apakah ada elemen list dengan Info(P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */
{
	//KAMUS LOKAL
	boolean found;
	address P;

	//ALGORITMA
	P = First(L);
	found = false;
	while ((P != Nil) && (!found)){
		if (X == Info(P))
			found = true;
		else
			P = Next(P);
	}
	if (!found)
		return Nil;
	else
		return P;
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (List *L, infotype X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
{
	// KAMUS LOKAL
	address P;

	//ALGORITMA
	P = Alokasi(X);
	if (P != Nil){
		Next(P) = First(*L);
		First(*L) = P;
	}
}

void InsVLast (List *L, infotype X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
{
	//KAMUS LOKAL
	address P;

	//ALGORITMA
	P = Alokasi(X);
	if (P != Nil){
		InsertLast(L,P);
	}
}

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (List *L, infotype *X)
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
{
	//KAMUS LOKAL
	address P;

	//ALGORITMA
	P = First(*L);
	First(*L) = Next(First(*L));
	Next(P) = Nil;
	*X = Info(P);
	Dealokasi(&P);
}

void DelVLast (List *L, infotype *X)
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */
{
	//KAMUS LOKAL
	address Last,PrecLast;

	//ALGORITMA
	Last = First(*L);
	PrecLast = Nil;
	while (Next(Last) != Nil){
		PrecLast = Last;
		Last = Next(Last);
	}
	*X = Info(Last);
	Dealokasi(&Last);
	if (PrecLast == Nil)
		First(*L) = Nil;
	else
		Next(PrecLast) = Nil;
}

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (List *L, address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
{
	Next(P) = First(*L);
	First(*L) = P;
}

void InsertAfter (List *L, address P, address Prec)
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
{
	Next(P) = Next(Prec);
	Next(Prec) = P;
}

void InsertLast (List *L, address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
{
	//KAMUS LOKAL
	address Last;

	//ALGORITMA
	if (IsEmpty(*L))
		InsertFirst(L,P);
	else{
		Last = First(*L);
		while (Next(Last) != Nil){
			Last = Next(Last);
		}
		InsertAfter(L,P,Last);
	}
}

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (List *L, address *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
{
	*P = First(*L);
	First(*L) = Next(First(*L));
	Next(*P) = Nil;
}

void DelP (List *L, infotype X)
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan Info(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
{
	//KAMUS LOKAL
	address Prec,P;
	boolean found;

	//ALGORITMA
	P = First(*L);
	Prec = Nil;
	found = false;
	while ((!found) && (P != Nil)){
		if (Info(P) == X){
			found = true;
		} else{
			Prec = P;
			P = Next(P);
		}
	}
	if (found){
		if (Prec == Nil){
			DelVFirst(L,&X);
		} else{
			DelAfter(&L,&P,Prec);
			Dealokasi(&P);
		}
	}
}

void DelLast (List *L, address *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yg lama, */
/* jika ada */
{
	//KAMUS LOKAL
	address Last, PrecLast;

	//ALGORITMA
	Last = First(*L);
	PrecLast = Nil;
	while (Next(Last) != Nil){
		PrecLast = Last;
		Last = Next(Last);
	}
	*P = Last;
	if (PrecLast == Nil)
		First(*L) = Nil;
	else
		Next(PrecLast) = Nil;
}

void DelAfter (List *L, address *Pdel, address Prec)
/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
{
	*Pdel = Next(Prec);
	Next(Prec) = Next(Next(Prec));
	Next(*Pdel) = Nil;
}

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintInfo (List L)
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
{
	//KAMUS LOKAL
	address P;

	//ALGORITMA
	if (IsEmpty(L))
		printf("[]\n");
	else{
		P = First(L);
		printf("[");
		while (P != Nil){
			printf("%d", Info(P));
			P = Next(P);
			if (P != Nil){
				printf(",");
			}
		}
		printf("]");
	}
}

int NbElmt (List L)
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
{
	//KAMUS LOKAL
	int count;
	address P;

	//ALGORITMA
	count = 0;
	P = First(L);
	while (P != Nil){
		count++;
		P = Next(P);
	}
	return count;
}

/*** Prekondisi untuk Max/Min/rata-rata : List tidak kosong ***/
infotype Max (List L)
/* Mengirimkan nilai Info(P) yang maksimum */
{
	//KAMUS LOKAL
	infotype max;
	address P;

	//ALGORITMA
	P = First(L);
	max = Info(P);
	P = Next(P);
	while (P != Nil){
		if (Info(P) > max){
			max = Info(P);
		}
		P = Next(P);
	}

	return max;
}
/****************** PROSES TERHADAP LIST ******************/
void Konkat1 (List *L1, List *L2, List *L3)
/* I.S. L1 dan L2 sembarang */
/* F.S. L1 dan L2 kosong, L3 adalah hasil konkatenasi L1 & L2 */
/* Konkatenasi dua buah list : L1 dan L2    */
/* menghasilkan L3 yang baru (dengan elemen list L1 dan L2) */
/* dan L1 serta L2 menjadi list kosong.*/
/* Tidak ada alokasi/dealokasi pada prosedur ini */
{
	//KAMUS LOKAL
	address Last1;

	//ALGORITMA
	CreateEmpty(L3);
	if (IsEmpty(*L1))
		First(*L3) = First(*L2);
	else{
		First(*L3) = First(*L1);
		Last1 = First(*L1);
		while (Next(Last1) != Nil){
			Last1 = Next(Last1);
		}
		Next(Last1) = First(*L2);
	}
	CreateEmpty(L1);
	CreateEmpty(L2);
}