/* Nama File : beasiswa */
/* NIM	: 13521111 */
/* Nama : Tabitha Permalla */
/* Tanggal : 1 September 2022 */
/* Topik praktikum : Perkenalan praktikum */
/* Deskripsi : Program membaca input 2 buah bilangan riil (float), misalnya ip dan pot, dengan ip mewakili IP mahasiswa (bernilai 0..4) dan pot mewakili pendapatan orang tua (dalam juta rupiah, bernilai >= 0) dan menuliskan ke layar kategori beasiswa (bernilai 0..4) yang berhak didapatkan oleh mahasiswa tersebut sesuai ketentuan*/

#include <stdio.h>
int main(){
	float ip, pot;
	scanf("%f", &ip);
	scanf("%f", &pot);
	if (ip >= 3.5){
		printf("4\n");
	}
	else if (pot < 1){
			printf("1\n");
		}
	else if (pot < 5){
		if (ip >= 2.0){
			printf("3\n");
		}
		else {
			printf("2\n");
		}
	}
	else {
		printf("0\n");
	}
	return 0;
}