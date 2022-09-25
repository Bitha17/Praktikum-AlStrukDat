/* File: wordmachine.c */
/* NIM : 13521111 */
/* Nama: Tabitha Permalla */
/* Tanggal: 25 September 2022 */
/* Topik praktikum: ADT Mesin Kata */
/* Definisi Word Machine: Model Akuisisi Versi I */

#include "wordmachine.h"
#include <stdio.h>

boolean EndWord;
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
        EndWord = true;
    }
    else{
        EndWord = false;
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
        EndWord = true;
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
    currentWord.Length = 0;
    while ((currentChar != BLANK) && (currentChar != MARK) && (currentWord.Length < NMax)){
        currentWord.TabWord[currentWord.Length] = currentChar;
        ADV();
        currentWord.Length++;
    }
}