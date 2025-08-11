#include <iostream>
#include "simulasyon.hpp"

int main(){

    Simulasyon* simulasyon = new Simulasyon();
    simulasyon->simuleEt();

    delete simulasyon;

    return 0;
}