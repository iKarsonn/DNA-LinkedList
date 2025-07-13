#include "kromozom.hpp"

Kromozom::Kromozom(){
    this->genSayisi = 0;
    this->ilkGen = nullptr;
    this->sonGen = nullptr;
    this->sonrakiKromozom = nullptr;
}

Kromozom::~Kromozom(){
    std::cout << "\nKromozom yikicisi cagirildi." << std::endl;
    Gen* silinecek;
    while (ilkGen != nullptr)
    {
        silinecek = ilkGen;
        ilkGen = ilkGen->getSonrakiGen();
        delete silinecek;
    }
}

void Kromozom::genEkle(Gen* yeniGen){  //Gen* ile listeye eleman ekleme
    if (this->ilkGen == nullptr) { //liste bos ise
        this->ilkGen = yeniGen;
        this->sonGen = yeniGen;
    }
    else {  //liste bos degilse
        this->sonGen->setSonrakiGen(yeniGen);
        this->sonGen->getSonrakiGen()->setOncekiGen(sonGen);
        this->sonGen = yeniGen;
    }
    genSayisi++;
}

void Kromozom::genEkle(char veri){  //veri ile listeye eleman ekleme
    Gen* yeniGen = new Gen(veri);

    if (this->ilkGen == nullptr) { //liste bos ise
        this->ilkGen = yeniGen;
        this->sonGen = yeniGen;
    }
    else {  //liste bos degilse
        this->sonGen->setSonrakiGen(yeniGen);
        this->sonGen->getSonrakiGen()->setOncekiGen(sonGen);
        this->sonGen = yeniGen;
    }
    genSayisi++;
}

// void Kromozom::genCikar(int indis){
//     if (indis >= genSayisi || indis < 0)
//         return;
    
//     genSayisi--;
// }

int Kromozom::getGenSayisi(){
    return this->genSayisi;
}

Gen* Kromozom::getIlkGen(){
    return this->ilkGen;
}

Gen* Kromozom::getSonGen(){
    return this->sonGen;
}

Kromozom* Kromozom::getSonrakiKromozom(){
    return this->sonrakiKromozom;
}

void Kromozom::setIlkGen(Gen* yeniGen){
    this->ilkGen = yeniGen;
}

void Kromozom::setSonGen(Gen* yeniGen){
    this->sonGen = yeniGen;
}

void Kromozom::setSonrakiKromozom(Kromozom* yeniKromozom){
    this->sonrakiKromozom = yeniKromozom;
}