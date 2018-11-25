/*FILE DRIVER MESINKAR.C*/

#include "../include/mesinkar.h"
#include <stdio.h>

int main(){
    //KAMUS
    char* FileName;
    //ALGORITMA
    FileName = "pitadriver.txt";
    START(FileName);
    while(!EOP){
        printf("%c\n",CC);
        ADV();
    }

    return 0;
}