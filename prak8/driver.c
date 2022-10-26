#include "listlinier.h"
#include <stdio.h>

int main(){
    List l;
    CreateList(&l);
    insertFirst(&l, 1);
    insertFirst(&l,2);
    insertLast(&l,3);
    insertAt(&l,2,2);
    displayList(l);
    int a;
    deleteLast(&l,&a);
    deleteAt(&l,1,&a);
    displayList(l);
    printf("%d\n", a);
}