// Patrycja Kiecak

#include <iostream>
using namespace std;

// h - wysokosc numerujac poziomy
// w - szerokosc numerujac piony
// d - glebokosc numerujac panele

// dlugosc krawedzi szescianu jest liczba parzysta
/* kazda bryla jest okreslona poprzez wierzcholek/srodek, trzy wzajemne prostopadle 
   i rownolegle do osi ukladu wspolrzednych krawedzie skierowane od zadanego wierzcholka/
   srodka do centrum szescianu
*/

int main(){
	int dlKrawSzescianu;	//dlugosc krawedzi szescianu
	char kodOperacji;
	int l;	//wspolrzedna poziomu wierzcholka
	int v;	//wspolrzedna pionu wierzcholka
	int p;	//wspolrzedna panelu wierzcholka
	int h;	//wysokosc prostopadloscianu
	int w;	//szerokosc prostopadloscianu
	int d;	//glebokosc prostopadloscianu
	int e;	//dlugosc prostopadlych krawedzi czworoscianu
	int r;	//dlugosc promienia
	char k;	//jedna z liter 'l', 'v', 'p'
	int i; 	//poprawna wartosc indeksu tablicy danych
	
	int suma = 0;
	
	int wlasciwyX = 0;		//dane potrzebne do wyliczania wspolrzednych figur przestrzennych
	int wlasciwyY = 0;
	int wlasciwyZ = 0;
	int x = 0;
	int y = 0;
	int z = 0;
	
	int sprawdzone = 0;		//zmienna do sprawdzania ktore wiersze danych zostaly juz sprawdzone
	int przechowalnia; 	//zmienna dodatkowa do przechowywania danych
	
	cin >> dlKrawSzescianu;
	int szescian [dlKrawSzescianu][dlKrawSzescianu][dlKrawSzescianu];
	long long fragment_macierzy [dlKrawSzescianu][dlKrawSzescianu];
	if ((dlKrawSzescianu >= 0) && (dlKrawSzescianu <= 32 ) && ((dlKrawSzescianu % 2) == 0)){	
		
		int i = 0;
		while (i < dlKrawSzescianu){
			
			int j = 0;
			while (j < dlKrawSzescianu){
				
				int k = 0;
				while (k < dlKrawSzescianu){
					cin >> szescian [j][k][i];		//wpisywanie danych do szescianu
					k++;
				}
				j++;
			}
			i++;
		}
		
		cin >> kodOperacji;
		while (kodOperacji != 'E'){		//pobieranie kodu operacji
			if (kodOperacji == 'C'){		//przeciecie prostopadloscianu z szescianem
				cin >> l >> v >> p >> h >> w >> d;
					
				if (l >= (dlKrawSzescianu / 2))
					x = -1;
				else 
					x = 1;
					
				if (v >= (dlKrawSzescianu / 2))		//orientacja polozenia wspolrzednych
					y = -1;
				else 
					y = 1;
					
				if (p >= (dlKrawSzescianu / 2))
					z = -1;
				else 
					z = 1;
				
				int i = 0;
				while (i <= h){
					
					int j = 0;
					while (j <= w){
						
						int k = 0;
						while (k <= d){
							wlasciwyX = l + x * i;		//koordynacje punktow figury
							wlasciwyY = v + y * j;
							wlasciwyZ = p + z * k;
							
							if ((wlasciwyX < dlKrawSzescianu) && (wlasciwyY < dlKrawSzescianu) && (wlasciwyZ < dlKrawSzescianu) && (wlasciwyX >= 0) && (wlasciwyY >= 0) && (wlasciwyZ >= 0)){	//warunki zawierania sie w szescianie
								suma += szescian[wlasciwyX][wlasciwyY][wlasciwyZ];
							}									
							k++;
						}
						j++;
					}
					i++;
				}
				cout << suma << endl;
				suma = 0;
			}
			else if (kodOperacji == 'T'){	//przeciecie zadanego czworoscianu z szescianem
				cin >> l >> v >> p >> e;
				
				if (l >= (dlKrawSzescianu / 2))
					x = -1;
				else 
					x = 1;
					
				if (v >= (dlKrawSzescianu / 2))		//orientacja polozenia wspolrzednych
					y = -1;
				else 
					y = 1;
					
				if (p >= (dlKrawSzescianu / 2))
					z = -1;
				else 
					z = 1;
					
				int i = 0;
				while (i <= e){
					
					int j = 0;
					while (j <= (e - i)){
						
						int k = 0;
						while (k <= (e - j - i)){
							wlasciwyX = l + x * i;		//koordynacje punktow figury
							wlasciwyY = v + y * j;
							wlasciwyZ = p + z * k;
							
							if ((wlasciwyX < dlKrawSzescianu) && (wlasciwyY < dlKrawSzescianu) && (wlasciwyZ < dlKrawSzescianu) && (wlasciwyX >= 0) && (wlasciwyY >= 0) && (wlasciwyZ >= 0)){ 	//warunki zawierania sie w szescianie
								suma += szescian[wlasciwyX][wlasciwyY][wlasciwyZ];
							}									
							k++;
						}
						j++;
					}
					i++;
				}
				cout << suma << endl;
				suma = 0;
			
			}
			else if (kodOperacji == 'O'){	//przeciecie oktala z szescianem
			cin >> l >> v >> p >> r;
					
				if (l >= (dlKrawSzescianu / 2))
					x = -1;
				else 
					x = 1;
					
				if (v >= (dlKrawSzescianu / 2))		//orientacja polozenia wspolrzednych
					y = -1;
				else 
					y = 1;
					
				if (p >= (dlKrawSzescianu / 2))
					z = -1;
				else 
					z = 1;
				
				int i = 0;
				while (i <= r){
					
					int j = 0;
					while (j <= r){
						
						int k = 0;
						while (k <= r){
							wlasciwyX = l + x * i; 		//koordynacje punktow figury
							wlasciwyY = v + y * j;
							wlasciwyZ = p + z * k;
							
							if ((wlasciwyX < dlKrawSzescianu) && (wlasciwyY < dlKrawSzescianu) && (wlasciwyZ < dlKrawSzescianu) && (wlasciwyX >= 0) && (wlasciwyY >= 0) && (wlasciwyZ >= 0)){ 	//warunki zawierania sie w szescianie
								if (((i * i) + (j * j) + (k * k)) <= (r * r))
									suma += szescian[wlasciwyX][wlasciwyY][wlasciwyZ];
							}									
							k++;
						}
						j++;
					}
					i++;
				}
				cout << suma << endl;
				suma = 0;
				
			}
			else if (kodOperacji == 'D'){	//wyznacznik
				cin >> k >> i;
				
				long long wyznacznik = 1;
				
				if (k == 'l'){		//poziom o poprawnej wartosci indeksu tablicy i
					int n = 0;
					while (n < dlKrawSzescianu){
						
						int j = 0;
						while (j < dlKrawSzescianu){
							
							fragment_macierzy [n][j] = szescian [i][n][j];
							
							j++;
						}
						n++;
					}
				}
				else if (k == 'v'){		//pion o poprawnej wartosci indeksu tablicy i
					int n = 0;
					while (n < dlKrawSzescianu){
						
						int j = 0;
						while (j < dlKrawSzescianu){
							
							fragment_macierzy [n][j] = szescian [n][i][j];
							
							j++;
						}
						n++;
					}
				}
				else if (k == 'p'){		//panel o poprawnej wartosci indeksu tablicy i
					int n = 0;
					while (n < dlKrawSzescianu){
						
						int j = 0;
						while (j < dlKrawSzescianu){
							
							fragment_macierzy [n][j] = szescian [n][j][i];
							
							j++;
						}
						n++;
					}
				}
				
				int n = 0;
				while (n < (dlKrawSzescianu - 1)){
					
					
					
					
					if (fragment_macierzy [n][n] == 0 ){
						sprawdzone = 1;
						
						int j = n + 1;
						while (j < dlKrawSzescianu){
							
							
							
							
							if ((fragment_macierzy [j][n] != 0) && (sprawdzone == 1)){
								
								int k = 0;
								while (k < dlKrawSzescianu){
									przechowalnia = fragment_macierzy[n][k];
                                	fragment_macierzy[n][k] = fragment_macierzy[j][k];
                                	fragment_macierzy[j][k] = przechowalnia;
									k++;
								}
								sprawdzone = 0;
								wyznacznik *= (-1);
							}
							
							if ((j == (dlKrawSzescianu - 1)) && (sprawdzone == 1) && (fragment_macierzy [j][n] == 0))
								wyznacznik = 0;
							
							j++;
						}
					}
					
					
					
					int j = n + 1;
					while (j < dlKrawSzescianu){
						przechowalnia = fragment_macierzy [j][n];
						
						int k = n;
						while (k < dlKrawSzescianu){
							if ((n != 0) && (fragment_macierzy [n - 1][n - 1] != 0))
								fragment_macierzy [j][k] = ((fragment_macierzy [j][k] * fragment_macierzy [n][n]) - (przechowalnia * fragment_macierzy [n][k])) / fragment_macierzy [n - 1][n - 1];
							else
								fragment_macierzy [j][k] = (fragment_macierzy [j][k] * fragment_macierzy [n][n]) - (przechowalnia * fragment_macierzy [n][k]);
							k++;
						}
						j++;
					}
					
					
					n++;
				}

				wyznacznik *= fragment_macierzy [dlKrawSzescianu - 1][dlKrawSzescianu - 1];
				cout << wyznacznik << endl;
				suma = 0;
			}
			cin >> kodOperacji;
		}
	}
	return 0;
}
