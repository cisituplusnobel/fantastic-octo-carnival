/* Kelompok    : CisituPlusNobel
/* File        : listdp.c */
/* Tanggal     : 29 Oktober 2018 */

#include "listdp.h"
#include <stdio.h>
#include <stdlib.h>

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmptyList (List L)
/* Mengirim true jika list kosong. Lihat definisi di atas. */
{
    return((First(L) == Nil) && (Last(L) == Nil));
}

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmptyList (List *L)
/* I.S. L sembarang  */
/* F.S. Terbentuk list kosong. Lihat definisi di atas. */
{
    First(*L) = Nil;
    Last(*L) = Nil;
}

/****************** Manajemen Memori ******************/
address AlokasiList (infotype X)
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil. */
/* Misalnya: menghasilkan P, maka Info(P)=X, Next(P)=Nil, Prev(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil. */
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

void DealokasiList (address P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
{
	free(P);
}

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address SearchList (List L, infotype X)
/* Mencari apakah ada elemen list dengan Info(P)=X */
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
void InsVFirstList (List *L, infotype X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
{
	//KAMUS LOKAL
	address P;

	//ALGORITMA
	P = Alokasi(X);
	if (P != Nil){
		InsertFirst(L,P);
	}
}

void InsVLastList (List *L, infotype X)
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
void DelVFirstList (List *L, infotype *X)
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
{
	//KAMUS LOKAL
	address P;

	//ALGORITMA
	DelFirst(L,&P);
	*X = Info(P);
	Dealokasi(P);
}

void DelVLastList (List *L, infotype *X)
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */
{
	//KAMUS LOKAL
	address P;

	//ALGORITMA
	DelLast(L,&P);
	*X = Info(P);
	Dealokasi(P);
}

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirstList (List *L, address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
{
	Next(P) = First(*L);
	if (!IsEmpty(*L)){
		Prev(First(*L)) = P;
	} else{
		Last(*L) = P;
	}
	First(*L) = P;
}

void InsertLastList (List *L, address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
{
	Prev(P) = Last(*L);
	if (!IsEmpty(*L)){
		Next(Last(*L)) = P;
	} else{
		First(*L) = P;
	}
	Last(*L) = P;
}

void InsertAfterList (List *L, address P, address Prec)
/* I.S. Prec pastilah elemen list; P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
{
	if (Next(Prec) != Nil){
		Prev(Next(Prec)) = P;
	} else{
		Last(*L) = P;
	}
	Next(P) = Next(Prec);
	Prev(P) = Prec;
	Next(Prec) = P;
}

void InsertBeforeList (List *L, address P, address Succ)
/* I.S. Succ pastilah elemen list; P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sebelum elemen beralamat Succ */
{
	if (Prev(Succ) != Nil){
		Next(Prev(Succ)) = P;
	} else{
		First(*L) = P;
	}
	Prev(P) = Prev(Succ);
	Next(P) = Succ;
	Prev(Succ) = P;
}

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirstList (List *L, address *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
{
	*P = First(*L);
	if (First(*L) == Last(*L)){
		Last(*L) = Nil;
	} else{
		Prev(Next(First(*L))) = Nil;
	}
	First(*L) = Next(First(*L));
	Next(*P) = Nil;
	Prev(*P) = Nil;
}

void DelLastList (List *L, address *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yg lama, jika ada */
{
	*P = Last(*L);
	if (First(*L) == Last(*L)){
		First(*L) = Nil;
	} else{
		Next(Prev(Last(*L))) = Nil;
	}
	Last(*L) = Prev(Last(*L));
	Next(*P) = Nil;
	Prev(*P) = Nil;
}

void DelPList (List *L, infotype X)
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan Info(P)=X  */
/* maka P dihapus dari list dan didealokasi */
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
			DelAfter(L,&P,Prec);
			Dealokasi(P);
		}
	}
}

void DelAfterList (List *L, address *Pdel, address Prec)
/* I.S. List tidak kosong. Prec adalah anggota list. */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
{
	*Pdel = Next(Prec);
	if (Next(Next(Prec)) != Nil){
		Prev(Next(Next(Prec))) = Prec;
	} else{
		Last(*L) = Prec;
	}
	Next(Prec) = Next(Next(Prec));
	Next(*Pdel) = Nil;
	Prev(*Pdel) = Nil;
}

void DelBeforeList (List *L, address *Pdel, address Succ)
/* I.S. List tidak kosong. Succ adalah anggota list. */
/* F.S. Menghapus Prev(Succ): */
/*      Pdel adalah alamat elemen list yang dihapus  */
{
	*Pdel = Prev(Succ);
	if (Prev(Prev(Succ)) != Nil){
		Next(Prev(Prev(Succ))) = Succ;
	} else{
		First(*L) = Succ;
	}
	Prev(Succ) = Prev(Prev(Succ));
	Prev(*Pdel) = Nil;
	Next(*Pdel) = Nil;
}

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintForwardList (List L)
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, isi list dicetak dari elemen pertama */
/* ke elemen terakhir secara horizontal ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
{
	//KAMUS LOKAL
	address P;

	//ALGORITMA
	if (IsEmpty(L))
		printf("[]");
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

void PrintBackwardList (List L)
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, isi list dicetak dari elemen terakhir */
/* ke elemen pertama secara horizontal ke kanan: [en,en-1,...,e2,e1] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [30,20,1] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
{
	//KAMUS LOKAL
	address P;

	//ALGORITMA
	if (IsEmpty(L))
		printf("[]");
	else{
		P = Last(L);
		printf("[");
		while (P != Nil){
			printf("%d", Info(P));
			P = Prev(P);
			if (P != Nil){
				printf(",");
			}
		}
		printf("]");
	}
}
