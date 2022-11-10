/* File: parserkurung.c */
/* NIM : 13521111 */
/* Nama: Tabitha Permalla */
/* Tanggal: 10 November 2022 */
/* Topik Praktikum: Queue dan Stack dengan list berkait */

#include <stdio.h>
#include "stacklinked.h"
#include "charmachine.h"

int rep(char c){
	if (c == '['){
		return 0;
	} else if (c == '('){
		return 1;
	} else if (c == '{'){
		return 3;
	} else if (c == '<'){
		return 4;
	} else if (c == ']'){
		return 5;
	} else if (c == ')'){
		return 6;
	} else if (c == '}'){
		return 8;
	} else if (c == '>'){
		return 9;
	} else{
		return -1;
	}
}

int main(){
	START();
	Stack s;
	CreateStack(&s);
	int temp;
	int count[5] = {0,0,0,0,0};
	int max = 0;
	boolean valid = true;
	while (!EOP){
		if (currentChar == '|'){
			if (isEmpty(s)){
				push(&s,2);
				count[2]++;
			}else if (TOP(s) == 2){
				pop(&s,&temp);
			} else{
				push(&s,2);
				count[2]++;
			}
			DisplayStack(s);
			printf("\n");
		} else if (rep(currentChar) != -1){
			if (rep(currentChar) < 5){
				push(&s,rep(currentChar));
				count[(rep(currentChar))]++;
			} else if(isEmpty(s)){
				valid = false;
			} else if(TOP(s) == rep(currentChar) - 5){
				pop(&s,&temp);
			} else{
				valid = false;
			}
			DisplayStack(s);
			printf("\n");
		}
		if (length(s) > max){
			max = length(s);
		}
		ADV();
	}
	if (!isEmpty(s) || !valid){
		printf("kurung tidak valid\n");
	} else{
		printf("kurung valid\n");
		printf("[%d] (%d) |%d| {%d} <%d>\n", count[0], count[1], count[2], count[3], count[4]);
		printf("MAX %d\n", max);
	}
}