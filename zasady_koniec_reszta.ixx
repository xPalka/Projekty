module;

#include <iostream>
#include <string>
#include <regex>
#include <thread>
#include <future>

export module zasady_koniec_reszta;

export import wczytywanie_i_zapis;


#pragma region zasady

/**
* Funkcja wypisujaca g³owne zasady gry shogi.
*/
export void zasady() {
    // wypisz wszystkie zasady 
   //wstaw_tekst(3, 2, "---------------------------------------------------------------------------------------------------------------", "Default"); // maks dlugosc
    wstaw_tekst(3, 3, "Zasady shogi nie sa trudne, i jak ktos umie grac w szachy tradycyjne,  szybko moze przestawic sie na japonskie", "Default");
    wstaw_tekst(3, 4, "zasady. Jako ze shogi wykorzystuja wiecej figur, plansza jest wieksza i jest rozmiaru 9 na 9 kratek. Celem gry", "Default");
    wstaw_tekst(3, 5, "jest zbicie krola przeciwnika.Gracz nie ma obowiazku informowania o szachu i gdy ten takiego ruchu nie zauwazy", "Default");
    wstaw_tekst(3, 6, "gre mozna zakonczyc poprzez zbicie krola.                                                                     ", "Default");
    wstaw_tekst(3, 7, "                                                                                                              ", "Default");
    wstaw_tekst(3, 8, "Podzia³ planszy do gry:                                                                                       ", "Dark Red");
    wstaw_tekst(3, 9, "    -Strefe 1 (watahsi- tu sa nasze figury) (3 wiersze z naszego brzegu planszy)                              ", "Default");
    wstaw_tekst(3, 10, "    -Strefe 2 (churitsu- strefa neutralna- srodkowa) (3 srodkowe wiersze)                                     ", "Default");
    wstaw_tekst(3, 11, "    -Strefe promocji (aite - strefa przeciwnika) (3 wiersze z przeciwnego brzegu planszy)                     ", "Default");
    wstaw_tekst(3, 12, "                                                                                                              ", "Default");
    wstaw_tekst(3, 13, "Ruchy podstawowych figur:                                                                                     ", "Dark Red");
    wstaw_tekst(3, 14, "Krol(K) - moze poruszac w kazdym kierunku o jedno pole.                                                       ", "Default");
    wstaw_tekst(3, 15, "Wieza(r) -  moze poruszac sie o dowolna ilosc pol po liniach pionowych i poziomych.                           ", "Default");
    wstaw_tekst(3, 16, "Goniec(b)- moze poruszac sie o dowolna ilosc pol po przekatnych.                                              ", "Default");
    wstaw_tekst(3, 17, "Z³oty genera³(g) - moze poruszyc sie o jedno pole w szesciu kierunkach: do przodu po prostej i po przekatnych,", "Default");
    wstaw_tekst(3, 18, "                   po prostej w lewo i prawo oraz do ty³u po prostej.                                         ", "Default");
    wstaw_tekst(3, 19, "Srebrny genera³(s) - moze poruszyc sie o jedno pole w pieciu kierunkach: do przodu po prostej oraz przekatnych", "Default");
    wstaw_tekst(3, 20, "                     i do ty³u po przekatnych. Nie moze chodzic na boki oraz do ty³u po prostej.              ", "Default");
    wstaw_tekst(3, 21, "Skoczek(n) - jak jego nazwa wskazuje moze przeskakiwac inne figury. Porusza sie tylko do przodu przeskakujac o", "Default");
    wstaw_tekst(3, 23, "             jedno pole w bok i dwa do przodu. Warto zwrocic uwage ze w przeciwienstwie do szachow zachodznich", "Default");
    wstaw_tekst(3, 24, "             w shogi skoczek nie moze ruszac sie skaczac na boki ani do ty³u.                                 ", "Default");
    wstaw_tekst(3, 25, "Lanca(l) - moze poruszyc sie o dowolna liczbe pol, lecz tylko do przodu.                                      ", "Default");
    wstaw_tekst(3, 26, "Pionek(p) - moze poruszyc sie tylo o jedno pole do przodu.  W przeciwienstwie do zachodnich szachow,  bije tez", "Default");
    wstaw_tekst(3, 27, "            tylko do przodu! (nie po skosach).                                                                ", "Default");
    wstaw_tekst(3, 28, "Ruchy figur rowniez rozpisane sa podczas rozgrywki.                                                           ", "Dark Blue");
    wstaw_tekst(3, 29, "                                                                                                              ", "Default");
    wstaw_tekst(3, 30, "Promocje:                                                                                                     ", "Dark Red");
    wstaw_tekst(3, 31, "Gdy nasze figury znajda sie w strefie promocji, moga zostac promowane i beda ruszac sie inaczej:              ", "Default");
    wstaw_tekst(3, 32, "    -Pionek,  lanca,  skoczek, srebrny genera³ po promocji zmieniaja sie w z³otego genera³a, czyli traca swoje", "Default");
    wstaw_tekst(3, 33, "     poprzednie mozliwosci poruszania sie a zyskuja ruchy z³otego                                             ", "Default");
    wstaw_tekst(3, 34, "    -Krol i z³oty genrea³ nie moga byc promowani.                                                             ", "Default");
    wstaw_tekst(3, 35, "    -Wieza i goniec zyskuja dodatkowe ruchy do tych, ktore wczesniej mieli:                                   ", "Default");
    wstaw_tekst(3, 36, "     -Promowana wieza [smok](R) zyskuje dodatkowo mozliwosc poruszania sie o jedno pole po przekatnych.       ", "Default");
    wstaw_tekst(3, 37, "     -Promowany goniec [kon](G) - zyskuje dodatkowo mozliwosc poruszania sie o jedno pole po liniach poziomych", "Default");
    wstaw_tekst(3, 38, "                                  i pionowych.                                                                ", "Default");
    wstaw_tekst(3, 39, "Promocja nie jest obowiazkowa, jesli dana figura ma mozliwosc wykonania kolejnego ruchu(np. gdyby lanca dosz³a", "Default");
    wstaw_tekst(3, 40, "do konca planszy, musi zostac promowana, gdyz w przeciwnym razie nie mog³a by sie juz wiecej poruszyc).       ", "Default");
    wstaw_tekst(3, 41, "                                                                                                              ", "Default");
    wstaw_tekst(3, 42, "Przyracanie figur (zrzutki):                                                                                  ", "Dark Red");
    wstaw_tekst(3, 43, "Zbite figury sa zdobywane przez gracza, ktory je zbija (i odk³adane sa na po prawej stronie planszy).  Dlatego", "Default");
    wstaw_tekst(3, 44, "zamiast ruchu gracz moze przywrocic wczesniej zbita przeciwnikowi figure.Moze ja przywrocic w dowolnym miejscu", "Default");
    wstaw_tekst(3, 45, "na planszy  –  jesli w nastepnej kolejce bedzie mog³a sie ona poruszyc (czyli np. nie mozemy przywrocic pionka", "Default");
    wstaw_tekst(3, 46, "lub lancy na ostatnia linie strefy promocji).Gdy przywracamy figure w strefie promocji, nie jest ona promowana", "Default");
    wstaw_tekst(3, 47, "Pionek nie moze byc przywrocony tak, zeby dawa³ szachmata (lecz inne figury mozna tak przywracac).            ", "Default");
    wstaw_tekst(3, 48, "Nie mozna przywrocic pionka w linii (pionowej), w ktorej juz jest jeden pionek.                               ", "Default");
    wstaw_tekst(3, 49, "Musi ona wykonac dopiero nastepny ruch (w tej strefie), aby mog³a byc promowana.                              ", "Default");
    wstaw_tekst(3, 50, "                                                                                                              ", "Default");
    wstaw_tekst(3, 51, "Zakonczenie gry:                                                                                              ", "Dark Red");
    wstaw_tekst(3, 52, "Gre zakonczyc mozna najprosciej przez zbicie krola przeciwnika.                                               ", "Default");
    wstaw_tekst(3, 53, "W przypadku impasu liczy sie punkty wed³ug schematu wieza i goniec po 5 punktow, pozosta³e figury oprocz krola", "Default");
    wstaw_tekst(3, 54, "po 1 punkcie. Jesli jeden z graczy ma mniej niz 24 punktow, przegrywa.  Jesli oboje maja wiecej niz 24 punktow", "Default");
    wstaw_tekst(3, 55, "nastepuje remis, w przypadku partii rozgrywanej przez profesjonalistow – gre powtarza sie ze zmiana gracza.   ", "Default");
    wstaw_tekst(3, 56, "Zgodnie z zasadami 'wieczny szach' jest niedozwolony. W takiej sytuacji przegrywa gracz, ktory szachuje.      ", "Default");
    wstaw_tekst(3, 57, "Rowniez pozycja okreslana jako 'pat' nie oznacza remisu. Strona, ktora posiada jedynie krola, przegrywa.      ", "Default");
    wstaw_tekst(3, 58, "                                                                                                              ", "Default");
    wstaw_tekst(3, 59, "Wiecej o shogi mozna wyczytac na stronach 'wikipedia.org/wiki/Shogi' lub 'kgj.pjwstk.edu.pl/shogi/zasady.html'", "Pink");
    wstaw_tekst(3, 60, "Aby przejsc do menu. ", "Pink");
    wstaw_tekst(24, 60, "", "Pink");
    system("pause");
}

/**
* Funkcja wypiusjaca podczas rogrywki zasady ruchow figur w shogi.
*/
export void zasady_ruchow() {

    // wypisz wszystkie zasady jak kazda figura sie moze ruszac 
    wstaw_tekst(3, 22, "-------------------------------------------------------------------------------------------------------------", "Default");
    wstaw_tekst(21, 23, "    'p'             'l'             'n'          'P''L''N'          's'             'S'    ", "Green");
    wstaw_tekst(21, 24, "                                                 promowany        srebrny        promowany ", "Green");
    wstaw_tekst(21, 25, "   pionek          lanca          skoczek    pion/lanca/skoczek   general       sr. general", "Green");
    wstaw_tekst(21, 26, "| | | | | |     | | ||| | |     | |x| |x| |     | | | | | |     | | | | | |     | | | | | |", "Default");
    wstaw_tekst(21, 27, "-----------     -----------     -----------     -----------     -----------     -----------", "Default");
    wstaw_tekst(21, 28, "| | |x| | |     | | ||| | |     | | | | | |     | |x|x|x| |     | |x|x|x| |     | |x|x|x| |", "Default");
    wstaw_tekst(21, 29, "-----------     -----------     -----------     -----------     -----------     -----------", "Default");
    wstaw_tekst(21, 30, "| | |p| | |     | | |l| | |     | | |n| | |     | |x|P|x| |     | | |s| | |     | |x|S|x| |", "Default");
    wstaw_tekst(21, 31, "-----------     -----------     -----------     -----------     -----------     -----------", "Default");
    wstaw_tekst(21, 32, "| | | | | |     | | | | | |     | | | | | |     | | |x| | |     | |x| |x| |     | | |x| | |", "Default");
    wstaw_tekst(21, 33, "-----------     -----------     -----------     -----------     -----------     -----------", "Default");
    wstaw_tekst(21, 34, "| | | | | |     | | | | | |     | | | | | |     | | | | | |     | | | | | |     | | | | | |", "Default");
    wstaw_tekst(21, 35, "  1 punkt         1 punkt         1 punkt         1 punkt         1 punkt         1 punkt  ", "Green");

    wstaw_tekst(3, 36, "-------------------------------------------------------------------------------------------------------------", "Default");
    wstaw_tekst(21, 37, "    'g'             'b'             'B'             'r'             'R'             'K'    ", "Green");
    wstaw_tekst(21, 38, "                                  promowany                      promowana                 ", "Green");
    wstaw_tekst(21, 39, "   zloty                           goniec                          wieza                   ", "Green");
    wstaw_tekst(21, 40, "  general         goniec           (Kon)           wieza          (smok)            Krol   ", "Green");
    wstaw_tekst(21, 41, "| | | | | |     |\\| | | |/|     |\\| | | |/|     | | ||| | |     | | ||| | |     | | | | | |", "Default");
    wstaw_tekst(21, 42, "-----------     -----------     -----------     -----------     -----------     -----------", "Default");
    wstaw_tekst(21, 43, "| |x|x|x| |     | |\\| |/| |     | |\\|x|/| |     | | ||| | |     | |x|||x| |     | |x|x|x| |", "Default");
    wstaw_tekst(21, 44, "-----------     -----------     -----------     -----------     -----------     -----------", "Default");
    wstaw_tekst(21, 45, "| |x|g|x| |     | | |b| | |     | |x|B|x| |     |-|-|r|-|-|     |-|-|R|-|-|     | |x|K|x| |", "Default");
    wstaw_tekst(21, 46, "-----------     -----------     -----------     -----------     -----------     -----------", "Default");
    wstaw_tekst(21, 47, "| | |x| | |     | |/| |\\| |     | |/|x|\\| |     | | ||| | |     | |x|||x| |     | |x|x|x| |", "Default");
    wstaw_tekst(21, 48, "-----------     -----------     -----------     -----------     -----------     -----------", "Default");
    wstaw_tekst(21, 49, "| | | | | |     |/| | | |\\|     |/| | | |\\|     | | ||| | |     | | ||| | |     | | | | | |", "Default");
    wstaw_tekst(21, 50, "  1 punkt        5 punktow       5 punktow       5 punktow       5 punktow       0 punktow ", "Green");
    wstaw_tekst(3, 51, "-------------------------------------------------------------------------------------------------------------", "Default");
}

/**
* Funkcja wypiusjaca podczas rogrywki ruchy figur w shogi.
*/
export void zasady_ruchow_znaki() {

    wstaw_tekst(3, 23, "      Symbol:     ", "Green");
    wstaw_tekst(3, 25, "Nazwa figury:     ", "Green");
    wstaw_tekst(3, 34, "        Ruch:     ", "Green");
    wstaw_tekst(3, 35, " Wartosc pkt:     ", "Green");
    wstaw_tekst(3, 37, "      Symbol:     ", "Green");
    wstaw_tekst(3, 40, "Nazwa figury:     ", "Green");
    wstaw_tekst(3, 49, "        Ruch:     ", "Green");
    wstaw_tekst(3, 50, " Wartosc pkt:     ", "Green");


    wstaw_tekst(26, 28, "x", "Red");
    wstaw_tekst(26, 30, "p", "Yellow");

    wstaw_tekst(42, 28, "|", "Red");
    wstaw_tekst(42, 26, "|", "Red");
    wstaw_tekst(42, 30, "l", "Yellow");

    wstaw_tekst(56, 26, "x", "Red");
    wstaw_tekst(60, 26, "x", "Red");
    wstaw_tekst(58, 30, "n", "Yellow");

    wstaw_tekst(72, 28, "x", "Red");
    wstaw_tekst(74, 28, "x", "Red");
    wstaw_tekst(76, 28, "x", "Red");
    wstaw_tekst(72, 30, "x", "Red");
    wstaw_tekst(76, 30, "x", "Red");
    wstaw_tekst(74, 32, "x", "Red");
    wstaw_tekst(74, 30, "P", "Yellow");

    wstaw_tekst(92, 28, "x", "Red");
    wstaw_tekst(90, 28, "x", "Red");
    wstaw_tekst(88, 28, "x", "Red");
    wstaw_tekst(88, 32, "x", "Red");
    wstaw_tekst(92, 32, "x", "Red");
    wstaw_tekst(90, 30, "s", "Yellow");

    wstaw_tekst(104, 28, "x", "Red");
    wstaw_tekst(106, 28, "x", "Red");
    wstaw_tekst(108, 28, "x", "Red");
    wstaw_tekst(104, 30, "x", "Red");
    wstaw_tekst(108, 30, "x", "Red");
    wstaw_tekst(106, 32, "x", "Red");
    wstaw_tekst(106, 30, "S", "Yellow");
    // ----------------------- 1 linia koniec

    wstaw_tekst(24, 43, "x", "Red");
    wstaw_tekst(26, 43, "x", "Red");
    wstaw_tekst(28, 43, "x", "Red");
    wstaw_tekst(24, 45, "x", "Red");
    wstaw_tekst(28, 45, "x", "Red");
    wstaw_tekst(26, 47, "x", "Red");
    wstaw_tekst(26, 45, "g", "Yellow");


    wstaw_tekst(46, 49, "\\", "Red");
    wstaw_tekst(44, 47, "\\", "Red");
    wstaw_tekst(40, 43, "\\", "Red");
    wstaw_tekst(38, 41, "\\", "Red");
    wstaw_tekst(46, 41, "/", "Red");
    wstaw_tekst(44, 43, "/", "Red");
    wstaw_tekst(40, 47, "/", "Red");
    wstaw_tekst(38, 49, "/", "Red");
    wstaw_tekst(42, 45, "b", "Yellow");


    wstaw_tekst(62, 49, "\\", "Red");
    wstaw_tekst(60, 47, "\\", "Red");
    wstaw_tekst(56, 43, "\\", "Red");
    wstaw_tekst(54, 41, "\\", "Red");
    wstaw_tekst(62, 41, "/", "Red");
    wstaw_tekst(60, 43, "/", "Red");
    wstaw_tekst(56, 47, "/", "Red");
    wstaw_tekst(54, 49, "/", "Red");
    wstaw_tekst(58, 43, "x", "Red");
    wstaw_tekst(58, 47, "x", "Red");
    wstaw_tekst(56, 45, "x", "Red");
    wstaw_tekst(60, 45, "x", "Red");
    wstaw_tekst(58, 45, "B", "Yellow");


    wstaw_tekst(70, 45, "-", "Red");
    wstaw_tekst(72, 45, "-", "Red");
    wstaw_tekst(76, 45, "-", "Red");
    wstaw_tekst(78, 45, "-", "Red");
    wstaw_tekst(74, 41, "|", "Red");
    wstaw_tekst(74, 43, "|", "Red");
    wstaw_tekst(74, 47, "|", "Red");
    wstaw_tekst(74, 49, "|", "Red");
    wstaw_tekst(74, 45, "r", "Yellow");

    wstaw_tekst(86, 45, "-", "Red");
    wstaw_tekst(88, 45, "-", "Red");
    wstaw_tekst(92, 45, "-", "Red");
    wstaw_tekst(94, 45, "-", "Red");
    wstaw_tekst(90, 41, "|", "Red");
    wstaw_tekst(90, 43, "|", "Red");
    wstaw_tekst(90, 47, "|", "Red");
    wstaw_tekst(90, 49, "|", "Red");
    wstaw_tekst(88, 43, "x", "Red");
    wstaw_tekst(92, 43, "x", "Red");
    wstaw_tekst(88, 47, "x", "Red");
    wstaw_tekst(92, 47, "x", "Red");
    wstaw_tekst(90, 45, "R", "Yellow");

    wstaw_tekst(104, 43, "x", "Red");
    wstaw_tekst(106, 43, "x", "Red");
    wstaw_tekst(108, 43, "x", "Red");
    wstaw_tekst(104, 45, "x", "Red");
    wstaw_tekst(108, 45, "x", "Red");
    wstaw_tekst(104, 47, "x", "Red");
    wstaw_tekst(106, 47, "x", "Red");
    wstaw_tekst(108, 47, "x", "Red");
    wstaw_tekst(106, 45, "K", "Yellow");

}

#pragma endregion zasady

#pragma region zakonczenie_gry

/**
* Funkcja zakonczenia gra przez zbiecie krola innego gracza.
* @param ruchGracza - aktrualny ruch gracza.
*/
export void zbicie_krola(Gracz ruchGracza) {
    // wyczyœæ ekran
    clear_screan();

    // wyœwietl odpowiedni komunikat wygranej
    if (ruchGracza == gracz1) {
        wstaw_tekst(35, 12, "Gracz 1 zbil krola przeciwnika", "Pink");
        wstaw_tekst(39, 13, "Partie wygrywa gracz 1", "Red");
        wstaw_tekst(44, 14, "Gratulacje!!", "Pink");
        wstaw_tekst(36, 15, "Aby przejsc do menu glownego", "Pink");
        wstaw_tekst(35, 16, "", "Pink");
        system("pause");

    }
    else {
        wstaw_tekst(35, 12, "Gracz 2 zbil krola przeciwnika", "Pink");
        wstaw_tekst(39, 13, "Partie wygrywa gracz 2", "Blue");
        wstaw_tekst(44, 14, "Gratulacje!!", "Pink");
        wstaw_tekst(36, 15, "Aby przejsc do menu glownego", "Pink");
        wstaw_tekst(35, 16, "", "Pink");
        system("pause");

    }
}

/**
* Funkcja zakonczenia gra przez zbiecie krola bota.
*/
export void zbicie_krola_bot() {
    // wyœwietl odpowiedni komunikat wygranej

    wstaw_tekst(25, 15, "Bot poddal sie                                 ", "Pink");
    wstaw_tekst(25, 16, "Partie wygrywa gracz                           ", "Red");
    wstaw_tekst(25, 17, "Gratulacje!!                                   ", "Pink");
    wstaw_tekst(25, 18, "Aby przejsc do menu glownego                   ", "Pink");
    wstaw_tekst(25, 19, "                                               ", "Pink");
    wstaw_tekst(25, 20, "                                               ", "Pink");
    wstaw_tekst(25, 19, "", "Pink");
    system("pause");

}

// git - async
/**
* Funkcja liczaca pkt po zakonczeniu gry przez impas.
* @param gra - ca³a dwuwymiarowa tablica pól (czyli nasza szachownica na której rozgrywa siê rozgrywka).
* @param gracz - sprawdzana ilosc pkt gracza
* @return intereger ilosci punktów podnaego gracza
*/
export int pktLiczenie(Pole** gra, Gracz gracz) {

    // LICZYMY PKT WED£UG:
    //  -wie¿a i goniec po 5 punktów,
    //  -król po 0 pkt, 
    //  -pozosta³e figury po 1 punkcie, 

    int suma = 0;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (gra[j][i].getStatusShort() != "") {
                std::string tmpp = "";
                if (gra[j][i].getStatusShort() == "p") {
                    if (gra[j][i].isEmptyPion()->getGracz() == gracz) suma += 1;
                }
                else if (gra[j][i].getStatusShort() == "l") {
                    if (gra[j][i].isEmptyLanca()->getGracz() == gracz) suma += 1;
                }
                else if (gra[j][i].getStatusShort() == "n") {
                    if (gra[j][i].isEmptySkoczek()->getGracz() == gracz) suma += 1;
                }
                else if (gra[j][i].getStatusShort() == "s") {
                    if (gra[j][i].isEmptymGeneral()->getGracz() == gracz) suma += 1;
                }
                else if (gra[j][i].getStatusShort() == "g") {
                    if (gra[j][i].isEmptydGeneral()->getGracz() == gracz) suma += 1;
                }
                else if (gra[j][i].getStatusShort() == "b") {
                    if (gra[j][i].isEmptyGoniec()->getGracz() == gracz) suma += 5;
                }
                else if (gra[j][i].getStatusShort() == "r") {
                    if (gra[j][i].isEmptyWieza()->getGracz() == gracz) suma += 5;
                }
            }
        }
    }
    return suma;
}

// git - async
/**
* Funkcja zakonczenia gry przez remis/impas.
* @param gra - ca³a dwuwymiarowa tablica pól (czyli nasza szachownica na której rozgrywa siê rozgrywka).
*/
export void remis(Pole** gra) {

    std::future<int> fut1 = std::async(std::launch::async, [&] { return pktLiczenie(gra, gracz1); }); // thread 1 
    std::future<int> fut2 = std::async(std::launch::async, [&] { return pktLiczenie(gra, gracz2); }); // thread 2

    int pkt_gracz1 = fut1.get();
    int pkt_gracz2 = fut2.get();


    for (int i = 10; i <= 21; i++) {
        wstaw_tekst(25, i, "                                                                ");
    }
    wstaw_tekst(28, 10, "Czwarty raz zostala uzyskana ta sama pozycja", "Green");
    wstaw_tekst(41, 11, "Liczenie punktow...", "Green");
    if (pkt_gracz1 > 24 && pkt_gracz2 > 24) {
        // remis oboje uzyskali powy¿ej 24 pkt
        wstaw_tekst(36, 12, "Oboje gracze uzyskali 24 pkt", "Pink");
        wstaw_tekst(41, 13, "Wynikiem parti jest", "Pink");
        wstaw_tekst(48, 14, "Remis", "Default");
        wstaw_tekst(36, 15, "Aby przejsc do menu glownego", "Pink");
        wstaw_tekst(35, 16, "", "Pink");
        system("pause");
    }
    else if (pkt_gracz1 > 24 && pkt_gracz2 < 24) {
        // wygrywa gracz 1
        // gracz 2 nie zdo³a³ uzyskac 24 pkt
        wstaw_tekst(34, 12, "Gracz 2 nie zdolal uzyskac 24 pkt", "Pink");
        wstaw_tekst(39, 13, "Partie wygrywa gracz 1", "Red");
        wstaw_tekst(44, 14, "Gratulacje!!", "Pink");
        wstaw_tekst(36, 15, "Aby przejsc do menu glownego", "Pink");
        wstaw_tekst(35, 16, "", "Pink");
        system("pause");
    }
    else if (pkt_gracz1 < 24 && pkt_gracz2 > 24) {
        // wygrywa gracz 2
        // gracz 1 nie zdo³a³ uzyskac 24 pkt
        wstaw_tekst(34, 12, "Gracz 1 nie zdolal uzyskac 24 pkt", "Pink");
        wstaw_tekst(39, 13, "Partie wygrywa gracz 2", "Blue");
        wstaw_tekst(44, 14, "Gratulacje!!", "Pink");
        wstaw_tekst(36, 15, "Aby przejsc do menu glownego", "Pink");
        wstaw_tekst(35, 16, "", "Pink");
        system("pause");
    }
    else if (pkt_gracz1 < 24 && pkt_gracz2 < 24) {
        // niemozliwy przypadek 
        // remis nie udalo sie nikomu uzyskac powyzej 24 pkt
        wstaw_tekst(35, 12, "Oboje gracze nie uzyskali 24 pkt", "Pink");
        wstaw_tekst(41, 13, "Wynikiem parti jest", "Red");
        wstaw_tekst(48, 14, "Remis", "Default");
        wstaw_tekst(36, 15, "Aby przejsc do menu glownego", "Pink");
        wstaw_tekst(35, 16, "", "Pink");
        system("pause");
    }


}

/**
* Funkcja sprawdzajaca czy oba krole dotarly od swoich stref promocji (jezeli tak to remis - impas)
* @param gra - ca³a dwuwymiarowa tablica pól (czyli nasza szachownica na której rozgrywa siê rozgrywka).
* @return boolen true jezeli oba krole sa promowane
*/
export bool promocjaKroli(Pole** gra) {
    bool tmp1 = false;
    bool tmp2 = false;

    //znadz krola
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (gra[j][i].getStatusShort() != "") {
                if (gra[j][i].getStatusShort() == "K") {
                    if (gra[j][i].isEmptyKrol()->getGracz() == gracz1) {
                        if (gra[j][i].isEmptyKrol()->getPromotion() == Promocja::promocja)
                            tmp1 = true;
                    }
                    else if (gra[j][i].isEmptyKrol()->getGracz() == gracz2) {
                        if (gra[j][i].isEmptyKrol()->getPromotion() == Promocja::promocja)
                            tmp2 = true;
                    }
                }
            }
        }
    }

    return tmp1 && tmp2;
}

/**
* Funkcja konca gry przez zaszachowanie.
* @param x - gracz ktory zaszachowal
*/
export void koniec_przez_zaszachowanie(Gracz x) {
    if (x == gracz1) {
        wstaw_tekst(30, 12, "Gracz 1 zaszachowal krola gracza2 4 razy z rzedu", "Pink");
        wstaw_tekst(39, 13, "Partie wygrywa gracz 2", "Blue");
        wstaw_tekst(44, 14, "Gratulacje!!", "Pink");
        wstaw_tekst(36, 15, "Aby przejsc do menu glownego", "Pink");
        wstaw_tekst(35, 16, "", "Pink");
        system("pause");
    }
    else if (x == gracz2) {
        wstaw_tekst(30, 12, "Gracz 2 zaszachowal krola gracza1 4 razy z rzedu", "Pink");
        wstaw_tekst(39, 13, "Partie wygrywa gracz 1", "Red");
        wstaw_tekst(44, 14, "Gratulacje!!", "Pink");
        wstaw_tekst(36, 15, "Aby przejsc do menu glownego", "Pink");
        wstaw_tekst(35, 16, "", "Pink");
        system("pause");
    }
}

/**
* Funkcja konca gry przez poddanie sie gracza z graczem.
* @param ruchGracza - aktualny ruch gracza
*/
export void koniec_przez_poddanie_1vs1(Gracz ruchGracza) {
    if (ruchGracza == gracz1) {
        wstaw_tekst(41, 12, "Gracz 1 sie poddal", "Pink");
        wstaw_tekst(39, 13, "Partie wygrywa gracz 2", "Blue");
        wstaw_tekst(44, 14, "Gratulacje!!", "Pink");
        wstaw_tekst(36, 15, "Aby przejsc do menu glownego", "Pink");
        wstaw_tekst(35, 16, "", "Pink");
        system("pause");

    }
    else {
        wstaw_tekst(41, 12, "Gracz 2 sie poddal", "Pink");
        wstaw_tekst(39, 13, "Partie wygrywa gracz 1", "Red");
        wstaw_tekst(44, 14, "Gratulacje!!", "Pink");
        wstaw_tekst(36, 15, "Aby przejsc do menu glownego", "Pink");
        wstaw_tekst(35, 16, "", "Pink");
        system("pause");
    }
}

/**
* Funkcja konca gry przez poddanie sie gracza z botem.
* @param ruchGracza - aktualny ruch gracza
*/
export void koniec_przez_poddanie_1vsBot(Gracz ruchGracza) {
    if (ruchGracza == gracz1) {
        wstaw_tekst(41, 12, "Gracz sie poddal", "Pink");
        wstaw_tekst(39, 13, "Partie wygrywa bot", "Blue");
        wstaw_tekst(36, 14, "Aby przejsc do menu glownego", "Pink");
        wstaw_tekst(35, 15, "", "Pink");
        system("pause");

    }
    else {
        wstaw_tekst(41, 12, "Gracz sie poddal", "Pink");
        wstaw_tekst(39, 13, "Partie wygrywa bot", "Red");
        wstaw_tekst(36, 14, "Aby przejsc do menu glownego", "Pink");
        wstaw_tekst(35, 15, "", "Pink");
        system("pause");
    }
}

#pragma endregion zakonczenie_gry

#pragma region reszta

/**
* Funkcja sprawdzajaca gdzie znajduje sie krol.
* @param gracz - (Gracz) sprawdzny krol gracza
* @param gra - ca³a dwuwymiarowa tablica pól (czyli nasza szachownica na której rozgrywa siê rozgrywka).
* @param x - intereger x pozycji krola
* @param y - intereger y pozycji krola
*/
export void gdzieKrol(Gracz gracz, Pole** gra, int& x, int& y) {

    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            if (gra[i][j].getStatusShort() == "K")
                if (gra[i][j].isEmptyKrol()->getGracz() == gracz) {
                    y = j; x = i;
                }
}

/**
* Funkcja wykonuja zrzut
* @param wybor - tablica char ruchu
* @param figuryGracza - figury gracza ktory wykonuje zrzut.
* @param gra - ca³a dwuwymiarowa tablica pól (czyli nasza szachownica na której rozgrywa siê rozgrywka).
*/
export void wykonanie_zrzutu(char wybor[3], FiguryGracza& figuryGracza, Pole** gra) {
    // jezeli jest pionkiem 
    int y_to = char_to_int(wybor[1]);
    int x_to = char_to_int(wybor[2]);

    if (wybor[0] == 'p') {
        std::shared_ptr<Pion> tmp = figuryGracza.zwroc_Pion(); // to wez ostatni mozliwy adress pionka z tabeli
        if (tmp != nullptr) tmp->wykonajRuchZrzut(gra[x_to][y_to], tmp);
        figuryGracza.usun(tmp);
    }
    // jezeli jest lanca
    else if (wybor[0] == 'l') {
        std::shared_ptr<Lanca> tmp = figuryGracza.zwroc_Lanca(); // to wez ostatni mozliwy adress pionka z tabeli
        if (tmp != nullptr) tmp->wykonajRuchZrzut(gra[x_to][y_to], tmp);
        figuryGracza.usun(tmp);
    }
    // jezeli jest skoczek
    else if (wybor[0] == 'n') {
        std::shared_ptr<Skoczek> tmp = figuryGracza.zwroc_Skoczek(); // to wez ostatni mozliwy adress pionka z tabeli
        if (tmp != nullptr) tmp->wykonajRuchZrzut(gra[x_to][y_to], tmp);
        figuryGracza.usun(tmp);
    }
    // jezeli jest mGeneral
    else if (wybor[0] == 's') {
        std::shared_ptr<mGeneral> tmp = figuryGracza.zwroc_mGeneral(); // to wez ostatni mozliwy adress pionka z tabeli
        if (tmp != nullptr) tmp->wykonajRuchZrzut(gra[x_to][y_to], tmp);
        figuryGracza.usun(tmp);
    }
    // jezeli jest dGeneral
    else if (wybor[0] == 'g') {
        std::shared_ptr<dGeneral> tmp = figuryGracza.zwroc_dGeneral(); // to wez ostatni mozliwy adress pionka z tabeli
        if (tmp != nullptr) tmp->wykonajRuchZrzut(gra[x_to][y_to], tmp);
        figuryGracza.usun(tmp);
    }
    // jezeli jest goniec
    else if (wybor[0] == 'b') {
        std::shared_ptr<Goniec> tmp = figuryGracza.zwroc_Goniec(); // to wez ostatni mozliwy adress pionka z tabeli
        if (tmp != nullptr) tmp->wykonajRuchZrzut(gra[x_to][y_to], tmp);
        figuryGracza.usun(tmp);
    }
    // jezeli jest wieza
    else if (wybor[0] == 'r') {
        std::shared_ptr<Wieza> tmp = figuryGracza.zwroc_Wieza(); // to wez ostatni mozliwy adress pionka z tabeli
        if (tmp != nullptr) tmp->wykonajRuchZrzut(gra[x_to][y_to], tmp);
        figuryGracza.usun(tmp);
    }
}

// async
/**
* Funkcja wykonujaca normalny ruch.
* @param wybor - tablica char ruchu
* @param figuryGracza - figury gracza ktory wykonuje zrzut.
* @param gra - ca³a dwuwymiarowa tablica pól (czyli nasza szachownica na której rozgrywa siê rozgrywka).
* @param wybor - aktualny ruch gracza
* @return intereger kodu wyniku ruchu (1-prawidlowo|0-powrot do poprzedniego menu|-1-blad)
*/
export int wykonaj_ruch(char wybor[4], FiguryGracza& figuryGracza, Pole** gra, Gracz& ruchGracza) {
    // zamiana char na int
    int y_from = char_to_int(wybor[0]);
    int x_from = char_to_int(wybor[1]);
    int y_to = char_to_int(wybor[2]);
    int x_to = char_to_int(wybor[3]);
    bool krol_zbiry = false;
    bool git = false;

    if (gra[x_from][y_from].wykonajRuch(gra[x_to][y_to], figuryGracza, ruchGracza, gra, krol_zbiry, '\0')) {
        if (krol_zbiry) {
            zbicie_krola(ruchGracza);
            return 0;
        }
        git = true;
    }
    else {
        wstaw_tekst(25, 16, "Nie mozna wyknac takiego ruchu wybrana figura. Prosze podac ruch ponownie.", "Orange");
        // false - czyli nie da siê tak poruszyæ figur¹ (ruch ³amie zasady)
        return -1;
    }

    if (ruchGracza == gracz1 && git) ruchGracza = gracz2;
    else if (ruchGracza == gracz2 && git) ruchGracza = gracz1;

    return 1;
}

/**
* Funkcja zapisu do logow informacji o ruchu zrzutce.
* @param wybor - tablica char ruchu
* @param gra - ca³a dwuwymiarowa tablica pól (czyli nasza szachownica na której rozgrywa siê rozgrywka).
* @paarm logi - obiekt Logs do ktorego zostanie zapisany ruch zrzutki
*/
export void zapis_do_logow_programu_zrzutka(char wybor[3], Pole** gra, Logs& logi) {

    // dodaje ruch do logow
    std::string ruch_z, ruch_na;
    ruch_z += wybor[0];
    ruch_z += "*";
    ruch_na += wybor[1];
    ruch_na += wybor[2];
    std::pair<std::string, std::string> para(ruch_z, ruch_na);
    logi.addToRuch(para);
    logi.addTozapis_gry(zapisz_planszy(gra)); // zapisujemy stan planszy 

}

/**
* Funkcja zapisu do logow informacji o ruchu normalnym.
* @param wybor - tablica char ruchu
* @param gra - ca³a dwuwymiarowa tablica pól (czyli nasza szachownica na której rozgrywa siê rozgrywka).
* @paarm logi - obiekt Logs do ktorego zostanie zapisany ruch
*/
export void zapis_do_logow_programu_ruch(char wybor[4], Pole** gra, Logs& logi) {

    std::string ruch_z, ruch_na;
    ruch_z += wybor[0];
    ruch_z += wybor[1];
    ruch_na += wybor[2];
    ruch_na += wybor[3];
    std::pair<std::string, std::string> para(ruch_z, ruch_na);
    logi.addToRuch(para);
    logi.addTozapis_gry(zapisz_planszy(gra)); // zapisujemy stan plansz

}

/**
* Funkcja zapis do logow ruchu oraz innych informacji do logow.
* @param wybor - tablica char ruchu
* @param gra - ca³a dwuwymiarowa tablica pól (czyli nasza szachownica na której rozgrywa siê rozgrywka).
* @paarm logi - obiekt Logs do ktorego zostanie zapisany ruch
* @return boolan true jezeli zapis do logow ruchu sie powidol
*/
export bool save_to_logs_move(char wybor[4], Pole** gra, Logs& logi) {

    std::promise<bool> promise1;
    std::promise<bool> promise2;
    std::promise<bool> promise3;
    std::promise<bool> promise4;
    std::future<bool> fut1 = promise1.get_future();
    std::future<bool> fut2 = promise2.get_future();
    std::future<bool> fut3g1 = promise3.get_future();
    std::future<bool> fut3g2 = promise4.get_future();

    int x1 = -1; int y1 = -1;
    int x2 = -1; int y2 = -1;
    gdzieKrol(gracz1, gra, x1, y1);
    gdzieKrol(gracz2, gra, x2, y2);

    fut1 = std::async(std::launch::async, [&] { return promocjaKroli(gra); }); // thread 1 
    fut2 = std::async(std::launch::async, [&] { return logi.powtrzorzenie_remis(); }); // thread 2
    fut3g1 = std::async(std::launch::async, [&] { return gra[x1][y1].czySzach(gra, gracz1); }); // thread 3
    fut3g2 = std::async(std::launch::async, [&] { return gra[x2][y2].czySzach(gra, gracz2); }); // thread 4

    zapis_do_logow_programu_ruch(wybor, gra, logi);

    if (fut1.get() || fut2.get()) {
        if (fut3g1.get() && logi.powtrzorzenie_ruchu()) logi.incIloscSzachowKrolGracza1(); // powtarza sie to w 3 miejscach 
        else logi.setIloscSzachowKrolGracza1(0);

        if (fut3g2.get() && logi.powtrzorzenie_ruchu()) logi.incIloscSzachowKrolGracza2();
        else logi.setIloscSzachowKrolGracza2(0);

        remis(gra); // Partia koñczy siê remisem, jeœli wskutek powtarzania posuniêæ powstanie po raz czwarty ta sama pozycja.

        return false;
    }
    else {
        // czy nie powtarza sie szachowanie 
        if (fut3g1.get() && logi.powtrzorzenie_ruchu()) logi.incIloscSzachowKrolGracza1(); // powtarza sie to w 3 miejscach 
        else logi.setIloscSzachowKrolGracza1(0);

        if (fut3g2.get() && logi.powtrzorzenie_ruchu()) logi.incIloscSzachowKrolGracza2();
        else logi.setIloscSzachowKrolGracza2(0);

        if (logi.getIloscSzachowKrolGracza1() >= 4) {
            koniec_przez_zaszachowanie(gracz1); // krol gracza 1 zosta³ zaszahcowany 4 razy z rzedu czyli wygrywa gracz2                               
            return false;
        }
        if (logi.getIloscSzachowKrolGracza2() >= 4) {
            koniec_przez_zaszachowanie(gracz2); // krol gracza 2 zosta³ zaszahcowany 4 razy z rzedu czyli wygrywa gracz1         
            return false;
        }
    }
    return true;
}

#pragma endregion reszta
