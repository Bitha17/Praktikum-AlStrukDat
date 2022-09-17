/* File: intersect.c */
/* NIM : 13521111 */
/* Nama: Tabitha Permalla */
/* Tanggal: 15 September 2022 */
/* Topik praktikum: ADT List Statik dan Dinamik */

#include <stdio.h>
#include "liststatik.h"
#include "boolean.h"

int main(){
	ListStatik l1,l2,l3;
	CreateListStatik(&l1);
	readList(&l1);
	CreateListStatik(&l2);
	readList(&l2);
	CreateListStatik(&l3);
	if (isEmpty(l1) || isEmpty(l2)){
		printf("0\n");
		printf("[]\n");
	}
	else{
		for(int i = 0; i < listLength(l1); i++){
			for(int j = 0; j < listLength(l2); j++){
				if(ELMT(l1,i) == ELMT(l2,j)){
					insertLast(&l3,ELMT(l1,i));
				}
			}
		}
		sortList(&l3,true);
		printf("%d\n", listLength(l3));
		printList(l3);
		printf("\n");
	}
}