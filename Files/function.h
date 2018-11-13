/* Kelompok    : CisituPlusNobel
/* File        : function.h */
/* Tanggal     : 29 Oktober 2018 */

#include "datatype.h"
#include "point.h"
#include "jam.h"
#include "queue.h"
#include "stackt.h"
#include "array.h"
#include "boolean.h"
#include "room.h"

void Interface(ROOM R, int room, Queue Q, Stack S, TabInt orders, JAM J, int life, int money);
/* Menulis Interface*/

void Go(ROOM *R, POINT *P, char C, int *room);
/*  Procesure Go terdiri dari 4 perintah yaitu Go Up, Go Down, Go Left, Go Right */

void Place(Queue *Q, ROOM *R, POINT P, int room, TabInt *tables);
/* Menempatkan pelangan dengan Top of Queue ke dalam meja yang kososng */

void Take(POINT P, Stack *S, ROOM R, int room);
/*Mengambil bahan makanan di dekat player */

void CH(Stack *S);
/* Membuang semua bahan makanan yang ada di tangan */

void Order(ROOM *R, int room, POINT P, TabInt *orders, TabInt tables);
/* Mengambil order dari meja yang bersebelahan */

void AddRemove(TabInt *orders, Queue *Q, Customer emptyOrder, JAM J, ROOM *R, POINT P, int *life, TabInt *tables);
/* Menambah Queue dan/atau mengurangi order berdasarkan waktu*/