#include "command.h"
#include <stdio.h>

void MOVE(){}
/* Melakukan perpindahan ke lokasi lain */

void STATUS(){}
/* Menampilkan status pemain berupa jumlah uang, build yang sedang dikerjakan, */
/* lokasi terkini dari pemain dan inventory pemain */

void CHECKORDER(){}
/* Melihat informasi dari order yang sedang dikerjakan */

void STARTBUILD(){}
/* Memulai sebuah build */

void FINISHBUILD(Stack *S, Queue *Q){}
/* Menyelesaikan sebuah build */
/* Setelah suatu build diselesaikan, order akan dianggap selesai */
/* Selanjutnya, pemain akan mendapatkan order baru */

void ADDCOMPONENT(Stack *S, List *L, boolean StartBuild){
/* Memasang komponen pada komputer rakitan player */
    if(!StartBuild){
        printf("Mohon maaf perintah tidak dapat dilakukan,\n");
        printf("Anda belum memulai perakitan pesanan, ");
        printf("mohon gunakan perintah 'STARTBUILD' terlebih dahulu\n");
        printf("\n");
    }
    else{
        int i, j, input;
        if(IsEmpty(*L)){
            printf("Anda belum memiliki komponen apa pun,\n");
            printf("Mohon melakukan pembelian komponen dahulu!\n");
            printf("\n");
        }
        else{
            Stack A;
            CreateStackEmpty(&A);
            CopyStack(*S,&A);
            InverseStack(&A);   

            printf("Komponen yang telah terpasang:\n");
            i = 1;
            if (IsStackEmpty(A)){
                printf("Belum ada komponen yang terpasang\n");
            }
            s_infotype StackElmt;
            while (!IsStackEmpty(A)){
                printf("%d. %s\n", i, NamaKomp(A));
                Pop(&A,&StackElmt);
                i++;
            }

            printf("Komponen yang tersedia:\n");
            j = 0;
            while(j < Length(*L)){
                printf("%d. %s\n", j+1, Item(*L,j));
                j++;
            }
            
            printf("Komponen yang ingin dipasang: ");
            scanf("%d", &input);
            while((input < 1) || (input > j)){
                printf("Nomor komponen tidak sesuai, mohon input ulang: ");
                scanf("%d", &input);
            }
            
            s_infotype C;
            C.Nama_Komponen = Item(*L,input-1);
            C.Kategori = Kateg(*L,input-1);
            C.Harga = HargaK(*L,input-1);
            Push(S,C);
            HapusItem(L,Item(*L,input-1));
            printf("Komponen berhasil dipasang!\n");
            printf("\n");
        }
    }
}

void REMOVECOMPONENT(Stack *S, List *L, boolean StartBuild){
/* Mencopot komponen pada komputer rakitan player */
    if(!StartBuild){
        printf("Mohon maaf perintah tidak dapat dilakukan,\n");
        printf("Anda belum memulai perakitan pesanan, ");
        printf("mohon gunakan perintah 'STARTBUILD' terlebih dahulu\n");
        printf("\n");
    }
    else {
        if(IsStackEmpty(*S)){
            printf("Belum ada komponen yang terpasang,\n");
            printf("Silakan pasang komponen terlebih dahulu.\n");
            printf("\n");
        }
        else {
            s_infotype X;
            Pop(S,&X);
            TambahItem(L,X.Nama_Komponen,X.Kategori,X.Harga);
            printf("Komponen %s berhasil dicopot!\n", X.Nama_Komponen);
            printf("\n");
        }
    }
}

void SHOP(){}
/* Membeli komponen pada saat berada di SHOP */

void DELIVER(){}
/* Mengantarkan pesanan komputer yang sudah selesai dirakit sesuai spesifikasi */
/* Deliver hanya dapat dilaksanakan ketika player berada pada lokasi customer */

void END_DAY(Queue *Q, ArrNama N, ArrKomponen K){
/* Mengakhiri hari yang berjalan dan menuju keesokan hari */
    CreateQueueEmpty(Q);
    TambahOrderan(Q,N,K,10);
}

void MAP(){}
/* Menampilkan peta dan posisi pemain */

void EXIT(){}
/* Mengakhiri permainan dan mengakhiri program */