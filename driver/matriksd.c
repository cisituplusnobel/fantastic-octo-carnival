/*File Driver ADT MATRIKS*/

#include "../include/matriks.h"
#include <stdio.h>

int main(){
    //Kamus
    MATRIKS M,MCopy;
    int Bar,Kol;
    int X;
    //Algoritma
    scanf("%d",&Bar);
    scanf("%d",&Kol);
    MakeMATRIKS(Bar,Kol,&M);
    MakeMATRIKS(Bar,Kol,&MCopy);
    BacaMATRIKS(&M,Bar,Kol);
    TulisMATRIKS(M);
    printf("%d",GetElmtDiagonalMATRIKS(M));
    CopyMATRIKS(M,&MCopy);
    TulisMATRIKS(MCopy);
    return 0;
}