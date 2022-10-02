/* File: longestword.c */
/* NIM : 13521111 */
/* Nama: Tabitha Permalla */
/* Tanggal: 29 September 2022 */
/* Topik praktikum: ADT Mesin Kata */

#include <stdio.h>
#include "wordmachine.h"

int main(){
	int maxlength = 0;
	endWord = false;
	STARTWORD();
	while (!endWord){
		if (currentWord.Length > maxlength){
			maxlength = currentWord.Length;
		}
		ADVWORD();
	}
	printf("%d\n", maxlength);
}