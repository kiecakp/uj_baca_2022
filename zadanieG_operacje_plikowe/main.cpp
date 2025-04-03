// Patrycja Kiecak

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct Publiczna {
	bool logiczka;
	unsigned char litera;
	float liczbaUlamkowa;
};

struct Struktura {
	int liczbaCalkowita;
	string tekst;
	string litera;
	Publiczna jeden;
	Publiczna dwa;
	Publiczna trzy;
	Publiczna cztery;
};

void SortInt (string napis, string napis1, string napis2){	//done

    fstream plikZero;
    fstream plikJeden;
    fstream plikPomocniczy;

    string sekwencja = "";
    string linia;
    int liczba;
    int liczbaKoncowa;
    bool petla = true;

	plikJeden.open(napis1.c_str(), fstream::in | fstream::out | fstream::trunc);
    plikJeden.close();
    plikPomocniczy.open(napis2.c_str(), fstream::in | fstream::out | fstream::trunc);
    plikPomocniczy.close();

    while (petla) {
        liczbaKoncowa = 999999999;
        plikZero.open(napis.c_str(), fstream::in);

        plikZero.seekp(0, fstream::end);
        if (plikZero.tellg() != 0)
            petla = true;
        else
            petla = false;

        plikZero.close();

        if (petla) {
            plikZero.open(napis.c_str(), fstream::in);

            while (true) {
                plikZero >> liczba;
                getline(plikZero, linia);

                if (plikZero.eof())
                    break;

                int i = 0;
                while (i < 6) {
                    getline(plikZero, sekwencja);
                    i++;
                }

                if (liczba < liczbaKoncowa)
                    liczbaKoncowa = liczba;
            }

            plikZero.close();

            plikZero.open(napis.c_str(), fstream::in);
            plikJeden.open(napis1.c_str(), fstream::app | fstream::out);
            plikPomocniczy.open(napis2.c_str(), fstream::out | fstream::in | fstream::trunc);

            while (true) {
                plikZero >> liczba;
                getline(plikZero, linia);

                if (plikZero.eof())
                    break;

                if (liczba == liczbaKoncowa) {
                    plikJeden << liczba;

                    int i = 0;
                    while (i < 6) {
                        getline(plikZero, sekwencja);
                        plikJeden << endl << sekwencja;
                        i++;
                    }
                    plikJeden << endl;

                } else {
                    plikPomocniczy << liczba;

                    int i = 0;
                    while (i < 6) {
                        getline(plikZero, sekwencja);
                        plikPomocniczy << endl << sekwencja;
                        i++;
                    }
                    plikPomocniczy << endl;

                }
            }
            plikZero.close();
            plikJeden.close();
            plikPomocniczy.close();

            plikZero.open(napis.c_str(), fstream::out | fstream::in | fstream::trunc);
            plikPomocniczy.open(napis2.c_str(), fstream::in);
            while (true) {
                plikPomocniczy >> liczba;
                getline(plikPomocniczy, linia);

                if (plikPomocniczy.eof())
                    break;

                plikZero << liczba;

                int i = 0;
                while (i < 6) {
                    getline(plikPomocniczy, sekwencja);
                    plikZero << endl << sekwencja;
                    i++;
                }
                plikZero << endl;

            }
            plikZero.close();
            plikPomocniczy.close();
        }
    }

    plikZero.open(napis.c_str(), fstream::out | fstream::in);
    plikJeden.open(napis1.c_str(), fstream::in);

    while (true){
        plikJeden >> liczba;
        getline(plikJeden, linia);

        if (plikJeden.eof())
            break;

        if (plikZero.tellg() != 0)
            plikZero << endl;

        plikZero << liczba;

        int i = 0;
        while (i < 6){
            getline (plikJeden, sekwencja);
            plikZero << endl << sekwencja;
            i++;
        }

    }
    plikZero.close();
    plikJeden.close();

    plikJeden.open(napis1.c_str(), fstream::in | fstream::out | fstream::trunc);
    plikJeden.close();
    plikPomocniczy.open(napis2.c_str(), fstream::in | fstream::out | fstream::trunc);
    plikPomocniczy.close();

}

void SortCount(string napis, string napis1, string napis2) {

    int liczba;
    string linia;
    string tekst;
    string litera;
    bool logicznaJeden;			// zmienne do wczytywania calej sekwencji
    bool logicznaDwa;
    bool logicznaTrzy;
    bool logicznaCztery;
    unsigned char cyfraJeden;
    unsigned char cyfraDwa;
    unsigned char cyfraTrzy;
    unsigned char cyfraCztery;
    float ulamekJeden;
    float ulamekDwa;
    float ulamekTrzy;
    float ulamekCztery;
    string sekwencja = "";

    fstream plikZero, plikJeden, plikPomocniczy;

    int liczbaChar = 0;
    int licznik = 0;
    int licznikDrugi = 0;

    bool petla = true;
    bool pierwszyRaz;
    int poprzedniInt;
    int licznikInt = 0;
    int maxLicznikInt = 0;
    int liczbaZestawowInt = 0;
    int ostatniLicznikInt = 999999999;
    int suma;
    int maxSumaAktualna;
    int poprzedniaMaxSuma;
    int maxInt;
    int poprzedniMaxInt;
    int doKopiowania;

    SortInt(napis, napis1, napis2);		//ulatwi w liczeniu ile razy powtarza sie dana liczba

    plikJeden.open(napis1.c_str(), fstream::out | fstream::trunc);
    plikJeden.close();
    plikPomocniczy.open(napis2.c_str(), fstream::out | fstream::trunc);
    plikPomocniczy.close();

    while (petla || licznik != licznikDrugi) {
        petla = false;
        pierwszyRaz = true;
        licznik = 0;
        licznikInt = 0;
        maxLicznikInt = 0;
        poprzedniMaxInt = 999999999;

        plikZero.close();
        plikZero.open(napis.c_str());
        
        while (true) {
            plikZero >> liczba;
            getline(plikZero, linia);
            
            if (plikZero.eof()) {
                break;
            }

            getline(plikZero, tekst);
            getline(plikZero, litera);

            plikZero >> logicznaJeden;
            plikZero >> liczbaChar;
            plikZero >> ulamekJeden;

            plikZero >> logicznaDwa;
            plikZero >> liczbaChar;
            plikZero >> ulamekDwa;

            plikZero >> logicznaTrzy;
            plikZero >> liczbaChar;
            plikZero >> ulamekTrzy;

            plikZero >> logicznaCztery;
            plikZero >> liczbaChar;
            plikZero >> ulamekCztery;
            getline(plikZero, linia);

            if (pierwszyRaz) {
                pierwszyRaz = false;
                licznikInt = 1;
                liczbaZestawowInt = 1;
                poprzedniInt = liczba;
            } 
			else if (poprzedniInt == liczba) {
                licznikInt++;
            } 
			else {
                if ((licznikInt < ostatniLicznikInt) && (licznikInt == maxLicznikInt)) {
                    liczbaZestawowInt++;
                }
                if ((licznikInt < ostatniLicznikInt) && (licznikInt > maxLicznikInt)) {
                    maxLicznikInt = licznikInt;
                    liczbaZestawowInt = 1;
                }
                licznikInt = 1;
                poprzedniInt = liczba;
            }
            licznik++;
        }
        if ((licznikInt < ostatniLicznikInt) && (licznikInt == maxLicznikInt)) {
            liczbaZestawowInt++;
        }
        if ((licznikInt < ostatniLicznikInt) && (licznikInt > maxLicznikInt)) {
            maxLicznikInt = licznikInt;
            liczbaZestawowInt = 1;
        }
        ostatniLicznikInt = maxLicznikInt;

        while (liczbaZestawowInt > 0) {
            licznikInt = 0;
            maxInt = 0;

            plikZero.close();
            plikZero.open(napis.c_str());
            
            while (true) {
                plikZero >> liczba;
                getline(plikZero, linia);
                
                if (plikZero.eof()) {
                    break;
                }

                getline(plikZero, tekst);
                getline(plikZero, litera);

                plikZero >> logicznaJeden;
                plikZero >> liczbaChar;
                plikZero >> ulamekJeden;

                plikZero >> logicznaDwa;
                plikZero >> liczbaChar;
                plikZero >> ulamekDwa;

                plikZero >> logicznaTrzy;
                plikZero >> liczbaChar;
                plikZero >> ulamekTrzy;

                plikZero >> logicznaCztery;
                plikZero >> liczbaChar;
                plikZero >> ulamekCztery;
                getline(plikZero, linia);

                if (poprzedniInt == liczba) {
                    licznikInt++;
                } 
				else {
                    if ((licznikInt == ostatniLicznikInt) && (poprzedniInt < poprzedniMaxInt) && (poprzedniInt > maxInt)) {
                        maxInt = poprzedniInt;
                    }
                    licznikInt = 1;
                    poprzedniInt = liczba;
                }
            }
            if ((licznikInt == ostatniLicznikInt) && (poprzedniInt < poprzedniMaxInt) && (poprzedniInt > maxInt)) {
                maxInt = poprzedniInt;
            }
            poprzedniMaxInt = maxInt;

            doKopiowania = 0;
            plikJeden.open(napis1.c_str(), fstream::in | fstream::out | fstream::trunc);

            plikZero.close();
            plikZero.open(napis.c_str());
            
            while (true) {
                plikZero >> liczba;
                getline(plikZero, linia);
                
                if (plikZero.eof()) {
                    break;
                }

                getline(plikZero, tekst);
                getline(plikZero, litera);

                plikZero >> logicznaJeden;
                plikZero >> liczbaChar;
                cyfraJeden = liczbaChar;
                plikZero >> ulamekJeden;

                plikZero >> logicznaDwa;
                plikZero >> liczbaChar;
                cyfraDwa = liczbaChar;
                plikZero >> ulamekDwa;

                plikZero >> logicznaTrzy;
                plikZero >> liczbaChar;
                cyfraTrzy = liczbaChar;
                plikZero >> ulamekTrzy;

                plikZero >> logicznaCztery;
                plikZero >> liczbaChar;
                cyfraCztery = liczbaChar;
                plikZero >> ulamekCztery;
                getline(plikZero, linia);

                if (liczba == poprzedniMaxInt) {
                    plikJeden << liczba << endl << tekst << endl << litera << endl <<
                              logicznaJeden << " " << (int) cyfraJeden << " " << ulamekJeden << endl <<
                              logicznaDwa << " " << (int) cyfraDwa << " " << ulamekDwa << endl <<
                              logicznaTrzy << " " << (int) cyfraTrzy << " " << ulamekTrzy << endl <<
                              logicznaCztery << " " << (int) cyfraCztery << " " << ulamekCztery << endl;
                    doKopiowania++;
                }
            }

            plikPomocniczy.open(napis2.c_str(), fstream::in | fstream::out | fstream::app);
            poprzedniaMaxSuma = 256;
            licznikDrugi += doKopiowania;
            
            while (doKopiowania > 0) {
                plikJeden.close();
                plikJeden.open(napis1.c_str(), fstream::in | fstream::out);

                maxSumaAktualna = -1;
                
                while (true) {
                    plikJeden >> liczba;
                    getline(plikJeden, linia);
                    
                    if (plikJeden.eof()) {
                        break;
                    }

                    getline(plikJeden, tekst);
                    getline(plikJeden, litera);

                    plikJeden >> logicznaJeden;
                    plikJeden >> liczbaChar;
                    cyfraJeden = liczbaChar;
                    plikJeden >> ulamekJeden;

                    plikJeden >> logicznaDwa;
                    plikJeden >> liczbaChar;
                    cyfraDwa = liczbaChar;
                    plikJeden >> ulamekDwa;

                    plikJeden >> logicznaTrzy;
                    plikJeden >> liczbaChar;
                    cyfraTrzy = liczbaChar;
                    plikJeden >> ulamekTrzy;

                    plikJeden >> logicznaCztery;
                    plikJeden >> liczbaChar;
                    cyfraCztery = liczbaChar;
                    plikJeden >> ulamekCztery;
                    getline(plikJeden, linia);

                    suma = (cyfraJeden + cyfraDwa + cyfraTrzy + cyfraCztery) % 256;
                    if ((suma < poprzedniaMaxSuma) && (suma > maxSumaAktualna)) {
                        maxSumaAktualna = suma;
                    }
                }

                poprzedniaMaxSuma = maxSumaAktualna;

                plikJeden.close();
                plikJeden.open(napis1.c_str(), fstream::in | fstream::out);

                while (true) {
                    plikJeden >> liczba;
                    getline(plikJeden, linia);
                    
                    if (plikJeden.eof()) {
                        break;
                    }

                    getline(plikJeden, tekst);
                    getline(plikJeden, litera);

                    plikJeden >> logicznaJeden;
                    plikJeden >> liczbaChar;
                    cyfraJeden = liczbaChar;
                    plikJeden >> ulamekJeden;

                    plikJeden >> logicznaDwa;
                    plikJeden >> liczbaChar;
                    cyfraDwa = liczbaChar;
                    plikJeden >> ulamekDwa;

                    plikJeden >> logicznaTrzy;
                    plikJeden >> liczbaChar;
                    cyfraTrzy = liczbaChar;
                    plikJeden >> ulamekTrzy;

                    plikJeden >> logicznaCztery;
                    plikJeden >> liczbaChar;
                    cyfraCztery = liczbaChar;
                    plikJeden >> ulamekCztery;
                    getline(plikJeden, linia);

                    suma = (cyfraJeden + cyfraDwa + cyfraTrzy + cyfraCztery) % 256;
                    if (suma == maxSumaAktualna) {
                        plikPomocniczy << liczba << endl << tekst << endl << litera << endl
                                       << logicznaJeden << " " << (int) cyfraJeden << " " << ulamekJeden << endl <<
                                       logicznaDwa << " " << (int) cyfraDwa << " " << ulamekDwa << endl <<
                                       logicznaTrzy << " " << (int) cyfraTrzy << " " << ulamekTrzy << endl <<
                                       logicznaCztery << " " << (int) cyfraCztery << " " << ulamekCztery << endl;
                        doKopiowania--;
                    }
                }
            }
            plikJeden.close();
            plikPomocniczy.close();
            liczbaZestawowInt--;
        }
    }
    
    plikZero.close();
    plikPomocniczy.close();
    plikZero.open(napis.c_str(), fstream::in | fstream::out | fstream::trunc);
    plikPomocniczy.open(napis2.c_str(), fstream::in | fstream::out);
    
    while (true){
        plikPomocniczy >> liczba;
        getline(plikPomocniczy, linia);

        if (plikPomocniczy.eof())
            break;

        if (plikZero.tellg() != 0)
            plikZero << endl;

        plikZero << liczba;

        int i = 0;
        while (i < 6){
            getline (plikPomocniczy, sekwencja);
            plikZero << endl << sekwencja;
            i++;
        }

    }
    plikZero.close();
    plikPomocniczy.close();
}

void SortString (string napis, string napis1, string napis2){	//done
		
	fstream plikZero;
	fstream plikJeden;
	fstream plikPomocniczy;
	
	string sekwencja = "";
	string min;
	string linia;
	string tekst;
	string tekst2;
	int liczba;
	bool petla = true;
	
	
	plikJeden.open(napis1.c_str(), fstream::in | fstream::out | fstream::trunc);
    plikJeden.close();
    plikPomocniczy.open(napis2.c_str(), fstream::in | fstream::out | fstream::trunc);
    plikPomocniczy.close();
	
	while (petla){
		min = "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz";
		plikZero.open(napis.c_str(), fstream::in);
		
		plikZero.seekp(0, fstream::end);
		if (plikZero.tellg() != 0)
			petla = true;
		else
			petla = false;
			
		plikZero.close();
			
		if (petla){
			plikZero.open(napis.c_str(), fstream::in);
			
			while (true){
				plikZero >> liczba;
				getline(plikZero, linia);
				
				if (plikZero.eof())
					break;
				
				getline (plikZero, tekst);
				
				if (tekst < min)
					min = tekst;
				
				int i = 0;
				while (i < 5){
					getline (plikZero, sekwencja);
					i++;
				}
			}
			
			plikZero.close();
			
			plikZero.open(napis.c_str(), fstream::in);
			plikJeden.open(napis1.c_str(), fstream::app | fstream::out);
			plikPomocniczy.open(napis2.c_str(), fstream::out | fstream::in | fstream::trunc);
			
			while (true){
				plikZero >> liczba;
				getline(plikZero, linia);
				
				if (plikZero.eof())
					break;
					
				getline (plikZero, tekst2);
					
				if (tekst2 == min){
                		
                	plikJeden << liczba;
                	plikJeden << endl << tekst2;
                	
					int i = 0;
					while (i < 5){
				    	getline (plikZero, sekwencja);
				    	plikJeden << endl << sekwencja;
				    	i++;
					}
					plikJeden << endl;
                	
				}
				else{	
                	plikPomocniczy << liczba;
                	plikPomocniczy << endl << tekst2;
           			
           			int i = 0;
           			while (i < 5){
				    	getline (plikZero, sekwencja);
				    	plikPomocniczy << endl << sekwencja;
				    	i++;
					}
					plikPomocniczy << endl;
					
				}
			}
			plikZero.close();
			plikJeden.close();
			plikPomocniczy.close();
			
			plikZero.open(napis.c_str(), fstream::out | fstream::in | fstream::trunc);
			plikPomocniczy.open(napis2.c_str(), fstream::in);
			while (true){
				plikPomocniczy >> liczba;
				getline(plikPomocniczy, linia);
				
				if (plikPomocniczy.eof())
					break;	
                	
                plikZero << liczba;
                
				int i = 0;
				while (i < 6){
			    	getline (plikPomocniczy, sekwencja);
			    	plikZero << endl << sekwencja;
			    	i++;
				}
				plikZero << endl;
				
			}
			plikZero.close();
			plikPomocniczy.close();
			
		}
		
	}
	
	plikZero.open(napis.c_str(), fstream::out | fstream::in);
	plikJeden.open(napis1.c_str(), fstream::in);
	
	while (true){
		plikJeden >> liczba;
		getline(plikJeden, linia);
		
		if (plikJeden.eof())
			break;
			
		if (plikZero.tellg() != 0)
            plikZero << endl;	
            
        plikZero << liczba;
        
		int i = 0;
		while (i < 6){
			getline (plikJeden, sekwencja);
			plikZero << endl << sekwencja;
			i++;
		}
			
	}
	plikZero.close();
	plikJeden.close();
	
	plikJeden.open(napis1.c_str(), fstream::in | fstream::out | fstream::trunc);
	plikJeden.close();
	plikPomocniczy.open(napis1.c_str(), fstream::in | fstream::out | fstream::trunc);
	plikPomocniczy.close();
	
}

void SymmetricDifference (string napis, string napis1, string napis2){	//done
	
	fstream plikZero;
	fstream plikJeden;
	fstream plikPomocniczy;
	
	bool roznica = false;
	
	string liniaInt1;
	string liniaString1;		//zmienne do wczytywania danych
	string liniaChar1;
	string publicznaJeden1;
	string publicznaDwa1;
	string publicznaTrzy1;
	string publicznaCztery1;
	
	string liniaInt2;
	string liniaString2;		//zmienne do zapisywania danych
	string liniaChar2;
	string publicznaJeden2;
	string publicznaDwa2;
	string publicznaTrzy2;
	string publicznaCztery2;
	
	plikJeden.open(napis1.c_str(), fstream::out | fstream::in);
	plikPomocniczy.open(napis2.c_str(), fstream::out | fstream::in | fstream::trunc);
	
	while (true) {
		
        getline(plikJeden, liniaInt1);
        
        if (plikJeden.eof())
			break;
        
        getline(plikJeden, liniaString1);
        getline(plikJeden, liniaChar1);

        getline(plikJeden, publicznaJeden1);
        getline(plikJeden, publicznaDwa1);
        getline(plikJeden, publicznaTrzy1);
        getline(plikJeden, publicznaCztery1);

        roznica = true;
        
        plikZero.open(napis.c_str(), fstream::in);
        
        while (true) {
            getline(plikZero, liniaInt2);
            
			if (plikZero.eof())
				break;
				
            getline(plikZero, liniaString2);
            getline(plikZero, liniaChar2);

            getline(plikZero, publicznaJeden2);
            getline(plikZero, publicznaDwa2);
            getline(plikZero, publicznaTrzy2);
            getline(plikZero, publicznaCztery2);

            if ((liniaInt1 == liniaInt2) && (liniaString1 == liniaString2) && (liniaChar1 == liniaChar2) && (publicznaJeden1 == publicznaJeden2) && (publicznaDwa1 == publicznaDwa2) && (publicznaTrzy1 == publicznaTrzy2) && (publicznaCztery1 == publicznaCztery2)) {
                roznica = false;
                break;
            }
        }
        
        plikZero.close();

        if (roznica) {
            plikZero.open(napis.c_str(), fstream::out | fstream::app);
            
            if (plikZero.tellg() != 0)
                plikZero << endl;
            
            plikZero << liniaInt1 << endl << liniaString1 << endl << liniaChar1 << endl << publicznaJeden1 << endl << publicznaDwa1 << endl << publicznaTrzy1 << endl << publicznaCztery1;
                
            plikZero.close();
        }
        else {
        	
            if (plikPomocniczy.tellg() != 0)
                plikPomocniczy << endl;
            
            plikPomocniczy << liniaInt1 << endl << liniaString1 << endl	<< liniaChar1 << endl << publicznaJeden1 << endl << publicznaDwa1 << endl << publicznaTrzy1 << endl << publicznaCztery1;
        }
    }

    plikJeden.close();
    plikPomocniczy.close();
    
    plikJeden.open(napis1.c_str(), fstream::out | fstream::trunc);
    plikPomocniczy.open(napis2.c_str(), fstream::in);
    
    while (true) {
        getline(plikPomocniczy, liniaInt1);
        
        if (plikPomocniczy.eof())
			break;
			
        getline(plikPomocniczy, liniaString1);
        getline(plikPomocniczy, liniaChar1);

        getline(plikPomocniczy, publicznaJeden1);
        getline(plikPomocniczy, publicznaDwa1);
        getline(plikPomocniczy, publicznaTrzy1);
        getline(plikPomocniczy, publicznaCztery1);

        if (plikJeden.tellg() != 0)
            plikJeden << endl;

        plikJeden << liniaInt1 << endl << liniaString1 << endl << liniaChar1 << endl << publicznaJeden1 << endl << publicznaDwa1 << endl << publicznaTrzy1 << endl << publicznaCztery1;
    }

    plikJeden.close();
    plikPomocniczy.close();
}
