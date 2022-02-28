# include "Graph.h"
# include <stdio.h>
# include <stdlib.h>

void CreateGraph(Graph *G, infotype X)
{
	First(*G) = AlokNode(X);
}

adrNode AlokNode (infotype X)
{
	adrNode P;
    P = (adrNode) malloc (sizeof(Node));
    
    if (P!=Nil){
    	Id(P)=X;
		Trail(P)=Nil;
		Next(P)=Nil;
    	return P;
    } 
	else{
    	return Nil;
    }
}

adrSuccNode AlokSuccNode (infotype X)
{
	adrSuccNode P;
    P = (adrSuccNode) malloc (sizeof(SuccNode));
    
    if (P!=Nil){
    	Id(P)=X;
		Next(P)=Nil;
    	return P;
    } 
	else{
    	return Nil;
    }
}

void InsertNode (Graph *G, infotype X)
{
	adrNode P = AlokNode(X);
	if(P != Nil){
		if(First(*G) == Nil){
			First(*G) = P;			
		}
		else{
			adrNode Pcek = First(*G);
			while(Next(Pcek) != Nil){
				Pcek = Next(Pcek);
			}
			Next(Pcek) = P;
		}
	}
}

void InsertSuccNode (Graph *G, infotype X, infotype Y)
{
	adrSuccNode P = AlokSuccNode(Y);
	if(P != Nil){
		adrNode Pcek = First(*G);
		while(Id(Pcek) != X){
			Pcek = Next(Pcek);
		}
		
		if(Trail(Pcek) == Nil){
			Trail(Pcek) = P;
		}
		else{
			adrSuccNode PScek = Trail(Pcek);
			while(Next(PScek) != Nil){
				PScek = Next(PScek);
			}
			Next(Trail(Pcek)) = P;
		}
	}
}

void PrintGraph (Graph G)
{
	adrNode P = First(G);
	while (P != Nil){
		printf("%d -> ", Id(P));
		adrSuccNode nunjuk = Trail(P);
		while(nunjuk != Nil){
			printf("%d ", Id(nunjuk));
			nunjuk = Next(nunjuk);
		}
		printf("\n");
		P = Next(P);
	}
}
