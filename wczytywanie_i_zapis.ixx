module;

#include <iostream>
#include <string>
#include <regex>
#include <fstream>
#include <filesystem>
#include <thread>
#include <future>

export module wczytywanie_i_zapis;

export import SFEN_USI_gra;


#pragma region wczytywanie_standadrowa_startowa_pozycja

std::mutex idx;
// thread - mutex 
/**
* Funkcja (thread) ustawiajaca(tworzaca obiekty) figur graczay na planszy.
* @param pole - ca³a dwuwymiarowa tablica pól (czyli nasza szachownica na której rozgrywa siê rozgrywka).
*/
export void ustaw_figury_start_gracz1_i_2(Pole** pole) {
    std::lock_guard<std::mutex> lck1(idx);

    std::shared_ptr<Pion> p11 = std::make_shared<Pion>(pole[0][2], gracz1);
    pole[0][2].setFigura(p11);
    std::shared_ptr<Pion> p12 = std::make_shared<Pion>(pole[1][2], gracz1);
    pole[1][2].setFigura(p12);
    std::shared_ptr<Pion> p13 = std::make_shared<Pion>(pole[2][2], gracz1);
    pole[2][2].setFigura(p13);
    std::shared_ptr<Pion> p14 = std::make_shared<Pion>(pole[3][2], gracz1);
    pole[3][2].setFigura(p14);
    std::shared_ptr<Pion> p15 = std::make_shared<Pion>(pole[4][2], gracz1);
    pole[4][2].setFigura(p15);
    std::shared_ptr<Pion> p16 = std::make_shared<Pion>(pole[5][2], gracz1);
    pole[5][2].setFigura(p16);
    std::shared_ptr<Pion> p17 = std::make_shared<Pion>(pole[6][2], gracz1);
    pole[6][2].setFigura(p17);
    std::shared_ptr<Pion> p18 = std::make_shared<Pion>(pole[7][2], gracz1);
    pole[7][2].setFigura(p18);
    std::shared_ptr<Pion> p19 = std::make_shared<Pion>(pole[8][2], gracz1);
    pole[8][2].setFigura(p19);

    std::shared_ptr<Lanca> l11 = std::make_shared<Lanca>(pole[0][0], gracz1);
    pole[0][0].setFigura(l11);
    std::shared_ptr<Lanca> l12 = std::make_shared<Lanca>(pole[8][0], gracz1);
    pole[8][0].setFigura(l12);
    std::shared_ptr<Skoczek> n11 = std::make_shared<Skoczek>(pole[1][0], gracz1);
    pole[1][0].setFigura(n11);
    std::shared_ptr<Skoczek> n12 = std::make_shared<Skoczek>(pole[7][0], gracz1);
    pole[7][0].setFigura(n12);
    std::shared_ptr<mGeneral> s11 = std::make_shared<mGeneral>(pole[2][0], gracz1);
    pole[2][0].setFigura(s11);
    std::shared_ptr<mGeneral> s12 = std::make_shared<mGeneral>(pole[6][0], gracz1);
    pole[6][0].setFigura(s12);
    std::shared_ptr<dGeneral> g11 = std::make_shared<dGeneral>(pole[3][0], gracz1);
    pole[3][0].setFigura(g11);
    std::shared_ptr<dGeneral> g12 = std::make_shared<dGeneral>(pole[5][0], gracz1);
    pole[5][0].setFigura(g12);
    std::shared_ptr<Goniec> b1 = std::make_shared<Goniec>(pole[7][1], gracz1);
    pole[7][1].setFigura(b1);
    std::shared_ptr<Wieza> r1 = std::make_shared<Wieza>(pole[1][1], gracz1);
    pole[1][1].setFigura(r1);
    std::shared_ptr<Krol> k1 = std::make_shared<Krol>(pole[4][0], gracz1);
    pole[4][0].setFigura(k1);

    std::shared_ptr<Pion> p21 = std::make_shared<Pion>(pole[0][6], gracz2);
    pole[0][6].setFigura(p21);
    std::shared_ptr<Pion> p22 = std::make_shared<Pion>(pole[1][6], gracz2);
    pole[1][6].setFigura(p22);
    std::shared_ptr<Pion> p23 = std::make_shared<Pion>(pole[2][6], gracz2);
    pole[2][6].setFigura(p23);
    std::shared_ptr<Pion> p24 = std::make_shared<Pion>(pole[3][6], gracz2);
    pole[3][6].setFigura(p24);
    std::shared_ptr<Pion> p25 = std::make_shared<Pion>(pole[4][6], gracz2);
    pole[4][6].setFigura(p25);
    std::shared_ptr<Pion> p26 = std::make_shared<Pion>(pole[5][6], gracz2);
    pole[5][6].setFigura(p26);
    std::shared_ptr<Pion> p27 = std::make_shared<Pion>(pole[6][6], gracz2);
    pole[6][6].setFigura(p27);
    std::shared_ptr<Pion> p28 = std::make_shared<Pion>(pole[7][6], gracz2);
    pole[7][6].setFigura(p28);
    std::shared_ptr<Pion> p29 = std::make_shared<Pion>(pole[8][6], gracz2);
    pole[8][6].setFigura(p29);

    std::shared_ptr<Lanca> l21 = std::make_shared<Lanca>(pole[0][8], gracz2);
    pole[0][8].setFigura(l21);
    std::shared_ptr<Lanca> l22 = std::make_shared<Lanca>(pole[8][8], gracz2);
    pole[8][8].setFigura(l22);
    std::shared_ptr<Skoczek> n21 = std::make_shared<Skoczek>(pole[1][8], gracz2);
    pole[1][8].setFigura(n21);
    std::shared_ptr<Skoczek> n22 = std::make_shared<Skoczek>(pole[7][8], gracz2);
    pole[7][8].setFigura(n22);
    std::shared_ptr<mGeneral> s21 = std::make_shared<mGeneral>(pole[2][8], gracz2);
    pole[2][8].setFigura(s21);
    std::shared_ptr<mGeneral> s22 = std::make_shared<mGeneral>(pole[6][8], gracz2);
    pole[6][8].setFigura(s22);
    std::shared_ptr<dGeneral> g21 = std::make_shared<dGeneral>(pole[3][8], gracz2);
    pole[3][8].setFigura(g21);
    std::shared_ptr<dGeneral> g22 = std::make_shared<dGeneral>(pole[5][8], gracz2);
    pole[5][8].setFigura(g22);
    std::shared_ptr<Goniec> b2 = std::make_shared<Goniec>(pole[1][7], gracz2);
    pole[1][7].setFigura(b2);
    std::shared_ptr<Wieza> r2 = std::make_shared<Wieza>(pole[7][7], gracz2);
    pole[7][7].setFigura(r2);
    std::shared_ptr<Krol> k2 = std::make_shared<Krol>(pole[4][8], gracz2);
    pole[4][8].setFigura(k2);
}

// thread - mutex
/**
* Funkcja (g³ówna) ustawiajaca(tworzaca obiekty) figur graczay na planszy.
* @param pole - ca³a dwuwymiarowa tablica pól (czyli nasza szachownica na której rozgrywa siê rozgrywka).
*/
export void ustaw_figury_start(Pole** pole) {

    std::vector<std::thread> vec(6);
    for (int i = 0; i < 6; i++)
        vec[i] = std::thread(ustaw_figury_start_gracz1_i_2, pole);
    for (auto& tmp : vec)
        tmp.join();
}

#pragma endregion wczytywanie_standadrowa_startowa_pozycja

#pragma region grupa_wczytanie_z_pliku

/**
* Funkcja sprawdzajaca format podanego pliku do wczytania.
* @param siezka - path wczytywanego pliku.
* @return Boolan czy format jest prawid³owy (true). W przeciwnym false.
*/
export bool format_wczytania(std::filesystem::path siezka) {

    bool tmp = true;
    std::ifstream odczyt(siezka);
    std::regex format_sprawdz_figGracz("\\b(p|l|n|s|g|b|r)*\\b");
    std::regex format_sprawdz_plansza("(([12][pPlLnNsSgGbBrRK])|(  )){9}");
    std::regex format_sprawdz_koleiki("[12]");
    std::regex format_sprawdz_ruchy("(([AaBbCcDdEeFfGgHhIi][123456789])|([plnsgbr][*]))-[AaBbCcDdEeFfGgHhIi][123456789]\\b");
    std::string fig_gracz1, fig_gracz2, linia, player, linia2;
    std::getline(odczyt, fig_gracz1);
    std::getline(odczyt, fig_gracz2);

    //size_t n = std::count(s.begin(), s.end(), '_');
    __int64 ilosc_p = 0;//18; 
    __int64 ilosc_l = 0;//4;
    __int64 ilosc_n = 0;//4;
    __int64 ilosc_s = 0;//4;
    __int64 ilosc_g = 0;//4;
    __int64 ilosc_b = 0;//2;
    __int64 ilosc_r = 0;//2;
    __int64 ilosc_1K = 0;//2;
    __int64 ilosc_2K = 0;//2;

    // sprwdz czy jest git fromat dla figurGracza1 jak nie to przerwij
    if (!std::regex_match(fig_gracz1, format_sprawdz_figGracz)) {
        wstaw_tekst(25, 16, "Zawartosc podanego pliku jest nieprawidlowa. Prosze podac inny plik.", "Orange");
        tmp = false;
    }
    else {
        // policz ile jest figur ogl
        ilosc_p += std::ranges::count(fig_gracz1.begin(), fig_gracz1.end(), 'p');
        ilosc_l += std::ranges::count(fig_gracz1.begin(), fig_gracz1.end(), 'l');
        ilosc_n += std::ranges::count(fig_gracz1.begin(), fig_gracz1.end(), 'n');
        ilosc_s += std::ranges::count(fig_gracz1.begin(), fig_gracz1.end(), 's');
        ilosc_g += std::ranges::count(fig_gracz1.begin(), fig_gracz1.end(), 'g');
        ilosc_b += std::ranges::count(fig_gracz1.begin(), fig_gracz1.end(), 'b');
        ilosc_r += std::ranges::count(fig_gracz1.begin(), fig_gracz1.end(), 'r');
    }
    // sprwdz czy jest git fromat dla figurGracza2 jak nie to przerwij
    if (!std::regex_match(fig_gracz2, format_sprawdz_figGracz)) {
        wstaw_tekst(25, 16, "Zawartosc podanego pliku jest nieprawidlowa. Prosze podac inny plik.", "Orange");
        tmp = false;
    }
    else {
        // polic ile jest figur ogl
        ilosc_p += std::ranges::count(fig_gracz2.begin(), fig_gracz2.end(), 'p');
        ilosc_l += std::ranges::count(fig_gracz2.begin(), fig_gracz2.end(), 'l');
        ilosc_n += std::ranges::count(fig_gracz2.begin(), fig_gracz2.end(), 'n');
        ilosc_s += std::ranges::count(fig_gracz2.begin(), fig_gracz2.end(), 's');
        ilosc_g += std::ranges::count(fig_gracz2.begin(), fig_gracz2.end(), 'g');
        ilosc_b += std::ranges::count(fig_gracz2.begin(), fig_gracz2.end(), 'b');
        ilosc_r += std::ranges::count(fig_gracz2.begin(), fig_gracz2.end(), 'r');
    }

    // sprwdz czy jest git fromat dla pola jak nie to przerwij
    int ii = 0;
    // podliczyæ ile figur jest na planszy
    while (ii < 9) {
        std::getline(odczyt, linia);
        if (!std::regex_match(linia, format_sprawdz_plansza)) {
            wstaw_tekst(25, 16, "Zawartosc podanego pliku jest nieprawidlowa. Prosze podac inny plik.", "Orange");
            tmp = false;
        }
        else {
            // policz ile jest figur ogl
            ilosc_p += std::ranges::count(linia.begin(), linia.end(), 'p');
            ilosc_l += std::ranges::count(linia.begin(), linia.end(), 'l');
            ilosc_n += std::ranges::count(linia.begin(), linia.end(), 'n');
            ilosc_s += std::ranges::count(linia.begin(), linia.end(), 's');
            ilosc_g += std::ranges::count(linia.begin(), linia.end(), 'g');
            ilosc_b += std::ranges::count(linia.begin(), linia.end(), 'b');
            ilosc_r += std::ranges::count(linia.begin(), linia.end(), 'r');
            ilosc_p += std::ranges::count(linia.begin(), linia.end(), 'P');
            ilosc_l += std::ranges::count(linia.begin(), linia.end(), 'L');
            ilosc_n += std::ranges::count(linia.begin(), linia.end(), 'N');
            ilosc_s += std::ranges::count(linia.begin(), linia.end(), 'S');
            ilosc_g += std::ranges::count(linia.begin(), linia.end(), 'G');
            ilosc_b += std::ranges::count(linia.begin(), linia.end(), 'B');
            ilosc_r += std::ranges::count(linia.begin(), linia.end(), 'R');

            std::string find2K = "2K";
            std::string find1K = "1K";
            std::string::size_type pos = 0;
            while ((pos = linia.find(find2K, pos)) != std::string::npos) {
                ilosc_2K++;
                pos += find2K.length();
            }
            pos = 0;
            while ((pos = linia.find(find1K, pos)) != std::string::npos) {
                ilosc_1K++;
                pos += find1K.length();
            }
        }
        ii++;
    }

    if (ilosc_p == 18 && ilosc_l == 4 && ilosc_n == 4 && ilosc_s == 4 && ilosc_g == 4 && ilosc_b == 2 && ilosc_r == 2 && ilosc_1K == 1 && ilosc_2K == 1) {}
    else {
        wstaw_tekst(25, 16, "Zawartosc podanego pliku jest nieprawidlowa. Prosze podac inny plik.", "Orange");
        tmp = false;
    }

    // sprwdz czy jest git fromat dla czyj teraz ruch jak nie to przerwij
    std::getline(odczyt, player);
    if (!std::regex_match(player, format_sprawdz_koleiki)) {
        wstaw_tekst(25, 16, "Zawartosc podanego pliku jest nieprawidlowa. Prosze podac inny plik.", "Orange");
        tmp = false;
    }

    while (std::getline(odczyt, linia2)) {
        if (!std::regex_match(linia2, format_sprawdz_ruchy)) {
            wstaw_tekst(25, 16, "Zawartosc podanego pliku jest nieprawidlowa. Prosze podac inny plik.", "Orange");
            tmp = false;
        }
        ii++;
    }
    odczyt.close();
    return tmp;
}

// interfejst do podawania pliku do wczytania i test czy wczytywanie jest poprawne
/**
* Funkcja interfejsu do podawania pliku do wczytania.
* @return path wczytywanego pliku.
*/
export std::filesystem::path wczytaj_figury_interfejs() {

    std::regex back_fromat("\\b[Bb][Aa][Cc][Kk]\\b");
    std::filesystem::path siezka;
    do {
        wstaw_tekst(25, 15, "Podaj sciezke do pliku z jakiego rozgrywka ma byc wczytana gra", "Green"); // +sciezke
        wstaw_tekst(25, 18, "Aby wrocic do menu wyboru typu ruchu wpisac 'back'.", "Green");
        bool gut = false;
        std::string nazwa1 = "";
        do {
            wstaw_tekst(25, 17, "Format: ['../nazwa_plik.txt']: ", "Green");
            wstaw_tekst(56, 17, "", "Orange");
            std::cin >> nazwa1;
            wstaw_tekst(56, 17, "                                                  ", "Orange");
            wstaw_tekst(25, 16, "                                                                                     ", "Orange");

            if (std::regex_match(nazwa1, back_fromat)) return "";

            siezka = nazwa1;
            if (std::filesystem::exists(siezka)) gut = true; // sprwdzic czy siezka istnieje na prawde 
            else wstaw_tekst(25, 16, "Podana sciezka/plik nie istnieje. Prosze podac ruch ponownie.", "Orange");
            if (siezka.extension() != ".txt") {
                wstaw_tekst(25, 16, "Plik ktory podales nie jest plikiem tekstowym. Prosze podac ruch ponownie.", "Orange");
                gut = false;
            }
        } while (!gut);
        wstaw_tekst(25, 15, "                                                                                     ", "Green");
        wstaw_tekst(25, 18, "                                                                                     ", "Green");
    } while (!format_wczytania(siezka));

    return siezka;
}

// thread - asnyc2
/**
* Funkcja wczytujaca do programu figury gracz 1.
* @param figuryGracza1 - FiguryGracza 1 z programu.
* @param fig_gracz1 - string figur 1 gracza z plilu.
* @return
*/
export void wczytaj_figury_gracza1(FiguryGracza& figuryGracza1, std::string& fig_gracz1) {
    // 1 linijka to figury gracza 1
    std::regex format_czego("\\b[plnsgbr]\\b");
    while (!fig_gracz1.empty()) {
        std::string sub = fig_gracz1.substr(0, 1); // 1 znak
        if (std::regex_match(sub, format_czego)) {
            // create new figura w zaleznosci jaki sybmol i dodaj do figuryGracza
            if (sub == "p") figuryGracza1.dodaj(std::make_shared<Pion>(gracz1));
            else if (sub == "l") figuryGracza1.dodaj(std::make_shared<Lanca>(gracz1));
            else if (sub == "n") figuryGracza1.dodaj(std::make_shared<Skoczek>(gracz1));
            else if (sub == "s") figuryGracza1.dodaj(std::make_shared<mGeneral>(gracz1));
            else if (sub == "g") figuryGracza1.dodaj(std::make_shared<dGeneral>(gracz1));
            else if (sub == "b") figuryGracza1.dodaj(std::make_shared<Goniec>(gracz1));
            else if (sub == "r") figuryGracza1.dodaj(std::make_shared<Wieza>(gracz1));
        }
        fig_gracz1 = fig_gracz1.substr(1, fig_gracz1.size());
    }
}

// thread - asnyc2
/**
* Funkcja wczytujaca do programu figury gracz 2.
* @param figuryGracza2 - FiguryGracza 2 z programu.
* @param fig_gracz2 - string figur 2 gracza z plilu.*/
export void wczytaj_figury_gracza2(FiguryGracza& figuryGracza2, std::string& fig_gracz2) {
    // 2 linijka to figury gracza 2 
    std::regex format_czego("\\b[plnsgbr]\\b");
    while (!fig_gracz2.empty()) {
        std::string sub = fig_gracz2.substr(0, 1); // 1 znak
        if (std::regex_match(sub, format_czego)) {
            // create new figura w zaleznosci jaki sybmol i dodaj do figuryGracza
            if (sub == "p") figuryGracza2.dodaj(std::make_shared<Pion>(gracz2));
            else if (sub == "l") figuryGracza2.dodaj(std::make_shared<Lanca>(gracz2));
            else if (sub == "n") figuryGracza2.dodaj(std::make_shared<Skoczek>(gracz2));
            else if (sub == "s") figuryGracza2.dodaj(std::make_shared<mGeneral>(gracz2));
            else if (sub == "g") figuryGracza2.dodaj(std::make_shared<dGeneral>(gracz2));
            else if (sub == "b") figuryGracza2.dodaj(std::make_shared<Goniec>(gracz2));
            else if (sub == "r") figuryGracza2.dodaj(std::make_shared<Wieza>(gracz2));
        }
        fig_gracz2 = fig_gracz2.substr(1, fig_gracz2.size());
    }
}

// thread - asnyc2
/**
* Funkcja wczytujaca do programu plansze.
* @param pole - ca³a dwuwymiarowa tablica pól (czyli nasza szachownica na której rozgrywa siê rozgrywka).
* @param odczyt - ifstream wczytywanego pliku
*/
export void wczytaj_figury_plansza(Pole** pole, std::ifstream& odczyt) {
    // 3+ (3 do 11) to plansza
    std::regex format_czego_plansza("\\b[pPlLnNsSgGbBrRK]\\b");
    std::string linia;
    int i = 0; // ilosc lini czyli wierszy
    while (i < 9) {
        std::getline(odczyt, linia);
        int j = 0; // ilosc w komulnie
        while (!linia.empty()) {
            std::string sub2 = linia.substr(0, 1); // 1 znak
            std::string sub = linia.substr(1, 1); // 1 znak
            Gracz gTMP = brak;
            if (sub2 == "1") gTMP = gracz1;
            else if (sub2 == "2") gTMP = gracz2;

            if (std::regex_match(sub, format_czego_plansza)) {
                // create new figura w zaleznosci jaki sybmol i dodaj na plansze 
                if (sub == "p") pole[j][i].setFigura(std::make_shared<Pion>(pole[j][i], gTMP));
                else if (sub == "P") pole[j][i].setFigura(std::make_shared<Pion>(pole[j][i], gTMP, Promocja::promocja)); // promowany pion
                else if (sub == "l") pole[j][i].setFigura(std::make_shared<Lanca>(pole[j][i], gTMP));
                else if (sub == "L") pole[j][i].setFigura(std::make_shared<Lanca>(pole[j][i], gTMP, Promocja::promocja)); // promowana lanca
                else if (sub == "n") pole[j][i].setFigura(std::make_shared<Skoczek>(pole[j][i], gTMP));
                else if (sub == "N") pole[j][i].setFigura(std::make_shared<Skoczek>(pole[j][i], gTMP, Promocja::promocja)); // promowana skoczek
                else if (sub == "s") pole[j][i].setFigura(std::make_shared<mGeneral>(pole[j][i], gTMP));
                else if (sub == "S") pole[j][i].setFigura(std::make_shared<mGeneral>(pole[j][i], gTMP, Promocja::promocja)); // promowana mGen
                else if (sub == "g") pole[j][i].setFigura(std::make_shared<dGeneral>(pole[j][i], gTMP));
                else if (sub == "G") pole[j][i].setFigura(std::make_shared<dGeneral>(pole[j][i], gTMP, Promocja::promocja)); // promowana dGen
                else if (sub == "b") pole[j][i].setFigura(std::make_shared<Goniec>(pole[j][i], gTMP));
                else if (sub == "B") pole[j][i].setFigura(std::make_shared<Goniec>(pole[j][i], gTMP, Promocja::promocja)); // promowana goniec
                else if (sub == "r") pole[j][i].setFigura(std::make_shared<Wieza>(pole[j][i], gTMP));
                else if (sub == "R") pole[j][i].setFigura(std::make_shared<Wieza>(pole[j][i], gTMP, Promocja::promocja)); // promowana wieza
                else if (sub == "K") pole[j][i].setFigura(std::make_shared<Krol>(pole[j][i], gTMP));
            }
            else if (sub == " ") {
                // nic nie rob po prsotu rob dalej
            }
            linia = linia.substr(2, linia.size());
            j++;
        }
        i++;
    }
}

// thread - main_asnyc2
/**
* G³ówna funkcja wczytujaca z pliku.
* @param pole - ca³a dwuwymiarowa tablica pól (czyli nasza szachownica na której rozgrywa siê rozgrywka).
* @param figuryGracza1 - obiekt FiguryGracza do ktorego zostana wpisane figury Gracza 1 z pliku
* @param figuryGracza2 - obiekt FiguryGracza do ktorego zostana wpisane figury Gracza 1 z pliku
* @param ruchGracza - zmienna Gracz ktora zostanie ustawiona czyj jest teraz ruch z pliku
* @param logi - obiekt Logi do ktorego zostana wpisane logi z pliku
* @param siezka - path pliku z jakiego zostanie przeprowadzone wczytywanie
*/
export void wczytaj_figury(Pole** pole, FiguryGracza& figuryGracza1, FiguryGracza& figuryGracza2, Gracz& ruchGracza, Logs& logi, std::filesystem::path siezka) {

    std::ifstream odczyt(siezka);
    std::string fig_gracz1, fig_gracz2, player, linia2;
    std::getline(odczyt, fig_gracz1);
    std::getline(odczyt, fig_gracz2);

    auto fut1 = std::async(std::launch::async, [&] { return wczytaj_figury_gracza1(figuryGracza1, fig_gracz1); }); // thread 1 
    auto fut2 = std::async(std::launch::async, [&] { return wczytaj_figury_gracza2(figuryGracza2, fig_gracz2); }); // thread 2 
    auto fut3 = std::async(std::launch::async, [&] { return wczytaj_figury_plansza(pole, odczyt); }); // thread 3
    fut1.get();
    fut2.get();
    fut3.get();

    std::getline(odczyt, player);
    if (player == "1") ruchGracza = gracz1;
    else if (player == "2") ruchGracza = gracz2;

    while (std::getline(odczyt, linia2)) {
        std::string sub_z = linia2.substr(0, 2); // 1 znak
        std::string sub_na = linia2.substr(3, 2); // 1 znak
        std::pair<std::string, std::string> para(sub_z, sub_na);
        logi.addToRuch(para);
    }

    odczyt.close();
}

#pragma endregion grupa_wczytanie_z_pliku

#pragma region zapis_do_pliku

/**
* Funkcja tworzoaca format planszy do zapisu planszy do pliku.
* @param pole - ca³a dwuwymiarowa tablica pól (czyli nasza szachownica na której rozgrywa siê rozgrywka).
* @return string formatu zapisu planszy do pliku
*/
export std::string zapisz_planszy(Pole** pole) {
    std::string tmp = "";
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (pole[j][i].getStatusShort() != "") {
                std::string tmpp = "";
                if (pole[j][i].getStatusShort() == "p") {
                    if (pole[j][i].isEmptyPion()->getGracz() == 1) tmpp = "1";
                    else tmpp = "2";
                    tmp += tmpp;
                    tmp += pole[j][i].isEmptyPion()->getZnak();
                }
                else if (pole[j][i].getStatusShort() == "l") {
                    if (pole[j][i].isEmptyLanca()->getGracz() == 1) tmpp = "1";
                    else tmpp = "2";
                    tmp += tmpp;
                    tmp += pole[j][i].isEmptyLanca()->getZnak();
                }
                else if (pole[j][i].getStatusShort() == "n") {
                    if (pole[j][i].isEmptySkoczek()->getGracz() == 1) tmpp = "1";
                    else tmpp = "2";
                    tmp += tmpp;
                    tmp += pole[j][i].isEmptySkoczek()->getZnak();
                }
                else if (pole[j][i].getStatusShort() == "s") {
                    if (pole[j][i].isEmptymGeneral()->getGracz() == 1) tmpp = "1";
                    else tmpp = "2";
                    tmp += tmpp;
                    tmp += pole[j][i].isEmptymGeneral()->getZnak();
                }
                else if (pole[j][i].getStatusShort() == "g") {
                    if (pole[j][i].isEmptydGeneral()->getGracz() == 1) tmpp = "1";
                    else tmpp = "2";
                    tmp += tmpp;
                    tmp += pole[j][i].isEmptydGeneral()->getZnak();
                }
                else if (pole[j][i].getStatusShort() == "b") {
                    if (pole[j][i].isEmptyGoniec()->getGracz() == 1) tmpp = "1";
                    else tmpp = "2";
                    tmp += tmpp;
                    tmp += pole[j][i].isEmptyGoniec()->getZnak();
                }
                else if (pole[j][i].getStatusShort() == "r") {
                    if (pole[j][i].isEmptyWieza()->getGracz() == 1) tmpp = "1";
                    else tmpp = "2";
                    tmp += tmpp;
                    tmp += pole[j][i].isEmptyWieza()->getZnak();
                }
                else if (pole[j][i].getStatusShort() == "K") {
                    if (pole[j][i].isEmptyKrol()->getGracz() == 1) tmpp = "1";
                    else tmpp = "2";
                    tmp += tmpp;
                    tmp += pole[j][i].isEmptyKrol()->getZnak();
                }
            }
            else {
                tmp += "  ";
            }
        }
        tmp += "\n";
    }
    return tmp;
}

/**
* G³ówna funkcja zapisu do pliku.
* @param pole - ca³a dwuwymiarowa tablica pól (czyli nasza szachownica na której rozgrywa siê rozgrywka).
* @param figuryGracza1 - obiekt FiguryGracza z ktorego zostana zapisane figury gracza 1.
* @param figuryGracza2 - obiekt FiguryGracza z ktorego zostana zapisane figury gracza 2.
* @param ruchGracza - zmienna Gracz ktora zostanie zapisana w pliku czyj jest teraz ruch.
* @param logi - obiekt Logi z ktorego zostana zapisane logi do pliku
* @param siezka - path pliku do ktorego zostanie przeprowadzony zapis
* @return boolean czy zapis sie powiód³, true inaczej false
*/
export bool zapisz_figury(Pole** pole, FiguryGracza figuryGracza1, FiguryGracza figuryGracza2, Gracz ruchGracza, Logs logi, std::filesystem::path& siezka) {
    // lokalizacja gdzie zapisac std::filesystem POTEM dodac
    std::regex format("\\b(\\d|\\w)+\\b");
    std::regex back_fromat("\\b[Bb][Aa][Cc][Kk]\\b");
    std::string nazwa;
    bool gut = false;
    bool gut2 = false;
    do {
        wstaw_tekst(25, 15, "Podaj sciezke gdzie plik z rozgrywka ma zostac zapisany", "Green");
        wstaw_tekst(25, 18, "Aby wrocic do menu wyboru typu ruchu wpisac 'back'.", "Green");
        wstaw_tekst(25, 17, "Fromat '../folder': ", "Green");
        wstaw_tekst(45, 17, "", "Orange");
        std::getline(std::cin, nazwa);
        wstaw_tekst(45, 17, "                                 ", "Orange");

        if (std::regex_match(nazwa, back_fromat)) {
            wstaw_tekst(25, 18, "                                                                     ", "Green");
            return false;
        }

        siezka = nazwa;
        if (std::filesystem::exists(siezka)) gut = true; // sprwdzic czy siezka istnieje na prawde 
        else wstaw_tekst(25, 16, "Podana sciezka/plik nie istnieje. Prosze podac ruch ponownie.", "Orange");

    } while (!gut);

    wstaw_tekst(25, 15, "                                                                         ", "Green");
    wstaw_tekst(25, 16, "                                                                         ", "Green");
    wstaw_tekst(25, 17, "                                                                         ", "Green");
    wstaw_tekst(25, 18, "                                                                         ", "Green");

    do {
        wstaw_tekst(25, 15, "Podaj nazwe pliku do jakiego ma zostac zapisana rogrywka", "Green");
        wstaw_tekst(25, 17, "Fromat 'nazwa': ", "Green");
        wstaw_tekst(41, 17, "", "Orange");
        std::getline(std::cin, nazwa);
        wstaw_tekst(41, 17, "                                 ", "Orange");

        if (std::regex_match(nazwa, format)) gut2 = true;
        else wstaw_tekst(25, 16, "Nieprawidlowy format nazwy pliku. Prosze podac ponownie nazwe.", "Orange");

    } while (!gut2);
    // dodaj nazwe do sciezki
    siezka = siezka / nazwa;
    // oraz dodaj rozszerzenie .txt
    siezka.replace_extension(".txt");

    std::ofstream zapis(siezka);

    // zapis figurGracza
    zapis << figuryGracza1.zapisz_figuryGracza_file(); // <- do pliku wypisac
    zapis << "\n";
    zapis << figuryGracza2.zapisz_figuryGracza_file(); // <- do pliku wypisac
    zapis << "\n";

    // zapis planszy
    zapis << zapisz_planszy(pole);

    // zapis ruchu gracza
    if (ruchGracza == gracz1) zapis << 1;
    else if (ruchGracza == gracz2) zapis << 2;

    // dodac zapis jakie byly ruchy
    zapis << "\n";
    zapis << logi.getAllRuch();


    zapis.close();
    return true;
}

#pragma endregion zapis_do_pliku
