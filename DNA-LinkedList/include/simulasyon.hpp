#ifndef SIMULASYON_HPP
#define SIMULASYON_HPP
#include <cstdint>
#include "dosyaOkuma.hpp"
#include "dna.hpp"

class Simulasyon {
private:
    Dna* dna;

    void caprazla(Dna*, int, int);
    void mutasyon(Dna*, int, int);
    void otomatikIslemler(std::string, Dna*);
    void ekranaYaz(Dna*);
    // void ekranaBas(Dna*);

public:
    Simulasyon();
    ~Simulasyon();
    
    void simuleEt();

};

#endif