//Nama Kelompok/Kelas : Cisitu plus Nobel / K03

#ifndef DATATYPE_H
#define DATATYPE_H 

/* DAFTAR TIPE BENTUKAN */

/*Customer adalah satu kelompok orang yang datang bersama*/

typedef struct{
    int NbPeople; //Jumlah orang dalam suatu kelompok
    int WaitTime; //Waktu menunggu di antrian
} Customer;

typedef struct{
    char FoodName[20];
    int FoodPrice; 
} Food;

typedef struct{
    int TableTime; //Waktu sejak sudah duduk di meja.
    Food Order; // Berisi nama makanan/minuman yang dipesan,setiap meja hanya dapat memesan 1 jenis makanan/minuman saja.
    int NbTable; //Nomor Meja.
} Table;

#endif
