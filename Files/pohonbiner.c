
#include "pohonbiner.h"



/***********************ADT POHON BINER********************************/
/*** Konstruktor ***/
void Allocate (paddress *P)
{
	//Kamus Lokal
	
	//Algoritma
	*P =(paddress) malloc(sizeof(node));
	if (*P != Nil){
		PanjangResep(*P) = 0;
	}
}

BinTree Tree (infotype A, BinTree L, BinTree R)
//Menghasilkan sebuah pohon biner dari A, L, dan R, jika alokasi berhasil
//Menghasilkan pohon kosong (Nil) jika alokasi gagal
{
	//Kamus Lokal
	paddress P;
	//Algoritma
	Allocate (&P);
	if (P!=Nil) {
		//Akar(P) = A;
		strcpy(NamaResep(P),A.TabKata);
		PanjangResep(P) = A.Length;
		Left(P) = L;
		Right(P) = R;
	}
	return P;
}
void MakeTree (infotype A, BinTree L, BinTree R, BinTree *P)
//I.S. Sembarang 
//F.S. Menghasilkan sebuah pohon P 
//Menghasilkan sebuah pohon biner P dari A, L, dan R, jika alokasi berhasil 
//Menghasilkan pohon P yang kosong (Nil) jika alokasi gagal 
{
	//Kamus Lokal
	
	//Algoritma
	Allocate(P);
	if (*P!=Nil) {
		//Akar(P) = A;
		strcpy(NamaResep(*P),A.TabKata);
		PanjangResep(*P) = A.Length;
		Left(*P) = L;
		Right(*P) = R;
	} 
}
void LoadResep(BinTree*P)
/*Mengambil Resep dari File Eksternal dan Menyusunnya dalam pohon resep */
{
	//Kamus
	char RecipeTree[NMax+1];
	//Algoritma
	START();
	BuildResep(P);
}
void BuildResep (BinTree *P)
/* Input dari string Resep */
/* I.S. CC == ‘ ( ' */
/* F.S. P terdefinisi */
/* Proses : Membaca string Resep dan membangun pohon secara rekursif
*/
{ 	/* Kamus Lokal */
	/* Algoritma */
		while (CC == '(')
			ADV();
		/* advance */
		if (CC ==')'){ /* Basis : pohon kosong */
			(*P) = Nil;
		}
		else {
			/* Rekurens */
			Allocate(P); //Alokasi memori buat nampung node string baru
			int CurrentIndex = 0;
			while (CC  != '('){
				NamaResep(*P)[CurrentIndex] = CC ;
				CurrentIndex++;
				PanjangResep(*P)++;
				ADV();
			}
			//puts(NamaResep(*P));
			//printf("\n");
			/* advance */
			BuildResep(&Left(*P));
			BuildResep(&Right(*P));
		}
		/* advance */
		ADV();

		
}

//Membentuk sebuah pohon biner P dari pita karakter yang dibaca }
//I.S. Pita berisi "konstanta" pohon dalam bentuk prefix.
//Memori pasti cukup, alokasi pasti berhasil. }
//F.S. P dibentuk dari ekspresi dalam pita }

/*** Predikat-Predikat Penting ***/
boolean IsTreeEmpty (BinTree P)
//Mengirimkan true jika P adalah pohon biner kosong
{
	//Kamus Lokal
	
	//Algoritma
	return (P==Nil);
}
boolean IsOneElmt (BinTree P)
//Mengirimkan true jika P adalah pohon biner tidak kosong dan
//hanya memiliki 1 elemen
{
	//Kamus Lokal
	
	//Algoritma
	return ((!IsTreeEmpty(P))&&(IsTreeEmpty(Left(P)))&&(IsTreeEmpty(Left(P))));
}
boolean IsUnerLeft (BinTree P)
//Mengirimkan true jika pohon biner tidak kosong P adalah
//pohon unerleft: hanya mempunyai subpohon kiri
{
	//Kamus Lokal
	
	//Algoritma
	return ((Right(P) == Nil) && (Left(P) != Nil));
}
boolean IsUnerRight (BinTree P)
//Mengirimkan true jika pohon biner tidak kosong P adalah
//pohon unerright: hanya mempunyai subpohon kanan
{
	//Kamus Lokal
	
	//Algoritma
	return ((Right(P) != Nil) && (Left(P) == Nil));
}
boolean IsBiner (BinTree P)
//Mengirimkan true jika pohon biner tidak kosong P adalah
//pohon biner: mempunyai subpohon kiri dan subpohon kanan
{
	//Kamus Lokal
	
	//Algoritma
	return ((Right(P) != Nil) && (Left(P) != Nil));
}

/*** Traversal ***/
void PrintPreorder (BinTree P)
//I.S. P terdefinisi
//F.S. Semua simpul P sudah dicetak secara preorder: akar, pohon kiri, dan pohon
//kanan. Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup ().
{
	//Kamus Lokal
	
	//Algoritma
	if (P!=Nil)  {
		printf("%s %d\n", NamaResep(P),PanjangResep(P));
		PrintPreorder(Left(P));
		PrintPreorder(Right(P));
	}
}
void PrintInorder (BinTree P)
//I.S. P terdefinisi
//F.S. Semua simpul P sudah dicetak secara inorder: pohon kiri, akar, dan pohon
//kanan. Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup ().
{
	//Kamus Lokal
	
	//Algoritma
	//printf("%d\n",P == Nil); //DEBUG
	if (P!=Nil)  {
		PrintInorder(Left(P));
		printf("%s %d\n", NamaResep(P),PanjangResep(P));
		PrintInorder(Right(P));
	}
}
void PrintPostorder (BinTree P)
//I.S. P terdefinisi
//F.S. Semua simpul P sudah dicetak secara postorder: pohon kiri, pohon kanan, dan
//akar. Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup ().
{
	//Kamus Lokal
	
	//Algoritma
	if (P!=Nil)  {
		PrintPostorder(Left(P));
		PrintPostorder(Right(P));
		printf("%s %d\n", NamaResep(P),PanjangResep(P));
	}
}
void RECIPE(BinTree P)
/*Mencetak Resep yang ada pada Tree*/
{
	//Algoritma
	PrintTree(P,5,5);
}
void PrintTree (BinTree P, int h, int hc)
//I.S. P terdefinisi, h adalah jarak indentasi
//F.S. Semua simpul P sudah ditulis dengan indentasi
{
	//Kamus Lokal
	
	//Algoritma
	if (!IsTreeEmpty(P)) {
		puts(NamaResep(P));
		if (!IsTreeEmpty(Left(P))) {
			PrintSpasi(hc+h);
			PrintTree(Left(P), h, hc+h);
		}
		if (!IsTreeEmpty(Right(P))) {
			PrintSpasi(hc+h);
			PrintTree(Right(P), h, hc+h);
		}
	}
}
void PrintSpasi(int h) 
{
	//Kamus Lokal
	int i;
	//Algoritma
	for (i=1; i<=h; i++) {
		printf(" ");
	}
}
/*** Searching ***/
paddress SearchResep (BinTree P, char* NamaBahan)
/* FUNGSI DALAM, mencari Nama Bahan (dari stack hand) yang paling atas */
{
	//Kamus Lokal
	paddress PTempA,PTempB;
	//Algoritma
	if (IsTreeEmpty(P)) {
		return Nil;
	}
	else{
		if (strcmp(NamaBahan,NamaResep(P)) == 0) { //Napa true nilainya 0 ya hmm
			return P;
		}
		else {
			PTempA = SearchResep(Left(P),NamaBahan);
			if (PTempA == Nil){
				PTempB = SearchResep(Right(P),NamaBahan);
				return PTempB; //Kalo gak ketemu di kedua cabang return Nil
			}
			else{
				return PTempA;
			}
		}
	}
}
boolean IsBisaDiambil (BinTree P, char* NamaBahan, char* YangMauDiambil)
/* Kalo YangMauDiambil gak sesuai sama alur tree , bakal menghasilkan false */
/* NamaBahan adalah stack paling atas dari bahan makanan yang belum jadi, misalkan nasi,jadi SearchResep pasti != Nil */
{
	//Kamus
	paddress temp;
	char Turunan1[NMax],Turunan2[NMax];
	char *NotFound = "Kosong";
	//Algoritma
	temp = SearchResep(P,NamaBahan);
	if (Left(temp) != Nil){
		strcpy(Turunan1,NamaResep(Left(temp))); 
	}
	else{
		strcpy(Turunan1,NotFound); // PROBLEM
	}
	if (Right(temp) != Nil){
		strcpy(Turunan2,NamaResep(Right(temp)));
	}
	else{
		strcpy(Turunan2,NotFound);// PROBLEM
	}
	return ((strcmp(Turunan1,YangMauDiambil) == 0) || (strcmp(Turunan2,YangMauDiambil) == 0));
}
/*** Fungsi-Fungsi Lain ***/
int NbElmtPB (BinTree P)
//Mengirimkan banyaknya elemen (node) pohon biner P
{
	//Kamus Lokal
	
	//Algoritma
	if (IsTreeEmpty(P)) {
		return 0;
	}
	else {
		return 1+NbElmtPB(Left(P))+NbElmtPB(Right(P));
	}
}
int NbDaun (BinTree P)
//Mengirimkan banyaknya daun (node) pohon biner P
{
	//Kamus Lokal
	
	//Algoritma
	if ((Left(P)==Nil)&&(Right(P)==Nil)) {
		return 1;
	}
	else {
		if ((Left(P)!=Nil)&&(Right(P)==Nil)) {
			return NbDaun(Left(P));
		}
		else if ((Left(P)==Nil)&&(Right(P)!=Nil)) {
			return NbDaun(Right(P));
		}
		else if ((Left(P)!=Nil)&&(Right(P)!=Nil)) {
			return NbDaun(Left(P))+NbDaun(Right(P));
		}
	}
}
boolean IsSkewLeft (BinTree P)
//Mengirimkan true jika P adalah pohon condong kiri 
{
	//Kamus Lokal
	
	//Algoritma
	if (IsTreeEmpty(P))
		return false;
	else {
		if (IsOneElmt(P)) {
			return true;
		}
		else 
			if (IsUnerLeft(P)) {
				return IsSkewLeft(Left(P));
			}
			else {
				return false;
			}
		}
}
boolean IsSkewRight (BinTree P)
//Mengirimkan true jika P adalah pohon condong kiri
{
	//Kamus Lokal
	
	//Algoritma
	if (IsTreeEmpty(P))
		return false;
	else {
		if (IsOneElmt(P)) {
			return true;
		}
		else 
			if (IsUnerRight(P)) {
				return IsSkewRight(Right(P));
			}
			else {
				return false;
			}
		}
}
/*
int main(){
	//Kamus
	BinTree Resep;
	//Algoritma
	LoadResep(&Resep);
	RECIPE(Resep);
	return 0;
}*/