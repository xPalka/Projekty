/*
* Made by: Szymon Palka
* Date: 06/2022
*/

import pole_code;

// 1 element - modułu - potem dodac
#include <fstream>
#include <filesystem>       // 4 element - dodane podczas zapisu i wczytywania
#include <thread>           // 5 element(6 i 7 też bo sie dziela na podelementy) 
#include <future>           
                            
#include "bot-process.h"


// do crt memory 
//#define _CRTDBG_MAP_ALLOC
//#include <stdlib.h>
//#include <crtdbg.h>

int main() {

    // --- ustawienia okna konsoli ---
    HWND console = GetConsoleWindow();
    RECT ConsoleRect;
    GetWindowRect(console, &ConsoleRect);
    MoveWindow(console, ConsoleRect.left, ConsoleRect.top, 950, 900, TRUE);
    // -------------------------------
    bool koniec = false;
    bool go_back_to_menu2 = false;
    bool go_back_to_menu_1vs1 = false;
    bool go_back_to_menu_1vsBot = false;
    std::cout << "......";
    clear_screan();
    koniec = false;
    do {
        clear_screan();
        std::string tryb = menu(); // odkomentować jest to głowe menu

        if (tryb == "1vs1") {

            go_back_to_menu2 = false;
            do {
                clear_screan();
                std::string tryb2 = menu2(tryb); 
                if (tryb2 == "powrot") break;
        
                // Inicjalizacja gry
                Gracz ruchGracza = gracz1;
                Logs logi;
                FiguryGracza figuryGracza1; // figury gracza 1 
                FiguryGracza figuryGracza2; // figury gracza 2
                
                Pole** gra; // przedstawia stan gry tablica 2 wymiarowa
                gra = new Pole * [9];
                for (int i = 0; i < 9; i++)
                    gra[i] = new Pole[9];
                

                for (int i = 0; i < 9; i++) {
                    for (int j = 0; j < 9; j++) {
                        gra[i][j].setx(i);
                        gra[i][j].sety(j);
                    }
                }

                if (tryb2 == "newGame") {
                    // ustawianie figur 
                    clear_screan();
                    rysuj_szachownice();
                    ustaw_figury_start(gra);
                    zasady_ruchow();
                    zasady_ruchow_znaki();
                    logi.addTozapis_gry(zapisz_planszy(gra)); // 0 pozycja
                }
                else if (tryb2 == "wczytaj") {
                    clear_screan();
                    rysuj_szachownice();
                    std::filesystem::path tmpPATH = wczytaj_figury_interfejs();
                    if (!tmpPATH.empty())  wczytaj_figury(gra, figuryGracza1, figuryGracza2, ruchGracza, logi, tmpPATH);
                    else break;
                    zasady_ruchow();
                    zasady_ruchow_znaki();
                    logi.addTozapis_gry(zapisz_planszy(gra)); // 0 pozycja
                }
                
                // figury ze zrzutki
                wstaw_tekst(25, 5, "Figury gracza 1:", "Red");
                wstaw_tekst(25, 8, "Figury gracza 2:", "Blue");

                // WSZYSTKO ZOSTAŁO USTAWIONE
                // PONIŻEJ SAMA ROZGRYWKA

                go_back_to_menu_1vs1 = false;
                do {
                    bool back_to_menu_1vs1 = false;

                    wstaw_tekst(25, 6, "                                           ", "Red");
                    wstaw_tekst(25, 6, "", "Red");
                    figuryGracza1.wypisz();
                    wstaw_tekst(25, 9, "                                           ", "Blue");
                    wstaw_tekst(25, 9, "", "Blue");
                    figuryGracza2.wypisz();

                    // wypisuje kto wykonuje ruch
                    if (ruchGracza == gracz1) wstaw_tekst(25, 14, "Ruch wykonuje gracz 1", "Red");
                    else wstaw_tekst(25, 14, "Ruch wykonuje gracz 2", "Blue");

                    std::string wybor2 = menu_1vs1();

                    if (wybor2 == "1") {
                        // jezeli wybierzesz ruch DONE
                        char wybor[4] = { 0 };
                        bool git = false;

                        do {
                            if (menu_ruchu(wybor, gra, ruchGracza) == 1) {
                                if (ruchGracza == gracz1) {
                                    int tmp_wr = wykonaj_ruch(wybor, figuryGracza1, gra, ruchGracza);
                                    if (tmp_wr == 0) {
                                        // return to menu po zbiciu krola
                                        go_back_to_menu2 = true;
                                        go_back_to_menu_1vsBot = true;
                                        break;
                                    }
                                    else if (tmp_wr == 1) {
                                        git = true;
                                    }
                                }
                                else if (ruchGracza == gracz2) {
                                    int tmp_wr = wykonaj_ruch(wybor, figuryGracza2, gra, ruchGracza);
                                    if (tmp_wr == 0) {
                                        // return to menu po zbiciu krola
                                        go_back_to_menu2 = true;
                                        go_back_to_menu_1vsBot = true;
                                        break;
                                    }
                                    else if (tmp_wr == 1) {
                                        git = true;
                                    }
                                }
                            }
                            else {
                                break;
                            }
                        } while (!git);


                        // dodaje ruch do logow 
                        if (git) {
                            if (!save_to_logs_move(wybor, gra, logi)) {
                                go_back_to_menu2 = true;
                                go_back_to_menu_1vs1 = true;
                            }
                        }


                    }
                    else if (wybor2 == "2") {
                        // przywrocenie figry na plansze

                        char wybor[3] = { 0 }; // wybor[0] - wybor figury | wybor[1 i 2] - wybór pola
                        int bak = 1;

                        std::promise<bool> promise3;
                        std::promise<bool> promise4;
                        std::future<bool> fut3g1 = promise3.get_future();
                        std::future<bool> fut3g2 = promise4.get_future();

                        if (ruchGracza == gracz1) {
                            // to do main 
                            bak = menu_zrzutka(wybor, gra, ruchGracza, figuryGracza1);

                            if (bak == 1) {
                                // git i idziemy z tym dalej czyli wystawiamy figure 
                                wykonanie_zrzutu(wybor, figuryGracza1, gra);
                                zapis_do_logow_programu_zrzutka(wybor, gra, logi);

                                int x1 = -1; int y1 = -1;
                                int x2 = -1; int y2 = -1;
                                gdzieKrol(gracz1, gra, x1, y1);
                                gdzieKrol(gracz2, gra, x2, y2);
                                fut3g1 = std::async(std::launch::async, [&] { return gra[x1][y1].czySzach(gra, gracz1); }); // thread 3
                                fut3g2 = std::async(std::launch::async, [&] { return gra[x2][y2].czySzach(gra, gracz2); }); // thread 4

                                ruchGracza = gracz2; // zamiana ruchu 
                            }
                            else if (bak == 0) {
                                back_to_menu_1vs1 = true;
                            }
                            else if (bak == -1) {
                                wstaw_tekst(45, 16, "- brak figur do wystawienia.", "Orange"); // nie mozna wystawic zadnej figury bo nie udalo sie zdobyc zadnej od przeciwnika 
                                back_to_menu_1vs1 = true;
                            }

                        }
                        else if (ruchGracza == gracz2) {

                            bak = menu_zrzutka(wybor, gra, ruchGracza, figuryGracza2);

                            if (bak == 1) {
                                // git i idziemy z tym dalej czyli wystawiamy figure 
                                wykonanie_zrzutu(wybor, figuryGracza2, gra);
                                zapis_do_logow_programu_zrzutka(wybor, gra, logi);

                                int x1 = -1; int y1 = -1;
                                int x2 = -1; int y2 = -1;
                                gdzieKrol(gracz1, gra, x1, y1);
                                gdzieKrol(gracz2, gra, x2, y2);
                                fut3g1 = std::async(std::launch::async, [&] { return gra[x1][y1].czySzach(gra, gracz1); }); // thread 3
                                fut3g2 = std::async(std::launch::async, [&] { return gra[x2][y2].czySzach(gra, gracz2); }); // thread 4

                                ruchGracza = gracz1; // zamiana ruchu 
                            }
                            else if (bak == 0) {
                                back_to_menu_1vs1 = true;
                            }
                            else if (bak == -1) {
                                wstaw_tekst(45, 16, "- brak figur do wystawienia.", "Orange"); // nie mozna wystawic zadnej figury bo nie udalo sie zdobyc zadnej od przeciwnika 
                                back_to_menu_1vs1 = true;
                            }
                        }

                        if (!back_to_menu_1vs1) {
                            // czy nie powtarza sie szachowanie 
                            if (fut3g1.get() && logi.powtrzorzenie_ruchu()) logi.incIloscSzachowKrolGracza1();
                            else logi.setIloscSzachowKrolGracza1(0);

                            if (fut3g2.get() && logi.powtrzorzenie_ruchu()) logi.incIloscSzachowKrolGracza2();
                            else logi.setIloscSzachowKrolGracza2(0);

                            if (logi.getIloscSzachowKrolGracza1() >= 4) {
                                koniec_przez_zaszachowanie(gracz1); // krol gracza 1 został zaszahcowany 4 razy z rzedu czyli wygrywa gracz2                               
                                go_back_to_menu2 = true;
                                break;
                            }
                            if (logi.getIloscSzachowKrolGracza2() >= 4) {
                                koniec_przez_zaszachowanie(gracz2); // krol gracza 2 został zaszahcowany 4 razy z rzedu czyli wygrywa gracz1
                                go_back_to_menu2 = true;
                                break;
                            }
                        }
                    }
                    else if (wybor2 == "3") {
                        // zapis do pliku DONE 
                        std::filesystem::path siezka;
                        if (zapisz_figury(gra, figuryGracza1, figuryGracza2, ruchGracza, logi, siezka)) {
                            clear_screan();
                            wstaw_tekst(8, 3, "Rozgrywka zostala zapisana do pliku.", "Pink");
                            std::string path_string{ siezka.string() };
                            wstaw_tekst(8, 4, path_string, "Orange");
                            wstaw_tekst(10, 5, "Aby przejsc do menu glownego.", "Pink");
                            wstaw_tekst(9, 6, "", "Pink");
                            system("pause");
                            go_back_to_menu2 = true;
                            go_back_to_menu_1vs1 = true; //break;
                        }
                    }
                    else if (wybor2 == "4") {
                        // poddanie sie/powrot do menu DONE
                        clear_screan();
                        koniec_przez_poddanie_1vs1(ruchGracza);
                        go_back_to_menu2 = true;
                        go_back_to_menu_1vs1 = true; //break;
                    }

                } while (!go_back_to_menu_1vs1);
                // dest  Pole** gra; // przedstawia stan gry tablica 2 wymiarowa

                for (int i = 0; i < 9; i++) {
                    delete[] gra[i];
                }
                delete[] gra;
                gra = 0;
            } while (!go_back_to_menu2);

            
        }
        else if (tryb == "1vsBot") {

            go_back_to_menu2 = false;
            do {
                clear_screan();
                std::string tryb2 = menu2(tryb); // odkomentować jest to głowe menu
                if (tryb2 == "powrot") break;
                    
                // wszystkie te struktury przetrzymywac w logi??
                Gracz ruchGracza = gracz1;
                botShogi prog;
                Logs logi;
                FiguryGracza figuryGracza1; // figury gracza 1 
                FiguryGracza figuryGracza2; // figury gracza 2
                // Inicjalizacja zmiennej lokalnej 
                Pole** gra; // przedstawia stan gry tablica 2 wymiarowa
                gra = new Pole * [9];
                for (int i = 0; i < 9; i++)
                    gra[i] = new Pole[9];
                

                for (int i = 0; i < 9; i++) {
                    for (int j = 0; j < 9; j++) {
                        gra[i][j].setx(i);
                        gra[i][j].sety(j);
                    }
                }
                // koniec inicjalizacji

                std::string poziom_bota, ruchBot;
                std::string pozycja_startowa = "startpos";
                Gracz KolorGracz = brak;
                prog.startBotNewGame(); // inicjalizacja komendami programu bota

                if (tryb2 == "newGame") {
                    // ustawianie figur 
                    KolorGracz = menu_bot(); // wybór kto zaczyna
                    clear_screan();
                    rysuj_szachownice();
                    ustaw_figury_start(gra);
                    zasady_ruchow();
                    zasady_ruchow_znaki();
                    poziom_bota = menuBotPoziom();
                    if (poziom_bota == "6") break;
                    ruchBot = "go depth " + poziom_bota + "\n";
                    logi.addTozapis_gry(zapisz_planszy(gra)); // 0 pozycja
                }
                else if (tryb2 == "wczytaj") {
                    clear_screan();
                    rysuj_szachownice();
                    std::filesystem::path tmpPATH = wczytaj_figury_interfejs();
                    if (!tmpPATH.empty()) {
                        pozycja_startowa = graToSFEN(tmpPATH);
                        prog.getNextMove("position " + pozycja_startowa + " moves\n");
                        wczytaj_figury(gra, figuryGracza1, figuryGracza2, ruchGracza, logi, tmpPATH);
                    }
                    else break;
                    KolorGracz = menu_bot_wczytanie(ruchGracza);

                    zasady_ruchow();
                    zasady_ruchow_znaki();
                    poziom_bota = menuBotPoziom();
                    if (poziom_bota == "6") break;
                    ruchBot = "go depth " + poziom_bota + "\n";
                    logi.addTozapis_gry(zapisz_planszy(gra)); // 0 pozycja
                }

                if (gracz1 == KolorGracz) {
                    wstaw_tekst(25, 5, "Figury gracza:", "Red");
                    wstaw_tekst(25, 8, "Figury bota:", "Blue");
                }
                else if (gracz2 == KolorGracz) {
                    wstaw_tekst(25, 5, "Figury bota:", "Red");
                    wstaw_tekst(25, 8, "Figury gracza:", "Blue");
                }

                go_back_to_menu_1vsBot = false;
                do {
                    bool back_to_menu_1vsBot = false;

                    // ruch gracza 
                    if (KolorGracz == ruchGracza) {
                        
                        wstaw_tekst(25, 6, "                                           ", "Red");
                        wstaw_tekst(25, 6, "", "Red");
                        figuryGracza1.wypisz();
                        wstaw_tekst(25, 9, "                                           ", "Blue");
                        wstaw_tekst(25, 9, "", "Blue");
                        figuryGracza2.wypisz();

                        // wypisuje kto wykonuje ruch
                        if (gracz1 == KolorGracz) wstaw_tekst(25, 14, "Ruch wykonuje gracz        ", "Red");
                        else wstaw_tekst(25, 14, "Ruch wykonuje gracz        ", "Blue");

                        std::string wybor2 = menu_1vs1();

                        bool back_to_menu_1vs1 = false;

                        if (wybor2 == "1") {
                            // jezeli wybierzesz ruch DONE
                            char wybor[4] = { 0 };
                            bool git = false;

                            do {
                                if (menu_ruchu(wybor, gra, ruchGracza) == 1) {
                                    if (ruchGracza == gracz1) {
                                        int tmp_wr = wykonaj_ruch(wybor, figuryGracza1, gra, ruchGracza);
                                        if (tmp_wr == 0) {
                                            // return to menu po zbiciu krola
                                            go_back_to_menu2 = true;
                                            go_back_to_menu_1vsBot = true;
                                            break;
                                        }
                                        else if (tmp_wr == 1) {
                                            git = true;
                                        }
                                    }
                                    else if (ruchGracza == gracz2) {
                                        int tmp_wr = wykonaj_ruch(wybor, figuryGracza2, gra, ruchGracza);
                                        if (tmp_wr == 0) {
                                            // return to menu po zbiciu krola
                                            go_back_to_menu2 = true;
                                            go_back_to_menu_1vsBot = true;
                                            break;
                                        }
                                        else if (tmp_wr == 1) {
                                            git = true;
                                        }
                                    }
                                }
                                else {
                                    break;
                                }
                            } while (!git);


                            // dodaje ruch do logow 
                            if (git) {
                                if (!save_to_logs_move(wybor, gra, logi)) {
                                    go_back_to_menu2 = true;
                                    go_back_to_menu_1vsBot = true;
                                }
                                else {
                                    // podanie ruchu do silnika
                                    prog.podaj_aktualna_pozycje(wybor, pozycja_startowa);
                                }
                            }
                        }
                        else if (wybor2 == "2") {
                            // przywrocenie figry na plansze

                            char wybor[3] = { 0 }; // wybor[0] - wybor figury | wybor[1 i 2] - wybór pola
                            int bak = 1;

                            std::promise<bool> promise3;
                            std::promise<bool> promise4;
                            std::future<bool> fut3g1 = promise3.get_future();
                            std::future<bool> fut3g2 = promise4.get_future();

                            if (ruchGracza == gracz1) {
                                // to do main 
                                bak = menu_zrzutka(wybor, gra, ruchGracza, figuryGracza1);

                                if (bak == 1) {
                                    // git i idziemy z tym dalej czyli wystawiamy figure 
                                    wykonanie_zrzutu(wybor, figuryGracza1, gra);
                                    zapis_do_logow_programu_zrzutka(wybor, gra, logi);

                                    prog.podaj_aktualna_pozycje_zrzutka(wybor, pozycja_startowa);

                                    int x1 = -1; int y1 = -1;
                                    int x2 = -1; int y2 = -1;
                                    gdzieKrol(gracz1, gra, x1, y1);
                                    gdzieKrol(gracz2, gra, x2, y2);
                                    fut3g1 = std::async(std::launch::async, [&] { return gra[x1][y1].czySzach(gra, gracz1); }); // thread 3
                                    fut3g2 = std::async(std::launch::async, [&] { return gra[x2][y2].czySzach(gra, gracz2); }); // thread 4

                                    ruchGracza = gracz2; // zamiana ruchu 
                                }
                                else if (bak == 0) {
                                    back_to_menu_1vsBot = true;
                                }
                                else if (bak == -1) {
                                    wstaw_tekst(45, 16, "- brak figur do wystawienia.", "Orange"); // nie mozna wystawic zadnej figury bo nie udalo sie zdobyc zadnej od przeciwnika 
                                    back_to_menu_1vsBot = true;
                                }

                            }
                            else if (ruchGracza == gracz2) {

                                bak = menu_zrzutka(wybor, gra, ruchGracza, figuryGracza2);

                                if (bak == 1) {
                                    // git i idziemy z tym dalej czyli wystawiamy figure 
                                    wykonanie_zrzutu(wybor, figuryGracza2, gra);
                                    zapis_do_logow_programu_zrzutka(wybor, gra, logi);

                                    prog.podaj_aktualna_pozycje_zrzutka(wybor, pozycja_startowa);

                                    int x1 = -1; int y1 = -1;
                                    int x2 = -1; int y2 = -1;
                                    gdzieKrol(gracz1, gra, x1, y1);
                                    gdzieKrol(gracz2, gra, x2, y2);
                                    fut3g1 = std::async(std::launch::async, [&] { return gra[x1][y1].czySzach(gra, gracz1); }); // thread 3
                                    fut3g2 = std::async(std::launch::async, [&] { return gra[x2][y2].czySzach(gra, gracz2); }); // thread 4

                                    ruchGracza = gracz1; // zamiana ruchu 
                                }
                                else if (bak == 0) {
                                    back_to_menu_1vsBot = true;
                                }
                                else if (bak == -1) {
                                    wstaw_tekst(45, 16, "- brak figur do wystawienia.", "Orange"); // nie mozna wystawic zadnej figury bo nie udalo sie zdobyc zadnej od przeciwnika 
                                    back_to_menu_1vsBot = true;
                                }
                            }

                            if (!back_to_menu_1vsBot) {
                                // czy nie powtarza sie szachowanie 
                                if (fut3g1.get() && logi.powtrzorzenie_ruchu()) logi.incIloscSzachowKrolGracza1();
                                else logi.setIloscSzachowKrolGracza1(0);

                                if (fut3g2.get() && logi.powtrzorzenie_ruchu()) logi.incIloscSzachowKrolGracza2();
                                else logi.setIloscSzachowKrolGracza2(0);

                                if (logi.getIloscSzachowKrolGracza1() >= 4) {
                                    koniec_przez_zaszachowanie(gracz1); // krol gracza 1 został zaszahcowany 4 razy z rzedu czyli wygrywa gracz2                               
                                    go_back_to_menu2 = true;
                                    break;
                                }
                                if (logi.getIloscSzachowKrolGracza2() >= 4) {
                                    koniec_przez_zaszachowanie(gracz2); // krol gracza 2 został zaszahcowany 4 razy z rzedu czyli wygrywa gracz1
                                    go_back_to_menu2 = true;
                                    break;
                                }
                            }
                        }
                        else if (wybor2 == "3") {
                            // zapis do pliku DONE 
                            std::filesystem::path siezka;
                            if (zapisz_figury(gra, figuryGracza1, figuryGracza2, ruchGracza, logi, siezka)) {
                                clear_screan();
                                wstaw_tekst(8, 3, "Rozgrywka zostala zapisana do pliku.", "Pink");
                                std::string path_string{ siezka.string() };
                                wstaw_tekst(8, 4, path_string, "Orange");
                                wstaw_tekst(10, 5, "Aby przejsc do menu glownego.", "Pink");
                                wstaw_tekst(9, 6, "", "Pink");
                                system("pause");
                                go_back_to_menu2 = true;
                                go_back_to_menu_1vsBot = true; //break;
                            }
                        }
                        else if (wybor2 == "4") {
                            // poddanie sie/powrot do menu DONE
                            clear_screan();
                            koniec_przez_poddanie_1vsBot(ruchGracza);
                            go_back_to_menu2 = true;
                            go_back_to_menu_1vsBot = true; //break;
                        }

                    }
                    else {

                        // bot ruch
                        std::string ruchProg = prog.getNextMove(ruchBot);
                        std::string USImove = konwersjaRuchuGraUSISilnik(ruchProg);

                        if (USImove.empty()) {
                            return 2; 
                        }
                        else if (USImove == "resig") {
                            // BOT przegrywa i wygrywa gracz
                            zbicie_krola_bot();
                            go_back_to_menu2 = true;
                            go_back_to_menu_1vsBot = true; //break;
                        }
                        else if (USImove[1] != '*') {

                            char wybor[4] = { '\0' };
                            char promocja = '\0';
                            wybor[0] = USImove[0];
                            wybor[1] = USImove[1];
                            wybor[2] = USImove[2];
                            wybor[3] = USImove[3];
                            if (USImove.size() == 5)
                                promocja = USImove[4];

                            bool git = false;

                            do {
                                if (ruchGracza == gracz1) {
                                    int tmp_wr = wykonaj_ruch(wybor, figuryGracza1, gra, ruchGracza);
                                    if (tmp_wr == 0) {
                                        // return to menu po zbiciu krola
                                        go_back_to_menu2 = true;
                                        go_back_to_menu_1vsBot = true;
                                        break;
                                    }
                                    else if (tmp_wr == 1) {
                                        git = true;
                                    }
                                }
                                else if (ruchGracza == gracz2) {
                                    int tmp_wr = wykonaj_ruch(wybor, figuryGracza2, gra, ruchGracza);
                                    if (tmp_wr == 0) {
                                        // return to menu po zbiciu krola
                                        go_back_to_menu2 = true;
                                        go_back_to_menu_1vsBot = true;
                                        break;
                                    }
                                    else if (tmp_wr == 1) {
                                        git = true;
                                    }
                                }
                            } while (!git);


                            // dodaje ruch do logow 
                            if (git) {
                                if (!save_to_logs_move(wybor, gra, logi)) {
                                    go_back_to_menu2 = true;
                                    go_back_to_menu_1vsBot = true;
                                }
                                else {
                                    // podanie ruchu do silnika
                                    prog.podaj_aktualna_pozycje(wybor, pozycja_startowa);
                                }
                            }
                        }
                        else if (USImove[1] == '*') {

                            char wybor[3];
                            wybor[0] = tolower(USImove[0]);
                            wybor[1] = USImove[2];
                            wybor[2] = USImove[3];

                            std::promise<bool> promise3;
                            std::promise<bool> promise4;
                            std::future<bool> fut3g1 = promise3.get_future();
                            std::future<bool> fut3g2 = promise4.get_future();

                            if (ruchGracza == gracz1) {
                                // git i idziemy z tym dalej czyli wystawiamy figure 
                                wykonanie_zrzutu(wybor, figuryGracza1, gra);
                                zapis_do_logow_programu_zrzutka(wybor, gra, logi);

                                prog.podaj_aktualna_pozycje_zrzutka(wybor, pozycja_startowa);

                                int x1 = -1; int y1 = -1;
                                int x2 = -1; int y2 = -1;
                                gdzieKrol(gracz1, gra, x1, y1);
                                gdzieKrol(gracz2, gra, x2, y2);
                                fut3g1 = std::async(std::launch::async, [&] { return gra[x1][y1].czySzach(gra, gracz1); }); // thread 3
                                fut3g2 = std::async(std::launch::async, [&] { return gra[x2][y2].czySzach(gra, gracz2); }); // thread 4

                                ruchGracza = gracz2; // zamiana ruchu 
                            }
                            else if (ruchGracza == gracz2) {
                                // git i idziemy z tym dalej czyli wystawiamy figure 
                                wykonanie_zrzutu(wybor, figuryGracza2, gra);
                                zapis_do_logow_programu_zrzutka(wybor, gra, logi);

                                prog.podaj_aktualna_pozycje_zrzutka(wybor, pozycja_startowa);

                                int x1 = -1; int y1 = -1;
                                int x2 = -1; int y2 = -1;
                                gdzieKrol(gracz1, gra, x1, y1);
                                gdzieKrol(gracz2, gra, x2, y2);
                                fut3g1 = std::async(std::launch::async, [&] { return gra[x1][y1].czySzach(gra, gracz1); }); // thread 3
                                fut3g2 = std::async(std::launch::async, [&] { return gra[x2][y2].czySzach(gra, gracz2); }); // thread 4

                                ruchGracza = gracz1; // zamiana ruchu                       
                            }

                            if (!back_to_menu_1vsBot) {
                                // czy nie powtarza sie szachowanie 
                                if (fut3g1.get() && logi.powtrzorzenie_ruchu()) logi.incIloscSzachowKrolGracza1();
                                else logi.setIloscSzachowKrolGracza1(0);

                                if (fut3g2.get() && logi.powtrzorzenie_ruchu()) logi.incIloscSzachowKrolGracza2();
                                else logi.setIloscSzachowKrolGracza2(0);

                                if (logi.getIloscSzachowKrolGracza1() >= 4) {
                                    koniec_przez_zaszachowanie(gracz1); // krol gracza 1 został zaszahcowany 4 razy z rzedu czyli wygrywa gracz2                               
                                    go_back_to_menu2 = true;
                                    break;
                                }
                                if (logi.getIloscSzachowKrolGracza2() >= 4) {
                                    koniec_przez_zaszachowanie(gracz2); // krol gracza 2 został zaszahcowany 4 razy z rzedu czyli wygrywa gracz1
                                    go_back_to_menu2 = true;
                                    break;
                                }
                            }
                            else {
                                if (fut3g1.get() && logi.powtrzorzenie_ruchu()) logi.incIloscSzachowKrolGracza1();
                                else logi.setIloscSzachowKrolGracza1(0);

                                if (fut3g2.get() && logi.powtrzorzenie_ruchu()) logi.incIloscSzachowKrolGracza2();
                                else logi.setIloscSzachowKrolGracza2(0);
                            }
                        }
                    }
                } while (!go_back_to_menu_1vsBot);
                // dest  Pole** gra; // przedstawia stan gry tablica 2 wymiarowa
                    
                for (int i = 0; i < 9; i++) {
                    delete[] gra[i];
                }
                delete[] gra;
                gra = 0;
            } while (!go_back_to_menu2);
        }
        else if (tryb == "zasady") {
            zasady();
        }
        else if (tryb == "exit") {
            koniec = true;
        }

    } while (!koniec);

    //_CrtDumpMemoryLeaks();
    return 1;
}
