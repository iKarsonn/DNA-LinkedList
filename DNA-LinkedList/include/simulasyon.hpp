#ifndef SIMULASYON_HPP
#define SIMULASYON_HPP
#include "dosyaOkuma.hpp"
#include "dna.hpp"

class Simulasyon {
private:
    Dna* dna;

    
    void ekranaBas(Dna*);

public:
    Simulasyon();
    ~Simulasyon();
    
    void caprazla(Dna*, int, int);
    void mutasyon(Dna*, int, int);
    void otomatikIslemler(Dna*);

    void simuleEt();

};

#endif