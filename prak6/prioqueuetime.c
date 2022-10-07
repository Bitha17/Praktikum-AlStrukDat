/* File : prioqueuetime.c */
/* NIM : 13521111 */
/* Nama: Tabitha Permalla */
/* Tanggal: 6 Oktober 2022 */
/* ADT Queue */
/* Definisi ADT Priority Queue Char dengan representasi array secara eksplisit dan alokasi dinamik */
/* Model Implementasi Versi III dengan circular buffer */
/* Elemen queue terurut membesar berdasarkan elemen time */

#include <stdio.h>
#include <stdlib.h>
#include "prioqueuetime.h"

/* ********* Prototype ********* */
boolean IsEmpty (PrioQueueTime Q){
/* Mengirim true jika Q kosong: lihat definisi di atas */
    return (Head(Q) == Nil) && (Tail(Q) == Nil);
}

boolean IsFull (PrioQueueTime Q){
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */
    return NBElmt(Q) == MaxEl(Q);
}

int NBElmt (PrioQueueTime Q){
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */
    if (IsEmpty(Q)){
        return 0;
    }
    else if (Tail(Q) >= Head(Q)){
        return Tail(Q) - Head(Q) + 1;
    }
    else{
        return MaxEl(Q) + Tail(Q) + 1 - Head(Q);
    }
}

/* *** Kreator *** */
void MakeEmpty (PrioQueueTime * Q, int Max){
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max+1 */
/* atau : jika alokasi gagal, Q kosong dg MaxEl=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */
    (*Q).T = (infotype*) malloc((Max + 1) * sizeof(infotype));
    if ((*Q).T != NULL) {
        MaxEl(*Q) = Max;
        Head(*Q) = Nil;
        Tail(*Q) = Nil;
    } 
    else {
        MaxEl(*Q) = 0;
    }
}

/* *** Destruktor *** */
void DeAlokasi(PrioQueueTime * Q){
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */
    free((*Q).T);
    MaxEl(*Q) = 0;
}

/* *** Primitif Add/Delete *** */
void Enqueue (PrioQueueTime * Q, infotype X){
/* Proses: Menambahkan X pada Q dengan aturan priority queue, terurut mengecil berdasarkan time */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X disisipkan pada posisi yang tepat sesuai dengan prioritas,
        TAIL "maju" dengan mekanisme circular buffer; */
    if (IsEmpty(*Q)){
        Head(*Q) = 0;
        Tail(*Q) = 0;
        InfoTail(*Q) = X;
    }
    else{
        if (Tail(*Q) == MaxEl(*Q) - 1){
            Tail(*Q) = 0;
            InfoTail(*Q) = X;
            if (Time(X) < Time(Elmt(*Q, MaxEl(*Q) - 1))){
                InfoTail(*Q) = Elmt(*Q, MaxEl(*Q) - 1);
                Elmt(*Q, MaxEl(*Q) - 1) = X;
                int count = MaxEl(*Q) - 1;
                while (count > 0 && ((Time(Elmt(*Q, count))) < (Time(Elmt(*Q, count - 1))))){
                    infotype temp = Elmt(*Q, count);
                    Elmt(*Q, count) = Elmt(*Q, count - 1);
                    Elmt(*Q, count - 1) = temp;
                    count--;
                }
            }
            
        }
        else{
            Tail(*Q)++;
            InfoTail(*Q) = X;
            int count = Tail(*Q);
            while (count > 0 && ((Time(Elmt(*Q, count))) < (Time(Elmt(*Q, count - 1))))){
                infotype temp = Elmt(*Q, count);
                Elmt(*Q, count) = Elmt(*Q, count - 1);
                Elmt(*Q, count - 1) = temp;
                count--;
            }
        }
    }
}

void Dequeue (PrioQueueTime * Q, infotype * X){
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer;
        Q mungkin kosong */
    *X = InfoHead(*Q);
    if (Head(*Q) == Tail(*Q)){
        Head(*Q) = Nil;
        Tail(*Q) = Nil;
    }
    else if(Head(*Q) == MaxEl(*Q) - 1){
        Head(*Q) = 0;
    }
    else{
        Head(*Q)++;
    }
}

/* Operasi Tambahan */
void PrintPrioQueueTime (PrioQueueTime Q){
/* Mencetak isi queue Q ke layar */
/* I.S. Q terdefinisi, mungkin kosong */
/* F.S. Q tercetak ke layar dengan format:
<time-1> <elemen-1>
...
<time-n> <elemen-n>
#
*/
    if (IsEmpty(Q)){
        printf("#\n");
    }
    else{
        if (Head(Q) == Tail(Q)){
            printf("%d %c\n", Time(InfoHead(Q)), Info(InfoHead(Q)));
        }
        else if (Tail(Q) > Head(Q)){
            for (int i = Head(Q); i < Tail(Q) + 1; i++){
                printf("%d %c\n", Time(Elmt(Q,i)), Info(Elmt(Q,i)));
            }
        }
        else{
            for (int i = Head(Q); i < MaxEl(Q); i++){
                printf("%d %c\n", Time(Elmt(Q,i)), Info(Elmt(Q,i)));
            }
            if (Tail(Q) != 0){
                for (int i = 0; i < Tail(Q) + 1; i++){
                    printf("%d %c\n", Time(Elmt(Q,i)), Info(Elmt(Q,i)));
                }
            }
        }
        printf("#\n");
    }
}
