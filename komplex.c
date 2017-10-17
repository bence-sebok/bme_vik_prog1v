#include <stdio.h>
#include <math.h>

typedef struct
{
	double valos;
	double kepzetes;
} Komplex;

Komplex beolvasKomplex(void)
{
	Komplex k;
	scanf("%lf %lf\n", &k.valos, &k.kepzetes);
	return k;
}

void kiirKomplex(Komplex k)
{
	if (k.kepzetes < 0)
	{
		printf("%.3f%.3fj", k.valos, k.kepzetes);
	}
	else
	{
		printf("%.3f+%.3fj", k.valos, k.kepzetes);
	}
}

double abszolutErtek(Komplex k)
{
	double absz;
	absz = sqrt(k.valos*k.valos + k.kepzetes*k.kepzetes);
	return absz;
}

int main()
{
	int i;
	double maxErtek;
	Komplex maxSzam;
	Komplex komplexSzamok[3];
	Komplex sokSzam[10] =
	{
		{ 1.0, 2.0 },
		{ 3.4,-7.1 },
		{ -5.3,3.1 },
		{ -6.1,9.6 },
		{ 3.675,1.23 },
		{ 3.0,4.0 },
		{ 3.0,-4.0 },
		{ 1.25,6.54 },
		{ 2.98,-9.99 },
		{ 4.1,5.6 }
	};

	/*
	// komplex szamok beolvasasa tombbe
	for (i = 0; i < 3; i++)
	{
		komplexSzamok[i] = beolvasKomplex();
	}
	*/

	// komplex szamok tombjenek kiirasa:
	for (i = 0; i < 10; i++)
	{
		kiirKomplex(sokSzam[i]);
		printf("\n");
	}


	// komplex szamok abszolut ertekenek kiirasa:
	for (i = 0; i < 10; i++)
	{
		kiirKomplex(sokSzam[i]);
		printf(" komplex szam abszolut erteke: %f\n", abszolutErtek(sokSzam[i]));
	}

	// legnagyobb abszolut erteku komplex szam megkeresese:
	maxErtek = abszolutErtek(sokSzam[0]);
	maxSzam = sokSzam[0];
	for (i = 1; i < 10; i++)
	{
		if (abszolutErtek(sokSzam[i]) > maxErtek)
		{
			maxErtek = abszolutErtek(sokSzam[i]);
			maxSzam = sokSzam[i];
		}
	}
	printf("Legnagyobb abszolut erteku komplex szam a tombben:\n");
	kiirKomplex(maxSzam);
	printf("\n");

	return 0;
}