/* File: butak.c */
/* NIM : 13521111 */
/* Nama: Tabitha Permalla */
/* Tanggal: 10 November 2022 */
/* Topik Praktikum: Queue dan Stack dengan list berkait */

#include <stdio.h>
#include "charmachine.h"
#include "queuelinked.h"

int all(Queue q){
	int count0 = 0;
	int count1 = 0;
	Address p = ADDR_HEAD(q);
	while (p != NULL){
		if (INFO(p) == 0){
			count0++;
		} else{
			count1++;
		}
		 p = NEXT(p);
	}
	if (count0 == 0){
		return 0; 
	} else if (count1 == 0){
		return 1;
	} else{
		return 2;
	}
}
int main(){
	START();
	Queue q1, q2, qM;
	CreateQueue(&q1);
	CreateQueue(&q2);
	CreateQueue(&qM);
	int i = 0;
	while(currentChar != ','){
		if (currentChar == 'B'){
			enqueue(&q1, 0);
		} else{
			enqueue(&q1, 1);
		}
		i++;
		enqueue(&qM, i);
		ADV();
	}
	ADV();
	int countM = length(q1);
	while(!EOP){
		if (currentChar == 'B'){
			enqueue(&q2, 0);
		} else{
			enqueue(&q2,1);
		}
		ADV();
	}
	int temp, count;
	while(!((all(q1) == 0 && HEAD(q2) == 1) || (all(q1) == 1 && HEAD(q2) == 0))){
		if (HEAD(q1) == HEAD(q2)){
			dequeue(&q1,&temp);
			dequeue(&q2,&temp);
			dequeue(&qM,&count);
			if (temp == 0){
				printf("%d -> bulat\n", count);
			} else{
				printf("%d -> kotak\n", count);
			}
		} else{
			dequeue(&q1,&temp);
			dequeue(&qM,&count);
			enqueue(&q1,temp);
			enqueue(&qM,count);
		}
		DisplayQueue(q1);
		DisplayQueue(q2);
		printf("\n");
	}
	printf("%d\n", length(q1));
}