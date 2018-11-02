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
    return((FirstList(L) == Nil) && (LastList(L) == Nil));
}

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmptyList (List *L)
/* I.S. L sembarang  */
/* F.S. Terbentuk list kosong. Lihat definisi di atas. */
{
    FirstList(*L) = Nil;
    LastList(*L) = Nil;
}

/****************** Manajemen Memori ******************/
address AlokasiList (infotype X)
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil. */
/* Misalnya: menghasilkan P, maka InfoList(P)=X, NextList(P)=Nil, PrevList(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil. */
{
    //KAMUS LOKAL
	address P;

	//ALGORITMA
	P = (address) malloc (sizeof(ElmtList));
	if (P == Nil)
		return Nil;
	else{
		InfoList(P) = X;
		NextList(P) = Nil;
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
/* Mencari apakah ada elemen list dengan InfoList(P)=X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */
{
	//KAMUS LOKAL
	boolean found;
	address P;

	//ALGORITMA
	P = FirstList(L);
	found = false;
	while ((P != Nil) && (!found)){
		if (X == InfoList(P))
			found = true;
		else
			P = NextList(P);
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
	P = AlokasiList(X);
	if (P != Nil){
		InsertFirstList(L,P);
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
	P = AlokasiList(X);
	if (P != Nil){
		InserLastListList(L,P);
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
	DelFirstList(L,&P);
	*X = InfoList(P);
	DealokasiList(P);
}

void DelVLastList (List *L, infotype *X)
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */
{
	//KAMUS LOKAL
	address P;

	//ALGORITMA
	DelLastList(L,&P);
	*X = InfoList(P);
	DealokasiList(P);
}

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirstList (List *L, address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
{
	NextList(P) = FirstList(*L);
	if (!IsEmptyList(*L)){
		PrevList(FirstList(*L)) = P;
	} else{
		LastList(*L) = P;
	}
	FirstList(*L) = P;
}

void InsertLastList (List *L, address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
{
	PrevList(P) = LastList(*L);
	if (!IsEmptyList(*L)){
		NextList(LastList(*L)) = P;
	} else{
		FirstList(*L) = P;
	}
	LastList(*L) = P;
}

void InsertAfterList (List *L, address P, address Prec)
/* I.S. Prec pastilah elemen list; P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
{
	if (NextList(Prec) != Nil){
		PrevList(NextList(Prec)) = P;
	} else{
		LastList(*L) = P;
	}
	NextList(P) = NextList(Prec);
	PrevList(P) = Prec;
	NextList(Prec) = P;
}

void InsertBeforeList (List *L, address P, address Succ)
/* I.S. Succ pastilah elemen list; P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sebelum elemen beralamat Succ */
{
	if (PrevList(Succ) != Nil){
		NextList(PrevList(Succ)) = P;
	} else{
		FirstList(*L) = P;
	}
	PrevList(P) = PrevList(Succ);
	NextList(P) = Succ;
	PrevList(Succ) = P;
}

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirstList (List *L, address *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
{
	*P = FirstList(*L);
	if (FirstList(*L) == LastList(*L)){
		LastList(*L) = Nil;
	} else{
		PrevList(NextList(FirstList(*L))) = Nil;
	}
	FirstList(*L) = NextList(FirstList(*L));
	NextList(*P) = Nil;
	PrevList(*P) = Nil;
}

void DelLastList (List *L, address *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yg lama, jika ada */
{
	*P = LastList(*L);
	if (FirstList(*L) == LastList(*L)){
		FirstList(*L) = Nil;
	} else{
		NextList(PrevList(LastList(*L))) = Nil;
	}
	LastList(*L) = PrevList(LastList(*L));
	NextList(*P) = Nil;
	PrevList(*P) = Nil;
}

void DelPList (List *L, infotype X)
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan InfoList(P)=X  */
/* maka P dihapus dari list dan didealokasi */
/* Jika tidak ada elemen list dengan InfoList(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
{
	//KAMUS LOKAL
	address Prec,P;
	boolean found;

	//ALGORITMA
	P = FirstList(*L);
	Prec = Nil;
	found = false;
	while ((!found) && (P != Nil)){
		if (InfoList(P) == X){
			found = true;
		} else{
			Prec = P;
			P = NextList(P);
		}
	}
	if (found){
		if (Prec == Nil){
			DelVFirstList(L,&X);
		} else{
			DelAfterList(L,&P,Prec);
			DealokasiList(P);
		}
	}
}

void DelAfterList (List *L, address *Pdel, address Prec)
/* I.S. List tidak kosong. Prec adalah anggota list. */
/* F.S. Menghapus NextList(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
{
	*Pdel = NextList(Prec);
	if (NextList(NextList(Prec)) != Nil){
		PrevList(NextList(NextList(Prec))) = Prec;
	} else{
		LastList(*L) = Prec;
	}
	NextList(Prec) = NextList(NextList(Prec));
	NextList(*Pdel) = Nil;
	PrevList(*Pdel) = Nil;
}

void DelBeforeList (List *L, address *Pdel, address Succ)
/* I.S. List tidak kosong. Succ adalah anggota list. */
/* F.S. Menghapus PrevList(Succ): */
/*      Pdel adalah alamat elemen list yang dihapus  */
{
	*Pdel = PrevList(Succ);
	if (PrevList(PrevList(Succ)) != Nil){
		NextList(PrevList(PrevList(Succ))) = Succ;
	} else{
		FirstList(*L) = Succ;
	}
	PrevList(Succ) = PrevList(PrevList(Succ));
	PrevList(*Pdel) = Nil;
	NextList(*Pdel) = Nil;
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
	if (IsEmptyList(L))
		printf("[]");
	else{
		P = FirstList(L);
		printf("[");
		while (P != Nil){
			printf("%d", InfoList(P));
			P = NextList(P);
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
	if (IsEmptyList(L))
		printf("[]");
	else{
		P = LastList(L);
		printf("[");
		while (P != Nil){
			printf("%d", InfoList(P));
			P = PrevList(P);
			if (P != Nil){
				printf(",");
			}
		}
		printf("]");
	}
}
