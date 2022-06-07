module;

#include <iostream>
#include <string>
#include <memory>

export module pole;

/*
import <iostream>;
import <string>;
import <memory>;
*/
export import figury;

/**
* Klasa pole szachownicy shogi. Klasa przechowuje informacje co na danym polu szachownicy stoi i jakie to jest pole.
*/
export class Pole {

private:
    int x; /*!< Wsp��dnie x pola */
    int y; /*!< Wsp��dnie y pola */
    std::shared_ptr<Pion> p; /*!< Wska�nik do obietku stojacej na polu figury Pion */
    std::shared_ptr<Lanca> l; /*!< Wska�nik do obietku stojacej na polu figury Lanca */
    std::shared_ptr<Skoczek> n; /*!< Wska�nik do obietku stojacej na polu figury Skoczek */
    std::shared_ptr<mGeneral> s; /*!< Wska�nik do obietku stojacej na polu figury mGeneral (srebrny general) */
    std::shared_ptr<dGeneral> g; /*!< Wska�nik do obietku stojacej na polu figury dGeneral (zloty general) */
    std::shared_ptr<Goniec> b; /*!< Wska�nik do obietku stojacej na polu figury Goniec */
    std::shared_ptr<Wieza> r; /*!< Wska�nik do obietku stojacej na polu figury Wieza */
    std::shared_ptr<Krol> k; /*!< Wska�nik do obietku stojacej na polu figury Krol */
    std::string status; /*!< D�uga/pe�na nazwa stojacej na polu figury */
    std::string status_short; /*!< Krotka nazwa/skrot stojacej na polu figury */

public:

    /**
    * Konstruktor bezargumentowy inicjujacy pole
    */
    Pole() :p(nullptr), l(nullptr), n(nullptr), s(nullptr), g(nullptr), b(nullptr), r(nullptr), k(nullptr), status(""), status_short(""), x(-1), y(-1) {}

    /**
    * Destruktor
    */
    ~Pole() {
        p = nullptr;
        l = nullptr;
        n = nullptr;
        s = nullptr;
        g = nullptr;
        b = nullptr;
        r = nullptr;
        k = nullptr;
    }

    /**
    * Metoda ustawiajaca wska�nik do obiektu figury Pion
    * @param _p - wsak�nik do obiektu kt�ry zostanie przypisany do pola
    */
    void setFigura(std::shared_ptr<Pion> _p) { p = _p; }

    /**
    * Metoda ustawiajaca wska�nik do obiektu figury Lanca
    * @param _l -  wsak�nik do obiektu kt�ry zostanie przypisany do pola
    */
    void setFigura(std::shared_ptr<Lanca> _l) { l = _l; }

    /**
    * Metoda ustawiajaca wska�nik do obiektu figury Skoczek
    * @param _n - wsak�nik do obiektu kt�ry zostanie przypisany do pola
    */
    void setFigura(std::shared_ptr<Skoczek> _n) { n = _n; }

    /**
    * Metoda ustawiajaca wska�nik do obiektu figury mGeneral
    * @param _s - wsak�nik do obiektu kt�ry zostanie przypisany do pola
    */
    void setFigura(std::shared_ptr<mGeneral> _s) { s = _s; }

    /**
    * Metoda ustawiajaca wska�nik do obiektu figury dGeneral
    * @param _g - wsak�nik do obiektu kt�ry zostanie przypisany do pola
    */
    void setFigura(std::shared_ptr<dGeneral> _g) { g = _g; }

    /**
    * Metoda ustawiajaca wska�nik do obiektu figury Goniec
    * @param _b - wsak�nik do obiektu kt�ry zostanie przypisany do pola
    */
    void setFigura(std::shared_ptr<Goniec> _b) { b = _b; }

    /**
    * Metoda ustawiajaca wska�nik do obiektu figury Wieza
    * @param _r - wsak�nik do obiektu kt�ry zostanie przypisany do pola
    */
    void setFigura(std::shared_ptr<Wieza> _r) { r = _r; }

    /**
    * Metoda ustawiajaca wska�nik do obiektu figury Krol
    * @param _k - wsak�nik do obiektu kt�ry zostanie przypisany do pola
    */
    void setFigura(std::shared_ptr<Krol> _k) { k = _k; }

    /**
    * Metoda sprawdzajaca czy dane pole jest puste
    * @return - boolowska warto�� czy pole jest puste (true) czy nie (false)
    */
    bool isEmptyPole() {
        if (status == "" && status_short == "")
            return true;
        else
            return false;
    }

    /**
    * Metoda sprawdzajaca czy na danym polu znajduje si� Pion
    * @return - wska�nik do obiektu figury Pion
    */
    std::shared_ptr<Pion> isEmptyPion() {
        if (p != nullptr) return p;
        else return nullptr;
    }

    /**
    * Metoda sprawdzajaca czy na danym polu znajduje si� Lanca.
    * @return - wska�nik do obiektu figury Lanca je�eli owy obiek znajduje si� na danym polu. Je�eli tak zwraca do niego wska�nik jezeli nie to zwraca nullptr.
    */
    std::shared_ptr<Lanca> isEmptyLanca() {
        if (l != nullptr) return l;
        else return nullptr;
    }

    /**
    * Metoda sprawdzajaca czy na danym polu znajduje si� Skoczek.
    * @return - wska�nik do obiektu figury Skoczek je�eli owy obiek znajduje si� na danym polu. Je�eli tak zwraca do niego wska�nik jezeli nie to zwraca nullptr.
    */
    std::shared_ptr<Skoczek> isEmptySkoczek() {
        if (n != nullptr) return n;
        else return nullptr;
    }

    /**
    * Metoda sprawdzajaca czy na danym polu znajduje si� mGeneral (srebrny general).
    * @return - wska�nik do obiektu figury mGeneral je�eli owy obiek znajduje si� na danym polu. Je�eli tak zwraca do niego wska�nik jezeli nie to zwraca nullptr.
    */
    std::shared_ptr<mGeneral> isEmptymGeneral() {
        if (s != nullptr) return s;
        else return nullptr;
    }

    /**
    * Metoda sprawdzajaca czy na danym polu znajduje si� dGeneral (zloty general).
    * @return - wska�nik do obiektu figury dGeneral je�eli owy obiek znajduje si� na danym polu. Je�eli tak zwraca do niego wska�nik jezeli nie to zwraca nullptr.
    */
    std::shared_ptr<dGeneral> isEmptydGeneral() {
        if (g != nullptr) return g;
        else return nullptr;
    }

    /**
    * Metoda sprawdzajaca czy na danym polu znajduje si� Goniec.
    * @return - wska�nik do obiektu figury Goniec je�eli owy obiek znajduje si� na danym polu. Je�eli tak zwraca do niego wska�nik jezeli nie to zwraca nullptr.
    */
    std::shared_ptr<Goniec> isEmptyGoniec() {
        if (b != nullptr) return b;
        else return nullptr;
    }

    /**
    * Metoda sprawdzajaca czy na danym polu znajduje si� Wieza.
    * @return - wska�nik do obiektu figury Wieza je�eli owy obiek znajduje si� na danym polu. Je�eli tak zwraca do niego wska�nik jezeli nie to zwraca nullptr.
    */
    std::shared_ptr<Wieza> isEmptyWieza() {
        if (r != nullptr) return r;
        else return nullptr;
    }

    /**
    * Metoda sprawdzajaca czy na danym polu znajduje si� Krol.
    * @return - wska�nik do obiektu figury Krol je�eli owy obiek znajduje si� na danym polu. Je�eli tak zwraca do niego wska�nik jezeli nie to zwraca nullptr.
    */
    std::shared_ptr<Krol> isEmptyKrol() {
        if (k != nullptr) return k;
        else return nullptr;
    }

    /**
    * Metoda ustawia wartosc x pola
    * @param _x - intereger kt�ry zostanie przypisany do pola jako jego x
    */
    void setx(int _x) { x = _x; }

    /**
    * Metoda ustawia wartosc y pola
    * @param _y - intereger kt�ry zostanie przypisany do pola jako jego y
    */
    void sety(int _y) { y = _y; }

    /**
    * Metoda ustawia pe�n� nazw� stoj�cej na polu figuty
    * @param s - string kt�ry zostanie przypisany do pola jako jego pa�na nazwa
    */
    void setStatusLong(std::string s) { status = s; }

    /**
    * Metoda ustawia skr�t stoj�cej na polu figuty
    * @param s - string kt�ry zostanie przypisany do pola jako jego skr�t
    */
    void setStatusShort(std::string s) { status_short = s; }

    /**
    * Metoda zwraca pe�n� nazw� stoj�cej na polu figuty
    * @return - pelna nazwe figury stojacej na danym polu
    */
    std::string getStatusLong() { return status; }

    /**
    * Metoda zwraca skr�t stoj�cej na polu figuty
    * @return - skrot figury stojacej na danym polu
    */
    std::string getStatusShort() { return status_short; }

    /**
    * Metoda zwraca wartosc x pola
    * @return - wartosc pola x
    */
    int getx() { return x; }

    /**
    * Metoda zwraca wartosc y pola
    * @return - wartosc pola y
    */
    int gety() { return y; }

    /**
    * Metoda wypisujaca do konsoli w danym miejscu na wy�wietlanej planszy figure jaka stoi na danym polu.
    * @param s - znak (figury) jaki zostanie wypisany do konsoli
    * @param g - enum Gracz, do jakiego gracza nale�y figura
    */
    void narysuj(std::string s, Gracz g);

    /**
    * Metoda odpowiadajaca za wykonanie ruchu.
    * @param pole - referencja do pole na jakie chcemy sie przesunac figura
    * @param figury - referencja do obiektu FiguryGracza kt�ra przetrzymuje informacje o stanie figur ka�dego gracza na temat zrzutki.
    * @param ruchGracza - enum Gracz, kt�ry gracz si� teraz porusza.
    * @param gra - ca�a dwuwymiarowa tablica p�l (czyli nasza szachownica na kt�rej rozgrywa si� rozgrywka).
    * @param krol_zbiry - referencja do wartosci boolowskiej czy kr�l zosta� zbity (koniec gry).
    * @param promocja_bot - pojedynczy znak okreslajacy czy jest promocja (dla silnika/bota). Znak '+' oznacz �e jest (warto�� ta zwracana jest przez slinik USI).
    * @return - boolowska warto�� czy ruch moze byc wykonany. Tak je�eli mo�e, a nie w przeciwnym wypadku.
    */
    bool wykonajRuch(Pole& pole, FiguryGracza& figury, Gracz ruchGracza, Pole** gra, bool& krol_zbiry, char promocja_bot);

    /**
    * Metoda sprawdzajaca czy na danym podanym polu znajduje si� jaka� figura.
    * @param pole - sprwadzane pole
    * @return - boolowska warto�c czy na podanym polu znajduje si� jaka� figura.
    */
    bool ifBicie(Pole pole);

    /**
    * Metoda sprawdzajaca czy dany ruch moze byc wykonany.
    * @param pole - referencja do pole na jakie chcemy sie przesunac figura
    * @param gra - ca�a dwuwymiarowa tablica p�l (czyli nasza szachownica na kt�rej rozgrywa si� rozgrywka).
    * @param promocja_bot - pojedynczy znak okreslajacy czy jest promocja (dla silnika/bota). Znak '+' oznacz �e jest (warto�� ta zwracana jest przez slinik USI).
    * @return - boolowska warto�� czy ruch moze byc wykonany. Tak je�eli mo�e, a nie w przeciwnym wypadku.
    */
    bool Ruch(Pole& pole, Pole** gra, char promocja_bot);

    /**
    * Metoda sprawdzajaca czy krol znajduje sie w szachu.
    * @param pole - ca�a dwuwymiarowa tablica p�l (czyli nasza szachownica na kt�rej rozgrywa si� rozgrywka).
    * @param gracz - enum Gracz, do jakiego gracza nale�y figura
    * @return - boolowska warto�� czy jest szach. Tak jezeli jest, nie w przeciwnym wypadku.
    */
    bool czySzach(Pole** pole, Gracz gracz);

};

