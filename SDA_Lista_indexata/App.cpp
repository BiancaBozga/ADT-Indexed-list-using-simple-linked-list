#include <iostream>
#include "LI.h"
#include<assert.h>
#include "TestScurt.h"
#include "TestExtins.h"
void testcerinta_lab() {
    LI l;
    for (int i = 0; i <= 50; i++) {
        l.adauga(i, i);
    }
    assert(l.element(1) == 1);
    int k = 2;
    for (int i = 0; i <= 50; i++) {
        assert(l.element(i) == i);
    }
    try {
        l.eliminaDinKInK(0);
        assert(false);
    }
    catch (std::exception e) {
        assert(true);
    }
    int p=l.eliminaDinKInK(k);
    assert(l.element(0) == 0);
    assert(l.element(1) == 2);
    assert(l.element(2) == 4);
    assert(l.element(3) == 6);
    l.eliminaDinKInK(3);
    assert(l.element(0) == 0);
    assert(l.element(1) == 2);
    assert(l.element(2) == 6);
   
}
int main() {
  
   
      testAll();
      testAllExtins();
    std::cout << "Finished LI Tests!" << std::endl;
    testcerinta_lab();
    std::cout << "Finished LI lab ex test!" << std::endl;
}