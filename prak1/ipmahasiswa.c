/* Nama File : beasiswa */
/* NIM	: 13521111 */
/* Nama : Tabitha Permalla */
/* Tanggal : 1 September 2022 */
/* Topik praktikum : Perkenalan praktikum */
/* Deskripsi : Program membaca masukan sejumlah nilai IP mahasiswa (bilangan rill) sebuah angkatan, sampai pengguna mengetikkan -999 */
/*			   Kemudian program menuliskan berapa banyak mahasiswa, berapa banyak yang lulus dan berapa yang tidak lulus (batas lulus adalah IP >= 2.75), dan rata-rata IP di kelas tersebut (data IP salah diabaikan) */

#include <stdio.h>
#include <stdbool.h>

bool isWithinRange (float X, float min, float max){
	bool status;
	if(X >= min && X <= max){
		status = true;
	}
	else{
		status = false;
	}
	return status;
}

int main(){
	float min = 0;
	float max = 4.0;
	float X = 0;
	int count = 0; 
	int lulus = 0;
	int tlulus = 0;
	float sum = 0;
	while (X != -999.0){
		scanf("%f", &X);
		if (isWithinRange(X, min, max)==true){
			sum += X;
			count++;
			if (X >= 2.75){
				lulus++;
			}
			else{
				tlulus++;
			}
		}
	}
	printf("%d\n", count);
	printf("%d\n", lulus);
	printf("%d\n", tlulus);
	float rata = sum / count;
	printf("%.2f\n", rata);
	return 0;
}