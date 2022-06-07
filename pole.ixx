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
    int x; /*!< Wspó³¿êdnie x pola */
    int y; /*!< Wspó³¿êdnie y pola */
    std::shared_ptr<Pion> p; /*!< WskaŸnik do obietku stojacej na polu figury Pion */
    std::shared_ptr<Lanca> l; /*!< WskaŸnik do obietku stojacej na polu figury Lanca */
    std::shared_ptr<Skoczek> n; /*!< WskaŸnik do obietku stojacej na polu figury Skoczek */
    std::shared_ptr<mGeneral> s; /*!< WskaŸnik do obietku stojacej na polu figury mGeneral (srebrny general) */
    std::shared_ptr<dGeneral> g; /*!< WskaŸnik do obietku stojacej na polu figury dGeneral (zloty general) */
    std::shared_ptr<Goniec> b; /*!< WskaŸnik do obietku stojacej na polu figury Goniec */
    std::shared_ptr<Wieza> r; /*!< WskaŸnik do obietku stojacej na polu figury Wieza */
    std::shared_ptr<Krol> k; /*!< WskaŸnik do obietku stojacej na polu figury Krol */
    std::string status; /*!< D³uga/pe³na nazwa stojacej na polu figury */
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
    * Metoda ustawiajaca wskaŸnik do obiektu figury Pion
    * @param _p - wsakŸnik do obiektu który zostanie przypisany do pola
    */
    void setFigura(std::shared_ptr<Pion> _p) { p = _p; }

    /**
    * Metoda ustawiajaca wskaŸnik do obiektu figury Lanca
    * @param _l -  wsakŸnik do obiektu który zostanie przypisany do pola
    */
    void setFigura(std::shared_ptr<Lanca> _l) { l = _l; }

    /**
    * Metoda ustawiajaca wskaŸnik do obiektu figury Skoczek
    * @param _n - wsakŸnik do obiektu który zostanie przypisany do pola
    */
    void setFigura(std::shared_ptr<Skoczek> _n) { n = _n; }

    /**
    * Metoda ustawiajaca wskaŸnik do obiektu figury mGeneral
    * @param _s - wsakŸnik do obiektu który zostanie przypisany do pola
    */
    void setFigura(std::shared_ptr<mGeneral> _s) { s = _s; }

    /**
    * Metoda ustawiajaca wskaŸnik do obiektu figury dGeneral
    * @param _g - wsakŸnik do obiektu który zostanie przypisany do pola
    */
    void setFigura(std::shared_ptr<dGeneral> _g) { g = _g; }

    /**
    * Metoda ustawiajaca wskaŸnik do obiektu figury Goniec
    * @param _b - wsakŸnik do obiektu który zostanie przypisany do pola
    */
    void setFigura(std::shared_ptr<Goniec> _b) { b = _b; }

    /**
    * Metoda ustawiajaca wskaŸnik do obiektu figury Wieza
    * @param _r - wsakŸnik do obiektu który zostanie przypisany do pola
    */
    void setFigura(std::shared_ptr<Wieza> _r) { r = _r; }

    /**
    * Metoda ustawiajaca wskaŸnik do obiektu figury Krol
    * @param _k - wsakŸnik do obiektu który zostanie przypisany do pola
    */
    void setFigura(std::shared_ptr<Krol> _k) { k = _k; }

    /**
    * Metoda sprawdzajaca czy dane pole jest puste
    * @return - boolowska wartoœæ czy pole jest puste (true) czy nie (false)
    */
    bool isEmptyPole() {
        if (status == "" && status_short == "")
            return true;
        else
            return false;
    }

    /**
    * Metoda sprawdzajaca czy na danym polu znajduje siê Pion
    * @return - wskaŸnik do obiektu figury Pion
    */
    std::shared_ptr<Pion> isEmptyPion() {
        if (p != nullptr) return p;
        else return nullptr;
    }

    /**
    * Metoda sprawdzajaca czy na danym polu znajduje siê Lanca.
    * @return - wskaŸnik do obiektu figury Lanca je¿eli owy obiek znajduje siê na danym polu. Je¿eli tak zwraca do niego wskaŸnik jezeli nie to zwraca nullptr.
    */
    std::shared_ptr<Lanca> isEmptyLanca() {
        if (l != nullptr) return l;
        else return nullptr;
    }

    /**
    * Metoda sprawdzajaca czy na danym polu znajduje siê Skoczek.
    * @return - wskaŸnik do obiektu figury Skoczek je¿eli owy obiek znajduje siê na danym polu. Je¿eli tak zwraca do niego wskaŸnik jezeli nie to zwraca nullptr.
    */
    std::shared_ptr<Skoczek> isEmptySkoczek() {
        if (n != nullptr) return n;
        else return nullptr;
    }

    /**
    * Metoda sprawdzajaca czy na danym polu znajduje siê mGeneral (srebrny general).
    * @return - wskaŸnik do obiektu figury mGeneral je¿eli owy obiek znajduje siê na danym polu. Je¿eli tak zwraca do niego wskaŸnik jezeli nie to zwraca nullptr.
    */
    std::shared_ptr<mGeneral> isEmptymGeneral() {
        if (s != nullptr) return s;
        else return nullptr;
    }

    /**
    * Metoda sprawdzajaca czy na danym polu znajduje siê dGeneral (zloty general).
    * @return - wskaŸnik do obiektu figury dGeneral je¿eli owy obiek znajduje siê na danym polu. Je¿eli tak zwraca do niego wskaŸnik jezeli nie to zwraca nullptr.
    */
    std::shared_ptr<dGeneral> isEmptydGeneral() {
        if (g != nullptr) return g;
        else return nullptr;
    }

    /**
    * Metoda sprawdzajaca czy na danym polu znajduje siê Goniec.
    * @return - wskaŸnik do obiektu figury Goniec je¿eli owy obiek znajduje siê na danym polu. Je¿eli tak zwraca do niego wskaŸnik jezeli nie to zwraca nullptr.
    */
    std::shared_ptr<Goniec> isEmptyGoniec() {
        if (b != nullptr) return b;
        else return nullptr;
    }

    /**
    * Metoda sprawdzajaca czy na danym polu znajduje siê Wieza.
    * @return - wskaŸnik do obiektu figury Wieza je¿eli owy obiek znajduje siê na danym polu. Je¿eli tak zwraca do niego wskaŸnik jezeli nie to zwraca nullptr.
    */
    std::shared_ptr<Wieza> isEmptyWieza() {
        if (r != nullptr) return r;
        else return nullptr;
    }

    /**
    * Metoda sprawdzajaca czy na danym polu znajduje siê Krol.
    * @return - wskaŸnik do obiektu figury Krol je¿eli owy obiek znajduje siê na danym polu. Je¿eli tak zwraca do niego wskaŸnik jezeli nie to zwraca nullptr.
    */
    std::shared_ptr<Krol> isEmptyKrol() {
        if (k != nullptr) return k;
        else return nullptr;
    }

    /**
    * Metoda ustawia wartosc x pola
    * @param _x - intereger który zostanie przypisany do pola jako jego x
    */
    void setx(int _x) { x = _x; }

    /**
    * Metoda ustawia wartosc y pola
    * @param _y - intereger który zostanie przypisany do pola jako jego y
    */
    void sety(int _y) { y = _y; }

    /**
    * Metoda ustawia pe³n¹ nazwê stoj¹cej na polu figuty
    * @param s - string który zostanie przypisany do pola jako jego pa³na nazwa
    */
    void setStatusLong(std::string s) { status = s; }

    /**
    * Metoda ustawia skrót stoj¹cej na polu figuty
    * @param s - string który zostanie przypisany do pola jako jego skrót
    */
    void setStatusShort(std::string s) { status_short = s; }

    /**
    * Metoda zwraca pe³n¹ nazwê stoj¹cej na polu figuty
    * @return - pelna nazwe figury stojacej na danym polu
    */
    std::string getStatusLong() { return status; }

    /**
    * Metoda zwraca skrót stoj¹cej na polu figuty
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
    * Metoda wypisujaca do konsoli w danym miejscu na wyœwietlanej planszy figure jaka stoi na danym polu.
    * @param s - znak (figury) jaki zostanie wypisany do konsoli
    * @param g - enum Gracz, do jakiego gracza nale¿y figura
    */
    void narysuj(std::string s, Gracz g);

    /**
    * Metoda odpowiadajaca za wykonanie ruchu.
    * @param pole - referencja do pole na jakie chcemy sie przesunac figura
    * @param figury - referencja do obiektu FiguryGracza która przetrzymuje informacje o stanie figur ka¿dego gracza na temat zrzutki.
    * @param ruchGracza - enum Gracz, który gracz siê teraz porusza.
    * @param gra - ca³a dwuwymiarowa tablica pól (czyli nasza szachownica na której rozgrywa siê rozgrywka).
    * @param krol_zbiry - referencja do wartosci boolowskiej czy król zosta³ zbity (koniec gry).
    * @param promocja_bot - pojedynczy znak okreslajacy czy jest promocja (dla silnika/bota). Znak '+' oznacz ¿e jest (wartoœæ ta zwracana jest przez slinik USI).
    * @return - boolowska wartoœæ czy ruch moze byc wykonany. Tak je¿eli mo¿e, a nie w przeciwnym wypadku.
    */
    bool wykonajRuch(Pole& pole, FiguryGracza& figury, Gracz ruchGracza, Pole** gra, bool& krol_zbiry, char promocja_bot);

    /**
    * Metoda sprawdzajaca czy na danym podanym polu znajduje siê jakaœ figura.
    * @param pole - sprwadzane pole
    * @return - boolowska wartoœc czy na podanym polu znajduje siê jakaœ figura.
    */
    bool ifBicie(Pole pole);

    /**
    * Metoda sprawdzajaca czy dany ruch moze byc wykonany.
    * @param pole - referencja do pole na jakie chcemy sie przesunac figura
    * @param gra - ca³a dwuwymiarowa tablica pól (czyli nasza szachownica na której rozgrywa siê rozgrywka).
    * @param promocja_bot - pojedynczy znak okreslajacy czy jest promocja (dla silnika/bota). Znak '+' oznacz ¿e jest (wartoœæ ta zwracana jest przez slinik USI).
    * @return - boolowska wartoœæ czy ruch moze byc wykonany. Tak je¿eli mo¿e, a nie w przeciwnym wypadku.
    */
    bool Ruch(Pole& pole, Pole** gra, char promocja_bot);

    /**
    * Metoda sprawdzajaca czy krol znajduje sie w szachu.
    * @param pole - ca³a dwuwymiarowa tablica pól (czyli nasza szachownica na której rozgrywa siê rozgrywka).
    * @param gracz - enum Gracz, do jakiego gracza nale¿y figura
    * @return - boolowska wartoœæ czy jest szach. Tak jezeli jest, nie w przeciwnym wypadku.
    */
    bool czySzach(Pole** pole, Gracz gracz);

};

