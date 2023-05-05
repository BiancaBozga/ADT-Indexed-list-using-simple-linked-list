#include <exception>
#include <iostream>
#include "LI.h"
#include "IteratorLI.h"
#include<exception>
//initializez campurile
Nod::Nod(TElem e, PNod urm) {
	this->e = e;
	this->urm = urm;
}

TElem Nod::element() {
	return e;
}

PNod Nod::urmator() {
	return urm;
}





LI::LI() {
	//teta(1)
	//initializam primul element nu null pointer si dimensiunea listei cu 0
	prim = nullptr;
	this->d = 0;
}

int LI::dim() const {
	//teta(1)
	return d;
}


bool LI::vida() const {
	//teta(1)
	if (d == 0)
		return true;
	else if(d>0)
		return false;
}

TElem LI::element(int i) const {
	//teta(n)-n nr de eleemnete de parcurs pana la pozitia i
	//verificam daca pozitia e valida, adica daca 0<e<d-1,atlfel aruncam exceptie
	if (i < 0 || i >= d)
		throw std::exception("pozitie invalida!");
	IteratorLI it(*this);
	//setam iteratorul pe prima pozitie
	it.prim();
	//extragem elementul curent, in cazul nostru priml
	PNod curent = it.curent;
	//parcurgem toate elementele pana la pozitia i
	//elementul de la pozitia i-1 va contine referinta catre elementul de pe pozitia i
	for (int j = 0; j < i; j++) {
		
		curent = curent->urm;
	}
	//returnam informatia utila din nodul de pe pozitia i
	return curent->element();
	
}

TElem LI::modifica(int i, TElem e) {
	//teta(n)-n nr de elemenete de parcurs pana la pozitia i
	//arunca exceptie daca i nu e valid
	if (i < 0 || i >= this->dim())
		throw std::exception("pozitie invalida!");
    
	IteratorLI it(*this);
	it.prim();
	Nod* curent = it.curent;
	//parcurgem elementele pana la elementul de pe pozitia i
	for (int j = 0; j < i; j++)
		curent = curent->urm;
	TElem e_old = curent->element();//retinem informatia utila din nod inainte de modificare
	//setam informatia utila la noua informatie utila
	curent->set_e(e);
	return e_old;
	
}

void LI::adaugaSfarsit(TElem e) {
	//o(n) -n lungimea listei
	PNod q = new Nod(e, nullptr);
	//daca exista doar un element in lista
	if (this->prim == nullptr) {
		this->prim = q;
	}
	else {

		PNod curent = this->prim;
		//parcurgem toate elementele pana la ultimul
		while (curent->urm != nullptr) {
			curent = curent->urm;
		}
		//punem nodul la final
		curent->urm = q;

	}
	//crestem dimensiunea
	d++;
}

void LI::adauga(int i, TElem e) {
	//teta(1)
	PNod q = new Nod(e, nullptr);
	if (i == 0) { //daca vrem sa inseram pe prima pozitie
		q->urm = this->prim;
		prim = q;
		d++;
	}
	else {
		PNod curent = this->prim;
		int poz = 0;
		//parcurgem pana cand ajungem la pozitie-1 pt a putea adauga nodul sau pana cand iesim din lista
		while (poz < i - 1 && curent != nullptr) {
			curent = curent->urm;
			poz++;
		}
		//daca curent este null atunci am iesit din dimensiunea listei
		if (curent == nullptr) {
			throw std::exception("pozitia invalida!");
		}
		//facem legaturile
		q->urm = curent->urm;
		curent->urm = q;
		d++;
	}

	
}

TElem LI::sterge(int i) {
	//O(n)-n lungimea listei
	//arunca exceptie daca pozitia i nu e valida
	if (i < 0 || i >= dim())
		throw std::exception("pozitie invalida!");
	IteratorLI it(*this);
	it.prim();
	Nod* curent = this->prim;
	Nod* ant = nullptr;
	TElem el = this->element(i);
	
	for (int j = 0; j < i; j++)
	{
		ant = curent;
		curent = curent->urm;
	}
	//tratam cazul daca e primul element
	//primul element nu va aveaa nimic in fata deci ant ramane null
	if (ant == nullptr) {
		prim = curent->urm;
	}
	else {
		ant->urm = curent->urm;
	}
	delete curent;
	
	d--;
	return el;
	
}

int LI::cauta(TElem e) const {
	/* de adaugat */
	int poz=0;
	TElem el;
	PNod p = this->prim;
	while (p != nullptr) {
		if (p->element() == e)
			return poz;
		p = p->urm;
		poz++;
	}
	return -1;
}

IteratorLI LI::iterator() const {
	IteratorLI iter(*this);
	 return iter;
}

int LI::eliminaDinKInK(int k) {
	//O(n^2)-n nr de elemente
	if (k <= 0)
		throw std::exception("k este invalid!");
	int nr_el = 0;
	if (this->dim() < k) {
		return nr_el;

	}
	else {
		int i = 0;
		while (i+nr_el < this->dim()-1) {
			
				if ((i +nr_el+ 1) % k == 0 && i + nr_el != 0)
				{

					this->sterge(i);
					nr_el++;
					d--;
				}
			i++;
		}
	}
	return nr_el;
}
LI::~LI() {
	
	delete[] prim;
	
}
