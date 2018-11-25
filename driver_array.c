/*File Driver ADT Array*/
#include <stdio.h>
#include "boolean.h"
#include "array.h"

int main(){
    TabInt T1,T2;
    int input;
    IdxType i=1;
    ElTypeArray X;
    X.NbTable=1;

    printf("Tester\n");
    printf("----------\n");
    while(true){
        printf("1 = Output\n2 = Is2\n3 = CopyTab\n4 = Operasi");
        scanf("%d",&input);
        MakeEmpty(&T1);
        MakeEmpty(&T2);
        switch(input){
            case 1:
                printf("[T1] \n");
                TulisIsiTab(T1);
                printf("\n");
                break;
            case 2:
                printf("IsEmpty(T1) = %d\n",IsEmpty(T1));
                printf("IsFull(T1) = %d\n",IsFull(T1));
                printf("NbElmtArray(T1) = %d\n",NbElmtArray(T1));
                printf("MaxNbEl(T1) = %d\n",MaxNbEl(T1));
                printf("GetFirstIdx(T1) = %d\n",GetFirstIdx(T1));
                printf("GetLastIdx(T1) = %d\n",GetLastIdx(T1));
            break;
            case 3:
                CopyTab(T1,&T2);
                printf("Hasil Copy T1\n");
                TulisIsiTab(T2);
                printf("\n");
            break;
            case 4:
                printf("[T1] \n");
                TulisIsiTab(T1);
                printf("\n");
                printf("1 = addlast\n2 = addeli\n3 = dellast\n4 = deleli\n5=ubaheli");
                scanf("%d",&input);
                switch(input){
                    case 1:
                        AddAsLastEl(&T1,X);
                    break;
                    case 2:
                        AddEli(&T1,X,i);
                    break;
                    case 3:
                        DelLastEl(&T1,&X);
                    break;
                    case 4:
                        DelEli(&T1,i,&X);
                    break;
                    case 5:
                        UbahEli(&T1,i,X);
                }
                printf("[T1] \n");
                TulisIsiTab(T1);
                printf("\n");
            break;
        }
    }
    return 0;
}