//Patrycja Kiecak

#include <iostream>
using namespace std;

int main(){
	int liczbaRozgrywek;	//deklaracja ilosci rozgrywek
	int pierwszaSila;		//deklaracja wartosci sily pierwszego gracza
	int drugaSila;			//deklaracja wartosci sily drugiego gracza
	
	float iloscGierA = 0;	//deklaracje ilosci gier danego gracza
	float iloscGierB = 0;
	float iloscGierC = 0;
	float iloscGierD = 0;
	float wygranaA = 0;		//deklaracje ilosci wygranych danego gracza
	float wygranaB = 0;
	float wygranaC = 0;
	float wygranaD = 0;
	float przegranaA = 0;	//deklaracje ilosci przegranych danego gracza
	float przegranaB = 0;
	float przegranaC = 0;
	float przegranaD = 0;
	float remisA = 0;		//deklaracje ilosci remisow danego gracza
	float remisB = 0;
	float remisC = 0;
	float remisD = 0;
	
	float wygrana = 0.0;	//deklaracje zmiennych do wyswietlenia na wyjsciu
	float remis = 0.0;
	float przegrana = 0.0;
	
	char pierwszyGracz;		//deklaracja id pierwszegi gracza
	char drugiGracz;		//deklaracja id drugiego gracza
	char pierwszyWybor;		//deklaracja wyboru pierwszego gracza
	char drugiWybor;		//deklaracja wyboru drugiego gracza
	
	cin >> liczbaRozgrywek;	
	
	if (liczbaRozgrywek > 0){
		while (liczbaRozgrywek > 0){
			cin >> pierwszyGracz >> pierwszyWybor >> pierwszaSila >> drugiGracz >> drugiWybor >> drugaSila;		//pobranie danych
					
			if (pierwszyGracz == 'a' || drugiGracz == 'a'){		//warunki dla gracza A
				iloscGierA += 1;
					
				if (pierwszyWybor != drugiWybor){						//warunek dla porownania wyborow
					if (pierwszyWybor == 'J' && drugiWybor == 'P'){			//warunki dla wygranej lub przegranej A
						if (pierwszyGracz == 'a')
							wygranaA += 1;
						else if (drugiGracz == 'a')
							przegranaA +=1;}						
					else if (pierwszyWybor == 'J' && drugiWybor == 'S'){
						if (pierwszyGracz == 'a')
							wygranaA += 1;
						else if (drugiGracz == 'a')
							przegranaA +=1;}
					else if (pierwszyWybor == 'K' && drugiWybor == 'J'){
						if (pierwszyGracz == 'a')
							wygranaA += 1;
						else if (drugiGracz == 'a')
							przegranaA +=1;}				
					else if (pierwszyWybor == 'K' && drugiWybor == 'N'){
						if (pierwszyGracz == 'a')
							wygranaA += 1;
						else if (drugiGracz == 'a')
							przegranaA +=1;}						
					else if (pierwszyWybor == 'N' && drugiWybor == 'J'){
						if (pierwszyGracz == 'a')
							wygranaA += 1;
						else if (drugiGracz == 'a')
							przegranaA +=1;}						
					else if (pierwszyWybor == 'N' && drugiWybor == 'P'){
						if (pierwszyGracz == 'a')
							wygranaA += 1;
						else if (drugiGracz == 'a')
							przegranaA +=1;}						
					else if (pierwszyWybor == 'P' && drugiWybor == 'K'){
						if (pierwszyGracz == 'a')
							wygranaA += 1;
						else if (drugiGracz == 'a')
							przegranaA +=1;}						
					else if (pierwszyWybor == 'P' && drugiWybor == 'S'){
						if (pierwszyGracz == 'a')
							wygranaA += 1;
						else if (drugiGracz == 'a')
							przegranaA +=1;}						
					else if (pierwszyWybor == 'S' && drugiWybor == 'K'){
						if (pierwszyGracz == 'a')
							wygranaA += 1;
						else if (drugiGracz == 'a')
							przegranaA +=1;}						
					else if (pierwszyWybor == 'S' && drugiWybor == 'N'){
						if (pierwszyGracz == 'a')
							wygranaA += 1;
						else if (drugiGracz == 'a')
							przegranaA +=1;}
							
					else if (pierwszyWybor == 'P' && drugiWybor == 'J'){		//warunki odwrotne do powyzszych dla wygranej lub przegranej A
						if (pierwszyGracz == 'a')
							przegranaA +=1;
						else if (drugiGracz == 'a')
							wygranaA += 1;}		
					else if (pierwszyWybor == 'S' && drugiWybor == 'J'){
						if (pierwszyGracz == 'a')
							przegranaA +=1;
						else if (drugiGracz == 'a')
							wygranaA += 1;}
					else if (pierwszyWybor == 'J' && drugiWybor == 'K'){
						if (pierwszyGracz == 'a')
							przegranaA +=1;
						else if (drugiGracz == 'a')
							wygranaA += 1;}
					else if (pierwszyWybor == 'N' && drugiWybor == 'K'){
						if (pierwszyGracz == 'a')
							przegranaA +=1;
						else if (drugiGracz == 'a')
							wygranaA += 1;}
					else if (pierwszyWybor == 'J' && drugiWybor == 'N'){
						if (pierwszyGracz == 'a')
							przegranaA +=1;
						else if (drugiGracz == 'a')
							wygranaA += 1;}
					else if (pierwszyWybor == 'P' && drugiWybor == 'N'){
						if (pierwszyGracz == 'a')
							przegranaA +=1;
						else if (drugiGracz == 'a')
							wygranaA += 1;}
					else if (pierwszyWybor == 'K' && drugiWybor == 'P'){
						if (pierwszyGracz == 'a')
							przegranaA +=1;
						else if (drugiGracz == 'a')
							wygranaA += 1;}
					else if (pierwszyWybor == 'S' && drugiWybor == 'P'){
						if (pierwszyGracz == 'a')
							przegranaA +=1;
						else if (drugiGracz == 'a')
							wygranaA += 1;}
					else if (pierwszyWybor == 'K' && drugiWybor == 'S'){
						if (pierwszyGracz == 'a')
							przegranaA +=1;
						else if (drugiGracz == 'a')
							wygranaA += 1;}
					else if (pierwszyWybor == 'N' && drugiWybor == 'S'){
						if (pierwszyGracz == 'a')
							przegranaA +=1;
						else if (drugiGracz == 'a')
							wygranaA += 1;}							
				}	
					
				else if (pierwszyWybor == drugiWybor){		//warunki gdy wybory sa rowne
					if (pierwszaSila == drugaSila)		//warunek dla wyniku remisu A
						remisA += 1;
					if (pierwszyGracz == 'a'){
						if (pierwszaSila > drugaSila)
							wygranaA += 1;					//porownanie sily i zdecydowanie czy wygrana czy przegrana
						else if (pierwszaSila < drugaSila)
							przegranaA += 1;	}	
				
					else if (drugiGracz == 'a'){
						if (pierwszaSila < drugaSila)
							wygranaA +=1;					//porownanie sily i zdecydowanie czy wygrana czy przegrana
						else if (pierwszaSila > drugaSila)
							przegranaA += 1;	}
				}	
			}
			
			if (pierwszyGracz == 'b' || drugiGracz == 'b'){		//warunki dla gracza B
				iloscGierB += 1;
					
				if (pierwszyWybor != drugiWybor){					//warunek dla porownania wyborow
					if (pierwszyWybor == 'J' && drugiWybor == 'P'){		//warunki dla wygranej lub przegranej B
						if (pierwszyGracz == 'b')
							wygranaB += 1;
						else if (drugiGracz == 'b')
							przegranaB +=1;}						
					else if (pierwszyWybor == 'J' && drugiWybor == 'S'){
						if (pierwszyGracz == 'b')
							wygranaB += 1;
						else if (drugiGracz == 'b')
							przegranaB +=1;}
					else if (pierwszyWybor == 'K' && drugiWybor == 'J'){
						if (pierwszyGracz == 'b')
							wygranaB += 1;
						else if (drugiGracz == 'b')
							przegranaB +=1;}				
					else if (pierwszyWybor == 'K' && drugiWybor == 'N'){
						if (pierwszyGracz == 'b')
							wygranaB += 1;
						else if (drugiGracz == 'b')
							przegranaB +=1;}						
					else if (pierwszyWybor == 'N' && drugiWybor == 'J'){
						if (pierwszyGracz == 'b')
							wygranaB += 1;
						else if (drugiGracz == 'b')
							przegranaB +=1;}						
					else if (pierwszyWybor == 'N' && drugiWybor == 'P'){
						if (pierwszyGracz == 'b')
							wygranaB += 1;
						else if (drugiGracz == 'b')
							przegranaB +=1;}						
					else if (pierwszyWybor == 'P' && drugiWybor == 'K'){
						if (pierwszyGracz == 'b')
							wygranaB += 1;
						else if (drugiGracz == 'b')
							przegranaB +=1;}						
					else if (pierwszyWybor == 'P' && drugiWybor == 'S'){
						if (pierwszyGracz == 'b')
							wygranaB += 1;
						else if (drugiGracz == 'b')
							przegranaB +=1;}						
					else if (pierwszyWybor == 'S' && drugiWybor == 'K'){
						if (pierwszyGracz == 'b')
							wygranaB += 1;
						else if (drugiGracz == 'b')
							przegranaB +=1;}						
					else if (pierwszyWybor == 'S' && drugiWybor == 'N'){
						if (pierwszyGracz == 'b')
							wygranaB += 1;
						else if (drugiGracz == 'b')
							przegranaB +=1;}
							
					else if (pierwszyWybor == 'P' && drugiWybor == 'J'){	//warunki odwrotne do powyzszych dla wygranej lub przegranej A
						if (pierwszyGracz == 'b')
							przegranaB +=1;
						else if (drugiGracz == 'b')
							wygranaB += 1;}		
					else if (pierwszyWybor == 'S' && drugiWybor == 'J'){
						if (pierwszyGracz == 'b')
							przegranaB +=1;
						else if (drugiGracz == 'b')
							wygranaB += 1;}
					else if (pierwszyWybor == 'J' && drugiWybor == 'K'){
						if (pierwszyGracz == 'b')
							przegranaB +=1;
						else if (drugiGracz == 'b')
							wygranaB += 1;}
					else if (pierwszyWybor == 'N' && drugiWybor == 'K'){
						if (pierwszyGracz == 'b')
							przegranaB +=1;
						else if (drugiGracz == 'b')
							wygranaB += 1;}
					else if (pierwszyWybor == 'J' && drugiWybor == 'N'){
						if (pierwszyGracz == 'b')
							przegranaB +=1;
						else if (drugiGracz == 'b')
							wygranaB += 1;}
					else if (pierwszyWybor == 'P' && drugiWybor == 'N'){
						if (pierwszyGracz == 'b')
							przegranaB +=1;
						else if (drugiGracz == 'b')
							wygranaB += 1;}
					else if (pierwszyWybor == 'K' && drugiWybor == 'P'){
						if (pierwszyGracz == 'b')
							przegranaB +=1;
						else if (drugiGracz == 'b')
							wygranaB += 1;}
					else if (pierwszyWybor == 'S' && drugiWybor == 'P'){
						if (pierwszyGracz == 'b')
							przegranaB +=1;
						else if (drugiGracz == 'b')
							wygranaB += 1;}
					else if (pierwszyWybor == 'K' && drugiWybor == 'S'){
						if (pierwszyGracz == 'b')
							przegranaB +=1;
						else if (drugiGracz == 'b')
							wygranaB += 1;}
					else if (pierwszyWybor == 'N' && drugiWybor == 'S'){
						if (pierwszyGracz == 'b')
							przegranaB +=1;
						else if (drugiGracz == 'b')
							wygranaB += 1;}				
				}
				
				else if (pierwszyWybor == drugiWybor){		//warunki gdy wybory sa rowne
					if (pierwszaSila == drugaSila)			//warunek dla wyniku remisu B
						remisB += 1;
					if (pierwszyGracz == 'b'){
						if (pierwszaSila > drugaSila)
							wygranaB += 1;					//porownanie sily i zdecydowanie czy wygrana czy przegrana
						else if (pierwszaSila < drugaSila)
							przegranaB += 1;	}	
				
					else if (drugiGracz == 'b'){
						if (pierwszaSila < drugaSila)
							wygranaB +=1;					//porownanie sily i zdecydowanie czy wygrana czy przegrana
						else if (pierwszaSila > drugaSila)
							przegranaB += 1;	}
				}	
			}	
			
			if (pierwszyGracz == 'c' || drugiGracz == 'c'){		//warunki dla gracza C
				iloscGierC += 1;
				
				if (pierwszyWybor != drugiWybor){
					if (pierwszyWybor == 'J' && drugiWybor == 'P'){
						if (pierwszyGracz == 'c')
							wygranaC += 1;
						else if (drugiGracz == 'c')
							przegranaC +=1;}						
					else if (pierwszyWybor == 'J' && drugiWybor == 'S'){
						if (pierwszyGracz == 'c')
							wygranaC += 1;
						else if (drugiGracz == 'c')
							przegranaC +=1;}
					else if (pierwszyWybor == 'K' && drugiWybor == 'J'){
						if (pierwszyGracz == 'c')
							wygranaC += 1;
						else if (drugiGracz == 'c')
							przegranaC +=1;}				
					else if (pierwszyWybor == 'K' && drugiWybor == 'N'){
						if (pierwszyGracz == 'c')
							wygranaC += 1;
						else if (drugiGracz == 'c')
							przegranaC +=1;}						
					else if (pierwszyWybor == 'N' && drugiWybor == 'J'){
						if (pierwszyGracz == 'c')
							wygranaC += 1;
						else if (drugiGracz == 'c')
							przegranaC +=1;}						
					else if (pierwszyWybor == 'N' && drugiWybor == 'P'){
						if (pierwszyGracz == 'c')
							wygranaC += 1;
						else if (drugiGracz == 'c')
							przegranaC +=1;}						
					else if (pierwszyWybor == 'P' && drugiWybor == 'K'){
						if (pierwszyGracz == 'c')
							wygranaC += 1;
						else if (drugiGracz == 'c')
							przegranaC +=1;}						
					else if (pierwszyWybor == 'P' && drugiWybor == 'S'){
						if (pierwszyGracz == 'c')
							wygranaC += 1;
						else if (drugiGracz == 'c')
							przegranaC +=1;}						
					else if (pierwszyWybor == 'S' && drugiWybor == 'K'){
						if (pierwszyGracz == 'c')
							wygranaC += 1;
						else if (drugiGracz == 'c')
							przegranaC +=1;}						
					else if (pierwszyWybor == 'S' && drugiWybor == 'N'){
						if (pierwszyGracz == 'c')
							wygranaC += 1;
						else if (drugiGracz == 'c')
							przegranaC +=1;}	
							
					else if (pierwszyWybor == 'P' && drugiWybor == 'J'){
						if (pierwszyGracz == 'c')
							przegranaC +=1;
						else if (drugiGracz == 'c')
							wygranaC += 1;}		
					else if (pierwszyWybor == 'S' && drugiWybor == 'J'){
						if (pierwszyGracz == 'c')
							przegranaC +=1;
						else if (drugiGracz == 'c')
							wygranaC += 1;}
					else if (pierwszyWybor == 'J' && drugiWybor == 'K'){
						if (pierwszyGracz == 'c')
							przegranaC +=1;
						else if (drugiGracz == 'c')
							wygranaC += 1;}
					else if (pierwszyWybor == 'N' && drugiWybor == 'K'){
						if (pierwszyGracz == 'c')
							przegranaC +=1;
						else if (drugiGracz == 'c')
							wygranaC += 1;}
					else if (pierwszyWybor == 'J' && drugiWybor == 'N'){
						if (pierwszyGracz == 'c')
							przegranaC +=1;
						else if (drugiGracz == 'c')
							wygranaC += 1;}
					else if (pierwszyWybor == 'P' && drugiWybor == 'N'){
						if (pierwszyGracz == 'c')
							przegranaC +=1;
						else if (drugiGracz == 'c')
							wygranaC += 1;}
					else if (pierwszyWybor == 'K' && drugiWybor == 'P'){
						if (pierwszyGracz == 'c')
							przegranaC +=1;
						else if (drugiGracz == 'c')
							wygranaC += 1;}
					else if (pierwszyWybor == 'S' && drugiWybor == 'P'){
						if (pierwszyGracz == 'c')
							przegranaC +=1;
						else if (drugiGracz == 'c')
							wygranaC += 1;}
					else if (pierwszyWybor == 'K' && drugiWybor == 'S'){
						if (pierwszyGracz == 'c')
							przegranaC +=1;
						else if (drugiGracz == 'c')
							wygranaC += 1;}
					else if (pierwszyWybor == 'N' && drugiWybor == 'S'){
						if (pierwszyGracz == 'c')
							przegranaC +=1;
						else if (drugiGracz == 'c')
							wygranaC += 1;}						
				}	
						
				else if (pierwszyWybor == drugiWybor){
					if (pierwszaSila == drugaSila)
						remisC += 1;
					if (pierwszyGracz == 'c'){
						if (pierwszaSila > drugaSila)
							wygranaC += 1;	
						else if (pierwszaSila < drugaSila)
							przegranaC += 1;	}	
				
					else if (drugiGracz == 'c'){
						if (pierwszaSila < drugaSila)
							wygranaC +=1;
						else if (pierwszaSila > drugaSila)
							przegranaC += 1;	}
				}	
			}
			
			if (pierwszyGracz == 'd' || drugiGracz == 'd'){		//warunki dla gracza D
				iloscGierD += 1;
					
				if (pierwszyWybor != drugiWybor){
					if (pierwszyWybor == 'J' && drugiWybor == 'P'){
						if (pierwszyGracz == 'd')
							wygranaD += 1;
						else if (drugiGracz == 'd')
							przegranaD +=1;}						
					else if (pierwszyWybor == 'J' && drugiWybor == 'S'){
						if (pierwszyGracz == 'd')
							wygranaD += 1;
						else if (drugiGracz == 'd')
							przegranaD +=1;}
					else if (pierwszyWybor == 'K' && drugiWybor == 'J'){
						if (pierwszyGracz == 'd')
							wygranaD += 1;
						else if (drugiGracz == 'd')
							przegranaD +=1;}				
					else if (pierwszyWybor == 'K' && drugiWybor == 'N'){
						if (pierwszyGracz == 'd')
							wygranaD += 1;
						else if (drugiGracz == 'd')
							przegranaD +=1;}						
					else if (pierwszyWybor == 'N' && drugiWybor == 'J'){
						if (pierwszyGracz == 'd')
							wygranaD += 1;
						else if (drugiGracz == 'd')
							przegranaD +=1;}						
					else if (pierwszyWybor == 'N' && drugiWybor == 'P'){
						if (pierwszyGracz == 'd')
							wygranaD += 1;
						else if (drugiGracz == 'd')
							przegranaD +=1;}						
					else if (pierwszyWybor == 'P' && drugiWybor == 'K'){
						if (pierwszyGracz == 'd')
							wygranaD += 1;
						else if (drugiGracz == 'd')
							przegranaD +=1;}						
					else if (pierwszyWybor == 'P' && drugiWybor == 'S'){
						if (pierwszyGracz == 'd')
							wygranaD += 1;
						else if (drugiGracz == 'd')
							przegranaD +=1;}						
					else if (pierwszyWybor == 'S' && drugiWybor == 'K'){
						if (pierwszyGracz == 'd')
							wygranaD += 1;
						else if (drugiGracz == 'd')
							przegranaD +=1;}						
					else if (pierwszyWybor == 'S' && drugiWybor == 'N'){
						if (pierwszyGracz == 'd')
							wygranaD += 1;
						else if (drugiGracz == 'd')
							przegranaD +=1;}
					else if (pierwszyWybor == 'P' && drugiWybor == 'N'){
						if (pierwszyGracz == 'd')
							przegranaD +=1;
						else if (drugiGracz == 'd')
							wygranaD += 1;}	
							
					else if (pierwszyWybor == 'P' && drugiWybor == 'J'){
						if (pierwszyGracz == 'd')
							przegranaD +=1;
						else if (drugiGracz == 'd')
							wygranaD += 1;}		
					else if (pierwszyWybor == 'S' && drugiWybor == 'J'){
						if (pierwszyGracz == 'd')
							przegranaD +=1;
						else if (drugiGracz == 'd')
							wygranaD += 1;}
					else if (pierwszyWybor == 'J' && drugiWybor == 'K'){
						if (pierwszyGracz == 'd')
							przegranaD +=1;
						else if (drugiGracz == 'd')
							wygranaD += 1;}
					else if (pierwszyWybor == 'N' && drugiWybor == 'K'){
						if (pierwszyGracz == 'd')
							przegranaD +=1;
						else if (drugiGracz == 'd')
							wygranaD += 1;}
					else if (pierwszyWybor == 'J' && drugiWybor == 'N'){
						if (pierwszyGracz == 'd')
							przegranaD +=1;
						else if (drugiGracz == 'd')
							wygranaD += 1;}
					else if (pierwszyWybor == 'P' && drugiWybor == 'N'){
						if (pierwszyGracz == 'd')
							przegranaD +=1;
						else if (drugiGracz == 'd')
							wygranaD += 1;}
					else if (pierwszyWybor == 'K' && drugiWybor == 'P'){
						if (pierwszyGracz == 'd')
							przegranaD +=1;
						else if (drugiGracz == 'd')
							wygranaD += 1;}
					else if (pierwszyWybor == 'S' && drugiWybor == 'P'){
						if (pierwszyGracz == 'd')
							przegranaD +=1;
						else if (drugiGracz == 'd')
							wygranaD += 1;}
					else if (pierwszyWybor == 'K' && drugiWybor == 'S'){
						if (pierwszyGracz == 'd')
							przegranaD +=1;
						else if (drugiGracz == 'd')
							wygranaD += 1;}
					else if (pierwszyWybor == 'N' && drugiWybor == 'S'){
						if (pierwszyGracz == 'd')
							przegranaD +=1;
						else if (drugiGracz == 'd')
							wygranaD += 1;}						
				}
				
				else if (pierwszyWybor == drugiWybor){
					if (pierwszaSila == drugaSila)
						remisD += 1;
					if (pierwszyGracz == 'd'){
						if (pierwszaSila > drugaSila)
							wygranaD += 1;	
						else if (pierwszaSila < drugaSila)
							przegranaD += 1;	}	
				
					else if (drugiGracz == 'd'){
						if (pierwszaSila < drugaSila)
							wygranaD +=1;
						else if (pierwszaSila > drugaSila)
							przegranaD += 1;	}
				}	
			}
			
			liczbaRozgrywek -= 1;
		}
		
		if (iloscGierA != 0){		//warunki jakie wyniki wypisac dla gracza A
			cout << "gracz a" << endl;
			if (wygranaA != 0){
				wygrana = ((wygranaA / iloscGierA) * 100);				//obliczanie procentowej wartosci wygranych
				cout << "	wygrane: " << wygrana << "%" << endl;	}
			if (remisA != 0){
				remis = ((remisA / iloscGierA) * 100);					//obliczanie procentowej wartosci remisow
				cout << "	remisy: " << remis << "%" << endl;	}
			if (przegranaA != 0){
				przegrana = ((przegranaA / iloscGierA) * 100);			//obliczanie procentowej wartosci przegranych
				cout << "	przegrane: " << przegrana << "%" << endl;	}
			cout << endl;
		}
		if (iloscGierB != 0){		//warunki jakie wyniki wypisac dla gracza B
			cout << "gracz b" << endl;
			if (wygranaB != 0){
				wygrana = 0;
				wygrana = ((wygranaB / iloscGierB) * 100);				//obliczanie procentowej wartosci wygranych
				cout << "	wygrane: " << wygrana << "%" << endl;	}
			if (remisB != 0){
				remis = 0;
				remis = ((remisB / iloscGierB) * 100);					//obliczanie procentowej wartosci remisow
				cout << "	remisy: " << remis << "%" << endl;	}
			if (przegranaB != 0){
				przegrana = 0;
				przegrana = ((przegranaB / iloscGierB) * 100);			//obliczanie procentowej wartosci przegranych
				cout << "	przegrane: " << przegrana << "%" << endl;	}
			cout << endl;
		}
		if (iloscGierC != 0){		//warunki jakie wyniki wypisac dla gracza C
			cout << "gracz c" << endl;
			if (wygranaC != 0){
				wygrana = 0;
				wygrana = ((wygranaC / iloscGierC) * 100);				//obliczanie procentowej wartosci wygranych
				cout << "	wygrane: " << wygrana << "%" << endl;	}
			if (remisC != 0){
				remis = 0;
				remis = ((remisC / iloscGierC) * 100);					//obliczanie procentowej wartosci remisow
				cout << "	remisy: " << remis << "%" << endl;	}
			if (przegranaC != 0){
				przegrana = 0;
				przegrana = ((przegranaC / iloscGierC) * 100);			//obliczanie procentowej wartosci przegranych
				cout << "	przegrane: " << przegrana << "%" << endl;	}
			cout << endl;
		}
		if (iloscGierD != 0){		//warunki jakie wyniki wypisac dla gracza D
			cout << "gracz d" << endl;
			if (wygranaD != 0){
				wygrana = 0;
				wygrana = ((wygranaD / iloscGierD) * 100);				//obliczanie procentowej wartosci wygranych
				cout << "	wygrane: " << wygrana << "%" << endl;	}
			if (remisD != 0){
				remis = 0;
				remis = ((remisD / iloscGierD) * 100);					//obliczanie procentowej wartosci remisow
				cout << "	remisy: " << remis << "%" << endl;	}
			if (przegranaD != 0){
				przegrana = 0;
				przegrana = ((przegranaD / iloscGierD) * 100);			//obliczanie procentowej wartosci przegranych
				cout << "	przegrane: " << przegrana << "%" << endl;	}
			cout << endl;
		}
		
	}
	
	return 0;
}
