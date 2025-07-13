#ifndef KROMOZOM_HPP
#define KROMOZOM_HPP
#include "gen.hpp"

class Kromozom {
private:
    int genSayisi;
    Gen* ilkGen;
    Gen* sonGen;

    Kromozom* sonrakiKromozom;

public:
    Kromozom();
    ~Kromozom();

    int getGenSayisi();
    Gen* getIlkGen();
    Gen* getSonGen();
    Kromozom* getSonrakiKromozom();

    
    void setIlkGen(Gen*);
    void setSonGen(Gen*);
    void setSonrakiKromozom(Kromozom*);

    void genEkle(Gen*);  //Gen* ile listeye eleman ekleme
    void genEkle(char);  //veri ile listeye eleman ekleme
    // void genCikar(int);  //Indisle eleman cikarma

};

#endif