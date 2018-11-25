/*FILE ADT DRIVER POINT*/

#include "../include/point.h"
#include <stdio.h>

int main(){
    //Kamus
    int X,Y,dx,dy;
    POINT P,dP;
    //Algoritma
    scanf("%d",&X);
    scanf("%d",&Y);
    scanf("%d",&dx);
    scanf("%d",&dy);
    P = MakePOINT(X,Y);
    dP = PlusDelta(P,dx,dy);
    Geser(&P,dx,dy);
    printf("EQP(P,dP) : %d",EQP(P,dP));
    return 0;
}
