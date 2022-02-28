#include "ArrayDinamis.h"
#include "order.h"
#include "bacafile.h"
#include "mesinkata.h"

void status(int uang, Queue Q, pembacaan *B) {
    char lokasi;
    printf("Uang tersisa: $%d\n", uang);
    printf("Build yang sedang dikerjakan: pesanan %d untuk pelanggan %s.\n", NoOrder(Q), NPemesan(Q));
    printf("Lokasi: pemain sedang berada pada %s.\n", lokasi);
    int i = 0;
    while (i < getbanyakBangunan(*B)) {
        if ((B->P[i].X == B->posisi.X) && (B->P[i].Y == B->posisi.Y)) {
            i = getbanyakBangunan(*B);
        }
    }
    char bangunan = KenaliBangunan(i);
    if (bangunan == 'B') {
        lokasi = "base";
    }
    else if (bangunan == 'S') {
        lokasi = "shop";
    }
    else {
        lokasi = "pelanggan";
    }
    printf("Inventory anda:\n");
    List L = MakeList();
    int j = 1;
    while (!IsEmpty(L)) {
        InsertAt(&L, Component(L, j), j);
        printf("%d. %s (%d)\n", j, Item(L, j), Count(L, j));
    }
}
