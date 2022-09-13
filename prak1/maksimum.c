 /* Nama File : maksimum */
 /* NIM	: 13521111 */
 /* Nama : Tabitha Permalla */
 /* Tanggal : 1 September 2022 */
 /* Topik praktikum : Perkenalan praktikum */
 /* Deskripsi : Program membaca 3 buah integer berturut-berturut, misalnya A, B, C, dan menghasilkan bilangan yang terbesar di antara ketiganya */

#include <stdio.h>
int main(){
	int max, b,c;
	scanf("%d", &max);
	scanf("%d", &b);
	scanf("%d", &c);
	if (b > max){
		max = b;
	}
	else{
		max=max;
	}
	if (c > max){
		max = c;
	}
	else{
		max=max;
	}
	printf("%d\n", max);
	return 0;
}