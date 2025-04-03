// Patrycja Kiecak

#include <string>
using namespace std;

string FormatujNapis (string napis, string napisJeden, string napisDwa, string napisTrzy){
	// napisJeden, napisDwa, napisTrzy to parametry przetworzen
	
	char c;
	char m;
	int n;
	int j;
	int k;
	
	string poLewej = "";
	string poPrawej = "";
	string srodek = "";
	string wynik = napis;
	
	int i = 0;
	while (i < wynik.size()){
		
		
		if (wynik[i] == '{') {
            n = wynik[i+3] - '0';
            j = i + 5;
            
            if (wynik [i + 1] == 'p'){
            	c = wynik [i + 5];
            	int k = 0;
            	while (k < n){
            		srodek += c;
            		k++;
				}
				j += 2;
			}
			
			else if (wynik [i + 1] == 'u'){
				
                while (n > 0){
                	while (wynik [j] == '{'){
                		k = 5;
						while (k > 0){
							poPrawej += wynik [j];
							k--;
						}
					}
                	n--;
                	j++;
				}
			}
			
			else if (wynik [i + 1] == 'U'){
				int nowyRozmiar = poLewej.size() - n;	//nowy rozmiar dla zmiennej poLewej zeby obejmowala pierwsze litery oprocz tych ktore maja byc usuniete
				poLewej.resize(nowyRozmiar); 	//nadanie nowego rozmiaru przez metode resizee
				i -= n;
			}
			
			else if (wynik [i + 1] == 'w'){
				if (n == 1){
					srodek += napisJeden;
				}
				else if (n == 2){
					srodek += napisDwa;
				}
				else if (n == 3){
					srodek += napisTrzy;
				}
			}
			
			else if (wynik [i + 1] == 'W'){
				m = wynik [i + 5] - '0';
				string srodekObliczeniowy = "";
				if (n == 1){
					srodekObliczeniowy += napisJeden;
				}
				else if (n == 2){
					srodekObliczeniowy += napisDwa;
				}
				else if (n == 3){
					srodekObliczeniowy += napisTrzy;
				}
	
				if (srodekObliczeniowy.size() < m){
					int roznica = m - srodekObliczeniowy.size();
					while (roznica != 0){
						srodekObliczeniowy += ' ';
						roznica--;
					}
					srodek = srodekObliczeniowy;
				}
				else if (srodekObliczeniowy.size() > m){
					int licznik = 0;
					while (licznik < m){
						srodek += srodekObliczeniowy [licznik];
						licznik++;
					}
				}
				
				j += 2;
			}

            
            while (j < wynik.size()) {
                poPrawej += wynik[j];
                j++;
            }
            wynik = poLewej + srodek + poPrawej;
            poPrawej = ""; 
			srodek = "";
        }
        if (wynik[i] != '{') {
            poLewej += wynik[i];
        }
       	else { 
           i--;
       	}
        
		i++;
	}
	
	
	return wynik;
}

string NajwiekszeSlowo (string napis){	//done
	string slowo = "";
	string slowoDrugie = "";
		
	int i = 0;
	while (i < napis.size()){
		if (napis [i] != ' '){
			slowoDrugie += napis [i];
		}
		else{
			if (slowoDrugie > slowo){
				slowo = slowoDrugie;
			}
			slowoDrugie = "";
		}
		
		if (i == (napis.size() - 1) && (slowoDrugie > slowo)) {
            slowo = slowoDrugie;
        }
        
		i++;	
	}
	
	return slowo;
}

string NormalizujNapis (string napis){	//done
	string wynik = "";
	string napis1 = "";
	
	int i = 0;
	while (napis[i] == ' '){	//wykluczenie spacji na poczatku
		i++;
	}
	
	while (i < napis.size()){		
		while ((napis[i] == ' ') && ((napis [i + 1] == ' ') || (napis [i + 1] == '.') || (napis [i + 1] == ','))){	//usuniecie spacji
			i++;
		}
		
		napis1 += napis [i];
		
		if ((i < (napis.size() - 1)) && ((napis [i] == '.') || (napis [i] == ','))){	//dodanie spacji po kropce i po przecinku
			napis1 += ' ';
		}
		
		i++;
	}
	
	int rozmiar = napis1.size();
	if (napis1 [rozmiar - 1] == ' '){	//wykluczenie spacji na koncu
		int j = 0;
		while (j < (rozmiar - 1)){
			wynik += napis1 [j];
			j++;
		}
	}
	else{
		wynik = napis1;		//wynik jak nie ma spacji na koncu
	}
	
	return wynik;
}

string UsunSlowo (string napis, int liczba){	//done
	string bezSlowa = "";
	// slowa zaczynaja sie od 1
	
	int miejsce = 0;	//zmienna do liczenia slow
	int i = 0;
	while (i < napis.size()){
		if ((napis [i] != ' ') && ((i == 0) || (napis [i - 1] == ' ') || (napis [i - 1] == '.') || (napis [i - 1] == ','))){
			miejsce ++;
		}
			
		if ((miejsce != liczba) || (napis [i] == ' ') || (napis [i] == '.') || (napis [i] == ',')){
			bezSlowa += napis [i];
		}		
		
		i++;
	}
	
	return bezSlowa;
}
