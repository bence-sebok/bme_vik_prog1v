#include <stdio.h>

// függvény: egy tömb minimum és maximum értékét adja vissza
// minimumot visszatérési értékként adja vissza (return-nel)
// maximumot paraméterlistán adja vissza (egy bemeneti paraméterként - int * maxertek - kapott memóriaxímre teszi)
int minmax(int tomb[], int meret, int * maxertek)
{
	// kezdeti értékek:
	int min = tomb[0];
	int max = tomb[0];
	
	// tömb bejárása
	int i;
	for(i = 0; i  < meret; i++)
	{
		// minimum keresése
		if(tomb[i] < min)
		{
			min = tomb[i];
		}
		// maximum keresése
		if(tomb[i] > max)
		{
			max = tomb[i];
		}
	}
	// for ciklus végére ért, megvan a min és max értéke
	
	// max visszaadása paraméterlistán: a maxertek memóriacímére mentjük
	*maxertek = max; // maxertek által mutatott adat legyen egyenlő max-szal (pointer dereferencia)
	
	// min visszaadása return-nel
	return min;
}

int main(void)
{
	int szam = 3; // egész számot tároló változó, értéke: 3
	int * mutato = NULL; // egész számot tároló változóra mutató mutató, értéke: NULL
	
	// későbbi függvényhíváshoz: 
	int minimum, maximum;
	int tomb[5] = {-9, -10, 0, 9 , 5};
	
	// int * mutato röviden: int típusú változó címe
	// változó deklarációnál (létrehozáskor) a csillag a tárolandó típus és a változó neve között van: TÍPUS * NÉV
	
	mutato = &szam; // mutató mutasson a szam nevű változóra (címére)
	// önmagában az &szam kifejezés egy memóriacím, a szam nevű változó címe a memóriában, vagyis a mutato egy memóriacímet kap értékül
	
	// &: címképző operátor, ez lekéri (=képzi) egy változó (struktúra stb) címét
	
	printf("%d\n", szam); // kiírjuk a szam változó értékét
	printf("%d\n", *mutato); // pointer dereferencia, vagyis felhasználunk egy memóriacímen lévő adatot (pointer által mutatott)
	// ez szintén a szam változó értékét írja ki, mert a mutato pointer a szam változóra (címére) mutato
	
	// mutató által mutatott memórián lévő adat elérése: *MUTATÓ
	
	// paraméterlistán kapunk egy adatot
	minimum = minmax(tomb, 5, &maximum);
	// a minimum változó a függvény visszatérési értékét kapja értékül
	// a maximum változó címét (címképző operátor!) átadjuk a függvénynek, így a függvény erre a címre teszi a tömb maximumát
	
	// a fentivel egyenértékű:
	// mutato = &maximum;
	// minimum = minmax(tomb, 5, mutato);
	// itt egy pointert állítunk a maximum változó címére és a pointert adjuk át a függvénynek
	// mivel a pointerek memóriacímeket tárolnak, így ugyanazt az eredményt kapjuk, mint a fenti függvényhívás során
	
	// memróriacímek kiírása:
	mutato = &szam;
	printf("szam valtozo cime: %p\n", &szam); // szám változó memóriacímét írjuk ki
	printf("mutato pointer erteke: %p\n", mutato); // mutato pointer értékét írjuk ki, ami szintén a szam változó címe
	printf("mutato pointer cime: %p\n", &mutato); // mutato pointer memóriacíme, ezen a címen tárolja a program a szam változó memóriacímét
	return 0;
}