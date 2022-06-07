module;

#include <iostream>
#include <string>
#include <ranges>
#include <map>
#include <memory>
#include <vector>

export module logs;

/*
import <iostream>;
import <string>;
import <ranges>;            
import <map>;
import <memory>;
import <vector>;
*/

export import include;

/**
* Klasa logow gry.
*/
export class Logs {
protected:

    std::vector<std::pair<std::string, std::string>> ruch; /*!< Wector par stringów wykonanych ruchów w rozgrwce (format europejski).  */
    std::map<std::string, int> iloscPowtorzenPozycji; /*!< Mapa stringa przechowyuj¹cy string uproszczonego zapisu pozycji oraz intereger iloœæ powtórzonych tych pozycji. */

    int iloscSzachowKrolGracza1; /*!< Intereger ile razy z rzedu by³ szachowny krol gracza1  */
    int iloscSzachowKrolGracza2; //*!< Intereger ile razy z rzedu by³ szachowny krol gracza2  */ 


public:

    /**
    * Destruktor
    */
    ~Logs() { }

    /**
    * Konstruktor bezargumentowy
    */
    Logs() :iloscSzachowKrolGracza1(0), iloscSzachowKrolGracza2(0) { }

    /**
    * Metoda ustawiajaca ilosc ile razy byl szachowany krol gracza 1.
    * @param _iloscSzachow - intereger ilosci szachow
    */
    void setIloscSzachowKrolGracza1(int _iloscSzachow) { iloscSzachowKrolGracza1 = _iloscSzachow; }

    /**
    * Metoda ustawiajaca ilosc ile razy byl szachowany krol gracza 2.
    * @param _iloscSzachow - intereger ilosci szachow
    */
    void setIloscSzachowKrolGracza2(int _iloscSzachow) { iloscSzachowKrolGracza2 = _iloscSzachow; }

    /**
    * Metoda incrementujaca o 1 ile razy byl szachowany krol gracza 1.
    */
    void incIloscSzachowKrolGracza1() { iloscSzachowKrolGracza1++; }

    /**
    * Metoda incrementujaca o 1 ile razy byl szachowany krol gracza 2.
    */
    void incIloscSzachowKrolGracza2() { iloscSzachowKrolGracza2++; }

    /**
    * Metoda zwracajaca ilosc ile razy byl szachowany krol gracza 1.
    * @return -  intereger ilosci szachow krola gracza 1.
    */
    int getIloscSzachowKrolGracza1() { return iloscSzachowKrolGracza1; }

    /**
    * Metoda zwracajaca ilosc ile razy byl szachowany krol gracza 2.
    * @return - intereger ilosci szachow krola gracza 2.
    */
    int getIloscSzachowKrolGracza2() { return iloscSzachowKrolGracza2; }

    /**
    * Metoda dodaje do vectora par wykonany ruch(stringi).
    * @param _para - para stringow
    */
    void addToRuch(std::pair<std::string, std::string> _para) { ruch.push_back(_para); }

    /**
    * Metoda zwracajaca cala historie ruchow rozgrywki ktora jest przetrzymywana w vectorze par ruchow.
    * @return - string wykonanych w rozgrywce ruchow.
    */
    std::string getAllRuch() {
        // wypisz wszystkie ruchy jakie byly 
        std::string tmp;
        for (int i = 0; i < ruch.size(); i++) {
            tmp += ruch[i].first;
            tmp += "-";
            tmp += ruch[i].second;
            tmp += "\n";
        }
        return tmp;
    }

    // zapisz figury w kolejnosci do vectota string 
    /**
    * Metoda dodajaca do mapy pozycji i jej powtórzeñ now¹ pozycjê lub dodaj¹ca iloœæ jej wystapieñ.
    * @param _zapis_gry - uproszony zapis pozycji
    */
    void addTozapis_gry(std::string _zapis_gry) {

        bool byl = false;
        for (auto& elem : iloscPowtorzenPozycji) {
            if (elem.first == _zapis_gry) {
                // jezeli juz jest to dodaj i zakoncz petle
                elem.second++;
                byl = true;
                break;
            }
        }

        // jezeli nie bylo to dodaj jako nowe
        if (!byl)
            std::pair<std::map<std::string, int>::iterator, bool> result = iloscPowtorzenPozycji.insert(std::pair<std::string, int>(_zapis_gry, 1));

    }

    /**
    * Metoda sprawdzajaca czy pozycja sie powtorzy³a sie.
    * @return Boolowska wartoœæ czy ruch pozycja sie powtrzy³a. True jezel tak ilosc pozycji powtrzy³a sie , false w innym wypadku.
    */
    bool powtrzorzenie_ruchu() {
        bool tmp = false;

        // patrzac na pare stringów RUCH z logów (tej klasy) to sprawdziæ czy siê ruch gracza nie powtórzy³
        if (ruch.size() >= 4) {
            if (ruch[ruch.size() - 1].first == ruch[ruch.size() - 3].second && ruch[ruch.size() - 1].second == ruch[ruch.size() - 3].first) {
                tmp = true;
            }
        }


        return tmp;
    }

    /**
    * Metoda sprawdcza czy jakas pozycja powtrzyla sie 4 razy z rzedu (rozgrywka konczy sie remisem).
    * @return Boolowska wartoœæ czy rozgrywka konczy sie remisem przez powtrzenie pozcji 4 razy. True jezeli tak, fasle w przeciwnym wypadku.
    */
    bool powtrzorzenie_remis() {
        bool tmp = false;

        // przegladaj caly wektor czy nie powtarzaja sie 4 razy te same pozycje
        for (auto& elem : iloscPowtorzenPozycji) {
            if (elem.second >= 4) {
                // 4 raz powtorzy³a sie pozycja
                tmp = true;
            }
        }
        return tmp;
    }
};