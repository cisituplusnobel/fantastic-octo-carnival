//Nama Kelompok/Kelas : Cisitu plus Nobel / K03


/* DAFTAR LIBRARY ADT YANG DIGUNAKAN */

#include "array.h"
#include "jam.h"
#include "listdp.h"
#include "listlinier.h"
#include "listsirkuler.h"
#include "matriks.h"
#include "mesinkata.h"
#include "point.h"
#include "queue.h"
#include "stackt.h"

/* Ada cara buat masukin semua ADT ke satu header gitu gak ya? */

/* DAFTAR TIPE BENTUKAN */

/*Customer adalah satu kelompok orang yang datang bersama*/
typedef struct{
    int NbPeople; //Jumlah orang dalam suatu kelompok
    int WaitTime; //Waktu menunggu di antrian
} Customer;

/*Gua skip dulu ya*/
//Array of array of char Room //kalo elemen suatu index sama dengan #,
//berarti disitu ada gaada meja, X untuk kursi kosong, nomor untuk meja, C untuk customer

typedef struct{
    int TableTime; //Waktu sejak sudah duduk di meja.
    char Order; // Berisi nama makanan/minumman yang dipesan,setiap meja hanya dapat memesan 1 jenis makanan/minuman saja.
    int NbTable; //Nomor Meja.
} Table;


/*typedef Queue CustomerQueue;*/ //mesti edit ADT Queue-nya dulu.
/*Stack FoodStack;*/ //mesti edit ADT stackt
/*Tree Hand*/

extern JAM PlayTime;
extern char Command[20];
extern int Money;
extern Table TableList[20];
extern int PlayerLife;




