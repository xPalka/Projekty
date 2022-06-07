module;

#include <string>
#include <memory>

export module figury;
/*
import <string>;
import <memory>;
*/
export import figuryGracza;

/**
* Klasa reprezentujaca figury z shogi.
*/
export class Figura {
protected:
    Promocja s1; /*!< Czy dana figura jest promowana czy nie. */
    Gracz gracz; /*!< Do którego gracza nale¿y dana figura */
    Pole* pole; /*!< WskaŸnik do obiektu Pole na jakim znajduje siê dana figura */
    std::string znak; /*!< Jaki znak/symbol(string) reprezentuje figure */

public:

    /**
    * Destruktor
    */
    virtual ~Figura() { pole = nullptr; }

    /**
    * Konstruktor bezargumentowy
    */
    Figura() :s1(Promocja::bez_promocji), gracz(brak), pole(nullptr), znak("") {}

    /**
    * Metoda zwracaj¹ca rodzaj promocji figury
    * @return - enum class Promocja
    */
    Promocja getPromotion() { return s1; }

    /**
    * Metoda ustawiajaca rodzaj promocji figury
    * @param ss - enum class Promocja
    */
    void setPromotion(Promocja ss) { s1 = ss; }

    /**
    * Metoda zwracaj¹ca znak figury
    * @return - string
    */
    std::string getZnak() { return znak; }

    /**
    * Metoda ustawiajaca znak figury
    * @param _x - string
    */
    void setZnak(std::string _x) { znak = _x; }

    /**
    * Metoda zwracajaca do jakiego gracza nalezy figura
    * @return - enum Gracz
    */
    Gracz getGracz() { return gracz; }

    /**
    * Metoda ustawiajaca do jakiego gracza nalezy figura
    * @param _gracz - enum Gracz
    */
    void setGracz(Gracz _gracz) { gracz = _gracz; }

    /**
    * Metoda ustawiajaca nullptr do wskaznika na jakim polu znajduje sie figura.
    */
    void resetPoleFigura() { pole = nullptr; }

};

