#ifndef KROMOZOM_HPP
#define KROMOZOM_HPP
#include "gen.hpp"

class Kromozom {
private:
    int genSayisi;
    Gen* ilkGen;
    Gen* sonGen;

public:
    Kromozom();
    ~Kromozom();

    int getGenSayisi();
    Gen* getIlkGen();
    Gen* getSonGen();

    void genEkle(Gen*);  //Gen* ile listeye eleman ekleme
    void genEkle(char);  //veri ile listeye eleman ekleme
    // void genCikar(int);  //Indisle eleman cikarma

};

#endif