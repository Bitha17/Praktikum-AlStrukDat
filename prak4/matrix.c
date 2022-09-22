/* File: matrix.c */
/* NIM : 13521111 */
/* Nama: Tabitha Permalla */
/* Tanggal: 22 September 2022 */
/* Topik praktikum: ADT Matrix */

#include <stdio.h>
#include "matrix.h"

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */
/* *** Konstruktor membentuk Matrix *** */
void createMatrix(int nRows, int nCols, Matrix *m){
/* Membentuk sebuah Matrix "kosong" yang siap diisi berukuran nRow x nCol di "ujung kiri" memori */
/* I.S. nRow dan nCol adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks m sesuai dengan definisi di atas terbentuk */
    ROW_EFF(*m) = nRows;
    COL_EFF(*m) = nCols;
}

/* *** Selektor "Dunia Matrix" *** */
boolean isMatrixIdxValid(int i, int j){
/* Mengirimkan true jika i, j adalah index yang valid untuk matriks apa pun */
    return ((i >= 0) && (i < ROW_CAP) && (j >= 0) && (j < COL_CAP));
}

/* *** Selektor: Untuk sebuah matriks m yang terdefinisi: *** */
IdxType getLastIdxRow(Matrix m){
/* Mengirimkan Index baris terbesar m */
    return ROW_EFF(m) - 1;
}
IdxType getLastIdxCol(Matrix m){
/* Mengirimkan Index kolom terbesar m */
    return COL_EFF(m) - 1;
}
boolean isIdxEff(Matrix m, IdxType i, IdxType j){
/* Mengirimkan true jika i, j adalah Index efektif bagi m */
    return ((i >= 0) && (i < ROW_EFF(m)) && (j >= 0) && (j < COL_EFF(m)));
}
ElType getElmtDiagonal(Matrix m, IdxType i){
/* Mengirimkan elemen m(i,i) */
    return ELMT(m,i,i);
}

/* ********** Assignment  Matrix ********** */
void copyMatrix(Matrix mIn, Matrix *mOut){
/* Melakukan assignment mOut <- mIn */
    createMatrix(ROW_EFF(mIn), COL_EFF(mIn), mOut);
    for (int i = 0; i < ROW_EFF(mIn); i++){
        for (int j = 0; j < COL_EFF(mIn); j++){
            ELMT(*mOut,i,j) = ELMT(mIn,i,j);
        }
    }
}

/* ********** KELOMPOK BACA/TULIS ********** */
void readMatrix(Matrix *m, int nRow, int nCol){
/* I.S. isIdxValid(nRow,nCol) */
/* F.S. m terdefinisi nilai elemen efektifnya, berukuran nRow x nCol */
/* Proses: Melakukan CreateMatrix(m,nRow,nCol) dan mengisi nilai efektifnya */
/* Selanjutnya membaca nilai elemen per baris dan kolom */
/* Contoh: Jika nRow = 3 dan nCol = 3, maka contoh cara membaca isi matriks :
1 2 3
4 5 6
8 9 10 
*/
    createMatrix(nRow,nCol,m);
    for (int i = 0; i < nRow; i++){
        for (int j = 0; j < nCol; j++){
            scanf("%d", &ELMT(*m,i,j));
        }
    }
}
void displayMatrix(Matrix m){
/* I.S. m terdefinisi */
/* F.S. Nilai m(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris 
   dipisahkan sebuah spasi. Baris terakhir tidak diakhiri dengan newline */
/* Proses: Menulis nilai setiap elemen m ke layar dengan traversal per baris dan per kolom */
/* Contoh: menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
1 2 3
4 5 6
8 9 10
*/
    for (int i = 0; i < ROW_EFF(m); i++){
        for (int j = 0; j < COL_EFF(m); j++){
            if (j == getLastIdxCol(m)){
                printf("%d\n", ELMT(m,i,j));
            }
            else{            
                printf("%d ", ELMT(m,i,j));
            }
        }
    }
}

/* ********** KELOMPOK OPERASI ARITMATIKA TERHADAP TYPE ********** */
Matrix addMatrix(Matrix m1, Matrix m2){
/* Prekondisi : m1 berukuran sama dengan m2 */
/* Mengirim hasil penjumlahan matriks: m1 + m2 */
    Matrix m3;
    createMatrix(ROW_EFF(m1), COL_EFF(m1), &m3);
    for (int i = 0; i < ROW_EFF(m1); i++){
        for (int j = 0; j < COL_EFF(m1); j++){
            ELMT(m3,i,j) = ELMT(m1,i,j) + ELMT(m2,i,j);
        }
    }
    return m3;
}
Matrix subtractMatrix(Matrix m1, Matrix m2){
/* Prekondisi : m1 berukuran sama dengan m2 */
/* Mengirim hasil pengurangan matriks: salinan m1 – m2 */
    Matrix m3;
    createMatrix(ROW_EFF(m1), COL_EFF(m1), &m3);
    for (int i = 0; i < ROW_EFF(m1); i++){
        for (int j = 0; j < COL_EFF(m1); j++){
            ELMT(m3,i,j) = ELMT(m1,i,j) - ELMT(m2,i,j);
        }
    }
    return m3;
}
Matrix multiplyMatrix(Matrix m1, Matrix m2){
/* Prekondisi : Ukuran kolom efektif m1 = ukuran baris efektif m2 */
/* Mengirim hasil perkalian matriks: salinan m1 * m2 */
    Matrix m3;
    createMatrix(ROW_EFF(m1), COL_EFF(m2), &m3);
    for (int i = 0; i < ROW_EFF(m3); i++){
        for (int j = 0; j < COL_EFF(m3); j++){
            int temp = 0;
            for (int k = 0; k < COL_EFF(m1); k++){
                temp += (ELMT(m1,i,k)*ELMT(m2,k,j));
            }
            ELMT(m3,i,j) = temp;
        }
    }
    return m3;
}
Matrix multiplyByConst(Matrix m, ElType x){
/* Mengirim hasil perkalian setiap elemen m dengan x */
    Matrix m1;
    createMatrix(ROW_EFF(m), COL_EFF(m), &m1);
    for (int i = 0; i < ROW_EFF(m1); i++){
        for (int j = 0; j < COL_EFF(m1); j++){
            ELMT(m1,i,j) = ELMT(m,i,j)*x;
        }
    }
    return m1;
}
void pMultiplyByConst(Matrix *m, ElType k){
/* I.S. m terdefinisi, k terdefinisi */
/* F.S. Mengalikan setiap elemen m dengan k */
    *m = multiplyByConst(*m,k);
}
/* ********** KELOMPOK OPERASI RELASIONAL TERHADAP Matrix ********** */
boolean isMatrixEqual(Matrix m1, Matrix m2){
/* Mengirimkan true jika m1 = m2, yaitu count(m1) = count(m2) dan */
/* untuk setiap i,j yang merupakan Index baris dan kolom m1(i,j) = m2(i,j) */
/* Juga merupakan strong eq karena getLastIdxCol(m1) = getLastIdxCol(m2) */
    if ((ROW_EFF(m1) == ROW_EFF(m2)) && (COL_EFF(m1) == COL_EFF(m2))){
        for (int i = 0; i < ROW_EFF(m1); i++){
            for (int j = 0; j < COL_EFF(m1); j++){
                if (ELMT(m1,i,j) != ELMT(m2,i,j)){
                    return false;
                }
            }
        }
        return true;
    }
    else{
        return false;
    }
}
boolean isMatrixNotEqual(Matrix m1, Matrix m2){
/* Mengirimkan true jika m1 tidak sama dengan m2 */
    return !isMatrixEqual(m1,m2);
}
boolean isMatrixSizeEqual(Matrix m1, Matrix m2){
/* Mengirimkan true jika ukuran efektif matriks m1 sama dengan ukuran efektif m2 */
/* yaitu RowEff(m1) = RowEff (m2) dan ColEff (m1) = ColEff (m2) */
    return (ROW_EFF(m1) == ROW_EFF(m2) && COL_EFF(m1) == COL_EFF(m2));
}

/* ********** Operasi lain ********** */
int countElmt(Matrix m){
/* Mengirimkan banyaknya elemen m */
    return (ROW_EFF(m)*COL_EFF(m));
}

/* ********** KELOMPOK TEST TERHADAP Matrix ********** */
boolean isSquare(Matrix m){
/* Mengirimkan true jika m adalah matriks dg ukuran baris dan kolom sama */
    return (ROW_EFF(m) == COL_EFF(m));
}
boolean isSymmetric(Matrix m){
/* Mengirimkan true jika m adalah matriks simetri : isSquare(m) 
   dan untuk setiap elemen m, m(i,j)=m(j,i) */
    if (isSquare(m)){
        for (int i = 0; i < ROW_EFF(m); i++){
            for (int j = 0; j < COL_EFF(m); j++){
                if (ELMT(m,i,j) != ELMT(m,j,i)){
                    return false;
                }
            }
        }
        return true;
    }
    else{
        return false;
    }
}
boolean isIdentity(Matrix m){
/* Mengirimkan true jika m adalah matriks satuan: isSquare(m) dan 
   setiap elemen diagonal m bernilai 1 dan elemen yang bukan diagonal bernilai 0 */
    if (isSquare(m)){
        for (int i = 0; i < ROW_EFF(m); i++){
            for (int j = 0; j < COL_EFF(m); j++){
                if (i == j && (ELMT(m,i,j) != 1)){
                        return false;
                    }
                else if (i != j && (ELMT(m,i,j) != 0)){
                        return false;
                    }
                }
            }
        return true;
    }
    else{
        return false;
    }
}
boolean isSparse(Matrix m){
/* Mengirimkan true jika m adalah matriks sparse: matriks “jarang” dengan definisi: 
   hanya maksimal 5% dari memori matriks yang efektif bukan bernilai 0 */
    int a = countElmt(m)/20;
    int count = 0;
    for (int i = 0; i < ROW_EFF(m); i++){
        for (int j = 0; j < COL_EFF(m); j++){
            if (ELMT(m,i,j) != 0){
                count++;
            }
        }
    }
    return (count <= a);
}
Matrix negation(Matrix m){
/* Menghasilkan salinan m dengan setiap elemen dinegasikan (dikalikan -1) */
    return multiplyByConst(m,-1);
}
void pNegation(Matrix *m){
/* I.S. m terdefinisi */
/* F.S. m di-invers, yaitu setiap elemennya dinegasikan (dikalikan -1) */
    *m = negation(*m);
}
float determinant(Matrix m){
/* Prekondisi: isSquare(m) */
/* Menghitung nilai determinan m */
    if (ROW_EFF(m) == 1) {
        return ELMT(m, 0, 0);
    } 
    else {
        float d = 0;
        int k = 1;
        for (int i=0; i<ROW_EFF(m);i++) {
            Matrix m1;
            createMatrix(ROW_EFF(m)-1, ROW_EFF(m)-1, &m1);
            for (int j = 0; j<ROW_EFF(m1); j++){
                for (int k = 0; k<COL_EFF(m1); k++){
                    if (k < i){
                        ELMT(m1,j,k) = ELMT(m,j+1,k);
                    }
                    else{
                        ELMT(m1,j,k) = ELMT(m,j+1,k+1);
                    }
                }
            }
            d += k*ELMT(m, 0, i)*determinant(m1);
            k *= -1;
        }
        return d;
    }
}
Matrix transpose(Matrix m){
/* I.S. m terdefinisi dan IsSquare(m) */
/* F.S. menghasilkan salinan transpose dari m, yaitu setiap elemen m(i,j) ditukar nilainya dengan elemen m(j,i) */
    Matrix m1;
    createMatrix(ROW_EFF(m), COL_EFF(m), &m1);
    for (int i = 0; i < ROW_EFF(m); i++){
        for (int j = 0; j < COL_EFF(m); j++){
            ELMT(m1,i,j) = ELMT(m,j,i);
        }
    }
    return m1;
}
void pTranspose(Matrix *m){
/* I.S. m terdefinisi dan IsSquare(m) */
/* F.S. m "di-transpose", yaitu setiap elemen m(i,j) ditukar nilainya dengan elemen m(j,i) */
    *m = transpose(*m);
}

/* Praktikum */
/* Operasi berbasis baris dan per kolom */


float AvgRow(Matrix M, IdxType i){
/* Menghasilkan rata-rata dari elemen pada baris ke-i */
/* Prekondisi: i adalah indeks baris efektif dari M */
    float sum = 0;
    for(int j = 0; j < COL_EFF(M); j++){
        sum += ELMT(M,i,j);
    }
    return sum/COL_EFF(M);
}


float AvgCol(Matrix M, IdxType j){
/* Menghasilkan rata-rata dari elemen pada kolom ke-j */
/* Prekondisi: j adalah indeks kolom efektif dari M */
    float sum = 0;
    for(int i = 0; i < ROW_EFF(M); i++){
        sum += ELMT(M,i,j);
    }
    return sum/ROW_EFF(M);
}


void MinMaxRow(Matrix M, IdxType i, ElType * max, ElType * min){
/* I.S. i adalah indeks baris efektif dari M, M terdefinisi */
/* F.S. max berisi elemen maksimum pada baris i dari M
min berisi elemen minimum pada baris i dari M */
    *max = ELMT(M,i,0);
    *min = ELMT(M,i,0);
    for(int j = 1; j < COL_EFF(M); j++){
        if (ELMT(M,i,j) > *max){
            *max = ELMT(M,i,j);
        }
        if (ELMT(M,i,j) < *min){
            *min = ELMT(M,i,j);
        }
    }
}


void MinMaxCol(Matrix M, IdxType j, ElType * max, ElType * min){
/* I.S. j adalah indeks kolom efektif dari M, M terdefinisi */
/* F.S. max berisi elemen maksimum pada kolom j dari M
min berisi elemen minimum pada kolom j dari M */
    *max = ELMT(M,0,j);
    *min = ELMT(M,0,j);
    for(int i = 1; i < ROW_EFF(M); i++){
        if (ELMT(M,i,j) > *max){
            *max = ELMT(M,i,j);
        }
        if (ELMT(M,i,j) < *min){
            *min = ELMT(M,i,j);
        }
    }
}

int CountNumRow(Matrix M, IdxType i, ElType X){
/* Menghasilkan banyaknya kemunculan X pada baris i dari M */
    int count = 0;
    for(int j = 0; j < COL_EFF(M); j++){
        if(ELMT(M,i,j) == X){
            count++;
        }
    }
    return count;
}

int CountNumCol(Matrix M, IdxType j, ElType X){
/* Menghasilkan banyaknya kemunculan X pada kolom j dari M */
    int count = 0;
    for(int i = 0; i < ROW_EFF(M); i++){
        if(ELMT(M,i,j) == X){
            count++;
        }
    }
    return count;
}

void RotateMat(Matrix *m){
/* I.S. m terdefinisi dan IsSquare(m) */
/* F.S. m "di-rotasi" searah jarum jam
   untuk semua "lapisan" elemen mulai dari yang terluar
   Contoh matrix 3x3 sebelum dirotasi:
   1 2 3
   4 5 6
   7 8 9
   Contoh matrix 3x3 setelah dirotasi:
   4 1 2
   7 5 3
   8 9 6
   Contoh matrix 4x4 sebelum dirotasi:
   1 2 3 4
   5 6 7 8
   9 10 11 12
   13 14 15 16
   Contoh matrix 4x4 setelah dirotasi:
   5 1 2 3
   9 10 6 4
   13 11 7 8
   14 15 16 12
*/
    int row = 0, col = 0;
    ElType prev, curr;
    int a = ROW_EFF(*m);
    int b = COL_EFF(*m);
    while (row < a && col < b) {
        if (row + 1 == a || col + 1 == b)
            break;
        prev = ELMT(*m,row+1,col); 
        for (int i = col; i < a; i++) {
            curr = ELMT(*m,row,i);
            ELMT(*m,row,i) = prev;
            prev = curr;
        }
        row++;
        for (int i = row; i < b; i++) {
            curr = ELMT(*m,i,b-1);
            ELMT(*m,i,b-1) = prev;
            prev = curr;
        }
        b--;
        if (row < a) {
            for (int i = b-1; i >= col; i--)
            {
                curr = ELMT(*m,a-1,i);
                ELMT(*m,a-1,i) = prev;
                prev = curr;
            }
        }
        a--;
        if (col < b) {
            for (int i = a-1; i >= row; i--)
            {
                curr = ELMT(*m,i,col);
                ELMT(*m,i,col) = prev;
                prev = curr;
            }
        }
        col++;
    }
}