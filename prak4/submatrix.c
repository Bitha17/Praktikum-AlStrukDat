/* File: matrix.c */
/* NIM : 13521111 */
/* Nama: Tabitha Permalla */
/* Tanggal: 22 September 2022 */
/* Topik praktikum: ADT Matrix */

#include <stdio.h>
#include "matrix.h"

int main(){
    int N, M;
    scanf("%d %d", &N, &M);
    Matrix m,mTemp;
    readMatrix(&m,N,N);
    int count[(N-M+1)*(N-M+1)];
    int idx = 1;
    for (int i = 0; i < N-M+1; i++){
        for (int j = 0; j < N-M+1; j++){
            int x = (N-M+1)*i+j+1;
            count[x] = 0;
            createMatrix(M,M,&mTemp);
            for (int k = 0; k < M; k++){
                for (int l = 0; l < M; l++){
                    ELMT(mTemp,k,l) = ELMT(m,i+k,j+l); 
                }
            }
            for (int k = 0; k < M; k++){
                for (int l = 0; l < M; l++){
                    if(ELMT(mTemp,k,l) != 0){
                        count[x]++;
                    } 
                }
            }
            if(count[x] > count[idx]){
                idx = x;
            }
        }
    }
    printf("%d\n", idx);
}