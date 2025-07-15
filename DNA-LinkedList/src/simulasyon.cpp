#include "simulasyon.hpp"

Simulasyon::Simulasyon(){
    this->dna = new Dna();
}

Simulasyon::~Simulasyon(){
    //std::cout << "\nSimulasyon yikicisi cagirildi.";
    delete this->dna;
}

void Simulasyon::ekranaBas(Dna* dna){
    Kromozom* geciciKromozom = dna->getIlkKromozom();
    Gen* geciciGen;
    for (int i = 0; i < dna->getKromozomSayisi(); i++)
    {
        geciciGen = geciciKromozom->getIlkGen();
        for (int i = 0; i < geciciKromozom->getGenSayisi(); i++)
        {
            std::cout << geciciGen->getVeri() << " ";
            geciciGen = geciciGen->getSonrakiGen();
        }
        std::cout << geciciKromozom->getGenSayisi();
        geciciKromozom = geciciKromozom->getSonrakiKromozom();
        std::cout << std::endl;
    }
    std::cout << dna->getKromozomSayisi();
    std::cout << std::endl;
}

void Simulasyon::caprazla(Dna* dna, int kromozomIndis1, int kromozomIndis2){
    Kromozom* kromozom1 = dna->kromozomBul(kromozomIndis1);
    Kromozom* kromozom2 = dna->kromozomBul(kromozomIndis2);
    
    if (kromozom1 == nullptr || kromozom2 == nullptr)
    {
        return;
    }
    
    Kromozom* yeniKromozom1 = new Kromozom();
    //BURDA KALDINNNN!!!

}

void Simulasyon::mutasyon(Dna* dna, int kromozomIndis, int genIndis){
    Kromozom* geciciKromozom = dna->kromozomBul(kromozomIndis);
    if (geciciKromozom == nullptr)
    {
        return;
    }
    
    Gen* geciciGen = geciciKromozom->genBul(genIndis);
    if (geciciGen == nullptr)
    {
        return;
    }
    
    geciciGen->setVeri('X');
    
}

void Simulasyon::otomatikIslemler(Dna* ){

}

void Simulasyon::simuleEt(){
    DosyaOkuma dosyaOkuma;
    dosyaOkuma.okuDosya((char*)"doc/Dna.txt", this->dna);

    ekranaBas(this->dna);

    mutasyon(this->dna, 1, 1);

    ekranaBas(this->dna);
}