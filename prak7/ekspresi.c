/* File : ekspresi.c */
/* NIM : 13521111 */
/* Nama: Tabitha Permalla */
/* Tanggal: 21 Oktober 2022 */
/* Topik Praktikum: ADT Stack */

#include <stdio.h>
#include "stack.h"
#include "wordmachine.h"
#include "math.h"

boolean isOP(char c){
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

int operate(int a, int b, char c){
    if (c == '+'){
        return a + b;
    } else if ( c == '-'){
        return a - b;
    } else if (c == '*'){
        return a * b;
    } else if (c == '/'){
        return a / b;
    } else{
        return pow(a,b);
    }
}

int toInt(Word w){
    int x = 0;
    for(int i = 0; i < w.Length; i++){
        x = (x * 10) + w.TabWord[i] - 48; 
    }
    return x;
}

int main(){
    Stack S;
    int a,b;
    CreateEmpty(&S);
    STARTWORD();
    if(endWord){
        printf("Ekspresi kosong\n");
    } else{
        while (!endWord){
            if (!isOP(currentWord.TabWord[0])){
                Push(&S, toInt(currentWord));
                printf("%d\n", toInt(currentWord));
            } else{
                Pop(&S, &b);
                Pop(&S, &a);
                printf("%d %c %d\n", a, currentWord.TabWord[0], b);
                Push(&S, operate(a,b,currentWord.TabWord[0]));
                printf("%d\n", InfoTop(S));
            }
            ADVWORD();
        }
        printf("Hasil=%d\n", InfoTop(S));
    }
}