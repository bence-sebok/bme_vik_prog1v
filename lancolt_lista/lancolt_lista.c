#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
=======
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Typedef egy szak tárolására.
typedef enum { VILLANY, INFO } szak;

// Hallgató struktúra.
typedef struct hallgato
{
	char neptun[7]; // NEPTUN kód: 6 karakter + lezáró nulla = 7 karakter.
	int szuletesiEv; // Érvényes tartomány: 1980...2017.
	szak kepzes; // Egy adott hallgató villanyos vagy infós.
} hallgato;

// Láncolt lista listaelem struktúra.
typedef struct listaelem
{
	hallgato h; // A listában tárolt hallgató.
	struct listaelem * kov; // A listában következő listaelemre mutató segédpointer.
} listaelem;

// Egy hallgató minden adatának kiírása.
void kiir_hallgato(hallgato h)
{
	printf("HALLGATO: %s %d ", h.neptun, h.szuletesiEv);
	// Esetszétválasztás a szak alapján.
	if (h.kepzes == VILLANY)
	{
		printf("villany");
	}
	else if (h.kepzes == INFO)
	{
		printf("info");
	}
	else
	{
		printf("ERVENYTELEN_SZAK"); // Ha esetleg hibás érték kerülne a szak változóba.
	}
	printf("\n");
}

// Egy listaelem kiírása = listaelemben tárolt hallgató adatainak kiírása.
void kiir_listaelem(listaelem * l)
{
	kiir_hallgato(l->h);
}

// Teljes lista kiírása.
void kiir_lista(listaelem * lista_feje)
{
	listaelem * seged;
	// Egyesével minden egyes hallgató kiírása a lista elejétől a végéig.
	for (seged = lista_feje; seged != NULL; seged = seged->kov)
	{
		kiir_listaelem(seged);
	}
}

// Beszúr egy új hallgatót a meglévő láncolt listába.
// Az új hallgatót a lista elejére fűzi be.
// Mivel a lista elejére fűzünk be, így változik a lista feje, mert már az újonnan beszúrt hallgatóra kell mutasson.
// Az új fejet ezért visszaadjuk a return-nel, az új fej: a most beszúrt hallgató címe.
listaelem * uj_listaelem(listaelem * lista_feje, hallgato uj_hallgato)
{
	// Foglalunk megfelelő méretű - sizeof(listaelem) - helyet a memóriában egy új hallgatónak.
	listaelem * uj = (listaelem*)malloc(sizeof(listaelem));
	// Ha uj != NULL, akkor sikerült foglalni memóriát a hallgatónak.
	// Csak akkor menthetjük el a hallgatót, ha sikerült neki memóriát foglalni.
	if (uj != NULL)
	{
		// Ha sikerült memóriát foglalni, akkor elmentjük a listaelembe az adatokat:
		strcpy(uj->h.neptun, uj_hallgato.neptun); // Sztring másolása strcpy-vel!!!
		uj->h.szuletesiEv = uj_hallgato.szuletesiEv;
		uj->h.kepzes = uj_hallgato.kepzes;
		uj->kov = lista_feje; // Lista eddigi elejére mutat az új elem kov pointere.

		lista_feje = uj; // Lista eleje mostantól legyen az új elem címe = lista elejére fűzünk.
	}

	// Mivel változik a lista elejére mutató pointer, vissza kell térnünk az új címmel, ami a lista új eleje.
	return lista_feje;
}

// Láncolt lista építése szöveges (txt) fájl tartalmából.
// Bemeneti paraméter: fájl neve (például ez_egy_fajl.txt).
// Kimenet: az elkészült láncolt lista.
listaelem * fajl_beolvasas(char * fajlnev)
{
	// Változók deklarációja.
	hallgato uj_hallgato; // Ebbe az ideiglenes változóba olvasunk be.
	listaelem * lista_feje = NULL; // Létrehozandó lista eleje.
	FILE * fajl;

	// A fajlnev sztring a fájlunk neve, és read text file módban nyitjuk meg a fájlt.
	fajl = fopen(fajlnev, "rt");
	
	// Ha nem sikerült megnyitni a fájlt ...
	if (fajl == NULL)
	{
		// akkor értesítjük erről a felhasználót.
		printf("Nem tudom megnyitni a fajlt: %s\n", fajlnev);
		return NULL; // Ha nincs miből listát építeni, akkor üres listát adjunk vissza.
	}

	// Addig olvasunk be, amíg a lenti formátumban be tudunk olvasni 3 adatot soronként.
	// Formátum: "%s %d %d\n" = minden sorban NEPTUN SZÜL.ÉV SZAK
	// fscanf visszatérési értéke a beolvasott adatok száma: mivel neptun, év és szak adatokat olvasunk be, ezért ez itt 3.
	while (fscanf(fajl, "%s %d %d\n", &uj_hallgato.neptun, &uj_hallgato.szuletesiEv, &uj_hallgato.kepzes) == 3)
	{
		// Ha sikerült a beolvasás = while feltétele teljesült ...
		lista_feje = uj_listaelem(lista_feje, uj_hallgato); // akkor szúrjuk be a listába az új hallgatót.
	}

	// Ha nem sikerült bezárni a fájlt (például USB-n és a program futása közben kihúzták) ...
	if (fclose(fajl) != 0)
	{
		// akkor értesítjük erről a felhasználót.
		printf("Nem tudom bezarni a fajlt: %s\n", fajlnev);
	}

	// Adjuk vissza az elkészült lista elejét.
	return lista_feje;
}

// Teljes lista felszabadítása.
void torol_lista(listaelem * lista_feje)
{
	// Változók deklarációja.
	listaelem * seged = lista_feje; // Segéd pointer a lista bejárására.
	listaelem * torlo_pointer; // Minden egyes listaelemet törölni fogunk ezzel a pointerrel.
	while (seged != NULL) // Addig törlünk, amíg még van listaelem.
	{
		torlo_pointer = seged; // Ezt fogjuk törölni.
		seged = seged->kov; // Lépjünk tovább a listában.
		free(torlo_pointer); // Törlés.
	}
}

// Egy bemeneti paraméterként kapott hallgató villamosmérnök hallgató-e.
// Bemenet: láncolt lista eleme, akinek a szakját vizsgáljuk.
// Kiemenet 1, ha villamosmérnök hallgató, 0 minden más esetben.
int villanyos_e(listaelem * hallgato)
{
	if (hallgato->h.kepzes == VILLANY)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

// Megszámolja a listában szereplő villamosmérnök hallgatókat.
// Bemenet: hallgatókat tároló lista.
// Kimenet: villamosmérnök hallgatók darabszáma.
int villanyosok_szama(listaelem * lista_feje)
{
	int darab = 0; // Kezdetben nincs egy darab villamosmérnök hallgató sem.
	listaelem * seged; // Be akarjuk járni a listát.

	for (seged = lista_feje; seged != NULL; seged = seged->kov)
	{
		// Ha találunk egy villamosmérnök hallgatót ...
		if (villanyos_e(seged) == 1)
		{
			darab = darab + 1; // akkor növeljük a számlálót.
		}
	}

	return darab;
}

// Legidősebb hallgató megkeresése.
// Bemenet: hallgatókat tároló láncolt lista.
// Kimenet: legidősebb hallgatóra mutató pointer.
listaelem * legidosebb_hallgato(listaelem * lista_feje)
{
	listaelem * seged; // Lista bejárásához.
	listaelem * legidosebb = lista_feje; // Kezdetben a lista elején lévő hallgató a legidősebb.
	int evszam;

	// Legidősebb hallgató = legkorábbi születési év (minimum keresés)
	evszam = lista_feje->h.szuletesiEv;
	for (seged = lista_feje; seged != NULL; seged = seged->kov)
	{
		// Ha találunk egy idősebb hallgatót ...
		if (seged->h.szuletesiEv < evszam)
		{
			evszam = seged->h.szuletesiEv; // akkor elmentjük az évszámát és ...
			legidosebb = seged; // rámutatunk a segédpointerrel.
		}
	}

	// VIGYÁZAT: ha üres listát kap a függvény, akkor NULL pointerrel tér vissza, vagyis a visszatérési értéket ellenőrizni kell NULL pointerre.
	return legidosebb;
}

int main()
{
	// Változók deklarációja.
	listaelem * lista_hallgatok = NULL;
	int villanyos_hallgatok;
	listaelem * legidosebb = NULL;

	// Lista felépítése.
	lista_hallgatok = fajl_beolvasas("lancolt_lista_bemenet.txt");

	// Teljes lista kiírása.
	printf("Teljes lancolt lista kiirasa:\n");
	kiir_lista(lista_hallgatok);

	// Villamosmérnök hallgatók számának meghatározása, majd kiírása.
	villanyos_hallgatok = villanyosok_szama(lista_hallgatok);
	printf("\nVillamosmernok hallgatok szama: %d\n", villanyos_hallgatok);

	// Legidősebb hallgató megkeresése.
	legidosebb = legidosebb_hallgato(lista_hallgatok);
	// Ha üres listát adunk át, akkor nincs legidősebb hallgató, ezért vigyázni kell a NULL pointerrel.
	if (legidosebb != NULL)
	{
		printf("\nLegidosebb hallgato adatai:\n");
		kiir_listaelem(legidosebb);
	}

	// Teljes lista felszabadítása.
	torol_lista(lista_hallgatok);
	return 0;
}
