/* File: queuelinked.c */
/* NIM : 13521111 */
/* Nama: Tabitha Permalla */
/* Tanggal: 7 November 2022 */
/* Topik Praktikum: Queue dan Stack dengan list berkait */

#include <stdio.h>
#include "queuelinked.h"

/* Prototype manajemen memori */
Address newNode(ElType x){
/* Mengembalikan alamat sebuah Node hasil alokasi dengan info = x, 
   atau NIL jika alokasi gagal */
    Address p = (Address) malloc(sizeof(Node));
    if (p != NULL){
        INFO(p) = x;
        NEXT(p) = NULL;
    }
    return p;
}

boolean isEmpty(Queue q){
/* Mengirim true jika q kosong: ADDR_HEAD(q)=NULL and ADDR_TAIL(q)=NULL */
    return ADDR_HEAD(q) == NULL && ADDR_TAIL(q) == NULL;
}

int length(Queue q){
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika q kosong */
    Address p = ADDR_HEAD(q);
    int i = 0;
    while (p != NULL){
        i++;
        p = NEXT(p);
    }
    return i;
}

/*** Kreator ***/
void CreateQueue(Queue *q){
/* I.S. sembarang */
/* F.S. Sebuah q kosong terbentuk */
    ADDR_HEAD(*q) = NULL;
    ADDR_TAIL(*q) = NULL;
}

void DisplayQueue(Queue q){
/* Proses : Menuliskan isi Queue, ditulis di antara kurung siku; antara dua elemen 
    dipisahkan dengan separator "koma", tanpa tambahan karakter di depan, di tengah, 
    atau di belakang, termasuk spasi dan enter */
/* I.S. q boleh kosong */
/* F.S. Jika q tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika Queue kosong : menulis [] */
    if (isEmpty(q)){
        printf("[]");
    } else{
        Address p = ADDR_HEAD(q);
        printf("[");
        while (NEXT(p) != NULL){
            printf("%d,", INFO(p));
            p = NEXT(p);
        }
        printf("%d]",INFO(p));
    }
}

/*** Primitif Enqueue/Dequeue ***/
void enqueue(Queue *q, ElType x){
/* Proses: Mengalokasi x dan menambahkan x pada bagian Tail dari q
           jika alokasi berhasil; jika alokasi gagal q tetap */
/* Pada dasarnya adalah proses insertLast */
/* I.S. q mungkin kosong */
/* F.S. x menjadi Tail, Tail "maju" */
    Address p = newNode(x);
    if (p != NULL){
        if (isEmpty(*q)){
            ADDR_HEAD(*q) = p;
        } else{
            NEXT(ADDR_TAIL(*q)) = p;
        }
        ADDR_TAIL(*q) = p;
    }
}

void dequeue(Queue *q, ElType *x){
/* Proses: Menghapus x pada bagian HEAD dari q dan mendealokasi elemen HEAD */
/* Pada dasarnya operasi deleteFirst */
/* I.S. q tidak mungkin kosong */
/* F.S. x = nilai elemen HEAD pd I.S., HEAD "mundur" */
    Address p = ADDR_HEAD(*q);
    *x = HEAD(*q);
    ADDR_HEAD(*q) = NEXT(p);
    if(ADDR_HEAD(*q) == NIL){
        ADDR_TAIL(*q) = NIL;
    }
    NEXT(p) = NIL;
    free(p);
}