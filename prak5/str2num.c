/* File: str2num.c */
/* NIM : 13521111 */
/* Nama: Tabitha Permalla */
/* Tanggal: 29 September 2022 */
/* Topik praktikum: ADT Mesin Kata */

#include <stdio.h>
#include "wordmachine.h"
#include "boolean.h"
#include <string.h>

boolean isNum(Word w, char *angka[]){
	for (int i = 0; i<15; i++){
		if (strcmp(w.TabWord,angka[i]) == 0){
			return true;
		}
	}
	return false;
}

int main(){
	char *angka[] = {"satu", "dua", "tiga", "empat", "lima", "enam", "tujuh", "delapan", "sembilan", "sepuluh", "sebelas", "belas", "puluh", "seratus", "ratus"};
	int num;
	endWord = false;
	STARTWORD();
	while(!endWord){
		if (isNum(currentWord, angka)){
			num = 0;
			while(isNum(currentWord, angka)){
				if (strcmp(currentWord.TabWord,"seratus") == 0){
					num += 100;
					ADVWORD();
				}
				else if(strcmp(currentWord.TabWord,"sepuluh") == 0){
					num += 10; 
					ADVWORD();
				}
				else if(strcmp(currentWord.TabWord,"sebelas") == 0){
					num += 11;
					ADVWORD();
				}
				else{
					for (int i = 0; i<10; i++){
						if (strcmp(currentWord.TabWord,angka[i])==0){
							ADVWORD();
							if (strcmp(currentWord.TabWord,"ratus")==0){
								num = (i+1)*100;
								ADVWORD();
							}
							else if (strcmp(currentWord.TabWord,"puluh")==0){
								num = (i+1)*10;
								ADVWORD();
							}
							else if (strcmp(currentWord.TabWord,"belas")==0){
								num = i+11;
								ADVWORD();
							}
							else{
								num = i+1;
							}
						}
					}
				}	
			}
			printf("%d ", num);
		}
		else{
			for (int i = 0; i < currentWord.Length; i++){
				printf("%c", currentWord.TabWord[i]);
			}
			ADVWORD();
			if (!endWord){
				printf(" ");
			}
		}
	}
	printf("\n");
}