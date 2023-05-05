#pragma once

//tip de data generic (pentru moment este intreg)
typedef int TElem;

//referire a clasei Iterator necesara folosirii instantelor de tip Iterator
//in definitia clasei Colectie inainte de definitia propriu-zisa a clasei Iterator
class IteratorLI;


//referire a clasei Nod

class Nod;



//se defineste tipul PNod ca fiind adresa unui Nod

typedef Nod* PNod;



class Nod

{

public:

	friend class Colectie;

	//constructor

	Nod(TElem e, PNod urm);

	TElem element();

	PNod urmator();
	PNod urm;
	//seteaza informatia utila din e la noua informatie utila e_nou
	void set_e(TElem e_nou) {
		e = e_nou;
	}
private:
	TElem e;
};




class LI {
private:
	friend class IteratorLI;
	/* aici e reprezentarea */
	PNod prim;
	int d;
	
public:
	
	int eliminaDinKInK(int k);
	// constructor implicit
	LI();

	// returnare dimensiune
	int dim() const;

	// verifica daca lista e vida
	bool vida() const;

	// returnare element
	//arunca exceptie daca i nu e valid
	TElem element(int i) const;

	// modifica element de pe pozitia i si returneaza vechea valoare
	//arunca exceptie daca i nu e valid
	TElem modifica(int i, TElem e);

	// adaugare element la sfarsit
	void adaugaSfarsit(TElem e);

	// adaugare element pe o pozitie i 
	//arunca exceptie daca i nu e valid
	void adauga(int i, TElem e);

	// sterge element de pe o pozitie i si returneaza elementul sters
	//arunca exceptie daca i nu e valid
	TElem sterge(int i);

	// cauta element si returneaza prima pozitie pe care apare (sau -1)
	int cauta(TElem e)  const;

	// returnare iterator
	IteratorLI iterator() const;

	//destructor
	~LI();

};
