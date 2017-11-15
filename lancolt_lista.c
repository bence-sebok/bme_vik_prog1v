#include <stdio.h>
#include <stdlib.h>

typedef enum { VILLANY, INFO } szak; // egy adott hallgat� villanyos vagy inf�s

// A l�ncolt list�ban hallgat�kat fogunk t�rolni.
typedef struct hallgato
{
	char neptun[7]; // NEPTUN k�d: 6 karakter + lez�r� nulla = 7 karakter
	int szuletesiEv; // �rv�nyes tartom�ny: 1980...2017
	szak kepzes; // egy adott hallgat� villanyos vagy inf�s
} hallgato;

typedef struct listaelem
{
	hallgato h; // a list�ban t�rolt hallgat�
	struct listaelem * kov; // a list�ban k�vetkez� listaelemre mutat� seg�dpointer
} listaelem;

// Besz�r egy �j hallgat�t a megl�v� l�ncolt list�ba.
// Az �j hallgat�t a lista elej�re f�zi be.
// Mivel a lista elej�re f�z�nk be, �gy v�ltozik a lista feje, mert m�r az �jonnan besz�rt hallgat�ra kell mutasson.
// Az �j fejet ez�rt visszaadjuk a return-nel, az �j fej: a most besz�rt hallgat� c�me.
listaelem * uj_listaelem(listaelem * lista_feje, hallgato uj_hallgato)
{
	// Foglalunk megfelel� m�ret� - sizeof(listaelem) - helyet a mem�ri�ban egy �j hallgat�nak.
	listaelem * uj = (listaelem*)malloc(sizeof(listaelem));
	// Ha uj != NULL, akkor siker�lt foglalni mem�ri�t a hallgat�nak.
	// Csak akkor menthetj�k el a hallgat�t, ha siker�lt neki mem�ri�t foglalni.
	if(uj != NULL)
	{
		// uj->kov = lista_feje; // Az �j elem kov pointere mutasson az eddigi els� elemre (ezt a lista_feje pointer t�rolja)
	}
}

int main()
{
	return 0;
}