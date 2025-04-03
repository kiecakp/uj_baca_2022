// Patrycja Kiecak

#include <iostream>
using namespace std;

/*
struct NODE_STRUCT {
	OBJECT_TYPE* object;
	BYTE use;
	NODE_STRUCT* next;
};
*/

// Dzialania obslugi pamieci

NODE_STRUCT* NewNode (){
	NODE_STRUCT* newNode = new NODE_STRUCT;
	OBJECT_TYPE* newObject = new OBJECT_TYPE [SIZE];
	newNode -> object = newObject;
	newNode -> use = 0;
	newNode -> next = NULL;
	return newNode;
}

void DeleteNode ( NODE_STRUCT* node ){
	delete [] node -> object;
	delete node;
}

void Clear ( NODE_STRUCT** nodeList ){
	NODE_STRUCT* magazyn;	//zmienna do przechowywania usuwanej czesci
		
	while (*nodeList != NULL){
		magazyn = (*nodeList) -> next;
		DeleteNode (*nodeList);
		*nodeList = magazyn;
	}
}

// Dzialania dodajace obiekty

void AddFirst ( NODE_STRUCT** nodeList, OBJECT_TYPE* tablica){
	if (*nodeList == NULL)
		*nodeList = NewNode();
		
	NODE_STRUCT* magazyn;
	magazyn = *nodeList;
	
	if (magazyn -> use == SIZE){
		NODE_STRUCT* nowyElem = NewNode();
		nowyElem -> next = magazyn;
		*(nowyElem -> object) = *tablica;
		nowyElem -> use += 1;
		*nodeList = nowyElem;
	}
	else {
		for (int i = (magazyn -> use) - 1; i >= 0; i--){
			*((magazyn -> object) + (i+1)) = *((magazyn -> object) + i);
		}
		*(magazyn -> object) = *tablica;
		magazyn -> use += 1;
	}
}

void AddLast ( NODE_STRUCT** nodeList, OBJECT_TYPE* tablica){	
	if (*nodeList == NULL)
		*nodeList = NewNode();
	
	NODE_STRUCT* magazyn;
	magazyn = *nodeList;
	
	while (magazyn != NULL){
		if (magazyn -> next == NULL)
			break;
		magazyn = magazyn -> next;
	}
	
	if (magazyn -> use == SIZE){
		NODE_STRUCT* nowyElem = NewNode();
		magazyn -> next = nowyElem;
		*(nowyElem -> object) = *tablica;
		nowyElem -> use += 1;
	}
	else {
		*((magazyn -> object) + (magazyn -> use)) = *tablica;
		magazyn -> use += 1;
	}
}

// Dzialania pobierajace obiekty

void GetFirst ( NODE_STRUCT* nodeList, NODE_STRUCT** wynik, BYTE* liczba){
	if (nodeList == NULL){
		*wynik = NULL;
	}
	else {
		*wynik = nodeList;
		*liczba = 0;
	}
}

void GetPrev ( NODE_STRUCT* nodeList, NODE_STRUCT* aktualNode, BYTE aktualLiczba, NODE_STRUCT** wynik, BYTE* liczba){
	if ((nodeList == NULL) || ((aktualNode == nodeList) && (aktualLiczba == 0))){
		*wynik = NULL;
	}
	else {
		NODE_STRUCT* magazyn;
		magazyn = nodeList;
	
		while (magazyn != NULL){
			if (magazyn -> next == aktualNode)
				break;
			magazyn = magazyn -> next;
		}
			
		if (aktualLiczba == 0){
			*wynik = magazyn;
			*liczba = (magazyn -> use) - 1;
		}
		else if (aktualNode -> use > aktualLiczba){
			*wynik = aktualNode;
			*liczba = aktualLiczba - 1;
		}		
	}
}

void GetNext ( NODE_STRUCT* nodeList, NODE_STRUCT* aktualNode, BYTE aktualLiczba, NODE_STRUCT** wynik, BYTE* liczba){
	if (((aktualNode -> next == NULL) && (aktualLiczba == ((aktualNode -> use) - 1))) || (nodeList == NULL)){
		*wynik = NULL;
	}
	else {
		if (((aktualNode -> use) - 1) > aktualLiczba){
			*wynik = aktualNode;
			*liczba = aktualLiczba + 1;
		}
		else if (((aktualNode -> use) - 1) == aktualLiczba){
			*wynik = aktualNode -> next;
			*liczba = 0;
		}
	}
}

void GetLast ( NODE_STRUCT* nodeList, NODE_STRUCT** wynik, BYTE* liczba){
	if (nodeList == NULL){
		*wynik = NULL;
	}
	else {
		NODE_STRUCT* magazyn;
		magazyn = nodeList;
	
		while (magazyn != NULL){
			if (magazyn -> next == NULL)
				break;
			magazyn = magazyn -> next;
		}
		
		*wynik = magazyn;
		*liczba = (magazyn -> use) - 1;
	}
}

// Dzialania wstawiajace obiekty

void InsertPrev ( NODE_STRUCT** nodeList, NODE_STRUCT* aktualNode, BYTE aktualLiczba, OBJECT_TYPE* tablica){
	// wstawia obiekt przed wskazanym obiektem
	
	if (aktualNode -> use < SIZE){
		
		for (int i = (aktualNode -> use); i > aktualLiczba; i--){
			*((aktualNode -> object) + (i)) = *((aktualNode -> object) + (i - 1));
		}
		
		*((aktualNode -> object) + (aktualLiczba)) = *tablica;
		aktualNode -> use += 1;
	}
	else if ((aktualNode -> use) == SIZE){
		if (aktualNode == *nodeList){
			if (aktualLiczba == 0){
				AddFirst (nodeList, tablica);
			}
			else {
				AddFirst (nodeList, (aktualNode -> object));
				for (int i = 0; i < (aktualLiczba - 1); i++){
					*((aktualNode -> object) + (i)) = *((aktualNode -> object) + (i + 1));
				}
				*((aktualNode -> object) + (aktualLiczba - 1)) = *tablica;
			}
		}
		else {
			if (aktualLiczba == 0){
				NODE_STRUCT* magazyn;
				magazyn = *nodeList;
				
				while (magazyn != NULL){
					if (magazyn -> next == aktualNode){
						break;
					}
					magazyn = magazyn -> next;
				}
				if ((magazyn -> use) == SIZE){
					NODE_STRUCT* nowyNode = NewNode();
					magazyn -> next = nowyNode;
					nowyNode -> next = aktualNode;
					*(nowyNode -> object) = *tablica;
					nowyNode -> use += 1;
				}
				else {
					*((magazyn -> object) + (magazyn -> use)) = *tablica;
					magazyn -> use += 1;
				}
				
			}
			else{
				NODE_STRUCT* magazyn;
				magazyn = *nodeList;
				
				while (magazyn != NULL){
					if (magazyn -> next == aktualNode){
						break;
					}
					magazyn = magazyn -> next;
				}
				if ((magazyn -> use) == SIZE){
					NODE_STRUCT* nowyNode = NewNode();
					magazyn -> next = nowyNode;
					nowyNode -> next = aktualNode;
					*(nowyNode -> object) = *(aktualNode -> object);
					nowyNode -> use += 1;
					
					for (int i = 0; i < (aktualLiczba - 1); i++){
						*((aktualNode -> object) + (i)) = *((aktualNode -> object) + (i + 1));
					}
					*((aktualNode -> object) + (aktualLiczba - 1)) = *tablica;
				}
				else {
					*((magazyn -> object) + (magazyn -> use)) = *(aktualNode -> object);
					magazyn -> use += 1;
					
					for (int i = 0; i < (aktualLiczba - 1); i++){
						*((aktualNode -> object) + (i)) = *((aktualNode -> object) + (i + 1));
					}
					*((aktualNode -> object) + (aktualLiczba - 1)) = *tablica;
				}
			}
		}
	}
}

void InsertNext ( NODE_STRUCT* nodeList, NODE_STRUCT* aktualNode, BYTE aktualLiczba, OBJECT_TYPE* tablica){
	if (aktualNode -> use < SIZE){
		for (int i = (aktualNode -> use); i > (aktualLiczba + 1); i--){
		 	*((aktualNode -> object) + (i)) = *((aktualNode -> object) + (i - 1));
		}
		 
		*((aktualNode -> object) + (aktualLiczba + 1)) = *tablica;
		aktualNode -> use += 1;
	}
	else if ((aktualNode -> use) == SIZE){
		if (aktualNode -> next == NULL){
			if (aktualLiczba == ((aktualNode -> use) - 1)){
				AddLast (&aktualNode, tablica);
			}
			else {
				AddLast (&nodeList, ((aktualNode -> object) + (aktualNode -> use - 1)));
				for (int i = (aktualNode -> use - 1); i > (aktualLiczba + 1); i--){
					*((aktualNode -> object) + (i)) = *((aktualNode -> object) + (i - 1));
				}
				*((aktualNode -> object) + (aktualLiczba + 1)) = *tablica;
			}
		}
		else {
			if (aktualLiczba == ((aktualNode -> use) - 1)){
				NODE_STRUCT* magazyn;
				magazyn = aktualNode -> next;
				
				if ((magazyn -> use) == SIZE){
					NODE_STRUCT* nowyElem = NewNode();
					aktualNode -> next = nowyElem;
					nowyElem -> next = magazyn;
					*(nowyElem -> object) = *tablica;
					nowyElem -> use += 1;
				}
				else{
					for (int i = (magazyn -> use); i > 0; i--){
		 				*((magazyn -> object) + (i)) = *((magazyn -> object) + (i - 1));
		 			}
					*(magazyn -> object) = *tablica;
					magazyn -> use += 1;
				}
			}
			else{
				NODE_STRUCT* magazyn;
				magazyn = aktualNode -> next;
				
				if ((magazyn -> use) == SIZE){
					NODE_STRUCT* nowyElem = NewNode();
					aktualNode -> next = nowyElem;
					nowyElem -> next = magazyn;
					*(nowyElem -> object) = *((aktualNode -> object) + (aktualNode -> use - 1));
					nowyElem -> use += 1;
					
					for (int i = (aktualNode -> use - 1); i > (aktualLiczba + 1); i--){
		 				*((aktualNode -> object) + (i)) = *((aktualNode -> object) + (i - 1));
		 			}
		 			
		 			*((aktualNode -> object) + (aktualLiczba + 1)) = *tablica;
				}
				else {
					for (int i = (magazyn -> use); i > 0; i--){
		 				*((magazyn -> object) + (i)) = *((magazyn -> object) + (i - 1));
		 			}
					*(magazyn -> object) = *((aktualNode -> object) + (aktualNode -> use - 1));
					magazyn -> use += 1;
					
					for (int i = (aktualNode -> use - 1); i > (aktualLiczba + 1); i--){
		 				*((aktualNode -> object) + (i)) = *((aktualNode -> object) + (i - 1));
		 			}
		 			
		 			*((aktualNode -> object) + (aktualLiczba + 1)) = *tablica;
				}
				
			}
		}
		
	}
	
}

// Dzialania usuwajace obiekty

void RemoveFirst ( NODE_STRUCT** nodeList){
	if (*nodeList != NULL){
		for (int i = 0; i < (((*nodeList) -> use) - 1); i++){
			*(((*nodeList)->object) + i) = *(((*nodeList)->object) + (i + 1));
		}
		
		(*nodeList) -> use -= 1;
		
		if (((*nodeList) -> use) == 0){
			if ((*nodeList) -> next == NULL){
				DeleteNode (*nodeList);
				*nodeList = NULL;
			}
			else {
				NODE_STRUCT* magazyn;
			
				magazyn = (*nodeList) -> next;
				DeleteNode (*nodeList);
				*nodeList = magazyn;
			}
			
		}
	}
}

void RemoveCurrent ( NODE_STRUCT** nodeList, NODE_STRUCT* doUsuniecia, BYTE element){
	if (*nodeList != NULL){
		NODE_STRUCT* magazyn;
		magazyn = *nodeList;
	
		while (magazyn != NULL){
			if (magazyn -> next == doUsuniecia)
				break;
			magazyn = magazyn -> next;
		}
		
		for (int i = element; i < ((doUsuniecia -> use) - 1); i++){
			*((doUsuniecia -> object) + i) = *((doUsuniecia -> object) + (i + 1));
		}
		doUsuniecia -> use -= 1;
		
		if (doUsuniecia -> use == 0){
			if ((*nodeList) -> next == NULL){
				DeleteNode (doUsuniecia);
				*nodeList = NULL;
			}	
			else if (*nodeList == doUsuniecia){
				NODE_STRUCT* magazynDwa;
				magazynDwa = doUsuniecia -> next;
			
				DeleteNode (doUsuniecia);
				*nodeList = magazynDwa;
			}
			else {
				NODE_STRUCT* magazynDwa;
				magazynDwa = doUsuniecia -> next;
			
				DeleteNode (doUsuniecia);
				magazyn -> next = magazynDwa;
			}
		
			
		}
	}
	
}

void RemovePrev ( NODE_STRUCT** nodeList, NODE_STRUCT* doUsuniecia, BYTE element){
	NODE_STRUCT* magazyn;
	
	GetPrev (*nodeList, doUsuniecia, element, &magazyn, &element);
	
	if (magazyn != NULL){
		RemoveCurrent (nodeList, magazyn, element);
	}
}

void RemoveNext ( NODE_STRUCT* nodeList, NODE_STRUCT* doUsuniecia, BYTE element){
	NODE_STRUCT* magazyn;
	
	GetNext (nodeList, doUsuniecia, element, &magazyn, &element);
	
	if (magazyn != NULL){
		RemoveCurrent (&nodeList, magazyn, element);
	}
}

void RemoveLast ( NODE_STRUCT** nodeList){
	if (*nodeList != NULL){
		
		NODE_STRUCT* magazyn;
		magazyn = *nodeList;
	
		while (magazyn != NULL){
			if (magazyn -> next == NULL)
				break;
			magazyn = magazyn -> next;
		}
		magazyn -> use -= 1;
		
		if (magazyn -> use == 0){
			if ((*nodeList) -> next == NULL){
				DeleteNode (magazyn);
				*nodeList = NULL;
			}
			else {
				NODE_STRUCT* magazynDwa;
				magazynDwa = *nodeList;
	
				while (magazynDwa != NULL){
					if (magazynDwa -> next == magazyn)
						break;
					magazynDwa = magazynDwa -> next;
				}
			
				DeleteNode (magazyn);
				magazynDwa -> next = NULL;
			}
			
		}
	}
}

// Dzialania dodatkowe

void Find ( NODE_STRUCT* nodeList, OBJECT_TYPE* wyszukaj, NODE_STRUCT** wynik, BYTE* liczba){
	bool znaleziony = false;
	NODE_STRUCT* magazyn;
	magazyn = nodeList;
	
	while (magazyn != NULL){
				
		for (int i = 0; i < (magazyn -> use); i++){
			if (*((magazyn -> object) + (i)) == *wyszukaj){
				*wynik = magazyn;
				*liczba = i;
				znaleziony = true;
				break; 
			}
			else {
				*wynik = NULL;
			}
		}
			
		if (znaleziony == true){
			break;
		}
		magazyn = magazyn -> next;
	}
}

 void Compress ( NODE_STRUCT* nodeList){
 	if (nodeList != NULL){
 		NODE_STRUCT* magazyn;
 		magazyn = nodeList;
 		
 		while (magazyn != NULL){
 			if (magazyn -> use == SIZE){
 				magazyn = magazyn -> next;
			 }
			 else {
			 	NODE_STRUCT* nastepnyNode;
			 	nastepnyNode = magazyn -> next;
			 	
			 	if (nastepnyNode == NULL){
			 		return;
				 }
				 else {
				 	*((magazyn -> object) + (magazyn -> use)) = *(nastepnyNode -> object);
				 	magazyn -> use += 1;
				 	
				 	RemoveCurrent (&magazyn, nastepnyNode, 0);
				 }
			}
	 	}
	 }
 }
 
 void Reverse ( NODE_STRUCT* nodeList){
 	if (nodeList != NULL){
 		Compress (nodeList);
 		
 		NODE_STRUCT* magazyn;
 		magazyn = nodeList;
 		int temp;
 		int licznik = 0;
 		
 		while (magazyn != NULL){
 			for (int i = 0; i < ((magazyn -> use) / 2); i++){
 				temp = *((magazyn -> object) + (magazyn -> use - i - 1));
 				*((magazyn -> object) + (magazyn -> use - i - 1)) = *((magazyn -> object) + i);
 				*((magazyn -> object) + i) = temp;
			 }
 			
 			magazyn = magazyn -> next;
		 }
		 
		 magazyn = nodeList;
		 
		 while (magazyn != NULL){
			 magazyn = magazyn -> next;
			 licznik += 1;
		 }
		 
		 NODE_STRUCT* poLewej;
 		 poLewej = nodeList;
 		 NODE_STRUCT* poPrawej;
 		 poPrawej = nodeList;
 		 OBJECT_TYPE zamiennik;
		 
		 for (int i = 0; i < (licznik / 2); i++){
		 	for (int j = 0; j < i; j++){
		 		poLewej = poLewej -> next;
			 }
			 for (int k = 0; k < (licznik - i - 1); k++){
			 	poPrawej = poPrawej -> next;
			 }
			 
			 for (int j = 0; j < (poPrawej -> use); j++){
			 	zamiennik = *((poPrawej -> object) + j);
			 	*((poPrawej -> object) + j) = *((poLewej -> object) + j);
			 	*((poLewej -> object) + j) = zamiennik;
			 }
			 if ((poPrawej -> use) < (poLewej -> use)){
			 	for (int j = (poPrawej -> use); j < (poLewej -> use); j++){
			 		*((poPrawej -> object) + j) = *((poLewej -> object) + j); 
				 }
				 temp = poPrawej -> use;
				 poPrawej -> use = poLewej -> use;
				 poLewej -> use = temp;
			 }
		 } 
	 }
 }
