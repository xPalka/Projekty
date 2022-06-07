module;

#include <iostream>
#include <string>
#include <regex>
#include <fstream>
#include <filesystem>
#include <random>
#include <thread>
#include <future>

export module interfejs_urzytkowinka;

export import funkcje_ogl;


#pragma region intefejs_urzytkownika_reszta

/**
* Funkcja pytajaca uzytkownia o to czy chce sie ruszyc normlanie, zrobic zrzut, zapisac gre, lub sie poddac.
* @return string wyboru ruchu uzytkownia
*/
export std::string menu_1vs1() {
    std::string wybor;
    wstaw_tekst(25, 15, "                                                                             ", "Green");
    wstaw_tekst(25, 17, "                                                                             ", "Green");
    wstaw_tekst(25, 18, "                                                                             ", "Green");
    wstaw_tekst(25, 19, "                                                                             ", "Green");

    std::regex format_wyboru("\\b[1-4]\\b");
    do {
        wstaw_tekst(25, 15, "1 - wykonaj ruch figura                                    ", "Green");
        wstaw_tekst(25, 16, "2 - przywroc figure", "Green");
        wstaw_tekst(25, 17, "3 - zapisz rozgywke do pliku                               ", "Green");
        wstaw_tekst(25, 18, "4 - poddaj sie/powrot do menu                              ", "Green");
        wstaw_tekst(25, 19, "Wybor:                                                     ", "Green");
        wstaw_tekst(32, 19, "", "Orange");
        std::getline(std::cin, wybor);
        wstaw_tekst(32, 19, "                                     ", "Orange");
    } while (!std::regex_match(wybor, format_wyboru));

    wstaw_tekst(25, 15, "                                                                             ", "Green");
    wstaw_tekst(25, 16, "                                                                             ", "Green");
    wstaw_tekst(25, 17, "                                                                             ", "Green");
    wstaw_tekst(25, 18, "                                                                             ", "Green");
    wstaw_tekst(25, 19, "                                                                             ", "Green");
    return wybor;
}

/**
* Funkcja pytajaca uzytkownia o to kim chce gracz rozegrac parie z botem (biale lub czarne)
* @return gracz(figury) wyboru ruchu uzytkownia
*/
export Gracz menu_bot() {

    bool git = false;
    Gracz grac = brak;
    do {
        std::string wybor = "";
        wstaw_tekst(10, 7, "                                                                     ", "Orange");
        wstaw_tekst(3, 3, "Kto ma rozpoczac gre?                                                 ", "Yellow");
        wstaw_tekst(3, 4, "1 - Gracz (gyakusho)                                                  ", "Yellow");
        wstaw_tekst(3, 5, "2 - Bot                                                               ", "Yellow");
        wstaw_tekst(3, 6, "3 - Losowo                                                            ", "Yellow");
        wstaw_tekst(3, 7, "Wybor: ", "Yellow");
        wstaw_tekst(10, 7, "", "Orange");
        std::cin >> wybor;

        if (wybor == "1") {
            grac = gracz1;
            git = true;
        }
        else if (wybor == "2") {
            grac = gracz2;
            git = true;
        }
        else if (wybor == "3") {
            git = true;
            std::random_device dev;
            std::mt19937 rng(dev());
            std::uniform_int_distribution<std::mt19937::result_type> num(1, 2);
            int rando = num(rng);
            if (rando == 1) grac = gracz1;
            else if (rando == 2) grac = gracz2;
        }

    } while (!git);

    return grac;
}

/**
* Funkcja pytajaca uzytkownia o to jaki ma byc poziom trudnosci bota.
* @return string poziomu bota wybrany przez uzytkownika
*/
export std::string menuBotPoziom() {
    std::string wybor;
    wstaw_tekst(25, 13, "                                                                             ", "Green");
    wstaw_tekst(25, 14, "                                                                             ", "Green");
    wstaw_tekst(25, 15, "                                                                             ", "Green");
    wstaw_tekst(25, 16, "                                                                             ", "Green");
    wstaw_tekst(25, 17, "                                                                             ", "Green");
    wstaw_tekst(25, 18, "                                                                             ", "Green");
    wstaw_tekst(25, 19, "                                                                             ", "Green");
    wstaw_tekst(25, 20, "                                                                             ", "Green");

    std::regex format_wyboru("\\b[1-6]\\b");
    do {
        wstaw_tekst(25, 13, "Wybierz poziom trudnosci:                      ", "Green");
        wstaw_tekst(25, 14, "1 - nowicjusz                                  ", "Green");
        wstaw_tekst(25, 15, "2 - latwy                                      ", "Green");
        wstaw_tekst(25, 16, "3 - normalny                                   ", "Green");
        wstaw_tekst(25, 17, "4 - trudny                                     ", "Green");
        wstaw_tekst(25, 18, "5 - ekspert                                    ", "Green");
        wstaw_tekst(25, 19, "6 - powrot                                     ", "Green");
        wstaw_tekst(25, 20, "Wybor:                                         ", "Green");
        wstaw_tekst(32, 20, "", "Orange");
        std::getline(std::cin, wybor);
        wstaw_tekst(32, 20, "                                     ", "Orange");
    } while (!std::regex_match(wybor, format_wyboru));

    wstaw_tekst(25, 13, "                                                                             ", "Green");
    wstaw_tekst(25, 14, "                                                                             ", "Green");
    wstaw_tekst(25, 15, "                                                                             ", "Green");
    wstaw_tekst(25, 16, "                                                                             ", "Green");
    wstaw_tekst(25, 17, "                                                                             ", "Green");
    wstaw_tekst(25, 18, "                                                                             ", "Green");
    wstaw_tekst(25, 19, "                                                                             ", "Green");
    wstaw_tekst(25, 20, "                                                                             ", "Green");

    if (wybor == "1") wybor = "1";
    else if (wybor == "2") wybor = "2";
    else if (wybor == "3") wybor = "5";
    else if (wybor == "4") wybor = "8";
    else if (wybor == "5") wybor = "12";

    return wybor;
    // nowicjusz deapth 1
    // ³atwy depth 4
    // normalny depth 8
    // hard depth 10
    // ekspert depth 14
}

/**
* Funkcja pytajaca uzytkownia o to kim chce gracz rozegrac parie z botem (biale lub czarne)
* @return gracz(figury) wyboru ruchu uzytkownia
*/
export Gracz menu_bot_wczytanie(Gracz ruchGracza) {

    wstaw_tekst(25, 15, "                                                                             ", "Green");
    wstaw_tekst(25, 16, "                                                                             ", "Green");
    wstaw_tekst(25, 17, "                                                                             ", "Green");
    wstaw_tekst(25, 18, "                                                                             ", "Green");
    wstaw_tekst(25, 19, "                                                                             ", "Green");

    bool git = false;
    Gracz grac = brak;
    std::string ruch_aktualny = "";
    if (ruchGracza == gracz1) ruch_aktualny = "czerwone";
    else ruch_aktualny = "niebieskie";
    do {
        std::string wybor = "";
        wstaw_tekst(25, 15, "Kim ma byc gracz? (nastepny ruch wykonuja " + ruch_aktualny + " figury)           ", "Yellow");
        wstaw_tekst(25, 16, "1 - Czerwoni                                                         ", "Red");
        wstaw_tekst(25, 17, "2 - Niebiescy                                                        ", "Blue");
        wstaw_tekst(25, 18, "3 - Losowo                                                           ", "Yellow");
        wstaw_tekst(25, 19, "Wybor: ", "Yellow");
        wstaw_tekst(32, 19, "", "Orange");
        wstaw_tekst(32, 19, "                                             ", "Orange");
        std::cin >> wybor;

        if (wybor == "1") {
            grac = gracz1;
            git = true;
        }
        else if (wybor == "2") {
            grac = gracz2;
            git = true;
        }
        else if (wybor == "3") {
            git = true;
            std::random_device dev;
            std::mt19937 rng(dev());
            std::uniform_int_distribution<std::mt19937::result_type> num(1, 2);
            int rando = num(rng);
            if (rando == 1) grac = gracz1;
            else if (rando == 2) grac = gracz2;
        }

    } while (!git);

    wstaw_tekst(25, 15, "                                                                             ", "Green");
    wstaw_tekst(25, 16, "                                                                             ", "Green");
    wstaw_tekst(25, 17, "                                                                             ", "Green");
    wstaw_tekst(25, 18, "                                                                             ", "Green");
    wstaw_tekst(25, 19, "                                                                             ", "Green");

    return grac;
}

/**
* Funkcja pytajaca uzytkownia w jaki tryb chce zagrac.
* @return string wyboru trybu gry.
*/
export std::string menu() {

    std::string wybor = "";
    std::regex format_wyboru("\\b[1-4]\\b");

    do {
        wstaw_tekst(3, 3, "1. Gra 1vs1                      ", "Yellow");
        wstaw_tekst(3, 4, "2. Gra 1vsBot                    ", "Yellow");
        wstaw_tekst(3, 5, "3. Zasady gry                    ", "Yellow");
        wstaw_tekst(3, 6, "4. Wyjdz z gry                   ", "Yellow");
        wstaw_tekst(3, 7, "Wybor:                           ", "Yellow");
        wstaw_tekst(10, 7, "", "Orange");
        std::cin >> wybor;
        wstaw_tekst(10, 7, "                            ", "Orange");

    } while (!std::regex_match(wybor, format_wyboru));

    if (wybor == "1") wybor = "1vs1";
    else if (wybor == "2") wybor = "1vsBot";
    else if (wybor == "3") wybor = "zasady";
    else if (wybor == "4") wybor = "exit";

    return wybor;
}

/**
* Funkcja pytajaca uzytkownia o to czy chce zagrac nowa gre czy ja wczytac.
* @return string opcji gry (nowa lub wczytanie)
*/
export std::string menu2(std::string tryb) {

    std::string wybor = "";
    std::regex format_wyboru("\\b[1-3]\\b");

    do {
        wstaw_tekst(3, 3, "Wybrany tryb: " + tryb + "                                            ", "Yellow");
        wstaw_tekst(3, 4, "1. Nowa gra                                                           ", "Yellow");
        wstaw_tekst(3, 5, "2. Wczytaj gre/kontynuuj                                              ", "Yellow");
        wstaw_tekst(3, 6, "3. Powrot                                                             ", "Yellow");
        wstaw_tekst(3, 7, "Wybor:                                                                ", "Yellow");
        wstaw_tekst(10, 7, "", "Orange");
        std::cin >> wybor;
        wstaw_tekst(10, 7, "                                            ", "Orange");

    } while (!std::regex_match(wybor, format_wyboru));

    if (wybor == "1") wybor = "newGame";
    else if (wybor == "2") wybor = "wczytaj";
    else if (wybor == "3") wybor = "powrot";

    return wybor;

}

#pragma endregion intefejs_urzytkownika_reszta

#pragma region intefejs_urzytkownika_zrzutka

/**
* Funkcja menu zrzutki podania figury do zrzutu.
* @param wybor - char znaku wyboru figury do zrzutu.
* @return figury - figury gracza mozliwe do zrzutu
*/
export bool menu_zrzutka_podanie_figury(char& wybor, FiguryGracza figury) {

    std::string input = "";
    bool gut = false;
    std::regex format_czego("\\b[plnsgbr]\\b");
    std::regex back_fromat("\\b[Bb][Aa][Cc][Kk]\\b");

    do {
        gut = false;
        wstaw_tekst(25, 15, "Jaka figure chcesz wystawic na plansze?                                            ", "Green");
        wstaw_tekst(25, 18, "Aby wrocic do menu wyboru typu ruchu wpisac 'back'.                                ", "Green");
        wstaw_tekst(25, 17, "Format 'sybmol_figury':                                                            ", "Green");
        wstaw_tekst(49, 17, "", "Orange");
        std::getline(std::cin, input);
        wstaw_tekst(49, 17, "                                            ", "Orange");

        if (std::regex_match(input, back_fromat)) {
            // wroc do poprzedniego menu
            wstaw_tekst(25, 15, "                                                                               ", "Green");
            wstaw_tekst(25, 16, "                                                                               ", "Green");
            wstaw_tekst(25, 17, "                                                                               ", "Green");
            wstaw_tekst(25, 18, "                                                                               ", "Green");
            return false;
        }

        if (std::regex_match(input, format_czego)) gut = true;
        else wstaw_tekst(25, 16, "Nieprawidlowy format. Prosze podac ruch ponownie.                                          ", "Orange");

        if (gut) {
            if (!figury.sprawdzCzyFiguraJest(input[0])) {
                wstaw_tekst(25, 16, "Nie mozna wystawic " + input + " gdyz nie jest ona w figurach gracza. Prosze podac ruch ponownie.      ", "Orange");
                gut = false;
            }
            // wsztko git w innym wypadku
        }

    } while (!gut);
    wstaw_tekst(25, 15, "                                                                               ", "Green");
    wstaw_tekst(25, 16, "                                                                               ", "Green");
    wstaw_tekst(25, 17, "                                                                               ", "Green");
    wstaw_tekst(25, 18, "                                                                               ", "Green");
    wybor = input[0];

    return true;
}

/**
* Funkcja menu zrzutki podania pola zrzutu.
* @param wybor - tablica char ruchu
*/
export void menu_zrzutka_podanie_pola_zrzutu(char wybor[3]) {

    std::string wybor_figury(1, wybor[0]);
    std::string xy_to = "";
    std::regex format_miejsca("\\b[A-Ia-i][1-9]\\b");

    // gdzie chcesz to wystawic
    bool gut = false;
    do {
        wstaw_tekst(25, 15, "Na jakie pole chcesz wystawic wybrana figure                   ", "Green");
        wstaw_tekst(71, 15, wybor_figury, "Orange");
        wstaw_tekst(25, 17, "Format '[a-i][1-9]':                                           ", "Green");
        wstaw_tekst(46, 17, "", "Orange");
        std::getline(std::cin, xy_to);
        wstaw_tekst(46, 17, "                                 ", "Orange");

        if (std::regex_match(xy_to, format_miejsca)) gut = true;
        else wstaw_tekst(25, 16, "Nieprawidlowy format. Prosze podac ruch ponownie.                ", "Orange");

    } while (!gut);
    wstaw_tekst(25, 15, "                                                                   ", "Green");
    wstaw_tekst(25, 16, "                                                                   ", "Green");
    wstaw_tekst(25, 17, "                                                                   ", "Green");

    wybor[1] = xy_to[0];
    wybor[2] = xy_to[1];
}

/**
* Funkcja spradzajaca podane parametyry zrzutki
* @param wybor - tablica char ruchu
* @param gra - ca³a dwuwymiarowa tablica pól (czyli nasza szachownica na której rozgrywa siê rozgrywka).
* @param ruchGracza - Gracz aktualny ruch gracza
* @param figury - figury gracza mozliwe do zrzutu
* @return true jezeli zrzutka jest dozwolona, false jezeli nie
*/
export bool menu_zrzutka_sprawdzenie(char wybor[3], Pole** gra, Gracz ruchGracza, FiguryGracza figury) {

    // konwersja ruchu to na chary i int
    int y_to = char_to_int(wybor[1]); // wiersz -> kolumny
    int x_to = char_to_int(wybor[2]); // kolumny -> wiersz

    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    // sprawdzDostepnoscRuchu

    // 0.Pole musi byæ puste 
    if (!gra[x_to][y_to].isEmptyPole()) {
        // coœ tu stoi 
        wstaw_tekst(25, 16, "Wybrane pole jest zajete. Prosze podac ruch ponownie.", "Orange");
        return false;
    }
    else if (wybor[0] == 'p') {
        // 1.nie mo¿na wstawiæ piona do kolumny, gdzie ju¿ jest niepromowany pion (kolmny)
        for (int it = 0; it < 9; it++) {
            // przeglad calej kolumny za pionem
            if (gra[x_to][it].isEmptyPion() != nullptr) {
                // jest gdzies w kolumnie pion juz jakis 
                if ((gra[x_to][it].isEmptyPion()->getPromotion() == Promocja::bez_promocji) && (gra[x_to][it].isEmptyPion()->getGracz() == ruchGracza)) {
                    // jest niepromowany oraz gracza ktory wykonuje ruch
                    // czyli nie mozna tu dac tego piona!!
                    wstaw_tekst(25, 16, "We wybranej kolumnie znajduje sie juz twoj pion. Prosze podac ruch ponownie.", "Orange");
                    return false;
                }
            }
        }

        // 2.pion nie moze byc wystawiony w ostatnim polu (wierszu)
        if (ruchGracza == gracz1) {
            if (y_to == 8) {
                // nie mozna tu wystawic 
                wstaw_tekst(25, 16, "Nie mozna wystawic pionka na ostatnie pole wierszy. Prosze podac ruch ponownie.", "Orange");
                return false;
            }
        }
        else if (ruchGracza == gracz2) {
            if (y_to == 0) {
                // nie mozna tu wystawic 
                wstaw_tekst(25, 16, "Nie mozna wystawic pionka na ostatnie pole wierszy. Prosze podac ruch ponownie.", "Orange");
                return false;
            }
        }

    }
    else if (wybor[0] == 'l') {
        // 1.nie mo¿na po³o¿yæ figury tak, ¿eby nie mia³a ruchu (lancy w ostatniej);
        if (ruchGracza == gracz1) {
            if (y_to == 8) {
                // nie mozna tu wystawic 
                wstaw_tekst(25, 16, "Nie mozna wystawic lancy na ostatnie pole wierszy. Prosze podac ruch ponownie.", "Orange");
                return false;
            }
        }
        else if (ruchGracza == gracz2) {
            if (y_to == 0) {
                // nie mozna tu wystawic 
                wstaw_tekst(25, 16, "Nie mozna wystawic lancy na ostatnie pole wierszy. Prosze podac ruch ponownie.", "Orange");
                return false;
            }
        }
    }
    else if (wybor[0] == 'n') {
        // 1.nie mo¿na po³o¿yæ figury tak, ¿eby nie mia³a ruchu (skoczka w dwóch ostatnich liniach);
        if (ruchGracza == gracz1) {
            if (y_to == 8 || y_to == 7) {
                // nie mozna tu wystawic 
                wstaw_tekst(25, 16, "Nie mozna wystawic skoczka na dwa ostatnie pola wierszy. Prosze podac ruch ponownie.", "Orange");
                return false;
            }
        }
        else if (ruchGracza == gracz2) {
            if (y_to == 0 || y_to == 1) {
                // nie mozna tu wystawic 
                wstaw_tekst(25, 16, "Nie mozna wystawic skoczka na dwa ostatnie pola wierszy. Prosze podac ruch ponownie.", "Orange");
                return false;
            }
        }
    }
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    return true;
}

/**
* Funkcja g³ówna menu zrzutki.
* @param wybor - tablica char ruchu
* @param gra - ca³a dwuwymiarowa tablica pól (czyli nasza szachownica na której rozgrywa siê rozgrywka).
* @param ruchGracza - Gracz aktualny ruch gracza
* @param figury - figury gracza mozliwe do zrzutu
* @return kod intereger wyniku zrzutki (1-udana|0-powrot do poprzedniego menu|-1-nieprawodlowe parametry)
*/
export int menu_zrzutka(char wybor[3], Pole** gra, Gracz ruchGracza, FiguryGracza figury) {

    if (!figury.isEmptyFigury()) {
        do {
            if (!menu_zrzutka_podanie_figury(wybor[0], figury)) return 0; // JE¯ELI NIE PRAWDZIWE TO WRÓÆ DO POPRZEDNIEGO MENU
            menu_zrzutka_podanie_pola_zrzutu(wybor);
        } while (!menu_zrzutka_sprawdzenie(wybor, gra, ruchGracza, figury));
    }
    else {
        return -1; // nie mozna wystawic zadnej figury bo nie udalo sie zdobyc zadnej od przeciwnika
    }

    return 1;
}

#pragma endregion intefejs_urzytkownika_zrzutka

#pragma region interfejs_urzytkownia_ruch

/**
* Funkcja sprawdzajaca poprawnosc podanego pola na jakie sie poruszamy.
* @param wybor - tablica char ruchu
* @param gra - ca³a dwuwymiarowa tablica pól (czyli nasza szachownica na której rozgrywa siê rozgrywka).
* @param ruchGracza - Gracz aktualny ruch gracza
* @return Boolean czy podane pole na ktore chemy sie poruszyc jest ok (true).
*/
export bool menu_ruchu_sprawdzenie_pola_na(char wybor[4], Pole** gra, Gracz ruchGracza) {

    // konwersja ruchu from na chary 
    int y_to = char_to_int(wybor[2]);
    int x_to = char_to_int(wybor[3]);

    // tam gdzie idzeisz nie mo¿e byæ twoja figura
    if (!gra[x_to][y_to].isEmptyPole()) {
        // cos tam stoi 

        // sprwdŸ po kolei co tam mo¿e staæ i sprawdŸ czyjego jest to gracza
        if (gra[x_to][y_to].isEmptyPion() != nullptr) {
            if (gra[x_to][y_to].isEmptyPion()->getGracz() == ruchGracza) {
                // w³aœnie próbujesz zbiæ swój pinek gamoniu
                wstaw_tekst(25, 16, "Nie mozna atakowac swoich figur! Prosze podac ruch ponownie.       ", "Orange"); // nie tego gracza figura któr¹ chcesz siê ruszyæ
                return false;
            }
        }
        else if (gra[x_to][y_to].isEmptyLanca() != nullptr) {
            if (gra[x_to][y_to].isEmptyLanca()->getGracz() == ruchGracza) {
                // w³aœnie próbujesz zbiæ swój pinek gamoniu
                wstaw_tekst(25, 16, "Nie mozna atakowac swoich figur! Prosze podac ruch ponownie.       ", "Orange"); // nie tego gracza figura któr¹ chcesz siê ruszyæ
                return false;
            }
        }
        // czy wybrane pole from jest git dla SKOCZEK
        else if (gra[x_to][y_to].isEmptySkoczek() != nullptr) {
            if (gra[x_to][y_to].isEmptySkoczek()->getGracz() == ruchGracza) {
                // w³aœnie próbujesz zbiæ swój pinek gamoniu
                wstaw_tekst(25, 16, "Nie mozna atakowac swoich figur! Prosze podac ruch ponownie.       ", "Orange"); // nie tego gracza figura któr¹ chcesz siê ruszyæ
                return false;
            }
        }
        // czy wybrane pole from jest git dla SREBRNY GENRAL
        else if (gra[x_to][y_to].isEmptymGeneral() != nullptr) {
            if (gra[x_to][y_to].isEmptymGeneral()->getGracz() == ruchGracza) {
                // w³aœnie próbujesz zbiæ swój pinek gamoniu
                wstaw_tekst(25, 16, "Nie mozna atakowac swoich figur! Prosze podac ruch ponownie.       ", "Orange"); // nie tego gracza figura któr¹ chcesz siê 
                return false;
            }
        }
        // czy wybrane pole from jest git dla ZLOTY GENERAL
        else if (gra[x_to][y_to].isEmptydGeneral() != nullptr) {
            if (gra[x_to][y_to].isEmptydGeneral()->getGracz() == ruchGracza) {
                // w³aœnie próbujesz zbiæ swój pinek gamoniu
                wstaw_tekst(25, 16, "Nie mozna atakowac swoich figur! Prosze podac ruch ponownie.", "Orange"); // nie tego gracza figura któr¹ chcesz siê ruszyæ
                return false;
            }

        }
        // czy wybrane pole from jest git dla GONIEC
        else if (gra[x_to][y_to].isEmptyGoniec() != nullptr) {
            if (gra[x_to][y_to].isEmptyGoniec()->getGracz() == ruchGracza) {
                // w³aœnie próbujesz zbiæ swój pinek gamoniu
                wstaw_tekst(25, 16, "Nie mozna atakowac swoich figur! Prosze podac ruch ponownie.", "Orange"); // nie tego gracza figura któr¹ chcesz siê 
                return false;
            }
        }
        // czy wybrane pole from jest git dla WIEZA
        else if (gra[x_to][y_to].isEmptyWieza() != nullptr) {
            if (gra[x_to][y_to].isEmptyWieza()->getGracz() == ruchGracza) {
                // w³aœnie próbujesz zbiæ swój pinek gamoniu
                wstaw_tekst(25, 16, "Nie mozna atakowac swoich figur! Prosze podac ruch ponownie.", "Orange"); // nie tego gracza figura któr¹ chcesz siê 
                return false;
            }
        }
        // czy wybrane pole from jest git dla KROL
        else if (gra[x_to][y_to].isEmptyKrol() != nullptr) {
            if (gra[x_to][y_to].isEmptyKrol()->getGracz() == ruchGracza) {
                // w³aœnie próbujesz zbiæ swój pinek gamoniu
                wstaw_tekst(25, 16, "Nie mozna atakowac swoich figur! Prosze podac ruch ponownie.", "Orange"); // nie tego gracza figura któr¹ chcesz siê ruszyæ
                return false;
            }
        }
    }

    return true;
}

/**
* Funkcja menu inefejsu urzytknika dla podania pola na jakie sie poruszamy.
* @param wybor - tablica char ruchu
*/
export void menu_ruchu_podanie_pola_na(char wybor[4]) {

    std::string xy_from = "";
    xy_from.push_back(wybor[0]);
    xy_from.push_back(wybor[1]);
    std::string xy_to = "";
    std::regex format_ruchu("\\b[A-Ia-i][1-9]\\b");

    // podanie prawd³owego formatu to pola
    bool gut = false;
    do {
        wstaw_tekst(25, 15, "Na jakie pole chcesz przesunac wybrana figure z                            ", "Green");
        wstaw_tekst(71, 15, xy_from, "Orange");
        wstaw_tekst(25, 17, "Format '[a-i][1-9]':                                                       ", "Green");
        wstaw_tekst(46, 17, "", "Orange");
        std::getline(std::cin, xy_to);
        wstaw_tekst(46, 17, "                                               ", "Orange");

        if (std::regex_match(xy_to, format_ruchu)) gut = true;
        else wstaw_tekst(25, 16, "Nieprawidlowy format. Prosze podac ruch ponownie.         ", "Orange");

    } while (!gut);
    wstaw_tekst(25, 15, "                                                                               ", "Green");
    wstaw_tekst(25, 16, "                                                                               ", "Orange");
    wstaw_tekst(25, 17, "                                                                               ", "Orange");

    wybor[2] = xy_to[0];
    wybor[3] = xy_to[1];
}

/**
* Funkcja sprawdzajaca poprawnosc podanego pola z jakiego sie poruszamy.
* @param wybor - tablica char ruchu
* @param gra - ca³a dwuwymiarowa tablica pól (czyli nasza szachownica na której rozgrywa siê rozgrywka).
* @param ruchGracza - Gracz aktualny ruch gracza
* @return Boolean czy podane pole z ktorego chemy sie poruszyc jest ok (true).
*/
export bool menu_ruchu_sprawdzenie_pola_z(char wybor[4], Pole** gra, Gracz ruchGracza) {

    // konwersja ruchu to na chary i int
    int y_from = char_to_int(wybor[0]);
    int x_from = char_to_int(wybor[1]);

    // czy cos tam stoi?
    if (!gra[x_from][y_from].isEmptyPole()) {
        // cos tam stoi 
        // czy wybrane pole from jest git dla PIONEK
        if (gra[x_from][y_from].isEmptyPion() != nullptr) {
            if (gra[x_from][y_from].isEmptyPion()->getGracz() != ruchGracza) {
                wstaw_tekst(25, 16, "Ten pionek nie nalezy do gracza ktory wykonuje ruch. Prosze podac ruch ponownie.           ", "Orange"); // nie tego gracza figura któr¹ chcesz siê ruszyæ
                return false;
            }
        }
        // czy wybrane pole from jest git dla LANCA
        else if (gra[x_from][y_from].isEmptyLanca() != nullptr) {
            if (gra[x_from][y_from].isEmptyLanca()->getGracz() != ruchGracza) {
                wstaw_tekst(25, 16, "Ta lanca nie nalezy do gracza ktory wykonuje ruch. Prosze podac ruch ponownie.         ", "Orange"); // nie tego gracza figura któr¹ chcesz siê ruszyæ
                return false;
            }
        }
        // czy wybrane pole from jest git dla SKOCZEK
        else if (gra[x_from][y_from].isEmptySkoczek() != nullptr) {
            if (gra[x_from][y_from].isEmptySkoczek()->getGracz() != ruchGracza) {
                wstaw_tekst(25, 16, "Ten skoczek nie nalezy do gracza ktory wykonuje ruch. Prosze podac ruch ponownie.          ", "Orange"); // nie tego gracza figura któr¹ chcesz siê ruszyæ
                return false;
            }
        }
        // czy wybrane pole from jest git dla SREBRNY GENRAL
        else if (gra[x_from][y_from].isEmptymGeneral() != nullptr) {
            if (gra[x_from][y_from].isEmptymGeneral()->getGracz() != ruchGracza) {
                wstaw_tekst(25, 16, "Ten srebrny general nie nalezy do gracza ktory wykonuje ruch. Prosze podac ruch ponownie.      ", "Orange"); // nie tego gracza figura któr¹ chcesz siê ruszyæ
                return false;
            }
        }
        // czy wybrane pole from jest git dla ZLOTY GENERAL
        else if (gra[x_from][y_from].isEmptydGeneral() != nullptr) {
            if (gra[x_from][y_from].isEmptydGeneral()->getGracz() != ruchGracza) {
                wstaw_tekst(25, 16, "Ten zloty general nie nalezy do gracza ktory wykonuje ruch. Prosze podac ruch ponownie.        ", "Orange"); // nie tego gracza figura któr¹ chcesz siê ruszyæ
                return false;
            }
        }
        // czy wybrane pole from jest git dla GONIEC
        else if (gra[x_from][y_from].isEmptyGoniec() != nullptr) {
            if (gra[x_from][y_from].isEmptyGoniec()->getGracz() != ruchGracza) {
                wstaw_tekst(25, 16, "Ten goniec nie nalezy do gracza ktory wykonuje ruch. Prosze podac ruch ponownie.           ", "Orange"); // nie tego gracza figura któr¹ chcesz siê ruszyæ
                return false;
            }
        }
        // czy wybrane pole from jest git dla WIEZA
        else if (gra[x_from][y_from].isEmptyWieza() != nullptr) {
            if (gra[x_from][y_from].isEmptyWieza()->getGracz() != ruchGracza) {
                wstaw_tekst(25, 16, "Ta wieza nie nalezy do gracza ktory wykonuje ruch. Prosze podac ruch ponownie.         ", "Orange"); // nie tego gracza figura któr¹ chcesz siê ruszyæ
                return false;
            }
        }
        // czy wybrane pole from jest git dla KROL
        else if (gra[x_from][y_from].isEmptyKrol() != nullptr) {
            if (gra[x_from][y_from].isEmptyKrol()->getGracz() != ruchGracza) {
                wstaw_tekst(25, 16, "Ten krol nie nalezy do gracza ktory wykonuje ruch. Prosze podac ruch ponownie.         ", "Orange"); // nie tego gracza figura któr¹ chcesz siê ruszyæ
                return false;
            }
        }
        // wybrane pole jest puste
    }
    else {
        std::string xy_from = "";
        xy_from.push_back(wybor[0]);
        xy_from.push_back(wybor[1]);
        wstaw_tekst(25, 16, "Wybrane pole " + xy_from + " jest puste. Prosze podac ruch ponownie.                                ", "Orange"); // nie ma figury na tym polu z którego chcesz siê ruszyæ
        return false;
    }

    return true;
}

/**
* Funkcja menu inefejsu urzytknika dla podania pola z jakiego sie poruszamy.
* @param wybor - tablica char ruchu
* @return Boolean czy podanie ruchu z jakiego pola sie ruszamy jest prawid³owe (false - powrót do poprzedniego menu)
*/
export bool menu_ruchu_podanie_pola_z(char wybor[4]) {
    std::regex format_ruchu("\\b[A-Ia-i][1-9]\\b");
    std::regex back_fromat("\\b[Bb][Aa][Cc][Kk]\\b");
    std::string xy_from = "";

    // podanie prawd³owego formatu form pola
    bool gut = false;
    do {
        wstaw_tekst(25, 15, "Z jakiego pola chcesz przesunac figure                                     ", "Green");
        wstaw_tekst(25, 18, "Aby wrocic do menu wyboru typu ruchu wpisac 'back'.                        ", "Green");
        wstaw_tekst(25, 17, "Format '[a-i][1-9]':                                                       ", "Green");
        wstaw_tekst(46, 17, "", "Orange");
        std::getline(std::cin, xy_from);
        wstaw_tekst(46, 17, "                   ", "Orange");

        if (std::regex_match(xy_from, back_fromat)) {
            // wroc do poprzedniego menu
            wstaw_tekst(25, 16, "                                                                                   ", "Green");
            wstaw_tekst(25, 17, "                                                                                   ", "Green");
            wstaw_tekst(25, 18, "                                                                                   ", "Green");
            return false;
        }

        if (std::regex_match(xy_from, format_ruchu)) gut = true;
        else wstaw_tekst(25, 16, "Nieprawidlowy format. Prosze podac ruch ponownie.", "Orange");

    } while (!gut);
    wstaw_tekst(25, 16, "                                                                                   ", "Green");
    wstaw_tekst(25, 17, "                                                                                   ", "Green");
    wstaw_tekst(25, 18, "                                                                                   ", "Green");

    wybor[0] = xy_from[0];
    wybor[1] = xy_from[1];
    return true;
}

/**
* Funkcja g³ówna menu ruchu.
* @param wybor - tablica char ruchu
* @param gra - ca³a dwuwymiarowa tablica pól (czyli nasza szachownica na której rozgrywa siê rozgrywka).
* @param ruchGracza - Gracz aktualny ruch gracza
* @return kod intereger wyniku zrzutki (1-udana|0-powrot do poprzedniego menu|-1-nieprawodlowe parametry)
*/
export int menu_ruchu(char wybor[4], Pole** gra, Gracz ruchGracza) {

    do {
        if (!menu_ruchu_podanie_pola_z(wybor)) return 0; // JE¯ELI NIE PRAWDZIWE TO WRÓÆ DO POPRZEDNIEGO MENU
    } while (!menu_ruchu_sprawdzenie_pola_z(wybor, gra, ruchGracza));

    do {
        menu_ruchu_podanie_pola_na(wybor);
    } while (!menu_ruchu_sprawdzenie_pola_na(wybor, gra, ruchGracza));

    return 1;

}

#pragma endregion interfejs_urzytkownia_ruch