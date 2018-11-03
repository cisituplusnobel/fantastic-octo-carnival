#include <stdio.h>
#include <string.h>
#include "variables.h"
#include "datatype.h"


#define RMin 1
#define RMax 100

typedef struct {
    MATRIKS Mem[RMax + 1];
} ROOM;

#define Elm(R,i) (R).Mem[(i)]


void MakeEmptyTable(ROOM *R, int room, int table)
/**/ {
    if (table == 1) {
        ElmtMATRIKS(Elm(*R, room), 1, 2) = 'X';
        ElmtMATRIKS(Elm(*R, room), 2, 1) = 'X';
        ElmtMATRIKS(Elm(*R, room), 2, 3) = 'X';
        ElmtMATRIKS(Elm(*R, room), 3, 2) = 'X';
        ElmtMATRIKS(Elm(*R, room), 2, 2) = '1';
    } else if (table == 2) {
        ElmtMATRIKS(Elm(*R, room), 2, 6) = 'X';
        ElmtMATRIKS(Elm(*R, room), 2, 8) = 'X';
        ElmtMATRIKS(Elm(*R, room), 2, 7) = '2';
    } else if (table == 3) {
        ElmtMATRIKS(Elm(*R, room), 6, 2) = 'X';
        ElmtMATRIKS(Elm(*R, room), 7, 1) = 'X';
        ElmtMATRIKS(Elm(*R, room), 7, 3) = 'X';
        ElmtMATRIKS(Elm(*R, room), 8, 2) = 'X';
        ElmtMATRIKS(Elm(*R, room), 7, 2) = '3';
    } else if (table == 4) {
        ElmtMATRIKS(Elm(*R, room), 7, 6) = 'X';
        ElmtMATRIKS(Elm(*R, room), 7, 8) = 'X';
        ElmtMATRIKS(Elm(*R, room), 7, 7) = '4';
    }
}

void MakeFullTable4(ROOM *R, int room, int table)
/**/ {
    if (table == 1) {
        ElmtMATRIKS(Elm(*R, room), 1, 2) = 'C';
        ElmtMATRIKS(Elm(*R, room), 2, 1) = 'C';
        ElmtMATRIKS(Elm(*R, room), 2, 3) = 'C';
        ElmtMATRIKS(Elm(*R, room), 3, 2) = 'C';
        ElmtMATRIKS(Elm(*R, room), 2, 2) = '1';
    } else if (table == 3) {
        ElmtMATRIKS(Elm(*R, room), 6, 2) = 'C';
        ElmtMATRIKS(Elm(*R, room), 7, 1) = 'C';
        ElmtMATRIKS(Elm(*R, room), 7, 3) = 'C';
        ElmtMATRIKS(Elm(*R, room), 8, 2) = 'C';
        ElmtMATRIKS(Elm(*R, room), 7, 2) = '3';
    }
}

void MakeFullTable2(ROOM *R, int room, int table)
/**/ {
    if (table == 1) {
        ElmtMATRIKS(Elm(*R, room), 1, 2) = 'X';
        ElmtMATRIKS(Elm(*R, room), 2, 1) = 'C';
        ElmtMATRIKS(Elm(*R, room), 2, 3) = 'C';
        ElmtMATRIKS(Elm(*R, room), 3, 2) = 'X';
        ElmtMATRIKS(Elm(*R, room), 2, 2) = '1';
    } else if (table == 3) {
        ElmtMATRIKS(Elm(*R, room), 6, 2) = 'X';
        ElmtMATRIKS(Elm(*R, room), 7, 1) = 'C';
        ElmtMATRIKS(Elm(*R, room), 7, 3) = 'C';
        ElmtMATRIKS(Elm(*R, room), 8, 2) = 'X';
        ElmtMATRIKS(Elm(*R, room), 7, 2) = '3';
    } else if (table == 2) {
        ElmtMATRIKS(Elm(*R, room), 2, 6) = 'C';
        ElmtMATRIKS(Elm(*R, room), 2, 8) = 'C';
        ElmtMATRIKS(Elm(*R, room), 2, 7) = '2';
    } else if (table == 4) {
        ElmtMATRIKS(Elm(*R, room), 7, 6) = 'C';
        ElmtMATRIKS(Elm(*R, room), 7, 8) = 'C';
        ElmtMATRIKS(Elm(*R, room), 7, 7) = '4';
    }
}

void MakeKitchen(ROOM *R)
/**/ {
    ElmtMATRIKS(Elm(*R, 4), 1, 1) = 'M';
    ElmtMATRIKS(Elm(*R, 4), 2, 1) = 'M';
    ElmtMATRIKS(Elm(*R, 4), 3, 1) = 'M';
    ElmtMATRIKS(Elm(*R, 4), 4, 1) = 'M';
    ElmtMATRIKS(Elm(*R, 4), 5, 1) = 'M';
    ElmtMATRIKS(Elm(*R, 4), 6, 1) = 'M';
    ElmtMATRIKS(Elm(*R, 4), 7, 1) = 'M';
    ElmtMATRIKS(Elm(*R, 4), 8, 1) = 'M';
    ElmtMATRIKS(Elm(*R, 4), 5, 4) = 'M';
    ElmtMATRIKS(Elm(*R, 4), 5, 5) = 'M';
    ElmtMATRIKS(Elm(*R, 4), 8, 4) = 'M';
    ElmtMATRIKS(Elm(*R, 4), 8, 5) = 'M';
    ElmtMATRIKS(Elm(*R, 4), 8, 6) = 'M';
    ElmtMATRIKS(Elm(*R, 4), 8, 7) = 'M';
    ElmtMATRIKS(Elm(*R, 4), 8, 8) = 'M';
    ElmtMATRIKS(Elm(*R, 4), 1, 8) = 'T';
}

boolean IsKosong(ROOM R, int room, int table)
/**/ {
    if (table == 1) {
        if (ElmtMATRIKS(Elm(R, room), 2, 2) == 'C') {
            return false;
        } else {
            return true;
        }
    } else if (table == 2) {
        if (ElmtMATRIKS(Elm(R, room), 2, 6) == 'C') {
            return false;
        } else {
            return true;
        }
    } else if (table == 3) {
        if (ElmtMATRIKS(Elm(R, room), 7, 1) == 'C') {
            return false;
        } else {
            return true;
        }
    } else if (table == 4) {
        if (ElmtMATRIKS(Elm(R, room), 7, 6) == 'C') {
            return false;
        } else {
            return true;
        }
    }
}

void IsKosong4(ROOM R, int *room, int *table) {
    //KAMUS LOKAL
    int i, j;
    boolean kosong;

    //ALGORITMA
    i = 1;
    kosong = false;
    *room = -999;
    *table = -999;
    while (i <= 3 && !kosong) {
        j = 1;
        while (j <= 4 && !kosong) {
            if (IsKosong(R, i, j)) {
                kosong = true;
                *room = i;
                *table = j;
            } else {
                j = j + 2;
            }
        }
        i++;
    }
}

void IsKosong2(ROOM R, int *room, int *table) {
    //KAMUS LOKAL
    int i, j;
    boolean kosong;

    //ALGORITMA
    i = 1;
    kosong = false;
    *room = -999;
    *table = -999;
    while (i <= 3 && !kosong) {
        j = 2;
        while (j <= 4 && !kosong) {
            if (IsKosong(R, i, j)) {
                kosong = true;
                *room = i;
                *table = j;
            } else {
                j = j + 2;
            }
        }
        i++;
    }
    i = 1;
    while (i <= 3 && !kosong) {
        j = 1;
        while (j <= 4 && !kosong) {
            if (IsKosong(R, i, j)) {
                kosong = true;
                *room = i;
                *table = j;
            } else {
                j = j + 2;
            }
        }
        i++;
    }
}

void Inisalisasi(ROOM *R, POINT *P, JAM *J, Queue *Q, Customer cust, Stack *S)
/* Melakukan inisalisasi pada bentuk setiap room
yaitu ruangan */ {
    //KAMUS LOKAL
    int i, j, k;
    //ALGORITMA
    for (i = 1; i <= 4; i++) {
        MakeMATRIKS(8, 8, &(Elm(*R, i)));
    }

    for (i = 1; i <= 4; i++) {
        for (j = 1; j <= 8; j++) {
            for (k = 1; k <= 8; k++) {
                ElmtMATRIKS(Elm(*R, i), j, k) = ' ';
            }
        }
        if (i != 4) {
            for (j = 1; j <= 4; j++) {
                MakeEmptyTable(R, i, j);
            }
        }
    }
    MakeKitchen(R);
    *P = MakePOINT(4, 4);
    *J = MakeJAM(0, 0, 0);
    CreateEmptyQueue(Q, 10);
    cust.NbPeople = 4;
    cust.WaitTime = 30;
    AddQueue(Q, cust);
    CreateEmptyStackt(&S);
}

int main() {
    //KAMUS LOKAL
    ROOM R;
    POINT P, temp;
    JAM J;
    Queue Q;
    Stack S;
    char C1, C2;
    int i, ii, j, k, room, ruang, meja;
    boolean boolq;
    Customer cust, X;
    List SeatedCust; // List berisi customer yang udah dapet duduk
    //ALGORITMA
    CreateEmptyList(&SeatedCust); //Sementara disini dulu ya
    Inisalisasi(&R, &P, &J, &Q, cust, &S);
    ElmtMATRIKS(Elm(R, 1), Absis(P), Ordinat(P)) = 'P';
    room = 1;
    TulisMATRIKS(Elm(R, room));
    printf("\n");
    printf("COMMAND = ");
    scanf("%c%c", &C2, &C1);
    while (true) {
        switch (C2) {
            case 'D':
                if (Absis(P) == 8 && Ordinat(P) == 5 && (room == 1 || room == 2)) {
                    ElmtMATRIKS(Elm(R, room), Absis(P), Ordinat(P)) = ' ';
                    if (room == 1) {
                        room = 4;
                    } else {
                        room = 3;
                    }
                    Absis(temp) = 1;
                    Ordinat(temp) = 5;
                    ElmtMATRIKS(Elm(R, room), Absis(temp), Ordinat(temp)) = 'P';
                } else if (ElmtMATRIKS(Elm(R, room), Absis(P) + 1, Ordinat(P)) == ' ') {
                    temp = PlusDelta(P, 1, 0);
                    ElmtMATRIKS(Elm(R, room), Absis(P), Ordinat(P)) = ' ';
                    ElmtMATRIKS(Elm(R, room), Absis(temp), Ordinat(temp)) = 'P';
                }
                J = NextDetik(J);
                break;
            case 'U':
                if (Absis(P) == 1 && Ordinat(P) == 5 && (room == 4 || room == 3)) {
                    ElmtMATRIKS(Elm(R, room), Absis(P), Ordinat(P)) = ' ';
                    if (room == 4) {
                        room = 1;
                    } else {
                        room = 2;
                    }
                    Absis(temp) = 8;
                    Ordinat(temp) = 5;
                    ElmtMATRIKS(Elm(R, room), Absis(temp), Ordinat(temp)) = 'P';
                } else if (ElmtMATRIKS(Elm(R, room), Absis(P) - 1, Ordinat(P)) == ' ') {
                    temp = PlusDelta(P, -1, 0);
                    ElmtMATRIKS(Elm(R, room), Absis(P), Ordinat(P)) = ' ';
                    ElmtMATRIKS(Elm(R, room), Absis(temp), Ordinat(temp)) = 'P';
                }
                J = NextDetik(J);
                break;
            case 'L':
                if (Absis(P) == 5 && Ordinat(P) == 1 && (room == 2 || room == 3)) {
                    ElmtMATRIKS(Elm(R, room), Absis(P), Ordinat(P)) = ' ';
                    if (room == 2) {
                        room = 1;
                    } else {
                        room = 4;
                    }
                    Absis(temp) = 5;
                    Ordinat(temp) = 8;
                    ElmtMATRIKS(Elm(R, room), Absis(temp), Ordinat(temp)) = 'P';
                } else if (ElmtMATRIKS(Elm(R, room), Absis(P), Ordinat(P) - 1) == ' ') {
                    temp = PlusDelta(P, 0, -1);
                    ElmtMATRIKS(Elm(R, room), Absis(P), Ordinat(P)) = ' ';
                    ElmtMATRIKS(Elm(R, room), Absis(temp), Ordinat(temp)) = 'P';
                }
                J = NextDetik(J);
                break;
            case 'R':
                if (Absis(P) == 5 && Ordinat(P) == 8 && (room == 1 || room == 4)) {
                    ElmtMATRIKS(Elm(R, room), Absis(P), Ordinat(P)) = ' ';
                    if (room == 1) {
                        room = 2;
                    } else {
                        room = 3;
                    }
                    Absis(temp) = 5;
                    Ordinat(temp) = 1;
                    ElmtMATRIKS(Elm(R, room), Absis(temp), Ordinat(temp)) = 'P';
                } else if (ElmtMATRIKS(Elm(R, room), Absis(P), Ordinat(P) + 1) == ' ') {
                    temp = PlusDelta(P, 0, 1);
                    ElmtMATRIKS(Elm(R, room), Absis(P), Ordinat(P)) = ' ';
                    ElmtMATRIKS(Elm(R, room), Absis(temp), Ordinat(temp)) = 'P';
                }
                J = NextDetik(J);
                break;
            case 'P':
                if (!IsEmptyQueue(Q)) {
                    if (InfoHead(Q).NbPeople == 4) {
                        (IsKosong4(R, &ruang, &meja));
                        if (ruang != -999) {
                            MakeFullTable4(&R, ruang, meja);
                            DelQueue(&Q, &X);
                            // Add ke list of Seated Customer
                            InsVLastList(&SeatedCust, X);
                           // AddEli(Customers, X, X.NbTable); // Customers : Array of Customer, pelanggan yang sudah duduk belum di buat.
                        } else {
                            (IsKosong2(R, &ruang, &meja));
                            if (ruang != -999) {
                                i = Head(Q);
                                boolq = false;
                                ii = Tail(Q) + 1;
                                if (ii > MaxEl) {
                                    ii = ii - MaxEl;
                                }
                                while ((i != ii) && !boolq) {
                                    if (Cust(Q, i) == 2) {
                                        MakeFullTable2(&R, ruang, meja);
                                        //Add ke list 
                                        InsVLastList(&SeatedCust, X);
                                        //AddEli(Customers, X, X.NbTable); // Customers : Array of Customer, pelanggan yang sudah duduk belum di buat.
                                        boolq = true;
                                        j = i;
                                        while (j != Tail(Q)) {
                                            k = j + 1;
                                            if (k > MaxEl) {
                                                k = k - MaxEl;
                                            }
                                            Q.T[j] = Q.T[k];
                                            j = k;
                                        }
                                        Tail(Q)--;
                                        if (Tail(Q) < 1) {
                                            Tail(Q) = MaxEl;
                                        }
                                    }
                                    i++;
                                    if (i > MaxEl) {
                                        i = i - MaxEl;
                                    }
                                }
                            } else {
                                printf("Semua Meja Penuh!\n");
                            }
                        }
                    } else {
                        (IsKosong2(R, &ruang, &meja));
                        if (ruang != -999) {
                            MakeFullTable2(&R, ruang, meja);
                        } else {
                            MakeFullTable4(&R, ruang, meja);
                        }
                        DelQueue(&Q, &X);
                        // Add List
                        InsVLastList(&SeatedCust, X);
                        //AddEli(Customers, X, X.NbTable); // Customers : Array of Customer, pelanggan yang sudah duduk belum di buats.
                    }
                }
                J = NextDetik(J);
                break;
            case 'T':
                if (room == 4) {
                    if ((ElmtMATRIKS(Elm(R, room), Absis(P) + 1, Ordinat(P)) == 'M') || (ElmtMATRIKS(Elm(R, room), Absis(P) - 1, Ordinat(P)) == 'M') || (ElmtMATRIKS(Elm(R, room), Absis(P), Ordinat(P) + 1) == 'M') || (ElmtMATRIKS(Elm(R, room), Absis(P), Ordinat(P) - 1) == 'M')) {
                        if (Absis(P) == 1 && Ordinat(P) == 1) {
                            Push(&S, 1);
                        } else if (Absis(P) == 1 && Ordinat(P) == 2) {
                            Push(&S, 2);
                        } else {
                        }
                }
                J = NextDetik(J);
                break;
            default:
                printf("RUANG 1 \n");
                TulisMATRIKS(Elm(R, 1));
                printf("\n\n");
                printf("RUANG 2 \n");
                TulisMATRIKS(Elm(R, 2));
                printf("\n\n");
                printf("RUANG 3 \n");
                TulisMATRIKS(Elm(R, 3));
                printf("\n\n");
                printf("DAPUR \n");
                TulisMATRIKS(Elm(R, 4));
                printf("\n\n");
        }

        Absis(P) = Absis(temp);
        Ordinat(P) = Ordinat(temp);
        TulisMATRIKS(Elm(R, room));
        printf("\n");
        printf("TIME : ");
        TulisJAM(J);
        printf("ANTRIAN : \n");

        if (!IsEmptyQueue(Q)) {
            if (Tail(Q) >= Head(Q)) {
                for (i = Head(Q); i <= Tail(Q); i++) {
                    printf("%d\n", Cust(Q, i));
                    WT(Q, i)--;
                }
            } else {
                i = Head(Q);
                while (i != Tail(Q)) {
                    printf("%d\n", Cust(Q, i));
                    i++;
                    if (i > MaxEl) {
                        i = i - MaxEl;
                        WT(Q, i)--;
                    }
                }
            }
        }
        if (WT(Q, Head(Q)) == 0) {
            DelQueue(&Q, &X);
            //printf("Deleted\n");
        }
        printf("COMMAND = ");
        scanf("%c%c", &C2, &C1);
        if (JAMToDetik(J) % 15 == 0) {
            if (JAMToDetik(J) % 2 == 0) {
                cust.NbPeople = 4;
                cust.WaitTime = 30;
            } else {
                cust.NbPeople = 2;
                cust.WaitTime = 30;
            }
            AddQueue(&Q, cust);
        }

    }
    return 0;
}
