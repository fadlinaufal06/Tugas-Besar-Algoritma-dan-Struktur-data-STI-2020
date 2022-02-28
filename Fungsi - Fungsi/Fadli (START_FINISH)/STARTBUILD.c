#include "boolean.h"
#include "string.h"
#include "command.h"
#include "komponen.h"
#include "player.h"
#include "order.h"
#include <stdio.h>

void STARTBUILD(Stack *S, Boolean *A){
		
	// if IsPosisiBase ??? then.... belum tau gimana cek nya
	CreateStackEmpty(S);
	printf("Kamu telah memulai pesanan %d untuk pelanggan %d", NoOrder(Q), NPemesan(Q)  );
	*A = true;
}


