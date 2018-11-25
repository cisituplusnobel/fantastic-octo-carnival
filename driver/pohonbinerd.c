/*DRIVER header pohonbiner.h Kelompok Cisitu plus Nobel */

#include "pohonbiner.h"

int main(){
    //Kamus
    BinTree Tree;
    //Algoritma
    LoadTree(&Tree);
    ShowBranch(Tree);
    puts('\n');
    print("IsTreeEmpty(Tree) : %d",IsTreeEmpty(Tree));
    print("IsOneElmt(Tree) : %d",IsOneElmt(Tree));
    print("IsUnerRight(Tree) : %d",IsUnerRight(Tree));
    print("IsUnerLeft(Tree) : %d",IsUnerLeft(Tree));
    print("IsBiner(Tree) : %d",IsBiner(Tree));
    return 0;
}
    

