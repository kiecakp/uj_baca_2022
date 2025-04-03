//Patrycja Kiecak

#include <iostream>
using namespace std;

int main(){
	int liczbaSesji;
	int liczbaElementow;
	int liczbaElementowZast;
	int x = 0;
	int startOperacji;
	int iloscMiejsc;
	int przesuniecie;
	char operacje;
	
	cin >> liczbaSesji;
	
	if(liczbaSesji > 0){
		cin >> liczbaElementow;
		liczbaElementowZast = liczbaElementow;
		int tablica [liczbaElementow];
		
		if (liczbaElementow > 0){
			while (liczbaSesji > 0){
				
				while (liczbaElementow > 0){		//zapisywanie danych do tablicy
				cin >> tablica [x];
				cout << tablica [x] << " ";
				x += 1;
				liczbaElementow -= 1;
				}
				cout << endl;
				
				while (operacje != 'F'){		//pobieranie operacji dopoki uzytkownik nie poda F
					cin >> operacje;
					
					if (operacje == 'R'){		//odwracanie	
						cin >> startOperacji >> iloscMiejsc;
						
						if (iloscMiejsc != 0){
							while (startOperacji < 0)
								startOperacji += liczbaElementowZast;
															
							int i = 0;
							while (i < (liczbaElementowZast / iloscMiejsc)){
								int przejscie = i * iloscMiejsc;
								
								int j = 0;
								while (j < (iloscMiejsc / 2)){
									int zamiennik = tablica [(startOperacji + przejscie + j) % liczbaElementowZast];
									tablica [(startOperacji + przejscie + j) % liczbaElementowZast] = tablica [(startOperacji + przejscie + iloscMiejsc - j - 1) % liczbaElementowZast];
									tablica [(startOperacji + przejscie + iloscMiejsc - j - 1) % liczbaElementowZast] = zamiennik;
									
									j++;
								}
								i++;
							}						
						}
					}					
					else if (operacje == 'M'){		//przesuniecie
					}
					else if (operacje == 'C'){		//zamiana parami
						cin >> startOperacji >> iloscMiejsc;
						
						if (iloscMiejsc != 0){
							while (startOperacji < 0)
								startOperacji += liczbaElementowZast;
								
							int i = 0;
							while ((i + 1) < (liczbaElementowZast / iloscMiejsc)){
								int przejscie = (i + 1) * iloscMiejsc;
								
								int j = 0;
								while (j < iloscMiejsc){
									int zamiennik = tablica [(startOperacji + przejscie + j) % liczbaElementowZast];
									tablica [(startOperacji + przejscie + j) % liczbaElementowZast] = tablica [(startOperacji + (2 * przejscie) + j) % liczbaElementowZast];
									tablica [(startOperacji + (2 * przejscie) + j) % liczbaElementowZast] = zamiennik;
									
									j++;
								}
								i++;
							}	
						}
					}
					else if (operacje == 'S'){		//sortowanie
						cin >> startOperacji >> iloscMiejsc;
						
						if (iloscMiejsc != 0){
							while (startOperacji < 0)
								startOperacji += liczbaElementowZast;
								
							int i = 0;
							while (i < (liczbaElementowZast / iloscMiejsc)){
								int przejscie = i * iloscMiejsc;
								
								int j = 0;
								while (j < (iloscMiejsc - 1)){
									
									if (iloscMiejsc > 0){
										if (tablica [(startOperacji + przejscie + j) % liczbaElementowZast] > tablica [(startOperacji + przejscie + j + 1) % liczbaElementowZast]){
											int zamiennik = tablica [(startOperacji + przejscie + j) % liczbaElementowZast];
											tablica [(startOperacji + przejscie + j) % liczbaElementowZast] = tablica [(startOperacji + przejscie + j + 1) % liczbaElementowZast];
											tablica [(startOperacji + przejscie + j + 1) % liczbaElementowZast] = zamiennik;
										}
									}									
									else if (iloscMiejsc < 0){
										if (tablica [(startOperacji + przejscie + j) % liczbaElementowZast] < tablica [(startOperacji + przejscie + j + 1) % liczbaElementowZast]){
											int zamiennik = tablica [(startOperacji + przejscie + j) % liczbaElementowZast];
											tablica [(startOperacji + przejscie + j) % liczbaElementowZast] = tablica [(startOperacji + przejscie + j + 1) % liczbaElementowZast];
											tablica [(startOperacji + przejscie + j + 1) % liczbaElementowZast] = zamiennik;
										}
									}
									j++;								
								}
								i++;
							}
							
							int przejscie = i * iloscMiejsc;
							int pozostalyFragment = liczbaElementowZast - przejscie;
							
							if (pozostalyFragment > 0){
								int j = 0;
								while (j < (pozostalyFragment - 1)){
									
									if (iloscMiejsc > 0){
										if (tablica [(startOperacji + przejscie + j) % liczbaElementowZast] > tablica [(startOperacji + przejscie + j + 1) % liczbaElementowZast]){
											int zamiennik = tablica [(startOperacji + przejscie + j) % liczbaElementowZast];
											tablica [(startOperacji + przejscie + j) % liczbaElementowZast] = tablica [(startOperacji + przejscie + j + 1) % liczbaElementowZast];
											tablica [(startOperacji + przejscie + j + 1) % liczbaElementowZast] = zamiennik;
										}
									}									
									else if (iloscMiejsc < 0){
										if (tablica [(startOperacji + przejscie + j) % liczbaElementowZast] < tablica [(startOperacji + przejscie + j + 1) % liczbaElementowZast]){
											int zamiennik = tablica [(startOperacji + przejscie + j) % liczbaElementowZast];
											tablica [(startOperacji + przejscie + j) % liczbaElementowZast] = tablica [(startOperacji + przejscie + j + 1) % liczbaElementowZast];
											tablica [(startOperacji + przejscie + j + 1) % liczbaElementowZast] = zamiennik;
										}
									}
									j++;								
								}
							}
						}
					}
				}
				liczbaSesji -= 1;
			}
		}

		x = 0;
		while (liczbaElementowZast > x){		//wypisywanie tablicy
			cout << tablica [x] << " ";
			x += 1;
		}
	}
		
	return 0;
}
