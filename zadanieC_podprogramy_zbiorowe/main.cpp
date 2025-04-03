// Patrycja Kiecak

#include <iostream>
using namespace std;

void Add (int liczba, int* tablica){ //done
	int dlugosc = 0;
	int powtorka = 0;
	int zamiennik = 0;
	
	int i = 0;
	while (tablica [i] != -1){
		dlugosc += 1;
		i++;
	}
	
	if ((liczba >= 1) && (liczba <= 4095)){
		i = 0;
		while (i <= dlugosc){
			if (liczba == tablica [i])
				powtorka += 1;
			i++;
		}
		if (powtorka == 0){
			dlugosc += 1;
			tablica [dlugosc] = liczba;
		}
	}
	
	i = 0;
	while (i <= dlugosc){
		int j = 1;
		while (j <= dlugosc){
			if (tablica [j-1] > tablica [j]){
				zamiennik = tablica [j - 1];
				tablica [j - 1] = tablica [j];
				tablica [j] = zamiennik;
			}
			j++;
		}
		i++;
	}
	
	zamiennik = tablica [0];
	i = 1;
	while (i <= dlugosc){
		tablica [i - 1] = tablica [i];
		i++;
	}
	tablica [dlugosc] = zamiennik;
}	

bool Element (int liczba, int* tablica){ //done
	int dlugosc = 0;
	int przynaleznosc = 0;
	
	int i = 0;
	while (tablica [i] != -1){
		dlugosc += 1;
		i++;
	}
	
	i = 0;
	while (i < dlugosc){
		if (tablica [i] == liczba)
			przynaleznosc += 1;
		i++;
	}
	
	if (przynaleznosc != 0)
		return 1;
	else
		return 0;
}

void Create (int liczba, int* tablicaWejsciowa, int* tablicaWyjsciowa){ //done
	int przynaleznosc = 0;
	int dlugosc = 0;
	int zamiennik;
	
	if (liczba >= 0){
		
		int i = 0;
		while (liczba != 0){
			if ((tablicaWejsciowa [i] >= 1) && (tablicaWejsciowa [i] <= 4095)){

				if (! Element (tablicaWejsciowa [i], tablicaWyjsciowa)){
					tablicaWyjsciowa [dlugosc++] = tablicaWejsciowa [i];
				}
			}
			liczba -= 1;
			i++;
		}
		tablicaWyjsciowa [dlugosc] = -1;
	}
}

void Complement (int* tablicaDopelniana, int* tablicaDopelniajaca){ //done
	int dlugosc = 0;

	int i = 1;
	while (i <= 4095){
		if (! Element (i, tablicaDopelniana)){
			tablicaDopelniajaca[dlugosc] = i;
			dlugosc += 1;
		}
		i++;
	}
	tablicaDopelniajaca[dlugosc] = -1;
}

void Union (int* tablicaPierwsza, int* tablicaDruga, int* wynik){ //done
	int dlugosc = 0;
	int zamiennik;
	
	int i = 0;
	while (tablicaPierwsza [i] != -1){
		if (! Element (tablicaPierwsza [i], tablicaDruga)){
			wynik [dlugosc] = tablicaPierwsza [i];
			dlugosc += 1;
		}
		i++;
	}
	
	i = 0;
	while (tablicaDruga [i] != -1){
		wynik [dlugosc] = tablicaDruga [i];
		dlugosc += 1;
		i++;
	}
	wynik [dlugosc] = -1;
	
	// sortowanie
	
	i = 0;
	while (i <= dlugosc){
		int j = 1;
		while (j <= dlugosc){
			if (wynik [j-1] > wynik [j]){
				zamiennik = wynik [j - 1];
				wynik [j - 1] = wynik [j];
				wynik [j] = zamiennik;
			}
			j++;
		}
		i++;
	}
	
	zamiennik = wynik [0];
	i = 1;
	while (i <= dlugosc){
		wynik [i - 1] = wynik [i];
		i++;
	}
	wynik [dlugosc] = zamiennik;
}

void Intersection (int* tablicaPierwsza, int* tablicaDruga, int* wynik){ //done
	int dlugosc = 0;
	
	int i = 0;
	while (tablicaPierwsza [i] != -1){
		if (Element (tablicaPierwsza [i], tablicaDruga)){
			wynik [dlugosc] = tablicaPierwsza [i];
			dlugosc += 1;
		}
		i++;			
	}
	wynik [dlugosc] = -1;
	
	int zamiennik;
	i = 0;
	while (i <= dlugosc){
		int j = 1;
		while (j < dlugosc){
			if (wynik [j-1] > wynik [j]){
				zamiennik = wynik [j - 1];
				wynik [j - 1] = wynik [j];
				wynik [j] = zamiennik;
			}
			j++;
		}
		i++;
	}
}

void Difference (int* tabOdejmna, int* tabOdejmnik, int* wynik){ //done
	//odejmna - liczba od ktorej odejmujemy (wieksza tablica)
	//odejmnik - liczba ktora odejmujemy (mniejsza tablica)
	//z polecenia wynika ze pierwsza podana tablica jest wieksza od drugiej
	
	int dlugosc = 0;
	
	int i = 0;
	while (tabOdejmna [i] != -1){
		if (! Element (tabOdejmna [i], tabOdejmnik)){
			wynik [dlugosc] = tabOdejmna [i];
			dlugosc += 1;
		}
		i++;
	}
	wynik [dlugosc] = -1;
	
	int zamiennik;
	i = 0;
	while (i <= dlugosc){
		int j = 1;
		while (j < dlugosc){
			if (wynik [j-1] > wynik [j]){
				zamiennik = wynik [j - 1];
				wynik [j - 1] = wynik [j];
				wynik [j] = zamiennik;
			}
			j++;
		}
		i++;
	}
}

void Symmetric (int* tablicaPierwsza, int* tablicaDruga, int* wynik){ //done
	//roznica symetryczna --> A%B = (A\B) U (B\A)
	/*
		A\B - roznica zbioru A i B (Difference)
		B\A - roznica zbioru B i A (Difference)
		(A\B) U (B\A) - suma zbiorow (Union)
	*/
	
	// A\B
	
	int dlugosc = 0;
	
	int i = 0;
	while (tablicaPierwsza [i] != -1){
		if (! Element (tablicaPierwsza [i], tablicaDruga)){
			wynik [dlugosc] = tablicaPierwsza [i];
			dlugosc += 1;
		}
		i++;
	}
	
	// B\A
	
	i = 0;
	while (tablicaDruga [i] != -1){
		if (! Element (tablicaDruga [i], tablicaPierwsza)){
			wynik [dlugosc] = tablicaDruga [i];
			dlugosc += 1;
		}
		i++;
	}
	wynik [dlugosc] = -1;
	
	int zamiennik;
	i = 0;
	while (i <= dlugosc){
		int j = 1;
		while (j < dlugosc){
			if (wynik [j-1] > wynik [j]){
				zamiennik = wynik [j - 1];
				wynik [j - 1] = wynik [j];
				wynik [j] = zamiennik;
			}
			j++;
		}
		i++;
	}
}

bool Subset (int* tablicaZawierana, int* tablicaZawierajaca){ //done
	int dl1 = 1;
	int dl2 = 1;
	int zawieranie = 0;
	
	int i = 0;
	while (tablicaZawierana [i] != -1){
		dl1 += 1;
		i++;
	}
	i = 0;
	while (tablicaZawierajaca [i] != -1){
		dl2 += 1;
		i++;
	}
	
	i = 0;
	while (i < dl2){
		int j = 0;
		while (j < dl1){
			if (tablicaZawierana [j] == tablicaZawierajaca [i])
				zawieranie += 1;
			j++;
		}
		i++;
	}
	
	if (zawieranie == dl1)
		return 1;
	else
		return 0;
}

bool Equal (int* tablicaPierwsza, int* tablicaDruga){ //done
	int dl1 = 1;
	int dl2 = 1;
	int rownosc = 0;

	int i = 0;
	while (tablicaPierwsza[i] != -1) {
		dl1 += 1;
		i++;
	}
	i = 0;
	while (tablicaDruga[i] != -1) {
		dl2 += 1;
		i++;
	}

	i = 0;
	while (i <= dl1)
	{
		int j = 0;
		while (j < dl2)
		{
			if (tablicaPierwsza[i] == tablicaDruga[j])
			{
				rownosc++;
			}
			j++;
		}
		i++;
	}

	if ((dl1 == rownosc) && (dl2 == rownosc))
		return 1;
	else
		return 0;
}

bool Empty (int* tablica){	//done
	int dlugosc = 0;
	
	int i = 0;
	while (tablica [i] != -1){
		dlugosc += 1;
		i++;
	}
	
	if (dlugosc == 0)
		return 1;
	else
		return 0;
}

bool Nonempty (int* tablica){ //done
	int dlugosc = 0;
	
	int i = 0;
	while (tablica [i] != -1){
		dlugosc += 1;
		i++;
	}
	
	if (dlugosc == 0)
		return 0;
	else
		return 1;
}

double Arithmetic (int* tablica){ //done
	double dlugosc = 0;
	double sumaElementow = 0;
	
	int i = 0;
	while (tablica [i] != -1){
		dlugosc += 1;
		i++;
	}
	
	if (dlugosc == 0)
		return 0;
	else{
		i = 0;
		while (i < dlugosc){
			sumaElementow += tablica [i];
			i++;
		}
		return sumaElementow / dlugosc;
	}
}

double Harmonic (int* tablica){ //done
	double dlugosc = 0;
	double sumaElementow = 0;
	double liczbaOdwrotna = 0;
	double element;
	
	int i = 0;
	while (tablica [i] != -1){
		dlugosc += 1;
		i++;
	}
	
	if (dlugosc == 0)
		return 1;
	else{
		i = 0;
		while (i < dlugosc){
			element = tablica [i];
			liczbaOdwrotna = 1 / element;
			sumaElementow += liczbaOdwrotna;
			i++;
		}
		return dlugosc / sumaElementow;
	} 
}

void MinMax (int* tablica, int* min, int& max){ //done
	//jezeli tablica jest niepusta to zmieniamy wartosci min, max
	
	if(! Empty(tablica)){
		max = 1;		//zalozenia dzieki ktorym beda zmieniane wartosci
		*min = 4095;
		
		int i = 0;
		while (tablica [i] != -1){
			
			if (tablica [i] > max)
				max = tablica [i];
				
			if (tablica [i] < *min)
				*min = tablica [i];
				
			i++;
		}
	}
	
}

void Cardinality (int* tablica, int* moc){ //done
	// moc zbioru jest rowna ilosci elementow zbioru
	
	*moc = 0;
	while (tablica [ *moc] != -1){
		*moc += 1;
	}
}

void Properties (int* tablica, char* ciag, double& sredniaArytmetyczna, double* sredniaHarmoniczna, int& min, int* max, int& moc){
	// a - wyznacza srednia arytmetyczna
	// h - wyznacza srednia harmoniczna
	// m - wyznacza min i max
	// c - wyznacza moc zbioru
	
	int i = 0;
	while (ciag [i] != '\0'){
		if (ciag [i] == 'a'){
			sredniaArytmetyczna = Arithmetic (tablica);
		}
		
		else if (ciag [i] == 'h'){
			*sredniaHarmoniczna = Harmonic (tablica);
		}
		
		else if (ciag [i] == 'm'){
			MinMax (tablica, &min, *max);
		}
		
		else if (ciag [i] == 'c'){
			Cardinality (tablica, &moc);
		}
		i++;
	}
}