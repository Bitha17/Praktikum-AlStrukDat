/* File: str2num.c */
/* NIM : 13521111 */
/* Nama: Tabitha Permalla */
/* Tanggal: 29 September 2022 */
/* Topik praktikum: ADT Mesin Kata */

#include <stdio.h>
#include "wordmachine.h"
#include "boolean.h"
#include <string.h>

boolean same(Word w, char *s){
	if (strlen(s) == w.Length){
		for (int j = 0; j < w.Length; j++){
			if (w.TabWord[j] != s[j]){
				return false;
			}
		}
		return true;
	}
	return false;
}

boolean isNum(Word w, char *angka[]){
	for (int i = 0; i<16; i++){
		if (same(w, angka[i])){
			return true;
		}
	}
	return false;
}

int satuan(Word w, char *angka[]){
	for (int i = 0; i<10; i++){
		if (same(w,angka[i])){
			return (i+1);
		}
	}
}

int main(){
	char *angka[] = {"satu", "dua", "tiga", "empat", "lima", "enam", "tujuh", "delapan", "sembilan", "sepuluh", "sebelas", "belas", "puluh", "seratus", "ratus", "nol"};
	int num;
	endWord = false;
	STARTWORD();
	while(!endWord){
		if (isNum(currentWord, angka)){
			num = 0;
			while(isNum(currentWord, angka)){
				if (same(currentWord, "nol")){
					ADVWORD();
					if (endWord) break;
				}
				else if (same(currentWord, "seratus")){
					num += 100;
					ADVWORD();
					if (endWord) break;
				}
				else if(same(currentWord, "sepuluh")){
					num += 10; 
					ADVWORD();
					if (endWord) break;
				}
				else if(same(currentWord,"sebelas")){
					num += 11;
					ADVWORD();
					if (endWord) break;
				}
				else{
					int temp = satuan(currentWord,angka);
					ADVWORD();
					if (endWord) {
						num += temp;
						break;
					}
					else if (same(currentWord,"ratus")){
						num += temp*100;
						ADVWORD();
						if (endWord) break;
					}
					else if (same(currentWord,"puluh")){
						num += temp*10;
					 	ADVWORD();
						if (endWord) break;
					}
					else if (same(currentWord,"belas")){
					 	num += temp + 10;
					 	ADVWORD();
						if (endWord) break;
					}
					else{
					 	num += temp;
					}
				}
			}	
			if (!endWord){
				printf("%d ", num);
			}
			else{
				printf("%d", num);
			}
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