module;

#include <memory>
#include <vector>
#include <string>
#include <ranges>
#include <iostream>
#include <algorithm>

export module figuryGracza;
/*
import <memory>;
import <vector>;
import <string>;
import <ranges>;
import <iostream>;
import <algorithm>;
*/
export import logs;

/**
* Klasa FiguryGracza. Klasa przechowuje informacje jakie figury gracz zdoby≥(i moøe je ponownie wystawiÊ).
*/
export class FiguryGracza {

private:
    std::vector<char> figury; /*!< Vecotr znakÛw/char ktore znajduja sie w posiadaniu gracza do ponownego wystawnienia. */
    std::shared_ptr<Pion> p[18]; /*!< Tablica wskaünikÛw do obiektow zdobytych Pion (z wielkoscia max 18 gdyz wiecej pionkow nie moze sie znalezc w rece gracza). */
    std::shared_ptr<Lanca> l[4]; /*!< Tablica wskaünikÛw do obiektow zdobytych Lanca (z wielkoscia max 4 gdyz wiecej lanc nie moze sie znalezc w rece gracza). */
    std::shared_ptr<Skoczek> n[4]; /*!< Tablica wskaünikÛw do obiektow zdobytych Skoczek (z wielkoscia max 4 gdyz wiecej skoczkÛw nie moze sie znalezc w rece gracza). */
    std::shared_ptr<mGeneral> s[4]; /*!< Tablica wskaünikÛw do obiektow zdobytych mGeneral (z wielkoscia max 4 gdyz wiecej srebrnych genera≥Ûw nie moze sie znalezc w rece gracza). */
    std::shared_ptr<dGeneral> g[4]; /*!< Tablica wskaünikÛw do obiektow zdobytych dGeneral (z wielkoscia max 4 gdyz wiecej z≥otych genera≥Ûw nie moze sie znalezc w rece gracza). */
    std::shared_ptr<Goniec> b[2]; /*!< Tablica wskaünikÛw do obiektow zdobytych Goniec (z wielkoscia max 2 gdyz wiecej goÒcÛw nie moze sie znalezc w rece gracza). */
    std::shared_ptr<Wieza> r[2]; /*!< Tablica wskaünikÛw do obiektow zdobytych Wieza (z wielkoscia max 2 gdyz wiecej wieø nie moze sie znalezc w rece gracza). */

public:

    /**
    * Destruktor
    */
    ~FiguryGracza() {
        for (int i = 0; i < 18; i++) {
            if (p[i] != nullptr)  p[i] = nullptr;
            if (i < 4) {
                if (l[i] != nullptr) l[i] = nullptr;
                if (n[i] != nullptr) n[i] = nullptr;
                if (s[i] != nullptr) s[i] = nullptr;
                if (g[i] != nullptr) g[i] = nullptr;
            }
            if (i < 2) {
                if (b[i] != nullptr) b[i] = nullptr;
                if (r[i] != nullptr)  r[i] = nullptr;
            }
        }
    }

    /**
    * Konstruktor bezargumentowy
    */
    FiguryGracza() {
        for (int i = 0; i < 18; i++)
            p[i] = nullptr;
        for (int i = 0; i < 4; i++)
            l[i] = nullptr;
        for (int i = 0; i < 4; i++)
            n[i] = nullptr;
        for (int i = 0; i < 4; i++)
            s[i] = nullptr;
        for (int i = 0; i < 4; i++)
            g[i] = nullptr;
        for (int i = 0; i < 2; i++)
            b[i] = nullptr;
        for (int i = 0; i < 2; i++)
            r[i] = nullptr;
    }

    /**
    * Metoda dodajaca Pion do figurGracza (zrzutki).
    * @param _p - wskaünik do obiektu dodawanego Pion
    */
    void dodaj(std::shared_ptr<Pion> _p) {
        for (int i = 0; i < 18; i++)
            if (p[i] == nullptr) {
                p[i] = _p;
                break;
            }
        figury.push_back('p');
    }

    /**
    * Metoda dodajaca Lanca do figurGracza (zrzutki).
    * @param _l - wskaünik do obiektu dodawanego Lanca
    */
    void dodaj(std::shared_ptr<Lanca> _l) {
        for (int i = 0; i < 4; i++)
            if (l[i] == nullptr) {
                l[i] = _l;
                break;
            }
        figury.push_back('l');
    }

    /**
    * Metoda dodajaca Skoczek do figurGracza (zrzutki).
    * @param _n - wskaünik do obiektu dodawanego Skoczek
    */
    void dodaj(std::shared_ptr<Skoczek> _n) {
        for (int i = 0; i < 4; i++)
            if (n[i] == nullptr) {
                n[i] = _n;
                break;
            }
        figury.push_back('n');
    }

    /**
    * Metoda dodajaca mGeneral do figurGracza (zrzutki).
    * @param _s - wskaünik do obiektu dodawanego mGeneral
    */
    void dodaj(std::shared_ptr<mGeneral> _s) {
        for (int i = 0; i < 4; i++)
            if (s[i] == nullptr) {
                s[i] = _s;
                break;
            }

        figury.push_back('s');
    }

    /**
    * Metoda dodajaca dGeneral do figurGracza (zrzutki).
    * @param _g - wskaünik do obiektu dodawanego dGeneral
    */
    void dodaj(std::shared_ptr<dGeneral> _g) {
        for (int i = 0; i < 4; i++)
            if (g[i] == nullptr) {
                g[i] = _g;
                break;
            }
        figury.push_back('g');
    }

    /**
    * Metoda dodajaca Goniec do figurGracza (zrzutki).
    * @param _b - wskaünik do obiektu dodawanego Goniec
    */
    void dodaj(std::shared_ptr<Goniec> _b) {
        for (int i = 0; i < 2; i++)
            if (b[i] == nullptr) {
                b[i] = _b;
                break;
            }
        figury.push_back('b');
    }

    /**
    * Metoda dodajaca Wieza do figurGracza (zrzutki).
    * @param _r - wskaünik do obiektu dodawanego Wieza
    */
    void dodaj(std::shared_ptr<Wieza> _r) {
        for (int i = 0; i < 2; i++)
            if (r[i] == nullptr) {
                r[i] = _r;
                break;
            }
        figury.push_back('r');
    }

private:

    /**
    * Metoda usuwa podany znak jezeli znajdue sie w vectorze znakÛw figur.
    * @param znak - znak usuwanej figury
    */
    void usunZvecChar(char znak) {
        auto position = std::ranges::find(figury.begin(), figury.end(), znak);
        if (position != figury.end()) {
            figury.erase(position); // usun z vec zank
        }
    }

public:

    /**
    * Metoda usuwa wskazany wskaünik obiektu piona z figuryGracza.
    * @param _p - wsakünik do obiektu Pion ktory zostanie usuniety z figurGracza.
    */
    void usun(std::shared_ptr<Pion> _p) {
        for (int i = 17; i >= 0; i--)
            if (p[i] == _p) {
                p[i] = nullptr; // ustawia to co wiezliemy z tab na nullptr
                usunZvecChar('p'); // usuwa znak z vec
            }
    }

    /**
    * Metoda usuwa wskazany wskaünik obiektu Lanca z figuryGracza.
    * @param _l - wsakünik do obiektu Lanca ktory zostanie usuniety z figurGracza.
    */
    void usun(std::shared_ptr<Lanca> _l) {
        for (int i = 3; i >= 0; i--)
            if (l[i] == _l) {
                l[i] = nullptr; // ustawia to co wiezliemy z tab na nullptr
                usunZvecChar('l'); // usuwa znak z vec
            }
    }

    /**
    * Metoda usuwa wskazany wskaünik obiektu Skoczek z figuryGracza.
    * @param _n - wsakünik do obiektu Skoczek ktory zostanie usuniety z figurGracza.
    */
    void usun(std::shared_ptr<Skoczek> _n) {
        for (int i = 3; i >= 0; i--)
            if (n[i] == _n) {
                n[i] = nullptr; // ustawia to co wiezliemy z tab na nullptr
                usunZvecChar('n'); // usuwa znak z vec
            }
    }

    /**
    * Metoda usuwa wskazany wskaünik obiektu mGeneral z figuryGracza.
    * @param _s - wsakünik do obiektu mGeneral ktory zostanie usuniety z figurGracza.
    */
    void usun(std::shared_ptr<mGeneral> _s) {
        for (int i = 3; i >= 0; i--)
            if (s[i] == _s) {
                s[i] = nullptr; // ustawia to co wiezliemy z tab na nullptr
                usunZvecChar('s'); // usuwa znak z vec
            }
    }

    /**
    * Metoda usuwa wskazany wskaünik obiektu dGeneral z figuryGracza.
    * @param _g - wsakünik do obiektu dGeneral ktory zostanie usuniety z figurGracza.
    */
    void usun(std::shared_ptr<dGeneral> _g) {
        for (int i = 3; i >= 0; i--)
            if (g[i] == _g) {
                g[i] = nullptr; // ustawia to co wiezliemy z tab na nullptr
                usunZvecChar('g'); // usuwa znak z vec
            }
    }

    /**
    * Metoda usuwa wskazany wskaünik obiektu Goniec z figuryGracza.
    * @param _b - wsakünik do obiektu Goniec ktory zostanie usuniety z figurGracza.
    */
    void usun(std::shared_ptr<Goniec> _b) {
        for (int i = 1; i >= 0; i--)
            if (b[i] == _b) {
                b[i] = nullptr; // ustawia to co wiezliemy z tab na nullptr
                usunZvecChar('b'); // usuwa znak z vec
            }
    }

    /**
    * Metoda usuwa wskazany wskaünik obiektu Wieza z figuryGracza.
    * @param _r - wsakünik do obiektu Wieza ktory zostanie usuniety z figurGracza.
    */
    void usun(std::shared_ptr<Wieza> _r) {
        for (int i = 1; i >= 0; i--)
            if (r[i] == _r) {
                r[i] = nullptr; // ustawia to co wiezliemy z tab na nullptr
                usunZvecChar('r'); // usuwa znak z vec
            }
    }

    // zwraca wskazany wskazkin obiektu figury z odpowiedniej tablicy 
    std::shared_ptr<Pion> returnPion(int i) { return p[i]; }
    std::shared_ptr<Lanca> returnLanca(int i) { return l[i]; }
    std::shared_ptr<Skoczek> returnSkoczek(int i) { return n[i]; }
    std::shared_ptr<mGeneral> returnmGeneral(int i) { return s[i]; }
    std::shared_ptr<dGeneral> returndGeneral(int i) { return g[i]; }
    std::shared_ptr<Goniec> returnGoniec(int i) { return b[i]; }
    std::shared_ptr<Wieza> returnWieza(int i) { return r[i]; }

    /**
    * Metoda zwraca ostatni dodany wskaznik do obiektu Pion z tablicy wskaünikÛw zdobytych Pion. Jeøeli tablica jest pusta(nie posiada sie PionkÛw do wystawienia) zwraca nullptr.
    * @return wskaünik do obiektu Pion jeøeli zosta≥ zdobyty i mozna go wystawiÊ. Jezeli nie zwraca nullptr.
    */
    std::shared_ptr<Pion> zwroc_Pion() {
        for (int i = 17; i >= 0; i--)
            if (p[i] != nullptr)
                return p[i];
        return nullptr;
    }

    /**
    * Metoda zwraca ostatni dodany wskaznik do obiektu Lanca z tablicy wskaünikÛw zdobytych Lanca. Jeøeli tablica jest pusta(nie posiada sie lanc do wystawienia) zwraca nullptr.
    * @return wskaünik do obiektu Lanca jeøeli zosta≥ zdobyty i mozna go wystawiÊ. Jezeli nie zwraca nullptr.
    */
    std::shared_ptr<Lanca> zwroc_Lanca() {
        for (int i = 3; i >= 0; i--)
            if (l[i] != nullptr)
                return l[i];
        return nullptr;
    }

    /**
    * Metoda zwraca ostatni dodany wskaznik do obiektu Skoczek z tablicy wskaünikÛw zdobytych Skoczek. Jeøeli tablica jest pusta(nie posiada sie skoczkow do wystawienia) zwraca nullptr.
    * @return wskaünik do obiektu Skoczek jeøeli zosta≥ zdobyty i mozna go wystawiÊ. Jezeli nie zwraca nullptr.
    */
    std::shared_ptr<Skoczek> zwroc_Skoczek() {
        for (int i = 3; i >= 0; i--)
            if (n[i] != nullptr)
                return n[i];
        return nullptr;
    }

    /**
    * Metoda zwraca ostatni dodany wskaznik do obiektu mGeneral z tablicy wskaünikÛw zdobytych mGeneral. Jeøeli tablica jest pusta(nie posiada sie srebrny genra≥Ûw do wystawienia) zwraca nullptr.
    * @return wskaünik do obiektu mGeneral jeøeli zosta≥ zdobyty i mozna go wystawiÊ. Jezeli nie zwraca nullptr.
    */
    std::shared_ptr<mGeneral> zwroc_mGeneral() {
        for (int i = 3; i >= 0; i--)
            if (s[i] != nullptr)
                return s[i];
        return nullptr;
    }

    /**
    * Metoda zwraca ostatni dodany wskaznik do obiektu dGeneral z tablicy wskaünikÛw zdobytych dGeneral. Jeøeli tablica jest pusta(nie posiada sie z≥otych genera≥Ûw do wystawienia) zwraca nullptr.
    * @return wskaünik do obiektu dGeneral jeøeli zosta≥ zdobyty i mozna go wystawiÊ. Jezeli nie zwraca nullptr.
    */
    std::shared_ptr<dGeneral> zwroc_dGeneral() {
        for (int i = 3; i >= 0; i--)
            if (g[i] != nullptr)
                return g[i];
        return nullptr;
    }

    /**
    * Metoda zwraca ostatni dodany wskaznik do obiektu Goniec z tablicy wskaünikÛw zdobytych Goniec. Jeøeli tablica jest pusta(nie posiada sie goÒcÛw do wystawienia) zwraca nullptr.
    * @return wskaünik do obiektu Goniec jeøeli zosta≥ zdobyty i mozna go wystawiÊ. Jezeli nie zwraca nullptr.
    */
    std::shared_ptr<Goniec> zwroc_Goniec() {
        for (int i = 1; i >= 0; i--)
            if (b[i] != nullptr)
                return b[i];
        return nullptr;
    }

    /**
    * Metoda zwraca ostatni dodany wskaznik do obiektu Wieza z tablicy wskaünikÛw zdobytych Wieza. Jeøeli tablica jest pusta(nie posiada sie wieø do wystawienia) zwraca nullptr.
    * @return wskaünik do obiektu Wieza jeøeli zosta≥ zdobyty i mozna go wystawiÊ. Jezeli nie zwraca nullptr.
    */
    std::shared_ptr<Wieza> zwroc_Wieza() {
        for (int i = 1; i >= 0; i--)
            if (r[i] != nullptr)
                return r[i];
        return nullptr;
    }

    /**
    * Metoda wypisuje wszystkie zdobyte przez gracza figury (dla wypisania na ekran).
    */
    void wypisz() {
        if (!figury.empty()) {
            std::cout << "|";
            std::ranges::sort(figury);
            for (auto fig : std::ranges::views::all(figury) | std::views::reverse | std::ranges::views::filter([](auto f) {return f; })) {
                std::cout << fig << "|";
            }
        }
    }

    /**
    * Metoda wypisuje wszystkie zdobyte przez gracza figury (dla zapisu do pliku).
    * @return string wszystich znakÛw zdobytych figur
    */
    std::string zapisz_figuryGracza_file() {
        std::string tmp = "";
        if (!figury.empty()) {
            for (char c : figury) {
                std::string s(1, c);
                tmp += s;
            }
        }
        return tmp;
    }

    /**
    * Metoda sprawdza podana figura znajdue sie w figurachGracza
    * @param x - znak sprawdzanej figury
    * @return Boolowska wartoúÊ czy ruch podana figura sie znajduje. True jezeli tak, false w przeciwnym wypadku.
    */
    bool sprawdzCzyFiguraJest(char x) {
        bool tmp = false;
        // sprawdzenie vectora czy it==x (szukany char jest w vec)
        for (auto vec : std::ranges::views::all(figury) | std::ranges::views::filter([x](char it) {return it == x; })) {
            tmp = true;
        }
        return tmp;
    }

    /**
    * Metoda sprawdza czy figuryGracza sπ puste.
    * @return Boolowska wartoúÊ czy ruch figuryGracza sπ puste. True jezeli tak, false w przeciwnym wypadku.
    */
    bool isEmptyFigury() { return figury.empty(); }
};
