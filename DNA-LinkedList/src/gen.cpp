#include "gen.hpp"

Gen::Gen(char veri){
    this->veri = veri;
    this->sonrakiGen = nullptr;
    this->oncekiGen = nullptr;
}

Gen::~Gen(){
    //std::cout << "\nGen yikicisi cagirildi." << std::endl;
    this->veri = ' ';
    this->sonrakiGen = nullptr;
    this->oncekiGen = nullptr;
}

char Gen::getVeri(){
    return this->veri;
}

Gen* Gen::getSonrakiGen(){
    return this->sonrakiGen;
}

Gen* Gen::getOncekiGen(){
    return this->oncekiGen;
}

void Gen::setVeri(char yeniVeri){
    this->veri = yeniVeri;
}

void Gen::setSonrakiGen(Gen* yeniGen){
    this->sonrakiGen = yeniGen;
}

void Gen::setOncekiGen(Gen* yeniGen){
    this->oncekiGen = yeniGen;
}