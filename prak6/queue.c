/* File : queue.h */
/* NIM : 13521111 */
/* Nama: Tabitha Permalla */
/* Tanggal: 4 Oktober 2022 */
/* ADT Queue */
/* Definisi ADT Queue versi 3 dengan representasi array secara eksplisit dan alokasi statik */

#include <stdio.h>
#include "queue.h"

/* *** Kreator *** */
void CreateQueue(Queue *q){
/* I.S. sembarang */
/* F.S. Sebuah q kosong terbentuk dengan kondisi sbb: */
/* - Index head bernilai IDX_UNDEF */
/* - Index tail bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah q kosong */
    IDX_HEAD(*q) = IDX_UNDEF;
    IDX_TAIL(*q) = IDX_UNDEF;
}

/* ********* Prototype ********* */
boolean isEmpty(Queue q){
/* Mengirim true jika q kosong: lihat definisi di atas */
    return (IDX_HEAD(q) == IDX_UNDEF) && (IDX_TAIL(q) == IDX_UNDEF);
}

boolean isFull(Queue q){
/* Mengirim true jika tabel penampung elemen q sudah penuh */
/* yaitu IDX_TAIL akan selalu di belakang IDX_HEAD dalam buffer melingkar*/
    return (IDX_TAIL(q) - IDX_HEAD(q) + 1) == CAPACITY;
}

int length(Queue q){
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika q kosong. */
    if (isEmpty(q)){
        return 0;
    }
    else if (IDX_TAIL(q) >= IDX_HEAD(q)){
        return IDX_TAIL(q) - IDX_HEAD(q) + 1;
    }
    else{
        return CAPACITY + IDX_TAIL(q) + 1 - IDX_HEAD(q);
    }    
}

/* *** Primitif Add/Delete *** */
void enqueue(Queue *q, ElType val){
/* Proses: Menambahkan val pada q dengan aturan FIFO */
/* I.S. q mungkin kosong, tabel penampung elemen q TIDAK penuh */
/* F.S. val menjadi TAIL yang baru, IDX_TAIL "mundur" dalam buffer melingkar. */
    if (isEmpty(*q)){
        IDX_HEAD(*q) = 0;
        IDX_TAIL(*q) = 0;
    }
    else{
        if (IDX_TAIL(*q) == CAPACITY - 1){
            IDX_TAIL(*q) = 0;
        }
        else{
            IDX_TAIL(*q)++;
        }
    }
    TAIL(*q) = val;
}

void dequeue(Queue *q, ElType *val){
/* Proses: Menghapus val pada q dengan aturan FIFO */
/* I.S. q tidak mungkin kosong */
/* F.S. val = nilai elemen HEAD pd I.S., IDX_HEAD "mundur";
        q mungkin kosong */
    *val = HEAD(*q);
    if (IDX_HEAD(*q) == IDX_TAIL(*q)){
        IDX_HEAD(*q) = IDX_UNDEF;
        IDX_TAIL(*q) = IDX_UNDEF;
    }
    else{
        IDX_HEAD(*q)++;
    }
}

/* *** Display Queue *** */
void displayQueue(Queue q){
/* Proses : Menuliskan isi Queue dengan traversal, Queue ditulis di antara kurung 
   siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan 
   karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. q boleh kosong */
/* F.S. Jika q tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika Queue kosong : menulis [] */
    if (isEmpty(q)){
        printf("[]\n");
    }
    else{
        printf("[");
        if (IDX_HEAD(q) == IDX_TAIL(q)){
            printf("%d]\n", HEAD(q));
        }
        else if (IDX_TAIL(q) > IDX_HEAD(q)){
            for (int i = IDX_HEAD(q); i < IDX_TAIL(q); i++){
                printf("%d,", q.buffer[i]);
            }
            printf("%d]\n", TAIL(q));
        }
        else{
            for (int i = IDX_HEAD(q); i < CAPACITY; i++){
                printf("%d,", q.buffer[i]);
            }
            if (IDX_TAIL(q) != 0){
                for (int i = 0; i < IDX_TAIL(q); i++){
                    printf("%d,", q.buffer[i]);
                }
            }
            printf("%d]\n", TAIL(q));
        }
    }
}