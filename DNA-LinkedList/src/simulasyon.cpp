#include "simulasyon.hpp"

Simulasyon::Simulasyon(){
    this->dna = new Dna();
}

Simulasyon::~Simulasyon(){
    //std::cout << "\nSimulasyon yikicisi cagirildi.";
    delete this->dna;
}


//Bu metod olusan kromzoomlarin genlerinin tamami ile birlikte gösterilmesini sagliyor
// void Simulasyon::ekranaBas(Dna* dna){
//     Kromozom* geciciKromozom = dna->getIlkKromozom();
//     Gen* geciciGen;
//     for (int i = 0; i < dna->getKromozomSayisi(); i++)
//     {
//         geciciGen = geciciKromozom->getIlkGen();
//         for (int i = 0; i < geciciKromozom->getGenSayisi(); i++)
//         {
//             std::cout << geciciGen->getVeri() << " ";
//             geciciGen = geciciGen->getSonrakiGen();
//         }
//         std::cout << geciciKromozom->getGenSayisi();
//         geciciKromozom = geciciKromozom->getSonrakiKromozom();
//         std::cout << std::endl;
//     }
//     //std::cout << dna->getKromozomSayisi();
//     std::cout << std::endl;
// }

void Simulasyon::caprazla(Dna* dna, int kromozomIndis1, int kromozomIndis2){
    Kromozom* kromozom1 = dna->kromozomBul(kromozomIndis1);
    Kromozom* kromozom2 = dna->kromozomBul(kromozomIndis2);
    
    if (kromozom1 == nullptr || kromozom2 == nullptr)
    {
        return;
    }

    Kromozom* yeniKromozom1 = new Kromozom();
    Kromozom* yeniKromozom2 = new Kromozom();

    for (int i = 0; i < (kromozom1->getGenSayisi() / 2); i++)
    {
        yeniKromozom1->genEkle(kromozom1->genBul(i)->getVeri());
    }//yeni ilk kromozomun ilk yarisi olusturuldu

    for (int i = 0; i < (kromozom2->getGenSayisi() / 2); i++)
    {
        yeniKromozom2->genEkle(kromozom2->genBul(i)->getVeri());
    }//yeni ikinci kromozomun ilk yarisi olusturuldu


    if ((kromozom2->getGenSayisi() % 2) != 0) //ikici kromozomun gen sayisi tek ise
    {
        int i = (kromozom2->getGenSayisi() / 2 + 1);
        for ( ; i < kromozom2->getGenSayisi(); i++)
        {
            yeniKromozom1->genEkle(kromozom2->genBul(i)->getVeri());
        }//yeni ilk kromozomun ikinci yarisi da olusturuldu
        dna->kromozomEkle(yeniKromozom1);
        
        for (int i = (kromozom1->getGenSayisi() + 1) / 2; i < kromozom1->getGenSayisi(); i++)
        {
            yeniKromozom2->genEkle(kromozom1->genBul(i)->getVeri());
        }//yeni ikinci kromozomun ikinci yarisi da olusturuldu
        dna->kromozomEkle(yeniKromozom2);
    }
    else{
        int i = kromozom2->getGenSayisi() / 2;
        for (; i < kromozom2->getGenSayisi(); i++)
        {
            yeniKromozom1->genEkle(kromozom2->genBul(i)->getVeri());
        }//yeni ilk kromozomun ikinci yarisi da olusturuldu
        dna->kromozomEkle(yeniKromozom1);
        
        for (int i = (kromozom1->getGenSayisi() + 1) / 2; i < kromozom1->getGenSayisi(); i++)
        {
            yeniKromozom2->genEkle(kromozom1->genBul(i)->getVeri());
        }//yeni ikinci kromozomun ikinci yarisi da olusturuldu
        dna->kromozomEkle(yeniKromozom2);
    }
    
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

void Simulasyon::otomatikIslemler(std::string dosyaYolu, Dna* dna){
    std::ifstream dosya(dosyaYolu);

    if (!dosya) {
        std::cerr << "Dosya acilamadi: " << dosyaYolu << std::endl;
        return;
    }

    std::string satir;
    while (getline(dosya, satir)) {
        // Satir bossa gec
        if (satir.empty()) {
            continue;
        }
        
        std::istringstream ss(satir);
        char islemTuru;
        int sayi1, sayi2;

        Kromozom* yeniKromozom = new Kromozom();
        while (ss >> islemTuru >> sayi1 >> sayi2) {
            if (islemTuru == 'C' || islemTuru == 'c') {
                caprazla(this->dna, (int)sayi1, (int)sayi2);
            }
            else if (islemTuru == 'M' || islemTuru == 'm') {
                mutasyon(this->dna, sayi1, sayi2);
            }
            else{

            }
        }
    }

    dosya.close();
}

void Simulasyon::ekranaYaz(Dna* dna){
    Kromozom* geciciKromozom = dna->getIlkKromozom();
    while (geciciKromozom != nullptr) //Tum kromozomlari dolanan dongu
    {
        if (geciciKromozom->getIlkGen() == nullptr || geciciKromozom->getSonGen() == nullptr) //Kromozom bos ise sonraki kromozoma gec
        {
            geciciKromozom = geciciKromozom->getSonrakiKromozom();
            continue;
        }
        
        char yazilacakGenVeri = geciciKromozom->getIlkGen()->getVeri(); //Ekrana yazilacak genin verisi dongu basinda ilk genin verisine esitleniyor
        Gen* geciciGen = geciciKromozom->getSonGen();
        while (geciciGen != nullptr) //Kromozomlarin tum genlerini dolanan dongu
        {       
            if (geciciGen->getVeri() < yazilacakGenVeri)
            {
                yazilacakGenVeri = geciciGen->getVeri(); //Sart saglanirsa yazilacak genin verisi bulunan genin verisine esitlenir
                break;
            }
            
            geciciGen = geciciGen->getOncekiGen(); //Sart saglanmazsa aramaya devam ediliyor
        }

        std::cout << yazilacakGenVeri << std::endl;

        geciciKromozom = geciciKromozom->getSonrakiKromozom(); //Gen bulunursa sonraki kromozoma gec
    }
    
}

void Simulasyon::simuleEt(){
    DosyaOkuma dosyaOkuma;
    dosyaOkuma.okuDosya("doc/Dna.txt", this->dna);
    system("cls");
    while (true)
    {
        std::cout << "1- Caprazlama\n";
        std::cout << "2- Mutasyon\n";
        std::cout << "3- Otomatiik Islemler\n";
        std::cout << "4- Ekrana Yaz\n";
        std::cout << "5- Cikis\n";
        
        std::string secim = "";
        std::cin >> secim;
        system("cls");
        if (secim == "1") {
            
            int kromozomIndis1 = 0;
            int kromozomIndis2 = 0;

            while (true)
            {
                std::cout << "Caprazlanacak kromozomlari girin...\n";
                std::cout << "Kromozom 1: ";
                std::cin >> kromozomIndis1;
                std::cout << std::endl;

                std::cout << "Kromozom 2: ";
                std::cin >> kromozomIndis2;
            
                if (std::cin.fail())
                {
                    std::cin.clear(); //Hata bayragini temizle
                    std::cin.ignore(INT32_MAX, '\n'); //Satirin kalanini temizle

                    std::cerr << "Lütfen tamsayi giriniz.";
                    continue;
                }
                else {
                    caprazla(this->dna, kromozomIndis1, kromozomIndis2);
                    system("cls");
                    break;
                }
            }
        }
        else if (secim == "2") {

            int kromozomIndis = 0, genIndis = 0;

            while (true)
            {
                std::cout << "Mutasyon yapilacak kromozomu girin...\n";
                std::cout << "Kromozom: ";
                std::cin >> kromozomIndis;

                std::cout << "Mutasyona ugrayacak geni girin...\n";
                std::cout << "Gen: ";
                std::cin >> genIndis;

                if (std::cin.fail())
                {
                    std::cin.clear(); //Hata bayragini temizle
                    std::cin.ignore(INT32_MAX, '\n'); //Satirin kalanini temizle

                    std::cerr << "Lütfen tamsayi giriniz.";
                    continue;
                }
                else {
                    mutasyon(this->dna, kromozomIndis, genIndis);
                    system("cls");
                    break;
                }
            }
            
        }
        else if (secim == "3") {
            otomatikIslemler("doc/Islemler.txt", this->dna);
            system("cls");
        }
        else if (secim == "4") {
            ekranaYaz(this->dna);
        }
        else if (secim == "5") {
            break;
        }
        // else if (secim == "6"){
        //     ekranaBas(this->dna);
        // }
        else {
            
        }
        
    }
 
}