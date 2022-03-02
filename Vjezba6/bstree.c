#include <stdio.h>
#include <malloc.h>
#include "bstree.h"

BSTree NewBSTree()
{
	// Novo prazno stablo
	return NULL;
}

void AddNode(BSTree *bst, char *word)
{
	// Rekurzivno se traži mjesto za novi èvor u stablu. Ako rijeè postoji u stablu, ne dodaje se.
	// bst parametar je dvostruki pokazivaè.
    if (*bst == NULL)                       //radi novi cvor
	{
		*bst = (BSTree)malloc(sizeof(Node));
		(*bst)->word = word;
		(*bst)->left = NULL;
		(*bst)->right = NULL;
	}
	else if (strcmp((*bst)->word, word) > 0) //ako je rijec manja od trenutne,rekurzivno livo ili desno
	{
		return AddNode(&(*bst)->left, word);
	}
	else if (strcmp((*bst)->word, word) < 0)
	{
		return AddNode(&(*bst)->right, word);
	}
}

int BSTHeight(BSTree bst)
{
	// Rekurzivno se prolazi cijelo stablo da bi se pronašla najduža grana (visina stabla).
	if (bst == NULL)
		return 0;

	int livo = BSTHeight(bst->left);
	int desno = BSTHeight(bst->right);

	if (livo > desno)
		return (livo + 1);
	else
		return (desno + 1);
}

void PrintBSTree(BSTree bst)
{
	// Ispisuje rijeèi u stablu na ekran po abecednom redu.
	// In-order šetnja po stablu (lijevo dijete, èvor, desno dijete)
    if (bst == NULL)
		return;
	PrintBSTree(bst->left); //prvo livo
	printf("%s\n", bst->word); //root
	PrintBSTree(bst->right);//desno
}

void SaveBSTree(BSTree bst, FILE *fd)
{
	// Snima rijeè po rijeè iz stabla u tekstualnu datoteku. Rijeèi su odvojene razmakom.
	// Pre-order šetnja po stablu (ttenutni èvor pa djeca)
	if (bst == NULL)
		return;
	fprintf(fd, "%s ", bst->word); //rijec
	SaveBSTree(bst->left, fd);	   //liva strana
	SaveBSTree(bst->right, fd);	   //desna strana
}

void DeleteBSTree(BSTree bst)
{
	// Briše stablo (string word i sam èvor) iz memorije.
	// Post-order šetnja po stablu (prvo djeca pa trenutni èvor)
	if (bst == NULL)
		return;
	DeleteBSTree(bst->left);
	DeleteBSTree(bst->right);
	printf("Brisanje cvora - %s\n", bst->word);

	free(bst->word);
	free(bst);
}

BSTree LoadBSTree(FILE *fd)
{
	// Uèitava rijeè po rijeè iz tekstualne datoteke i dodaje ih u stablo preko AddNode() funkcije.
	// Rijeè duplicirati sa strdup().
	BSTree bst = NewBSTree();
	char buffer[1024];
	while (readWord(fd, buffer))
	{
		AddNode(&bst, strdup(buffer));
	}
	return bst;
}
