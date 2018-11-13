/* Kelompok    : CisituPlusNobel
/* File        : room.h */
/* Tanggal     : 29 Oktober 2018 */

#include "datatype.h"
#include "point.h"
#include "jam.h"
#include "queue.h"
#include "stackt.h"
#include "array.h"
#include "boolean.h"

void MakeEmptyTable(ROOM *R, int table);
/*  Membuat meja menjadi kosong. Meja kosong ditandai dengan X. Procedure ini hanya merubah
    tampilan pada matriks saja.*/

void MakeFullTable4(ROOM *R, int table);
/*  Membuat meja yang kapasitasnya 4 menjadi penuh. Meja penuh ditandai dengan C. Procedure 
    ini hanya merubah tampilan pada matriks saja.*/

void MakeFullTable2(ROOM *R, int table);
/*  Membuat meja yang kapasitasnya 2 atau 4 menjadi penuh. Meja penuh ditandai dengan C. Procedure 
    ini hanya merubah tampilan pada matriks saja.*/

void MakeKitchen(ROOM *R);
/*  Membuat bentuk denah kitchen. Setiap tempat bahan makanan ditandai dengan M dan nampan ditandai
    dengan T */

boolean IsKosong(ROOM R, int table);
/*  Mengecek apakah meja kosong atau tidak. Proses pengecekan masih prmitif karena hanya melihat
    isi matriksnya (X atau C). Menghasilkan true jika meja kosong */

void CekKosong4(ROOM R, int *table);
/*  Melakukan pengecekan apakah terdapat meja dengan kapasitas 4 yang kosong. Pengeekan masih
    dilakukan primitif karena hanya meihat isi matriksnya saja (X atau C). Jika terdapat meja
    dengan kapasitas 4 yang kosong, maka room dan table akan diisi dengan ruangan dan nomor meja
    ditemukannya meja kosong. Jika tidak room dan table akan diisi dengan -999 */

void CekKosong2(ROOM R, int *table);
/*  Melakukan pengecekan apakah terdapat meja dengan kapasitas 2 yang kosong. Pengeekan masih
    dilakukan primitif karena hanya meihat isi matriksnya saja (X atau C). Jika terdapat meja
    dengan kapasitas 2 yang kosong, maka room dan table akan diisi dengan ruangan dan nomor meja
    ditemukannya meja kosong. Jika tidak room dan table akan diisi dengan -999 */

void CekSebelahan(ROOM R,int room, POINT P,int *meja);
/*  Melakukan oengecekan apakah koordinat player (P) bersebelahan dengan salah satu meja
    Jika bersebelahan maka akan meja akan diisi dengan nomor meja yang bersebelahan*/

void Inisalisasi(ROOM *R, POINT *P, JAM *J, Queue *Q, Stack *S, TabInt *orders, TabInt *tables, Customer *emptyOrder, int *life, int *money);
/*  Melakukan inisalisasi pada bentuk setiap room yaitu ruangan dalam representasi matriks, koordinat pemain,
    waktu pemain, antrian, stack of foods, array of orders, list of tables */