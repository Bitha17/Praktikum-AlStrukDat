/* File: wordmachine.c */
/* NIM : 13521111 */
/* Nama: Tabitha Permalla */
/* Tanggal: 29 September 2022 */
/* Topik praktikum: ADT Mesin Kata */
/* Definisi Word Machine: Model Akuisisi Versi I */

#include "wordmachine.h"
#include <stdio.h>

boolean endWord;
Word currentWord;

void IgnoreBlanks(){
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */
    while(currentChar == BLANK){
        ADV();
    }
}

void STARTWORD(){
/* I.S. : currentChar sembarang
   F.S. : EndWord = true, dan currentChar = MARK;
          atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */
    START();
    IgnoreBlanks();
    if (currentChar == MARK){
        endWord = true;
    }
    else{
        endWord = false;
        CopyWord();
    }
}

void ADVWORD(){
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, EndWord = true.
   Proses : Akuisisi kata menggunakan procedure SalinWord */
    IgnoreBlanks();
    if (currentChar == MARK){
        endWord = true;
    }
    else{
        CopyWord();
        IgnoreBlanks();
    }
}

void CopyWord(){
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi;
          currentChar = BLANK atau currentChar = MARK;
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
    for (int j = 0; j < currentWord.Length; j++){
        currentWord.TabWord[j] = BLANK;
    }
    int i = 0;
    while ((currentChar != BLANK) && (currentChar != MARK) && (i < NMax)){
            currentWord.TabWord[i] = currentChar;
            ADV();
            i++;
        }
    currentWord.Length = i;
}

void LowerCase(){
/* I.S. currentword terdefinisi sembarang tetapi tidak kosong */
/* F.S. currentword menjadi lowercase di setiap karakternya */
    for (int i = 0; i < currentWord.Length; i++){
      if(currentWord.TabWord[i] >= 65 && currentWord.TabWord[i] <= 90){
        currentWord.TabWord[i] += 32;
      }
    }
}