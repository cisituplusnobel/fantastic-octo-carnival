/*Driver dari ADT JAM*/

#include "../include/jam.h"
#include <stdio.h>

int main(){
    //Kamus
    int H,M,S;
    long second;
    JAM Jam1,Jam2;
    //Algoritma
    scanf("%d",&H);
    scanf("%d",&M);
    scanf("%d",&S);
    Jam1 = MakeJAM(H,M,S);
    TulisJAM(Jam1);
    printf("%d\n",JAMToDetik(Jam1));
    scanf("%ld",&second);
    Jam2 = DetikToJAM(second);
    JAM NextJam1 = NextDetik(Jam1);
    JAM PrevJam1 = PrevDetik(Jam1);
    printf("%d",JAMToDetik(NextJam1));
    printf("%d",JAMToDetik(PrevJam1));
    return 0;
}