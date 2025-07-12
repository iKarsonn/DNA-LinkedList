#include "gen.hpp"

Gen::Gen(char veri){
    this->veri = veri;
    this->sonraki = nullptr;
    this->onceki = nullptr;
}

Gen::~Gen(){
    this->veri = ' ';
    this->sonraki = nullptr;
    this->onceki = nullptr;
}

char Gen::getVeri(){
    return this->veri;
}

Gen* Gen::getSonraki(){
    return this->sonraki;
}

Gen* Gen::getOnceki(){
    return this->onceki;
}

void Gen::setSonraki(Gen* yeniGen){
    this->sonraki = yeniGen;
}

void Gen::setOnceki(Gen* yeniGen){
    this->onceki = yeniGen;
}