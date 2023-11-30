// Auta.cpp : Defines the entry point for the application.
//

#include "Auta.h"

#include <stdio.h>
#include <ctype.h>              // tolower
#include <stdlib.h>				// system

#include "AutaDB.h"

struct t_auto* prvni = NULL; // globalni ukazatel na prvni auto

void OnAdd()
{
	char my_name[ZNACKA_SIZE];
	int my_year;
	char my_album[ALBUMSIZE];

	printf("\nKapela : ");         // dotazeme se na polozky
	scanf_s("%s", my_name, ZNACKA_SIZE);
	while (getchar() != '\n');
	printf("\nRok vzniku : ");
	scanf_s("%d", &my_year);
	while (getchar() != '\n');
	printf("\nalbum : ");
	scanf_s("%s", &my_album, ALBUMSIZE);
	while (getchar() != '\n');
	add(my_name, my_year, my_album, & prvni);         // volame pridavaci funkci
}

void OnDel()
{
	int my_year;

	printf("\nRok : ");
	scanf_s("%d", &my_year);
	while (getchar() != '\n');
	del(my_year, &prvni);         // volame mazaci funkci
}

void ShowCars()
{
	struct t_auto* aktAuto = prvni; // ukazatel na aktualni auto
	printf("\n\n");
	while (aktAuto) // prochazeni seznamu
	{
		printf("%s: %d: %s\n", aktAuto->znacka, aktAuto->rok,aktAuto->album); // tisk radku
		aktAuto = aktAuto->dalsi; // posun na dalsi auto
	}
	getchar();
}


int main()
{
	char  cmd;

	do
	{
		system("cls");		// smaze obrazovku
		printf("A: Pridat     ");
		printf("D: Smazat     ");
		printf("P: Tisk     ");
		printf("Q: Konec\n\n");

		cmd = tolower(getchar());
		while (getchar() != '\n');

		switch (cmd)
		{
		case 'a':
			OnAdd();					// volame pridani
			break;
		case 'd':
			OnDel();					// volame mazani
			break;
		case 'p':
			ShowCars();
			break;
		}
	} while (cmd != 'q');     // koncime az pri Q
	return 0;
}


