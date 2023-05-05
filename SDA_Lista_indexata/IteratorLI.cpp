#include "IteratorLI.h"
#include "LI.h"
#include <exception>

IteratorLI::IteratorLI(const LI& li) : lista(li) {
    //teta(1)
     curent = li.prim;
    
}

void IteratorLI::prim() {
    //teta(1)
    curent = lista.prim;
}

void IteratorLI::urmator() {
    //teta(1)
    if (!this->valid())
        throw std::exception("iteratorul nu e valid!");
    curent = curent->urmator();
}

bool IteratorLI::valid() const {
    //teta(1)
    return curent != nullptr;
    
}

TElem IteratorLI::element() const {
   //teta(1)
    if (!this->valid())
        throw std::exception("iteratorul nu e valid!");
    return curent->element();
}