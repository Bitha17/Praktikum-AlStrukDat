/* File : sjf.c */
/* NIM : 13521111 */
/* Nama: Tabitha Permalla */
/* Tanggal: 7 Oktober 2022 */
/* ADT Queue */

#include <stdio.h>
#include "prioqueuetime.h"

int main(){
    int N;
    scanf("%d", &N);
    PrioQueueTime Q;
    MakeEmpty(&Q, N);
    int countout = 0;
    infotype in[N];
    for (int i = 0; i < N; i++){
        scanf("%d %c", &Time(in[i]), &Info(in[i]));
    }
    int countin = 0;
    int det1 = 0;
    int detik = 0;
    infotype out;
    while (countout < N){
        if (countin < N){
            infotype x;
            Time(x) = Time(in[countin]);
            Info(x) = Info(in[countin]); 
            Enqueue(&Q, x);
            countin++;
        }
        det1++;
        if (det1 > detik){
            Dequeue(&Q, &out);
            printf("%d %c\n", detik, Info(out));
            detik += Time(out);
            countout++;
        }
    }
}