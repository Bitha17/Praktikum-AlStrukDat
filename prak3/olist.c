/* File: olist.c */
/* NIM : 13521111 */
/* Nama: Tabitha Permalla */
/* Tanggal: 15 September 2022 */
/* Topik praktikum: ADT List Statik dan Dinamik */

#include <stdio.h>
#include "liststatik.h"
#include "boolean.h"

int main(){
	ListStatik l;
	CreateListStatik(&l);
	readList(&l);
	printList(l);
	printf("\n");
	int x;
	scanf("%d", &x);
	int i = 0;
	int count = 0;
	int idx = -1;
	for (i; i < listLength(l); i++){
		if (ELMT(l,i) == x){
			count++;
			idx = i;
		} 
	}
	printf("%d\n", count);
	if (count != 0){
		printf("%d\n", idx);
		int max, min;
		extremeValues(l, &max, &min);
		if (x == max){
			printf("maksimum\n");
		}
		if (x == min){
			printf("minimum\n");
		}
		sortList(&l,true);
		if((listLength(l)) % 2 == 0){
			if (ELMT(l,(listLength(l))/2 - 1) == x){
				printf("median\n");
			}
		}else{
			if (ELMT(l,(listLength(l))/2) == x){
				printf("median\n");
			}
		}
	}else{
		printf("%d tidak ada\n", x);
	}
	return 0;
}