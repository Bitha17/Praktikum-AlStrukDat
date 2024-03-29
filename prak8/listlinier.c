/* File : listlinier.c */
/* NIM : 13521111 */
/* Nama: Tabitha Permalla */
/* Tanggal: 27 Oktober 2022 */
/* Topik Praktikum: ADT Linked List */
/* contoh ADT list berkait dengan representasi fisik pointer  */
/* Representasi address dengan pointer */
/* ElType adalah integer */

#include <stdio.h>
#include "stdlib.h"
#include "listlinier.h"

/* Implementasi Node */
Address newNode(ElType val){
    Address p = (Address) malloc(sizeof(Node));
    if (p != NULL){
        INFO(p) = val;
        NEXT(p) = NULL;
    }
    return p;
}

/* PROTOTYPE */
/****************** PEMBUATAN LIST KOSONG ******************/
void CreateList(List *l){
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */
    FIRST(*l) = NULL;
}

/****************** TEST LIST KOSONG ******************/
boolean isEmpty(List l){
/* Mengirim true jika list kosong */
    return (FIRST(l) == NULL);
}

/****************** GETTER SETTER ******************/
ElType getElmt(List l, int idx){
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Mengembalikan nilai elemen l pada indeks idx */
    Address p = FIRST(l);
    for (int i = 0; i < idx; i++){
        p = NEXT(p);
    }
    return INFO(p);
}

void setElmt(List *l, int idx, ElType val){
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Mengubah elemen l pada indeks ke-idx menjadi val */
    Address p = FIRST(*l);
    for (int i = 0; i < idx; i++){
        p = NEXT(p);
    }
    INFO(p) = val;
}

int indexOf(List l, ElType val){
/* I.S. l, val terdefinisi */
/* F.S. Mencari apakah ada elemen list l yang bernilai val */
/* Jika ada, mengembalikan indeks elemen pertama l yang bernilai val */
/* Mengembalikan IDX_UNDEF jika tidak ditemukan */
    Address p = FIRST(l);
    boolean found = false;
    int i = 0;

    while (p != NULL && !found){
        if (INFO(p) == val){
            found = true;
        } else{
            p = NEXT(p);
            i++;
        }
    }

    if (found){
        return i;
    } else{
        return IDX_UNDEF;
    }
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void insertFirst(List *l, ElType val){
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai val jika alokasi berhasil. */
/* Jika alokasi gagal: I.S.= F.S. */
    Address p = newNode(val);
    if (p != NULL){
        NEXT(p) = FIRST(*l);
        FIRST(*l) = p;
    }
}

void insertLast(List *l, ElType val){
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
    if (isEmpty(*l)){
        insertFirst(l, val);
    } else{
        Address p = FIRST(*l);
        while (NEXT(p) != NULL){
            p = NEXT(p);
        }
        Address p1 = newNode(val);
        if (p1 != NULL){
            NEXT(p) = p1;
        }
    }
}

void insertAt(List *l, ElType val, int idx){
/* I.S. l tidak mungkin kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menyisipkan elemen dalam list pada indeks ke-idx (bukan menimpa elemen di i) */
/* yang bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
    if (idx == 0){
        insertFirst(l, val);
    } else{    
        Address p1 = newNode(val);
        if (p1 != NULL){
            Address p = FIRST(*l);
            for (int i = 0; i < idx - 1; i++){
                p = NEXT(p);
            }
            NEXT(p1) = NEXT(p);
            NEXT(p) = p1;
        }
    }
}

/*** PENGHAPUSAN ELEMEN ***/
void deleteFirst(List *l, ElType *val){
/* I.S. List l tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada x */
/*      dan alamat elemen pertama di-dealokasi */
    Address p = FIRST(*l);
    *val = INFO(p);
    FIRST(*l) = NEXT(p);
    free(p);
}

void deleteLast(List *l, ElType *val){
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada x */
/*      dan alamat elemen terakhir di-dealokasi */
    Address p = FIRST(*l);
    Address p1 = NULL;
    while (NEXT(p) != NULL){
        p1 = p;
        p = NEXT(p);
    }
    *val = INFO(p);
    if (p1 == NULL){
        FIRST(*l) = NULL;
    } else{
        NEXT(p1) = NULL;
    }
    free(p);
}

void deleteAt(List *l, int idx, ElType *val){
/* I.S. list tidak kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. val diset dengan elemen l pada indeks ke-idx. */
/*      Elemen l pada indeks ke-idx dihapus dari l */
    if (idx == 0){
        deleteFirst(l, val);
    } else{
        Address p = FIRST(*l);
        for (int i = 0; i < idx - 1; i++){
            p = NEXT(p);
        }
        Address p1 = NEXT(p);
        *val = INFO(p1);
        NEXT(p) = NEXT(p1);
        free(p1);
    }
}


/****************** PROSES SEMUA ELEMEN LIST ******************/
void displayList(List l){
// void printInfo(List l);
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
    if (isEmpty(l)){
        printf("[]");
    } else{
        Address p = FIRST(l);
        printf("[");
        while (NEXT(p) != NULL){
            printf("%d,", INFO(p));
            p = NEXT(p);
        }
        printf("%d]",INFO(p));
    }
}

int length(List l){
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
    Address p = FIRST(l);
    int i = 0;
    while (p != NULL){
        i++;
        p = NEXT(p);
    }
    return i;
}

/****************** PROSES TERHADAP LIST ******************/
List concat(List l1, List l2) {
/* I.S. l1 dan l2 sembarang */
/* F.S. l1 dan l2 kosong, l3 adalah hasil konkatenasi l1 & l2 */
/* Konkatenasi dua buah list : l1 dan l2    */
/* menghasilkan l3 yang baru (dengan elemen list l1 dan l2 secara beurutan). */
/* Tidak ada alokasi/dealokasi pada prosedur ini */
    List l3;
    CreateList(&l3);

    Address p = FIRST(l1);
    while (p != NULL){
        insertLast(&l3, INFO(p));
        p = NEXT(p);
    }
    p = FIRST(l2);
    while (p != NULL){
        insertLast(&l3, INFO(p));
        p = NEXT(p);
    }
    return l3;
}

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
boolean fSearch(List L, Address P){
/* Mencari apakah ada elemen list yang beralamat P */
/* Mengirimkan true jika ada, false jika tidak ada */
    boolean found = false;
    Address A = FIRST(L);
    while (A != NULL && !found){
        if (A == P){
            found = true;
        }
        A = NEXT(A);
    }
    return found;
}
Address searchPrec(List L, ElType X){
/* Mengirimkan address elemen sebelum elemen yang nilainya=X */
/* Mencari apakah ada elemen list dengan Info(P)=X */
/* Jika ada, mengirimkan address Prec, dengan Next(Prec)=P dan Info(P)=X. */
/* Jika tidak ada, mengirimkan Nil */
/* Jika P adalah elemen pertama, maka Prec=Nil */
/* Search dengan spesifikasi seperti ini menghindari */
/* traversal ulang jika setelah Search akan dilakukan operasi lain */
    if (isEmpty(L) || indexOf(L,X) == 0){
        return NULL;
    } else{
        Address P = FIRST(L);
        Address prev;
        while (P != NULL && INFO(P) != X){
            prev = P;
            P = NEXT(P);
        }
        if (P == NULL){
            return NULL;
        } else{
            return prev;
        }
    }
}

/*** Prekondisi untuk Max/Min : List tidak kosong ***/
ElType max(List l){
/* Mengirimkan nilai info(P) yang maksimum */
    Address p = FIRST(l);
    ElType max = INFO(p);
    while (p != NULL){
        if (INFO(p) > max){
            max = INFO(p);
        }
        p = NEXT(p);
    }
    return max;
}

Address adrMax(List l){
/* Mengirimkan address P, dengan info(P) yang bernilai maksimum */
    Address p = FIRST(l);
    ElType nmax = max(l);
    while (p != NULL && INFO(p) != nmax){
        p = NEXT(p);
    }
    return p;
}

ElType min(List l){
/* Mengirimkan nilai info(P) yang minimum */
    Address p = FIRST(l);
    ElType min = INFO(p);
    while (p != NULL){
        if (INFO(p) < min){
            min = INFO(p);
        }
        p = NEXT(p);
    }
    return min;
}

Address adrMin(List l){
/* Mengirimkan address P, dengan info(P) yang bernilai minimum */
    Address p = FIRST(l);
    ElType nmin = min(l);
    while (p != NULL && INFO(p) != nmin){
        p = NEXT(p);
    }
    return p;
}

/***************** FUNGSI dan PROSEDUR TAMBAHAN **************/
void deleteAll(List *l){
/* Delete semua elemen list dan alamat elemen di-dealokasi */
    Address p = FIRST(*l);
    int temp;
    while (p != NULL){
        deleteFirst(l,&temp);
        p = NEXT(p);
    }
    FIRST(*l) = NULL;
}

void copyList(List *l1, List *l2){
/* I.S. L1 sembarang. F.S. L2=L1 */
/* L1 dan L2 "menunjuk" kepada list yang sama.*/
/* Tidak ada alokasi/dealokasi elemen */
    FIRST(*l2) = FIRST(*l1); 
}

void inverseList(List *l){
/* I.S. sembarang. */
/* F.S. elemen list dibalik : */
/* Elemen terakhir menjadi elemen pertama, dan seterusnya. */
/* Membalik elemen list, tanpa melakukan alokasi/dealokasi. */
    if (!isEmpty(*l)){
        Address p = FIRST(*l);
        Address prev;
        Address last;
        while (NEXT(p) != NULL){
            p = NEXT(p);
        }
        last = p;
        while (p != FIRST(*l)){
            prev = *l;
            while (NEXT(prev) != p){
                prev = NEXT(prev);
            }
            NEXT(p) = prev;
            p = prev;
        }
        NEXT(p) = NULL;
        FIRST(*l) = last;
    }
}

void splitList(List *l1, List *l2, List l){
/* I.S. l mungkin kosong */
/* F.S. Berdasarkan L, dibentuk dua buah list l1 dan l2 */
/* L tidak berubah: untuk membentuk l1 dan l2 harus alokasi */
/* l1 berisi separuh elemen L dan l2 berisi sisa elemen L */
/* Jika elemen L ganjil, maka separuh adalah length(L) div 2 */
    CreateList(l1);
    CreateList(l2);
    int n = length(l) / 2;
    Address p = FIRST(l);
    for (int i = 0; i < n; i++){
        insertLast(l1, INFO(p));
        p = NEXT(p);
    }
    while (p != NULL){
        insertLast(l2, INFO(p));
        p = NEXT(p);
    }
}