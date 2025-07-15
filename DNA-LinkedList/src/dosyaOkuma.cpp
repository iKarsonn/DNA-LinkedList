#include "dosyaOkuma.hpp"
#include <algorithm>  // std::all_of için gerekli başlık

DosyaOkuma::DosyaOkuma(){

}

DosyaOkuma::~DosyaOkuma(){
    //std::cout << "\nDosyaOkuma yikicisi cagirildi.";

}

void DosyaOkuma::okuDosya(char* dosyaYolu, Dna* dna) {
    std::ifstream dosya(dosyaYolu);

    if (!dosya) {
        std::cerr << "Dosya acilamadi: " << dosyaYolu << std::endl;
        return;
    }

    std::string satir;
    while (getline(dosya, satir)) {
        // Satır boşsa geç
        if (satir.empty()) {
            continue;
        }
        if (std::all_of(satir.begin(), satir.end(), ::isspace)) {
            continue;  // Satır sadece boşluk karakterlerinden oluşuyorsa geç
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
