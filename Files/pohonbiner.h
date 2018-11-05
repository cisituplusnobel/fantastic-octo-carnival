
/**********************ADT Pohon Biner*******************/

#ifndef pohonbiner_h
#define pohonbiner_h

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "mesinkata.h"

/*** Definisi Type Pohon Biner ***/
typedef Kata infotype;
typedef struct tNode *paddress;
typedef struct tNode {
	infotype Info;
	paddress Left;
	paddress Right;
} node;
typedef paddress BinTree;

/*** Definisi Type List of Node ***/
//typedef List ListOfNode;
#define Nil NULL
/*** Selektor ***/
//#define Akar(P) (P)->Info
//Mengirimkan nilai Akar pohon biner P
#define Left(P) (P)->Left
//Mengirimkan Anak Kiri pohon biner P
#define Right(P) (P)->Right
//Mengirimkan Anak Kanan pohon biner P
#define NamaResep(P) (P)->Info.TabKata
/* String Nama Resep */
#define PanjangResep(P) (P)->Info.Length
/* Banyak Huruf Dari Resep */

/*** Konstruktor ***/
void Allocate (paddress *P);
/* I.S. sembarang */
/* F.S. mengalokasi P, menghasilkan Nil jika gagal */
BinTree Tree (infotype A, BinTree L, BinTree R);
//Menghasilkan sebuah pohon biner dari A, L, dan R, jika alokasi berhasil
//Menghasilkan pohon kosong (Nil) jika alokasi gagal

void MakeTree (infotype Akar, BinTree L, BinTree R, BinTree *P);
//I.S. Sembarang 
//F.S. Menghasilkan sebuah pohon P 
//Menghasilkan sebuah pohon biner P dari A, L, dan R, jika alokasi berhasil 
//Menghasilkan pohon P yang kosong (Nil) jika alokasi gagal 
void LoadResep(BinTree*P);
/*Mengambil Resep dari File Eksternal dan Menyusunnya dalam pohon resep */
void BuildResep (BinTree *P);
//Membentuk sebuah pohon biner P dari pita karakter yang dibaca }
//I.S. Pita berisi "konstanta" pohon dalam bentuk prefix.
//Memori pasti cukup, alokasi pasti berhasil. }
//F.S. P dibentuk dari ekspresi dalam pita }

/*** Predikat-Predikat Penting ***/
boolean IsTreeEmpty (BinTree P);
//Mengirimkan true jika P adalah pohon biner kosong

boolean IsOneElmt (BinTree P);
//Mengirimkan true jika P adalah pohon biner tidak kosong dan
//hanya memiliki 1 elemen

boolean IsUnerLeft (BinTree P);
//Mengirimkan true jika pohon biner tidak kosong P adalah
//pohon unerleft: hanya mempunyai subpohon kiri

boolean IsUnerRight (BinTree P);
//Mengirimkan true jika pohon biner tidak kosong P adalah
//pohon unerright: hanya mempunyai subpohon kanan

boolean IsBiner (BinTree P);
//Mengirimkan true jika pohon biner tidak kosong P adalah
//pohon biner: mempunyai subpohon kiri dan subpohon kanan

/*** Traversal ***/
void PrintPreorder (BinTree P);
//I.S. P terdefinisi
//F.S. Semua simpul P sudah dicetak secara preorder: akar, pohon kiri, dan pohon
//kanan. Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup ().

void PrintInorder (BinTree P);
//I.S. P terdefinisi
//F.S. Semua simpul P sudah dicetak secara inorder: pohon kiri, akar, dan pohon
//kanan. Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup ().

void PrintPostorder (BinTree P);
//I.S. P terdefinisi
//F.S. Semua simpul P sudah dicetak secara postorder: pohon kiri, pohon kanan, dan
//akar. Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup ().
void RECIPE(BinTree P);
/*Mencetak Resep yang ada pada Tree*/
void PrintTree (BinTree P, int h, int hc);
//I.S. P terdefinisi, h adalah jarak indentasi
//F.S. Semua simpul P sudah ditulis dengan indentasi
void PrintSpasi(int h);
/*** Searching ***/
paddress SearchResep (BinTree P, char* NamaBahan);
/* FUNGSI DALAM, mencari Nama Bahan (dari stack hand) yang paling atas */

boolean IsBisaDiambil (BinTree P, char* NamaBahan, char* YangMauDiambil);
/* Kalo YangMauDiambil gak sesuai sama alur tree , bakal menghasilkan false */
/* NamaBahan adalah stack paling atas dari bahan makanan yang belum jadi, misalkan nasi,jadi SearchResep pasti != Nil */

/*** Fungsi-Fungsi Lain ***/
int NbElmtPB (BinTree P);
//Mengirimkan banyaknya elemen (node) pohon biner P

int NbDaun (BinTree P);
//Mengirimkan banyaknya daun (node) pohon biner P

boolean IsSkewLeft (BinTree P);
//Mengirimkan true jika P adalah pohon condong kiri 

boolean IsSkewRight (BinTree P);
//Mengirimkan true jika P adalah pohon condong kiri


#endif
