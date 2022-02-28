/* ADT Adjacency List */

#ifndef _GRAPH_
#define _GRAPH_

#define Nil 0

typedef int infotype;
typedef struct tNode *adrNode;
typedef struct tSuccNode *adrSuccNode;
typedef struct tNode { 
	infotype Id;
	adrSuccNode Trail;
	adrNode Next;
} Node;

typedef struct tSuccNode {
	infotype Id;
	adrSuccNode Next;
} SuccNode;

typedef struct {
	adrNode First;
} Graph;

/* *** PROTOTYPE *** */

/* *** Selektor *** */
#define First(G) ((G).First)
#define Id(P) (P)->Id
#define Trail(P) (P)->Trail
#define Next(P) (P)->Next

/* *** Konstruktor *** */
void CreateGraph (Graph *G, infotype X);
/* I.S. Sembarang */
/* F.S. Terbentuk Graph dengan satu simpul dengan Id=X */

/* *** Manajemen Memory List Simpul (Leader) *** */
adrNode AlokNode (infotype X);
/* Mengembalikan address hasil alokasi Simpul X */
/* Jika alokasi berhasil, maka address tidak Nil, misalnya
menghasilkan P, maka Id(P)=X, Trail(P)=Nil, dan Next(P)=Nil. 
Jika alokasi gagal, mengembalikan Nil */

/* *** Manajemen Memory List Successor (Trailer) *** */
adrSuccNode AlokSuccNode (infotype X);
/* Mengembalikan address hasil alokasi */
/* Jika alokasi berhasil, maka address tidak Nil, misalnya
menghasilkan Pt, maka Id(Pt)=X dan Next(Pt)=Nil. Jika
alokasi gagal, mengembalikan Nil */

/* *** Fungsi/Prosedur Lain *** */
void InsertNode (Graph *G, infotype X);
/* Menambahkan simpul X ke dalam graph, jika alokasi X berhasil */
/* I.S. G terdefinisi, X terdefinisi dan belum ada pada G */
/* F.S. Jika alokasi berhasil, X menjadi elemen terakhir G, Pn berisi
address simpul X. Jika alokasi gagal, G tetap, Pn berisi Nil */

void InsertSuccNode (Graph *G, infotype X, infotype Y);
/* Menambahkan simpul Y yang ditunjuk oleh simpul X */

void PrintGraph (Graph G);
/* Melakukan pencetakan Graph */

#endif
