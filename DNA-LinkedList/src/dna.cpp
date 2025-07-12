#include "dna.hpp"

Dna::Dna(){
    kromozomSayisi = 0;
    ilkKromozom = nullptr;
    sonKromozom = nullptr;
}

Dna::~Dna(){
    Kromozom* silinecek;
    while (this->ilkKromozom != nullptr)
    {
        silinecek = ilkKromozom;
        //ilkKromozom = //BURDA KALDINNNN!!!!!
    }
}

void Dna::kromozomEkle(Kromozom*){

}

void Dna::kromozomCikar(){

}

void Dna::kromozomCikar(int){

}