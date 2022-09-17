/* File: merge.c */
/* NIM : 13521111 */
/* Nama: Tabitha Permalla */
/* Tanggal: 15 September 2022 */
/* Topik praktikum: ADT List Statik dan Dinamik */

#include <stdio.h>
#include "listdin.h"
#include "boolean.h"

int main(){
	ListDin l1,l2,l3;
	CreateListDin(&l1,200);
	readList(&l1);
	CreateListDin(&l2,200);
	readList(&l2);
	CreateListDin(&l3,400);
	if (isEmpty(l1) && isEmpty(l2)){
		printf("0\n");
		printf("[]\n");
	}
	else{
		for(int i = 0; i < listLength(l1); i++){
			insertLast(&l3,ELMT(l1,i));
		}
		for(int j = 0; j < listLength(l2); j++){
			if(countVal(l3,ELMT(l2,j)) == 0){
					insertLast(&l3,ELMT(l2,j));
			}
		}
		sort(&l3,true);
		printf("%d\n", listLength(l3));
		printList(l3);
		printf("\n");
	}
}