#include "dna.hpp"

Dna::Dna(){
    this->kromozomSayisi = 0;
    this->ilkKromozom = nullptr;
    this->sonKromozom = nullptr;
}

Dna::~Dna(){
    std::cout << "\nDna yikicisi cagirildi." << std::endl;
    Kromozom* silinecek;
    while (this->ilkKromozom != nullptr)
    {
        silinecek = ilkKromozom;
        this->ilkKromozom = this->ilkKromozom->getSonrakiKromozom();
        delete silinecek;
    }
}

void Dna::kromozomEkle(Kromozom* yeniKromozom){
    if (this->ilkKromozom == nullptr ) {
        this->ilkKromozom = yeniKromozom;   
        this->sonKromozom = yeniKromozom;
    }
    else{
        this->sonKromozom->setSonrakiKromozom(yeniKromozom);
        this->sonKromozom = yeniKromozom;
    }
    this->kromozomSayisi++;
}

int Dna::getKromozomSayisi(){
    return this->kromozomSayisi;
}

Kromozom* Dna::getIlkKromozom(){
    return this->ilkKromozom;
}

Kromozom* Dna::getSonKromozom(){
    return sonKromozom;
}




// void Dna::kromozomCikar(){

// }

// void Dna::kromozomCikar(int){

// }