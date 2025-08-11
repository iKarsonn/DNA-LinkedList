#ifndef DOSYAOKUMA_HPP
#define DOSYAOKUMA_HPP
#include <fstream>
#include <sstream>
#include <string>
#include "dna.hpp"

class DosyaOkuma {
private:

public:
    DosyaOkuma();
    ~DosyaOkuma();

    void okuDosya(std::string, Dna*);

};

#endif