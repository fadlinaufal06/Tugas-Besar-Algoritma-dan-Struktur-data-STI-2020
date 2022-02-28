
void FINISHBUILD(Stack *S, Queue *Q){
/* Menyelesaikan sebuah build */
/* Setelah suatu build diselesaikan, order akan dianggap selesai */
/* Selanjutnya, pemain akan mendapatkan order baru */

	Stack A,B;
	s_infotype xA, xB;
	CopyStack(*S,&A);
	/* S itu stack daftar komponen yang sudah terpasang, jadi stack ini udah dideclare di program utama */
	/* Informasi dari stack S dicopy ke stack dummy A */
	
	CopyStack(LKomponen(*Q),&B);
	/* Lkomponen(*Q) itu selektor yang sudah dibuat, jadi bisa langsung akses stack yang isinya daftar */
	/* komponen yang diinginkan oleh pelanggan. Jadi dicopy dulu ke stack dummy B */
	
	/* Proses pengecekan dengan looping */
	if (Top(A) != Top(B)){
	/* Jika nilai top tidak sama berarti sudah pasti tidak sesuai pesanan */
		printf("Komponen belum sesuai\n");
	}
	else{
		boolean sama = true;
		while((!(IsStackEmpty(A))) && (sama)){		
		/* Looping berjalan selama stack A yaitu daftar komponen yang sudah terpasang tidak kosong */
		/* dan Nama komponen sama dengan pesanan pelanggan */
		if (NamaKomp(A)!= NamaKomp(B)){		
			// Jika nama komponen tidak sama maka proses looping akan berhenti
			sama = false;
		}
		Pop(&A,&xA);
		Pop(&B,&xB);
		}
		if (sama) {
		printf("Pesanan %d telah selesai. Silahkan antar pelanggan %d\n", NoOrder(*Q), NPemesan(*Q));
		}
		else{
		printf("Komponen belum sesuai\n");
		}
	}
}
