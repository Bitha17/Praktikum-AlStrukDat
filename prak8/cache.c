/* File : listlinier.c */
/* NIM : 13521111 */
/* Nama: Tabitha Permalla */
/* Tanggal: 27 Oktober 2022 */
/* Topik Praktikum: ADT Linked List */

#include <stdio.h>
#include "listlinier.h"

int main(){
    int n;
    ElType temp, temp1;
    float count, hit, ratio;
    scanf("%d", &n);
    scanf("%f", &count);
    if (n != 0){
        if (count != 0){
            List l;
            CreateList(&l);
            hit = 0.0;
            for (int i = 0; i < count; i++){
                scanf("%d", &temp);
                if(indexOf(l,temp) != IDX_UNDEF){
                    deleteAt(&l,indexOf(l,temp),&temp1);
                    insertFirst(&l,temp);
                    printf("hit ");
                    hit++;
                } else if(length(l) == n){
                    deleteLast(&l,&temp1);
                    insertFirst(&l,temp);
                    printf("miss ");
                } else{
                    insertFirst(&l,temp);
                    printf("miss ");
                }
                displayList(l);
                printf("\n");
            }
            ratio = hit/count;
        } else {
            ratio = 0.0;
        }
    } else{
        if (count != 0){
            for (int i = 0; i < count; i++){
                printf("miss []\n");
            }
        }
        ratio = 0.0;
    }
    printf("hit ratio: %.2f\n", ratio);
}