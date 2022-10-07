/* File : antrianSix.h */
/* NIM : 13521111 */
/* Nama: Tabitha Permalla */
/* Tanggal: 6 Oktober 2022 */
/* ADT Queue */

#include <stdio.h>
#include "queue.h"

int main(){
	int choice, t, min, max, temp, count;
	float sum;
	min = 9999;
	max = -1;
	count = 0;
	sum = 0;
	Queue q;
	CreateQueue(&q);
	scanf("%d", &choice);
	while (choice != 0){
		if (choice == 1){
			scanf("%d", &t);
			if(!isFull(q)){
				enqueue(&q, t);
			}
			else{
				printf("Queue penuh\n");
			}
		}
		else if (choice == 2){
			if (!isEmpty(q)){
				dequeue(&q,&temp);
				if (temp < min){
					min = temp;
				}
				if (temp > max){
					max = temp;
				}
				count++;
				sum += temp;
			}
			else{
				printf("Queue kosong\n");
			}
		}
		scanf("%d", &choice);
	}
	printf("%d\n", count);
	if (count == 0){
		printf("Tidak bisa dihitung\n");
		printf("Tidak bisa dihitung\n");
		printf("Tidak bisa dihitung\n");
	}
	else{
		printf("%d\n", min);
		printf("%d\n", max);
		printf("%.2f\n", sum/count);
	}
}