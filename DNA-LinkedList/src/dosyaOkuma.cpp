#include "dosyaOkuma.hpp"

DosyaOkuma::DosyaOkuma(){

}

DosyaOkuma::~DosyaOkuma(){
    //std::cout << "\nDosyaOkuma yikicisi cagirildi.";

}

void DosyaOkuma::okuDosya(std::string dosyaYolu, Dna* dna) {
    std::ifstream dosya(dosyaYolu);

    if (!dosya) {
        std::cerr << "Dosya acilamadi: " << dosyaYolu << std::endl;
        return;
    }

    std::string satir;
    while (getline(dosya, satir)) {
        // Satır bossa gec
        if (satir.empty()) {
            continue;
        }
        
        std::istringstream ss(satir);
        char genBilgi;

        Kromozom* yeniKromozom = new Kromozom();
        while (ss >> genBilgi) {
            yeniKromozom->genEkle(genBilgi);  // Her bir genin bilgisini ekle
        }

        dna->kromozomEkle(yeniKromozom);
    }

    dosya.close();
}
