/* Kelompok    : CisituPlusNobel
/* File        : matriks.c */
/* Tanggal     : 29 Oktober 2018 */

/* *** IMPLEMENTASI DARI HEADER *** */

#include "matriks.h"
#include <stdio.h>

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */              
/* *** Konstruktor membentuk MATRIKS *** */
void MakeMATRIKS (int NB, int NK, MATRIKS * M)
/* Membentuk sebuah MATRIKS "kosong" yang siap diisi berukuran NB x NK di "ujung kiri" memori */
/* I.S. NB dan NK adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks M sesuai dengan definisi di atas terbentuk */
{
	NBrsEff(*M) = NB;
	NKolEff(*M) = NK;
}

/* *** Selektor "DUNIA MATRIKS" *** */
boolean IsIdxValidMATRIKS (int i, int j)
/* Mengirimkan true jika i, j adalah indeks yang valid untuk matriks apa pun */
{
	return((BrsMin<=i && BrsMax>=i) && (KolMin<=j && KolMax>=j));
}

/* *** Selektor: Untuk sebuah matriks M yang terdefinisi: *** */
indeks GetFirstIdxBrsMATRIKS (MATRIKS M)
/* Mengirimkan indeks baris terkecil M */
{
	return BrsMin;
}

indeks GetFirstIdxKolMATRIKS (MATRIKS M)
/* Mengirimkan indeks kolom terkecil M */
{
	return KolMin;
}

indeks GetLastIdxBrsMATRIKS (MATRIKS M)
/* Mengirimkan indeks baris terbesar M */
{
	return(GetFirstIdxBrsMATRIKS(M)+NBrsEff(M)-1);
}

indeks GetLastIdxKolMATRIKS (MATRIKS M)
/* Mengirimkan indeks kolom terbesar M */
{
	return(GetFirstIdxKolMATRIKS(M)+NKolEff(M)-1);
}

boolean IsIdxEffMATRIKS (MATRIKS M, indeks i, indeks j)
/* Mengirimkan true jika i, j adalah indeks efektif bagi M */
{
	return((GetFirstIdxBrsMATRIKS(M)<=i && GetLastIdxBrsMATRIKS(M)>=i) && (GetFirstIdxKolMATRIKS(M)<=j && GetLastIdxKolMATRIKS(M)>=j));
}

ElType GetElmtDiagonalMATRIKS (MATRIKS M, indeks i)
/* Mengirimkan elemen M(i,i) */
{
	return(Elmt(M,i,i));
}

/* ********** Assignment  MATRIKS ********** */
void CopyMATRIKS (MATRIKS MIn, MATRIKS * MHsl)
/* Melakukan assignment MHsl  MIn */
{
	//KAMUS LOKAL
	indeks i,j;

	//ALGORITMA
	MakeMATRIKS (NBrsEff(MIn), NKolEff(MIn), MHsl);
	for (i=GetFirstIdxBrsMATRIKS(MIn); i<=GetLastIdxBrsMATRIKS(MIn); i++){
		for (j=GetFirstIdxKolMATRIKS(MIn); j<=GetLastIdxKolMATRIKS(MIn); j++){
			Elmt(*MHsl,i,j) = Elmt(MIn,i,j);
		}
	}
}

/* ********** KELOMPOK BACA/TULIS ********** */ 
void BacaMATRIKS (MATRIKS * M, int NB, int NK)
/* I.S. IsIdxValid(NB,NK) */ 
/* F.S. M terdefinisi nilai elemen efektifnya, berukuran NB x NK */
/* Proses: Melakukan MakeMATRIKS(M,NB,NK) dan mengisi nilai efektifnya */
/* Selanjutnya membaca nilai elemen per baris dan kolom */
/* Contoh: Jika NB = 3 dan NK = 3, maka contoh cara membaca isi matriks :
1 2 3
4 5 6
8 9 10 
*/
{
	//KAMUS LOKAL
	indeks i,j;
	ElType temp;

	//ALGORITMA
	MakeMATRIKS (NB, NK, M);
	for (i=GetFirstIdxBrsMATRIKS(*M); i<=GetLastIdxBrsMATRIKS(*M); i++){
		for (j=GetFirstIdxKolMATRIKS(*M); j<=GetLastIdxKolMATRIKS(*M); j++){
			scanf("%c", &temp);
			Elmt(*M,i,j) = temp;
		}
	}
}

void TulisMATRIKS (MATRIKS M)
/* I.S. M terdefinisi */
/* F.S. Nilai M(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris 
   dipisahkan sebuah spasi */
/* Proses: Menulis nilai setiap elemen M ke layar dengan traversal per baris dan per kolom */
/* Contoh: menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
1 2 3
4 5 6
8 9 10
*/
{
	//KAMUS LOKAL
	indeks i,j;

	//ALGORITMA
	for (i=GetFirstIdxBrsMATRIKS(M); i<=GetLastIdxBrsMATRIKS(M); i++){
		for (j=GetFirstIdxKolMATRIKS(M); j<=GetLastIdxKolMATRIKS(M); j++){
			if (j != GetLastIdxKolMATRIKS(M)){
				printf("%c ", Elmt(M,i,j));
			} else if (i != GetLastIdxBrsMATRIKS(M)){
				printf("%c\n", Elmt(M,i,j));
			} else{
				printf("%c", Elmt(M,i,j));
			}
		}
	}
}

/* ********** KELOMPOK OPERASI ARITMATIKA TERHADAP TYPE ********** */                                  
MATRIKS TambahMATRIKS (MATRIKS M1, MATRIKS M2)
/* Prekondisi : M1  berukuran sama dengan M2 */
/* Mengirim hasil penjumlahan matriks: M1 + M2 */ 
{
	//KAMUS LOKAL
	indeks i,j;
	MATRIKS temp;

	//ALGORITMA
	MakeMATRIKS(NBrsEff(M1), NKolEff(M1), &temp);
	for (i=GetFirstIdxBrsMATRIKS(M1); i<=GetLastIdxBrsMATRIKS(M1); i++){
		for (j=GetFirstIdxKolMATRIKS(M1); j<=GetLastIdxKolMATRIKS(M1); j++){
			Elmt(temp,i,j) = Elmt(M1,i,j)+Elmt(M2,i,j);	
		}
	}
	return temp;
}

MATRIKS KurangMATRIKS (MATRIKS M1, MATRIKS M2)
/* Prekondisi : M berukuran sama dengan M */
/* Mengirim hasil pengurangan matriks: salinan M1 – M2 */ 
{
	//KAMUS LOKAL
	indeks i,j;
	MATRIKS temp;

	//ALGORITMA
	MakeMATRIKS(NBrsEff(M1), NKolEff(M1), &temp);
	for (i=GetFirstIdxBrsMATRIKS(M1); i<=GetLastIdxBrsMATRIKS(M1); i++){
		for (j=GetFirstIdxKolMATRIKS(M1); j<=GetLastIdxKolMATRIKS(M1); j++){
			Elmt(temp,i,j) = Elmt(M1,i,j)-Elmt(M2,i,j);	
		}
	}
	return temp;	
}

MATRIKS KaliMATRIKS (MATRIKS M1, MATRIKS M2)
/* Prekondisi : Ukuran kolom efektif M1 = ukuran baris efektif M2 */
/* Mengirim hasil perkalian matriks: salinan M1 * M2 */
{
	//KAMUS LOKAL
	indeks i,j,k;
	MATRIKS temp;
	int sum;

	//ALGORITMA
	MakeMATRIKS(NBrsEff(M1), NKolEff(M2), &temp);
	for (i=GetFirstIdxBrsMATRIKS(M1); i<=GetLastIdxBrsMATRIKS(M1); i++){
		for (j=GetFirstIdxKolMATRIKS(M2); j<=GetLastIdxKolMATRIKS(M2); j++){
			sum = 0;
			for (k=GetFirstIdxKolMATRIKS(M1); k<=GetLastIdxKolMATRIKS(M1); k++){
				sum += (Elmt(M1,i,k)*Elmt(M2,k,j));
			}
			Elmt(temp,i,j) = sum;
		}
	}
	return temp;
}

MATRIKS KaliKonsMATRIKS (MATRIKS M, ElType X)
/* Mengirim hasil perkalian setiap elemen M dengan X */
{
	//KAMUS LOKAL
	indeks i,j;
	MATRIKS temp;

	//ALGORITMA
	MakeMATRIKS(NBrsEff(M), NKolEff(M), &temp);
	for (i=GetFirstIdxBrsMATRIKS(M); i<=GetLastIdxBrsMATRIKS(M); i++){
		for (j=GetFirstIdxKolMATRIKS(M); j<=GetLastIdxKolMATRIKS(M); j++){
			Elmt(temp,i,j) = Elmt(M,i,j)*X;	
		}
	}
	return temp;	
}

void PKaliKonsMATRIKS (MATRIKS * M, ElType K)
/* I.S. M terdefinisi, K terdefinisi */
/* F.S. Mengalikan setiap elemen M dengan K */
{
	//KAMUS LOKAL
	indeks i,j;

	//ALGORITMA
	for (i=GetFirstIdxBrsMATRIKS(*M); i<=GetLastIdxBrsMATRIKS(*M); i++){
		for (j=GetFirstIdxKolMATRIKS(*M); j<=GetLastIdxKolMATRIKS(*M); j++){
			Elmt(*M,i,j) *= K;	
		}
	}
}

/* ********** KELOMPOK OPERASI RELASIONAL TERHADAP MATRIKS ********** */
boolean EQ (MATRIKS M1, MATRIKS M2)
/* Mengirimkan true jika M1 = M2, yaitu NBElmt(M1) = NBElmt(M2) dan */
/* untuk setiap i,j yang merupakan indeks baris dan kolom M1(i,j) = M2(i,j) */
/* Juga merupakan strong EQ karena GetFirstIdxBrs(M1) = GetFirstIdxBrs(M2) 
   dan GetLastIdxKol(M1) = GetLastIdxKol(M2) */
{
	//KAMUS
	indeks i,j;
	boolean Found;

	//ALGORITMA
	if (NBElmt(M1) == NBElmt(M2)){
		if ((GetFirstIdxBrsMATRIKS(M1) == GetFirstIdxBrsMATRIKS(M2)) && (GetLastIdxKolMATRIKS(M1) == GetLastIdxKolMATRIKS(M2))){
			i = GetFirstIdxBrsMATRIKS(M1);
			Found = false;
			while (i<=GetLastIdxBrsMATRIKS(M1) && (Found==false)){
				j = GetFirstIdxKolMATRIKS(M1);
				while (j<=GetLastIdxKolMATRIKS(M1) && (Found==false)){
					if (Elmt(M1,i,j) != Elmt(M2,i,j)){
						Found = true;
					} else
						j++;
				}
				i++;
			}
			if (Found == true)
				return false;
			else
				return (true);
		} else
			return false;
	} else
		return false;
}

boolean NEQ (MATRIKS M1, MATRIKS M2)
/* Mengirimkan true jika M1 tidak sama dengan M2 */
{
	return(!EQ(M1,M2));
}

boolean EQSizeMATRIKS (MATRIKS M1, MATRIKS M2)
/* Mengirimkan true jika ukuran efektif matriks M1 sama dengan ukuran efektif M2 */
/* yaitu GetBrsEff(M1) = GetNBrsEff (M2) dan GetNKolEff (M1) = GetNKolEff (M2) */
{
	return((NBrsEff(M1) == NBrsEff (M2)) && (NKolEff (M1) == NKolEff (M2)));
}

/* ********** Operasi lain ********** */
int NBElmt (MATRIKS M)
/* Mengirimkan banyaknya elemen M */
{
	return(NBrsEff(M)*NKolEff(M));
}

/* ********** KELOMPOK TEST TERHADAP MATRIKS ********** */
boolean IsBujurSangkarMATRIKS (MATRIKS M)
/* Mengirimkan true jika M adalah matriks dg ukuran baris dan kolom sama */
{
	return(NBrsEff(M)==NKolEff(M));
}

boolean IsSimetriMATRIKS (MATRIKS M)
/* Mengirimkan true jika M adalah matriks simetri : IsBujurSangkar(M) 
   dan untuk setiap elemen M, M(i,j)=M(j,i) */
{
	//KAMUS
	indeks i,j;
	boolean Found;

	//ALGORITMA
	if (IsBujurSangkarMATRIKS(M)){
		i = GetFirstIdxBrsMATRIKS(M);
		Found = false;
		while (i<=GetLastIdxBrsMATRIKS(M) && (Found==false)){
			j = GetFirstIdxKolMATRIKS(M);
			while (j<=GetLastIdxKolMATRIKS(M) && (Found==false)){
				if (Elmt(M,i,j) != Elmt(M,j,i)){
					Found = true;
				} else
					j++;
			}
			i++;
		}
		if (Found == true)
			return false;
		else
			return (true);
	}else
		return false;
}

boolean IsSatuanMATRIKS (MATRIKS M)
/* Mengirimkan true jika M adalah matriks satuan: IsBujurSangkar(M) dan 
   setiap elemen diagonal M bernilai 1 dan elemen yang bukan diagonal bernilai 0 */ 
{
	//KAMUS
	indeks i,j;
	boolean Found;

	//ALGORITMA
	if (IsBujurSangkarMATRIKS(M)){
		i = GetFirstIdxBrsMATRIKS(M);
		Found = false;
		while (i<=GetLastIdxBrsMATRIKS(M) && (Found==false)){
			j = GetFirstIdxKolMATRIKS(M);
			while (j<=GetLastIdxKolMATRIKS(M) && (Found==false)){
				if (i==j){
					if (Elmt(M,i,j) != 1)
						Found = true;
					else
						j++;
				}else{
					if (Elmt(M,i,j) != 0)
						Found = true;
					else
						j++;;
				}
			}
			i++;
		}
		if (Found == true)
			return false;
		else
			return true;
	}else
		return false;
}

boolean IsSparseMATRIKS (MATRIKS M)
/* Mengirimkan true jika M adalah matriks sparse: mariks “jarang” dengan definisi: 
   hanya maksimal 5% dari memori matriks yang efektif bukan bernilai 0 */ 
{
	//KAMUS
	indeks i,j;
	float sparse,count;

	//ALGORITMA
	i = GetFirstIdxBrsMATRIKS(M);
	count = 0.0;
	sparse = 0.0;
	while (i<=GetLastIdxBrsMATRIKS(M) && (sparse<=0.05)){
		j = GetFirstIdxKolMATRIKS(M);
		while (j<=GetLastIdxKolMATRIKS(M) && (sparse<=0.05)){
			if (Elmt(M,i,j) != 0){
				count++;
				sparse = (count*1.0)/NBElmt(M);
			}
			j++;
		}
		i++;
	}
	return(sparse<=0.05);
}
MATRIKS Inverse1MATRIKS (MATRIKS M)
/* Menghasilkan salinan M dengan setiap elemen "di-invers", yaitu dinegasikan (dikalikan -1) */
{
	return(KaliKonsMATRIKS (M, -1));
}

void getCofactor(MATRIKS M, MATRIKS *temp, int p, int q) 
{ 
	//KAMUS LOKAL
  	indeks i,j,row,col;
  	
  	//ALGPRITMA
  	i = 1;
  	j = 1;
    for (row=GetFirstIdxBrsMATRIKS(M); row<=GetLastIdxBrsMATRIKS(M); row++){ 
        for (col=GetFirstIdxBrsMATRIKS(M); col<=GetLastIdxBrsMATRIKS(M); col++){ 
            if ((row != p) && (col != q)){ 
                Elmt(*temp,i,j) = Elmt(M,row,col);
  				j++;
                if (j == GetLastIdxBrsMATRIKS(M)){ 
                    j = 1; 
                    i++; 
                } 
            } 
        } 
    }
} 

float DeterminanMATRIKS (MATRIKS M)
/* Prekondisi: IsBujurSangkar(M) */
/* Menghitung nilai determinan M */
{
	//KAMUS LOKAL
	float Det;
	MATRIKS temp;
	int sign;
	indeks i;
	
	//ALGORITMA
	Det = 0.0;
	sign = 1;
  	//BASIS
	if (GetLastIdxBrsMATRIKS(M) == 1){
    	return Elmt(M,1,1); 
	}
	//REKURSI 
	for (i=GetFirstIdxKolMATRIKS(M); i<=GetLastIdxKolMATRIKS(M); i++){ 
    	// KOFAKTOR
    	MakeMATRIKS(NBrsEff(M)-1, NKolEff(M)-1, &temp);
    	getCofactor(M, &temp, 1, i);
    	Det += sign * Elmt(M,1,i) * DeterminanMATRIKS(temp); 
    	sign = -sign; 
	} 
	return Det;
}

void PInverse1MATRIKS (MATRIKS * M)
/* I.S. M terdefinisi */
/* F.S. M di-invers, yaitu setiap elemennya dinegasikan (dikalikan -1) */
{
	PKaliKonsMATRIKS (M, -1);
}

void TransposeMATRIKS (MATRIKS * M)
/* I.S. M terdefinisi dan IsBujursangkar(M) */
/* F.S. M "di-transpose", yaitu setiap elemen M(i,j) ditukar nilainya dengan elemen M(j,i) */
{
	//KAMUS LOKAL
	MATRIKS temp;
	indeks i,j;

	//ALGORITMA
	CopyMATRIKS(*M, &temp);
	for (i = GetFirstIdxBrsMATRIKS(temp); i<=GetLastIdxBrsMATRIKS(temp); i++){
		for (j = GetFirstIdxKolMATRIKS(temp); j<=GetLastIdxKolMATRIKS(temp); j++){
			(Elmt(*M,i,j) = Elmt(temp,j,i));
		}
	}
}
