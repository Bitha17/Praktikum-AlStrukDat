/* Nama File : beasiswa */
/* NIM	: 13521111 */
/* Nama : Tabitha Permalla */
/* Tanggal : 1 September 2022 */
/* Topik praktikum : Perkenalan praktikum */
/* Deskripsi : Program menerima masukan sebuah bilangan bulat, misal N dan kemudian menampilkan gambar belah ketupat bintang */

#include <stdio.h>
#include <stdbool.h>

int GambarBelahKetupat(int N){
	int i, j, k;
    for (i=0; i < N/2 ; i++){
		j = 0;
		do {
			printf(" ");
			j++;
		}
		while (j < (N/2 - i));
		k = 0;
		do {
			printf("*");
			k++;
		}
		while (k < ((i+1)*2 - 1));
		printf("\n");
	}
	for (i=0; i < N; i++){
		printf("*");
	}
	printf("\n");   
    for (i=0; i < N/2; i++){
		j = 0;
		do {
			printf(" ");
			j++;
		}
		while (j < (i + 1));
		k = 0;
		do {
			printf("*");
			k++;
		}
		while (k < (N - ((i+1)*2)));
		printf("\n");
	}
	return 0; 
}
    
    

bool IsValid(int N){
    if (N > 0 && N % 2 == 1){
        return true;
	}
    else {
        return false;
	}
}

int main(){
	int N;
	scanf("%d", &N);
	if (IsValid(N) == true){
		GambarBelahKetupat(N);
	}
	else {
		printf("Masukan tidak valid\n");
	}
	return 0;
}