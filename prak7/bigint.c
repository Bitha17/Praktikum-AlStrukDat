/* File : bigint.c */
/* NIM : 13521111 */
/* Nama: Tabitha Permalla */
/* Tanggal: 21 Oktober 2022 */
/* Topik Praktikum: ADT Stack */

#include <stdio.h>
#include <string.h>
#include "stack.h"

boolean greaterThan(Stack Sa, Stack Sb){
    if (Top(Sa) > Top(Sb)){
        return true;
    } else if (Top(Sa) == Top(Sb)){
        boolean great = false;
        for (int i = Top(Sa); i >= 0; i--){
            if (Sa.T[Top(Sa) - i] > Sb.T[Top(Sb) - i]){
                great = true;
            }
        }
        return great;
    } else {
        return false;
    }
}

Stack subtract(Stack *Sa, Stack *Sb){
    Stack SR;
    CreateEmpty(&SR);
    int a, b, c;
    int minus = 0;
    while (!IsEmpty(*Sb)){
        Pop(Sa,&a);
        Pop(Sb,&b);
        c = a - b + minus;
        if (c < 0){
            minus = -1;
            c += 10;
        } else{
            minus = 0;
        }
        Push(&SR, c);
    }
    while (!IsEmpty(*Sa)){
        Pop(Sa, &a);
        c = a + minus;
        if (c < 0){
            minus = -1;
            c += 10;
        } else{
            minus = 0;
        }
        Push(&SR, c);
    }
    int temp;
    while (InfoTop(SR) == 0 && Top(SR) > 0){
        Pop(&SR,&temp);
    }
    return SR;
}

int main(){
    Stack S1, S2, SR;
    char c;

    CreateEmpty(&S1);
    CreateEmpty(&S2);
    CreateEmpty(&SR);

    scanf("%c", &c);

    while(c != '\n'){
        if (c - 48 >= 0){
            Push(&S1, c - 48);
        }
        scanf("%c", &c);
    }
    scanf("%c", &c);
    while(c != '\n'){
        if (c - 48 >= 0){
            Push(&S2, c - 48);
        }
        scanf("%c", &c);
    }
    if (greaterThan(S2,S1)){
        SR = subtract(&S2,&S1);
        int n;
        Pop(&SR, &n);
        printf("%d", (-1)*n);
        while (!IsEmpty(SR)){
            Pop(&SR, &n);
            printf("%d",n);
        }
    } else{
        SR = subtract(&S1,&S2);
        while (!IsEmpty(SR)){
            int n;
            Pop(&SR, &n);
            printf("%d",n);
        }
    }
    printf("\n");
}