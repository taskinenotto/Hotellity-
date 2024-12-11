#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>

const double HUONEEN_HINTA = 100.0;

struct Varaus {
    std::string varaajanNimi;
    int varausnumero;
    int huonenumero;
    int oidenMaara;
};

std::vector<Varaus> varaukset;

void teeVaraus() {
    Varaus uusiVaraus;
    std::cout << "Anna varaajan nimi: ";
    std::cin.ignore(); // Varmistaa, ettei syöte jää jumiin
    std::getline(std::cin, uusiVaraus.varaajanNimi);
    
    uusiVaraus.varausnumero = rand() % 90000 + 10000; // Arvotaan numero väliltä 10000-99999
    
    // Huonenumeron ja varaustilanteen tarkistus
    while (true) {
        std::cout << "Anna huonenumero (1-100): ";
        std::cin >> uusiVaraus.huonenumero;

        if (uusiVaraus.huonenumero >= 1 && uusiVaraus.huonenumero <= 100) {
            // Tarkistetaan varaustilanne
            bool huoneVarattu = false;
            for (const auto& varaus : varaukset) {
                if (varaus.huonenumero == uusiVaraus.huonenumero) {
                    huoneVarattu = true;
                    break;
                }
            }
            if (huoneVarattu) {
                std::cout << "Virhe: Huone " << uusiVaraus.huonenumero 
                          << " on jo varattu. Valitse toinen huone.\n";
            } else {
                break; // Huone on vapaa
            }
        } else {
            std::cout << "Virhe: Huonenumero voi olla vain väliltä 1-100. Yritä uudelleen.\n";
        }
    }
    
    std::cout << "Anna öiden määrä: ";
    std::cin >> uusiVaraus.oidenMaara;
    
    varaukset.push_back(uusiVaraus);
    std::cout << "Varaus tehty! Varausnumero: " << uusiVaraus.varausnumero << std::endl;
}

void haeVarauksia() {
    std::string haettuNimi;
    std::cout << "Anna varaajan nimi: ";
    std::cin.ignore(); // Varmistaa oikean syötteen
    std::getline(std::cin, haettuNimi);

    bool loytyi = false;
    for (const auto& varaus : varaukset) {
        if (varaus.varaajanNimi == haettuNimi) {
            std::cout << "Löytyi varaus! Varausnumero: " << varaus.varausnumero
                      << ", Huone: " << varaus.huonenumero
                      << ", Öitä: " << varaus.oidenMaara
                      << ", Hinta: " << varaus.oidenMaara * HUONEEN_HINTA << " euroa.\n";
            loytyi = true;
        }
    }

    if (!loytyi) {
        std::cout << "Varausta ei löytynyt.\n";
    }
}

int main() {
    srand(static_cast<unsigned>(time(0))); // Asetetaan satunnaislukujen siemen
    
    while (true) {
        std::cout << "1. Tee varaus\n";
        std::cout << "2. Hae varauksia\n";
        std::cout << "3. Lopeta\n";
        std::cout << "Valitse toiminto: ";
        
        int valinta;
        std::cin >> valinta;
        
        switch (valinta) {
            case 1:
                teeVaraus();
                break;
            case 2:
                haeVarauksia();
                break;
            case 3:
                std::cout << "Ohjelma lopetetaan.\n";
                return 0;
            default:
                std::cout << "Virheellinen valinta.\n";
                break;
        }
    }

    return 0; // Lopuksi päätetään ohjelma
}