/* File: mtime.c */
/* NIM : 13521111 */
/* Nama: Tabitha Permalla */
/* Tanggal: 8 September 2022 */
/* Topik praktikum: ADT Sederhana */
/* Deskripsi:   program yang digunakan untuk membaca beberapa pasangan TIME 
                yang merepresentasikan waktu mulai dan waktu selesai pembicaraan telepon 
                di suatu perusahaan penyedia layanan telepon, misalnya <T1, T2>.  */

#include <stdio.h>
#include "time.h"

int main(){
    int N, i;
    TIME t1, t2, maxT, minT;
	Hour(maxT) = 0;
	Minute(maxT) = 0;
	Second(maxT) = 0;

	Hour(minT) = 23;
	Minute(minT) = 59;
	Second(minT) = 59;
    
    scanf("%d", &N);
    for(i = 0; i < N; i++){
        printf("[%d]\n", (i+1));
        BacaTIME(&t1);
        BacaTIME(&t2);
        if(TGT(t2,t1)){
            printf("%ld\n", Durasi(t1,t2));
        }
        else{
            printf("%ld\n", Durasi(t2,t1));
        }
        if (TGT(t1, maxT))
		{
			maxT = t1;
		}
		if (TGT(t2, maxT))
		{
			maxT = t2;
		}

		if (TLT(t1, minT))
		{
			minT = t1;
		}
		if (TLT(t1, minT))
		{
			minT = t2;
		}
    }
    TulisTIME(minT);
    printf("\n");
    TulisTIME(maxT);
    printf("\n");
    return 0;
}