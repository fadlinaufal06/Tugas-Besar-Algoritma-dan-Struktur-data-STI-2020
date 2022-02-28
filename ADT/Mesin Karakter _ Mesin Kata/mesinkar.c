/* File = mesinkar.c
Implementasi Mesin Karakter */

#include "mesinkarakter.h"
#include <stdio.h>
#include <stdlib.h>

char CC;


static FILE *pita;
static int retval;

void START()
{
  /* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   I.S. : sembarang
   F.S. : CC adalah karakter pertama pada pita
          Jika CC != MARK maka EOP akan padam (false)
          Jika CC = MARK maka EOP akan menyala (true) */
  FILE *FILEKU;
  FILEKU = fopen("pitakarakter.txt","r" );
  retval = fscanf(FILEKU,"%c",&CC);
}

void ADV()
{
  /* Pita dimajukan satu karakter.
   I.S. : Karakter pada jendela = CC, CC != MARK
   F.S. : CC adalah karakter berikutnya dari CC yang lama,
          CC mungkin = MARK
          Jika  CC = MARK maka EOP akan menyala (true) */
  FILE *FILEKU;
  retval = fscanf(FILEKU,"%c",&CC) ;
  if (EOP){  
  }
}

boolean EOP() {
/*	true jika CC==mark */
	return (CC==mark);
}
