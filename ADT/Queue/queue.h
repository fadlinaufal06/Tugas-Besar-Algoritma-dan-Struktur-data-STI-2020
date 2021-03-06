/* File: queuelist.h */
#ifndef _QUEUELIST_H
#define _QUEUELIST_H
#include "boolean.h"
#include "stackt.h"
#include <stdlib.h>

#define Nil NULL
/* Queue dengan representasi berkait dengan pointer */
typedef struct tNode *address;
typedef struct tNode {
    int No_Order;
    char* Pemesan;
    Stack List_Komponen;
    int THarga;
    address Next;
} ElmtQueue;

/* Type queue dengan ciri HEAD dan TAIL: */
typedef struct {
    address HEAD; /* alamat penghapusan */
    address TAIL; /* alamat penambahan */
} Queue;

/* Selektor */
#define Head(Q) (Q).HEAD
#define Tail(Q) (Q).TAIL
#define NoOrder(Q) (Q).HEAD->No_Order
#define NPemesan(Q) (Q).HEAD->Pemesan
#define LKomponen(Q) (Q).HEAD->List_Komponen
#define TotalH(Q) (Q).HEAD->THarga

#define NomorOrder(P) (P)->No_Order
#define NamaPemesan(P) (P)->Pemesan
#define ListKomponen(P) (P)->List_Komponen
#define TotalHarga(P) (P)->THarga
#define Next(P) (P)->Next
#define Info(P) (P)->Info

/* Prototype manajemen memori */
void AlokasiQ(address *P, char* Nama, Stack List, int Total);
/* I.S. Sembarang */
/* F.S. Alamat P dialokasi, jika berhasil maka Info(P)=X dan Next(P)=Nil */
/* P=Nil jika alokasi gagal */

void DealokasiQ(address P);
/* I.S. P adalah hasil alokasi, P != Nil */
/* F.S. Alamat P didealokasi, dikembalikan ke sistem */

boolean IsQueueEmpty(Queue Q);
/* Mengirim true jika Q kosong: HEAD(Q)=Nil and TAIL(Q)=Nil */

int NBQueueElmt(Queue Q);
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong */
/*** Kreator ***/

void CreateQueueEmpty(Queue *Q);
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk */
/*** Primitif Enqueue/Dequeue ***/

void Enqueue(Queue *Q, char* Nama, Stack List, int Total);
/* Proses: Mengalokasi X dan menambahkan X pada bagian TAIL dari Q
jika alokasi berhasil; jika alokasi gagal Q tetap */
/* Pada dasarnya adalah proses insert last */
/* I.S. Q mungkin kosong */
/* F.S. X menjadi TAIL, TAIL "maju" */

void Dequeue(Queue *Q);
/* Proses: Menghapus X pada bagian HEAD dari Q dan mendealokasi elemen HEAD */
/* Pada dasarnya operasi delete first */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "mundur" */

#endif