#include <stdio.h>
#include <math.h>

struct Konyv
{
	char nev[100 + 1];
	int oldalszam;
};

typedef struct
{
	int nem;
	int magassag;
} Tanulo;

int tancparok_e (Tanulo t1, Tanulo t2)
{
	/*
	if(t1.nem != t2.nem)
	{
		if(abs(t1.magassag - t2.magassag) < 10)
		{
			return 1; // igaz;
		}
	}
	return 0;
	*/
	if( (t1.nem != t2.nem) && (abs(t1.magassag - t2.magassag) < 10))
	{
		return 1;
	}
	return 0;
}

int tancparok(Tanulo t, Tanulo tomb[], int meret)
{
	int darab = 0;
	int i;
	for(i = 0; i < meret; i++)
	{
		if(tancparok_e(t, tomb[i]) == 1)
		{
			darab = darab + 1;
		}
	}
	return darab;
}

int feladat4d(Tanulo tomb[], int meret)
{
	int i;
	int maxMagassag = tomb[0].magassag;
	int maxIndex = 0;
	int darab = 0;
	for(i = 0; i < meret; i++)
	{
		if(tomb[i].magassag > maxMagassag)
		{
			maxMagassag = tomb[i].magassag;
			maxIndex = i;
		}
	}

	darab = tancparok(tomb[maxIndex], tomb, meret);

	return darab;
	// return maxIndex;
}

int tombosszege(int tomb[], int meret)
{
	int i;
	int osszeg = 0;
	for(i = 0; i < meret; i++)
	{
		osszeg = osszeg + tomb[i];
	}
	return osszeg;
}

int main()
{
	int also;
	int felso;
	int i;
	int egyes;
	int tizes;
	int szazas;

	scanf("%d %d\n", &also, &felso);

	for(i = also; i <= felso; i++)
	{
		if(i >= 0 && i <= 9)
		{
			szazas = 0;
			tizes = 0;
			egyes = i % 10;
		}
		else if(i >= 10 && i <= 99)
		{
			egyes = i % 10;
			tizes = (i / 10) % 10;
			szazas = 0;
		}
		else
		{
			egyes = i % 10;
			tizes = (i / 10) % 10;
			szazas = (i / 100) % 10;
		}

		if(szazas - tizes == tizes - egyes)
		{
			printf("%d\n", i);
		}
	}

	/*
	struct Konyv k = {"Egri csillagok", 420};

	int n = 60;
	int i;
	for(i = 1; i <= n; i++)
	{
		if(n % i == 0)
		{
			// printf("%d\n", i);
		}
	}
	*/
	
	/*
	int ev = 2017;
	int egyes = ev % 10;
	int tizes = (ev / 10) % 10;
	int szazas = (ev / 100) % 10;
	int ezres = (ev / 1000) % 10;
	printf("%d %d %d %d\n", ezres, szazas, tizes, egyes);
	*/
	return 0;
}