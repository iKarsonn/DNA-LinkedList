#ifndef DNA_HPP
#define DNA_HPP
#include "kromozom.hpp"

class Dna {
private:
    int kromozomSayisi;
    Kromozom* ilkKromozom;
    Kromozom* sonKromozom;

public:
    Dna();
    ~Dna();

    int getKromozomSayisi();
    Kromozom* getIlkKromozom();
    Kromozom* getSonKromozom();

    void kromozomEkle(Kromozom*);  //DNAya kromozom eklemek icin
    // void kromozomCikar();  //Sondan kromozom cikarmak icin
    // void kromozomCikar(int);  //indis ile cikarmak icin

};

#endif