void Put (BinTree  P, Stack *Bahan,Stack *Food)
/* I.S : P, Bahan, dan Food semuanya harus sudah terdefinisi */
/* Prosedur ini mengecek apakah urutan bahan dalam Stack sudah benar dari bawah ke atas */
/* Jika benar , F.S semua bahan berurutan yang sesuai dengan resep yang ada pada BinTree dihilangkan,*/
/* dan makanan jadi ditambahkan pada Stack Food */
/* Jika tidak ada urutan bahan yang benar, tidak merubah apa-apa pada stack bahan dan stack food*/
{
  //Kamus
  Stack SIn,SOut;
  infotypeStackt X;
  BinTree Px;
  //Algoritma
  CreateEmptyStackt(&SIn);
  //Cari piring di tumpukan stack
  while ((InfoTop(*Bahan) != 1) && (!IsEmptyStackt(*Bahan))){
      Pop(Bahan,&X);
      Push(&SIn,X);
  }
  if (InfoTop(*Bahan) == 1) { //Nemu piring di bahan
      CreateEmptyStackt(&SOut);
      Pop(Bahan,&X); //taro piring di SIn
      Push(&SIn,X);
      if (IsEmptyStackt(*Bahan)){
        Px = P; 
        SearchBranch(&Px, &SIn, &SOut);
        if ((IsOneElmt(Px)) && (IsEmptyStackt(SIn))){ //harus persis resep
          Push(Food,Akar(Px));
        }
        else{ //balikin semula
          while(!IsEmptyStackt(SOut)){
            Pop(&SOut,&X);
            Push(&SIn,X);
          }
          while (!IsEmptyStackt(SIn)){ 
            Pop(&SIn,&X);
            Push(Bahan,X);
          }
        }
      }
      else { //Gak ada piring di stack Bahan ,balikin
        while (!IsEmptyStackt(SIn)){ 
          Pop(&SIn,&X);
          Push(Bahan,X);
        }
      }
  }
  else { //Gak ada piring di stack Bahan ,balikin
      while (!IsEmptyStackt(SIn)){ 
        Pop(&SIn,&X);
        Push(Bahan,X);
      }
  }
}