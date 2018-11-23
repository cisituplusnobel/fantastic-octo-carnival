//Graph berarah diimplementasi sebagai multilist

#include "boolean.h"
#include "listrek.h"
#include "graph.h"
#include <stdio.h>
#include <stdlib.h>


/*** Konstruktor ***/
void CreateGraph (int X, Graph *L)
/*I.S. Sembarang
  F.S. Terbentuk graph dengan X sebagai First element dari graph*/
{
    adrNode Pn;
    Pn=AlokNode(X);
    if (Pn!=Nil){
        First(*L)=Pn;
    }
}

/*** Manajemen Memori List Simpul (Leader) ***/
adrNode AlokNode (int X)
/* Mengembalikan address hasil alokasi Simpul X. */
/* Jika alokasi berhasil, maka address tidak Nil, misalnya
menghasilkan P, maka Id(P)=X, Npred(P)=0, Trail(P)=Nil,
dan Next(P)=Nil. Jika alokasi gagal, mengembalikan Nil. */
{
    adrNode P;
    P = (adrNode) malloc(sizeof(Node));
    if (P!=Nil){
        Id(P)=X;
        NPred(P)=Nil;
        Trail(P)=Nil;
        Next(P)=Nil;
    }
    return P;
}
void DealokNode (adrNode P)
/* I.S. P terdefinisi; F.S. P dikembalikan ke sistem */
{
    free(P);
}

/*** Manajemen Memory List Successor (Trailer) ***/
adrSuccNode AlokSuccNode (adrNode Pn)
/* Mengembalikan address hasil alokasi. */
/* Jika alokasi berhasil, maka address tidak Nil, misalnya
menghasilkan Pt, maka Succ(Pt)=Pn dan Next(Pt)=Nil. Jika
alokasi gagal, mengembalikan Nil. */
{
    adrSuccNode Pt;
    Pt = (adrSuccNode) malloc(sizeof(SuccNode));
    if (Pt!=Nil){
        Succ(Pt)=Pn;
        Next(Pt)=Nil;
    }
    return Pt;
}
void DealokSuccNode (adrSuccNode P)
/* I.S. P terdefinisi; F.S. P dikembalikan ke sistem */
{
    free(P);
}

/*** Fungsi/Prosedur Lain ***/ 
adrNode SearchNode (Graph G, int X)
/*Mengembalikan address simpul dengan Id=X jika sudah ada pada Graph, 
  Nil jika belum*/
{
    adrNode Pn;
    Pn=First(G);
    while (Next(Pn)!=Nil && Id(Pn)!=X){
        Pn = Next(Pn);
    }
    if (Id(Pn)!=X){
        return Nil;
    }
    else{
        return Pn;
    }
}
adrSuccNode SearchEdge (Graph G, int prec, int succ)
/*Mengembalikan address trailer dengan busur yang menyimpan info busur 
  (prec,succ) jika sudah ada pada graph, Nil jika belum*/
{
    adrNode Pn; adrSuccNode Pt;
    Pn = SearchNode(G,prec);
    if (Pn==Nil){
        return Nil;
    }
    else{
        Pt = Trail(Pn);
        while (Next(Pt)!=Nil && Id(Succ(Pt))!=succ){
            Pt = Next(Pt);
        }
        if (Id(Succ(Pt))!=succ){
            return Nil;
        }
        else{
            return Pt;
        }
    }
}
void InsertNode (Graph *G, int X, adrNode *Pn)
/* Menambahkan simpul X ke dalam graph, jika alokasi X berhasil */
/* I.S. G terdefinisi, X terdefinisi dan belum ada pada G */
/* F.S. JIka alokasi berhasil, X menjadi elemen terakhir G */
/* Pn berisi address simpul X. */
/* Jika alokasi gagal G tetap, Pn berisi Nil */
{
    adrNode PnTemp;
    *Pn = AlokNode(X);
    if(*Pn!=Nil){
        PnTemp=First(*G);
        while (Next(PnTemp)!=Nil){
            PnTemp=Next(PnTemp);
        }
        Next(PnTemp)=*Pn;
    }
}
void InsertEdge (Graph *G, int prec, int succ)
/* Menambahkan busur dari prec menuju succ ke dalam G */
/* I.S. G, prec, succ terdefinisi */
/* F.S. Jika belum ada busur (prec,succ) di G, maka tambahkan busur (prec,succ) ke G */
/* Jika simpul prec/succ belum ada pada G, tambahkan simpul tersebut dahulu */
/* Jika sudah ada busur (prec,succ) di G, maka G tetap */
{
    adrSuccNode Pt, Pttemp;
    adrNode Pnprec,Pnsucc;
    Pt=SearchEdge(*G,prec,succ);
    if (Pt==Nil){
        Pnprec=SearchNode(*G,prec);
        Pnsucc=SearchNode(*G,succ);
        if (Pnprec==Nil){
            InsertNode(G,prec,&Pnprec);
        }
        if (Pnsucc==Nil){
            InsertNode(G,succ,&Pnsucc);
        }
        Pt=AlokSuccNode(Pnsucc);
        Pttemp=Trail(Pnprec);
        if (Pttemp==Nil){
            Pttemp=Pt;
        }
        else{
            while (Next(Pttemp)!=Nil){
                Pttemp=Next(Pttemp);
            }
            Next(Pttemp)=Pt;
        }
        (NPred(Pnsucc))++;
    }
}
void DeleteNode (Graph *G, int X)
/* Menghapus simpul X dari G */
/* I.S. G terdefinisi, X terdefinisi dan ada pada G, jumlah simpul pada G lebih dari 1 */
/* F.S. Simpul X dan semua busur yang terhubung ke X dihapus dari G */
{
    adrNode Pn,Pnprec,P;
    adrSuccNode Pt,Ptprec;
    //Ganti next dr simpul sebelum simpul X
    Pn = First(*G);
    while (Next(Pn)!=Nil && Id(Pn)!=X){
        Pnprec=Pn;
        Pn = Next(Pn);
    }
    Next(Pnprec)=Next(Pn);
    Next(Pn)=Nil;
    //Hapus semua busur dengan prec = simpul X
    Pt=Trail(Pn);
    if (Pt!=Nil){
        while (Next(Pt)!=Nil){
            NPred(Succ(Pt))--;
            Ptprec=Pt;
            Pt=Next(Pt);
            DealokSuccNode(Ptprec);
        }
        NPred(Succ(Pt))--;
        DealokSuccNode(Pt);
    }
    //Hapus semua busur dengan succ = simpul X
    P = Pn;
    if (NPred(P)!=Nil){
        Pn = First(*G);
        //Cek busur setiap simpul
        while (Next(Pn)!=Nil){
            Pt=Trail(Pn);
            if (Pt!=Nil){
                //Telusuri list edge untuk mencari edge dengan succ = simpul X
                while(Id(Succ(Pt))!=X){
                    Ptprec=Pt;
                    Pt=Next(Pt);
                }
                Next(Ptprec)=Next(Pt);
                DealokSuccNode(Pt);
            }
            Pn = Next(Pn);
        }  
        Pt=Trail(Pn);
        if (Pt!=Nil){
        //Telusuri list edge simpul terakhir untuk mencari edge dengan succ = simpul X
            while(Id(Succ(Pt))!=X){
                Ptprec=Pt;
                Pt=Next(Pt);
            }
            Next(Ptprec)=Next(Pt);
            DealokSuccNode(Pt);
        }
    }
    DealokNode(P);
}