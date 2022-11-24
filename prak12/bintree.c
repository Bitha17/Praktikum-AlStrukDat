/* File : bintree.c */
/* NIM : 13521111 */
/* Nama: Tabitha Permalla */
/* Tanggal: 24 November 2022 */
/* Topik Praktikum: ADT pohon biner */

#include "bintree.h"
#include <stdio.h>
#include <stdlib.h>

BinTree NewTree (ElType root, BinTree left_tree, BinTree right_tree){ 
/* Menghasilkan sebuah pohon biner dari root, left_tree, dan right_tree, jika alokasi berhasil 
   Menghasilkan pohon kosong (NULL) jika alokasi gagal */
   Address p = newTreeNode(root);
   if (p != NULL){
      LEFT(p) = left_tree;
      RIGHT(p) = right_tree;
   }
   return p;
}

void CreateTree (ElType root, BinTree left_tree, BinTree right_tree, BinTree *p){
/* I.S. Sembarang
   F.S. Menghasilkan sebuah pohon p
   Menghasilkan sebuah pohon biner p dari akar, l, dan r, jika alokasi 
   berhasil 
   Menghasilkan pohon p yang kosong (NULL) jika alokasi gagal */
   *p = newTreeNode(root);
   if (*p != NULL){
      LEFT(*p) = left_tree;
      RIGHT(*p) = right_tree;
   }
}

Address newTreeNode(ElType val){
/* Alokasi sebuah address p, bernilai tidak NULL jika berhasil */
/* Mengirimkan address hasil alokasi sebuah elemen bernilai val
   Jika alokasi berhasil, maka address tidak NULL, dan misalnya 
   menghasilkan p, maka p↑.info=val, p↑.left=NULL, p↑.right=NULL 
   Jika alokasi gagal, mengirimkan NULL */
   Address p = (Address) malloc(sizeof(TreeNode));
    if (p != NULL){
        ROOT(p) = val;
        LEFT(p) = NULL;
        RIGHT(p) = NULL;
    }
    return p;
}

void deallocTreeNode (Address p){
/* I.S. p terdefinisi 
   F.S. p dikembalikan ke sistem 
   Melakukan dealokasi/pengembalian address p */
   free(p);
}

boolean isTreeEmpty (BinTree p){
/* Mengirimkan true jika p adalah pohon biner yang kosong */
   return p == NULL;
}

boolean isOneElmt (BinTree p){
/* Mengirimkan true jika p tidak kosong dan hanya terdiri atas 1 elemen */
   return (!isTreeEmpty(p) && isTreeEmpty(LEFT(p)) && isTreeEmpty(RIGHT(p)));
}

boolean isUnerLeft (BinTree p){
/* Mengirimkan true jika pohon biner tidak kosong, p adalah pohon unerleft: 
   hanya mempunyai subpohon kiri */
   return (!isTreeEmpty(p) && !isTreeEmpty(LEFT(p)) && isTreeEmpty(RIGHT(p)));
}

boolean isUnerRight (BinTree p){
/* Mengirimkan true jika pohon biner tidak kosong, p adalah pohon unerright: 
   hanya mempunyai subpohon kanan */
   return (!isTreeEmpty(p) && isTreeEmpty(LEFT(p)) && !isTreeEmpty(RIGHT(p)));
}

boolean isBinary (BinTree p){
/* Mengirimkan true jika pohon biner tidak kosong, p adalah pohon biner: 
  mempunyai subpohon kiri dan subpohon kanan */
   return (!isTreeEmpty(p) && !isTreeEmpty(LEFT(p)) && !isTreeEmpty(RIGHT(p)));
}
/* ****** Display Tree ***** */
void printPreorder(BinTree p){
/* I.S. p terdefinisi */
/* F.S. Semua simpul p sudah dicetak secara preorder: akar, pohon kiri, dan pohon kanan. 
   Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup (). 
   Pohon kosong ditandai dengan ().
   Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
/* Contoh: 
   (A()()) adalah pohon dengan 1 elemen dengan akar A
   (A(B()())(C()())) adalah pohon dengan akar A dan subpohon kiri (B()()) dan subpohon kanan (C()()) */
   if(isTreeEmpty(p)){
      printf("()");
   } else{
      printf("(%d", ROOT(p));
      printPreorder(LEFT(p));
      printPreorder(RIGHT(p));
      printf(")");
   }
}

void printInorder(BinTree p){
/* I.S. p terdefinisi */
/* F.S. Semua simpul p sudah dicetak secara inorder: pohon kiri, akar, dan pohon kanan. 
   Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup (). 
   Pohon kosong ditandai dengan ().
   Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
/* Contoh: 
   (()A()) adalah pohon dengan 1 elemen dengan akar A
   ((()B())A(()C())) adalah pohon dengan akar A dan subpohon kiri (()B()) dan subpohon kanan (()C()) */
   if(isTreeEmpty(p)){
      printf("()");
   } else{
      printf("(");
      printInorder(LEFT(p));
      printf("%d", ROOT(p));
      printInorder(RIGHT(p));
      printf(")");
   }
}

void printPostorder(BinTree p){
/* I.S. p terdefinisi */
/* F.S. Semua simpul p sudah dicetak secara postorder: pohon kiri, pohon kanan, dan akar. 
   Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup (). 
   Pohon kosong ditandai dengan ().
   Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
/* Contoh: 
   (()()A) adalah pohon dengan 1 elemen dengan akar A
   ((()()B)(()()C)A) adalah pohon dengan akar A dan subpohon kiri (()()B) dan subpohon kanan (()()C) */
   if(isTreeEmpty(p)){
      printf("()");
   } else{
      printf("(");
      printPostorder(LEFT(p));
      printPostorder(RIGHT(p));
      printf("%d)",ROOT(p));
   }
}

void printTree1(BinTree p, int h, int count){
   if (!isTreeEmpty(p)){
      for (int i = 0; i < h*count; i++){
         printf(" ");
      }
      printf("%d\n", ROOT(p));
      printTree1(LEFT(p), h, count+1);
      printTree1(RIGHT(p), h, count+1);
   }
}

void printTree(BinTree p, int h){
/* I.S. p terdefinisi, h adalah jarak indentasi (spasi) */
/* F.S. Semua simpul p sudah ditulis dengan indentasi (spasi) */
/* Penulisan akar selalu pada baris baru (diakhiri newline) */
/* Contoh, jika h = 2: 
1) Pohon preorder: (A()()) akan ditulis sbb:
A
2) Pohon preorder: (A(B()())(C()())) akan ditulis sbb:
A
  B
  C
3) Pohon preorder: (A(B(D()())())(C()(E()()))) akan ditulis sbb:
A
  B
    D
  C
    E
Note: Anda boleh membuat fungsi tambahan untuk membuat implementasi fungsi ini jika diperlukan
*/
   printTree1(p, h, 0);
}

int rob1(BinTree root){
   if (isOneElmt(root)){
      return ROOT(root);
   } else if (!isTreeEmpty(root)){
      if (rob1(LEFT(root)) > rob1(RIGHT(root))){
         return ROOT(root) + rob1(LEFT(root));
      } else{
         return ROOT(root) + rob1(RIGHT(root));
      }
   }
}

int rob2(BinTree root){
   if (isTreeEmpty(root)){
      return 0;
   } else if (isOneElmt(root)){
      return ROOT(root);
   } else if (!isTreeEmpty(root)){
      int n1, n2;
      if (isUnerLeft(root)){
         n1 = ROOT(root) + rob2(LEFT(LEFT(root))) + rob2(RIGHT(LEFT(root)));
         n2 = rob2(LEFT(root));
      } else if (isUnerRight(root)){
         n1 = ROOT(root) + rob2(LEFT(RIGHT(root))) + rob2(RIGHT(RIGHT(root)));
         n2 = rob2(RIGHT(root));
      } else{
         n1 = ROOT(root) + rob2(LEFT(LEFT(root))) + rob2(RIGHT(LEFT(root))) + rob2(LEFT(RIGHT(root))) + rob2(RIGHT(RIGHT(root)));
         n2 = rob2(LEFT(root)) + rob2(RIGHT(root));
      }
      if (n1 > n2){
         return n1;
      } else{
         return n2;
      }
   }
}