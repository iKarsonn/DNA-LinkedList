#ifndef GEN_HPP
#define GEN_HPP
#include <iostream>

class Gen {
private:
    char veri;
    Gen* sonrakiGen;
    Gen* oncekiGen;

public:
    Gen(char);
    ~Gen();

    char getVeri();
    
    Gen* getSonrakiGen();
    Gen* getOncekiGen();


    void setVeri(char);
    void setSonrakiGen(Gen*);
    void setOncekiGen(Gen*);

};

#endif