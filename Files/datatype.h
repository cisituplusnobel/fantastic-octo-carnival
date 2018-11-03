//Nama Kelompok/Kelas : Cisitu plus Nobel / K03
#ifndef DATATYPE_H
#define DATATYPE_H 

/* DAFTAR TIPE BENTUKAN */

/*Customer adalah satu kelompok orang yang datang bersama*/
#define TableUndef -999

/* TUPLE DARI LIST OF SEATED CUSTOMER */
typedef struct{
    int NbPeople; //Jumlah orang dalam suatu kelompok
    int WaitTime; //Waktu menunggu di antrian
    int NbTable; //Nomor meja, jika belum mendapat meja maka bernilai TableUndef
} Customer;

/* TUPLE DARI ARRAY OF ORDER */
typedef struct{
    int Code;
    int Price;
    int TableNb;
} Order;

/*TUPLE DARI LIST OF STACK OF FOOD (belum ada) */





#endif


