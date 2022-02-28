/* File: command.h */
#ifndef COMMAND_H
#define COMMAND_H

#include "boolean.h"
#include "string.h"
#include "komponen.h"
#include "player.h"
#include "order.h"

void MOVE();
/* Melakukan perpindahan ke lokasi lain */

void STATUS();
/* Menampilkan status pemain berupa jumlah uang, build yang sedang dikerjakan, */
/* lokasi terkini dari pemain dan inventory pemain */

void CHECKORDER();
/* Melihat informasi dari order yang sedang dikerjakan */

void STARTBUILD();
/* Memulai sebuah build */

void FINISHBUILD();
/* Menyelesaikan sebuah build */
/* Setelah suatu build diselesaikan, order akan dianggap selesai */
/* Selanjutnya, pemain akan mendapatkan order baru */

void ADDCOMPONENT(Stack *S, List *L, boolean StartBuild);
/* Memasang komponen pada komputer rakitan player */

void REMOVECOMPONENT(Stack *S, List *L, boolean StartBuild);
/* Mencopot komponen pada komputer rakitan player */

void SHOP();
/* Membeli komponen pada saat berada di SHOP */

void DELIVER();
/* Mengantarkan pesanan komputer yang sudah selesai dirakit sesuai spesifikasi */
/* Deliver hanya dapat dilaksanakan ketika player berada pada lokasi customer */

void END_DAY(Queue *Q, ArrNama N, ArrKomponen K);
/* Mengakhiri hari yang berjalan dan menuju keesokan hari */

void MAP();
/* Menampilkan peta dan posisi pemain */

void EXIT();
/* Mengakhiri permainan dan mengakhiri program */

#endif