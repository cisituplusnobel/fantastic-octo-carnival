//Nama Kelompok/Kelas : Cisitu plus Nobel / K03
#ifndef DATATYPE_H
#define DATATYPE_H 

/* DAFTAR TIPE BENTUKAN */

/*Customer adalah satu kelompok orang yang datang bersama*/
#define TableUndef -999

typedef struct{
    int NbPeople; //Jumlah orang dalam suatu kelompok
    int WaitTime; //Waktu menunggu di antrian
    int NbTable; //Nomor meja, jika belum mendapat meja maka bernilai TableUndef
} Customer;

typedef struct{
    int Code;
    int Price; 
} Order;

/*
typedef struct{
    int TableTime; //Waktu sejak sudah duduk di meja.
    Order FoodOrder; // Berisi nama makanan/minuman yang dipesan,setiap meja hanya dapat memesan 1 jenis makanan/minuman saja.
    int NbTable; //Nomor Meja.
} Table;
*/

#endif


