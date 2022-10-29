#include "listlinier.c"
#include <stdio.h>

int main(){
    List l;
    CreateList(&l);
    insertFirst(&l, 1);
    insertFirst(&l,2);
    insertLast(&l,3);
    insertAt(&l,2,2);
    displayList(l);
    inverseList(&l);
    displayList(l);
}