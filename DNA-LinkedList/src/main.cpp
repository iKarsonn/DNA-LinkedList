#include <iostream>
#include "simulasyon.hpp"

int main(){

    // Dna* yeniDna = new Dna();

    // Kromozom* kromozom1 = new Kromozom();
    // Kromozom* kromozom2 = new Kromozom();
    // Kromozom* kromozom3 = new Kromozom();
    
    // Gen* gen1 = new Gen('a');
    // Gen* gen2 = new Gen('b');
    // Gen* gen3 = new Gen('c');
    // Gen* gen4 = new Gen('d');
    // Gen* gen5 = new Gen('e');
    // Gen* gen6 = new Gen('f');
    // Gen* gen7 = new Gen('g');
    // Gen* gen8 = new Gen('h');
    // Gen* gen9 = new Gen('j');
    // Gen* gen10 = new Gen('k');
    



    // kromozom1->genEkle(gen1);
    // kromozom1->genEkle(gen2);
    // kromozom1->genEkle(gen3);
    // kromozom1->genEkle(gen4);


    // kromozom2->genEkle(gen5);
    // kromozom2->genEkle(gen6);

    // kromozom3->genEkle(gen7);
    // kromozom3->genEkle(gen8);
    // kromozom3->genEkle(gen9);
    // kromozom3->genEkle(gen10);
    


    // yeniDna->kromozomEkle(kromozom1);
    // yeniDna->kromozomEkle(kromozom2);
    // yeniDna->kromozomEkle(kromozom3);
    
    // Kromozom* geciciKromozom = yeniDna->getIlkKromozom();
    // Gen* geciciGen;
    // for (int i = 0; i < yeniDna->getKromozomSayisi(); i++)
    // {
    //     geciciGen = geciciKromozom->getIlkGen();
    //     for (int i = 0; i < geciciKromozom->getGenSayisi(); i++)
    //     {
    //         std::cout << geciciGen->getVeri() << " ";
    //         geciciGen = geciciGen->getSonrakiGen();
    //     }
    //     geciciKromozom = geciciKromozom->getSonrakiKromozom();
    //     std::cout << std::endl;
    // }
    
    // delete yeniDna;

    Simulasyon* simulasyon = new Simulasyon();
    simulasyon->simuleEt();

    delete simulasyon;
    
    return 0;
}