#include <stdio.h>
#include <stdlib.h>

typedef enum { VILLANY, INFO } szak; // egy adott hallgató villanyos vagy infós

// A láncolt listában hallgatókat fogunk tárolni.
typedef struct hallgato
{
	char neptun[7]; // NEPTUN kód: 6 karakter + lezáró nulla = 7 karakter
	int szuletesiEv; // érvényes tartomány: 1980...2017
	szak kepzes; // egy adott hallgató villanyos vagy infós
} hallgato;

typedef struct listaelem
{
	hallgato h; // a listában tárolt hallgató
	struct listaelem * kov; // a listában következõ listaelemre mutató segédpointer
} listaelem;

// Beszúr egy új hallgatót a meglévõ láncolt listába.
// Az új hallgatót a lista elejére fûzi be.
// Mivel a lista elejére fûzünk be, így változik a lista feje, mert már az újonnan beszúrt hallgatóra kell mutasson.
// Az új fejet ezért visszaadjuk a return-nel, az új fej: a most beszúrt hallgató címe.
listaelem * uj_listaelem(listaelem * lista_feje, hallgato uj_hallgato)
{
	// Foglalunk megfelelõ méretû - sizeof(listaelem) - helyet a memóriában egy új hallgatónak.
	listaelem * uj = (listaelem*)malloc(sizeof(listaelem));
	// Ha uj != NULL, akkor sikerült foglalni memóriát a hallgatónak.
	// Csak akkor menthetjük el a hallgatót, ha sikerült neki memóriát foglalni.
	if(uj != NULL)
	{
		// uj->kov = lista_feje; // Az új elem kov pointere mutasson az eddigi elsõ elemre (ezt a lista_feje pointer tárolja)
	}
}

int main()
{
	return 0;
}