//Graph berarah diimplementasi sebagai multilist

#ifndef _GRAPH_H_
#define _GRAPH_H_

#include "boolean.h"
#include "listrek.h"

#define Nil NULL

typedef struct tNode *adrNode;
typedef struct tSuccNode *adrSuccNode;
typedef struct tNode{
    int Id;
    int NPred;
    adrSuccNode Trail;
    adrNode next;
} Node;
typedef struct tSuccNode{
    adrNode Succ;
    adrSuccNode next;
}SuccNode;

typedef struct{
    adrNode First;
} Graph;

/*** Selektor ***/
#define First(G) (G).First
#define Id(Pn) (Pn)->Id
#define NPred(Pn) (Pn)->NPred
#define Trail(Pn) (Pn)->Trail
#define Succ(Pt) (Pt)->Succ

/*** Konstruktor ***/
void CreateGraph (int X, Graph *L);
/*I.S. Sembarang
  F.S. Terbentuk graph*/

/*** Manajemen Memori List Simpul (Leader) ***/
adrNode AlokNode (int X);
/* Mengembalikan address hasil alokasi Simpul X. */
/* Jika alokasi berhasil, maka address tidak Nil, misalnya
menghasilkan P, maka Id(P)=X, Npred(P)=0, Trail(P)=Nil,
dan Next(P)=Nil. Jika alokasi gagal, mengembalikan Nil. */
void DealokNode (adrNode P);
/* I.S. P terdefinisi; F.S. P dikembalikan ke sistem */

/*** Manajemen Memory List Successor (Trailer) ***/
adrSuccNode AlokSuccNode (adrNode Pn);
/* Mengembalikan address hasil alokasi. */
/* Jika alokasi berhasil, maka address tidak Nil, misalnya
menghasilkan Pt, maka Succ(Pt)=Pn dan Next(Pt)=Nil. Jika
alokasi gagal, mengembalikan Nil. */
void DealokSuccNode (adrSuccNode P);
/* I.S. P terdefinisi; F.S. P dikembalikan ke sistem */

/*** Fungsi/Prosedur Lain ***/ 
adrNode SearchNode (Graph G, int X);
/*Mengembalikan address simpul dengan Id=X jika sudah ada pada Graph, 
  Nil jika belum*/
adrSuccNode SearchEdge (Graph G, int prec, int succ);
/*Mengembalikan address trailer dengan busur yang menyimpan info busur 
  (prec,succ) jika sudah ada pada graph, Nil jika belum*/
void InsertNode (Graph *G, int X, adrNode *Pn);
/* Menambahkan simpul X ke dalam graph, jika alokasi X berhasil */
/* I.S. G terdefinisi, X terdefinisi dan belum ada pada G */
/* F.S. JIka alokasi berhasil, X menjadi elemen terakhir G */
/* Pn berisi address simpul X. */
/* Jika alokasi gagal G tetap, Pn berisi Nil */
void InsertEdge (Graph *G, int prec, int succ);
/* Menambahkan busur dari prec menuju succ ke dalam G */
/* I.S. G, prec, succ terdefinisi */
/* F.S. Jika belum ada busur (prec,succ) di G, maka tambahkan busur (prec,succ) ke G */
/* Jika simpul prec/succ belum ada pada G, tambahkan simpul tersebut dahulu */
/* Jika sudah ada busur (prec,succ) di G, maka G tetap */
void DeleteNode (Graph *G, int X);
/* Menghapus simpul X dari G */
/* I.S. G terdefinisi, X terdefinisi dan ada pada G, jumlah simpul pada G lebih dari 1 */
/* F.S. Simpul X dan semua busur yang terhubung ke X dihapus dari G */

#endif