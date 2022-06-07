module;

#include <string>
#include <regex>
#include <iostream>

export module include;

/*
import <string>;
import <regex>;
import <iostream>;
*/
export class Logs;
export class FiguryGracza;
export class Pole;
export class Figura;
export class Pion;
export class Lanca;
export class Skoczek;
export class mGeneral;
export class dGeneral;
export class Goniec;
export class Wieza;
export class Krol;

/**
* Typ enum Gracz. Do kogo nale¿y figura (gracz1, gracz2 czy brak).
*/
export enum Gracz {
    gracz1 = 1, // gracz jeden porusza siê w "górê"
    gracz2 = -1, // gracz dwa porusza siê w "dó³"
    brak = 0
};

/**
* Klasa enum Promocja. Czy figura jest bez_promocji, czy posiad³a promocje.
*/
export enum class Promocja {
    bez_promocji, //nie jest w polu promocji
    promocja //jest w polu promocji
};

/**
* Funkcja wyswietlajaca 'fikusnie' tekst w konsoli za pomoca ESC code ANSI.
* @param x - inetereger szerokosci od prawego rogu wyswietlanego tekstu
* @param y - inetereger wysokosci od prawego rogu wyswietlanego tekstu
* @param s - string wyswietlanego tekstu
* @param kolor - string po angielsku koloru wyswietlanego tesktu
*/
export void wstaw_tekst(unsigned int x, unsigned int y, std::string s, std::string kolor = "Default") {

    // \033 to ESC w ANSI 
    // \033[... to (3 korpy) ANSI SGR parameters
    std::string s2;
    if (kolor == "Default") s2 = "\033[39m";
    else if (kolor == "Red") s2 = "\033[91m";
    else if (kolor == "Dark Red") s2 = "\033[31m";
    else if (kolor == "Green") s2 = "\033[32m";
    else if (kolor == "Yellow") s2 = "\033[33m";
    else if (kolor == "Blue") s2 = "\033[94m";
    else if (kolor == "Dark Blue") s2 = "\033[94m";
    else if (kolor == "Orange") s2 = "\033[38;5;208m";
    else if (kolor == "Pink") s2 = "\033[95m";
    else if (kolor == "Black") s2 = "\033[30m";
    else s2 = "\033[97m";
    std::cout << "\033[" << y << ";" << x << "H" << s2 << s;
}
/**
* Funkcja pytajaca uzytkownia o promocje figury kiedy jest mozliwa.
* @return Promocja wybrana przez uzytkownia. Jej brak lub ze jest.
*/
export Promocja askIfPromotion() {

    std::string x;
    std::regex format_pyt("\\b[TtNn][AaIi][KkEe]\\b");
    std::regex format_TAK("\\b[Tt][Aa][Kk]\\b");

    wstaw_tekst(25, 15, "                                                        ", "Orange");
    wstaw_tekst(25, 16, "                                                        ", "Orange");
    wstaw_tekst(25, 17, "                                                        ", "Orange");
    wstaw_tekst(25, 18, "                                                        ", "Green");

    bool gut = false;
    do {
        wstaw_tekst(25, 15, "Czy chcesz wykonac promocje?", "Green");
        wstaw_tekst(25, 17, "Format 'tak/nie': ", "Green");
        wstaw_tekst(43, 17, "", "Orange");
        std::getline(std::cin, x);
        wstaw_tekst(43, 17, "                                               ", "Orange");

        if (std::regex_match(x, format_pyt)) gut = true;
        else wstaw_tekst(25, 16, "Nieprawidlowy format. Prosze podac tak/nie.", "Orange");

    } while (!gut);

    wstaw_tekst(25, 15, "                                                        ", "Orange");
    wstaw_tekst(25, 16, "                                                        ", "Orange");
    wstaw_tekst(25, 17, "                                                        ", "Orange");

    if (std::regex_match(x, format_TAK)) {
        return Promocja::promocja;
    }
    else {
        return Promocja::bez_promocji;
    }

}

export void zbicie_krola(Gracz ruchGracza);