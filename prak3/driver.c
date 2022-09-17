
#include "liststatik.h"
#include "boolean.h"
#include <stdio.h>

int main(){
    ListStatik l,l1;
    CreateListStatik(&l); 
    CreateListStatik(&l1);
    readList(&l);
    readList(&l1);
/* int listLength(ListStatik l);
IdxType getFirstIdx(ListStatik l);
IdxType getLastIdx(ListStatik l);
boolean isIdxValid(ListStatik l, IdxType i);
boolean isIdxEff(ListStatik l, IdxType i);
boolean isEmpty(ListStatik l);
boolean isFull(ListStatik l);
void readList(ListStatik *l);
void printList(ListStatik l);
ListStatik plusMinusList(ListStatik l1, ListStatik l2, boolean plus); */
    printf("%d\n", isListEqual(l,l1));
/* int indexOf(ListStatik l, ElType val);
void extremeValues(ListStatik l, ElType *max, ElType *min);
void insertFirst(ListStatik *l, ElType val);
void insertAt(ListStatik *l, ElType val, IdxType idx);
void insertLast(ListStatik *l, ElType val);
void deleteFirst(ListStatik *l, ElType *val);
void deleteAt(ListStatik *l, ElType *val, IdxType idx);
void deleteLast(ListStatik *l, ElType *val);
sortList(ListStatik *l, boolean asc); */
}