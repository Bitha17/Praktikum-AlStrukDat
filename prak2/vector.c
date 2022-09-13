/* File: vector.c */
/* NIM : 13521111 */
/* Nama: Tabitha Permalla */
/* Tanggal: 8 September 2022 */
/* Topik praktikum: ADT Sederhana */
/* Deskripsi: implementasi fungsi-fungsi primitif ADT vector */

#include <stdio.h>
#include "vector.h"
#include "point.h"
#include "math.h"

/* *** DEFINISI PROTOTIPE PRIMITIF *** */
/* *** Konstruktor membentuk VECTOR *** */
void CreateVector(VECTOR *v, float x, float y)
/* Membentuk sebuah VECTOR dengan komponen absis x dan
   komponen ordinat y */
{
   AbsisComponent(*v) = x;
   OrdinatComponent(*v) = y;
}

/* *** KELOMPOK Interaksi dengan I/O device, BACA/TULIS  *** */
void TulisVector(VECTOR v)
/* Nilai v ditulis ke layar dengan format "<X,Y>"
   tanpa spasi, enter, atau karakter lain di depan, belakang, atau di antaranya
   Output X dan Y harus dituliskan dalam bilangan riil dengan 2 angka di belakang koma.
*/
/* I.S. v terdefinisi */
/* F.S. v tertulis di layar dengan format "<X,Y>" */
{
   printf("<%.2f,%.2f>", AbsisComponent(v), OrdinatComponent(v));
}


/* *** KELOMPOK OPERASI LAIN TERHADAP TYPE *** */
float Magnitude(VECTOR v)
/* Menghasilkan magnitudo dari vector, yakni sqrt(v.x^2+v.y^2) */
{
   return(sqrtf(AbsisComponent(v)*AbsisComponent(v) + OrdinatComponent(v)*OrdinatComponent(v)));
}

VECTOR Add(VECTOR a, VECTOR b)
/* Menghasilkan sebuah vector yang merupakan hasil a + b.
   Komponen absis vector hasil adalah vector pertama
   ditambah vector kedua, begitu pula dengan ordinatnya */
{
   VECTOR v;
   AbsisComponent(v) = AbsisComponent(a) + AbsisComponent(b);
   OrdinatComponent(v) = OrdinatComponent(a) + OrdinatComponent(b);
   return v;
}

VECTOR Substract(VECTOR a, VECTOR b)
/* Menghasilkan sebuah vector yang merupakan hasil a - b.
   Komponen absis vector hasil adalah vector pertama
   dikurangi vector kedua, begitu pula dengan ordinatnya */
{
   VECTOR v;
   AbsisComponent(v) = AbsisComponent(a) - AbsisComponent(b);
   OrdinatComponent(v) = OrdinatComponent(a) - OrdinatComponent(b);
   return v;
}

float Dot(VECTOR a, VECTOR b)
/* Menghasilkan perkalian dot vector, yakni a.x * b.x + a.y * b.y */
{
   return(AbsisComponent(a)*AbsisComponent(b) + OrdinatComponent(a)*OrdinatComponent(b));
}

VECTOR Multiply(VECTOR v, float s)
/* Menghasilkan perkalian skalar vector dengan s, yakni
   (s * v.x, s * v.y) */
{
   AbsisComponent(v) *= s;
   OrdinatComponent(v) *= s;
   return v;
}
